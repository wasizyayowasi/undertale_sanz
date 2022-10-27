#include "DxLib.h"
#include "Player.h"
#include "game.h"

namespace {
	const char* const kPlayerFilename = "data/heart.png";
	//ジャンプ力
	constexpr float kJumpAcc = -10.0f;
	//重力
	constexpr float kGravity = 0.2f;
}

Player::Player() :
	m_handle(-1),
	m_pos(),
	tracePosX(0),
	tracePosY(0)
{

}
Player::~Player() {

}

//初期化
void Player::init() {
	m_handle = LoadGraph(kPlayerFilename);

	m_fieldY = 800;
	m_pos.x = Game::kScreenWidth / 2;
	m_pos.y = m_fieldY - 26;

	m_vec.x = 0.0f;
	m_vec.y = 0.0f;
}

//終了
void Player::end() {
	DeleteGraph(m_handle);
}

//アップデート
void Player::update() {
	m_pos += m_vec;

	bool isField = false;

	if (m_pos.y > m_fieldY - 26) {
		m_pos.y = m_fieldY - 26;
		isField = true;
	}

	// キー入力処理
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_UP)
	{
		if (isField) {
			m_vec.y = kJumpAcc; //ジャンプ開始
		}
	}
	if (padState & PAD_INPUT_LEFT) {
		m_pos.x -= 8;
		if (!CollisionDetection()) {
			
		}
		else {
			m_pos.x = tracePosX;
		}
	}
	if (padState & PAD_INPUT_RIGHT) {
		m_pos.x += 8;
		if (!CollisionDetection()) {
			
		}
		else {
			m_pos.x = tracePosX;
		}
	}
	m_vec.y += kGravity;
}

//描画
void Player::draw() {
	DrawBox(100, 100, 1180, 800, GetColor(255, 255, 255), false);
	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle, true);
}

//ひとつ前の座標を残す
void Player::trace() {
	tracePosX = m_pos.x;
	tracePosY = m_pos.y;
}


//構造体
typedef struct ColData {
	int left;
	int top;
	int right;
	int bottom;
}ColData;
//データ
ColData colData[] = {
	//外壁確認
	{90, 100,100, 800},			//左
	{100, 90, 1180, 100},		//上
	{1180, 100,1190, 800},		//右
	//{100,800, 1180, 810 },		//下
	
};

bool Player::CollisionDetection() {
	float playerLeft = getPos().x;
	float playerRight = getPos().x + 26;
	float playerTop = getPos().y;
	float playerBottom = getPos().y + 26;

	for (ColData data : colData) {
		if (playerRight < data.left)continue;
		if (playerLeft > data.right)continue;
		if (playerBottom < data.top)continue;
		if (playerTop > data.bottom)continue;
		return true;
	}
	return false;
}
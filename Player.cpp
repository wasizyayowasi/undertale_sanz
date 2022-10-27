#include "DxLib.h"
#include "Player.h"
#include "game.h"

namespace {
	const char* const kPlayerFilename = "data/heart.png";
	//�W�����v��
	constexpr float kJumpAcc = -10.0f;
	//�d��
	constexpr float kGravity = 0.2f;
}

Player::Player() :
	m_handle(-1),
	m_pos()
{

}
Player::~Player() {

}

//������
void Player::init() {
	m_handle = LoadGraph(kPlayerFilename);

	m_fieldY = 800;
	m_pos.x = Game::kScreenWidth / 2;
	m_pos.y = m_fieldY - 26;

	m_vec.x = 0.0f;
	m_vec.y = 0.0f;
}

//�I��
void Player::end() {
	DeleteGraph(m_handle);
}

//�A�b�v�f�[�g
void Player::update() {
	m_pos += m_vec;

	bool isField = false;

	if (m_pos.y > m_fieldY - 26) {
		m_pos.y = m_fieldY - 26;
		isField = true;
	}

	// �L�[���͏���
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_UP)
	{
		if (isField) {
			m_vec.y = kJumpAcc; //�W�����v�J�n
		}
	}
	if (padState & PAD_INPUT_LEFT) {
		m_pos.x -= 8;
	}
	if (padState & PAD_INPUT_RIGHT) {
		m_pos.x += 8;
	}
	m_vec.y += kGravity;
		
}

//�`��
void Player::draw() {
	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle, true);
}

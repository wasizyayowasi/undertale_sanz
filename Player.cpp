#include "DxLib.h"
#include "Player.h"

namespace {
	const char* const kPlayerFilename = "data/heart.png";
}

Player::Player() :
	m_handle(-1),
	m_pos()
{

}
Player::~Player() {

}

//初期化
void Player::init() {
	m_handle = LoadGraph(kPlayerFilename);
}

//終了
void Player::end() {
	DeleteGraph(m_handle);
}

//アップデート
void Player::update() {

}

//描画
void Player::draw() {
	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle, true);
}

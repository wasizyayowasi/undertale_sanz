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

//������
void Player::init() {
	m_handle = LoadGraph(kPlayerFilename);
}

//�I��
void Player::end() {
	DeleteGraph(m_handle);
}

//�A�b�v�f�[�g
void Player::update() {

}

//�`��
void Player::draw() {
	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle, true);
}

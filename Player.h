#pragma once

#include "Vec2.h"

class Player {
public:
	Player();
	virtual ~Player();

	//�O���t�B�b�N�f�[�^�̐ݒ�
	virtual void setHandle(int handle) { m_handle = handle; }

	//�f�[�^�̎擾
	Vec2 getPos()const { return m_pos; }

	//������
	virtual void init();

	//�I��
	virtual	void end();

	//�A�b�v�f�[�g
	virtual	void update();

	//�`��
	virtual	void draw();

	void trace();

	//�Փ˔���
	bool CollisionDetection();
private:
	//�O���t�B�b�N
	int m_handle;

	//Vec2
	Vec2 m_pos;

	// �x�N�g��
	Vec2 m_vec;

	// �n�ʂ̍���
	float m_fieldY;

	float tracePosX;
	float tracePosY;
};
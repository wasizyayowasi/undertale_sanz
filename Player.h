#pragma once

#include "Vec2.h"

class Player {
public:
	Player();
	virtual ~Player();

	//�O���t�B�b�N�f�[�^�̐ݒ�
	virtual void setHandle(int handle) { m_handle = handle; }

	//������
	virtual void init();

	//�I��
	virtual	void end();

	//�A�b�v�f�[�g
	virtual	void update();

	//�`��
	virtual	void draw();
private:
	//�O���t�B�b�N
	int m_handle;
	//Vec2
	Vec2 m_pos;
};
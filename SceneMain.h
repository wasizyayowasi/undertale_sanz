#pragma once
#include "Player.h"

class SceneMain {
public:
	SceneMain();
	virtual ~SceneMain();

	void init();
	void end();
	void update();
	void draw();
private:
	Player m_player;
};
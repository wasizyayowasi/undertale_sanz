#pragma once

#include "Vec2.h"

class Player {
public:
	Player();
	virtual ~Player();

	//グラフィックデータの設定
	virtual void setHandle(int handle) { m_handle = handle; }

	//初期化
	virtual void init();

	//終了
	virtual	void end();

	//アップデート
	virtual	void update();

	//描画
	virtual	void draw();
private:
	//グラフィック
	int m_handle;
	//Vec2
	Vec2 m_pos;
};
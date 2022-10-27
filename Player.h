#pragma once

#include "Vec2.h"

class Player {
public:
	Player();
	virtual ~Player();

	//グラフィックデータの設定
	virtual void setHandle(int handle) { m_handle = handle; }

	//データの取得
	Vec2 getPos()const { return m_pos; }

	//初期化
	virtual void init();

	//終了
	virtual	void end();

	//アップデート
	virtual	void update();

	//描画
	virtual	void draw();

	void trace();

	//衝突判定
	bool CollisionDetection();
private:
	//グラフィック
	int m_handle;

	//Vec2
	Vec2 m_pos;

	// ベクトル
	Vec2 m_vec;

	// 地面の高さ
	float m_fieldY;

	float tracePosX;
	float tracePosY;
};
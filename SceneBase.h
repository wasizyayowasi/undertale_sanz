#pragma once

class SceneBase {
public:
	SceneBase(){}
	virtual ~SceneBase(){}

	virtual	void init(){}
	virtual	void update(){}
	virtual	void draw(){}
	virtual	void end(){}
private:

};
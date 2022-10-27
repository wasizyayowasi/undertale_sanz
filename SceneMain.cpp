#include "SceneMain.h"

SceneMain::SceneMain() {

}
SceneMain::~SceneMain() {

}

void SceneMain::init() {
	m_player.init();
}
void SceneMain::end() {
	m_player.end();
}
void SceneMain::update() {
	m_player.update();
	m_player.trace();
}
void SceneMain::draw() {
	m_player.draw();
}
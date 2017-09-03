#pragma once
#include "gameNode.h"
class player;
class camera;
class stage18_21_traproom : public gameNode
{
private:
	RECT nextdoor;
public:
	stage18_21_traproom();
	~stage18_21_traproom();

	HRESULT init();
	void release();
	void update();
	void render();


	player* _player;
	camera* _camera;

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
};


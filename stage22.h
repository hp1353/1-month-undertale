#pragma once
#include "gameNode.h"
class player;
class camera;
class stage22 : public gameNode
{
private:
	RECT nextdoor;
	RECT itemdoor;
public:
	stage22();
	~stage22();

	HRESULT init();
	void release();
	void update();
	void render();


	player* _player;
	camera* _camera;

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
};


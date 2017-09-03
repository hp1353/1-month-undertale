#pragma once
#include "gameNode.h"
class player;
class camera;
class stage15_store : public gameNode
{
private:
	RECT nextdoor;
public:
	stage15_store();
	~stage15_store();


	HRESULT init();
	void release();
	void update();
	void render();

	player* _player;
	camera* _camera;

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
};


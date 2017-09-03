#pragma once
#include "gameNode.h"
class player;
class camera;
class last : public gameNode
{
private:
	RECT nextdoor;
public:
	last();
	~last();

	HRESULT init();
	void release();
	void update();
	void render();


	player* _player;
	camera* _camera;

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
};


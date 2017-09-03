#pragma once
#include "gameNode.h"
class player;
class camera;
class stage18 : public gameNode
{
private:
	RECT nextdoor;
	RECT blue;
	RECT yellow;
	RECT red;
	RECT text;
	int tcount;
	int tindex;
	int textnum;
	RECT textrc;
	int heartcontrol;
public:
	stage18();
	~stage18();

	HRESULT init();
	void release();
	void update();
	void render();


	player* _player;
	camera* _camera;

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }

	void TextControlUpdate();
	void TextControl();
};


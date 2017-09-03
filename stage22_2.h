#pragma once
#include "gameNode.h"
class player;
class camera;
class stage22_2 : public gameNode
{
private:
	RECT backdoor;
	RECT knife;
	int tcount;
	int tindex;
	int textnum;
	RECT textrc;
public:
	stage22_2();
	~stage22_2();


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


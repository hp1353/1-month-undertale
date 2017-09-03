#pragma once
#include "gameNode.h"
class player;
class camera;
class stage22_1 : public gameNode
{
private:
	RECT nextdoor;
	RECT backdoor;
	image* frognpc;
	int count;
	int index;
	RECT frogrc;
	int tcount;
	int tindex;
	int textnum;
	RECT textrc;
public:
	stage22_1();
	~stage22_1();


	HRESULT init();
	void release();
	void update();
	void render();


	player* _player;
	camera* _camera;

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
	void frogFrame();
	void TextControlUpdate();
	void TextControl();
};


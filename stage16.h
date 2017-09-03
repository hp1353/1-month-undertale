#pragma once
#include "gameNode.h"
class player;
class camera;
class stage16 : public gameNode
{
private:
	RECT nextdoor;
	RECT textrc;
	int tcount;
	int tindex;
	int textnum;
	RECT text;
	RECT text2;
	image* frognpc;
	int count;
	int index;
	

public:
	stage16();
	~stage16();


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
	void frogFrame();
	
};


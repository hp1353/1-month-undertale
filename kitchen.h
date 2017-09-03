#pragma once
#include "gameNode.h"
class player;
class camera;
class kitchen : public gameNode
{
private:
	RECT backdoor;
	int tcount;
	int tindex;
	int textnum;
	RECT textrc;
	bool talkend;
	RECT t1;
	RECT t2;
	RECT t3;
	RECT t4;
	RECT t5;
public:
	kitchen();
	~kitchen();


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
	void TextControl2();
};


#pragma once
#include "gameNode.h"
class player;
class camera;
class myroom : public gameNode
{
private:
	RECT backdoor;
	RECT light;
	bool lightswitch;
	int lightnum;
	RECT t1;
	RECT t2;
	RECT t3;
	RECT sleep;
	RECT pie;
	int tcount;
	int tindex;
	int textnum;
	RECT textrc;
	bool talkend;
	bool sleeping;
	bool gosleep;
	int alpha;
	bool getup;
	bool showpie;
public:
	myroom();
	~myroom();

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


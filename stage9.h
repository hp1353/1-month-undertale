#pragma once
#include "gameNode.h"
class player;
class camera;
class stage9 : public gameNode
{
private:
	
	RECT intro9_1;
	int count;
	int index;
	image* frognpc;
	RECT frogrc;
	int tindex;
	int tcount;
	RECT textrc;
	int textnum;
	int tindex2;
	int textnum2;
	image* savestar;
	int count1;
	int index1;
	RECT starrc;
	RECT nextdoor;
public:
	stage9();
	~stage9();

	HRESULT init();
	void release();
	void update();
	void render();

	player* _player;
	camera* _camera;

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
	void frogFrame();
	void starFrame();
	void TextControl();
	void TextControlUpdate();
	void TextControl2();
};


#include "gameNode.h"
#pragma once

class player;
class camera;
class stage3;

class stage8 : public gameNode
{
private:
	image* toriel;
	int textnum;
	int textnum2;
	int tindex;
	int tindex2;
	int tcount;
	RECT textrc;
	int count;
	int index;
	float tospeed;
	bool tomove;
	RECT nextdoor;
	
public:
	stage8();
	~stage8();
    
	player* _player;
	camera* _camera;
	stage3* _stage3;

	HRESULT init();
	void release();
	void update();
	void render();


	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
	void Stage3Link(stage3* stage3) { _stage3 = stage3; }
	void TextControl();
	void TextControl2();
	void TextControlUpdate();
	void torielFrame();
	void torielMove();
};


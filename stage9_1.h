#pragma once
#include "gameNode.h"
class player;
class camera;
class stage9_1 : public gameNode
{
private:
	
	RECT intro9;
	RECT candy;
	RECT textrc;
	image* stage9_1_river;
	
	int count;
	int index;
	
	int textnum;
	int tindex;
	int tcount;
	int yes;
	int no;
	int candynum;
	bool talking;
	bool isfuckcandy;
	int shehavecandynum;
public:
	stage9_1();
	~stage9_1();

	HRESULT init();
	void release();
	void update();
	void render();

	player* _player;
	camera* _camera;

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
	void riverFrame();
	void TextControl();
	void TextControlUpdate();
};


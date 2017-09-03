#pragma once
#include"gameNode.h"
class player;
class camera;
class stage11:public gameNode
{
private:
	image* stage11_trap;
	RECT trapmark;
	bool isloadmark;
	RECT stonerc;
	image* stone;
	bool stonerock;
	RECT nextdoor;
	RECT t1;
	int tcount;
	int tindex;
	int textnum;
	RECT textrc;
public:
	stage11();
	~stage11();

	HRESULT init();
	void release();
	void update();
	void render();

	player* _player;
	camera* _camera;

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
	void TextControl();
	void TextControlUpdate();
};


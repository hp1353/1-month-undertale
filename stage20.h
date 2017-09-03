#pragma once
#include "gameNode.h"
class player;
class camera;
class stage20:public gameNode
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
	bool dooropen;

	bool drop;
	bool makehole;
	int howmanydrop;
	int dropcount;
	//bool dooropen;
	int saveholex;
	int saveholey;
	int saveholex1;
	int saveholey1;
	int saveholex2;
	int saveholey2;
	int saveholex3;
	int saveholey3;
	int saveholex4;
	int saveholey4;
	int saveholex5;
	int saveholey5;
	int saveholex6;
	int saveholey6;
	int saveholex7;
	int saveholey7;
	int saveholex8;
	int saveholey8;
	int saveholex9;
	int saveholey9;
	RECT loadmark;
	bool once;
public:
	stage20();
	~stage20();

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
	void beforedrop();
	void afterdrop();
};


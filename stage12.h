#pragma once
#include "gameNode.h"
class player;
class camera;
class stage12 : public gameNode
{
private:
	
	RECT droprc1;
	RECT droprc2;
	RECT droprc3;
	RECT droprc4;
	RECT uprc;
	RECT nextdoor;
	RECT uptext;
	RECT downtext;
	int dropcount;
	bool makehole;
	bool drop;
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
	int howmanydrop;

	int tcount;
	int tindex;
	RECT textrc;
	int textnum;
public:
	stage12();
	~stage12();

	HRESULT init();
	void release();
	void update();
	void render();

	player* _player;
	camera* _camera;

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
	void beforedrop();
	void afterdrop();
	void TextControl();
	void TextControlUpdate();
};


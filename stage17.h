#pragma once
#include"gameNode.h"
class player;
class camera;
class stage17 : public gameNode
{
private:
	RECT nextdoor;
	RECT holerc1[3];
	RECT holerc2[3];
	image* stage17switch;
	RECT switchrc;
	RECT loadmark;
	RECT updoor1;
	RECT updoor2;
	RECT updoor3;
	RECT updoor4;
	RECT updoor5;
	RECT updoor6;
	bool drop;
	bool makehole;
	int howmanydrop;
	int dropcount;
	bool dooropen;
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

	int tcount;
	int tindex;
	int textnum;
	RECT textrc;
	RECT text;

	bool once;

public:
	stage17();
	~stage17();

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
	void TextControlUpdate();
	void TextControl();
};


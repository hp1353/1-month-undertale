#pragma once
#include "gameNode.h"
class player;
class camera;
class stage10 : public gameNode
{
private:
	RECT holerc;
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
	int howmanydrop;
	bool index;
	RECT door1;
	RECT door2;
	RECT nextdoor;
public:
	stage10();
	~stage10();


	HRESULT init();
	void release();
	void update();
	void render();

	player* _player;
	camera* _camera;

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
};


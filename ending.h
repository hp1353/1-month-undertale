#pragma once
#include "gameNode.h"
class player;
class camera;
class ending:public gameNode
{
private:
	RECT nextdoor;
	bool end;
	int alpha;
	bool over;
	image* flowerfun;
	image* flowerhide;
	int count;
	int index;
	int count2;
	int index2;

	int tcount;
	int tindex;
	int textnum;
	RECT textrc;
	bool talkend;

	image* flower_1;
	image* flower_2;
	image* flower_3;
	image* flower_4;

	int facecount1;
	int faceindex1;
	int facecount2;
	int faceindex2;
	int facecount3;
	int faceindex3;
	int facecount4;
	int faceindex4;

	bool talkonce;
	bool flowerzzz;
	bool funonce;
	bool allover;

public:
	ending();
	~ending();
	HRESULT init();
	
	void update();
	void render();


	player* _player;
	camera* _camera;

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
	void TextControlUpdate();
	void TextControl();
	void FlowerFrame();
};


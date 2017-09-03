#pragma once
#include "gameNode.h"
class player;
class camera;
class stage3;
class stage6 : public gameNode
{
private:
	
	stage3* _stage3;
	player* _player;
	camera* _camera;
	image* toriel;
	int count;
	int index;
	int tcount;
	int tindex;
	RECT textrc;
	int textnum;
	RECT loadMark;
	RECT introBattle;
	RECT nextdoor;
	float speed;
	int speed1;
	int count1;
	int count2;
	bool ischange;
	float speedx;
	float speedy;
	int endx;
	int endy;
	int aftertextnum1;
	int aftertextindex1;
	int aftertextnum2;
	int aftertextindex2;
	int aftertextnum3;
	int aftertextindex3;
	int aftertextnum4;
	int aftertextindex4;
	//TCHAR buf[100];
	
public:
	stage6();
	~stage6();

	HRESULT init();
	void release();
	void update();
	void render();

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
	void Stage3Link(stage3* stage3) { _stage3 = stage3; }

	void torielFrame();
	void TextControl();
	void TextControlUpdate();
	void entryBattle();

	void patten1_text();
	void patten2_text();
	void patten3_text();
	void patten4_text();
	void AfterTextControlUpdate();
};


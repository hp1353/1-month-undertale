#pragma once
#include "gameNode.h"
class player;
class camera;
class stage3;
class leftroom : public gameNode
{
private:
	RECT nextdoor;
	RECT backdoor;
	image* fire;
	image* torielsitup;
	
	int firecount;
	int fireindex;
	RECT torielsitrc;
	int tcount;
	int tindex;
	int textnum;
	RECT textrc;
	image* toriel;
	image* torielface_1;
	image* torielface_0;
	image* torielface_talk;
	int count;
	int index;
	int count1;
	int index1;
	int count2;
	int talkcount;
	int talkindex;
	bool talkend;
	bool viewfuck;
	int fuckcount;
	bool nextevent;
	bool tormove1;
	bool tormove2;
	int count3;
	int index3;
	int heartcontrol;
	bool nosleep;
	int textcount;
	int count5;
	int index5;
	bool torielangry;
public:
	leftroom();
	~leftroom();


	HRESULT init();
	void release();
	void update();
	void render();


	player* _player;
	camera* _camera;
	stage3* _stage3;

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
	void Stage3Link(stage3* stage3) { _stage3 = stage3; }
	void fireFrame();
	void TextControlUpdate();
	void TextControl();
	void torielFrame();
};


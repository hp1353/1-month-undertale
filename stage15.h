#pragma once
#include "gameNode.h"
class player;
class camera;
class stage15 : public gameNode
{
private:
	RECT nextdoor;
	RECT storedoor;
	RECT loadmark;
	RECT GhostTextrc;
	int tindex;
	int tcount;
	int textnum;
	RECT textrc;
	int heartcontrolnum;
	int speed;
	int speedx;
	int speedy;
	bool ischange;
	int endx;
	int endy;
	int count2;
	bool select;
	int test;
	bool gobattle;
	bool playonce;
	bool playonce2;
	int ghostalpha;
	int alphacount;
	bool alpha;
public:
	stage15();
	~stage15();

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
	void entryBattle();
};


#pragma once
#include "gameNode.h"
class player;
class camera;
class stage13 : public gameNode
{
private:
	
	image* stone1;
	image* stone2;
	image* stoneAI;
	image* stage13_trap;
	RECT stone1rc;
	RECT stone2rc;
	RECT stoneAIrc;
	RECT loadmark;
	bool switchon;
	int tcount;
	int tindex;
	int textnum;
	RECT textrc;
	bool move1;
	bool move2;
	bool move3;
	bool move4;
	bool moving;
	bool move5;
	RECT nextdoor;
public:
	stage13();
	~stage13();

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


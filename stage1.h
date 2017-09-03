#pragma once
#include "gameNode.h"

class player;

class stage1 : public gameNode
{
private:
	player* _player;
	int mapx;
	int mapy;
	
	RECT door;
public:
	stage1();
	~stage1();

	HRESULT init();
	void release();
	void update();
	void render();
	
	void PlayerLink(player* player) { _player = player; }
	void pixelCollision();
	
};


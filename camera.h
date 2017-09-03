#pragma once
#include "gameNode.h"

class player;



class camera : public gameNode
{
private:
	int saveX, saveY;
	int boomx, boomy;
	int countx;
	int county;
	int indexx;
	int indexy;
	bool boomover;
public:
	camera();
	~camera();
	
	cameraAngle cam;
	player* _player;

	HRESULT init();
	void release();
	void update();
	void render();

	void PlayerLink(player* player) { _player = player; }

	cameraAngle* getCam() { return &cam; }
};


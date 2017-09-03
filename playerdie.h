#pragma once
#include "gameNode.h"
class player;
class camera;
class playerdie : public gameNode
{
private:
	bool once;
	bool once2;
	bool once3;
	int alpha;
	int heartx;
	int hearty;
	int heartxcount;
	int heartycount;

	image* playerheartbreakframe;
	image* playerheartbreakframe2;
	image* playerheartbreakframe3;
	image* playerheartbreakframe4;
	image* playerheartbreakframe5;

	int count;
	int index;

	float break1x;
	float break2x;
	float break3x;
	float break4x;
	float break5x;
	float breaky;
	float breakynum;
	float break1y;
	float break2y;
	float break3y;
	float break4y;
	float break5y;

	int bugfixcount;
	bool heartbreak;

	bool play;

	int soundcount;

	bool gameover;
	int alpha2;

	int tcount;
	int tindex;
	int textnum;
	RECT textrc;
	bool over;

public:
	playerdie();
	~playerdie();

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
};


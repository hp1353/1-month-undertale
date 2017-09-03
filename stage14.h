#pragma once
#include "gameNode.h"
class player;
class camera;
class stage14 : public gameNode
{
private:
	
	image* savestar;
	int count1;
	int index1;
	RECT mouse;
	RECT cheeze;
	RECT starrc;
	RECT nextdoor;
	int tcount;
	int tindex;
	int textnum;
	RECT textrc;
	
public:
	stage14();
	~stage14();

	HRESULT init();
	void release();
	void update();
	void render();

	player* _player;
	camera* _camera;

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
	void starFrame();
	void TextControl();
	void TextControlUpdate();
};


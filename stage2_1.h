#pragma once
#include "gameNode.h"
class player;
class camera;
class stage2_1 : public gameNode
{
private:
	int count;
	int index;
	int tcount;
	int tindex;
	image* toriel_speak;
	image* toriel;
	bool chat;
	RECT nextdoor;
	int textnum;
	RECT textrc;
	bool talkend;
	int count1;
	int index1;
	image* torielface_1;
	image* torielface_talk;
	bool move;
public:
	stage2_1();
	~stage2_1();

	player* _player;
	camera* _camera;

	HRESULT init();
	void release();
	void update();
	void render();


	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
	void TextControlUpdate();
	void TextControl();
};


#pragma once
#include "gameNode.h"
#include "camera.h"
class player;
class camera;

class stage2 : public gameNode
{
private:
	RECT Eventrc;
	bool playevent;
	int eventnum;
	int textcount;
	int textindex;
	bool eventtext[7];
	image* flowerFrame;
	int index;
	int count;
	int tcount;
	int tindex;
	int textnum;
	RECT textrc;
	bool talkend;
public:
	stage2();
	~stage2();

	player* _player;
	camera* _camera;
	HRESULT init();
	void release();
	void update();
	void render();

	void PlayerLink(player* player) { _player = player; }
	void Event();
	void EventRender();
	void FrameUpdate();

	void CameraLink(camera* camera) { _camera = camera; }


	void TextControlUpdate();
	void TextControl();
};


#pragma once
#include "gameNode.h"

class player;
class camera;
struct torielMotion
{
	bool walk;
	bool idle;
	bool moveup;
	bool moveleft;
	bool movedown;
	bool moveright;
};
class stage3 : public gameNode
{
private:
	int count;
	int index;
	int count1;
	int index1;
	bool talkcountreset;
	int tcount;
	int tindex;
	int textnum;
	RECT textrc;
public:
	stage3();
	~stage3();

	player* _player;
	camera* _camera;
	image* toriel;
	torielMotion _torielMotion;
	image* savestar;
	RECT save;
	RECT nextdoor;
	HRESULT init();
	void release();
	void update();
	void render();
	void FrameUpdate();
	void EventMove();
	

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
	void TextControlUpdate();
	void TextControl();
};


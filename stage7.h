#include "gameNode.h"
#pragma once 

class player;
class camera;
class stage3;
struct torielplusMotion
{
	bool walk;
	bool idle;
	bool moveup;
	bool moveleft;
	bool movedown;
	bool moveright;
};
class stage7 : public gameNode
{
private:
	image* trap[14][4];
	RECT traprc[14][4];
	image* toriel;
	image* torplus;
	int textnum;
	int tindex;
	RECT textrc;
	int tcount;
	int count;
	int index;
	int count1;
	int index1;
	bool isfirstevent;
	bool islastevent;
	RECT loadmark;
	RECT bottomrc;
	bool move[5];
	bool lastmove;
	RECT nextdoor;
	RECT introbattle;
	torielplusMotion _torielplus;
	int speedx;
	int speedy;
	int speed;
	int count2;
	int endx;
	int endy;
	bool ischange;
	
public:
	stage7();
	~stage7();
	player* _player;
	camera* _camera;
	stage3* _stage3;

	HRESULT init();
	void release();
	void update();
	void render();

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
	void Stage3Link(stage3* stage3) { _stage3 = stage3; }

	void traprender();
	void TextControl();
	void TextControl2();
	void TextControl3();
	void TextControlUpdate();
	void torielFrame();
	void entryBattle();
};


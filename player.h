#pragma once

#include "gameNode.h"
#include "stage1.h"

class camera;
class player : public gameNode
{

private:
	int count;
	int index;
	int changecount;
	int changeindex;
	image* piximage;
	int point;
	bool itemview;
	bool stateview;
	int itemarr;
	int iteminfoarr;
	bool infomonstercandy;
	bool usecandy;
	bool infocandy;
	int itemnum;
	int candyindex;
	int candycount;
	RECT candytextrc;
	int candytextnum;
	int turncount;
	int turnindex;
	bool isturn;
	int fuckingturn;
	bool infoknife;
	bool useknife;
	int knifetextnum;
	int pietextnum;
	bool infopie;
	bool once;
	int RndMonsterNum;
	int RndWalkNum;
	int Walkcount;
	int Walkindex;
	int monsterbeforecount;
	bool introonce;
	bool intro2;
	int introcount;
	int introindex;
	bool entryonce;

	int endx;
	int endy;
	int speed;
	int speedx;
	int speedy;
	int count2;
	bool ischange;
	
public:
	
	player();
	~player();
	camera* _camera;
	PlayerInfo _player;
	
	HRESULT init();
	void release();
	void update();
	void render();

	void FrameUpdate();
	void KeyControl();
	void entrybattle();
	void talkControl();
	void InvenUpdate();
	void InvenRender();
	void candyinfo();
	void candytextupdate();
	void Turn();
	void MonsterMeet();
	PlayerInfo* getPlayer() { return &_player; }
	void CameraLink(camera* camera) { _camera = camera; }
	
};


#pragma once
#include "gameNode.h"
class player;
class camera;
class stage7battle : public gameNode
{
private:
	
	int speed;
	int speedx;
	int speedy;
	bool ischange;
	int endx;
	int endy;
	int count1;
	int frogcount;
	int frogindex;
	int textnum;
	int textnum2;
	int tcount;
	int tindex;
	int fcount;
	int findex;
	int lacount;
	int next;
	int heartwx;
	int towx;
	int fowx;
	int stickx;
	int count;
	int fcount4;
	int fcount5;
	int fcount6;
	int fcount7;
	int att;
	int stickindex;
	int fcount2;
	int fcount3;
	int dboxy;
	float te;
	float te2;
	float rhd;
	float epa;
	int epa2;
	int hpx;

	RECT textrc;
	RECT dbox;

	image* heartw;
	image* fight;
	image* act;
	image* item;
	image* mercy;
	image* frog;
	image* tototo;
	image* frororo;
	image* stick;
	image* gagef;
	image* attack;

	bool hs;
	bool frofs;

	bool start;
	bool fightchoices;
	bool fightgages;
	bool fightatts;
	bool fightatt2s1;
	bool fightmisss;
	bool mercychoices;
    bool actchoices;
	bool atts;
	bool fights;
	bool acts;
	bool items;
	bool mercys;
	bool sticks;
	bool misss;
	int runcount;
	

public:
	stage7battle();
	~stage7battle();

	HRESULT init();
	void release();
	void update();
	void render();

	camera* _camera;
	player* _player;

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
	void entryBattle();


	void choice();

	void fightchoice();
	void fightgage();
	void fightatt();
	void fightatt2();
	
	void fightmiss();
	void actchoice();
	void mercychoice();

	void TextControl();
};


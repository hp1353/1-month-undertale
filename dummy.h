#pragma once
#include "gameNode.h"

class player;
class camera;
class dummy : public gameNode
{
private:
	
	image* fight;
	image* act;
	image* item;
	image* mercy;
	image* heartw;
	image* stick;
	image* attack;
	image* dummy2;
	image* gagef;

	RECT textrc;
	RECT textrc2;
	RECT dbox;

	int textnum;
	int textnum2;
	int tcount;
	int tindex;
	int count;
	int evcount;
	int next;
	int dummyy;
	int dummyx;
	int heartwx;
	int fcount;
	int fcount2;
	int fcount3;
	int fcount4;
	int fcount5;
	int fcount6;
	int fcount7;
	int findex;
	int stickx;
	int stickindex;
	int att;
	int hpx;
	int epa2;
	int dboxy;

	float rhd;
	float epa;
	float te;
	float te2;

	bool start;
	bool fightchoices;
	bool fightatts;
	bool fightatt2s1;
	bool fightatt2s2;
	bool fightgages;
	bool fightmisss;
	bool actchoices;
	bool actchoice2s;
	bool mercychoices;

	bool textrc2s;
	bool fights;
	bool acts;
	bool items;
	bool mercys;
	bool hs;
	bool sticks;
	bool stickf; 
	bool misss;
	bool atts;
public:
	dummy();
	~dummy();

	player* _player;
	camera* _camera;
	



	HRESULT init();
	void release();
	void update();
	void render();


	void playerlink(player* player) { _player = player; }
	void cameralink(camera* camera) { _camera = camera; }

	void choice();
	void fightchoice();
	void fightatt();
	void fightatt2();
	void fightgage();
	void fightmiss();
	void actchoice();
	void actchoice2();
	void mercychoice();
	void TextControl();

	void viewEvery();
};


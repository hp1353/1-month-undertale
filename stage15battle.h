#pragma once
#include "gameNode.h"

#define BULLETMAX 100
class player;
class camera;

struct tagBullet2
{
	RECT rctpfh;
	RECT rcrkfh;
	
	bool ups;
	bool rights;
	bool lefts;
	bool fires;
	bool downs;
	float puspeed;
};
struct tagBullet3
{
	RECT rcbullsm;
	RECT rcbullla;

	bool fires;
	bool la;
	
	float puspeed;
};
class stage15battle :public gameNode
{
private:
	tagBullet2 _bullet[BULLETMAX];
	tagBullet2 _bullet2[BULLETMAX];
	tagBullet3 _bullet3[BULLETMAX];
	tagBullet3 _bullet4[BULLETMAX];
	image* ghost;
	image* fight;
	image* act;
	image* item;
	image* mercy;
	image* bull123;
	image* bull1234;
	image* bulllal;
	image* bulllal1;
	image* bulllal2;
	image* bulllal3;
	image* bulllal4;
	image* bulllal5;
	image* bulllar;
	image* bulllar1;
	image* bulllar2;
	image* bulllar3;
	image* bulllar4;
	image* bullsml;
	image* bullsml1;
	image* bullsml2;
	image* bullsml3;
	image* bullsml4;
	image* bullsml5;
	image* bullsml6;
	image* bullsml7;
	image* bullsml8;
	image* bullsmr;
	image* bullsmr1;
	image* bullsmr2;
	image* bullsmr3;
	image* bullsmr4;
	image* bullsmr5;
	image* bttbf;
	image* stick;
	image* gagef;
	image* attack;
	image* lvnum;
	image* tennum;
	image* onenum;
	image* tennum2;
	image* onenum2;
	image* napd;
	int index1;
	int bttbcount;
	int count1;
	int tindex;
	int tcount;
	int textnum;
	int textnum2;
	int textnum3;
	int textnum4;
	int textnum5;
	int textnum6;
	int firecount;
	int fireindex;
	int indexbull;
	int att;
	int stickindex;
	int next;
	int rlqnsn;
	int rlqnsc;
	int rlqnsi;
	int praisecount;
	int tlscount;
	int tlsindex;
	int hpx;
	int hpx2;
	int stickx;
	int count;
	int fcount2;
	int fcount5;
	int fcount4;
	int fcount6;
	int fcount7;
	int dkdkdk;
	int dkdkdk2;
	float bully[100];
	float bullx[100];
	float bull2y[100];
	float bull2x[100];
	int plhx;
	int plhy;
	int bullxint;
	int dboxy;
	float te;
	float te2;
	float rhd;
	float epa;
	int epa2;
	int vlxkscount;
	bool vlxkss;

	RECT textrc;
	RECT textrc2;
	RECT textrc3;
	RECT bbox;
	RECT bbox2;
	RECT plh;
	RECT dbox;
	RECT vlxksr;
	
	bool plays;
	bool resetbulls;
	bool ptt1s;
	bool ptt2s;
	bool textlast;
	bool pttcos;
	bool textrc2s;
	bool textrc3s;
	bool ptt1sco;
	bool bttbs;
	bool interimclosings;
	bool closings;
	bool nothings;
	bool praise;
	bool lastpraise;
	bool tlstks;
	bool sticks;
	bool rlqns1;
	bool rlqns2;
	bool rlqns3;
	bool text2s;
	bool text3s;
	bool atts;
	bool start;
	bool actchoices;
	bool mercychoices;

	bool fights;
	bool acts;
	bool items;
	bool mercys;
	bool misss;
	bool fightchoices;
	bool fightgages;
	bool fightatts;
	bool fightatt2s1;
	bool fightmisss;

public:
	stage15battle();
	~stage15battle();

	HRESULT init();
	void release();
	void update();
	void render();

	player* _player;
	camera* _camera;

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
	void ghostFrame();
	void TextControlUpdate();
	void TextControl();
	void play();
	void choice();
	void fightchoice();
	void fightgage();
	void fightatt();
	void fightatt2();
	void fightmiss();
	void actchoice();
	void mercychoice();
	void resetbull();
	void pttco();
	void ptt1();
	void ptt2();
	void interimclosing();
	void closing();
	void tlstk();
	void vlxks();
 
};


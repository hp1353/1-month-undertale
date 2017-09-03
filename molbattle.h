#pragma once
#define bulletmax 1000
#include "gameNode.h"
#include < vector >
class player;
class camera;
struct tagmol
{
	image* bulletImage;
	RECT rc;
	int radius;
	float angle;
	float x, y;
	float fireX, fireY;
	float speed;
	bool fire;
	int index;
	int count; //프레임 돌릴 거
	int rndy;
	int rndx;
};

struct tagmol2
{
	image* bulletImage;
	RECT rc;
	int radius;
	float angle;
	float x, y;
	float fireX, fireY;
	float speed;
	bool fire;
	int index;
	int count; //프레임 돌릴 거
};
class molbattle : public gameNode
{
private:
	vector<tagmol> _vBullet;
	vector<tagmol>::iterator _viBullet;
	vector<tagmol2> _vBullet2;
	vector<tagmol2>::iterator _viBullet2;

	int firecount;
	bool molturn;
	int firerndx;

	image* lvnumber;
	image* curhpnumber1;
	image* curhpnumber10;
	image* maxhpnumber1;
	image* maxhpnumber10;
	image* mol_act;
	image* mol_fight;
	image* mol_item;
	image* mol_mercy;
	int curhpimagebar;
	image* attackeffect;
	int attackeffectcount;
	int attackeffectindex;
	image* number1;
	image* number10;
	image* number100;
	image* number1000;
	image* heartrun;
	int heartruncount;
	int heartrunindex;
	int molrendercount;
	int molrenderindex;
	int molcurhp;
	int molmaxhp;
	int molimagehpbar;

	bool fight;
	bool act;
	bool mercy;
	bool item;

	bool morefight;
	bool moreact;
	bool moremercy;
	bool moreitem;

	bool moremoreact;
	bool moremorefight;
	int rndtextnum;

	int yourdmg;
	int point;

	int tcount;
	int textnum;
	int tindex;

	bool moremoreactselect;
	int textboxmovex;
	int textboxsmallerx;

	RECT textrc;
	RECT textrc2;

	int text3heartcontrolx;
	int text3heartcontroly;
	RECT removerc;
	bool goodman;
	int goodmancount;
	int goodmanalpha;
	RECT heartbox;

	image* attackbar;
	int attackbarmovex;
	image* attackgagegone;
	bool isyouattack;
	int attackgagecount;
	int attackgageindex;
	bool gagegoneframe;
	bool stopbar;
	int index;
	int count;
	bool attack;
	bool onceattacksound1;
	bool onceattacksound2;
	int yourdmgbar;

	int dmgbefore;
	int molboom;
	int indexx;
	bool boomover;
	int boomx;
	bool ismolunderattack;
	int countx;
	bool moldie;
	int diecount;
	int dieindex;
	bool dieover;
	int moremercyxheartx;
	bool run;
	int runcount;
	bool once;
	bool moltextcount;
	int moltextnum;
	int rndtextnum2;
	bool dieonce;
	
public:
	molbattle();
	~molbattle();

	HRESULT init();
	void release();
	void update();
	void render();

	player* _player;
	camera* _camera;

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }

	void fire(float x, float y, float angle, float speed);
	void move();
	void fire2(float x, float y, float angle, float speed);
	void move2();
	void EraseAndFire2();
	void NumberSet();
	void BattleControl();
	void TextControlUpdate();
	void TextControl();
	void MolTextControlUpdate();
	void MolTextControl();
	void removebullet();
	void molunderattack();
	void runOut();
};


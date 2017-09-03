
#pragma once
#define bulletMax 200
#include "gameNode.h"
#include <vector>

class player;
class camera;


class nobody : public gameNode
{

private:
	
	float movex;
	bool leftmove;
	bool rightmove;
	int bulletcount;
	int firecount1;
	int firecount2;
	RECT removerc;
	int diecount;
	int dieindex;

	

	image* lvnumber;
	image* curhpnumber1;
	image* curhpnumber10;
	image* maxhpnumber1;
	image* maxhpnumber10;
	image* number1;
	image* number10;
	image* number100;
	image* number1000;
	int curhpimagebar;
	image* tb_act;
	image* tb_fight;
	image* tb_item;
	image* tb_mercy;
	bool act;
	bool fight;
	bool item;
	bool mercy;
	bool moreact;
	bool morefight;
	bool moreitem;
	bool moremercy;
	int point;
	int tcount;
	int tindex;
	int textnum;
	RECT textrc;
	RECT textrc2;
	bool talkend;
	int moremercyheartpoint;
	int mercycount;
	bool run;
	image* heartrun;
	int heartruncount;
	int heartrunindex;
	bool once;
	int moreactheartpoint;
	int moremoreactheartpoint;
	bool moremoreact;
	bool oncetalk1;
	bool oncetalk2;
	bool moremoreactselect;
	bool moremorefight;
	int torcurhp;
	int tormaxhp;
	int torimagebarhp;
	int attackbarmovex;
	bool torturn;
	image* attackgagegone;
	bool isyouattack;
	int attackgageindex;
	int attackgagecount;

	int textboxmovex;
	int textboxsmallerx;
	image* attackbar;
	bool stopbar;
	int count;
	int index;
	image* attackeffect;
	bool attack;
	int attackeffectcount;
	int attackeffectindex;
	int yourdmg;
	int yourdmgbar;
	bool onceattacksound1;
	bool onceattacksound2;

	bool sheunderattack;

	int torielboom;

	int indexx;
	bool boomover;
	int boomx;
	int countx;

	int dmgbefore;
	bool mercycountonce;
	bool mercygagegone;
	bool gagegoneframe;

	image* torielbullet;
	bool patten1attack;

	RECT heartbox;
	bool goodman;
	int goodmancount;
	int goodmanalpha;

	bool patten2attack;
	int torielpattennum;

	bool patten3attack;
	int handx;
	RECT handrc;
	int handfirespeed;

	bool fireonce[10];

	bool patten4attack;
	bool torielsad;
	RECT playershield;

	bool torieltalk;

	int tortcount;
	int tortindex;
	int tortextnum;

	bool torieldie;
	bool torlasttext;

	//int diecount;
	//int dieindex;
	int rndtextnum;
	bool mercytext;
	bool torhp0;
	bool torhp0attack;
	int moltextnum;
	image* monster;
	int monstercount;
	int monsterindex;
	int moremoreactheartpointy;

	int patten1rndx;
	int patten2rndx;
	bool food;
	bool dieonce;

public:
	nobody();
	~nobody();

	HRESULT init();
	void release();
	void update();
	void render();

	player* _player;
	camera* _camera;

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
	void NumberSet();
	void BattleControl();
	void TextControlUpdate();
	void TextControl();
	void GetOut();
	void torielAttack();
	void torielUnderAttack();
	void torielpatten1();
	void torielpatten2();
	void torielpatten3();
	void torielpatten4();
	void torielTextControl();
	void torielTextControlUpdate();
	void removebullet();
};


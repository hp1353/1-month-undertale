#pragma once

#include "image.h"

struct cameraAngle
{
	image* mapimage;
	RECT maprc; //맵전체 크기의 렉트
	RECT rc;  //캐릭터 기준으로 움직이는 화면크기의 렉트
	bool overviewX;
	bool overviewY;
	bool cameramove;
	int x;
	int y;
};

enum Motion
{
	WALK,
	IDLE
};

struct PlayerInfo
{
	RECT rc;
	RECT bottomrc;
	image* image;
	Motion motion;
	int x, y;
	int Lv;
	int MaxHp;
	int CurHp;
	int MaxExp;
	int CurExp;
	int SaveX, SaveY;
	int SaveStageNum;
	int Gold;
	int At;
	bool talk;
	int talkindex;
	bool talking;
	bool isRight;
	bool isLeft;
	bool isUp;
	bool isDown;
	bool viewEvery;

	bool control;
	bool frame;
	bool frameReset;

	bool changebattle;
	bool battleScene;

	bool chagne;
	bool changeScene;

	bool ischangebattle;

	bool playerRender;
	bool stage6_patten1;
	bool stage6_patten2;
	bool stage6_patten3;
	bool stage6_patten4;
	
	bool playertor;

	int changeindex;
	
	bool isstage9_1;
	bool viewInven;
	int itemarr[10];
	int candynum;
	int shehavecandy;
	bool killstage7frog;
	bool dontpix;
	bool turn;

	bool stage7return;
	bool isstage15_store;
	bool istraproom;
	bool isstage22_1;
	bool isstage22_2;
	bool pressZ;

	bool stage19nopillar;
	bool stage20nopillar;
	bool stage21nopillar;
	bool haveknife;
	bool notree;
	bool viewtorielhomeEvent;
	bool viewrightroomEvent;

	bool isbeforerightroom;
	bool isbeforeleftroom;
	bool isbeforekitchen;
	bool isbeforeunderroom;
	bool isbefroemyroom;
	bool isbeforetorielroom;
	bool gosleep;
	int alpha;
	bool isgetpie;
	bool angrytoriel;
	bool under1event;
	bool under2event;
	bool under3event;
	bool under4event;

	bool boom;

	bool goodending;
	bool badending;

	bool ghostend;

	int killnum;
	bool battleend;
	int walkcount;

	bool stage11clear;
	bool stage13clear;
	bool stage17clear;
	bool stage19clear;
	bool stage20clear;
	bool stage21clear;


	int savecamx;
	int savecamy;

	bool killghost;

	int loadstagenum;
	bool stage15skip;
};

static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", 6000, 4520 );

class gameNode
{
private:
	HDC _hdc;
	bool _managerInit;

public:
	gameNode();
	virtual ~gameNode();

	virtual HRESULT init();
	virtual HRESULT init(bool managerInit);
	virtual void release();
	virtual void update();
	virtual void render();

	image* getBackBuffer() { return _backBuffer; }
	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

	
};


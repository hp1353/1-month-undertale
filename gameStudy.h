#pragma once

#include "gameNode.h"
#include "player.h"
#include "stage1.h"
#include "camera.h"
#include "stage2.h"
#include "stage2_1.h"
#include "firstbattle.h"
#include "stage3.h"
#include "stage4.h"
#include "stage5.h"
#include "stage6.h"
#include "dummy.h"
#include "stage7.h"
#include "stage7battle.h"
#include "stage8.h"
#include "stage9.h"
#include "stage9_1.h"
#include "stage10.h"
#include "stage11.h"
#include "stage12.h"
#include "stage13.h"
#include "stage14.h"
#include "stage15.h"
#include "stage15battle.h"
#include "stage15_store.h"
#include "stage16.h"
#include "stage17.h"
#include "stage18.h"
#include "stage19.h"
#include "stage20.h"
#include "stage21.h"
#include "stage18_21_traproom.h"
#include "stage22.h"
#include "stage22_1.h"
#include "stage22_2.h"
#include "torielgarden.h"
#include "torielhome.h"
#include "leftroom.h"
#include "kitchen.h"
#include "rightroom.h"
#include "myroom.h"
#include "torielroom.h"
#include "undertorielhome_1.h"
#include "undertorielhome_2.h"
#include "undertorielhome_3.h"
#include "undertorielhome_4.h"
#include "torielbattle.h"
#include "torieldie.h"
#include "molbattle.h"
#include "monster1.h"
#include "monster2.h"
#include "nobody.h"
#include "opening.h"
#include "last.h"
#include "ending.h"
#include "playerdie.h"

class gameStudy : public gameNode
{
private:
	player* _player;
	stage1* _stage1;
	camera* _camera;
	stage2* _stage2;
	stage2_1* _stage2_1;
	firstbattle* _battle;
	stage3* _stage3;
	stage4* _stage4;
	stage5* _stage5;
	stage6* _stage6;
	dummy* _dummybattle;
	stage7* _stage7;
	stage7battle* _stage7battle;
	stage8* _stage8;
	stage9* _stage9;
	stage9_1* _stage9_1;
	stage10* _stage10;
	stage11* _stage11;
	stage12* _stage12;
	stage13* _stage13;
	stage14* _stage14;
	stage15* _stage15;
	stage15battle* _stage15battle;
	stage15_store* _stage15_store;
	stage16* _stage16;
	stage17* _stage17;
	stage18* _stage18;
	stage19* _stage19;
	stage20* _stage20;
	stage21* _stage21;
	stage18_21_traproom* _stage18_21_traproom;
	stage22* _stage22;
	stage22_1* _stage22_1;
	stage22_2* _stage22_2;
	torielgarden* _torielgarden;
	torielhome* _torielhome;
	leftroom* _leftroom;
	kitchen* _kitchen;
	rightroom* _rightroom;
	myroom* _myroom;
	torielroom* _torielroom;
	undertorielhome_1* _undertorielhome_1;
	undertorielhome_2* _undertorielhome_2;
	undertorielhome_3* _undertorielhome_3;
	undertorielhome_4* _undertorielhome_4;
	torielbattle* _torielbattle;
	torieldie* _torieldie;
	molbattle* _molbattle;
	monster1* _monster1;
	monster2* _monster2;
	nobody* _nobody;
	int sleepcount;
	bool cover;
	bool nocover;
	opening* _opening;
	last* _last;
	ending* _ending;
	playerdie* _playerdie;



public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	image* frog[64];
	
};
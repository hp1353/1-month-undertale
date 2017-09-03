#include "stdafx.h"
#include "monster1.h"
#include "player.h"
#include "camera.h"


monster1::monster1()
{
}
monster1::~monster1()
{
}

HRESULT monster1::init()
{
	if (SOUNDMANAGER->isPlaySound("stagesound"))
	{
		SOUNDMANAGER->pause("stagesound");
	}
	IMAGEMANAGER->addImage("torhp0attack", "image/undertale/battle/torielbattle/torhp0attack.bmp", 144, 204, false, false);
	IMAGEMANAGER->addImage("torhp0attack2", "image/undertale/battle/torielbattle/torhp0attack2.bmp", 144, 204, false, false);

	_player->getPlayer()->playertor = true;
	_player->getPlayer()->changeScene = false;
	_player->getPlayer()->control = false;
	_player->getPlayer()->y = 300;
	IMAGEMANAGER->addImage("torielbattle_base", "image/undertale/battle/torielbattle/torielbattle_base.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("torielbattle_toriel", "image/undertale/battle/torielbattle/torielbattle_toriel.bmp", 142, 198, false, false);
	monster = IMAGEMANAGER->addFrameImage("monster1", "image/undertale/battle/monster1/monster1.bmp", 240, 108, 3, 1, false, false);
	lvnumber = IMAGEMANAGER->addFrameImage("lvnumber", "image/undertale/battle/number.bmp", 120, 15, 10, 1, false, false);
	curhpnumber1 = IMAGEMANAGER->addFrameImage("curhpnumber1", "image/undertale/battle/number.bmp", 120, 15, 10, 1, false, false);
	curhpnumber10 = IMAGEMANAGER->addFrameImage("curhpnumber10", "image/undertale/battle/number.bmp", 120, 15, 10, 1, false, false);
	maxhpnumber1 = IMAGEMANAGER->addFrameImage("maxhpnumber1", "image/undertale/battle/number.bmp", 120, 15, 10, 1, false, false);
	maxhpnumber10 = IMAGEMANAGER->addFrameImage("maxhpnumber10", "image/undertale/battle/number.bmp", 120, 15, 10, 1, false, false);
	tb_act = IMAGEMANAGER->addFrameImage("tb_act", "image/undertale/battle/torielbattle/act.bmp", 330, 42, 3, 1, false, false);
	tb_fight = IMAGEMANAGER->addFrameImage("tb_fight", "image/undertale/battle/torielbattle/fight.bmp", 330, 42, 3, 1, false, false);
	tb_item = IMAGEMANAGER->addFrameImage("tb_item", "image/undertale/battle/torielbattle/item.bmp", 330, 42, 3, 1, false, false);
	tb_mercy = IMAGEMANAGER->addFrameImage("tb_mercy", "image/undertale/battle/torielbattle/mercy.bmp", 330, 42, 3, 1, false, false);
	IMAGEMANAGER->addImage("more_mercy", "image/undertale/battle/torielbattle/more_mercy.bmp", 177, 68, false, false);
	IMAGEMANAGER->addImage("torielhand", "image/undertale/battle/torielbattle/torielhand.bmp", 56, 38, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("mdie1", "image/undertale/battle/monster1/mdie1.bmp", 96, 152, false, false);
	IMAGEMANAGER->addImage("mdie2", "image/undertale/battle/monster1/mdie2.bmp", 96, 152, false, false);
	IMAGEMANAGER->addImage("mdie3", "image/undertale/battle/monster1/mdie3.bmp", 96, 152, false, false);
	IMAGEMANAGER->addImage("mdie4", "image/undertale/battle/monster1/mdie4.bmp", 96, 152, false, false);
	IMAGEMANAGER->addImage("mdie5", "image/undertale/battle/monster1/mdie5.bmp", 96, 152, false, false);
	IMAGEMANAGER->addImage("mdie6", "image/undertale/battle/monster1/mdie6.bmp", 96, 152, false, false);
	IMAGEMANAGER->addImage("mdie7", "image/undertale/battle/monster1/mdie7.bmp", 96, 152, false, false);
	IMAGEMANAGER->addImage("mdie8", "image/undertale/battle/monster1/mdie8.bmp", 96, 152, false, false);
	IMAGEMANAGER->addImage("mdie9", "image/undertale/battle/monster1/mdie9.bmp", 96, 152, false, false);
	IMAGEMANAGER->addImage("mdie10", "image/undertale/battle/monster1/mdie10.bmp", 96, 152, false, false);

	if (!SOUNDMANAGER->isPlaySound("battlesound"))
	{
		SOUNDMANAGER->play("battlesound", 1.f);
	}
	mercytext = false;
	act = false;
	mercy = false;
	fight = true;
	item = false;

	moreact = false;
	moremercy = false;
	morefight = false;
	moreitem = false;

	point = 1;

	textnum = 1;
	tindex = 0;
	tcount = 0;

	moremercyheartpoint = 305;

	mercycount = 0;
	run = false;
	heartrun = IMAGEMANAGER->addFrameImage("heartrun", "image/undertale/battle/torielbattle/heartrun.bmp", 32, 24, 2, 1, true, RGB(255, 0, 255));
	heartruncount = 0;
	heartrunindex = 0;
	heartrun->setX(60);
	heartrun->setY(325);
	once = false;
	moremoreact = false;
	moreactheartpoint = 60;
	moremoreactheartpoint = 60;
	oncetalk1 = false;
	oncetalk2 = false;
	moremoreactselect = false;

	torcurhp = 50;
	tormaxhp = 50;

	IMAGEMANAGER->addImage("torhpmax", "image/undertale/battle/torielbattle/torhpmax.bmp", 101, 17, false, false);
	IMAGEMANAGER->addImage("torhpmin", "image/undertale/battle/torielbattle/torhpmin.bmp", 101, 17, false, false);
	IMAGEMANAGER->addImage("attackgage", "image/undertale/battle/torielbattle/gage.bmp", 565, 130, false, false);
	attackbar = IMAGEMANAGER->addFrameImage("attackbar", "image/undertale/battle/torielbattle/attackbar.bmp", 28, 130, 2, 1, false, false);
	attackbarmovex = 37;
	torturn = false;

	attackgagegone = IMAGEMANAGER->addFrameImage("attackgagegone", "image/undertale/battle/torielbattle/gagegone.bmp", 7345, 130, 13, 1, false, false);

	isyouattack = false;
	attackgagecount = 0;
	attackgageindex = 0;

	textboxmovex = 32;
	textboxsmallerx = 575;

	IMAGEMANAGER->addImage("textbox", "image/undertale/battle/torielbattle/textbox.bmp", 575, 140, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("m1battlebox", "image/undertale/battle/torielbattle/battlebox.bmp", 165, 140, true, RGB(255, 0, 255));

	count = 0;
	index = 0;

	stopbar = false;
	attackeffect = IMAGEMANAGER->addFrameImage("attackeffect", "image/undertale/battle/torielbattle/attackeffect.bmp", 693, 154, 7, 1, true, RGB(255, 0, 255));
	attackeffectcount = 0;
	attackeffectindex = 0;
	yourdmg = 0;
	yourdmgbar = 0;

	onceattacksound1 = false;
	onceattacksound2 = false;

	sheunderattack = false;

	torielboom = 0;

	countx = 0;
	boomover = false;
	indexx = 0;
	boomx = 0;

	IMAGEMANAGER->addImage("torhpmin2", "image/undertale/battle/torielbattle/torhpmin2.bmp", 101, 17, false, false);

	number1 = IMAGEMANAGER->addFrameImage("number1", "image/undertale/battle/number2.bmp", 280, 27, 10, 1, false, false);
	number10 = IMAGEMANAGER->addFrameImage("number10", "image/undertale/battle/number2.bmp", 280, 27, 10, 1, false, false);
	number100 = IMAGEMANAGER->addFrameImage("number100", "image/undertale/battle/number2.bmp", 280, 27, 10, 1, false, false);
	number1000 = IMAGEMANAGER->addFrameImage("number1000", "image/undertale/battle/number2.bmp", 280, 27, 10, 1, false, false);
	IMAGEMANAGER->addImage("torielbattle_base", "image/undertale/battle/torielbattle/torielbattle_base.bmp", 640, 480, false, false);
	dmgbefore = 0;
	mercycountonce = false;
	gagegoneframe = false;
	moltextnum = 0;


	//torielbullet = IMAGEMANAGER->addFrameImage("torielbullet", "image/undertale/battle/torielbattle/torielbullet.bmp", 128, 32, 4, 1, true, RGB(255, 0, 255));
	patten1attack = false;

	for (int i = 0; i < bulletMax; i++)
	{
		tagmonster bullet;


		bullet.bulletImage = IMAGEMANAGER->addFrameImage("bullet1", "image/undertale/battle/monster1/bullet1.bmp", 14, 22, 1, 1, true, (RGB(255, 0, 255)));
		bullet.speed = 0.1f;
		bullet.fire = false;
		bullet.count = 0;
		bullet.index = 1;

		_vBullet.push_back(bullet);
	}
	for (int i = 0; i < bulletMax; i++)
	{
		tagmonster2 bullet2;


		bullet2.bulletImage = IMAGEMANAGER->addFrameImage("bullet", "image/undertale/battle/monster1/bullet.bmp", 14, 22, 1, 1, true, (RGB(255, 0, 255)));
		bullet2.speed = 0.1f;
		bullet2.fire = false;
		bullet2.count = 0;
		bullet2.index = 1;

		_vBullet2.push_back(bullet2);
	}
	for (int i = 0; i < bulletMax; i++)
	{
		tagmonster3 bullet3;


		bullet3.bulletImage = IMAGEMANAGER->addFrameImage("bullet2", "image/undertale/battle/monster1/bullet2.bmp", 13, 21, 1, 1, true, (RGB(255, 0, 255)));
		bullet3.speed = 1.1f;
		bullet3.fire = false;
		bullet3.count = 0;
		bullet3.index = 1;
		bullet3.movex = 0;
		_vBullet3.push_back(bullet3);
	}
	for (int i = 0; i < bulletMax; i++)
	{
		tagmonster4 bullet4;


		bullet4.bulletImage = IMAGEMANAGER->addFrameImage("bullet3", "image/undertale/battle/monster1/bullet3.bmp", 12, 21, 1, 1, true, (RGB(255, 0, 255)));
		bullet4.speed = 1.1f;
		bullet4.fire = false;
		bullet4.count = 0;
		bullet4.index = 1;
		bullet4.movex = 0;

		_vBullet4.push_back(bullet4);
	}

	leftmove = false;
	rightmove = true;
	bulletcount = 0;
	firecount1 = 0;
	firecount2 = 0;
	removerc = RectMake(0, 0, 640, 480);

	goodman = false;
	goodmancount = 0;
	goodmanalpha = 255;

	patten2attack = false;
	torielpattennum = 0;
	handx = 240;

	for (int i = 0; i < bulletMax; i++)
	{
		tagmonster5 bullet5;


		bullet5.bulletImage = IMAGEMANAGER->addFrameImage("bullet4", "image/undertale/battle/monster1/bullet4.bmp", 13, 18, 1, 1, true, (RGB(255, 0, 255)));
		bullet5.speed = 0.1f;
		bullet5.fire = false;
		bullet5.count = 0;
		bullet5.index = 0;
		bullet5.movex = 0;
		bullet5.coll = false;
		bullet5.collx = 1;

		_vBullet5.push_back(bullet5);
	}

	for (int i = 0; i < 10; i++)
	{
		fireonce[i] = false;
	}

	for (int i = 0; i < bulletMax; i++)
	{
		tagmonster6 bullet6;


		bullet6.bulletImage = IMAGEMANAGER->addFrameImage("bullet5", "image/undertale/battle/monster1/bullet5.bmp", 13, 15, 1, 1, true, (RGB(255, 0, 255)));
		bullet6.speed = 1.1f;
		bullet6.fire = false;
		bullet6.count = 0;
		bullet6.index = 1;
		bullet6.movex = 0;

		_vBullet6.push_back(bullet6);
	}
	patten4attack = false;
	torielsad = false;
	IMAGEMANAGER->addImage("miss", "image/undertale/battle/torielbattle/miss.bmp", 118, 30, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("talkrect", "image/undertale/battle/torielbattle/talkRect.bmp", 84, 114, true, RGB(255, 0, 255));


	torieltalk = false;
	tortextnum = 0;
	tortindex = 0;
	tortcount = 0;

	torieldie = false;
	torlasttext = false;

	IMAGEMANAGER->addImage("torielsad", "image/undertale/battle/torielbattle/torielsad.bmp", 144, 204, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("torieldie1", "image/undertale/battle/torielbattle/torieldie1.bmp", 142, 198, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("torieldie2", "image/undertale/battle/torielbattle/torieldie2.bmp", 132, 156, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("torieldie3", "image/undertale/battle/torielbattle/torieldie3.bmp", 132, 156, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("torieldie4", "image/undertale/battle/torielbattle/torieldie4.bmp", 132, 156, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("torieldie5", "image/undertale/battle/torielbattle/torieldie5.bmp", 132, 156, true, RGB(255, 0, 255));

	rndtextnum = 0;
	torhp0 = false;

	IMAGEMANAGER->addImage("tortext13", "image/undertale/battle/torielbattle/tortext13.bmp", 144, 204, false, false);
	IMAGEMANAGER->addImage("tortext16", "image/undertale/battle/torielbattle/tortext16.bmp", 144, 204, false, false);
	IMAGEMANAGER->addImage("tortext19", "image/undertale/battle/torielbattle/tortext19.bmp", 144, 204, false, false);
	IMAGEMANAGER->addImage("tortext21", "image/undertale/battle/torielbattle/tortext21.bmp", 144, 204, false, false);
	IMAGEMANAGER->addImage("tortext25", "image/undertale/battle/torielbattle/tortext25.bmp", 144, 204, false, false);
	torhp0attack = false;

	monstercount = 0;
	monsterindex = 0;

	IMAGEMANAGER->addImage("molbase", "image/undertale/battle/molbattle/molbase.bmp", 609, 236, false, false);

	moremoreactheartpointy = 265;
	food = false;
	patten2rndx = 0;
	
	diecount = 0;
	dieindex = 0;

	dieonce = false;
	attack = false;


	return S_OK;
}

void monster1::release()
{
}

void monster1::update()
{
	if (_player->getPlayer()->x < 250)
	{
		_player->getPlayer()->x += 2;

	}
	if (_player->getPlayer()->x > 390)
	{
		_player->getPlayer()->x -= 2;
	}
	if (_player->getPlayer()->y > 370)
	{
		_player->getPlayer()->y -= 2;
	}
	if (_player->getPlayer()->y < 260)
	{
		_player->getPlayer()->y += 2;
	}
	if (mercycount >= 14)
	{
		if (SOUNDMANAGER->isPlaySound("boss"))
			SOUNDMANAGER->stop("boss");
	}
	if (torieldie && textnum !=14)
	{
		if (!dieonce && !SOUNDMANAGER->isPlaySound("monsterdead"))
		{
			SOUNDMANAGER->play("monsterdead", 1.f);
			dieonce = true;
			tindex = 0;
		}
		tortextnum = 0;

		textnum = 14;
		torturn = false;
		morefight = false;
		moremorefight = false;
	}
	if (torieldie)
	{
		diecount++;
		if (diecount % 10 == 0)dieindex++;
	}
	monster->setFrameX(monsterindex);
	monstercount++;

	if (monsterindex > monster->getMaxFrameX())
	{
		monsterindex = 0;
	}
	else if (monstercount % 20 == 0)monsterindex++;
	playershield = RectMake(_player->getPlayer()->x - 50, _player->getPlayer()->y - 50, 100, 100);
	textrc = RectMake(60 + _camera->getCam()->x + 20, 255 + _camera->getCam()->y, 565, 130);
	textrc2 = RectMake(450, 130, 560, 150);
	if (!sheunderattack)torielboom = 0;
	//카메라셋팅
	_camera->getCam()->x = 0;
	_camera->getCam()->y = 0;
	if (!torturn)
	{
		NumberSet();
		BattleControl();
	}
	NumberSet();
	TextControlUpdate();
	torielTextControlUpdate();
	//if (_player->getPlayer()->CurHp < 5)torielsad = true;
	if (torcurhp <= 0)torieldie = true;
	if (run) GetOut();
	if (torturn && !patten1attack) torielAttack();
	if (patten1attack)
	{

		{
			if (food)torielpattennum = 0;
			
				
				if (torielpattennum % 2 == 0)torielpatten1();
				else if (torielpattennum % 2 == 1)torielpatten2();
			
		}

	}
	removebullet();
	if (torturn) _player->getPlayer()->control = true;
	else _player->getPlayer()->control = false;
	heartbox = RectMake(_player->getPlayer()->x, _player->getPlayer()->y, 16, 16);



}

void monster1::render()
{
	IMAGEMANAGER->findImage("dark")->render(getMemDC());
	//IMAGEMANAGER->findImage("torielbattle_base")->render(getMemDC());
	IMAGEMANAGER->findImage("molbase")->render(getMemDC(), 14, 10);
	IMAGEMANAGER->findImage("lv")->render(getMemDC(), 72, 402); //lv 이미지
	IMAGEMANAGER->findImage("lvnumber")->frameRender(getMemDC(), 109, 402); // lv 숫자이미지
	IMAGEMANAGER->findImage("curhpnumber1")->frameRender(getMemDC(), 330, 403); // 현재체력 1의자리
	IMAGEMANAGER->findImage("curhpnumber10")->frameRender(getMemDC(), 314, 403); // 현재체력 10의자리
	IMAGEMANAGER->findImage("maxhpnumber1")->frameRender(getMemDC(), 393, 403); // 최대체력 1의자리
	IMAGEMANAGER->findImage("maxhpnumber10")->frameRender(getMemDC(), 376, 403); // 최대체력 10의자리
	IMAGEMANAGER->findImage("hpnull")->render(getMemDC(), 240, 398); // hp 글씨밑  옆 / 표시
	IMAGEMANAGER->findImage("hpmin")->render(getMemDC(), 275, 400); // hp 바탕 ( 빨간색체력)
	IMAGEMANAGER->findImage("hpmax")->render(getMemDC(), 275, 400, 0, 0, curhpimagebar, 21); //hp바  25,21 max
	IMAGEMANAGER->findImage("tb_fight")->frameRender(getMemDC(), 32 + _camera->getCam()->x, 432 + _camera->getCam()->y);
	IMAGEMANAGER->findImage("tb_act")->frameRender(getMemDC(), 185 + _camera->getCam()->x, 432 + _camera->getCam()->y);
	IMAGEMANAGER->findImage("tb_item")->frameRender(getMemDC(), 345 + _camera->getCam()->x, 432 + _camera->getCam()->y);
	IMAGEMANAGER->findImage("tb_mercy")->frameRender(getMemDC(), 500 + _camera->getCam()->x, 432 + _camera->getCam()->y);
	
	if (!torhp0attack)
	{
		if (torcurhp > 0)
			IMAGEMANAGER->findImage("monster1")->frameRender(getMemDC(), 325 + torielboom, 135);
	//	if (torcurhp > 0 && torielsad)
		//	IMAGEMANAGER->findImage("torielsad")->render(getMemDC(), 250 + torielboom, 45);

		if (dieindex == 1)IMAGEMANAGER->findImage("mdie1")->render(getMemDC(), 320, 88);
		if (dieindex == 2)IMAGEMANAGER->findImage("mdie2")->render(getMemDC(), 320, 88);
		if (dieindex == 3)IMAGEMANAGER->findImage("mdie3")->render(getMemDC(), 320, 88);
		if (dieindex == 4)IMAGEMANAGER->findImage("mdie4")->render(getMemDC(), 320, 88);
		if (dieindex == 5)IMAGEMANAGER->findImage("mdie5")->render(getMemDC(), 320, 88);
		if (dieindex == 6)IMAGEMANAGER->findImage("mdie6")->render(getMemDC(), 320, 88);
		if (dieindex == 7)IMAGEMANAGER->findImage("mdie7")->render(getMemDC(), 320, 88);
		if (dieindex == 8)IMAGEMANAGER->findImage("mdie8")->render(getMemDC(), 320, 88);
		if (dieindex == 9)IMAGEMANAGER->findImage("mdie9")->render(getMemDC(), 320, 88);
		if (dieindex == 10)IMAGEMANAGER->findImage("mdie10")->render(getMemDC(), 320, 88);
		
	}
	if (torhp0attack)
	{
		if (tortextnum < 53)
			IMAGEMANAGER->findImage("torhp0attack")->render(getMemDC(), 250 + torielboom, 45);
		if (tortextnum == 53)
			IMAGEMANAGER->findImage("torhp0attack2")->render(getMemDC(), 250 + torielboom, 45);
		if (tortextnum == 54)
			IMAGEMANAGER->findImage("torieldie5")->render(getMemDC(), 260 + torielboom, 80);
	}

	if (tortextnum != 0 && !torieldie)
	{
		IMAGEMANAGER->findImage("talkrect")->render(getMemDC(), 430, 120);
	}
	torielTextControl();
	if (moremercy)
	{
		//IMAGEMANAGER->findImage("more_mercy")->render(getMemDC(), 90, 270);
		textnum = 7;
		if (!run)
			IMAGEMANAGER->findImage("heart")->render(getMemDC(), 60, moremercyheartpoint);
	}
	if (run)
	{
		moremercy = false;

		IMAGEMANAGER->findImage("heartrun")->frameRender(getMemDC(), heartrun->getX(), heartrun->getY());
	}
	if (moreact && !moremoreact)
	{
		IMAGEMANAGER->findImage("heart")->render(getMemDC(), moreactheartpoint, 265);
	}
	if (moremoreact)
	{
		if (textnum != 4 && textnum != 5 && textnum != 6 && textnum != 10 && textnum !=15 && textnum !=14)
			IMAGEMANAGER->findImage("heart")->render(getMemDC(), moremoreactheartpoint, moremoreactheartpointy);
	}
	if (morefight && !moremorefight)
	{
		IMAGEMANAGER->findImage("heart")->render(getMemDC(), 60, 265);
		IMAGEMANAGER->findImage("torhpmin")->render(getMemDC(), 320, 270);
		IMAGEMANAGER->findImage("torhpmax")->render(getMemDC(), 320, 270, 0, 0, torimagebarhp, 17);
	}
	if (sheunderattack)
	{
		IMAGEMANAGER->findImage("torhpmin2")->render(getMemDC(), 320, 110);
		IMAGEMANAGER->findImage("torhpmax")->render(getMemDC(), 320, 110, 0, 0, torimagebarhp, 17);

		IMAGEMANAGER->findImage("number1")->frameRender(getMemDC(), 370, 80);
		IMAGEMANAGER->findImage("number10")->frameRender(getMemDC(), 340, 80);
		if (torhp0attack)
		{
			IMAGEMANAGER->findImage("number100")->frameRender(getMemDC(), 260, 0);
			IMAGEMANAGER->findImage("number1000")->frameRender(getMemDC(), 230, 0);
		}


	}
	if (attackbarmovex >= 600)IMAGEMANAGER->findImage("miss")->render(getMemDC(), 320, 110);
	if (moremorefight)
	{
		IMAGEMANAGER->findImage("attackgage")->render(getMemDC(), 37, 256);
		if (attackbarmovex < 600)
			IMAGEMANAGER->findImage("attackbar")->frameRender(getMemDC(), attackbarmovex, 256);
		if (attackbarmovex >= 600 || isyouattack)
		{
			IMAGEMANAGER->findImage("attackgagegone")->frameRender(getMemDC(), 37, 256);
		}
	}
	if (!torturn)
		IMAGEMANAGER->findImage("textbox")->render(getMemDC(), textboxmovex, 250, 0, 0, textboxsmallerx, 140);
	if (torturn)
	{
		IMAGEMANAGER->findImage("m1battlebox")->render(getMemDC(), 240, 250);
		if (goodman)
		{

			IMAGEMANAGER->findImage("heart")->alphaRender(getMemDC(), _player->getPlayer()->x, _player->getPlayer()->y, goodmanalpha);
		}
		else IMAGEMANAGER->findImage("heart")->render(getMemDC(), _player->getPlayer()->x, _player->getPlayer()->y);
	}
	if (attack)
	{
		IMAGEMANAGER->findImage("attackeffect")->frameRender(getMemDC(), 320, 100);
	}

	if (patten1attack)
	{
		//IMAGEMANAGER->findImage("torielbullet")->frameRender(getMemDC(), torbullet.x, torbullet.y);


		for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
		{
			if (!_viBullet->fire) continue;
			if (_viBullet->x < 240 || _viBullet->x >400 || _viBullet->y >370 || _viBullet->y < 260)continue;
			_viBullet->bulletImage->frameRender(getMemDC(), _viBullet->rc.left, _viBullet->rc.top);

		}
		for (_viBullet2 = _vBullet2.begin(); _viBullet2 != _vBullet2.end(); ++_viBullet2)
		{
			if (!_viBullet2->fire) continue;
			if (_viBullet2->x < 240 || _viBullet2->x >400 || _viBullet2->y >370 || _viBullet2->y < 260)continue;
			_viBullet2->bulletImage->frameRender(getMemDC(), _viBullet2->rc.left, _viBullet2->rc.top);

		}
	}
	if (patten2attack)
	{
		for (_viBullet3 = _vBullet3.begin(); _viBullet3 != _vBullet3.end(); ++_viBullet3)
		{
			if (!_viBullet3->fire || _viBullet3->y >= 380) continue;
			if (_viBullet3->x < 240 || _viBullet3->x >400 || _viBullet3->y >370 || _viBullet3->y < 260)continue;
			_viBullet3->bulletImage->frameRender(getMemDC(), _viBullet3->rc.left, _viBullet3->rc.top);

		}
		for (_viBullet4 = _vBullet4.begin(); _viBullet4 != _vBullet4.end(); ++_viBullet4)
		{
			if (!_viBullet4->fire || _viBullet4->y >= 380) continue;
			if (_viBullet4->x < 240 || _viBullet4->x >400 || _viBullet4->y >370 || _viBullet4->y < 260)continue;
			_viBullet4->bulletImage->frameRender(getMemDC(), _viBullet4->rc.left, _viBullet4->rc.top);

		}
		
		for (_viBullet5 = _vBullet5.begin(); _viBullet5 != _vBullet5.end(); ++_viBullet5)
		{
			if (!_viBullet5->fire) continue;
			if (_viBullet5->x < 240 || _viBullet5->x >400 || _viBullet5->y >370 || _viBullet5->y < 260)continue;
			_viBullet5->bulletImage->frameRender(getMemDC(), _viBullet5->rc.left, _viBullet5->rc.top);

		}
		for (_viBullet6 = _vBullet6.begin(); _viBullet6 != _vBullet6.end(); ++_viBullet6)
		{
			if (!_viBullet6->fire) continue;
			if (_viBullet6->x < 240 || _viBullet6->x >400 || _viBullet6->y >370 || _viBullet6->y < 260)continue;
			_viBullet6->bulletImage->frameRender(getMemDC(), _viBullet6->rc.left, _viBullet6->rc.top);

		}
	}
	
	TextControl();

	if (_player->getPlayer()->viewEvery)
	{
		char str7[128];
		sprintf_s(str7, "textnum :  %d ", textnum);
		TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y + 120, str7, strlen(str7));
		char str8[128];
		sprintf_s(str8, "tindex :  %d ", tindex);
		TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y + 140, str8, strlen(str8));
		char str9[128];
		sprintf_s(str9, "patten2atk :  %d ", patten2attack);
		TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y + 160, str9, strlen(str9));
		char str10[128];
		sprintf_s(str10, "patten1atk :  %d ", patten1attack);
		TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y + 180, str10, strlen(str10));
		Rectangle(getMemDC(), heartbox.left, heartbox.top, heartbox.right, heartbox.bottom);

		for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
		{
			if (!_viBullet->fire) continue;

			Rectangle(getMemDC(), _viBullet->rc.left, _viBullet->rc.top, _viBullet->rc.right, _viBullet->rc.bottom);

		}
		for (_viBullet2 = _vBullet2.begin(); _viBullet2 != _vBullet2.end(); ++_viBullet2)
		{
			if (!_viBullet2->fire) continue;

			Rectangle(getMemDC(), _viBullet2->rc.left, _viBullet2->rc.top, _viBullet2->rc.right, _viBullet2->rc.bottom);

		}
		char str11[128];
		sprintf_s(str11, "torpattennum :  %d ", torielpattennum);
		TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y + 200, str11, strlen(str11));
		Rectangle(getMemDC(), playershield.left, playershield.top, playershield.right, playershield.bottom);

	}

}

void monster1::NumberSet()
{
	//레벨숫자 세팅
	lvnumber->setFrameX(_player->getPlayer()->Lv);
	//hp숫자 세팅
	for (int i = 0; i < 10; i++)
	{
		if (_player->getPlayer()->CurHp % 10 == i)curhpnumber1->setFrameX(i);
		if (_player->getPlayer()->CurHp / 10 % 10 == i)curhpnumber10->setFrameX(i);
		if (_player->getPlayer()->MaxHp % 10 == i)maxhpnumber1->setFrameX(i);
		if (_player->getPlayer()->MaxHp / 10 % 10 == i)maxhpnumber10->setFrameX(i);
		if (yourdmg % 10 == i)number1->setFrameX(i);
		if (yourdmg / 10 % 10 == i)number10->setFrameX(i);
		if (yourdmg / 100 % 10 == i)number100->setFrameX(i);
		if (yourdmg / 1000 % 10 == i)number1000->setFrameX(i);
	}
	//hp 바 비율 계산
	curhpimagebar = (25 * _player->getPlayer()->CurHp / _player->getPlayer()->MaxHp);
	torimagebarhp = (101 * torcurhp / tormaxhp);
}

void monster1::BattleControl()
{
	
	if (gagegoneframe)
	{
		textnum = 0;
		act = false;
		mercy = false;
		fight = true;
		item = false;

		moreact = false;
		moremercy = false;
		morefight = false;
		moreitem = false;

		moremoreact = false;
		moremorefight = false;

		textnum = 0;
		textboxmovex += 8;
		textboxsmallerx -= 16;

		attackgagegone->setFrameX(attackgageindex);
		attackgagecount++;

		if (attackgageindex > attackgagegone->getMaxFrameX())
		{
			torturn = true;
		}
		else if (attackgagecount % 2 == 0)attackgageindex++;
	}
	if (stopbar)
	{
		attackbar->setFrameX(index);
		count++;

		if (index > attackbar->getMaxFrameX())
		{
			index = 0;
		}
		else if (count % 5 == 0)index++;
	}
	if (fight)
	{
		tb_fight->setFrameX(0);
		tb_act->setFrameX(1);
		tb_item->setFrameX(1);
		tb_mercy->setFrameX(1);
	}
	if (act)
	{
		tb_act->setFrameX(0);
		tb_fight->setFrameX(1);
		tb_mercy->setFrameX(1);
		tb_item->setFrameX(1);
	}
	if (item)
	{
		tb_item->setFrameX(0);
		tb_fight->setFrameX(1);
		tb_act->setFrameX(1);
		tb_mercy->setFrameX(1);
	}
	if (mercy)
	{
		tb_mercy->setFrameX(0);
		tb_act->setFrameX(1);
		tb_fight->setFrameX(1);
		tb_item->setFrameX(1);
	}
	if (point == 1)
	{
		if (!morefight)
			fight = true;
		act = false;
		item = false;
		mercy = false;
		if (_player->getPlayer()->pressZ)
		{
			textnum = 0;
			morefight = true;
			if (!SOUNDMANAGER->isPlaySound("pointselect"))
			{
				SOUNDMANAGER->play("pointselect", 1.f);
			}

		}
	}
	if (point == 2)
	{
		if (!moreact)
			act = true;
		fight = false;
		item = false;
		mercy = false;
		if (_player->getPlayer()->pressZ && !moremoreact)
		{
			textnum = 0;
			moreact = true;
			if (!SOUNDMANAGER->isPlaySound("pointselect"))
			{
				SOUNDMANAGER->play("pointselect", 1.f);
			}

		}
	}
	if (point == 3)
	{
		if (!moreitem)
			item = true;
		act = false;
		fight = false;
		mercy = false;
		if (_player->getPlayer()->pressZ)
		{
			textnum = 0;
			moreitem = true;
			if (!SOUNDMANAGER->isPlaySound("pointselect"))
			{
				SOUNDMANAGER->play("pointselect", 1.f);
			}
		}
	}
	if (point == 4)
	{
		if (!moremercy)
			mercy = true;
		item = false;
		fight = false;
		act = false;
		if (_player->getPlayer()->pressZ)
		{
			textnum = 0;
			moremercy = true;
			if (!SOUNDMANAGER->isPlaySound("pointselect"))
			{
				SOUNDMANAGER->play("pointselect", 1.f);
			}
		}
	}
	if (moreact) tb_act->setFrameX(2);
	if (morefight)tb_fight->setFrameX(2);
	if (moreitem)tb_item->setFrameX(2);
	if (moremercy)tb_mercy->setFrameX(2);

	// 키컨트롤
	if (textnum != 7 && textnum != 8 && textnum != 9 && textnum != 10)
	{
		if (KEYMANAGER->isOnceDown(VK_LEFT))
		{
			if (point > 1 && !moreact && !morefight && !moreitem && !moremercy)
			{
				if (!SOUNDMANAGER->isPlaySound("pointmove"))
					SOUNDMANAGER->play("pointmove", 1.f);
				point -= 1;
			}
			if (moremoreact)
			{

				moremoreactheartpoint = 60;


			}

		}
		if (KEYMANAGER->isOnceDown(VK_RIGHT))
		{
			if (point < 4 && !moreact && !morefight && !moreitem && !moremercy)
			{
				if (!SOUNDMANAGER->isPlaySound("pointmove"))
					SOUNDMANAGER->play("pointmove", 1.f);
				point += 1;
			}
			if (moremoreact)
			{


				moremoreactheartpoint = 300;

			}
		}
	}
	// 취소버튼 ====
	if (KEYMANAGER->isOnceDown('X'))
	{

		if (textnum != 4 && textnum != 5 && textnum != 6 && textnum != 14
			&& textnum != 15 )
		{
			if (moreact && !moremoreact)
			{
				moreact = false;
				if (torhp0)textnum = 21;
				if (!torhp0)
				{
					if (rndtextnum == 0)
						textnum = 1;
					if (rndtextnum == 1)
						textnum = 11;
					if (rndtextnum == 2)
						textnum = 12;
					if (rndtextnum == 3)
						textnum = 13;
			
				}
				tindex = 0;
			}
			if (moremoreact)
			{
				moremoreact = false;
				moremoreactselect = false;
				textnum = 4;
			}
			if (morefight)
			{
				morefight = false;
				if (torhp0)textnum = 21;
				if (!torhp0)
				{
					if (rndtextnum == 0)
						textnum = 1;
					if (rndtextnum == 1)
						textnum = 11;
					if (rndtextnum == 2)
						textnum = 12;
					if (rndtextnum == 3)
						textnum = 13;
					
				}
				tindex = 0;
			}
			if (moreitem)
			{
				moreitem = false;
				if (torhp0)textnum = 21;
				if (!torhp0)
				{
					if (rndtextnum == 0)
						textnum = 1;
					if (rndtextnum == 1)
						textnum = 11;
					if (rndtextnum == 2)
						textnum = 12;
					if (rndtextnum == 3)
						textnum = 13;
					
				}
				tindex = 0;
			}
			if (moremercy)
			{
				moremercy = false;
				if (torhp0)textnum = 21;
				if (!torhp0)
				{
					if (rndtextnum == 0)
						textnum = 1;
					if (rndtextnum == 1)
						textnum = 11;
					if (rndtextnum == 2)
						textnum = 12;
					if (rndtextnum == 3)
						textnum = 13;
					
				}
				tindex = 0;
			}
		}
	}
	// ====
	// ---- 자비 ----
	if (moremercy)
	{
		if (KEYMANAGER->isOnceDown(VK_UP))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			moremercyheartpoint = 270;
		}
		if (KEYMANAGER->isOnceDown(VK_DOWN))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			moremercyheartpoint = 305;
		}
		if (moremercyheartpoint == 270)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				mercycount += 1; // 살려주기
				mercytext = true;
				//textnum = 0;
				gagegoneframe = true;
			}



		}
		if (moremercyheartpoint == 305)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				run = true;
			}
		}
	}
	// ------

	// -- 행동 ------
	if (moreact && !moremoreact)
	{
		textnum = 2;
		if (!moremoreact)
		{
			if (KEYMANAGER->isOnceDown('Z') && textnum == 2)
			{
				if (!SOUNDMANAGER->isPlaySound("pointselect"))
				{
					SOUNDMANAGER->play("pointselect", 1.f);
				}
				tindex = 0;
				moremoreact = true;
			}
		}
	}
	if (moremoreact)
	{

		if (KEYMANAGER->isOnceDown(VK_UP))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			moremoreactheartpointy = 265;
		}
		if (KEYMANAGER->isOnceDown(VK_DOWN))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			moremoreactheartpointy = 305;
		}
		if (moremoreactheartpoint == 60 && moremoreactheartpointy == 265 &&textnum != 4 && textnum != 5 && textnum != 6 && textnum != 10) //살펴보기 대화하기

		{
			if (_player->getPlayer()->pressZ)
			{
				tindex = 0;
				moremoreactselect = true;
				textnum = 4;
			}
		}
		else if (moremoreactheartpoint == 300 && moremoreactheartpointy== 265 && textnum != 4 && textnum != 5 && textnum != 6 && textnum != 10) //먹기 식사하기
		{
			if (_player->getPlayer()->pressZ)
			{
				tindex = 0;
				moremoreactselect = true;
				tortextnum = 2;
				gagegoneframe = true;
			}
		}
		else if (moremoreactheartpoint == 60 && moremoreactheartpointy == 305 && textnum != 4 && textnum != 5 && textnum != 6 && textnum != 10 && textnum !=15) //먹기
		{
			if (_player->getPlayer()->pressZ)
			{
				if(torcurhp < 51)
				{
					tindex = 0;
					moremoreactselect = true;
					textnum = 15;
					if (_player->getPlayer()->CurHp + 5 > _player->getPlayer()->MaxHp) _player->getPlayer()->CurHp = _player->getPlayer()->MaxHp;
					else _player->getPlayer()->CurHp += 5;
				}
				else
				{
					tindex = 0;
					moremoreactselect = true;
					textnum = 5;
				}
			}
		}
		else if (moremoreactheartpoint == 300 && moremoreactheartpointy == 305 && textnum != 4 && textnum != 5 && textnum != 6 && textnum != 10) //식사하기
		{
			if (_player->getPlayer()->pressZ)
			{
				tindex = 0;
				moremoreactselect = true;
				textnum = 6;
			}
		}
		if (!moremoreactselect)
			textnum = 3;

	}
	// -----

	// ------- 때리기   ------
	if (stopbar)
	{
		yourdmgbar = (attackbarmovex - 310) / 40;
		if (yourdmgbar < 0)
		{
			yourdmgbar = yourdmgbar * -1;
		}
	}
	if (torhp0)
	{
		yourdmg = 97842;

	}
	else
		yourdmg = (20 + _player->getPlayer()->At) - yourdmgbar;
	if (morefight && !moremorefight)
	{
		textnum = 2;
		if (KEYMANAGER->isOnceDown('Z'))
		{
			moremorefight = true;
		}

	}
	if (moremorefight)
	{
		if (attackbarmovex < 600)
		{
			if (!stopbar)
				attackbarmovex += 6;
			textnum = 0;
			if (_player->getPlayer()->pressZ)
			{
				if (yourdmg >= 9000 && tortextnum <50)
				{
					torhp0attack = true;
					textnum = 0;

					mercycount = 0;
					mercytext = false;
				}
				attack = true;
				stopbar = true;
			}
		}

		if (attackbarmovex >= 600 || isyouattack)
		{
			textboxmovex += 8;
			textboxsmallerx -= 16;

			attackgagegone->setFrameX(attackgageindex);
			attackgagecount++;

			if (attackgageindex > attackgagegone->getMaxFrameX())
			{
				torturn = true;
			}
			else if (attackgagecount % 2 == 0)attackgageindex++;

			if (attackbarmovex >= 600 && !mercycountonce)
			{
				mercycount = RND->getFromIntTo(3,5);
				mercytext = true;
				mercycountonce = true;
			}
			if (sheunderattack && !mercycountonce)
			{
				mercycount = RND->getFromIntTo(3,5);
				mercytext = true;
				mercycountonce = true;
			}
		}
	}

	if (attack)
	{
		if (!SOUNDMANAGER->isPlaySound("playerattack") && !onceattacksound1)
		{
			SOUNDMANAGER->play("playerattack", 1.f);
			onceattacksound1 = true;
		}
		attackeffect->setFrameX(attackeffectindex);
		attackeffectcount++;

		if (attackeffectindex > attackeffect->getMaxFrameX())
		{
			if (!SOUNDMANAGER->isPlaySound("attacksound") && !onceattacksound2)
			{
				SOUNDMANAGER->play("attacksound", 1.f);
				onceattacksound2 = true;
			}
			sheunderattack = true;
		}
		else if (attackeffectcount % 8 == 0)attackeffectindex++;
	}

	if (sheunderattack)
	{
		torielUnderAttack();
		//isyouattack = true;
	}
	//////////

}

void monster1::TextControlUpdate()
{
	tcount++;
	//17,18,19,20 이 토리엘 기본대사
	if (tcount % 2 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 39)
				tindex++;
		}
		if (textnum == 2)
		{
			if (tindex < 16)
				tindex++;
		}
		if (textnum == 3)
		{
			tindex = 70;
			
		}
		if (textnum == 4)
		{
			if (tindex < 81)
				tindex++;
		}
		if (textnum == 5)
		{
			if (tindex < 66)
				tindex++;
		}

		if (textnum == 6)
		{
			if (tindex < 68)
				tindex++;

		}
		if (textnum == 7)
		{
			tindex = 24;

		}
		
		if (textnum == 11)
		{
			if (tindex < 27)
				tindex++;
		}
		if (textnum == 12)
		{
			if (tindex < 46)
				tindex++;
		}
		if (textnum == 13)
		{
			if (tindex < 36)
				tindex++;
		}
		if (textnum == 14)
		{
			if (tindex < 38)
				tindex++;
		}
		if (textnum == 15)
		{
			if (tindex < 69)
				tindex++;
		}

	

	}
	if (textnum == 6)
	{
		if (tindex == 68)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{

				//tindex = 0;
				food = true;
				textnum = 0;
				mercycount = RND->getFromIntTo(3, 5);
				mercytext = true;
				gagegoneframe = true;
			}

		}

	}
	if (textnum == 5)
	{
		if (tindex == 66)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{

				//tindex = 0;
				textnum = 0;
				oncetalk1 = true;
				mercycount = RND->getFromIntTo(3, 5);
				mercytext = true;
				gagegoneframe = true;
			}
		}

	}
	if (textnum == 4)
	{
		if (tindex == 81)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{

				//tindex = 0;
				textnum = 0;
				oncetalk1 = true;
				mercycount = RND->getFromIntTo(3, 5);
				mercytext = true;
				
				gagegoneframe = true;
			}
		}

	}
	if (textnum == 14)
	{

		if (tindex == 38)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				_player->getPlayer()->killnum += 1;
				_player->getPlayer()->Gold += 1;
				_player->getPlayer()->CurExp += 6;
				_player->getPlayer()->battleend = true;
				if(_player->getPlayer()->SaveStageNum == 9) SCENEMANAGER->changeScene("stage9");
				if (_player->getPlayer()->SaveStageNum == 10) SCENEMANAGER->changeScene("stage10");
				if (_player->getPlayer()->SaveStageNum == 11) SCENEMANAGER->changeScene("stage11");
				if (_player->getPlayer()->SaveStageNum == 12) SCENEMANAGER->changeScene("stage12");
				if (_player->getPlayer()->SaveStageNum == 13) SCENEMANAGER->changeScene("stage13");
				if (_player->getPlayer()->SaveStageNum == 14) SCENEMANAGER->changeScene("stage14");
				if (_player->getPlayer()->SaveStageNum == 15) SCENEMANAGER->changeScene("stage15");
				if (_player->getPlayer()->SaveStageNum == 16) SCENEMANAGER->changeScene("stage16");
				if (_player->getPlayer()->SaveStageNum == 17) SCENEMANAGER->changeScene("stage17");
				if (_player->getPlayer()->SaveStageNum == 18) SCENEMANAGER->changeScene("stage18");
				if (_player->getPlayer()->SaveStageNum == 19) SCENEMANAGER->changeScene("stage19");
				if (_player->getPlayer()->SaveStageNum == 20) SCENEMANAGER->changeScene("stage20");
				if (_player->getPlayer()->SaveStageNum == 21) SCENEMANAGER->changeScene("stage21");



			}
		}

	}
	if (textnum == 15)
	{
		if (tindex == 69)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{

				//tindex = 0;
				textnum = 14;
				tindex = 0;

				

			}
		}

	}
	

}

void monster1::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/monster1/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/monster1/text2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("text/monster1/text3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 4)
		hInputFile = CreateFile(_T("text/monster1/text4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 5)
		hInputFile = CreateFile(_T("text/monster1/text5.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 6)
		hInputFile = CreateFile(_T("text/monster1/text6.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 7)
		hInputFile = CreateFile(_T("text/monster1/text7.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

	if (textnum == 11)
		hInputFile = CreateFile(_T("text/monster1/text11.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 12)
		hInputFile = CreateFile(_T("text/monster1/text12.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 13)
		hInputFile = CreateFile(_T("text/monster1/text13.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 14)
		hInputFile = CreateFile(_T("text/monster1/text14.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 15)
		hInputFile = CreateFile(_T("text/monster1/text15.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	
	ReadFile(hInputFile, buf, 999 * sizeof(TCHAR), &dwRead, NULL);
	CloseHandle(hInputFile);

	//TextOut(getMemDC(), 80, 200, buf, 2 * tindex);
	DrawText(getMemDC(), buf, tindex, &textrc, DT_LEFT);
	DeleteObject(font);
	font = CreateFont(20, 0, 0, 0, 0, 0, 0, 00, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, NULL);
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	DeleteObject(font);
}

void monster1::GetOut()
{
	heartrun->setFrameX(heartrunindex);
	heartruncount++;

	if (heartrunindex > heartrun->getMaxFrameX())
	{
		heartrunindex = 0;
	}
	else if (heartruncount % 5 == 0)heartrunindex++;

	heartrun->setX(heartrun->getX() - 1);
	if (heartrun->getX() < 0)
	{

		_player->getPlayer()->battleend = true;
		if (_player->getPlayer()->SaveStageNum == 9) SCENEMANAGER->changeScene("stage9");
		if (_player->getPlayer()->SaveStageNum == 10) SCENEMANAGER->changeScene("stage10");
		if (_player->getPlayer()->SaveStageNum == 11) SCENEMANAGER->changeScene("stage11");
		if (_player->getPlayer()->SaveStageNum == 12) SCENEMANAGER->changeScene("stage12");
		if (_player->getPlayer()->SaveStageNum == 13) SCENEMANAGER->changeScene("stage13");
		if (_player->getPlayer()->SaveStageNum == 14) SCENEMANAGER->changeScene("stage14");
		if (_player->getPlayer()->SaveStageNum == 15) SCENEMANAGER->changeScene("stage15");
		if (_player->getPlayer()->SaveStageNum == 16) SCENEMANAGER->changeScene("stage16");
		if (_player->getPlayer()->SaveStageNum == 17) SCENEMANAGER->changeScene("stage17");
		if (_player->getPlayer()->SaveStageNum == 18) SCENEMANAGER->changeScene("stage18");
		if (_player->getPlayer()->SaveStageNum == 19) SCENEMANAGER->changeScene("stage19");
		if (_player->getPlayer()->SaveStageNum == 20) SCENEMANAGER->changeScene("stage20");
		if (_player->getPlayer()->SaveStageNum == 21) SCENEMANAGER->changeScene("stage21");
	}
	if (!SOUNDMANAGER->isPlaySound("runout") && !once)
	{
		SOUNDMANAGER->play("runout", 1.f);
		once = true;
	}
}

void monster1::torielAttack()
{
	rndtextnum = 0;
	handx = 240;
	textnum = 0;
	act = false;
	mercy = false;
	fight = false;
	item = false;

	moreact = false;
	moremercy = false;
	morefight = false;
	moreitem = false;

	moremoreact = false;
	moremorefight = false;

	attackgagecount = 0;
	attackgageindex = 0;

	attackbarmovex = 37;
	textboxmovex = 32;
	textboxsmallerx = 575;
	stopbar = false;


	count = 0;
	index = 0;

	attackeffectcount = 0;
	attackeffectindex = 0;

	isyouattack = false;

	yourdmg = 0;
	yourdmgbar = 0;


	onceattacksound1 = false;
	onceattacksound2 = false;

	sheunderattack = false;

	countx = 0;
	boomover = false;
	indexx = 0;
	boomx = 0;

	dmgbefore = 0;

	mercycountonce = false;
	gagegoneframe = false;
	if (!torieldie && !mercytext)
		patten1attack = true;
	//if (torlasttext && tortextnum == 0 && !torieldie) tortextnum = 1;
	attack = false;
	if (torhp0attack && tortextnum < 50)
		tortextnum = 50;

	firecount1 = 0;
	firecount2 = 0;

	moremoreactselect = false;

	for (int i = 0; i < 10; i++)fireonce[i] = false;

	if (mercytext)
	{
		
		tortextnum = mercycount;
	}

}

void monster1::torielUnderAttack()
{

	if (dmgbefore < yourdmg)
	{
		torcurhp -= 2;
		dmgbefore += 2;
	}


	if (indexx > 10)
	{
		boomover = true;
		boomx = 0;
		torielboom = 0;


	}
	else if (indexx <= 10)
	{
		torielboom += boomx;
		countx++;
		if (countx % 2 == 0)
		{
			indexx++;
		}
		if (indexx % 2 == 1) boomx = 20;
		else if (indexx % 2 == 0) boomx = -20;
	}


	if (boomover)
	{

		countx = 0;
		indexx = 0;
		boomx = 0;
		torielboom = 0;
		boomover = false;
		sheunderattack = false;
		isyouattack = true;
	}
}

void monster1::torielpatten1()
{

	bulletcount = RND->getFromIntTo(0, 1000);
	patten1rndx = RND->getFromIntTo(240, 460);
	if (bulletcount % 20 == 0)
		fire(patten1rndx, 250);
	if (food)
	{
		
		fire2(patten1rndx, 250);
		
		food = false;
	}
	move();
	//move2();
	
	
	move2();
	//움직임
	if (!torielsad)
	{
		
	}

	if (torielsad)
	{
		for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
		{
			if (IntersectRect(&RectMake(0, 0, 0, 0), &playershield, &_viBullet->rc))
			{
				//if (bulletcount % 2 == 0)
				if (_viBullet->x > playershield.right)
					_viBullet->x += 5.f;
				else
				{
					_viBullet->x -= 5.f;
				}
				//if (bulletcount % 2 == 1)

			}
		}
		for (_viBullet2 = _vBullet2.begin(); _viBullet2 != _vBullet2.end(); ++_viBullet2)
		{
			if (IntersectRect(&RectMake(0, 0, 0, 0), &playershield, &_viBullet2->rc))
			{
				//if (bulletcount % 2 == 0)

				//if (bulletcount % 2 == 1)
				if (_viBullet2->x < playershield.left)
					_viBullet2->x -= 5.f;
				else _viBullet2->x += 5.f;
			}
		}
	}
	//프레임
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->setFrameX(_viBullet->index);
		_viBullet->count++;
		if (_viBullet->index > _viBullet->bulletImage->getMaxFrameX())
		{
			_viBullet->index = 1;
		}
		else if (_viBullet->count % 10 == 0)_viBullet->index += 2;


	}


	if (firecount1 + firecount2 > 31)
	{
		torturn = false;
		patten1attack = false;
		torielpattennum = 1;
		if (rndtextnum == 0)
		{
			rndtextnum = RND->getFromIntTo(1, 3);
			tindex = 0;
		}
		if (rndtextnum == 1)textnum = 11;
		if (rndtextnum == 2)textnum = 12;
		if (rndtextnum == 3)textnum = 13;
		

	}
}

void monster1::torielpatten2()
{
	patten2attack = true;
	bulletcount = RND->getFromIntTo(0, 10000);
	patten2rndx = RND->getFromIntTo(240, 460);
	if (bulletcount % 29 == 0)
		fire3(patten2rndx, 265, PI / 4 * 3, 1.f);
	if (bulletcount % 21 == 0)
		fire4(patten2rndx, 265, PI / 4 * 2, 1.f);
	if (bulletcount % 23 == 0)
		fire5(patten2rndx, 265, PI / 4,1.f);
	if (bulletcount % 27 == 0)
		fire6(patten2rndx, 265, PI / 3, 1.f);
	
	move3();
	move4();
	move5();
	move6();
	//움직임

	for (_viBullet3 = _vBullet3.begin(); _viBullet3 != _vBullet3.end(); ++_viBullet3)
	{
		if (!_viBullet3->fire) continue;

		for (int i = 0; i < 10; i++)
		{
			if (_viBullet3->y > 260 + 26 * i)
			{

				if (i % 2 == 0)
					_viBullet3->movex = -3.3f;
				if (i % 2 == 1)
					_viBullet3->movex = 3.3f;

			}

		}

	}
	for (_viBullet4 = _vBullet4.begin(); _viBullet4 != _vBullet4.end(); ++_viBullet4)
	{
		if (!_viBullet4->fire) continue;

		for (int i = 0; i < 10; i++)
		{
			if (_viBullet4->y > 260 + 26 * i)
			{

				if (i % 2 == 0)
					_viBullet4->movex = -3.3f;
				if (i % 2 == 1)
					_viBullet4->movex = 3.3f;
			}

		}

	}

	//프레임
	for (_viBullet3 = _vBullet3.begin(); _viBullet3 != _vBullet3.end(); ++_viBullet3)
	{
		_viBullet3->bulletImage->setFrameX(_viBullet3->index);
		_viBullet3->count++;
		if (_viBullet3->index > _viBullet3->bulletImage->getMaxFrameX())
		{
			_viBullet3->index = 1;
		}
		else if (_viBullet3->count % 10 == 0)_viBullet3->index += 2;
	}


	if (firecount1 + firecount2 > 30)
	{
		torturn = false;
		patten1attack = false;
		torielpattennum = 0;
		if (rndtextnum == 0)
		{
			rndtextnum = RND->getFromIntTo(1, 3);
			tindex = 0;
		}
		if (rndtextnum == 1)textnum = 11;
		if (rndtextnum == 2)textnum = 12;
		if (rndtextnum == 3)textnum = 13;
		
	}
}

void monster1::torielpatten3()
{
	patten3attack = true;
	if (handx > 280 && !fireonce[0])
	{
		fire5(280, 300, MY_UTIL::getAngle(280, 300, _player->getPlayer()->x, _player->getPlayer()->y), 0.1f);
		fireonce[0] = true;
	}
	if (handx > 300 && !fireonce[1])
	{
		fire5(300, 300, MY_UTIL::getAngle(280, 300, _player->getPlayer()->x, _player->getPlayer()->y), 0.1f);
		fireonce[1] = true;
	}
	if (handx > 320 && !fireonce[2])
	{
		fire5(320, 300, MY_UTIL::getAngle(280, 300, _player->getPlayer()->x, _player->getPlayer()->y), 0.1f);
		fireonce[2] = true;
	}
	if (handx > 340 && !fireonce[3])
	{
		fire5(340, 300, MY_UTIL::getAngle(280, 300, _player->getPlayer()->x, _player->getPlayer()->y), 0.1f);
		fireonce[3] = true;
	}
	if (handx > 360 && !fireonce[4])
	{
		fire5(360, 300, MY_UTIL::getAngle(280, 300, _player->getPlayer()->x, _player->getPlayer()->y), 0.1f);
		fireonce[4] = true;
	}
	if (handx > 380 && !fireonce[5])
	{
		fire5(380, 300, MY_UTIL::getAngle(280, 300, _player->getPlayer()->x, _player->getPlayer()->y), 0.1f);
		fireonce[5] = true;
	}
	move5();
	handx += 3;

	for (_viBullet5 = _vBullet5.begin(); _viBullet5 != _vBullet5.end(); ++_viBullet5)
	{
		_viBullet5->bulletImage->setFrameX(_viBullet5->index);
		_viBullet5->count++;
		if (_viBullet5->index > _viBullet5->bulletImage->getMaxFrameX())
		{
			_viBullet5->index = 0;
		}
		else if (_viBullet5->count % 10 == 0)_viBullet5->index += 1;

		if (_viBullet5->count > 300 && torielpattennum == 2)
		{
			torturn = false;
			patten1attack = false;
			if (torielsad)torielpattennum = 3;
			else torielpattennum = 0;
			if (rndtextnum == 0)
			{
				rndtextnum = RND->getFromIntTo(1, 3);
				tindex = 0;
			}
			if (rndtextnum == 1)textnum = 11;
			if (rndtextnum == 2)textnum = 12;
			if (rndtextnum == 3)textnum = 13;
			
		}
	}


}

void monster1::torielpatten4()
{
	patten4attack = true;
	bulletcount = RND->getFromIntTo(0, 10000);
	if (bulletcount % 20 == 0)
		fire(325, 250);
	if (bulletcount % 20 == 1)
		fire2(325, 250);

	move6();
	//움직임

	if (!rightmove && leftmove)
	{
		movex -= 0.1f;
	}
	if (!leftmove && rightmove)
		movex += 0.1f;

	if (movex > 2.6f)
	{
		rightmove = false;
		leftmove = true;
	}
	if (movex < -2.6f)
	{
		leftmove = false;
		rightmove = true;
	}
	//프레임
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->setFrameX(_viBullet->index);
		_viBullet->count++;
		if (_viBullet->index > _viBullet->bulletImage->getMaxFrameX())
		{
			_viBullet->index = 1;
		}
		else if (_viBullet->count % 10 == 0)_viBullet->index += 2;
	}


	if (firecount1 + firecount2 > 31)
	{
		torturn = false;
		patten1attack = false;
		//torielpattennum += 1;
		if (rndtextnum == 0)
		{
			rndtextnum = RND->getFromIntTo(1, 3);
			tindex = 0;
		}
		if (rndtextnum == 1)textnum = 11;
		if (rndtextnum == 2)textnum = 12;
		if (rndtextnum == 3)textnum = 13;
		
	}
}

void monster1::torielTextControl()
{
	HFONT font2 = CreateFont(20, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												 //폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font2);
	SetTextColor(getMemDC(), RGB(0, 0, 0));

	TCHAR buf[2000] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (tortextnum == 1)
		hInputFile = CreateFile(_T("text/monster1/hetalk/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (tortextnum == 2)
		hInputFile = CreateFile(_T("text/monster1/hetalk/text2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (tortextnum == 3)
		hInputFile = CreateFile(_T("text/monster1/hetalk/text3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (tortextnum == 4)
		hInputFile = CreateFile(_T("text/monster1/hetalk/text4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (tortextnum == 5)
		hInputFile = CreateFile(_T("text/monster1/hetalk/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

	ReadFile(hInputFile, buf, 999 * sizeof(TCHAR), &dwRead, NULL);
	CloseHandle(hInputFile);

	//TextOut(getMemDC(), 80, 200, buf, 2 * tindex);
	DrawText(getMemDC(), buf, tortindex, &textrc2, DT_LEFT);
	DeleteObject(font2);
	font2 = CreateFont(20, 0, 0, 0, 0, 0, 0, 00, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, NULL);
	SelectObject(getMemDC(), font2);
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	DeleteObject(font2);
}

void monster1::torielTextControlUpdate()
{
	tortcount++;

	if (tortcount % 5 == 0)
	{
		if (tortextnum == 1)
		{
			if (tortindex < 22)
				tortindex++;
		}
		if (tortextnum == 2)
		{
			if (tortindex < 24)
				tortindex++;
		}
		if (tortextnum == 3)
		{
			if (tortindex < 21)
				tortindex++;
		}
		if (tortextnum == 4)
		{
			if (tortindex < 19)
				tortindex++;
		}
		if (tortextnum == 5)
		{
			if (tortindex < 22)
				tortindex++;
		}
		
	}
	if (tortextnum == 1)
	{
		if (tortindex == 22)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{

				tortindex = 0;
				tortextnum = 0;
				mercytext = false;

			}

		}

	}
	if (tortextnum == 2)
	{
		if (tortindex == 24)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{

				tortindex = 0;
				tortextnum = 0;
				mercytext = false;

			}
		}

	}
	if (tortextnum == 3)
	{
		if (tortindex == 21)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{

				tortindex = 0;
				tortextnum = 0;
				mercytext = false;
			}
		}

	}
	if (tortextnum == 4)
	{
		if (tortindex == 19)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{

				tortindex = 0;
				tortextnum = 0;
				mercytext = false;
			}
		}

	}
	if (tortextnum == 5)
	{
		if (tortindex == 22)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{

				tortindex = 0;
				tortextnum = 0;
				mercytext = false;

			}

		}

	}

	

}

void monster1::removebullet()
{
	if (!torturn)
	{
		for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
		{
			if (IntersectRect(&RectMake(0, 0, 0, 0), &removerc, &_viBullet->rc))
			{

				_viBullet = _vBullet.erase(_viBullet);
			}

		}
		for (_viBullet2 = _vBullet2.begin(); _viBullet2 != _vBullet2.end(); ++_viBullet2)
		{
			if (IntersectRect(&RectMake(0, 0, 0, 0), &removerc, &_viBullet2->rc))
			{

				_viBullet2 = _vBullet2.erase(_viBullet2);
			}

		}

		for (_viBullet3 = _vBullet3.begin(); _viBullet3 != _vBullet3.end(); ++_viBullet3)
		{
			if (IntersectRect(&RectMake(0, 0, 0, 0), &removerc, &_viBullet3->rc))
			{

				_viBullet3 = _vBullet3.erase(_viBullet3);
			}

		}
		for (_viBullet4 = _vBullet4.begin(); _viBullet4 != _vBullet4.end(); ++_viBullet4)
		{
			if (IntersectRect(&RectMake(0, 0, 0, 0), &removerc, &_viBullet4->rc))
			{

				_viBullet4 = _vBullet4.erase(_viBullet4);
			}

		}
		for (_viBullet5 = _vBullet5.begin(); _viBullet5 != _vBullet5.end(); ++_viBullet5)
		{
			if (IntersectRect(&RectMake(0, 0, 0, 0), &removerc, &_viBullet5->rc))
			{

				_viBullet5 = _vBullet5.erase(_viBullet5);
			}

		}
		for (_viBullet6 = _vBullet6.begin(); _viBullet6 != _vBullet6.end(); ++_viBullet6)
		{
			if (IntersectRect(&RectMake(0, 0, 0, 0), &removerc, &_viBullet6->rc))
			{

				_viBullet6 = _vBullet6.erase(_viBullet6);
			}

		}
	}
	if (torturn)
	{
		if (goodman)

		{
			if (goodmancount % 5 == 0)
				goodmanalpha = 250;
			if (goodmancount % 5 == 1)
				goodmanalpha = 0;

			if (goodmancount > 100)
			{
				goodman = false;
				goodmancount = 0;
			}
			else goodmancount++;
		}

		for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
		{
			if (IntersectRect(&RectMake(0, 0, 0, 0), &heartbox, &_viBullet->rc) && !goodman)
			{
				_viBullet = _vBullet.erase(_viBullet);
				_player->getPlayer()->CurHp -= 3;
				goodman = true;
				if (!SOUNDMANAGER->isPlaySound("playerhit"))
					SOUNDMANAGER->play("playerhit", 1.f);


			}
		}
		for (_viBullet2 = _vBullet2.begin(); _viBullet2 != _vBullet2.end(); ++_viBullet2)
		{
			if (IntersectRect(&RectMake(0, 0, 0, 0), &heartbox, &_viBullet2->rc) && !goodman)
			{

				_viBullet2 = _vBullet2.erase(_viBullet2);
				_player->getPlayer()->CurHp += 3;
				

				if (!SOUNDMANAGER->isPlaySound("heal"))
					SOUNDMANAGER->play("heal", 1.f);

			}

		}

		for (_viBullet3 = _vBullet3.begin(); _viBullet3 != _vBullet3.end(); ++_viBullet3)
		{
			if (IntersectRect(&RectMake(0, 0, 0, 0), &heartbox, &_viBullet3->rc) && !goodman)
			{
				_viBullet3 = _vBullet3.erase(_viBullet3);
				_player->getPlayer()->CurHp -= 3;
				goodman = true;
				if (!SOUNDMANAGER->isPlaySound("playerhit"))
					SOUNDMANAGER->play("playerhit", 1.f);


			}

		}
		for (_viBullet4 = _vBullet4.begin(); _viBullet4 != _vBullet4.end(); ++_viBullet4)
		{
			if (IntersectRect(&RectMake(0, 0, 0, 0), &heartbox, &_viBullet4->rc) && !goodman)
			{

				_viBullet4 = _vBullet4.erase(_viBullet4);
				_player->getPlayer()->CurHp -= 3;
				goodman = true;

				if (!SOUNDMANAGER->isPlaySound("playerhit"))
					SOUNDMANAGER->play("playerhit", 1.f);

			}

		}

		for (_viBullet5 = _vBullet5.begin(); _viBullet5 != _vBullet5.end(); ++_viBullet5)
		{
			if (IntersectRect(&RectMake(0, 0, 0, 0), &heartbox, &_viBullet5->rc) && !goodman)
			{

				_viBullet5 = _vBullet5.erase(_viBullet5);
				_player->getPlayer()->CurHp -= 3;
				goodman = true;

				if (!SOUNDMANAGER->isPlaySound("playerhit"))
					SOUNDMANAGER->play("playerhit", 1.f);

			}

		}

		for (_viBullet6 = _vBullet6.begin(); _viBullet6 != _vBullet6.end(); ++_viBullet6)
		{
			if (IntersectRect(&RectMake(0, 0, 0, 0), &heartbox, &_viBullet6->rc) && !goodman)
			{

				_viBullet6 = _vBullet6.erase(_viBullet6);
				_player->getPlayer()->CurHp -= 3;
				goodman = true;

				if (!SOUNDMANAGER->isPlaySound("playerhit"))
					SOUNDMANAGER->play("playerhit", 1.f);

			}

		}

	}
}

void monster1::fire(float x, float y)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (_viBullet->fire) continue;

		_viBullet->fire = true;
		_viBullet->x = _viBullet->fireX = x;
		_viBullet->y = _viBullet->fireY = y;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getFrameWidth(),
			_viBullet->bulletImage->getFrameHeight());
		firecount1 += 1;
		break;
	}
}

void monster1::move()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (!_viBullet->fire) continue;

		_viBullet->x += movex;
		if(_viBullet->speed < 5.f)
		_viBullet->speed += 0.04f;
		
			_viBullet->y += _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getFrameWidth(),
			_viBullet->bulletImage->getFrameHeight());


	}
}



void monster1::fire2(float x, float y)
{
	for (_viBullet2 = _vBullet2.begin(); _viBullet2 != _vBullet2.end(); ++_viBullet2)
	{
		if (_viBullet2->fire) continue;

		_viBullet2->fire = true;
		_viBullet2->x = _viBullet2->fireX = x;
		_viBullet2->y = _viBullet2->fireY = y;
		_viBullet2->rc = RectMakeCenter(_viBullet2->x, _viBullet2->y,
			_viBullet2->bulletImage->getFrameWidth() ,
			_viBullet2->bulletImage->getFrameHeight());
		firecount2 += 1;
		break;
	}
}

void monster1::move2()
{
	for (_viBullet2 = _vBullet2.begin(); _viBullet2 != _vBullet2.end(); ++_viBullet2)
	{
		if (!_viBullet2->fire) continue;

		
		if (_viBullet2->speed < 3.f)
			_viBullet2->speed += 0.02f;
		if (_viBullet2->y < 380)
			_viBullet2->y += _viBullet2->speed;
		_viBullet2->rc = RectMakeCenter(_viBullet2->x, _viBullet2->y,
			_viBullet2->bulletImage->getFrameWidth(),
			_viBullet2->bulletImage->getFrameHeight());


	}
}

void monster1::fire3(float x, float y, float angle, float speed)
{
	for (_viBullet3 = _vBullet3.begin(); _viBullet3 != _vBullet3.end(); ++_viBullet3)
	{
		if (_viBullet3->fire) continue;

		_viBullet3->fire = true;
		_viBullet3->x = _viBullet3->fireX = x;
		_viBullet3->y = _viBullet3->fireY = y;
		_viBullet3->rc = RectMakeCenter(_viBullet3->x, _viBullet3->y,
			_viBullet3->bulletImage->getFrameWidth() ,
			_viBullet3->bulletImage->getFrameHeight());
		firecount1 += 1;
		break;
	}
}

void monster1::move3()
{
	for (_viBullet3 = _vBullet3.begin(); _viBullet3 != _vBullet3.end(); ++_viBullet3)
	{
		if (!_viBullet3->fire) continue;

		//_viBullet5->x += cosf(_viBullet5->angle) * _viBullet5->speed;
		//_viBullet5->y += -sinf(_viBullet5->angle) * _viBullet5->speed;


		_viBullet3->x += cosf(_viBullet3->angle) * _viBullet3->speed ;
		_viBullet3->y += -sinf(_viBullet3->angle) * _viBullet3->speed ;
		if (_viBullet3->speed > 1.f)
			_viBullet3->speed -= 0.02f;
		if (_viBullet3->x < 240)
		{
			_viBullet3->angle = PI - _viBullet3->angle;
			_viBullet3->speed = 3.f;

		}
		if (_viBullet3->x > 400)
		{
			_viBullet3->angle = PI - _viBullet3->angle;
			_viBullet3->speed = 3.f;
		}
		if (_viBullet3->y > 370)
		{
			_viBullet3->angle = 2 * PI - _viBullet3->angle;
			_viBullet3->speed = 3.f;
		}
		if (_viBullet3->y < 260)
		{
			_viBullet3->angle = 2 * PI - _viBullet3->angle;
			_viBullet3->speed = 3.f;
		}


		_viBullet3->rc = RectMakeCenter(_viBullet3->x, _viBullet3->y,
			_viBullet3->bulletImage->getFrameWidth(),
			_viBullet3->bulletImage->getFrameHeight());


	}
}

void monster1::fire4(float x, float y, float angle, float speed)
{
	for (_viBullet4 = _vBullet4.begin(); _viBullet4 != _vBullet4.end(); ++_viBullet4)
	{
		if (_viBullet4->fire) continue;

		_viBullet4->fire = true;
		_viBullet4->x = _viBullet4->fireX = x;
		_viBullet4->y = _viBullet4->fireY = y;
		_viBullet4->rc = RectMakeCenter(_viBullet4->x, _viBullet4->y,
			_viBullet4->bulletImage->getFrameWidth() ,
			_viBullet4->bulletImage->getFrameHeight() );
		firecount2 += 1;
		break;
	}
}

void monster1::move4()
{
	for (_viBullet4 = _vBullet4.begin(); _viBullet4 != _vBullet4.end(); ++_viBullet4)
	{
		if (!_viBullet4->fire) continue;

		//_viBullet5->x += cosf(_viBullet5->angle) * _viBullet5->speed;
		//_viBullet5->y += -sinf(_viBullet5->angle) * _viBullet5->speed;


		_viBullet4->x += cosf(_viBullet4->angle) * _viBullet4->speed;
		_viBullet4->y += -sinf(_viBullet4->angle) * _viBullet4->speed;
		if (_viBullet4->speed > 1.f)
			_viBullet4->speed -= 0.02f;
		if (_viBullet4->x < 240)
		{
			_viBullet4->angle = PI - _viBullet4->angle;
			_viBullet4->speed = 3.f;

		}
		if (_viBullet4->x > 400)
		{
			_viBullet4->angle = PI - _viBullet4->angle;
			_viBullet4->speed = 3.f;
		}
		if (_viBullet4->y > 370)
		{
			_viBullet4->angle = 2 * PI - _viBullet4->angle;
			_viBullet4->speed = 3.f;
		}
		if (_viBullet4->y < 260)
		{
			_viBullet4->angle = 2 * PI - _viBullet4->angle;
			_viBullet4->speed = 3.f;
		}


		_viBullet4->rc = RectMakeCenter(_viBullet4->x, _viBullet4->y,
			_viBullet4->bulletImage->getFrameWidth(),
			_viBullet4->bulletImage->getFrameHeight());


	}
}

void monster1::fire5(float x, float y, float angle, float speed)
{
	for (_viBullet5 = _vBullet5.begin(); _viBullet5 != _vBullet5.end(); ++_viBullet5)
	{
		if (_viBullet5->fire) continue;

		_viBullet5->fire = true;
		_viBullet5->x = _viBullet5->fireX = x;
		_viBullet5->y = _viBullet5->fireY = y;
		_viBullet5->rc = RectMakeCenter(_viBullet5->x, _viBullet5->y,
			_viBullet5->bulletImage->getFrameWidth() ,
			_viBullet5->bulletImage->getFrameHeight() );
		_viBullet5->angle = angle;
		_viBullet5->speed = speed;
		firecount2 += 1;
		break;
	}
}



void monster1::move5()
{
	for (_viBullet5 = _vBullet5.begin(); _viBullet5 != _vBullet5.end(); ++_viBullet5)
	{
		if (!_viBullet5->fire) continue;

		//_viBullet5->x += cosf(_viBullet5->angle) * _viBullet5->speed;
		//_viBullet5->y += -sinf(_viBullet5->angle) * _viBullet5->speed;


		_viBullet5->x += cosf(_viBullet5->angle) * _viBullet5->speed;
		_viBullet5->y += -sinf(_viBullet5->angle) * _viBullet5->speed;
		if(_viBullet5->speed > 1.f)
		_viBullet5->speed -= 0.02f;
		if (_viBullet5->x < 240)
		{
			_viBullet5->angle = PI - _viBullet5->angle;
			_viBullet5->speed = 3.f;

		}
		if (_viBullet5->x > 400)
		{
			_viBullet5->angle = PI - _viBullet5->angle;
			_viBullet5->speed = 3.f;
		}
		if (_viBullet5->y > 370)
		{
			_viBullet5->angle = 2 * PI - _viBullet5->angle;
			_viBullet5->speed = 3.f;
		}
		if (_viBullet5->y < 260)
		{
			_viBullet5->angle = 2 * PI - _viBullet5->angle;
			_viBullet5->speed = 3.f;
		}
		

		_viBullet5->rc = RectMakeCenter(_viBullet5->x, _viBullet5->y,
			_viBullet5->bulletImage->getFrameWidth() ,
			_viBullet5->bulletImage->getFrameHeight() );


	}
}

void monster1::fire6(float x, float y, float angle, float speed)
{
	for (_viBullet6 = _vBullet6.begin(); _viBullet6 != _vBullet6.end(); ++_viBullet6)
	{
		if (_viBullet6->fire) continue;

		_viBullet6->fire = true;
		_viBullet6->x = _viBullet6->fireX = x;
		_viBullet6->y = _viBullet6->fireY = y;
		_viBullet6->rc = RectMakeCenter(_viBullet6->x, _viBullet6->y,
			_viBullet6->bulletImage->getFrameWidth() ,
			_viBullet6->bulletImage->getFrameHeight() );
		//firecount2 += 1;
		break;
	}
}

void monster1::move6()
{
	for (_viBullet6 = _vBullet6.begin(); _viBullet6 != _vBullet6.end(); ++_viBullet6)
	{
		if (!_viBullet6->fire) continue;

		//_viBullet5->x += cosf(_viBullet5->angle) * _viBullet5->speed;
		//_viBullet5->y += -sinf(_viBullet5->angle) * _viBullet5->speed;


		_viBullet6->x += cosf(_viBullet6->angle) * _viBullet6->speed * _viBullet6->collx;
		_viBullet6->y += -sinf(_viBullet6->angle) * _viBullet6->speed * _viBullet6->collx;
		if (_viBullet6->speed > 1.f)
			_viBullet6->speed -= 0.02f;
		if (_viBullet6->x < 240)
		{
			_viBullet6->angle = PI - _viBullet6->angle;
			_viBullet6->speed = 3.f;

		}
		if (_viBullet6->x > 400)
		{
			_viBullet6->angle = PI - _viBullet6->angle;
			_viBullet6->speed = 3.f;
		}
		if (_viBullet6->y > 370)
		{
			_viBullet6->angle = 2 * PI - _viBullet6->angle;
			_viBullet6->speed = 3.f;
		}
		if (_viBullet6->y < 260)
		{
			_viBullet6->angle = 2 * PI - _viBullet6->angle;
			_viBullet6->speed = 3.f;
		}


		_viBullet6->rc = RectMakeCenter(_viBullet6->x, _viBullet6->y,
			_viBullet6->bulletImage->getFrameWidth(),
			_viBullet6->bulletImage->getFrameHeight());


	}
}


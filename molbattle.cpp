#include "stdafx.h"
#include "molbattle.h"
#include "player.h"
#include "camera.h"

molbattle::molbattle()
{
}


molbattle::~molbattle()
{
}

HRESULT molbattle::init()
{
	attack = false;
	if (SOUNDMANAGER->isPlaySound("stagesound"))
	{
		SOUNDMANAGER->pause("stagesound");
	}
	for (int i = 0; i < bulletmax; i++)
	{
		tagmol bullet;


		bullet.bulletImage = IMAGEMANAGER->addFrameImage("bullet1", "image/undertale/battle/molbattle/bullet1.bmp", 10, 10,1,1, true, (RGB(255, 0, 255)));
		bullet.speed = 0.1f;
		bullet.fire = false;
		bullet.count = 0;
		bullet.index = 0;
		bullet.rndy = 0;
		bullet.rndx = 0;
		bullet.angle = PI / 2 * 3;

		_vBullet.push_back(bullet);
	}
	for (int i = 0; i < bulletmax; i++)
	{
		tagmol2 bullet2;


		bullet2.bulletImage = IMAGEMANAGER->addFrameImage("bullet2", "image/undertale/battle/molbattle/bullet2.bmp", 3, 3,1,1, true, (RGB(255, 0, 255)));
		bullet2.speed = 1.1f;
		bullet2.fire = false;
		bullet2.count = 0;
		bullet2.index = 0;
		bullet2.angle = PI;



		_vBullet2.push_back(bullet2);
	}
	
	molturn = false;
	firerndx = 0;
	IMAGEMANAGER->addImage("talkrect", "image/undertale/battle/torielbattle/talkRect.bmp",102, 114, true, RGB(255, 0, 255));

	//mol image
	{//mol image
		IMAGEMANAGER->addImage("mol1", "image/undertale/battle/molbattle/mol1.bmp", 96, 92, false, false);
		IMAGEMANAGER->addImage("mol2", "image/undertale/battle/molbattle/mol2.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol3", "image/undertale/battle/molbattle/mol3.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol4", "image/undertale/battle/molbattle/mol4.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol5", "image/undertale/battle/molbattle/mol5.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol6", "image/undertale/battle/molbattle/mol6.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol7", "image/undertale/battle/molbattle/mol7.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol8", "image/undertale/battle/molbattle/mol8.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol9", "image/undertale/battle/molbattle/mol9.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol10", "image/undertale/battle/molbattle/mol10.bmp", 96 , 92, false, false);

		IMAGEMANAGER->addImage("mol11", "image/undertale/battle/molbattle/mol11.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol12", "image/undertale/battle/molbattle/mol12.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol13", "image/undertale/battle/molbattle/mol13.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol14", "image/undertale/battle/molbattle/mol14.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol15", "image/undertale/battle/molbattle/mol15.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol16", "image/undertale/battle/molbattle/mol16.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol17", "image/undertale/battle/molbattle/mol17.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol18", "image/undertale/battle/molbattle/mol18.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol19", "image/undertale/battle/molbattle/mol19.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol20", "image/undertale/battle/molbattle/mol20.bmp", 96 , 92, false, false);

		IMAGEMANAGER->addImage("mol21", "image/undertale/battle/molbattle/mol21.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol22", "image/undertale/battle/molbattle/mol22.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol23", "image/undertale/battle/molbattle/mol23.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol24", "image/undertale/battle/molbattle/mol24.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol25", "image/undertale/battle/molbattle/mol25.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol26", "image/undertale/battle/molbattle/mol26.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol27", "image/undertale/battle/molbattle/mol27.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol28", "image/undertale/battle/molbattle/mol28.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol29", "image/undertale/battle/molbattle/mol29.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol30", "image/undertale/battle/molbattle/mol30.bmp", 96 , 92, false, false);

		IMAGEMANAGER->addImage("mol31", "image/undertale/battle/molbattle/mol31.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol32", "image/undertale/battle/molbattle/mol32.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol33", "image/undertale/battle/molbattle/mol33.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol34", "image/undertale/battle/molbattle/mol34.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol35", "image/undertale/battle/molbattle/mol35.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol36", "image/undertale/battle/molbattle/mol36.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol37", "image/undertale/battle/molbattle/mol37.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol38", "image/undertale/battle/molbattle/mol38.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol39", "image/undertale/battle/molbattle/mol39.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol40", "image/undertale/battle/molbattle/mol40.bmp", 96 , 92, false, false);

		IMAGEMANAGER->addImage("mol41", "image/undertale/battle/molbattle/mol41.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol42", "image/undertale/battle/molbattle/mol42.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol43", "image/undertale/battle/molbattle/mol43.bmp", 96 , 92, false, false);
		IMAGEMANAGER->addImage("mol44", "image/undertale/battle/molbattle/mol44.bmp", 96 , 92, false, false);
		
		IMAGEMANAGER->addImage("die1", "image/undertale/battle/molbattle/die1.bmp", 128, 124, false, false);
		IMAGEMANAGER->addImage("die2", "image/undertale/battle/molbattle/die2.bmp", 128, 124, false, false);
		IMAGEMANAGER->addImage("die3", "image/undertale/battle/molbattle/die3.bmp", 128, 124, false, false);
		IMAGEMANAGER->addImage("die4", "image/undertale/battle/molbattle/die4.bmp", 128, 124, false, false);
		IMAGEMANAGER->addImage("die5", "image/undertale/battle/molbattle/die5.bmp", 128, 124, false, false);
		IMAGEMANAGER->addImage("die6", "image/undertale/battle/molbattle/die6.bmp", 128, 124, false, false);
		IMAGEMANAGER->addImage("die7", "image/undertale/battle/molbattle/die7.bmp", 128, 124, false, false);
		IMAGEMANAGER->addImage("die8", "image/undertale/battle/molbattle/die8.bmp", 128, 124, false, false);
		IMAGEMANAGER->addImage("die9", "image/undertale/battle/molbattle/die9.bmp", 128, 124, false, false);
		IMAGEMANAGER->addImage("die10", "image/undertale/battle/molbattle/die10.bmp", 128, 124, false, false);
		IMAGEMANAGER->addImage("die11", "image/undertale/battle/molbattle/die11.bmp", 128, 124, false, false);
		IMAGEMANAGER->addImage("die12", "image/undertale/battle/molbattle/die12.bmp", 128, 124, false, false);
	}  
	// ---  ---
	IMAGEMANAGER->addImage("molbase", "image/undertale/battle/molbattle/molbase.bmp", 609, 236, false, false);
	_player->getPlayer()->changeScene = false;
	_player->getPlayer()->playertor = true;
	_player->getPlayer()->x = 300;
	_player->getPlayer()->y = 300;
	IMAGEMANAGER->addImage("torielbattle_base", "image/undertale/battle/torielbattle/torielbattle_base.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("torielbattle_toriel", "image/undertale/battle/torielbattle/torielbattle_toriel.bmp", 142, 198, false, false);
	lvnumber = IMAGEMANAGER->addFrameImage("lvnumber", "image/undertale/battle/number.bmp", 120, 15, 10, 1, false, false);
	curhpnumber1 = IMAGEMANAGER->addFrameImage("curhpnumber1", "image/undertale/battle/number.bmp", 120, 15, 10, 1, false, false);
	curhpnumber10 = IMAGEMANAGER->addFrameImage("curhpnumber10", "image/undertale/battle/number.bmp", 120, 15, 10, 1, false, false);
	maxhpnumber1 = IMAGEMANAGER->addFrameImage("maxhpnumber1", "image/undertale/battle/number.bmp", 120, 15, 10, 1, false, false);
	maxhpnumber10 = IMAGEMANAGER->addFrameImage("maxhpnumber10", "image/undertale/battle/number.bmp", 120, 15, 10, 1, false, false);
	mol_act = IMAGEMANAGER->addFrameImage("tb_act", "image/undertale/battle/torielbattle/act.bmp", 330, 42, 3, 1, false, false);
	mol_fight = IMAGEMANAGER->addFrameImage("tb_fight", "image/undertale/battle/torielbattle/fight.bmp", 330, 42, 3, 1, false, false);
	mol_item = IMAGEMANAGER->addFrameImage("tb_item", "image/undertale/battle/torielbattle/item.bmp", 330, 42, 3, 1, false, false);
	mol_mercy = IMAGEMANAGER->addFrameImage("tb_mercy", "image/undertale/battle/torielbattle/mercy.bmp", 330, 42, 3, 1, false, false);
	IMAGEMANAGER->addImage("more_mercy", "image/undertale/battle/torielbattle/more_mercy.bmp", 177, 68, false, false);
	IMAGEMANAGER->addImage("torielhand", "image/undertale/battle/torielbattle/torielhand.bmp", 56, 38, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("textbox", "image/undertale/battle/torielbattle/textbox.bmp", 575, 140, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("m3battlebox", "image/undertale/battle/torielbattle/battlebox.bmp", 165, 140, true, RGB(255, 0, 255));
	attackeffect = IMAGEMANAGER->addFrameImage("attackeffect", "image/undertale/battle/torielbattle/attackeffect.bmp", 693, 154, 7, 1, true, RGB(255, 0, 255));
	attackeffectcount = 0;
	attackeffectindex = 0;
	number1 = IMAGEMANAGER->addFrameImage("number1", "image/undertale/battle/number2.bmp", 280, 27, 10, 1, false, false);
	number10 = IMAGEMANAGER->addFrameImage("number10", "image/undertale/battle/number2.bmp", 280, 27, 10, 1, false, false);
	number100 = IMAGEMANAGER->addFrameImage("number100", "image/undertale/battle/number2.bmp", 280, 27, 10, 1, false, false);
	number1000 = IMAGEMANAGER->addFrameImage("number1000", "image/undertale/battle/number2.bmp", 280, 27, 10, 1, false, false);
	IMAGEMANAGER->addImage("miss", "image/undertale/battle/torielbattle/miss.bmp", 118, 30, true, RGB(255, 0, 255));

	heartrun = IMAGEMANAGER->addFrameImage("heartrun", "image/undertale/battle/torielbattle/heartrun.bmp", 32, 24, 2, 1, true, RGB(255, 0, 255));
	heartruncount = 0;
	heartrunindex = 0;
	heartrun->setX(60);
	heartrun->setY(325);

	molrenderindex = 1;
	molrendercount = 0;

	molcurhp = 50;
	molmaxhp = 50;

	point = 1;
	rndtextnum = 0;

	textboxmovex = 32;
	textboxsmallerx = 575;
	
	textnum = 1;
	tcount = 0;
	tindex = 0;

	moreact = false;
	morefight = false;
	moreitem = false;
	moremercy = false;
	act = false;
	fight = false;
	item = false;
	mercy = false;
	moremoreact = false;
	moremorefight = false;

	text3heartcontrolx = 80;
	text3heartcontroly = 270;

	goodman = false;
	goodmanalpha = 250;
	goodmancount = 0;
	once = false;


	IMAGEMANAGER->addImage("torhpmax", "image/undertale/battle/torielbattle/torhpmax.bmp", 101, 17, false, false);
	IMAGEMANAGER->addImage("torhpmin", "image/undertale/battle/torielbattle/torhpmin.bmp", 101, 17, false, false);
	IMAGEMANAGER->addImage("attackgage", "image/undertale/battle/torielbattle/gage.bmp", 565, 130, false, false);
	attackbar = IMAGEMANAGER->addFrameImage("attackbar", "image/undertale/battle/torielbattle/attackbar.bmp", 28, 130, 2, 1, false, false);
	attackbarmovex = 37;
	attackgagegone = IMAGEMANAGER->addFrameImage("attackgagegone", "image/undertale/battle/torielbattle/gagegone.bmp", 7345, 130, 13, 1, false, false);

	isyouattack = false;
	attackgagecount = 0;
	attackgageindex = 0;
	stopbar = false;
	attackeffect = IMAGEMANAGER->addFrameImage("attackeffect", "image/undertale/battle/torielbattle/attackeffect.bmp", 693, 154, 7, 1, true, RGB(255, 0, 255));
	attackeffectcount = 0;
	attackeffectindex = 0;
	IMAGEMANAGER->addImage("torhpmin2", "image/undertale/battle/torielbattle/torhpmin2.bmp", 101, 17, false, false);
	gagegoneframe = false;
	index = 0;
	count = 0;
	attack = false;
	onceattacksound1 = false;
	onceattacksound2 = false;
	yourdmgbar = 0;
	molboom = false;

	boomx = 0;
	indexx = 0;
	boomover = false;
	moldie = false;
	diecount = 0;
	dieindex = 0;
	dieover = false;

	moremercyxheartx = 50;

	run = false;
	runcount = 0;

	moltextcount = 0;
	moltextnum = 0;

	textrc2 = RectMake(440, 140, 100, 50);
	rndtextnum2 = 0;
	dieonce = false;
	if (!SOUNDMANAGER->isPlaySound("battlesound"))
	{
		SOUNDMANAGER->play("battlesound", 1.f);
	}
	return S_OK;
}

void molbattle::release()
{
}

void molbattle::update()
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
	moltextnum = 1;
	TextControlUpdate();
	_camera->getCam()->x = 0;
	_camera->getCam()->y = 0;
	

	if (run)runOut();
	//if (!moldie)


	{
		EraseAndFire2();
		NumberSet();
		if (!molturn)
			BattleControl();

		move();
		move2();
		textrc = RectMake(60 + _camera->getCam()->x + 20, 255 + _camera->getCam()->y, 565, 130);
		removerc = RectMake(0, 0, 640, 480);
		heartbox = RectMake(_player->getPlayer()->x + 2, _player->getPlayer()->y + 2, 10, 10);
		//molturn = true;
		if (molturn)
		{
			firecount++;
			if (firecount % 100 == 0)
			{
				firerndx = RND->getFromIntTo(250, 390);
				fire(firerndx, 250, PI / 2 * 3, 1.f);
			}
			if (firecount > 600)molturn = false;
			//firecount++;
			if (firecount < 200)
			{
				//moltextnum = 1;
				if (rndtextnum2 == 1)
				{
					tindex = 18;
					moltextnum = 1;
				}
				if (rndtextnum2 == 2)
				{
					tindex = 16;
					moltextnum = 2;
				}
				
			}
			else if(firecount > 300)
			{
				tindex = 0;
			}
			
			moreact = false;
			morefight = false;
			moreitem = false;
			moremercy = false;
			act = false;
			fight = false;
			item = false;
			mercy = false;
			moremoreact = false;
			moremorefight = false;
			//tindex = 0;
			onceattacksound1 = false;
			onceattacksound2 = false;
			rndtextnum = RND->getFromIntTo(1, 2);
			if (rndtextnum == 1) textnum = 8;
			if (rndtextnum == 2) textnum = 7;
			attackbarmovex = 37;

		}
		if (!molturn)
		{
			if (ismolunderattack)molunderattack();
			firecount = 0;
			if (goodmanalpha != 250)goodmanalpha = 250;
			moltextcount = 0;
			rndtextnum2 = RND->getFromIntTo(1, 2);
			
		}
		removebullet();
		molrendercount++;
		{

			if (molrenderindex > 43) molrenderindex = 1;
			else
			{
				if (molrendercount % 3 == 0)molrenderindex++;
			}
		}
	
		
	}

	if (moldie && !dieover)
	{
		diecount++;
		if (diecount % 5 == 0)dieindex++;
		if (dieindex > 12)dieover = true;
	}
	if (moldie)
	{
		if (!SOUNDMANAGER->isPlaySound("monsterdead")&&dieonce)
		{
			SOUNDMANAGER->play("monsterdead", 1.f);
			dieonce = true;
		}
		attackeffectcount = 0;
		attackeffectindex = 0;
		molturn = false;
		textnum = 13;
		heartruncount = 0;
		heartrunindex = 0;
		heartrun->setX(60);
		heartrun->setY(325);

		molrenderindex = 1;
		molrendercount = 0;

		

		point = 1;
		rndtextnum = 0;

		textboxmovex = 32;
		textboxsmallerx = 575;

		
		

		moreact = false;
		morefight = false;
		moreitem = false;
		moremercy = false;
		act = false;
		fight = false;
		item = false;
		mercy = false;
		moremoreact = false;
		moremorefight = false;

		text3heartcontrolx = 80;
		text3heartcontroly = 270;

		goodman = false;
		goodmanalpha = 250;
		goodmancount = 0;
		isyouattack = false;
		attackgagecount = 0;
		attackgageindex = 0;
		stopbar = false;
		attackeffectcount = 0;
		attackeffectindex = 0;
		gagegoneframe = false;
		index = 0;
		count = 0;
		attack = false;
		onceattacksound1 = false;
		onceattacksound2 = false;
		yourdmgbar = 0;
		molboom = false;

		
	
		boomover = false;
		


	}
}

void molbattle::render()
{
	IMAGEMANAGER->findImage("dark")->render(getMemDC());
	IMAGEMANAGER->findImage("molbase")->render(getMemDC(),14,10);

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

	
	//mol render
	if(!moldie)
	{
		if (molrenderindex == 1)IMAGEMANAGER->findImage("mol1")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 2)IMAGEMANAGER->findImage("mol2")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 3)IMAGEMANAGER->findImage("mol3")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 4)IMAGEMANAGER->findImage("mol4")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 5)IMAGEMANAGER->findImage("mol5")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 6)IMAGEMANAGER->findImage("mol6")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 7)IMAGEMANAGER->findImage("mol7")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 8)IMAGEMANAGER->findImage("mol8")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 9)IMAGEMANAGER->findImage("mol9")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 10)IMAGEMANAGER->findImage("mol10")->render(getMemDC(), 320 + boomx, 140);

		if (molrenderindex == 11)IMAGEMANAGER->findImage("mol11")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 12)IMAGEMANAGER->findImage("mol12")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 13)IMAGEMANAGER->findImage("mol13")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 14)IMAGEMANAGER->findImage("mol14")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 15)IMAGEMANAGER->findImage("mol15")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 16)IMAGEMANAGER->findImage("mol16")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 17)IMAGEMANAGER->findImage("mol17")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 18)IMAGEMANAGER->findImage("mol18")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 19)IMAGEMANAGER->findImage("mol19")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 20)IMAGEMANAGER->findImage("mol20")->render(getMemDC(), 320+boomx, 140);

		if (molrenderindex == 21)IMAGEMANAGER->findImage("mol21")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 22)IMAGEMANAGER->findImage("mol22")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 23)IMAGEMANAGER->findImage("mol23")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 24)IMAGEMANAGER->findImage("mol24")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 25)IMAGEMANAGER->findImage("mol25")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 26)IMAGEMANAGER->findImage("mol26")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 27)IMAGEMANAGER->findImage("mol27")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 28)IMAGEMANAGER->findImage("mol28")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 29)IMAGEMANAGER->findImage("mol29")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 30)IMAGEMANAGER->findImage("mol30")->render(getMemDC(), 320+boomx, 140);

		if (molrenderindex == 31)IMAGEMANAGER->findImage("mol31")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 32)IMAGEMANAGER->findImage("mol32")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 33)IMAGEMANAGER->findImage("mol33")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 34)IMAGEMANAGER->findImage("mol34")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 35)IMAGEMANAGER->findImage("mol35")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 36)IMAGEMANAGER->findImage("mol36")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 37)IMAGEMANAGER->findImage("mol37")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 38)IMAGEMANAGER->findImage("mol38")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 39)IMAGEMANAGER->findImage("mol39")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 40)IMAGEMANAGER->findImage("mol40")->render(getMemDC(), 320+boomx, 140);

		if (molrenderindex == 41)IMAGEMANAGER->findImage("mol41")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 42)IMAGEMANAGER->findImage("mol42")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 43)IMAGEMANAGER->findImage("mol43")->render(getMemDC(), 320+boomx, 140);
		if (molrenderindex == 44)IMAGEMANAGER->findImage("mol44")->render(getMemDC(), 320+boomx, 140);
		
	}
	
	
	if (moldie)
	{
		if(dieindex == 1)IMAGEMANAGER->findImage("die1")->render(getMemDC(), 304 , 122);
		if (dieindex == 2)IMAGEMANAGER->findImage("die2")->render(getMemDC(), 304, 122);
		if (dieindex == 3)IMAGEMANAGER->findImage("die3")->render(getMemDC(), 304, 122);
		if (dieindex == 4)IMAGEMANAGER->findImage("die4")->render(getMemDC(), 304, 122);
		if (dieindex == 5)IMAGEMANAGER->findImage("die5")->render(getMemDC(), 304, 122);
		if (dieindex == 6)IMAGEMANAGER->findImage("die6")->render(getMemDC(), 304, 122);
		if (dieindex == 7)IMAGEMANAGER->findImage("die7")->render(getMemDC(), 304, 122);
		if (dieindex == 8)IMAGEMANAGER->findImage("die8")->render(getMemDC(), 304, 122);
		if (dieindex == 9)IMAGEMANAGER->findImage("die9")->render(getMemDC(), 304, 122);
		if (dieindex == 10)IMAGEMANAGER->findImage("die10")->render(getMemDC(), 304, 122);
		if (dieindex == 11)IMAGEMANAGER->findImage("die11")->render(getMemDC(), 304, 122);
		if (dieindex == 12)IMAGEMANAGER->findImage("die12")->render(getMemDC(), 304, 122);
	}

	if (molturn && !moldie)
	{
		IMAGEMANAGER->findImage("m3battlebox")->render(getMemDC(), 240, 250);
		IMAGEMANAGER->findImage("heart")->alphaRender(getMemDC(), _player->getPlayer()->x, _player->getPlayer()->y,goodmanalpha);
	}
	if (!molturn)
	{
		IMAGEMANAGER->findImage("textbox")->render(getMemDC(), textboxmovex, 250, 0, 0, textboxsmallerx, 140);
		TextControl();
	}
	if (textnum == 2)
	{
		IMAGEMANAGER->findImage("heart")->render(getMemDC(), 80, 270);
	}
	if (textnum == 3)
	{
		IMAGEMANAGER->findImage("heart")->render(getMemDC(), text3heartcontrolx, text3heartcontroly);
	}
	if (textnum == 14)
	{
		IMAGEMANAGER->findImage("heart")->render(getMemDC(), moremercyxheartx, 270);
	}
	if (firecount < 200 && molturn)
	{
		IMAGEMANAGER->findImage("talkrect")->render(getMemDC(), 420, 120);
	}
	MolTextControl();
	if (run)
	{
		moremercy = false;
		textnum = 16;
		IMAGEMANAGER->findImage("heartrun")->frameRender(getMemDC(), heartrun->getX(), heartrun->getY());
	}
	if(textnum == 9)IMAGEMANAGER->findImage("heart")->render(getMemDC(), 80, 270);
	
	if (attackbarmovex >= 600)IMAGEMANAGER->findImage("miss")->render(getMemDC(), 260, 20);

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
	if (ismolunderattack)
	{
		
			IMAGEMANAGER->findImage("torhpmin2")->render(getMemDC(), 320, 120);
			IMAGEMANAGER->findImage("torhpmax")->render(getMemDC(), 320, 120, 0, 0, molimagehpbar, 17);

			IMAGEMANAGER->findImage("number1")->frameRender(getMemDC(), 370, 80);
			IMAGEMANAGER->findImage("number10")->frameRender(getMemDC(), 340, 80);
			


		
	}
	if (attack)
	{
		IMAGEMANAGER->findImage("attackeffect")->frameRender(getMemDC(), 310, 80);
	}
	if (!moldie)
	{
		for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
		{
			if (!_viBullet->fire) continue;
			if (_viBullet->x < 250 || _viBullet->x > 390 || _viBullet->y < 260 || _viBullet->y > 385) continue;
			_viBullet->bulletImage->frameRender(getMemDC(), _viBullet->rc.left - 5, _viBullet->rc.top - 10);

		}

		for (_viBullet2 = _vBullet2.begin(); _viBullet2 != _vBullet2.end(); ++_viBullet2)
		{
			if (!_viBullet2->fire) continue;
			if (_viBullet2->x < 250 || _viBullet2->x > 390 || _viBullet2->y < 260 || _viBullet2->y > 385) continue;

			_viBullet2->bulletImage->render(getMemDC(), _viBullet2->rc.left - 5, _viBullet2->rc.top - 10);

		}
	}
	if (_player->getPlayer()->viewEvery)
	{
		char str10[128];
		sprintf_s(str10, "textnum :  %d ", textnum);
		TextOut(getMemDC(), _camera->getCam()->x + 450, _camera->getCam()->y + 180, str10, strlen(str10));

		char str11[128];
		sprintf_s(str11, "tindex :  %d ", tindex);
		TextOut(getMemDC(), _camera->getCam()->x + 450, _camera->getCam()->y + 200, str11, strlen(str11));
		Rectangle(getMemDC(), heartbox.left, heartbox.top, heartbox.right, heartbox.bottom);
	}
	
}

void molbattle::fire(float x, float y, float angle, float speed)
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
		_viBullet->angle = angle;
		_viBullet->speed = speed;
		_viBullet->rndy = RND->getFromIntTo(260, 370);
		//_viBullet->rndx = RND->getFromIntTo(250, 390);
		break;

		
	}
}

void molbattle::move()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (!_viBullet->fire) continue;

		

		_viBullet->x += cosf(_viBullet->angle) * _viBullet->speed;

		_viBullet->y += -sinf(_viBullet->angle) * _viBullet->speed;


		if (_viBullet->speed < 1.f)
			_viBullet->speed += 0.1f;

		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getFrameWidth(),
			_viBullet->bulletImage->getFrameHeight());


	}
}

void molbattle::fire2(float x, float y, float angle, float speed)
{
	for (_viBullet2 = _vBullet2.begin(); _viBullet2 != _vBullet2.end(); ++_viBullet2)
	{
		if (_viBullet2->fire) continue;

		_viBullet2->fire = true;
		_viBullet2->x = _viBullet2->fireX = x;
		_viBullet2->y = _viBullet2->fireY = y;
		_viBullet2->rc = RectMakeCenter(_viBullet2->x, _viBullet2->y,
			_viBullet2->bulletImage->getFrameWidth(),
			_viBullet2->bulletImage->getFrameHeight());
		_viBullet2->angle = angle;
		_viBullet2->speed = speed;

		break;
	}
}

void molbattle::move2()
{
	for (_viBullet2 = _vBullet2.begin(); _viBullet2 != _vBullet2.end(); ++_viBullet2)
	{
		if (!_viBullet2->fire) continue;

		


		_viBullet2->x += cosf(_viBullet2->angle) * _viBullet2->speed;

		_viBullet2->y += -sinf(_viBullet2->angle) * _viBullet2->speed;


		if (_viBullet2->speed < 1.f)
			_viBullet2->speed += 0.1f;

		_viBullet2->rc = RectMakeCenter(_viBullet2->x, _viBullet2->y,
			_viBullet2->bulletImage->getFrameWidth(),
			_viBullet2->bulletImage->getFrameHeight());


	}
}

void molbattle::EraseAndFire2()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (!_viBullet->fire) continue;
		if (_viBullet->y > _viBullet->rndy)
		{

			_viBullet->speed = 0.f;
			for (int i = 0; i < 16; i++)
			{
				fire2(_viBullet->x, _viBullet->y, PI + PI / 8 * i, 0.1f);

			}
			_viBullet = _vBullet.erase(_viBullet);
			break;
		}
	}
}

void molbattle::NumberSet()
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
	molimagehpbar = (101 * molcurhp / molmaxhp);
}

void molbattle::BattleControl()
{
	if (gagegoneframe)
	{
		attack = false;
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
			molturn = true;
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
		mol_fight->setFrameX(0);
		mol_act->setFrameX(1);
		mol_item->setFrameX(1);
		mol_mercy->setFrameX(1);
	}
	if (act)
	{
		mol_act->setFrameX(0);
		mol_fight->setFrameX(1);
		mol_mercy->setFrameX(1);
		mol_item->setFrameX(1);
	}
	if (item)
	{
		mol_item->setFrameX(0);
		mol_fight->setFrameX(1);
		mol_act->setFrameX(1);
		mol_mercy->setFrameX(1);
	}
	if (mercy)
	{
		mol_mercy->setFrameX(0);
		mol_act->setFrameX(1);
		mol_fight->setFrameX(1);
		mol_item->setFrameX(1);
	}

	if (point == 1)
	{
		if (!morefight)
			fight = true;
		act = false;
		item = false;
		mercy = false;
		if (textnum == 1 || textnum == 7 || textnum == 8)
		{
			if (_player->getPlayer()->pressZ)
			{
				textnum = 9;
				morefight = true;
				if (!SOUNDMANAGER->isPlaySound("pointselect"))
				{
					SOUNDMANAGER->play("pointselect", 1.f);
				}

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
		if (textnum == 1 || textnum == 7 || textnum == 8)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				textnum = 2;
				moreact = true;
				if (!SOUNDMANAGER->isPlaySound("pointselect"))
				{
					SOUNDMANAGER->play("pointselect", 1.f);
				}

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
		if (textnum != 14)
		{
			if (_player->getPlayer()->pressZ && textnum != 14 && textnum != 15 && textnum != 16)
			{
				//textnum = 0;
				textnum = 14;
				moremercy = true;
				if (!SOUNDMANAGER->isPlaySound("pointselect"))
				{
					SOUNDMANAGER->play("pointselect", 1.f);
				}
			}
		}
	}
	if (moreact) mol_act->setFrameX(2);
	if (morefight)mol_fight->setFrameX(2);
	if (moreitem)mol_item->setFrameX(2);
	if (moremercy)mol_mercy->setFrameX(2);


	if (textnum != 10)
	{
		if (KEYMANAGER->isOnceDown(VK_LEFT))
		{
			if (point > 1 && !moreact && !morefight && !moreitem && !moremercy)
			{
				if (!SOUNDMANAGER->isPlaySound("pointmove"))
					SOUNDMANAGER->play("pointmove", 1.f);
				point -= 1;
			}
			if (textnum == 3)
			{
				text3heartcontrolx = 80;
				//moremoreactheartpoint = 60;


			}
			if (textnum == 14) moremercyxheartx = 50;

		}
		if (KEYMANAGER->isOnceDown(VK_RIGHT))
		{
			if (point < 4 && !moreact && !morefight && !moreitem && !moremercy)
			{
				if (!SOUNDMANAGER->isPlaySound("pointmove"))
					SOUNDMANAGER->play("pointmove", 1.f);
				point += 1;
			}
			if (textnum == 3)
			{
				text3heartcontrolx = 310;

				//moremoreactheartpoint = 300;

			}
			if (textnum == 14)moremercyxheartx = 260;
		}
		if (KEYMANAGER->isOnceDown(VK_UP))
		{
			if(textnum == 3)
			text3heartcontroly = 270;
		}
		if (KEYMANAGER->isOnceDown(VK_DOWN))
		{
			if(textnum == 3 && text3heartcontrolx == 80)
			text3heartcontroly = 310;
		}
	}
	// 취소버튼 ====
	if (KEYMANAGER->isOnceDown('X'))
	{

		if (textnum != 4 && textnum !=5 && textnum != 6 && textnum !=15 && textnum != 16 && textnum != 13)
		{
			if (moreact && !moremoreact)
			{
				moreact = false;
				
				if (rndtextnum == 1) textnum = 8;
				if (rndtextnum == 2) textnum = 7;
				if (rndtextnum == 0)textnum = 1;
			}
			if (moremoreact && textnum == 0)
			{
				moremoreact = false;
				moremoreactselect = false;
				textnum = 2;
			}
			if (morefight)
			{
				morefight = false;
				
				if (rndtextnum == 1) textnum = 8;
				if (rndtextnum == 2) textnum = 7;
				if (rndtextnum == 0)textnum = 1;
				
				
			}
			if (moreitem)
			{
				moreitem = false;
				
				if (rndtextnum == 1) textnum = 8;
				if (rndtextnum == 2) textnum = 7;
				if (rndtextnum == 0)textnum = 1;
				
				
			}
			if (moremercy)
			{
				moremercy = false;
				
				if (rndtextnum == 1) textnum = 8;
				if (rndtextnum == 2) textnum = 7;
				if (rndtextnum == 0)textnum = 1;
				
			}
		}
	}
	//때리기
	if (stopbar)
	{
		yourdmgbar = (attackbarmovex - 310) / 40;
		if (yourdmgbar < 0)
		{
			yourdmgbar = yourdmgbar * -1;
		}
	}
	
	yourdmg = (20 + _player->getPlayer()->At) - yourdmgbar;
	
	if (moremorefight)
	{
		if (attackbarmovex < 600)
		{
			if (!stopbar)
				attackbarmovex += 6;
			textnum = 0;
			if (_player->getPlayer()->pressZ)
			{
				
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

			countx = 0;
			indexx = 0;
			boomx = 0;
			molboom = 0;
			boomover = false;
			ismolunderattack = false;
			attackeffectindex = 0;
			attack = false;
			
			attackgageindex = 0;
			stopbar = false;
			dmgbefore = 0;
			goodman = false;
			goodmancount = 0;
			isyouattack = true;
			attackbarmovex = 37;
			molturn = true;

			textboxmovex = 32;
			textboxsmallerx = 575;

			if (attackgageindex > attackgagegone->getMaxFrameX())
			{
				//isyouattack = true;
			
				molturn = true;
				
			}
			else if (attackgagecount % 2 == 0)attackgageindex++;

			
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
			if(!moldie)
			ismolunderattack = true;
			if (moldie)tindex = 0;
		}
		else if (attackeffectcount % 8 == 0)attackeffectindex++;
	}
	// ---


	if (textnum == 3)
	{
		if (text3heartcontrolx == 80 && text3heartcontroly == 270) //살펴보기
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 4;
			}
		}
		if (text3heartcontrolx == 80 && text3heartcontroly == 310) // 작업걸기
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 6;
			}
		}
		if (text3heartcontrolx == 310) // 따라하기
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 5;
			}
		}
	}
	if (textnum == 9)
	{
		if (KEYMANAGER->isOnceDown('Z'))
		{
			moremorefight = true;
		}
	}
	if (textnum == 14)
	{
		
		{
			if (moremercyxheartx == 50)
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					tindex = 0;
					textnum = 15;
				}
			}
			else if (moremercyxheartx == 260)
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					textnum = 16;
					run = true;
				}
			}
		}
	}
	
}

void molbattle::TextControlUpdate()
{
	tcount++;
	//17,18,19,20 이 토리엘 기본대사
	if (tcount % 2 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 23)
				tindex++;
		}
		if (textnum == 2)
		{
			tindex = 14;
		}
		if (textnum == 3)
		{
			tindex = 50;
		}
		if (textnum == 4)
		{
			if (tindex < 73)
				tindex++;
		}
		if (textnum == 5)
		{
			if (tindex < 78)
				tindex++;
		}

		if (textnum == 6)
		{
			if (tindex < 84)
				tindex++;

		}
		if (textnum == 7)
		{
			if (tindex < 47)
				tindex++;
		}
		if (textnum == 8)
		{
			if (tindex < 38)
				tindex++;
		}
		if (textnum == 9)
		{
			if (tindex < 14)
				tindex++;
		}
		if (moltextnum == 1)
		{
			if (tindex < 18)
				tindex++;
		}
		if (moltextnum == 2)
		{
			if (tindex < 16)
				tindex++;
		}
		if (textnum == 13)
		{
			if (tindex < 35)
				tindex++;
		}
		if (textnum == 14)
		{
			tindex = 28;
			
		}
		if (textnum == 15)
		{
			if (tindex < 35)
				tindex++;

		}
		if (textnum == 16)
			tindex = 14;

	}
	
	if (textnum == 2)
	{
		if (tindex == 14 || tindex == 15)
		{
		
			if (KEYMANAGER->isOnceDown('Z'))
			{

				tindex = 0;
				textnum = 3;
				
			
			}
		}

	}
	
	if (textnum == 4)
	{
		if (tindex == 73)
		{

			if (KEYMANAGER->isOnceDown('Z'))
			{

				tindex = 0;
				textnum = 0;
				//isyouattack = true;
				molturn = true;

			}
		}

	}
	if (textnum == 5)
	{
		if (tindex == 78)
		{

			if (KEYMANAGER->isOnceDown('Z'))
			{

				tindex = 0;
				textnum = 0;
				//isyouattack = true;
				molturn = true;

			}
		}

	}
	if (textnum == 6)
	{
		if (tindex == 84)
		{

			if (KEYMANAGER->isOnceDown('Z'))
			{

				tindex = 0;
				textnum = 0;
				//isyouattack = true;
				molturn = true;

			}
		}

	}

	if (textnum == 9)
	{
		if (tindex == 14)
		{

			if (KEYMANAGER->isOnceDown('Z'))
			{

				tindex = 0;
				textnum = 0;
				moremorefight = true;

			}
		}

	}
	if (textnum == 13)
	{
		if (tindex == 35)
		{

			if (KEYMANAGER->isOnceDown('Z'))
			{
				_player->getPlayer()->CurExp += 2;
				_player->getPlayer()->Gold += 2;
				_player->getPlayer()->killnum += 1;

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
		}

	}

	if (textnum == 15)
	{
		if (tindex == 35)
		{

			if (KEYMANAGER->isOnceDown('Z'))
			{
				_player->getPlayer()->Gold += 2;

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
		}

	}
	
}

void molbattle::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/molbattle/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/molbattle/text2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("text/molbattle/text3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 4)
		hInputFile = CreateFile(_T("text/molbattle/text4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 5)
		hInputFile = CreateFile(_T("text/molbattle/text5.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 6)
		hInputFile = CreateFile(_T("text/molbattle/text6.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 7)
		hInputFile = CreateFile(_T("text/molbattle/text7.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 8)
		hInputFile = CreateFile(_T("text/molbattle/text8.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 9)
		hInputFile = CreateFile(_T("text/molbattle/text9.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 13)
		hInputFile = CreateFile(_T("text/molbattle/text13.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 14)
		hInputFile = CreateFile(_T("text/molbattle/text14.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 15)
		hInputFile = CreateFile(_T("text/molbattle/text15.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 16)
		hInputFile = CreateFile(_T("text/molbattle/text16.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

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

void molbattle::MolTextControlUpdate()
{
}

void molbattle::MolTextControl()
{
	HFONT font2 = CreateFont(20, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font2);
	SetTextColor(getMemDC(), RGB(0, 0, 0));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (moltextnum == 1)
		hInputFile = CreateFile(_T("text/molbattle/text11.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (moltextnum == 2)
		hInputFile = CreateFile(_T("text/molbattle/text12.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	
	ReadFile(hInputFile, buf, 999 * sizeof(TCHAR), &dwRead, NULL);
	CloseHandle(hInputFile);

	//TextOut(getMemDC(), 80, 200, buf, 2 * tindex);
	DrawText(getMemDC(), buf, tindex, &textrc2, DT_LEFT);
	DeleteObject(font2);
	font2 = CreateFont(20, 0, 0, 0, 0, 0, 0, 00, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, NULL);
	SelectObject(getMemDC(), font2);
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	DeleteObject(font2);
}

void molbattle::removebullet()
{
	if (!molturn)
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
	}
	if (molturn)
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
				goodmanalpha = 250;
			}
			else goodmancount++;
		}

		for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
		{
			if (IntersectRect(&RectMake(0, 0, 0, 0), &heartbox, &_viBullet->rc) && !goodman)
			{
				_viBullet = _vBullet.erase(_viBullet);
				_player->getPlayer()->CurHp -= 5;
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
				_player->getPlayer()->CurHp -= 2;
				goodman = true;

				if (!SOUNDMANAGER->isPlaySound("playerhit"))
					SOUNDMANAGER->play("playerhit", 1.f);

			}

		}
	}
}

void molbattle::molunderattack()
{
	if (dmgbefore < yourdmg)
	{
		molcurhp -= 2;
		dmgbefore += 2;
	}


	if (indexx > 20 )
	{
		boomover = true;
		boomx = 0;
		molboom = 0;


	}
	else if (indexx <= 20)
	{
		molboom += boomx;
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
		molboom = 0;
		boomover = false;
		ismolunderattack = false;
		attackeffectindex = 0;
		attack = false;
		attackeffectindex = 0;
		attackbarmovex = 37;
		attackgageindex = 0;
		stopbar = false;
		dmgbefore = 0;
		goodman = false;
		goodmancount = 0;
		//isyouattack = true;
		if(!moldie)
		molturn = true;
		if (molcurhp <= 0) moldie = true;
	}
	
}

void molbattle::runOut()
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

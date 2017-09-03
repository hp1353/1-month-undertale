#include "stdafx.h"
#include "nobody.h"
#include "player.h"
#include "camera.h"


nobody::nobody()
{
}
nobody::~nobody()
{
}

HRESULT nobody::init()
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

	if (!SOUNDMANAGER->isPlaySound("alldie"))
	{
		SOUNDMANAGER->play("alldie", 1.f);
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
	IMAGEMANAGER->addImage("battlebox", "image/undertale/battle/torielbattle/battlebox.bmp", 165, 140, true, RGB(255, 0, 255));

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

	
	for (int i = 0; i < 10; i++)
	{
		fireonce[i] = false;
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

void nobody::release()
{
}

void nobody::update()
{
	
	
	
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
		
	}
	NumberSet();
	TextControlUpdate();

	
	
	if (torturn) _player->getPlayer()->control = true;
	else _player->getPlayer()->control = false;
	heartbox = RectMake(_player->getPlayer()->x, _player->getPlayer()->y, 16, 16);



}

void nobody::render()
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


	
	
	if (!torturn)
		IMAGEMANAGER->findImage("textbox")->render(getMemDC(), textboxmovex, 250, 0, 0, textboxsmallerx, 140);
	if (torturn)
	{
		IMAGEMANAGER->findImage("battlebox")->render(getMemDC(), 240, 250);
		if (goodman)
		{

			IMAGEMANAGER->findImage("heart")->alphaRender(getMemDC(), _player->getPlayer()->x, _player->getPlayer()->y, goodmanalpha);
		}
		else IMAGEMANAGER->findImage("heart")->render(getMemDC(), _player->getPlayer()->x, _player->getPlayer()->y);
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

		
		char str11[128];
		sprintf_s(str11, "torpattennum :  %d ", torielpattennum);
		TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y + 200, str11, strlen(str11));
		Rectangle(getMemDC(), playershield.left, playershield.top, playershield.right, playershield.bottom);

	}

}

void nobody::NumberSet()
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


void nobody::TextControlUpdate()
{
	tcount++;
	//17,18,19,20 이 토리엘 기본대사
	if (tcount % 2 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 29)
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
	if (textnum == 1)
	{
		if (tindex == 29)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{

				//tindex = 0;
				
				textnum = 0;
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

void nobody::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 0, 0));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/nobody/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
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


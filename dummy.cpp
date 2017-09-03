#include "stdafx.h"
#include "dummy.h"
#include "player.h"
#include "camera.h"

dummy::dummy()
{
}


dummy::~dummy()
{
}

HRESULT dummy::init()
{
	//  ----- 카메라 초기화 -----
	_camera->getCam()->x = 0;
	_camera->getCam()->y = 0;
	//  -------------------------
	_player->getPlayer()->playertor = false;
	_player->getPlayer()->battleScene = true;
	_player->getPlayer()->battleend = false;
	_player->getPlayer()->walkcount = 0;
	_player->getPlayer()->control = true;
	_player->getPlayer()->dontpix = false;
	_player->getPlayer()->changeindex = 0;
	IMAGEMANAGER->addImage("1", "image/undertale/battle/flabttle/1.bmp", 1068, 728, false, false);
	IMAGEMANAGER->addImage("bt", "image/undertale/battle/dummy/bt.bmp", 609, 236, false, false);
	IMAGEMANAGER->addImage("red", "image/undertale/battle/dummy/red.bmp", 55, 30, false, false);
	IMAGEMANAGER->addImage("miss", "image/undertale/battle/dummy/miss.bmp", 118, 30, true, RGB(255,0,255));

	IMAGEMANAGER->addImage("gage", "image/undertale/battle/dummy/gage.bmp", 565, 130, false, false);
	
	/*IMAGEMANAGER->addImage("dummy", "image/undertale/battle/dummy/dummy.bmp", 69, 103, true, RGB(255, 0, 255));*/
	IMAGEMANAGER->addImage("lv0", "image/undertale/battle/dummy/lv.bmp", 375, 31, false, false);
	IMAGEMANAGER->addImage("hp", "image/undertale/battle/dummy/hp.bmp", 101, 13, false, false);
	IMAGEMANAGER->addImage("hp2", "image/undertale/battle/dummy/hp2.bmp", 103, 15, false, false);
	IMAGEMANAGER->addImage("heart", "image/undertale/battle/dummy/heart.bmp", 16, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("....", "image/undertale/battle/dummy/.....bmp", 99, 108, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bttb", "image/undertale/battle/dummy/bttb.bmp", 575, 140, false, false);//대사박스

																									//공격 행동 아이템 자비
	fight = IMAGEMANAGER->addFrameImage("fight", "image/undertale/battle/dummy/fight.bmp", 330, 42, 3, 1, false, false);
	act = IMAGEMANAGER->addFrameImage("act", "image/undertale/battle/dummy/act.bmp", 330, 42, 3, 1, false, false);
	item = IMAGEMANAGER->addFrameImage("item", "image/undertale/battle/dummy/item.bmp", 330, 42, 3, 1, false, false);
	mercy = IMAGEMANAGER->addFrameImage("mercy", "image/undertale/battle/dummy/mercy.bmp", 330, 42, 3, 1, false, false);
	heartw = IMAGEMANAGER->addFrameImage("heartw", "image/undertale/battle/dummy/heartw.bmp", 32, 24, 2, 1, true, RGB(255, 0, 255));
	stick = IMAGEMANAGER->addFrameImage("stick", "image/undertale/battle/dummy/stick.bmp", 28, 130, 2, 1, true, RGB(255, 0, 255));
	attack = IMAGEMANAGER->addFrameImage("attack", "image/undertale/battle/dummy/attack.bmp", 693, 154, 7, 1, true, RGB(255, 0, 255));
	dummy2 = IMAGEMANAGER->addFrameImage("dummy", "image/undertale/battle/dummy/dummy2.bmp", 2450, 111, 25, 1, true, RGB(255, 0, 255));
	gagef = IMAGEMANAGER->addFrameImage("gagef", "image/undertale/battle/dummy/gagef.bmp", 7345, 130, 13, 1, false,false);
	textnum = 7;
	textnum2 = 7;
	//textrc = RectMake(37, 255, 565, 130);
	textrc = RectMake(17 + _camera->getCam()->x + 20, 255 + _camera->getCam()->y, 565, 130);
	textrc2 = RectMake(340, 150, 70, 50);
	
	tcount = 0;
	tindex = 0;
	next = 0;
	evcount = 0;
	dummyy = 130;
	dummyx = 219;
	heartwx = 55;
	fcount = 0;
	fcount2 = 0;
	findex = 0;
	stickx = 28;
	fcount3 = 10;
	hpx = 101;
	dboxy = 70;
	fcount6 = 0;
	rhd = 17;
	epa = 0;
	te = 0;
	te2 = 284;

	start = true;
	fightchoices = false;
	fightgages = false;
	fightatts = false;
	fightatt2s1 = false;
	fightatt2s2 = false;
	fightmisss = false;
	actchoices = false;
	actchoice2s = false;
	mercychoices = false;
	textrc2s = false;
	sticks = false;
	stickf = false;

	fights = true;
	acts = false;
	items = false;
	mercys = false;
	misss = false;
	hs = false;
	atts = false;
	act->setFrameX(1);
	item->setFrameX(1);
	mercy->setFrameX(1);
	if (SOUNDMANAGER->isPlaySound("stagesound"))
	{
		SOUNDMANAGER->pause("stagesound");
		
	}
	if (!SOUNDMANAGER->isPlaySound("dummy"))
	{
		SOUNDMANAGER->play("dummy",1.f);
	}

	return S_OK;
}

void dummy::release()
{
}

void dummy::update()
{

	
	dbox = RectMake(235, dboxy, 70, 40);
	
	if (start)choice();
	if (fightchoices)fightchoice();
	if (fightgages)fightgage();
	if (fightatts)fightatt();
	if (fightatt2s1)fightatt2();
	if (fightmisss)fightmiss();
	if (actchoices)actchoice();
	if (actchoice2s)actchoice2();
	if (mercychoices)mercychoice();


	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 7)
		{
			if (tindex < 23)
				tindex++;
		}
		if (textnum == 2)
		{
			tindex = 100;
		}
		if (textnum == 3)
		{
			tindex = 100;
		}
		if (textnum == 5)
		{
			if (tindex < 94)
				tindex++;
		}
		if (textnum == 0)
		{
			if (tindex < 40)
				tindex++;
		}
		if (textnum == 1)
		{
			if (tindex < 30)
				tindex++;
		}
		if (textnum == 6)
		{
			if (tindex < 37)
				tindex++;
		}
		if (textnum == 8)
		{
			if (tindex < 40)
				tindex++;
		}
		if (textnum == 9)
		{
			if (tindex < 28)
				tindex++;
		}
		if (textnum == 10)
		{
			if (tindex < 39)
				tindex++;
		}
		if (textnum == 11)
		{
			if (tindex < 58)
				tindex++;
		}
		
	}
	if (tcount % 10 == 0)
	{
		if (textnum == 13)
		{
			if (tindex < 7)
				tindex++;
		}
		
	}
	if (sticks)
	{
		if (tcount % 7 == 0)stickindex++;
		stick->setFrameX(stickindex);
		if (stickindex > stick->getMaxFrameX())stickindex = 0;
	
	}
	if (misss)
	{
		count++;
		
		if (count > 100)
		{
			misss = false;
			
		}
			
	}
	if (atts)
	{
		if (tcount % 7 == 0)att++;
		attack->setFrameX(att);
	}

}

void dummy::render()
{
	
	IMAGEMANAGER->findImage("1")->render(getMemDC(), 0, 0);

	IMAGEMANAGER->findImage("bt")->render(getMemDC(), 15, 9);
	IMAGEMANAGER->findImage("bttb")->render(getMemDC(), 32, 250);
	IMAGEMANAGER->findImage("lv0")->render(getMemDC(), 29, 397);
	IMAGEMANAGER->findImage("dummy")->frameRender(getMemDC(), dummyx, dummyy);
	
	if(textrc2s)IMAGEMANAGER->findImage("....")->render(getMemDC(), 320, 135);

	IMAGEMANAGER->findImage("fight")->frameRender(getMemDC(), 31, 432);
	IMAGEMANAGER->findImage("act")->frameRender(getMemDC(), 184, 432);
	IMAGEMANAGER->findImage("item")->frameRender(getMemDC(), 337, 432);
	IMAGEMANAGER->findImage("mercy")->frameRender(getMemDC(), 490, 432);

	if (misss)IMAGEMANAGER->findImage("miss")->render(getMemDC(),210,100);
	if (atts)IMAGEMANAGER->findImage("attack")->frameRender(getMemDC(), 220, 90);


	if (fightatts)fightatt();
	TextControl();
	SetBkMode(getMemDC(), TRANSPARENT); //문자열 배경색 출력안되게
	viewEvery();
	if (fightchoices)fightchoice();
	if (fightgages)fightgage();
	
	if (fightatt2s1)fightatt2();
	if (fightmisss)fightmiss();
	if (actchoices)actchoice();
	if (actchoice2s)actchoice2();
	if (mercychoices)mercychoice();

	
	
}

void dummy::choice()
{
	if (fights)
	{
		if (KEYMANAGER->isOnceDown(VK_LEFT))
		{
			fights = false;
			mercys = true;
			fight->setFrameX(1);
			mercy->setFrameX(0);
		}
		if (KEYMANAGER->isOnceDown(VK_RIGHT))
		{
			fights = false;
			acts = true;
			fight->setFrameX(1);
			act->setFrameX(0);
		}
		if (KEYMANAGER->isOnceDown('Z'))
		{
			textnum = 2;
			fightchoices = true;
			start = false;
			fight->setFrameX(2);
		}

	}
	if (mercys)
	{
		if (KEYMANAGER->isOnceDown(VK_LEFT))
		{
			mercys = false;
			items = true;
			mercy->setFrameX(1);
			item->setFrameX(0);
		}
		if (KEYMANAGER->isOnceDown(VK_RIGHT))
		{
			mercys = false;
			fights = true;
			mercy->setFrameX(1);
			fight->setFrameX(0);
		}
		if (KEYMANAGER->isOnceDown('Z'))
		{
			textnum = 3;
			mercychoices = true;
			start = false;
			mercy->setFrameX(2);
		}
	}
	if (acts)
	{
		if (KEYMANAGER->isOnceDown(VK_LEFT))
		{
			acts = false;
			fights = true;
			act->setFrameX(1);
			fight->setFrameX(0);
		}
		if (KEYMANAGER->isOnceDown(VK_RIGHT))
		{
			acts = false;
			items = true;
			act->setFrameX(1);
			item->setFrameX(0);
		}
		if (KEYMANAGER->isOnceDown('Z'))
		{
			textnum = 2;
			actchoices = true;
			start = false;
			act->setFrameX(2);
		}
	}
	if (items)
	{
		if (KEYMANAGER->isOnceDown(VK_LEFT))
		{
			items = false;
			acts = true;
			item->setFrameX(1);
			act->setFrameX(0);
		}
		if (KEYMANAGER->isOnceDown(VK_RIGHT))
		{
			items = false;
			mercys = true;
			item->setFrameX(1);
			mercy->setFrameX(0);
		}
	}
}

void dummy::fightchoice()
{
	IMAGEMANAGER->findImage("heart")->render(getMemDC(), 55, 270);
	IMAGEMANAGER->findImage("hp")->frameRender(getMemDC(), 250, 272);
	if (KEYMANAGER->isOnceDown('X'))
	{
		fightchoices = false;
		start = true;
		tindex = 0;
		textnum = textnum2;
		fight->setFrameX(0);
	}
	if (KEYMANAGER->isOnceDown('Z'))
	{
		fightgages = true;
		fightchoices = false;
	}
}



void dummy::fightgage()
{
	IMAGEMANAGER->findImage("gage")->render(getMemDC(), textrc.left, textrc.top);
	IMAGEMANAGER->findImage("stick")->frameRender(getMemDC(), stickx, 255);
	if (!sticks)
	{
		stickx += 2;
	}
	if (KEYMANAGER->isOnceDown('Z'))
	{
		sticks = true;
		atts = true;
		fightgages = false;
		fightatts = true;
		textnum = 100;
		tindex = 0;
	}
	if (stickx>596)
	{
		
		fightgages = false;
		fightmisss = true;
		textnum = 100;
		count = 0;

	}

}

void dummy::fightatt()
{
	if (fcount2 == 0)
	{
		IMAGEMANAGER->findImage("gage")->render(getMemDC(), textrc.left, textrc.top);
		IMAGEMANAGER->findImage("stick")->frameRender(getMemDC(), stickx, 255);
		if (att > attack->getMaxFrameX())
		{
			fightatt2s1 = true;
			fcount2 = 1;
			te =(312 - stickx) / te2;
		}
	}
	if (fcount2 == 1)
	{
		IMAGEMANAGER->findImage("gage")->render(getMemDC(), textrc.left, textrc.top);
		IMAGEMANAGER->findImage("stick")->frameRender(getMemDC(), stickx, 255);
		dummy2->setFrameX(1);
		if (dummyx < 219 + fcount3)
		{
			dummyx += 1;
			
			
		}
		if (dummyx == 219 + fcount3)
		{
			fcount2 = 2;
			fcount3 -= 1;
		}
		if (fcount3 < 0)fcount2 = 3;
	}
	if (fcount2 == 2)
	{
		IMAGEMANAGER->findImage("gage")->render(getMemDC(), textrc.left, textrc.top);
		IMAGEMANAGER->findImage("stick")->frameRender(getMemDC(), stickx, 255);
		if (dummyx > 219 - fcount3)
		{
			dummyx -= 1;
			
			
		}
		if (dummyx == 219 - fcount3)
		{
			fcount2 = 1;
			fcount3 -= 1;
		}
		if (fcount3 < 0)fcount2 = 3;
	}
	if (fcount2 == 3)
	{
		IMAGEMANAGER->findImage("gagef")->frameRender(getMemDC(), textrc.left, textrc.top);
		fcount4++;
		textnum = 10;
		if (fcount4 % 5 == 0)fcount5++;
		gagef->setFrameX(fcount5);
		dummy2->setFrameX(fcount5);
		if (tindex > 37)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				//체인지씬 인형은 싸우려고 있는게 아니에요!ㅋ
				_player->getPlayer()->stage6_patten1 = true;
				SCENEMANAGER->changeScene("stage6");
			}
		}
	}
}

void dummy::fightatt2()
{
	fcount7++;
	/*Rectangle(getMemDC(), dbox.left, dbox.top, dbox.right, dbox.bottom);*/
	/*IMAGEMANAGER->findImage("red")->render(getMemDC(), dbox.left+2, dbox.top+11);*/
	IMAGEMANAGER->findImage("hp2")->render(getMemDC(), 216, 119);
	IMAGEMANAGER->findImage("hp")->render(getMemDC(), 217, 120, 0, 0, hpx, 13);
	hpx -= 2;
	if(te>0)epa = rhd * (2 - te);
	if (te<0)epa = rhd * (2 + te);
	if (te==0)epa = rhd * 2;
	epa2 = epa;
	HFONT font = CreateFont(45, 25, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "맑은 고딕");//글꼴생성		//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SetTextColor(getMemDC(), RGB(255, 0, 0));
	SelectObject(getMemDC(), font);

	char str11[128];
	sprintf_s(str11, "%d", epa2);
	TextOut(getMemDC(), dbox.left, dbox.top, str11, strlen(str11));
		/*rhd*(2 - ((((312 - stickx) * 2) / 2)/284));*/
	//공격력*(2-{((중앙-stickx)*2)/2/284}
	//28
	//중앙 312
	//284
	//596
	if (fcount6 == 0)
	{
		if (dboxy > 60)dboxy -= 1;
		if (fcount7>38)fcount6=1;
	}
	if (fcount6 == 1)
	{
		if (dboxy < 80)dboxy += 1;
	}
	if (fcount7 > 160)fightatt2s1 = false;
	
}

void dummy::fightmiss()
{
	
	if (next == 0)
	{
		if (evcount > 7)
		{
			tindex = 0;
			next = 2;
			textnum = 11;
		}
		if (evcount < 8)
		{
			if (count < 1)misss = true;
			evcount += 1;
			textnum2 = (evcount % 2);
			tindex = 0;
			textrc2s = true;
			textnum = 13;
			next = 1;
		}
	}
	if (next == 1)
	{
		if (KEYMANAGER->isOnceDown('Z'))
		{
			tindex = 0;
			fight->setFrameX(0);
			fightmisss = false;
			start = true;
			textrc2s = false;
			textnum = textnum2;
			next = 0;
			stickx = 28;
		}
	}
	if (next == 2)
	{
		dummyy -= 2;
		if (tindex > 56)
		{
			textnum = 10;
			tindex = 0;
			next = 3;
		}
	}
	if (next == 3)
	{
		if (KEYMANAGER->isOnceDown('X'))
		{
			tindex = 39;
		}
		if (tindex > 37)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				//전투종료 체인지씬 더미피곤해함 토리엘 황당
				_player->getPlayer()->stage6_patten2 = true;
				SCENEMANAGER->changeScene("stage6");
			}
		}
	}
}

void dummy::actchoice()
{

	IMAGEMANAGER->findImage("heart")->render(getMemDC(), 55, 270);
	if (KEYMANAGER->isOnceDown('X'))
	{
		actchoices = false;
		start = true;
		tindex = 0;
		textnum = textnum2;
		act->setFrameX(0);
	}
	if (KEYMANAGER->isOnceDown('Z'))
	{
		actchoices = false;
		actchoice2s = true;
		textnum = 4;

	}
}

void dummy::actchoice2()
{
	if (next == 0)
	{
		if (!hs)
		{
			IMAGEMANAGER->findImage("heart")->render(getMemDC(), 55, 270);
			if (KEYMANAGER->isOnceDown(VK_LEFT))
			{
				hs = true;
			}
			if (KEYMANAGER->isOnceDown(VK_RIGHT))
			{
				hs = true;
			}
			if (KEYMANAGER->isOnceDown('Z'))
			{
				next = 1;
				tindex = 0;
				textnum = 5;
			}
		}
		if (hs)
		{
			IMAGEMANAGER->findImage("heart")->render(getMemDC(), 295, 270);
			if (KEYMANAGER->isOnceDown(VK_LEFT))
			{
				hs = false;
			}
			if (KEYMANAGER->isOnceDown(VK_RIGHT))
			{
				hs = false;
			}
			if (KEYMANAGER->isOnceDown('Z'))
			{
				next = 3;
				tindex = 0;
				textnum = 6;
			}
		}
		if (KEYMANAGER->isOnceDown('X'))
		{
			actchoice2s = false;
			actchoices = true;
			textnum = 2;
			hs = false;
		}
	}
	if (next == 1)
	{
		if (KEYMANAGER->isOnceDown('X'))
		{
			tindex = 93;
		}
		if (tindex > 92)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				evcount += 1;
				textnum2 = (evcount % 2);
				textrc2s = true;
				tindex = 0;
				textnum = 13;
				next = 2;
			}
		}
	}
	if (next == 2)
	{
		
		if (KEYMANAGER->isOnceDown('Z'))
		{
			tindex = 0;

			act->setFrameX(0);
			actchoice2s = false;
			start = true;
			textrc2s = false;
			textnum = textnum2;
			next = 0;
		}
	}
	if (next == 3)
	{
		if (KEYMANAGER->isOnceDown('X'))
		{
			tindex = 37;
		}
		if (tindex > 35)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				next = 4;
				textnum = 8;
			}
		}
	}
	if (next == 4)
	{
		if (KEYMANAGER->isOnceDown('X'))
		{
			tindex = 40;
		}
		if (tindex > 38)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				next = 5;
				textnum = 9;
			}
		}
	}
	if (next == 5)
	{
		if (KEYMANAGER->isOnceDown('X'))
		{
			tindex = 28;
		}
		if (tindex > 26)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				next = 6;
				textnum = 10;
			}
		}
	}
	if (next == 6)
	{
		if (KEYMANAGER->isOnceDown('X'))
		{
			tindex = 39;
		}
		if (tindex > 37)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				//전투종료 체인지씬 토리엘 기뻐함
				_player->getPlayer()->stage6_patten3 = true;
				SCENEMANAGER->changeScene("stage6");
			}
		}
	}
}

void dummy::mercychoice()
{
	if (next == 0)
	{
		if (!hs)
		{
			IMAGEMANAGER->findImage("heart")->render(getMemDC(), 55, 270);
			if (KEYMANAGER->isOnceDown(VK_UP))
			{
				hs = true;
			}
			if (KEYMANAGER->isOnceDown(VK_DOWN))
			{
				hs = true;
			}
			if (KEYMANAGER->isOnceDown('Z'))
			{
				if (evcount > 7)
				{
					tindex = 0;
					next = 2;
					textnum = 11;
				}
				else
				{
					evcount += 1;
					textnum2 = (evcount % 2);
					tindex = 0;
					textrc2s = true;
					textnum = 13;
					next = 1;
				}
			}
		}
		if (hs)
		{
			IMAGEMANAGER->findImage("heart")->render(getMemDC(), 55, 310);
			if (KEYMANAGER->isOnceDown(VK_UP))
			{
				hs = false;
			}
			if (KEYMANAGER->isOnceDown(VK_DOWN))
			{
				hs = false;
			}
			if (KEYMANAGER->isOnceDown('Z'))
			{
				next = 4;
				textnum = 12;
			}
		}
		if (KEYMANAGER->isOnceDown('X'))
		{
			mercychoices = false;
			start = true;
			hs = false;
			tindex = 0;
			textnum = textnum2;
			mercy->setFrameX(0);
		}
	}
	if (next == 1)
	{
		
		if (KEYMANAGER->isOnceDown('Z'))
		{
			tindex = 0;
			mercy->setFrameX(0);
			mercychoices = false;
			start = true;
			textrc2s = false;
			textnum = textnum2;
			next = 0;
		}
	}
	if (next == 2)
	{
		dummyy -= 2;
		if (tindex > 56)
		{
			textnum = 10;
			tindex = 0;
			next = 3;
		}
	}
	if (next == 3)
	{
		if (KEYMANAGER->isOnceDown('X'))
		{
			tindex = 39;
		}
		if (tindex > 37)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				//전투종료 체인지씬 더미피곤해함 토리엘 황당
				_player->getPlayer()->stage6_patten2 = true;
				SCENEMANAGER->changeScene("stage6");
			}
		}
	}
	if (next == 4)
	{
		IMAGEMANAGER->findImage("heartw")->frameRender(getMemDC(), heartwx, 310);
		fcount++;
		if (fcount % 10 == 0)findex++;
		heartw->setFrameX(findex);
		if (findex > heartw->getMaxFrameX())findex = 0;
		heartwx -= 1;
		if (heartwx < -100)
		{
			_player->getPlayer()->stage6_patten4 = true;
			SCENEMANAGER->changeScene("stage6");
		}
		//전투종료 체인지씬 도망치다 토리엘 나쁘지않은선택
	}
}

void dummy::TextControl()
{


	HANDLE hInputFile;
	if (textnum == 0)
		hInputFile = CreateFile(_T("image/undertale/battle/dummy/0.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 1)
		hInputFile = CreateFile(_T("image/undertale/battle/dummy/1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 7)
		hInputFile = CreateFile(_T("image/undertale/battle/dummy/7.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("image/undertale/battle/dummy/2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("image/undertale/battle/dummy/3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 4)
		hInputFile = CreateFile(_T("image/undertale/battle/dummy/4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 5)
		hInputFile = CreateFile(_T("image/undertale/battle/dummy/5.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 6)
		hInputFile = CreateFile(_T("image/undertale/battle/dummy/6.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 8)
		hInputFile = CreateFile(_T("image/undertale/battle/dummy/8.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 9)
		hInputFile = CreateFile(_T("image/undertale/battle/dummy/9.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 10)
		hInputFile = CreateFile(_T("image/undertale/battle/dummy/10.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 11)
		hInputFile = CreateFile(_T("image/undertale/battle/dummy/11.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 12)
		hInputFile = CreateFile(_T("image/undertale/battle/dummy/12.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 13)
		hInputFile = CreateFile(_T("image/undertale/battle/dummy/13.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);


	if (!textrc2s)
	{
		HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																													//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)

		SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));

		TCHAR buf[100] = _T("");
		DWORD dwRead;



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
	if (textrc2s)
	{
		HFONT font = CreateFont(23, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																													//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)

		SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));

		TCHAR buf[100] = _T("");
		DWORD dwRead;



		ReadFile(hInputFile, buf, 999 * sizeof(TCHAR), &dwRead, NULL);
		CloseHandle(hInputFile);

		//TextOut(getMemDC(), 80, 200, buf, 2 * tindex);
		DrawText(getMemDC(), buf, tindex, &textrc2, DT_LEFT);
		DeleteObject(font);
		font = CreateFont(20, 0, 0, 0, 0, 0, 0, 00, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, NULL);
		SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		DeleteObject(font);
	}
}

void dummy::viewEvery()
{
	if (_player->getPlayer()->viewEvery)
	{
		SetBkMode(getMemDC(), OPAQUE);
	}
	else
	{
		SetBkMode(getMemDC(), TRANSPARENT);
	}
}

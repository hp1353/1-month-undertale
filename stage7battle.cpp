#include "stdafx.h"
#include "stage7battle.h"
#include "player.h"
#include "camera.h"

stage7battle::stage7battle()
{
}


stage7battle::~stage7battle()
{
}

HRESULT stage7battle::init()
{
	_player->getPlayer()->playertor = false;
	_player->getPlayer()->battleScene = true;
	_player->getPlayer()->battleend = false;
	_player->getPlayer()->walkcount = 0;
	_player->getPlayer()->control = true;
	_player->getPlayer()->dontpix = false;
	_player->getPlayer()->changeindex = 0;
	IMAGEMANAGER->addImage("1", "image/undertale/battle/flabttle/1.bmp", 1068, 728, false, false);
	//IMAGEMANAGER->addImage("battlebase", "image/undertale/battle/stage7battle/battlebase.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("frotk", "image/undertale/battle/stage7battle/cap/1.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk2", "image/undertale/battle/stage7battle/cap/2.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk3", "image/undertale/battle/stage7battle/cap/3.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk4", "image/undertale/battle/stage7battle/cap/4.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk5", "image/undertale/battle/stage7battle/cap/5.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk6", "image/undertale/battle/stage7battle/cap/6.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk7", "image/undertale/battle/stage7battle/cap/7.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk8", "image/undertale/battle/stage7battle/cap/8.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk9", "image/undertale/battle/stage7battle/cap/9.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk10", "image/undertale/battle/stage7battle/cap/10.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk11", "image/undertale/battle/stage7battle/cap/11.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk12", "image/undertale/battle/stage7battle/cap/12.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk13", "image/undertale/battle/stage7battle/cap/13.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk14", "image/undertale/battle/stage7battle/cap/14.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk15", "image/undertale/battle/stage7battle/cap/15.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk16", "image/undertale/battle/stage7battle/cap/16.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk17", "image/undertale/battle/stage7battle/cap/17.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk18", "image/undertale/battle/stage7battle/cap/18.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk19", "image/undertale/battle/stage7battle/cap/19.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk20", "image/undertale/battle/stage7battle/cap/20.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk21", "image/undertale/battle/stage7battle/cap/21.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk22", "image/undertale/battle/stage7battle/cap/22.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk23", "image/undertale/battle/stage7battle/cap/23.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("frotk24", "image/undertale/battle/stage7battle/cap/24.bmp", 424, 236, false, false);
	IMAGEMANAGER->addImage("lv2rkfk", "image/undertale/battle/stage7battle/lv2.bmp", 382, 31, false, false);
	IMAGEMANAGER->addImage("bt", "image/undertale/battle/dummy/bt.bmp", 609, 236, false, false);
	IMAGEMANAGER->addImage("bttb", "image/undertale/battle/dummy/bttb.bmp", 575, 140, false, false);//대사박스
	IMAGEMANAGER->addImage("lv0", "image/undertale/battle/dummy/lv.bmp", 375, 31, false, false);
	IMAGEMANAGER->addImage("miss", "image/undertale/battle/dummy/miss.bmp", 118, 30, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("hp", "image/undertale/battle/dummy/hp.bmp", 101, 13, false, false);
	IMAGEMANAGER->addImage("heart", "image/undertale/battle/dummy/heart.bmp", 16, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("gage", "image/undertale/battle/dummy/gage.bmp", 565, 130, false, false);
	IMAGEMANAGER->addImage("hp", "image/undertale/battle/dummy/hp.bmp", 101, 13, false, false);
	IMAGEMANAGER->addImage("hp2", "image/undertale/battle/dummy/hp2.bmp", 103, 15, false, false);
	stick = IMAGEMANAGER->addFrameImage("stick", "image/undertale/battle/dummy/stick.bmp", 28, 130, 2, 1, true, RGB(255, 0, 255));
	heartw = IMAGEMANAGER->addFrameImage("heartw", "image/undertale/battle/dummy/heartw.bmp", 32, 24, 2, 1, true, RGB(255, 0, 255));
	fight = IMAGEMANAGER->addFrameImage("fight", "image/undertale/battle/dummy/fight.bmp", 330, 42, 3, 1, false, false);
	act = IMAGEMANAGER->addFrameImage("act", "image/undertale/battle/dummy/act.bmp", 330, 42, 3, 1, false, false);
	item = IMAGEMANAGER->addFrameImage("item", "image/undertale/battle/dummy/item.bmp", 330, 42, 3, 1, false, false);
	mercy = IMAGEMANAGER->addFrameImage("mercy", "image/undertale/battle/dummy/mercy.bmp", 330, 42, 3, 1, false, false);
	frog = IMAGEMANAGER->addFrameImage("frogf", "image/undertale/monster/frog/frogf.bmp", 7168, 112, 64, 1, false, false);
	frororo = IMAGEMANAGER->addFrameImage("frororo", "image/undertale/battle/stage7battle/frororo.bmp", 224, 224, 2, 2, true, RGB(255, 0, 255));
	tototo = IMAGEMANAGER->addFrameImage("tototo", "image/undertale/battle/stage7battle/tototo.bmp", 304, 208, 2, 1, true, RGB(255, 0, 255));
	gagef = IMAGEMANAGER->addFrameImage("gagef", "image/undertale/battle/dummy/gagef.bmp", 7345, 130, 13, 1, false, false);
	attack = IMAGEMANAGER->addFrameImage("attack", "image/undertale/battle/dummy/attack.bmp", 693, 154, 7, 1, true, RGB(255, 0, 255));
	textrc = RectMake(17 + _camera->getCam()->x + 20, 255 + _camera->getCam()->y, 565, 130);
	//textrc = RectMake(37 + _camera->getCam()->x + 20, 255 + _camera->getCam()->y + 10, 565, 130);
	count = 0;
	towx = 700;
	fowx = CENTERX - 107;
	heartwx = 55 + _camera->getCam()->x;
	count1 = 0;
	textnum = 0;
	textnum2 = 0;

	next = 0;
	lacount = 0;
	stickx = 28;
	te = 0;
	te2 = 284;
	rhd = 11;
	epa = 0;
	fcount6 = 0;
	fcount2 = 0;
	fcount3 = 10;
	dboxy = 70;
	hpx = 100;

	fight->setFrameX(0);
	act->setFrameX(1);
	item->setFrameX(1);
	mercy->setFrameX(1);
	_player->getPlayer()->control = true;

	_player->getPlayer()->ischangebattle = false;
	_player->getPlayer()->changebattle = false;
	atts = false;
	hs = false;
	frofs = true;
	sticks = false;
	start = true;
	fightchoices = false;
	fightgages = false;
	fightatts = false;
	fightatt2s1 = false;
	fightmisss = false;
	mercychoices = false;
	misss = false;
	fights = true;
	acts = false;
	items = false;
	mercys = false;
	runcount = 0;

	if (SOUNDMANAGER->isPlaySound("stagesound"))
	{
		SOUNDMANAGER->pause("stagesound");
	}
	if (!SOUNDMANAGER->isPlaySound("dummy"))
	{
		SOUNDMANAGER->play("dummy", 1.f);
	}
	return S_OK;
}

void stage7battle::release()
{
}

void stage7battle::update()
{
	
	dbox = RectMake(235 + _camera->getCam()->x, dboxy + _camera->getCam()->y, 70, 40);

	frogcount++;
	frog->setFrameX(frogindex);
	if (frogcount % 2 == 0)frogindex++;
	if (frogindex > frog->getMaxFrameX())frogindex = 0;

	if (start)choice();
	if (fightchoices)fightchoice();
	if (fightgages)fightgage();
	if (fightatts)fightatt();
	if (fightatt2s1)fightatt2();
	if (fightmisss)fightmiss();
	if (actchoices)actchoice();
	if (mercychoices)mercychoice();

	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 0)
		{
			if (tindex < 28)
				tindex++;
		}

		if (textnum == 3)
		{
			tindex = 100;
		}
		if (textnum == 2)
		{
			tindex = 100;
		}
		if (textnum == 5)
		{
			if (tindex < 55)
				tindex++;
		}
		if (textnum == 6)
		{
			if (tindex < 73)
				tindex++;
		}
		if (textnum == 7)
		{
			if (tindex < 66)
				tindex++;
		}
		if (textnum == 10)
		{
			if (tindex < 39)
				tindex++;
		}
		if (textnum == 11)
		{
			if (tindex < 66)
				tindex++;
		}
		if (textnum == 12)
		{
			tindex = 100;
		}
	}


	_camera->getCam()->overviewX = true;
	_camera->getCam()->overviewY = true;
	
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
	if (sticks)
	{
		if (tcount % 7 == 0)stickindex++;
		stick->setFrameX(stickindex);
		if (stickindex > stick->getMaxFrameX())stickindex = 0;

	}

}

void stage7battle::render()
{
	
	IMAGEMANAGER->findImage("1")->render(getMemDC(), 0, 0);

	IMAGEMANAGER->findImage("lv0")->render(getMemDC(), 29 + _camera->getCam()->x, 397 + _camera->getCam()->y);
	//IMAGEMANAGER->findImage("battlebase")->render(getMemDC(),_camera->getCam()->x,_camera->getCam()->y);
	IMAGEMANAGER->findImage("bt")->render(getMemDC(), 15+ _camera->getCam()->x, 9+ _camera->getCam()->y);
	/*IMAGEMANAGER->findImage("frog1")->render(getMemDC(), _camera->getCam()->x + CENTERX - 107 , _camera->getCam()->y + CENTERY - 107);*/
	if(frofs)IMAGEMANAGER->findImage("frogf")->frameRender(getMemDC(), _camera->getCam()->x + CENTERX - 107 , _camera->getCam()->y + CENTERY - 107);
	IMAGEMANAGER->findImage("bttb")->render(getMemDC(), 32 + _camera->getCam()->x, 250 + _camera->getCam()->y);

	IMAGEMANAGER->findImage("fight")->frameRender(getMemDC(), 31 + _camera->getCam()->x, 432 + _camera->getCam()->y);
	IMAGEMANAGER->findImage("act")->frameRender(getMemDC(), 184 + _camera->getCam()->x, 432 + _camera->getCam()->y);
	IMAGEMANAGER->findImage("item")->frameRender(getMemDC(), 337 + _camera->getCam()->x, 432 + _camera->getCam()->y);
	IMAGEMANAGER->findImage("mercy")->frameRender(getMemDC(), 490 + _camera->getCam()->x, 432 + _camera->getCam()->y);
	if (misss)IMAGEMANAGER->findImage("miss")->render(getMemDC(), 210 + _camera->getCam()->x, 100 + _camera->getCam()->y);
	if (atts)IMAGEMANAGER->findImage("attack")->frameRender(getMemDC(), 220 + _camera->getCam()->x, 90 + _camera->getCam()->y);
	
	
	if (mercychoices)mercychoice();
	if (actchoices)actchoice();
	if (fightchoices)fightchoice();
	
	
	if (fightatts)fightatt();
	TextControl();
	if (fightgages)fightgage();
	if (fightatt2s1)fightatt2();
	if (fightmisss)fightmiss();
}

void stage7battle::choice()
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

void stage7battle::fightchoice()
{
	IMAGEMANAGER->findImage("heart")->render(getMemDC(), 55 + _camera->getCam()->x, 270 + _camera->getCam()->y);
	IMAGEMANAGER->findImage("hp")->frameRender(getMemDC(), 250 + _camera->getCam()->x, 272 + _camera->getCam()->y);
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

void stage7battle::fightgage()
{
	IMAGEMANAGER->findImage("gage")->render(getMemDC(), textrc.left, textrc.top);
	IMAGEMANAGER->findImage("stick")->frameRender(getMemDC(), stickx + _camera->getCam()->x, 255 + _camera->getCam()->y);
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
		tindex = 0;

	}
}

void stage7battle::fightatt()
{
	if (fcount2 == 0)
	{
		IMAGEMANAGER->findImage("gage")->render(getMemDC(), textrc.left, textrc.top);
		IMAGEMANAGER->findImage("stick")->frameRender(getMemDC(), stickx + _camera->getCam()->x, 255 + _camera->getCam()->y);
		if (att > attack->getMaxFrameX())
		{
			fightatt2s1 = true;
			fcount2 = 1;
			te = (312 - stickx) / te2;
			frofs = false;
		}
	}
	if (fcount2 == 1)
	{
		IMAGEMANAGER->findImage("frororo")->frameRender(getMemDC(), _camera->getCam()->x + fowx, _camera->getCam()->y + CENTERY - 107);
		IMAGEMANAGER->findImage("gage")->render(getMemDC(), textrc.left, textrc.top);
		IMAGEMANAGER->findImage("stick")->frameRender(getMemDC(), stickx + _camera->getCam()->x, 255 + _camera->getCam()->y);
		frororo->setFrameY(1);
		if (fowx < 219 + fcount3)
		{
			fowx += 1;


		}
		if (fowx == 219 + fcount3)
		{
			fcount2 = 2;
			fcount3 -= 1;
		}
		if (fcount3 < 0)fcount2 = 3;
	}
	if (fcount2 == 2)
	{
		IMAGEMANAGER->findImage("frororo")->frameRender(getMemDC(), _camera->getCam()->x + fowx, _camera->getCam()->y + CENTERY - 107);
		IMAGEMANAGER->findImage("gage")->render(getMemDC(), textrc.left, textrc.top);
		IMAGEMANAGER->findImage("stick")->frameRender(getMemDC(), stickx + _camera->getCam()->x, 255 + _camera->getCam()->y);
		if (fowx > 219 - fcount3)
		{
			fowx -= 1;


		}
		if (fowx == 219 - fcount3)
		{
			fcount2 = 1;
			fcount3 -= 1;
		}
		if (fcount3 < 0)fcount2 = 3;
	}
	if (fcount2 == 3)
	{
		if (epa2 < 20)
		{
			fcount2 = 4;
			
			tindex = 0;
		}
		if (epa2 > 20)fcount2 = 5;
		if (epa2 == 20)fcount2 = 5;
	}
	if (fcount2 == 4)
	{
		IMAGEMANAGER->findImage("tototo")->frameRender(getMemDC(), towx + _camera->getCam()->x, 40 + _camera->getCam()->y);
		IMAGEMANAGER->findImage("frororo")->frameRender(getMemDC(), _camera->getCam()->x + fowx, _camera->getCam()->y + CENTERY - 107);
		if (fowx > -190)
		IMAGEMANAGER->findImage("gagef")->frameRender(getMemDC(), textrc.left, textrc.top);
		fcount4++;
		if (fcount4 % 5 == 0)fcount5++;
		gagef->setFrameX(fcount5);
		if (towx>500)towx -= 2;
		if (towx < 502)
		{
			lacount++;
			if (lacount > 60)
			{
				IMAGEMANAGER->findImage("frororo")->frameRender(getMemDC(), _camera->getCam()->x + fowx, _camera->getCam()->y + CENTERY - 107);
				frofs = false;
				frororo->setFrameY(0);
			}
			if (lacount > 200)
			{
				frororo->setFrameX(1);
				fowx -= 1;
			}
		}
		if (fowx < -190)
		{
			tototo->setFrameX(1);
			textnum = 10;
			if (tindex > 38)
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					SCENEMANAGER->changeScene("stage7");
					// 공격했지만 안죽음 전투종료
				}
			}
		}
	}
	if (fcount2 == 5)
	{
		IMAGEMANAGER->findImage("gagef")->frameRender(getMemDC(), textrc.left, textrc.top);
		IMAGEMANAGER->findImage("lv2rkfk")->render(getMemDC(), 29 + _camera->getCam()->x, 397 + _camera->getCam()->y);
		fcount4++;
		textnum = 11;
		if (fcount4 % 5 == 0)fcount5++;
		gagef->setFrameX(fcount5);
		if(fcount5==0)IMAGEMANAGER->findImage("frotk")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 1)IMAGEMANAGER->findImage("frotk2")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 2)IMAGEMANAGER->findImage("frotk3")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 3)IMAGEMANAGER->findImage("frotk4")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 4)IMAGEMANAGER->findImage("frotk5")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 5)IMAGEMANAGER->findImage("frotk6")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 6)IMAGEMANAGER->findImage("frotk7")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 7)IMAGEMANAGER->findImage("frotk8")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 8)IMAGEMANAGER->findImage("frotk9")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 9)IMAGEMANAGER->findImage("frotk10")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 10)IMAGEMANAGER->findImage("frotk11")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 11)IMAGEMANAGER->findImage("frotk12")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 12)IMAGEMANAGER->findImage("frotk13")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 13)IMAGEMANAGER->findImage("frotk14")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 14)IMAGEMANAGER->findImage("frotk15")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 15)IMAGEMANAGER->findImage("frotk16")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 16)IMAGEMANAGER->findImage("frotk17")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 17)IMAGEMANAGER->findImage("frotk18")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 18)IMAGEMANAGER->findImage("frotk19")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 19)IMAGEMANAGER->findImage("frotk20")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 20)IMAGEMANAGER->findImage("frotk21")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 21)IMAGEMANAGER->findImage("frotk22")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 22)IMAGEMANAGER->findImage("frotk23")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (fcount5 == 23)IMAGEMANAGER->findImage("frotk24")->render(getMemDC(), 54 + _camera->getCam()->x, 7 + _camera->getCam()->y);
		if (tindex > 64)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				_player->getPlayer()->Lv = 2;
				_player->getPlayer()->Gold += 20;
				_player->getPlayer()->MaxExp = 20;
				_player->getPlayer()->MaxHp = 24;
				_player->getPlayer()->CurExp = 0;
				_player->getPlayer()->killstage7frog = true;
				SCENEMANAGER->changeScene("stage7");
				//프로깃 죽을 xp+10  G+20  LV2로 오름 전투종료
			}
		}

	}



}

void stage7battle::fightatt2()
{
	fcount7++;
	/*Rectangle(getMemDC(), dbox.left, dbox.top, dbox.right, dbox.bottom);*/
	/*IMAGEMANAGER->findImage("red")->render(getMemDC(), dbox.left+2, dbox.top+11);*/
	IMAGEMANAGER->findImage("hp2")->render(getMemDC(), 216 + _camera->getCam()->x, 119 + _camera->getCam()->y);
	IMAGEMANAGER->findImage("hp")->render(getMemDC(), 217 + _camera->getCam()->x, 120 + _camera->getCam()->y, 0, 0, hpx, 13);
	if (te>0)epa = rhd * (2 - te);
	if (te<0)epa = rhd * (2 + te);
	if (te == 0)epa = rhd * 2;
	epa2 = epa;
	if(hpx>100-(epa2*5)&&hpx>0)hpx -= 2;
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
		if (fcount7>38)fcount6 = 1;
	}
	if (fcount6 == 1)
	{
		if (dboxy < 80)dboxy += 1;
	}
	if (fcount7 > 160)fightatt2s1 = false;
}

void stage7battle::fightmiss()
{
	if (fowx > -190)
	IMAGEMANAGER->findImage("gagef")->frameRender(getMemDC(), textrc.left, textrc.top);
	fcount4++;
	if (fcount4 % 5 == 0)fcount5++;
	gagef->setFrameX(fcount5);
	if (count < 1)misss = true;
	IMAGEMANAGER->findImage("tototo")->frameRender(getMemDC(), towx + _camera->getCam()->x, 40 + _camera->getCam()->y);
	if (towx>500)towx -= 2;
	if (towx < 502)
	{
		lacount++;
		if (lacount > 60)
		{
			IMAGEMANAGER->findImage("frororo")->frameRender(getMemDC(), _camera->getCam()->x + fowx, _camera->getCam()->y + CENTERY - 107);
			frofs = false;
		}
		if (lacount > 200)
		{
			frororo->setFrameX(1);
			fowx -= 1;
		}
	}
	if (fowx < -190)
	{
		tototo->setFrameX(1);
		textnum = 10;
		if (tindex > 38)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				SCENEMANAGER->changeScene("stage7");
				// 공격 미스전투종료
			}
		}
	}
}

void stage7battle::actchoice()
{
	if (next == 0)
	{
		IMAGEMANAGER->findImage("heart")->render(getMemDC(), 55 + _camera->getCam()->x, 270 + _camera->getCam()->y);
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
			next = 1;
			textnum = 4;
		}
	}
	if (next == 1)
	{
		IMAGEMANAGER->findImage("heart")->render(getMemDC(), 55 + _camera->getCam()->x, 270 + _camera->getCam()->y);
		if (KEYMANAGER->isOnceDown(VK_LEFT))
		{
			next = 2;
		}
		if (KEYMANAGER->isOnceDown(VK_RIGHT))
		{
			next = 2;
		}
		if (KEYMANAGER->isOnceDown(VK_DOWN))
		{
			next = 3;
		}
		if (KEYMANAGER->isOnceDown(VK_UP))
		{
			next = 3;
		}
		if (KEYMANAGER->isOnceDown('Z'))
		{
			next = 4;
			tindex = 0;
			textnum = 5;
		}
		if (KEYMANAGER->isOnceDown('X'))
		{
			next = 0;
			textnum = 2;
		}
	}
	if (next == 2)
	{
		IMAGEMANAGER->findImage("heart")->render(getMemDC(), 295 + _camera->getCam()->x, 270 + _camera->getCam()->y);
		if (KEYMANAGER->isOnceDown(VK_LEFT))
		{
			next = 1;
		}
		if (KEYMANAGER->isOnceDown(VK_RIGHT))
		{
			next = 1;
		}
		if (KEYMANAGER->isOnceDown(VK_DOWN))
		{
			next = 3;
		}
		if (KEYMANAGER->isOnceDown(VK_UP))
		{
			next = 3;
		}
		if (KEYMANAGER->isOnceDown('Z'))
		{
			next = 5;
			tindex = 0;
			textnum = 6;
		}
		if (KEYMANAGER->isOnceDown('X'))
		{
			next = 0;
			textnum = 2;
		}
	}
	if (next == 3)
	{
		IMAGEMANAGER->findImage("heart")->render(getMemDC(), 55 + _camera->getCam()->x, 310 + _camera->getCam()->y);
		if (KEYMANAGER->isOnceDown(VK_LEFT))
		{
			next = 2;
		}
		if (KEYMANAGER->isOnceDown(VK_RIGHT))
		{
			next = 2;
		}
		if (KEYMANAGER->isOnceDown(VK_DOWN))
		{
			next = 1;
		}
		if (KEYMANAGER->isOnceDown(VK_UP))
		{
			next = 1;
		}
		if (KEYMANAGER->isOnceDown('Z'))
		{
			next = 6;
			tindex = 0;
			textnum = 7;
		}
		if (KEYMANAGER->isOnceDown('X'))
		{
			next = 0;
			textnum = 2;
		}
	}
	if (next == 4)
	{
		if (tindex > 54)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				next = 7;
				tindex = 0;
				textnum = 99;
			}
		}
		if (KEYMANAGER->isOnceDown('X'))
		{
			tindex = 100;
		}
	}
	if (next == 5)
	{
		if (tindex > 72)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				next = 7;
				tindex = 0;
				textnum = 99;
			}
		}
		if (KEYMANAGER->isOnceDown('X'))
		{
			tindex = 100;
		}
	}
	if (next == 6)
	{
		if (tindex > 65)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				next = 7;
				textnum = 99;
				tindex = 0;
			}
		}
		if (KEYMANAGER->isOnceDown('X'))
		{
			tindex = 100;
		}
	}
	if (next == 7)
	{
		IMAGEMANAGER->findImage("tototo")->frameRender(getMemDC(), towx + _camera->getCam()->x, 40 + _camera->getCam()->y);
		if (towx>500)towx -= 2;
		if (towx < 502)
		{
			lacount++;
			if (lacount > 60)
			{
				IMAGEMANAGER->findImage("frororo")->frameRender(getMemDC(), _camera->getCam()->x + fowx, _camera->getCam()->y + CENTERY - 107);
				frofs = false;
			}
			if (lacount > 200)
			{
				frororo->setFrameX(1);
				fowx -= 1;
			}
		}
		if (fowx < -190)
		{
			tototo->setFrameX(1);
			textnum = 10;
			if (tindex > 38)
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					SCENEMANAGER->changeScene("stage7");
					// 대화끝 전투종료
				}
			}
		}
	}
}

void stage7battle::mercychoice()
{
	if (next == 0)
	{
		if (!hs)
		{
			IMAGEMANAGER->findImage("heart")->render(getMemDC(), 55+_camera->getCam()->x, 270+ _camera->getCam()->y);
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
				next = 3;
				textnum = 99;
				tindex = 0;
			}
		}
		if (hs)
		{
			IMAGEMANAGER->findImage("heart")->render(getMemDC(), 55+ _camera->getCam()->x, 310+ _camera->getCam()->y);
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
	if (next == 3)
	{
		IMAGEMANAGER->findImage("tototo")->frameRender(getMemDC(), towx + _camera->getCam()->x, 40 + _camera->getCam()->y);
		if(towx>500)towx -= 2;
		if (towx < 502)
		{
			lacount++;
			if (lacount > 60)
			{
				IMAGEMANAGER->findImage("frororo")->frameRender(getMemDC(), _camera->getCam()->x + fowx, _camera->getCam()->y + CENTERY - 107);
				frofs = false;
			}
			if (lacount > 200)
			{
				frororo->setFrameX(1);
				fowx -= 1;
			}
		}
		if (fowx < -190)
		{
			tototo->setFrameX(1);
			textnum = 10;
			if (tindex > 38)
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					SCENEMANAGER->changeScene("stage7");
					//살려주기 전투종료
				}
			}
		}
	}
	if (next == 4)
	{
		IMAGEMANAGER->findImage("heartw")->frameRender(getMemDC(), heartwx, 310+ _camera->getCam()->y);
		fcount++;
		if (fcount % 10 == 0)findex++;
		heartw->setFrameX(findex);
		if (findex > heartw->getMaxFrameX())findex = 0;
		heartwx -= 1;
		runcount++;
		if (runcount >  100)
		{
			SCENEMANAGER->changeScene("stage7");
			//도망치기 전투종료 
		}
	}
}

void stage7battle::TextControl()
{

	char str[128];
	/*if (!textrc2s)
	{*/
		HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성		//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		SelectObject(getMemDC(), font);
	/*}
	if (textrc2s)
	{
		HFONT font = CreateFont(20, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		SelectObject(getMemDC(), font);
	}*/

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 0)
		hInputFile = CreateFile(_T("image/undertale/battle/stage7battle/0.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	
	if (textnum == 2)
		hInputFile = CreateFile(_T("image/undertale/battle/stage7battle/2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("image/undertale/battle/dummy/3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 4)
		hInputFile = CreateFile(_T("image/undertale/battle/stage7battle/4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 5)
		hInputFile = CreateFile(_T("image/undertale/battle/stage7battle/5.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 6)
		hInputFile = CreateFile(_T("image/undertale/battle/stage7battle/6.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 7)
		hInputFile = CreateFile(_T("image/undertale/battle/stage7battle/7.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 10)
		hInputFile = CreateFile(_T("image/undertale/battle/dummy/10.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 11)
		hInputFile = CreateFile(_T("image/undertale/battle/stage7battle/11.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 12)
		hInputFile = CreateFile(_T("image/undertale/battle/dummy/12.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

	ReadFile(hInputFile, buf, 999 * sizeof(TCHAR), &dwRead, NULL);
	CloseHandle(hInputFile);
	/*if (!textrc2s)
	{*/
		DrawText(getMemDC(), buf, tindex, &textrc, DT_LEFT);
		DeleteObject(font);
	/*}
	if (textrc2s)
	{
		DrawText(getMemDC(), buf, tindex, &textrc2, DT_LEFT);
	}*/



}

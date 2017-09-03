#include "stdafx.h"
#include "firstbattle.h"
#include "player.h"
#include "camera.h"
firstbattle::firstbattle()
{
}


firstbattle::~firstbattle()
{
}

HRESULT firstbattle::init()
{
	font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
	font2 = CreateFont(20, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성

	//  ----- 카메라 초기화 -----
	_camera->getCam()->x = 0;
	_camera->getCam()->y = 0;
	//  -------------------------
	count = 0;
	textcount = 0;
	bullcount = 15;
	homingcount = 0;
	firebx = 470;
	fireby = 180;
	flx = 278;
	fly = 170;
	tox = 800;
	IMAGEMANAGER->addImage("1", "image/undertale/battle/flabttle/1.bmp", 1068, 728, false, false);
	IMAGEMANAGER->addImage("2", "image/undertale/battle/flabttle/2.bmp", 51, 52, false, false);
	IMAGEMANAGER->addImage("heart", "image/undertale/battle/heart.bmp", 16, 16, true, RGB(255, 0, 255));
	/*IMAGEMANAGER->addImage("box", "image/undertale/battle/battlebox.bmp", 165, 140, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("box2", "image/undertale/battle/flabttle/bbox2.bmp", 105, 95, true, RGB(255, 0, 255));*/
	lv = IMAGEMANAGER->addFrameImage("lv1313", "image/undertale/battle/flabttle/lv.bmp", 512, 31, 2, 1, true, RGB(255, 0, 255));
	flw = IMAGEMANAGER->addFrameImage("fl", "image/undertale/battle/flabttle/flw11.bmp", 170, 992, 2, 11, true, RGB(255,0,255));
	bullet = IMAGEMANAGER->addFrameImage("bull", "image/undertale/battle/shot.bmp", 24, 12, 2, 1, true, RGB(255, 0, 255));
	bboxr = IMAGEMANAGER->addFrameImage("box", "image/undertale/battle/flabttle/battlebox2.bmp", 496, 140, 3, 1, true, RGB(255, 0, 255));
	fireball = IMAGEMANAGER->addFrameImage("fireB", "image/undertale/battle/flabttle/fireBall.bmp", 256, 64, 4, 1, true, RGB(255, 0, 255));
	torel = IMAGEMANAGER->addFrameImage("tore", "image/undertale/battle/flabttle/tore.bmp", 290, 410, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bl", "image/undertale/battle/flabttle/bl.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("s1", "image/undertale/battle/flabttle/s1.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("s2", "image/undertale/battle/flabttle/s2.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("s3", "image/undertale/battle/flabttle/s3.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("s4", "image/undertale/battle/flabttle/s4.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("s5", "image/undertale/battle/flabttle/s5.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("s6", "image/undertale/battle/flabttle/s6.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("s7", "image/undertale/battle/flabttle/s7.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("s8", "image/undertale/battle/flabttle/s8.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("s9", "image/undertale/battle/flabttle/s9.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("s10", "image/undertale/battle/flabttle/s10.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("b1", "image/undertale/battle/flabttle/b1.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("b2", "image/undertale/battle/flabttle/b2.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("b3-1", "image/undertale/battle/flabttle/b3-1.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("b3-2", "image/undertale/battle/flabttle/b3-2.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("b3-3", "image/undertale/battle/flabttle/b3-3.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("b3-4", "image/undertale/battle/flabttle/b3-4.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("b3-5", "image/undertale/battle/flabttle/b3-5.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("b3-6", "image/undertale/battle/flabttle/b3-6.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("b3-7", "image/undertale/battle/flabttle/b3-7.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("b4", "image/undertale/battle/flabttle/b4.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("b5", "image/undertale/battle/flabttle/b5.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("d1", "image/undertale/battle/flabttle/d1.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bs1", "image/undertale/battle/flabttle/bs1.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bs3", "image/undertale/battle/flabttle/bs3.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bs2", "image/undertale/battle/flabttle/bs2.bmp", 240, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("t1", "image/undertale/battle/flabttle/t1.bmp", 240, 105, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("t2", "image/undertale/battle/flabttle/t2.bmp", 240, 105, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("t3", "image/undertale/battle/flabttle/t3.bmp", 240, 105, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("t4", "image/undertale/battle/flabttle/t4.bmp", 240, 105, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("t5", "image/undertale/battle/flabttle/t5.bmp", 240, 105, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("t6", "image/undertale/battle/flabttle/t6.bmp", 240, 105, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bullb", "image/undertale/battle/flabttle/bull.bmp", 224, 223, true, RGB(255, 0, 255));
	bbox = RectMake(242, 292, 155, 130);
	bbox2 = RectMake(273, 332, 95, 85);
	flface = true;
	patton1s = false;
	patton2s = false;
	patton3s = false;
	patton4s = false;
	fires = false;
	patton1render = false;
	patton2render = false;
	patton3render = false;
	patton4render = false;
	starts = false;
	nots1s = false;
	nots2s = false;
	nots3s = false;
	beShots = false;
	deads = false;
	key = true;
	bullxy2 = true;
	bullxy3 = true;
	bullxy4 = true;
	bullder = true;
	bullcos = false;
	fireballs = false;
	once = false;

	for (int i = 0; i < BULLETMAX; i++)
	{
		_bullet[i].isFire = false;
		
	}
	for (int i = 0; i < 100; i++)
	{
		bullx[i] = 320;
		bully[i] = 225;
	}
	return S_OK;
}

void firstbattle::release()
{

}


void firstbattle::update()
{
	stcount++;
	pl = RectMake(_player->getPlayer()->x + 10, _player->getPlayer()->y + 23, 16, 16);
	if (!deads)
	{
		if (pl.right > bbox.right)_player->getPlayer()->x -= 2;
		if (pl.left < bbox.left)_player->getPlayer()->x += 2;
		if (pl.bottom > bbox.bottom)_player->getPlayer()->y -= 2;
		if (pl.top < bbox.top)_player->getPlayer()->y += 2;
	}
	if (deads)
	{
		if (pl.right > bbox2.right)_player->getPlayer()->x -= 2;
		if (pl.left < bbox2.left)_player->getPlayer()->x += 2;
		if (pl.bottom > bbox2.bottom)_player->getPlayer()->y -= 2;
		if (pl.top < bbox2.top)_player->getPlayer()->y += 2;
	}
	
	if (stcount>75)
	if (KEYMANAGER->isOnceDown('Z'))
	{
		if(key)textcount+=1;
	}
	/*if (KEYMANAGER->isOnceDown('X'))
	{
		bullcos = true;
	}
	if (KEYMANAGER->isOnceDown('C'))
	{
		tttt += 1;
	}*/
	if(starts)start();
	if (nots1s)nots1();
	if (nots2s)nots2();
	if (nots3s)nots3();
	if (beShots)beShot();
	if (bullcos)bullco();
	if (deads)dead();
	if(stcount>75)
	FrameUpdate();
	bullrender();

	if (patton1s)patton1();
	if (patton2s)patton2();
	if (patton3s)patton3();
	if (patton4s)patton4();
	if (fires)fire();

	if (!beShots&&!deads)
	{
		if (bully[4] > 560 && bully[4] < 580)
		{
			starts = false;
			nots1s = true;;
			textcount = 0;
			homingcount = 0;
		}
		if (bully[7] > 560 && bully[7] < 580)
		{
			nots1s = false;
			nots2s = true;;
			textcount = 0;
			homingcount = 0;
		}
		if (bully[12] > 560 && bully[12] < 580)
		{
			nots2s = false;
			nots3s = true;;
			textcount = 0;
			homingcount = 0;
		}
	}
	for (int i = 0; i < 15; i++)
	{
		if (IntersectRect(&wal, &_bullet[i].rcBullet, &pl))
		{
			if (!once)
			{
				if (!SOUNDMANAGER->isPlaySound("underattack"))
				{
					SOUNDMANAGER->play("underattack", 1.f);
					once = true;
				}
				
			}
			starts = false;
			nots1s = false;
			nots2s = false;
			bullder = false;
			beShots = true;
			textcount = 0;
			homingcount = 0;
		}
	}
	
}


void firstbattle::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	IMAGEMANAGER->findImage("1")->render(getMemDC(),0,0);
	
	if (nots1s)nots1();
	if (nots2s)nots2();
	if (nots3s)nots3();
	if (starts)start();
	if (beShots)beShot();
	if (deads)dead();
	if (bullcos)bullco();
	if (stcount > 50)
	{
		IMAGEMANAGER->findImage("fl")->frameRender(getMemDC(), flx, fly);
		IMAGEMANAGER->findImage("box")->frameRender(getMemDC(), 237, 282);
		IMAGEMANAGER->findImage("lv1313")->frameRender(getMemDC(), 196, 429);
		
		if (stcount > 75 && stcount < 80)
			starts = true;
	}
	

	IMAGEMANAGER->findImage("heart")->render(getMemDC(), pl.left, pl.top);

	if (bullder)
	{
		for (int i = 0; i < 15; i++)
		{
			IMAGEMANAGER->findImage("bull")->frameRender(getMemDC(), _bullet[i].rcBullet.left, _bullet[i].rcBullet.top);
		}
	}
	IMAGEMANAGER->findImage("2")->render(getMemDC(), 0, 0);
	/*for (int i = 15; i < BULLETMAX; i++)
	{
		
		IMAGEMANAGER->findImage("bull")->frameRender(getMemDC(), _bullet[i].rcBullet.left, _bullet[i].rcBullet.top);
	}*/
	//char str[128];
	//sprintf_s(str, "to.x : %f", bullx[tttt]);
	//TextOut(getMemDC(),100, 100, str, strlen(str));
	//char str2[128];
	//sprintf_s(str, "to.x : %f", bully[tttt]);
	//TextOut(getMemDC(), 100, 200, str, strlen(str));
}

void firstbattle::start()
{
	
	
	if (textcount == 0)
	{
		flw->setFrameY(0);
		IMAGEMANAGER->findImage("s1")->render(getMemDC(), 366, 165);
	}
	if (textcount == 1)IMAGEMANAGER->findImage("s2")->render(getMemDC(), 366, 165);
	if (textcount == 2)IMAGEMANAGER->findImage("s3")->render(getMemDC(), 366, 165);
	if (textcount == 3)IMAGEMANAGER->findImage("s4")->render(getMemDC(), 366, 165);
	if (textcount == 4)IMAGEMANAGER->findImage("s5")->render(getMemDC(), 366, 165);
	if (textcount == 5)
	{
		key = false;
		flw->setFrameY(8);
		textindex++;
			if (textindex % 100 == 0)textcount += 1;
	}
	if (textcount == 6)
	{
		textindex = 0;
		patton1s = true;
		key = true;
		flw->setFrameY(1);
		IMAGEMANAGER->findImage("s6")->render(getMemDC(), 366, 165);
	}
	if (textcount == 7)IMAGEMANAGER->findImage("s7")->render(getMemDC(), 366, 165);
	if (textcount == 8)
	{
		flw->setFrameY(4);
		IMAGEMANAGER->findImage("s8")->render(getMemDC(), 366, 165);
	}
	if (textcount == 9)
	{
		flw->setFrameY(0);
		IMAGEMANAGER->findImage("s9")->render(getMemDC(), 366, 165);
	}
	if (textcount == 10)
	{
		homingcount++;
		fires = true;
		key = false;
		IMAGEMANAGER->findImage("s10")->render(getMemDC(), 366, 165);
		
	}



}

void firstbattle::nots1()
{
	if (textcount == 0)
	{
		
		flface = false;
		flw->setFrameY(5);
		textcount += 1;
		
	}
	if (textcount == 1)
	{
		
		textindex++;
		if (textindex % 200 == 0)textcount += 1;
	}
		if (textcount == 2)
		{
			SOUNDMANAGER->stop("flower1");
			textindex=0; 
			key = true;
			flface = true;
			IMAGEMANAGER->findImage("b1")->render(getMemDC(), 366, 165);
		}
		if (textcount == 3)IMAGEMANAGER->findImage("b2")->render(getMemDC(), 366, 165);
		if (textcount == 4)
		{
			key = false;
			flface = false;
			flw->setFrameY(0);
			patton2s = true;
			homingcount++;
		}
}

void firstbattle::nots2()
{
	if (textcount == 0)
	{
		flw->setFrameY(6);
		textcount += 1;

	}
	if (textcount == 1)
	{
		textindex++;
		if (textindex % 200 == 0)
		{
			textcount += 1;
			textindex = 0;
		}
	}
	if (textcount == 2)
	{
		flface = true;
		textindex++;
		IMAGEMANAGER->findImage("b3-1")->render(getMemDC(), 366, 165);
		if (textindex % 200 == 0)
		{
			textcount += 1;
			textindex = 0;
		}
	}
	if (textcount == 3)
	{
		textindex++;
		IMAGEMANAGER->findImage("b3-2")->render(getMemDC(), 366, 165);
		if (textindex % 200 == 0)
		{
			textcount += 1;
			textindex = 0;
		}
	}
	if (textcount == 4)
	{
		textindex++;
		IMAGEMANAGER->findImage("b3-3")->render(getMemDC(), 366, 165);
		if (textindex % 200 == 0)
		{
			textcount += 1;
			textindex = 0;
		}
	}
	if (textcount == 5)
	{
		textindex++;
		IMAGEMANAGER->findImage("b3-4")->render(getMemDC(), 366, 165);
		if (textindex % 200 == 0)
		{
			textcount += 1;
			textindex = 0;
		}
	}
	if (textcount == 6)
	{
		textindex++;
		IMAGEMANAGER->findImage("b3-5")->render(getMemDC(), 366, 165);
		if (textindex % 200 == 0)
		{
			textcount += 1;
			textindex = 0;
		}
	}
	if (textcount == 7)
	{
		textindex++;
		IMAGEMANAGER->findImage("b3-6")->render(getMemDC(), 366, 165);
		if (textindex % 100 == 0)
		{
			textcount += 1;
			textindex = 0;
		}
	}
	if (textcount == 8)
	{
		textindex++;
		flw->setFrameY(9);
		IMAGEMANAGER->findImage("b3-6")->render(getMemDC(), 366, 165);
		if (textindex % 150 == 0)
		{
			textcount += 1;
			textindex = 0;
		}
	}
	if (textcount == 9)
	{
		flw->setFrameY(0);
		IMAGEMANAGER->findImage("b3-7")->render(getMemDC(), 366, 165);
		patton3s = true;
		homingcount++;
	}
}

void firstbattle::nots3()
{
	if (textcount == 0)
	{
		patton4s = true;
		textcount += 1;

	}
	if (textcount == 1)
	{
		textindex++;
		if (textindex % 200 == 0)
		{
			textcount += 1;
			textindex = 0;
		}
	}
	if (textcount == 2)
	{
		textindex++;
		flw->setFrameY(7);
		if (textindex % 50 == 0)
		{
			textcount += 1;
			textindex = 0;
		}
	}
	if (textcount == 3)
	{
		textindex++;
		flw->setFrameY(7);
		if (textindex % 50 == 0)
		{
			textcount += 1;
			textindex = 0;
		}
	}
	if (textcount == 4)
	{
		key = true;
		IMAGEMANAGER->findImage("b4")->render(getMemDC(), 366, 165);
	}
	if (textcount == 5)IMAGEMANAGER->findImage("b5")->render(getMemDC(), 366, 165);
	if (textcount == 6)
	{
		
		key = false;
		nots3s = false;
		deads = true;;
		textcount = 0;
	}
	
	
}

void firstbattle::beShot()
{
	SOUNDMANAGER->stop("flower1");
	if (textcount == 0)
	{
		patton4s = true;
		lv->setFrameX(1);
		flw->setFrameY(2);
		flface = false;
		textcount += 1;
		

	}
	if (textcount == 1)
	{
		textindex++;
		if (textindex % 200 == 0)
		{
			textcount += 1;
			textindex = 0;
		}
	}
	if (textcount == 2)
	{
		flface = true;
		key = true;
		IMAGEMANAGER->findImage("bs1")->render(getMemDC(), 366, 165);
	}
	if (textcount == 3)IMAGEMANAGER->findImage("bs2")->render(getMemDC(), 366, 165);
    if (textcount == 4)IMAGEMANAGER->findImage("bs3")->render(getMemDC(), 366, 165);
	if (textcount == 5)
	{
		
		key = false;
		beShots = false;
		deads = true;
		textcount = 0;
	}

}

void firstbattle::dead()
{
	if (textcount == 0)
	{
		
		textindex++;
		if (textindex % 10 == 0)
		{
			textcount += 1;
			textindex = 0;
		}
		flface = false;
		flw->setFrameY(7);
		bboxr->setFrameX(1);
	}
	if (textcount == 1)
	{
		textindex++;
		if (textindex % 10 == 0)
		{
			textcount += 1;
			textindex = 0;
			bboxr->setFrameX(2);

		}

	}
	if (textcount == 2)
	{
		patton4render = true;
		bullcos = true;
		textindex++;
		if (textindex % 300 == 0)
		{
			textcount += 1;
			textindex = 0;

		}
	}
	if (textcount == 3)
	{
		flface = true;
		key = true;
		IMAGEMANAGER->findImage("d1")->render(getMemDC(), 366, 165);
		bullxy4 = false;
	}
	if (textcount == 4)
	{
		if(!SOUNDMANAGER->isPlaySound("flowerlaugh"))
		SOUNDMANAGER->play("flowerlaugh", 1.f);
		key = false;
		flw->setFrameY(3);
		bullx[15] += 0.0815;
		bully[15] += 0.0038;
		bullx[16] += 0.0792;
		bully[16] += 0.0130;
		bullx[17] += 0.0776;
		bully[17] += 0.0207;
		bullx[18] += 0.0753;//237
		bully[18] += 0.0292;//327
		bullx[19] += 0.0723;
		bully[19] += 0.0376;
		bullx[20] += 0.0692;
		bully[20] += 0.0446;
		bullx[21] += 0.0630;
		bully[21] += 0.0515;
		bullx[22] += 0.0569;//261
		bully[22] += 0.0584;//289
		bullx[23] += 0.0507;
		bully[23] += 0.0638;
		bullx[24] += 0.0446;
		bully[24] += 0.0676;
		bullx[25] += 0.0369;
		bully[25] += 0.0723;
		bullx[26] += 0.0292;
		bully[26] += 0.0761;
		bullx[27] += 0.0207;
		bully[27] += 0.0784;
		bullx[28] += 0.0123;
		bully[28] += 0.0807;
		bullx[29] += 0.0038;//330
		bully[29] += 0.0815;//259
		bullx[30] -= 0.0038;
		bully[30] += 0.0815;
		bullx[31] -= 0.0123;
		bully[31] += 0.0807;
		bullx[32] -= 0.0207;
		bully[32] += 0.0784;
		bullx[33] -= 0.0292;
		bully[33] += 0.0761;
		bullx[34] -= 0.0369;
		bully[34] += 0.0723;
		bullx[35] -= 0.0446;
		bully[35] += 0.0676;
		bullx[36] -= 0.0507;
		bully[36] += 0.0638;
		bullx[37] -= 0.0569;//261
		bully[37] += 0.0584;//289
		bullx[38] -= 0.0630;
		bully[38] += 0.0515;
		bullx[39] -= 0.0692;
		bully[39] += 0.0446;
		bullx[40] -= 0.0723;
		bully[40] += 0.0376;
		bullx[41] -= 0.0753;//237
		bully[41] += 0.0292;//327
		bullx[42] -= 0.0776;
		bully[42] += 0.0207;
		bullx[43] -= 0.0792;
		bully[43] += 0.0130;
		bullx[44] -= 0.0815;
		bully[44] += 0.0038;

		bullx[59] -= 0.0038;
		bully[59] -= 0.0815;
		bullx[58] -= 0.0123;
		bully[58] -= 0.0807;
		bullx[57] -= 0.0207;
		bully[57] -= 0.0784;
		bullx[56] -= 0.0292;
		bully[56] -= 0.0761;
		bullx[55] -= 0.0369;
		bully[55] -= 0.0723;
		bullx[54] -= 0.0446;
		bully[54] -= 0.0676;
		bullx[53] -= 0.0507;
		bully[53] -= 0.0638;
		bullx[52] -= 0.0569;//261
		bully[52] -= 0.0584;//289
		bullx[51] -= 0.0630;
		bully[51] -= 0.0515;
		bullx[50] -= 0.0692;
		bully[50] -= 0.0446;
		bullx[49] -= 0.0723;
		bully[49] -= 0.0376;
		bullx[48] -= 0.0753;//237
		bully[48] -= 0.0292;//327
		bullx[47] -= 0.0776;
		bully[47] -= 0.0207;
		bullx[46] -= 0.0792;
		bully[46] -= 0.0130;
		bullx[45] -= 0.0815;
		bully[45] -= 0.0038;

		bullx[60] += 0.0038;
		bully[60] -= 0.0815;
		bullx[61] += 0.0123;
		bully[61] -= 0.0807;
		bullx[62] += 0.0207;
		bully[62] -= 0.0784;
		bullx[63] += 0.0292;
		bully[63] -= 0.0761;
		bullx[64] += 0.0369;
		bully[64] -= 0.0723;
		bullx[65] += 0.0446;
		bully[65] -= 0.0676;
		bullx[66] += 0.0507;
		bully[66] -= 0.0638;
		bullx[67] += 0.0569;//261
		bully[67] -= 0.0584;//289
		bullx[68] += 0.0630;
		bully[68] -= 0.0515;
		bullx[69] += 0.0692;
		bully[69] -= 0.0446;
		bullx[70] += 0.0723;
		bully[70] -= 0.0376;
		bullx[71] += 0.0753;//237
		bully[71] -= 0.0292;//327
		bullx[72] += 0.0776;
		bully[72] -= 0.0207;
		bullx[73] += 0.0792;
		bully[73] -= 0.0130;
		bullx[74] += 0.0815;
		bully[74] -= 0.0038;

		textindex++;
		if (textindex % 700 == 0)
		{
			textcount += 1;
			textindex = 0;

		}
		for (int i = 15; i < 75; i++)
		{
			if (IntersectRect(&RectMake(0, 0, 0, 0), &pl, &_bullet[i].rcBullet))
			{
				if(!SOUNDMANAGER->isPlaySound("heal"))
				SOUNDMANAGER->play("heal",1.f);
				SOUNDMANAGER->stop("flowerlaugh");
				textcount += 1;
				textindex = 0;
			}
		}

	}
	if (textcount == 5)
	{
		lv->setFrameX(0);
		flface = false;
		bullcos = false;

		textindex++;
		if (textindex % 300 == 0)
		{
			textindex = 0;
			textcount += 1;
			

		}
	}
	if (textcount == 6)
	{
		flw->setFrameX(1);
		flw->setFrameY(6);
		textindex++;
		if (!textindex % 100 == 0)
		{
			if (textindex % 20 == 0)
			{
				IMAGEMANAGER->findImage("fireB")->frameRender(getMemDC(), 470, 180);
			}
		}
		if (textindex % 100==0)
		{
			textcount += 1;
			textindex = 0;
		}
		
	}
	if (textcount == 7)
	{
		IMAGEMANAGER->findImage("fireB")->frameRender(getMemDC(), firebx , fireby);
		fireballs = true;
		firebx -= 2;
		if (firebx < 350)
		{
			flw->setFrameY(10);
			flw->setFrameX(0);
			textcount += 1;
		}

	}
	if (textcount == 8)
	{
		flw->setFrameX(1);
		flx -= 3;
		fly -= 0.5;
		if(flx<-90)textcount += 1;
	}
	if (textcount == 9)
	{
		IMAGEMANAGER->findImage("tore")->frameRender(getMemDC(), tox, 80);
		if (tox > 240)
		{
			tox -= 2;		
		}
		if (tox == 240)textcount += 1;
		SOUNDMANAGER->play("flowerdie", 1.f);
	}
	if (textcount == 10)
	{
		key = true;
		flface = true;;
		
		IMAGEMANAGER->findImage("tore")->frameRender(getMemDC(), 240, 80);
		IMAGEMANAGER->findImage("t1")->render(getMemDC(), 366, 80);
	}
	if (textcount == 11)
	{
		IMAGEMANAGER->findImage("tore")->frameRender(getMemDC(), 240, 80);
		torel->setFrameY(1);
		IMAGEMANAGER->findImage("t2")->render(getMemDC(), 366, 80);
	}
	if (textcount == 12)
	{
		IMAGEMANAGER->findImage("tore")->frameRender(getMemDC(), 240, 80);
		IMAGEMANAGER->findImage("t3")->render(getMemDC(), 366, 80);
	}
	if (textcount == 13)
	{
		IMAGEMANAGER->findImage("tore")->frameRender(getMemDC(), 240, 80);
		IMAGEMANAGER->findImage("t4")->render(getMemDC(), 366, 80);
	}
	if (textcount == 14)
	{
		IMAGEMANAGER->findImage("tore")->frameRender(getMemDC(), 240, 80);
		IMAGEMANAGER->findImage("t5")->render(getMemDC(), 366, 80);
	}
	if (textcount == 15)
	{
		IMAGEMANAGER->findImage("tore")->frameRender(getMemDC(), 240, 80);
		IMAGEMANAGER->findImage("t6")->render(getMemDC(), 366, 80);
	}
	if (textcount == 16)
	{
		SCENEMANAGER->changeScene("stage2_1");
	}

}


void firstbattle::FrameUpdate()
{
	count++;
	if (count % 10 == 0)index++;

	if(flface)flw->setFrameX(index);
	if (index > flw->getMaxFrameX())index = 0;
		
	if (flface)torel->setFrameX(index);
	if (index > torel->getMaxFrameX())index = 0;

	if (count % 10 == 0)fireballindex++;
	if (fireballs)fireball->setFrameX(fireballindex);
	if (fireballindex > fireball->getMaxFrameX())fireballindex = 0;

	if (count % 4 == 0)bullindex++;
	bullet->setFrameY(0);
	bullet->setFrameX(bullindex);
	if (bullindex > bullet->getMaxFrameX())bullindex = 0;
	

}

void firstbattle::bullrender()
{
	
		if (patton1render)
		{
			for (int i = 0; i < 5; i++)
			{
				_bullet[i].rcBullet = RectMakeCenter(bullx[i], bully[i], 12, 12);
			}
		}
		if (patton2render)
		{
			for (int i = 5; i < 10; i++)
			{
				_bullet[i].rcBullet = RectMakeCenter(bullx[i], bully[i], 12, 12);
			}
		}
		if (patton3render)
		{
			for (int i = 10; i < 15; i++)
			{
				_bullet[i].rcBullet = RectMakeCenter(bullx[i], bully[i], 12, 12);
			}
		}
		if (patton4render)
		{
			for (int i = 15; i < 75; i++)
			{
				
				_bullet[i].rcBullet = RectMakeCenter(bullx[i], bully[i], 12, 12);
			}
		}
	
}

void firstbattle::patton1()
{
	patton1render = true;
	if (count % 2 == 0)
	{
		if (bullx[0] > 198)
		{
			bullx[0] -= 5.1;
			bully[0] -= 1.7;
		}
		if (bullx[1] > 248)
		{
			bullx[1] -= 3;
			bully[1] -= 4;
		}
		if (bully[2] > 98)
		{
			bully[2] -= 5.5;
		}
		if (bullx[3] < 388)
		{
			bullx[3] += 3;
			bully[3] -= 4;
		}
		if (bullx[4] < 438)
		{
			bullx[4] += 5.1;
			bully[4] -= 1.7;
		}
	}

}

void firstbattle::patton2()
{
	if (bullxy2)
	{
		bullx[5] = 197;
		bully[5] = 184;
		bullx[6] = 248;
		bully[6] = 129;
		bullx[7] = 320;
		bully[7] = 93;
		bullx[8] = 389;
		bully[8] = 133;
		bullx[9] = 442;
		bully[9] = 184;
		if (bully[9] = 184)bullxy2 = false;
	}
	patton2render = true;
}

void firstbattle::patton3()
{
	if (bullxy3)
	{
		bullx[10] = 197;
		bully[10] = 184;
		bullx[11] = 248;
		bully[11] = 129;
		bullx[12] = 320;
		bully[12] = 93;
		bullx[13] = 389;
		bully[13] = 133;
		bullx[14] = 442;
		bully[14] = 184;
		if (bully[14] = 184)bullxy3 = false;
	}
	patton3render = true;
}

void firstbattle::patton4()
{
	if (bullxy4)
	{
		bullx[15] = 230;
		bully[15] = 360;
		bullx[16] = 232;
		bully[16] = 348;
		bullx[17] = 234;
		bully[17] = 338;
		bullx[18] = 237;
		bully[18] = 327;
		bullx[19] = 241;
		bully[19] = 316;
		bullx[20] = 245;
		bully[20] = 307;
		bullx[21] = 253;
		bully[21] = 298;
		bullx[22] = 261;
		bully[22] = 289;
		bullx[23] = 269;
		bully[23] = 282;
		bullx[24] = 277;
		bully[24] = 277;
		bullx[25] = 287;
		bully[25] = 271;
		bullx[26] = 297;
		bully[26] = 266;
		bullx[27] = 308;
		bully[27] = 263;
		bullx[28] = 319;
		bully[28] = 260;
		bullx[29] = 330;
		bully[29] = 259;
		bullx[30] = bullx[31] - (bullx[29] - bullx[28]);
		bully[30] = bully[29];
		bullx[31] = bullx[32] - (bullx[28] - bullx[27]);
		bully[31] = bully[28];
		bullx[32] = bullx[33] - (bullx[27] - bullx[26]);
		bully[32] = bully[27];
		bullx[33] = bullx[34] - (bullx[26] - bullx[25]);
		bully[33] = bully[26];
		bullx[34] = bullx[35] - (bullx[25] - bullx[24]);
		bully[34] = bully[25];
		bullx[35] = bullx[36] - (bullx[24] - bullx[23]);
		bully[35] = bully[24];
		bullx[36] = bullx[37] - (bullx[23] - bullx[22]);
		bully[36] = bully[23];
		bullx[37] = bullx[38] - (bullx[22] - bullx[21]);
		bully[37] = bully[22];
		bullx[38] = bullx[39] - (bullx[21] - bullx[20]);
		bully[38] = bully[21];
		bullx[39] = bullx[40] - (bullx[20] - bullx[19]);
		bully[39] = bully[20];
		bullx[40] = bullx[41] - (bullx[19] - bullx[18]);
		bully[40] = bully[19];
		bullx[41] = bullx[42] - (bullx[18] - bullx[17]);
		bully[41] = bully[18];
		bullx[42] = bullx[43] - (bullx[17] - bullx[16]);
		bully[42] = bully[17];
		bullx[43] = 438;
		bully[43] = 348;
		bullx[44] = 440;
		bully[44] = 360;

		bullx[45] = 440;
		bully[45] = 370;
		bullx[46] = bullx[43];
		bully[46] = bully[45] + (bully[44] - bully[43]);
		for (int i = 47; i < 76; i++)
		{
			bullx[i] = bullx[89 - i];
			bully[i] = bully[i - 1] + (bully[90 - i] - bully[89 - i]);		
		}
		
	}

	
}

void firstbattle::fire()
{
	patton1s = false;
	
	if (patton1render)
	{
		for (int i = 0; i < 5; i++)
		{
			if (homingcount<51&&!homingcount==0)
			{
				_bullet[i].homing = ((pl.left - bullx[i]) / 80);
			}
			bullx[i] += _bullet[i].homing;
			bully[i] += 1.5;
		}
	}
	if (patton2render)
	{
		for (int i = 5; i < 10; i++)
		{
			if (homingcount<51 && !homingcount == 0)
			{
				_bullet[i].homing = ((pl.left - bullx[i]) / 80);
			}
			bullx[i] += _bullet[i].homing;
			bully[i] += 1.5;
		}
	}
	if (patton3render)
	{
		for (int i = 10; i < 15; i++)
		{
			if (homingcount<51 && !homingcount == 0)
			{
				_bullet[i].homing = ((pl.left - bullx[i]) / 80);
			}
			bullx[i] += _bullet[i].homing;
			bully[i] += 1.5;
		}
	}
	
}

void firstbattle::bullco()
{
	
		bullcount2++;

		if (bullcount < 75)
		{
			if (bullcount2 % 5 == 0)
			{
				bullcount += 1;
				if(!SOUNDMANAGER->isPlaySound("flowermakebullet"))
				SOUNDMANAGER->play("flowermakebullet", 1.f);
			}
		}
			for (int i = 15; i < bullcount; i++)
			{

			IMAGEMANAGER->findImage("bull")->frameRender(getMemDC(), _bullet[i].rcBullet.left, _bullet[i].rcBullet.top);
			}
	
	
}

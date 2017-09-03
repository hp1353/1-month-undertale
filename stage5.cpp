#include "stdafx.h"
#include "stage5.h"
#include "player.h"
#include "camera.h"
#include "stage3.h"
stage5::stage5()
{
}


stage5::~stage5()
{
}

HRESULT stage5::init()
{
	if (!SOUNDMANAGER->isPauseSound("stagesound"))
	{
		SOUNDMANAGER->resume("stagesound");
	}
	_player->getPlayer()->SaveStageNum = 5;
	IMAGEMANAGER->addImage("stage5", "image/undertale/stage/stage5.bmp", 1503, 481, false, false);
	river = IMAGEMANAGER->addFrameImage("river", "image/undertale/object/river.bmp", 222, 300, 3, 1, false, false);
	switch1 = IMAGEMANAGER->addFrameImage("switch1", "image/undertale/object/switch1.bmp", 28, 36, 2, 1, true, RGB(255, 0, 255));
	switch2 = IMAGEMANAGER->addFrameImage("switch2", "image/undertale/object/switch1.bmp", 28, 36, 2, 1, true, RGB(255, 0, 255));
	switch3 = IMAGEMANAGER->addFrameImage("switch3", "image/undertale/object/switch1.bmp", 28, 36, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("say1", "image/undertale/event/stage5Event/say1.bmp", 578, 152, false, false);
	IMAGEMANAGER->addImage("say2", "image/undertale/event/stage5Event/say2.bmp", 578, 152, false, false);
	IMAGEMANAGER->addImage("say3", "image/undertale/event/stage5Event/say3.bmp", 578, 152, false, false);
	IMAGEMANAGER->addImage("say4", "image/undertale/event/stage5Event/say4.bmp", 578, 152, false, false);
	IMAGEMANAGER->addImage("say5", "image/undertale/event/stage5Event/say5.bmp", 578, 152, false, false);
	IMAGEMANAGER->addImage("say6", "image/undertale/event/stage5Event/say6.bmp", 578, 152, false, false);
	IMAGEMANAGER->addImage("say7", "image/undertale/event/stage5Event/say7.bmp", 578, 152, false, false);
	IMAGEMANAGER->addImage("say8", "image/undertale/event/stage5Event/say8.bmp", 578, 152, false, false);
	IMAGEMANAGER->addImage("say9", "image/undertale/event/stage5Event/say9.bmp", 578, 152, false, false);
	IMAGEMANAGER->addImage("say10", "image/undertale/event/stage5Event/say10.bmp", 578, 152, false, false);
	IMAGEMANAGER->addImage("obtext1", "image/undertale/event/stage5Event/obtext1.bmp", 578, 152, false, false);
	IMAGEMANAGER->addImage("obtext2", "image/undertale/event/stage5Event/obtext2.bmp", 578, 152, false, false);
	obrc1 = RectMake(778, 107, 20, 50);
	obrc2 = RectMake(1199, 107, 20, 50);
	obrc3 = RectMake(1275, 107, 20, 50);
	torielface_1 = IMAGEMANAGER->addFrameImage("torielface_1", "image/undertale/npc/torielface_0.bmp", 288, 88, 3, 1, false, false);
	torielface_talk = IMAGEMANAGER->addFrameImage("torielface_talk", "image/undertale/npc/torielface_talk.bmp", 192, 88, 2, 1, false, false);

	trap2 = IMAGEMANAGER->addFrameImage("trap22", "image/undertale/object/trap2.bmp", 80, 80, 2, 1, false, false);
	count = 0;
	index = 0;
	obcount = 0;
	obindex = 0;
	_camera->getCam()->overviewY = true;
	_camera->getCam()->overviewX = true;
	_player->getPlayer()->x = 268;
	_player->getPlayer()->y = 410;
	_player->getPlayer()->isDown = false;
	_player->getPlayer()->isUp = true;
	toriel = IMAGEMANAGER->addFrameImage("toriel", "image/undertale/npc/toriel.bmp", 200, 416, 4, 4, true, RGB(255, 0, 255));
	toriel->setX(CENTERX - toriel->getFrameWidth() / 2 + 10);
	toriel->setY(220);
	toriel->setFrameX(0);
	toriel->setFrameY(0);
	says = false;
	says4 = false;
	firstsay = false;
	talkcountreset1 = false;
	talkcountreset2 = false;
	talkcountreset3 = false;
	firstmove = false;
	secondsay = false;
	sayonceagain = false;
	viewFirstEvent = false;
	_player->getPlayer()->talk = false;
	fuck = false;
	lastmove = false;
	switch1on = false;
	switch2on = false;
	switch3on = false;
	textcount = 2;

	obtrc1 = RectMake(200, 100, 50, 50);
	obtrc2 = RectMake(255, 240, 50, 50);
	obtext1 = false;
	obtext2 = false;
	textcount1 = 0;
	textcount2 = 0;
	talkcountreset4 = false;
	talkcountreset5 = false;
	talkcountreset6 = false;
	talkcountreset7 = false;
	talk = false;
	keys = true;
	says2 = false;
	says3 = false;
	nexts = false;
	says5 = false;
	says6 = false;
	nexts2 = false;
	obt1 = false;
	obt2 = false;
	nextdoor = RectMake(1470, 300, 50, 50);
	isfirstsay = false;

	tcount = 0;
	tindex = 0;
	textnum = 0;
	once = false;
	once2 = false;

	nexttext1 = false;
	nexttext2 = false;
	nexttext3 = false;

	_stage3->_torielMotion.movedown = true;
	_stage3->_torielMotion.idle = true;
	_stage3->_torielMotion.walk = false;
	
	sound = false;
	talkcount = 0;
	talkindex = 0;
	count1 = 0;
	count2 = 0;
	index1 = 0;

	return S_OK;
}

void stage5::release()
{
}

void stage5::update()
{
	FrameUpdate();
	if (textnum != 0)_player->getPlayer()->control = false;
	if (textnum == 0)_player->getPlayer()->control = true;
	
	Event();
	torielFrame();
	loadmark = RectMakeCenter(toriel->getX() + toriel->getFrameWidth() / 2, toriel->getY() + toriel->getFrameHeight() / 2 + 40, 50, 100);
	LoadMark();
	if (firstmove && !viewFirstEvent && !switch1on)
	{
		if (toriel->getX() < 920)
		{
			toriel->setX(toriel->getX() + 3);
		
		}
		_stage3->_torielMotion.moveup = false;
		_stage3->_torielMotion.moveleft = false;
		_stage3->_torielMotion.moveright = true;
		_stage3->_torielMotion.movedown = false;
		_stage3->_torielMotion.walk = true;
		_stage3->_torielMotion.idle = false;
		if (toriel->getX() >= 920 && !switch1on)
		{
			firstmove = false;
			_stage3->_torielMotion.idle = true;
			_stage3->_torielMotion.walk = false;
			_stage3->_torielMotion.moveright = false;
			//toriel->setFrameY(2);
			//toriel->setFrameX(0);
			viewFirstEvent = true;
			_player->getPlayer()->talk = false;
		}
	}

	if (switch1on)
	{
		if (toriel->getX() < 1380)
			toriel->setX(toriel->getX() + 3);
		_stage3->_torielMotion.walk = true;
		_stage3->_torielMotion.idle = false;
		_stage3->_torielMotion.moveup = false;
		_stage3->_torielMotion.moveleft = false;
		_stage3->_torielMotion.moveright = true;
		_stage3->_torielMotion.movedown = false;
		
		if (toriel->getX() > 1380)
		{
			_stage3->_torielMotion.idle = true;
			_stage3->_torielMotion.walk = false;
			_stage3->_torielMotion.moveright = false;

		}
	}
	if (switch2on && textnum == 0 && !once2)
	{
		textnum = 9;
		once2 = true;
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &obrc1))
	{
		if (KEYMANAGER->isOnceDown('Z'))
		{

			switch1->setFrameX(1);
			switch1on = true;
		}
	}
	else if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &obrc2))
	{
		if (!switch2on)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				switch2->setFrameX(1);
				switch2on = true;
				trap2->setFrameX(1);
				if (!SOUNDMANAGER->isPlaySound("boom") && !sound)
				{
					_player->getPlayer()->boom = true;
					SOUNDMANAGER->play("boom", 1.f);
					sound = true;
				}
			}
		}
	}

	else if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &obrc3))
	{
		if (_player->getPlayer()->pressZ)
		{
			if (!lastmove)
			{
				textnum = 13;
			}
			if (lastmove)
			{
				textnum = 16;
			}
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &obtrc1))
	{
		if (_player->getPlayer()->pressZ)
		{
			textnum = 12;
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &obtrc2))
	{
		if (_player->getPlayer()->pressZ)
		{
			textnum = 11;
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &loadmark) && textnum == 0)
	{
		if (_player->getPlayer()->pressZ)
		{
			if (toriel->getX() < 930)
			{
				if (nexttext1)
				textnum = 4;
				if(!nexttext1)
				textnum = 3;
			}
			else
			{
				if (nexttext2)
					textnum = 7;
				if (!nexttext2)
					textnum = 6;
			}
		}
	}
	if (lastmove)
	{

		_stage3->_torielMotion.moveright = true;
		_stage3->_torielMotion.walk = true;
		_stage3->_torielMotion.idle = false;
		toriel->setX(toriel->getX() + 3);

	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("stage6");
	}
	if(textnum == 11 || textnum == 12 || textnum ==16 )textrc = RectMake(_camera->getCam()->x + 80, _camera->getCam()->y + 20, 500, 150);
	else textrc = RectMake(_camera->getCam()->x + 170, _camera->getCam()->y + 20, 500, 150);

	TextControlUpdate();
	
	

}

void stage5::render()
{
	IMAGEMANAGER->findImage("stage5")->render(getMemDC());
	IMAGEMANAGER->findImage("river")->frameRender(getMemDC(), 480, 140);
	IMAGEMANAGER->findImage("river")->frameRender(getMemDC(), 984, 140);
	IMAGEMANAGER->findImage("switch1")->frameRender(getMemDC(), 778, 107);
	IMAGEMANAGER->findImage("switch2")->frameRender(getMemDC(), 1199, 107);
	IMAGEMANAGER->findImage("switch3")->frameRender(getMemDC(), 1275, 107);
	IMAGEMANAGER->findImage("trap22")->frameRender(getMemDC(), 1422, 281);
	
	IMAGEMANAGER->findImage("toriel")->frameRender(getMemDC(), toriel->getX(), toriel->getY());
	
	if (textnum == 11 || textnum == 12 || textnum == 16)IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
	else if (textnum != 0)
	{
		IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
		if (!talkend)
		{
			IMAGEMANAGER->findImage("torielface_talk")->frameRender(getMemDC(), _camera->getCam()->x + 50, _camera->getCam()->y + 30);
		}
		if (talkend)
			IMAGEMANAGER->findImage("torielface_1")->frameRender(getMemDC(), _camera->getCam()->x + 48, _camera->getCam()->y + 34);

	}
	TextControl();
	
	if (_player->getPlayer()->viewEvery)
	{
		char str[128];
		sprintf_s(str, "to.x : %f", toriel->getX());
		TextOut(getMemDC(), toriel->getX(), toriel->getY() - 40, str, strlen(str));
		char str1[128];
		sprintf_s(str1, "to.y : %f", toriel->getY());
		TextOut(getMemDC(), toriel->getX(), toriel->getY() - 20, str1, strlen(str1));
		char str2[128];
		sprintf_s(str2, "talkIndex : %d", _player->getPlayer()->talkindex);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y + 20, str2, strlen(str2));
		Rectangle(getMemDC(), loadmark.left, loadmark.top, loadmark.right, loadmark.bottom);
		char str3[128];
		sprintf_s(str3, "talk : %d", _player->getPlayer()->talk);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y + 40, str3, strlen(str3));
		char str4[128];
		sprintf_s(str4, "sayonceagain : %d", sayonceagain);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y + 60, str4, strlen(str4));
		char str5[128];
		sprintf_s(str5, "fuck : %d", fuck);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y + 80, str5, strlen(str5));
		char str6[128];
		sprintf_s(str6, "textcount : %d", textcount);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y + 100, str6, strlen(str6));
		Rectangle(getMemDC(), obrc1.left, obrc1.top, obrc1.right, obrc1.bottom);
		Rectangle(getMemDC(), obrc2.left, obrc2.top, obrc2.right, obrc2.bottom);
		Rectangle(getMemDC(), obrc3.left, obrc3.top, obrc3.right, obrc3.bottom);
		Rectangle(getMemDC(), obtrc1.left, obtrc1.top, obtrc1.right, obtrc1.bottom);
		Rectangle(getMemDC(), obtrc2.left, obtrc2.top, obtrc2.right, obtrc2.bottom);
		char str7[128];
		sprintf_s(str7, "obindex : %d", obindex);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y + 120, str6, strlen(str6));
		Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
	}

}

void stage5::FrameUpdate()
{
	obcount++;
	if (obcount % 20 == 0)
	{

		river->setFrameX(obindex);
		obindex++;
		if (obindex > river->getMaxFrameX()) obindex = 0;


	}
}

void stage5::Event()
{
	if (_player->getPlayer()->y < 350 && textnum == 0 && !firstmove &&!once)
	{
		textnum = 1;
		
		firstsay = true;

	}
}

void stage5::FirstSay()
{
	if (firstsay)
	{

		if(once)
		firstmove = true;

	}
}

void stage5::SecondSay()
{

	if (!talkcountreset2)
	{
		_player->getPlayer()->talking = true;
		_player->getPlayer()->frameReset = true;
		_player->getPlayer()->control = false;
		_player->getPlayer()->talkindex = 1;
		talkcountreset2 = true;
	}
	if (_player->getPlayer()->talkindex == 1)
	{
		IMAGEMANAGER->findImage("say3")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);

	}
	if (_player->getPlayer()->talkindex <= 0)
	{
		_player->getPlayer()->control = true;
		if (!fuck)
			_player->getPlayer()->talk = false;
		_player->getPlayer()->talking = false;
		sayonceagain = true;
	}
}
void stage5::ThirdSay()
{
	if (sayonceagain)
	{
		_player->getPlayer()->talking = true;
		_player->getPlayer()->frameReset = true;
		_player->getPlayer()->control = false;
		_player->getPlayer()->talkindex = 2;
		if (_player->getPlayer()->talkindex == 2)
		{
			IMAGEMANAGER->findImage("say4")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
		}
		if (_player->getPlayer()->talkindex == 1)
		{
			IMAGEMANAGER->findImage("say5")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
		}
		if (_player->getPlayer()->talkindex <= 0)
		{
			_player->getPlayer()->control = true;
			_player->getPlayer()->talking = false;
			//_player->getPlayer()->talk = false;
		}
	}
}
void stage5::torielFrame()
{

	//토리엘 입모양
	if (!talkend)
	{
		talkcount++;
		if (talkcount % 10 == 0)
		{

			torielface_talk->setFrameX(talkindex);
			talkindex++;
			if (talkindex > torielface_talk->getMaxFrameX()) talkindex = 0;


		}
	}
	if (talkend) //토리엘 눈감빡이는얼굴
	{
		torielface_talk->setFrameX(0);
		count1++;
		count2++;
		if (count1 % 10 == 0)
		{

			torielface_1->setFrameX(index1);
			if (index1 == 0)
			{
				if (count2 % 100 == 0) index1++;
			}
			else index1++;
			if (index1 > torielface_1->getMaxFrameX()) index1 = 0;


		}
	}

	if (_stage3->_torielMotion.idle)
	{
		toriel->setFrameX(0);
		toriel->setFrameY(0);
	}
	if (_stage3->_torielMotion.walk)
	{
		count++;
		if (count % 10 == 0)
		{

			toriel->setFrameX(index);
			index++;
			if (index > toriel->getMaxFrameX()) index = 0;


		}

	}

	if (_stage3->_torielMotion.movedown)
	{
		_stage3->_torielMotion.moveleft = false;
		_stage3->_torielMotion.moveright = false;
		_stage3->_torielMotion.moveup = false;
		toriel->setFrameY(0);

	}
	if (_stage3->_torielMotion.moveleft)
	{
		_stage3->_torielMotion.movedown = false;
		_stage3->_torielMotion.moveright = false;
		_stage3->_torielMotion.moveup = false;
		toriel->setFrameY(2);
	}
	if (_stage3->_torielMotion.moveright)
	{
		_stage3->_torielMotion.movedown = false;
		_stage3->_torielMotion.moveleft = false;
		_stage3->_torielMotion.moveup = false;
		toriel->setFrameY(3);
	}
	if (_stage3->_torielMotion.moveup)
	{
		_stage3->_torielMotion.movedown = false;
		_stage3->_torielMotion.moveleft = false;
		_stage3->_torielMotion.moveright = false;
		toriel->setFrameY(1);
	}
	if (viewFirstEvent && !switch1on) toriel->setFrameY(2);
	if (toriel->getX()>1380 && !lastmove)toriel->setFrameY(2);
}

void stage5::LoadMark()
{
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &loadmark))
	{
		if (_player->getPlayer()->rc.right > loadmark.left + 10)
		{
			_player->getPlayer()->x -= 2;
		}
		if (_player->getPlayer()->talk && viewFirstEvent && sayonceagain)
		{
			//_player->getPlayer()->talk = true;
			//thirdsay = true;
			textnum = 4;
		}
		else if (_player->getPlayer()->talk && viewFirstEvent)
		{
			//secondsay = true;
			textnum = 3;

		}
		fuck = false;
	}
	else
	{
		fuck = true;
	}
}

void stage5::TextControlUpdate()
{
	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 59)
			{
				talkend = false;
				tindex++;
			}
		}
		if (textnum == 2)
		{
			if (tindex < 66)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 3)
		{
			if (tindex < 34)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 4)
		{
			if (tindex < 46)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 5)
		{
			if (tindex < 23)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 6)
		{
			if (tindex < 30)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 7)
		{
			if (tindex < 39)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 8)
		{
			if (tindex < 36)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 9)
		{
			if (tindex < 45)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 10)
		{
			if (tindex < 23)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 11)
		{
			if (tindex < 42)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 12)
		{
			if (tindex < 20)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 13)
		{
			if (tindex < 21)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 14)
		{
			if (tindex < 29)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 15)
		{
			if (tindex < 34)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 16)
		{
			if (tindex < 37)
			{
				tindex++;
				talkend = false;
			}
		}
	}

	if (textnum == 1)
	{
		if (tindex == 59)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{

				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 59;
		}
	}
	if (textnum == 2)
	{
		if (tindex == 66)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				once = true;
				firstmove = true;
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 66;
		}
	}
	if (textnum == 3)
	{
		if (tindex == 34)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				nexttext1 = true;
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 34;
		}
	}
	if (textnum == 4)
	{

		if (tindex == 46)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 46;
		}
	}
	if (textnum == 5)
	{
		if (tindex == 23)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 23;
		}
	}
	if (textnum == 6)
	{
		if (tindex == 30)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
				nexttext2 = true;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 30;
		}
	}
	if (textnum == 7)
	{
		if (tindex == 39)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 39;
		}
	}
	if (textnum == 8)
	{
		if (tindex == 36)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 36;
		}
	}
	if (textnum == 9)
	{
		if (tindex == 45)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 45;
		}
	}
	if (textnum == 10)
	{
		if (tindex == 23)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				lastmove = true;
				
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 23;
		}
	}
	if (textnum == 11)
	{
		if (tindex == 42)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 42;
		}
	}
	if (textnum == 12)
	{
		if (tindex == 20)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 20;
		}
	}
	if (textnum == 13)
	{
		if (tindex == 21)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 21;
		}
	}
	if (textnum == 14)
	{
		if (tindex == 29)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 29;
		}
	}
	if (textnum == 15)
	{
		if (tindex == 34)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 34;
		}
	}
	if (textnum == 16)
	{
		if (tindex == 37)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				lastmove = true;

				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 37;
		}
	}
}

void stage5::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/stage5/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/stage5/text2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("text/stage5/text3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 4)
		hInputFile = CreateFile(_T("text/stage5/text4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 5)
		hInputFile = CreateFile(_T("text/stage5/text5.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 6)
		hInputFile = CreateFile(_T("text/stage5/text6.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 7)
		hInputFile = CreateFile(_T("text/stage5/text7.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 8)
		hInputFile = CreateFile(_T("text/stage5/text8.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 9)
		hInputFile = CreateFile(_T("text/stage5/text9.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 10)
		hInputFile = CreateFile(_T("text/stage5/text10.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 11)
		hInputFile = CreateFile(_T("text/stage5/text11.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 12)
		hInputFile = CreateFile(_T("text/stage5/text12.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 13)
		hInputFile = CreateFile(_T("text/stage5/text13.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 14)
		hInputFile = CreateFile(_T("text/stage5/text14.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 15)
		hInputFile = CreateFile(_T("text/stage5/text15.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 16)
		hInputFile = CreateFile(_T("text/stage5/text16.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

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

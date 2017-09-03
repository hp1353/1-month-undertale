#include "stdafx.h"
#include "leftroom.h"
#include "player.h"
#include "camera.h"
#include "stage3.h"

leftroom::leftroom()
{
}


leftroom::~leftroom()
{
}

HRESULT leftroom::init()
{
	_player->getPlayer()->SaveStageNum = 1;
	IMAGEMANAGER->addImage("leftroom", "image/undertale/stage/leftroom.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("torielsit", "image/undertale/npc/torielsit.bmp", 96, 106, true, RGB(255, 0, 255));
	fire = IMAGEMANAGER->addFrameImage("fire", "image/undertale/object/fire.bmp", 260, 34, 5, 1, false, false);
	toriel = IMAGEMANAGER->addFrameImage("toriel", "image/undertale/npc/toriel.bmp", 200, 416, 4, 4, true, (RGB(255, 0, 255)));
	toriel->setX(260);
	toriel->setY(100);
	_stage3->_torielMotion.idle = true;
	_stage3->_torielMotion.walk = false;
	_stage3->_torielMotion.moveleft = false;
	_stage3->_torielMotion.moveright = true;
	torielface_1 = IMAGEMANAGER->addFrameImage("torielface_1", "image/undertale/npc/torielface_2.bmp", 288, 88, 3, 1, false, false);//기본표정눈감기
	torielface_0 = IMAGEMANAGER->addFrameImage("torielface_0", "image/undertale/npc/torielface_2.bmp", 288, 88, 3, 1, false, false);//오른쪽표정 눈감기
	torielface_talk = IMAGEMANAGER->addFrameImage("torielface_talk", "image/undertale/npc/torielface_talk2.bmp", 192, 88, 2, 1, false, false);//기본표정 말하기
	torielsitup = IMAGEMANAGER->addFrameImage("toriel_situp", "image/undertale/npc/toriel_situp.bmp", 566, 106, 6, 1, true, RGB(255, 0, 255));
	if (!_player->getPlayer()->isbeforekitchen)
	{
		_player->getPlayer()->x = 600;
		_player->getPlayer()->y = 330;
	}
	if (_player->getPlayer()->isbeforekitchen)
	{
		_player->getPlayer()->isbeforekitchen = false;
		_player->getPlayer()->x = 100;
		_player->getPlayer()->y = 100;
	}
	_camera->getCam()->x = 0;
	_camera->getCam()->y = 0;
	_camera->getCam()->overviewX = true;
	_camera->getCam()->overviewY = true;

	nextdoor = RectMake(110, 20, 50, 50);
	backdoor = RectMake(650, 330, 50, 50);
	firecount = 0;
	fireindex = 0;

	count = 0;
	index = 0;
	count1 = 0;
	index1 = 0;
	count2 = 0;
	talkend = true;
	viewfuck = false;
	fuckcount = 0;
	nextevent = false;
	tormove1 = false;
	tormove2 = false;
	talkcount = 0;
	talkindex = 0;
	heartcontrol = 160;
	nosleep = false;
	textcount = 0;
	count5 = 0;
	index5 = 0;
	torielangry = false;
	_player->getPlayer()->isbeforeleftroom = true;
	return S_OK;
}

void leftroom::release()
{
}

void leftroom::update()
{
	if (torielangry)
	{
		_player->getPlayer()->angrytoriel = true;
	}
	textrc = RectMake(_camera->getCam()->x + 170, _camera->getCam()->y + 20, 500, 150);
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("kitchen");
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &backdoor))
	{
		SCENEMANAGER->changeScene("torielhome");
	}
	if (_player->getPlayer()->viewrightroomEvent && _player->getPlayer()->viewtorielhomeEvent && !torielangry &&!_player->getPlayer()->angrytoriel)
	torielsitrc = RectMake(220, 120, 100, 70);
	if(_player->getPlayer()->angrytoriel)torielsitrc = RectMake(0, 0, 0, 0);
	fireFrame();
	TextControlUpdate();
	torielFrame();

	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &torielsitrc))
	{
		if (_player->getPlayer()->pressZ && textnum == 0 && !torielangry)
		{
			if (nosleep) textnum = 32;
			if(!nosleep && textcount == 0) textnum = 1;
			if (textcount == 1) textnum = 13;
			if (textcount == 2) textnum = 12;
		}
	}
	if (textnum != 0)_player->getPlayer()->control = false;
	if (textnum == 0)_player->getPlayer()->control = true;
	if (KEYMANAGER->isOnceDown(VK_LEFT))
	{
		heartcontrol = 160;
	}
	if (KEYMANAGER->isOnceDown(VK_RIGHT))
	{
		heartcontrol = 300;
	}
	if (torielangry && index5 > 5 && toriel->getX() < 620)
	{
		_stage3->_torielMotion.walk = true;
		_stage3->_torielMotion.idle = false;
		_stage3->_torielMotion.moveright = true;
		toriel->setX(toriel->getX() + 4);
		toriel->setY(toriel->getY() + 2);
	}
	
}

void leftroom::render()
{
	IMAGEMANAGER->findImage("leftroom")->render(getMemDC());
	IMAGEMANAGER->findImage("fire")->frameRender(getMemDC(), 310, 115);
	
	if (_player->getPlayer()->viewrightroomEvent && _player->getPlayer()->viewtorielhomeEvent && !torielangry &&!_player->getPlayer()->angrytoriel)
	{
		IMAGEMANAGER->findImage("torielsit")->render(getMemDC(), 214, 99);
	}
	if(torielangry && index5 < 5)IMAGEMANAGER->findImage("toriel_situp")->frameRender(getMemDC(), 214, 99);

	if (textnum != 0)
	{


		IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
		if (!talkend)
		{
			IMAGEMANAGER->findImage("torielface_talk")->frameRender(getMemDC(), _camera->getCam()->x + 50, _camera->getCam()->y + 30);
		}
		if (talkend)
			IMAGEMANAGER->findImage("torielface_1")->frameRender(getMemDC(), _camera->getCam()->x + 48, _camera->getCam()->y + 34);
		if (textnum == 3 && tindex == 63)
			IMAGEMANAGER->findImage("heart")->render(getMemDC(), heartcontrol, 115);
		if (textnum == 313 && tindex == 62)
			IMAGEMANAGER->findImage("heart")->render(getMemDC(), heartcontrol, 115);
		if (textnum == 11 && tindex == 68)
			IMAGEMANAGER->findImage("heart")->render(getMemDC(), heartcontrol, 115);
		if (textnum == 7 && tindex == 68)
			IMAGEMANAGER->findImage("heart")->render(getMemDC(), heartcontrol, 115);
		if (textnum == 13 && tindex == 68)
			IMAGEMANAGER->findImage("heart")->render(getMemDC(), heartcontrol, 115);

	}
	if (index5 > 4)
	{
		if(toriel->getX() < 620)
		IMAGEMANAGER->findImage("toriel")->frameRender(getMemDC(), toriel->getX(), toriel->getY());
	}
	TextControl();
	
	if (_player->getPlayer()->viewEvery)
	{
		Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
		Rectangle(getMemDC(), backdoor.left, backdoor.top, backdoor.right, backdoor.bottom);
		Rectangle(getMemDC(), torielsitrc.left, torielsitrc.top, torielsitrc.right, torielsitrc.bottom);
	}
	else
	{

	}
}

void leftroom::fireFrame()
{
	fire->setFrameX(fireindex);
	firecount++;

	if (fireindex > fire->getMaxFrameX())
	{
		fireindex = 0;
	}
	else if (firecount % 10 == 0)fireindex++;
}

void leftroom::TextControlUpdate()
{
	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 22)
			{
				talkend = false;
				tindex++;
			}
		}
		if (textnum == 2)
		{
			if (tindex < 31)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 3)
		{
			if (tindex < 63)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 4)
		{
			if (tindex < 46)
			{
				talkend = false;
				tindex++;
			}
		}
		if (textnum == 5)
		{
			if (tindex < 46)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 6)
		{
			if (tindex < 53)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 7)
		{
			if (tindex < 68)
			{
				talkend = false;
				tindex++;
			}
		}
		if (textnum == 8)
		{
			if (tindex < 49)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 9)
		{
			if (tindex < 34)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 10)
		{
			if (tindex < 59)
			{
				talkend = false;
				tindex++;
			}
		}
		if (textnum == 11)
		{
			if (tindex < 68)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 12)
		{
			if (tindex < 48)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 31)
		{
			if (tindex < 14)
			{
				talkend = false;
				tindex++;
			}
		}
		if (textnum == 32)
		{
			if (tindex < 37)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 33)
		{
			if (tindex < 44)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 34)
		{
			if (tindex < 52)
			{
				talkend = false;
				tindex++;
			}
		}
		if (textnum == 35)
		{
			if (tindex < 59)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 36)
		{
			if (tindex < 37)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 37)
		{
			if (tindex < 32)
			{
				talkend = false;
				tindex++;
			}
		}
		if (textnum == 38)
		{
			if (tindex < 36)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 39)
		{
			if (tindex < 53)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 310)
		{
			if (tindex < 9)
			{
				talkend = false;
				tindex++;
			}
		}
		if (textnum == 311)
		{
			if (tindex < 42)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 312)
		{
			if (tindex < 30)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 313)
		{
			if (tindex < 62)
			{
				talkend = false;
				tindex++;
			}
		}
		if (textnum == 314)
		{
			if (tindex < 45)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 71)
		{
			if (tindex < 49)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 72)
		{
			if (tindex < 34)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 73)
		{
			if (tindex < 33)
			{
				tindex++;
				talkend = false;
			}
		}
		


	}

	if (textnum == 1)
	{
		if (tindex == 22)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 22;
		}
	}
	if (textnum == 2)
	{
		if (tindex == 31)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 31;
		}
	}
	if (textnum == 3)
	{
		if (tindex == 63)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				if (heartcontrol == 160)
				{
					textnum = 31;
					nosleep = true;
				}
				if (heartcontrol == 300)
				{
					textnum = 32;
				}
				
				
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 63;
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
	if (textnum == 6)
	{
		if (tindex == 53)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 53;
		}
	}
	if (textnum == 7)
	{
		if (tindex == 68)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{

				tindex = 0;
				if (heartcontrol == 160)
				{
					textcount += 1;
					textnum = 71;
				}
				if (heartcontrol == 300)
				{
					textnum = 8;
				}
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 68;
		}
	}
	if (textnum == 8)
	{
		if (tindex == 49)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 49;
		}
	}
	if (textnum == 9)
	{
		if (tindex == 34)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 34;
		}
	}
	if (textnum == 10)
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
	if (textnum == 11)
	{
		if (tindex == 68)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{

				tindex = 0;
				if (heartcontrol == 160)
				{
					textcount += 1;
					textnum = 314;
				}
				if (heartcontrol == 300)
				{
					textnum = 12;
				}
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 68;
		}
	}
	if (textnum == 12)
	{
		if (tindex == 48)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				_player->getPlayer()->angrytoriel = true;
				torielangry = true;
				tindex = 0;
				textnum = 0;

			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 48;
		}
	}
	if (textnum == 13)
	{
		if (tindex == 68)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				if (heartcontrol == 160)
				{
					textcount += 1;
					textnum = 314;
				}
				if (heartcontrol == 300)
				{
					textnum = 12;
				}

			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 68;
		}
	}
	if (textnum == 31)
	{
		if (tindex == 14)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 14;
		}
	}
	if (textnum == 32)
	{
		if (tindex == 37)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 37;
		}
	}
	if (textnum == 33)
	{
		if (tindex == 44)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 44;
		}
	}
	if (textnum == 34)
	{
		if (tindex == 52)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 52;
		}
	}
	if (textnum == 35)
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
	if (textnum == 36)
	{
		if (tindex == 37)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 37;
		}
	}
	if (textnum == 37)
	{
		if (tindex == 32)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 32;
		}
	}
	if (textnum == 38)
	{
		if (tindex == 36)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 36;
		}
	}
	if (textnum == 39)
	{
		if (tindex == 53)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 310;

			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 53;
		}
	}
	if (textnum == 310)
	{
		if (tindex == 9)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 9;
		}
	}
	if (textnum == 311)
	{
		if (tindex == 42)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 42;
		}
	}
	if (textnum == 312)
	{
		if (tindex == 30)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 30;
		}
	}
	if (textnum == 313)
	{
		if (tindex == 62)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				if (heartcontrol == 160)
				{
					textcount += 1;
					textnum = 314;
				}
				if (heartcontrol == 300)
				{
					textnum = 4;
				}

			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 62;
		}
	}
	if (textnum == 314)
	{
		if (tindex == 45)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 45;
		}
	}
	if (textnum == 71)
	{
		if (tindex == 49)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 49;
		}
	}
	if (textnum == 72)
	{
		if (tindex == 34)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 34;
		}
	}
	if (textnum == 73)
	{
		if (tindex == 33)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 7;

			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 33;
		}
	}
}

void leftroom::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/leftroom/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/leftroom/text2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("text/leftroom/text3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 4)
		hInputFile = CreateFile(_T("text/leftroom/text4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 5)
		hInputFile = CreateFile(_T("text/leftroom/text5.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 6)
		hInputFile = CreateFile(_T("text/leftroom/text6.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 7)
		hInputFile = CreateFile(_T("text/leftroom/text7.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 8)
		hInputFile = CreateFile(_T("text/leftroom/text8.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 9)
		hInputFile = CreateFile(_T("text/leftroom/text9.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 10)
		hInputFile = CreateFile(_T("text/leftroom/text10.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 11)
		hInputFile = CreateFile(_T("text/leftroom/text11.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 12)
		hInputFile = CreateFile(_T("text/leftroom/text12.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 13)
		hInputFile = CreateFile(_T("text/leftroom/text13.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 31)
		hInputFile = CreateFile(_T("text/leftroom/text3_1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 32)
		hInputFile = CreateFile(_T("text/leftroom/text3_2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 33)
		hInputFile = CreateFile(_T("text/leftroom/text3_3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 34)
		hInputFile = CreateFile(_T("text/leftroom/text3_4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 35)
		hInputFile = CreateFile(_T("text/leftroom/text3_5.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 36)
		hInputFile = CreateFile(_T("text/leftroom/text3_6.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 37)
		hInputFile = CreateFile(_T("text/leftroom/text3_7.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 38)
		hInputFile = CreateFile(_T("text/leftroom/text3_8.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 39)
		hInputFile = CreateFile(_T("text/leftroom/text3_9.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 310)
		hInputFile = CreateFile(_T("text/leftroom/text3_10.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 311)
		hInputFile = CreateFile(_T("text/leftroom/text3_11.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 312)
		hInputFile = CreateFile(_T("text/leftroom/text3_12.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 313)
		hInputFile = CreateFile(_T("text/leftroom/text3_13.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 314)
		hInputFile = CreateFile(_T("text/leftroom/text3_14.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 71)
		hInputFile = CreateFile(_T("text/leftroom/text7_1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 72)
		hInputFile = CreateFile(_T("text/leftroom/text7_2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 73)
		hInputFile = CreateFile(_T("text/leftroom/text7_3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

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

void leftroom::torielFrame()
{
	

	//토리엘 입모양
	if (torielangry)
	{
		count5++;
		if (count5 % 15 == 0)
		{

			torielsitup->setFrameX(index5);
			index5++;
			


		}
	}
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
			torielface_0->setFrameX(index1);
			if (index1 == 0)
			{
				if (count2 % 100 == 0) index1++;
			}
			else index1++;
			if (index1 > torielface_1->getMaxFrameX()) index1 = 0;
			if (index1 > torielface_0->getMaxFrameX()) index1 = 0;


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
}

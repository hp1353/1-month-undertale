#include "stdafx.h"
#include "ending.h"
#include "player.h"
#include "camera.h"

ending::ending()
{
}


ending::~ending()
{
}

HRESULT ending::init()
{
	IMAGEMANAGER->addImage("lastending", "image/undertale/stage/stage2_1.bmp", 640, 740, false, false);
	IMAGEMANAGER->addImage("light", "image/undertale/stage/light.bmp", 640, 740, false, false);
	IMAGEMANAGER->addImage("logo", "image/undertale/opening/logo.bmp", 640, 480, false, false);
	nextdoor = RectMake(300, 190, 50, 50);
	
	_player->getPlayer()->x = 300;
	_player->getPlayer()->y = 660;
	_camera->getCam()->x = 0;
	_camera->getCam()->y = 260;
	_camera->getCam()->overviewX = true;
	_camera->getCam()->overviewY = true;

	alpha = 0;
	over = false;

	count2 = 0;
	count = 0;
	index = 0;
	index2 = 0;

	flowerfun = IMAGEMANAGER->addFrameImage("flowerfun", "image/undertale/npc/flowerfun.bmp", 84, 42, 2, 1, true, RGB(255, 0, 255));
	flowerhide = IMAGEMANAGER->addFrameImage("flowerhide", "image/undertale/npc/flowerhide.bmp", 210, 42, 5, 1, true, RGB(255, 0, 255));

	tcount = 0;
	tindex = 0;
	textnum = 0;
	talkend = false;
    
	flower_1 = IMAGEMANAGER->addFrameImage("flower_1", "image/undertale/npc/flower_1.bmp", 168, 84, 2, 1, false, false);
	flower_2 = IMAGEMANAGER->addFrameImage("flower_2", "image/undertale/npc/flower_2.bmp", 168, 84, 2, 1, false, false);
	flower_3 = IMAGEMANAGER->addFrameImage("flower_3", "image/undertale/npc/flower_3.bmp", 168, 84, 2, 1, false, false);
	flower_4 = IMAGEMANAGER->addFrameImage("flower_4", "image/undertale/npc/flower_4.bmp", 168, 84, 2, 1, false, false);

	facecount1 = 0;
	faceindex1 = 0;
	facecount2 = 0;
	faceindex2 = 0;
	facecount3 = 0;
	faceindex3 = 0;
	facecount4 = 0;
	faceindex4 = 0;

	talkonce = false;
	flowerzzz = false;
	funonce = false;

	return S_OK;
}

void ending::update()
{
	FlowerFrame();
	TextControlUpdate();
	textrc = RectMake(_camera->getCam()->x + 170, _camera->getCam()->y + 20, 500, 150);
	if (textnum != 0)_player->getPlayer()->control = false;
	if (textnum == 0)_player->getPlayer()->control = true;
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		end = true;
		_player->getPlayer()->playertor = true;
		_player->getPlayer()->battleScene = true;
		_player->getPlayer()->changeScene = false;
	}
	if (end)
	{
		_player->getPlayer()->control = false;
		if(alpha < 250)
		alpha++;
		if (alpha >= 249)
		{
			over = true;
		}
	}
	if (_player->getPlayer()->killnum > 9)
	{
		if (_player->getPlayer()->y < 600 && !talkonce)
		{
			textnum = 1;
			talkonce = true;
		}
	}
	if (talkend && !flowerzzz)
	{
		flower_1->setFrameX(0);
		flower_2->setFrameX(0);
		flower_3->setFrameX(0);
		flower_4->setFrameX(0);
		flowerfun->setFrameX(0);
	}
	if (textnum == 0 && !flowerzzz)flowerfun->setFrameX(0);

	if (flowerzzz && !funonce)
	{
		if(!SOUNDMANAGER->isPlaySound("lastflowerfun"))
		{
			SOUNDMANAGER->play("lastflowerfun", 1.f);
			funonce = true;
		}
	}
	
}

void ending::render()
{
	IMAGEMANAGER->findImage("lastending")->render(getMemDC());
	if (end)
	{
		IMAGEMANAGER->findImage("light")->alphaRender(getMemDC(),alpha);
	}
	if (over)
	{
		IMAGEMANAGER->findImage("logo")->render(getMemDC(),_camera->getCam()->x,_camera->getCam()->y);
	}
	if (funonce && !allover)
	{
		IMAGEMANAGER->findImage("flowerhide")->frameRender(getMemDC(), 300, 470);
	}
	if (_player->getPlayer()->killnum > 9 && (SOUNDMANAGER->isPlaySound("lastflowerfun") || !funonce))
	{
		IMAGEMANAGER->findImage("flowerfun")->frameRender(getMemDC(), 300, 470);
	}
	
	if (textnum != 0)
	{


		IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
		if (textnum < 4)
		{
			
			IMAGEMANAGER->findImage("flower_1")->frameRender(getMemDC(), _camera->getCam()->x + 52, _camera->getCam()->y + 34);
		}
		if (textnum == 4 || textnum == 5)
		{
			IMAGEMANAGER->findImage("flower_2")->frameRender(getMemDC(), _camera->getCam()->x + 52, _camera->getCam()->y + 34);
		}
		if (textnum == 6 || textnum == 7 || textnum == 8)
		{
			IMAGEMANAGER->findImage("flower_3")->frameRender(getMemDC(), _camera->getCam()->x + 52, _camera->getCam()->y + 34);
		}
		if (textnum == 9 || textnum == 10)
		{
			IMAGEMANAGER->findImage("flower_4")->frameRender(getMemDC(), _camera->getCam()->x + 52, _camera->getCam()->y + 34);
		}


	}
	TextControl();
	
	
}

void ending::TextControlUpdate()
{
	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 11)
			{
				talkend = false;
				tindex++;
			}
		}
		if (textnum == 2)
		{
			if (tindex < 30)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 3)
		{
			if (tindex < 52)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 4)
		{
			if (tindex < 20)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 5)
		{
			if (tindex < 55)
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
			if (tindex < 50)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 8)
		{
			if (tindex < 51)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 9)
		{
			if (tindex < 56)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 10)
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
		if (tindex == 11)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 11;
		}
	}
	if (textnum == 2)
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
	if (textnum == 3)
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
	if (textnum == 4)
	{

		if (tindex == 20)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 20;
		}
	}
	if (textnum == 5)
	{
		if (tindex == 55)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 55;
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
		if (tindex == 50)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 50;
		}
	}
	if (textnum == 8)
	{
		if (tindex == 51)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 51;
		}
	}
	if (textnum == 9)
	{
		if (tindex == 56)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 56;
		}
	}
	if (textnum == 10)
	{
		if (tindex == 33)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
				flowerzzz = true;

			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 33;
		}
	}
}

void ending::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/last/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/last/text2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("text/last/text3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 4)
		hInputFile = CreateFile(_T("text/last/text4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 5)
		hInputFile = CreateFile(_T("text/last/text5.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 6)
		hInputFile = CreateFile(_T("text/last/text6.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 7)
		hInputFile = CreateFile(_T("text/last/text7.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 8)
		hInputFile = CreateFile(_T("text/last/text8.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 9)
		hInputFile = CreateFile(_T("text/last/text9.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 10)
		hInputFile = CreateFile(_T("text/last/text10.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

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

void ending::FlowerFrame()
{
	flowerfun->setFrameX(index);
	count++;

	if (index > flowerfun->getMaxFrameX())
	{
		index = 0;
	}
	else if (count % 10 == 0)index++;

	if (funonce && !SOUNDMANAGER->isPlaySound("lastflowerfun"))
	{
		flowerhide->setFrameX(index2);
		count2++;

		if (index2 > flowerhide->getMaxFrameX())
		{
			allover = true;
		}
		else if (count2 % 10 == 0)index2++;
	}

	flower_1->setFrameX(faceindex1);
	facecount1++;

	if (faceindex1 > flower_1->getMaxFrameX())
	{
		faceindex1 = 0;
	}
	else if (facecount1 % 10 == 0)faceindex1++;

	flower_2->setFrameX(faceindex2);
	facecount2++;

	if (faceindex2 > flower_2->getMaxFrameX())
	{
		faceindex2 = 0;
	}
	else if (facecount2 % 10 == 0)faceindex2++;

	flower_3->setFrameX(faceindex3);
	facecount3++;

	if (faceindex3 > flower_3->getMaxFrameX())
	{
		faceindex3 = 0;
	}
	else if (facecount3 % 10 == 0)faceindex3++;

	flower_4->setFrameX(faceindex4);
	facecount4++;

	if (faceindex4 > flower_4->getMaxFrameX())
	{
		faceindex4 = 0;
	}
	else if (facecount4 % 10 == 0)faceindex4++;
}

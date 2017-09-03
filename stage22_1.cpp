#include "stdafx.h"
#include "stage22_1.h"
#include "player.h"
#include "camera.h"

stage22_1::stage22_1()
{
}


stage22_1::~stage22_1()
{
}

HRESULT stage22_1::init()
{
	_player->getPlayer()->SaveStageNum = 1;
	IMAGEMANAGER->addImage("stage22_1", "image/undertale/stage/stage22_1.bmp", 640, 480, false, false);
	frognpc = IMAGEMANAGER->addFrameImage("frognpc", "image/undertale/npc/frognpc.bmp", 152, 40, 4, 1, true, RGB(255, 0, 255));

	nextdoor = RectMake(290, 100, 50, 50);
	backdoor = RectMake(-20, 280, 50, 50);

	if (_player->getPlayer()->isstage22_2)
	{
		_player->getPlayer()->x = 290;
		_player->getPlayer()->y = 150;
	}
	else
	{
		_player->getPlayer()->x = 30;
		_player->getPlayer()->y = 230;
	}
	
	_camera->getCam()->x = 0;
	_camera->getCam()->y = 0;
	_camera->getCam()->overviewX = true;
	_camera->getCam()->overviewY = true;

	_player->getPlayer()->isstage22_1 = true;

	frogrc = RectMake(160, 160, 50, 50);

	count = 0;
	index = 0;

	return S_OK;
}

void stage22_1::release()
{
}

void stage22_1::update()
{
	textrc = RectMake(_camera->getCam()->x + 80, _camera->getCam()->y + 20, 500, 150);
	if (textnum != 0)_player->getPlayer()->control = false;
	if (textnum == 0)_player->getPlayer()->control = true;
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("stage22_2");
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &backdoor))
	{
		SCENEMANAGER->changeScene("stage22");
	}
	if (_player->getPlayer()->killnum < 10)
	{
		if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &frogrc))
		{
			if (_player->getPlayer()->pressZ)
			{
				textnum = 1;
			}
		}
	}
	frogFrame();
	TextControlUpdate();
}

void stage22_1::render()
{
	IMAGEMANAGER->findImage("stage22_1")->render(getMemDC());
	if(_player->getPlayer()->killnum < 10)
	IMAGEMANAGER->findImage("frognpc")->frameRender(getMemDC(), 160, 160);
	if (textnum != 0)IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
	TextControl();
	if (_player->getPlayer()->viewEvery)
	{
		Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
		Rectangle(getMemDC(), backdoor.left, backdoor.top, backdoor.right, backdoor.bottom);
		Rectangle(getMemDC(), frogrc.left, frogrc.top, frogrc.right, frogrc.bottom);
	}
	else
	{

	}
}
void stage22_1::frogFrame()
{
	frognpc->setFrameX(index);
	count++;

	if (index > frognpc->getMaxFrameX())
	{
		index = 0;
	}
	else if (count % 20 == 0)index++;
}

void stage22_1::TextControlUpdate()
{
	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 46)
				tindex++;
		}
		if (textnum == 2)
		{
			if (tindex < 59)
				tindex++;
		}
		if (textnum == 3)
		{
			if (tindex < 28)
				tindex++;
		}
		if (textnum == 4)
		{
			if (tindex < 41)
				tindex++;
		}
		if (textnum == 5)
		{
			if (tindex < 44)
				tindex++;
		}


	}

	if (textnum == 1)
	{
		if (tindex == 46)
		{
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
	if (textnum == 2)
	{
		if (tindex == 59)
		{
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
	if (textnum == 3)
	{
		if (tindex == 28)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 28;
		}
	}
	if (textnum == 4)
	{
		if (tindex == 41)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 41;
		}
	}
	if (textnum == 5)
	{
		if (tindex == 44)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 44;
		}
	}
	
}

void stage22_1::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/stage22_1/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/stage22_1/text2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("text/stage22_1/text3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 4)
		hInputFile = CreateFile(_T("text/stage22_1/text4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 5)
		hInputFile = CreateFile(_T("text/stage22_1/text5.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

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

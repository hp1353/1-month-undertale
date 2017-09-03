#include "stdafx.h"
#include "kitchen.h"
#include "player.h"
#include "camera.h"

kitchen::kitchen()
{
}


kitchen::~kitchen()
{
}

HRESULT kitchen::init()
{
	_player->getPlayer()->SaveStageNum = 1;
	IMAGEMANAGER->addImage("kitchen", "image/undertale/stage/kitchen.bmp", 640, 480, false, false);

	_player->getPlayer()->x = 100;
	_player->getPlayer()->y = 420;
	_camera->getCam()->overviewX = true;
	_camera->getCam()->overviewY = true;
	backdoor = RectMake(120, 480, 50, 50);
	t1 = RectMake(50, 260, 50, 50);
	t2 = RectMake(120, 260, 50, 50);
	t3 = RectMake(190, 260, 40, 50);
	t4 = RectMake(250, 260, 40, 50);
	t5 = RectMake(300, 260, 40, 50);
	_player->getPlayer()->isbeforekitchen = true;
	return S_OK;
}

void kitchen::release()
{
}

void kitchen::update()
{
	textrc = RectMake(_camera->getCam()->x + 80, _camera->getCam()->y + 20, 500, 150);
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &backdoor))
	{
		SCENEMANAGER->changeScene("leftroom");
	}
	if (textnum != 0)_player->getPlayer()->control = false;
	if (textnum == 0)_player->getPlayer()->control = true;
	TextControlUpdate();

	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &t1))
	{
		if(_player->getPlayer()->pressZ)
		textnum = 1;
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &t2))
	{
		if (_player->getPlayer()->pressZ)
			textnum = 2;
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &t3))
	{
		if (_player->getPlayer()->pressZ)
		{
			if (_player->getPlayer()->killnum < 10)
				textnum = 3;
			else
				textnum = 6;
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &t4))
	{
		if (_player->getPlayer()->pressZ)
			textnum = 4;
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &t5))
	{
		if (_player->getPlayer()->pressZ)
			textnum = 5;
	}
	if (textnum != 0) _player->getPlayer()->control = false;
	if (textnum == 0) _player->getPlayer()->control = true;
}

void kitchen::render()
{
	IMAGEMANAGER->findImage("kitchen")->render(getMemDC());
	if (textnum != 0)IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
	TextControl();
	TextControl2();
	if (_player->getPlayer()->viewEvery)
	{
		
		Rectangle(getMemDC(), backdoor.left, backdoor.top, backdoor.right, backdoor.bottom);
		Rectangle(getMemDC(), t1.left, t1.top, t1.right, t1.bottom);
		Rectangle(getMemDC(), t2.left, t2.top, t2.right, t2.bottom);
		Rectangle(getMemDC(), t3.left, t3.top, t3.right, t3.bottom);
		Rectangle(getMemDC(), t4.left, t4.top, t4.right, t4.bottom);
		Rectangle(getMemDC(), t5.left, t5.top, t5.right, t5.bottom);
	}
	else
	{

	}
}

void kitchen::TextControlUpdate()
{
	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 67)
			{
				talkend = false;
				tindex++;
			}
		}
		if (textnum == 2)
		{
			if (tindex < 32)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 3)
		{
			if (tindex < 48)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 4)
		{
			if (tindex < 53)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 5)
		{
			if (tindex < 73)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 6)
		{
			if (tindex < 22)
			{
				tindex++;
				talkend = false;
			}
		}
		



	}

	if (textnum == 1)
	{
		if (tindex == 67)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 67;
		}
	}
	if (textnum == 2)
	{
		if (tindex == 32)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 32;
		}
	}
	if (textnum == 3)
	{
		if (tindex == 48)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 48;
		}
	}
	if (textnum == 4)
	{

		if (tindex == 53)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 53;
		}
	}
	if (textnum == 5)
	{
		if (tindex == 73)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 73;
		}
	}
	if (textnum == 6)
	{
		if (tindex == 22)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 22;
		}
	}
	
}

void kitchen::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/kitchen/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/kitchen/text2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("text/kitchen/text3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 4)
		hInputFile = CreateFile(_T("text/kitchen/text4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 5)
		hInputFile = CreateFile(_T("text/kitchen/text5.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	
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

void kitchen::TextControl2()
{

	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 0, 0));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 6)
		hInputFile = CreateFile(_T("text/kitchen/text6.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	
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

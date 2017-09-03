#include "stdafx.h"
#include "stage18.h"
#include "player.h"
#include "camera.h"

stage18::stage18()
{
}


stage18::~stage18()
{
}

HRESULT stage18::init()
{
	_player->getPlayer()->loadstagenum = 18;
	_player->getPlayer()->dontpix = false;
	if (SOUNDMANAGER->isPlaySound("battlesound"))
	{
		SOUNDMANAGER->stop("battlesound");
	}
	if (_player->getPlayer()->killnum < 10)
	{
		if (!SOUNDMANAGER->isPlaySound("stagesound"))
		{
			SOUNDMANAGER->play("stagesound", 1.f);
		}
		if (SOUNDMANAGER->isPauseSound("stagesound"))
		{
			SOUNDMANAGER->resume("stagesound");
		}
	}
	_player->getPlayer()->SaveStageNum = 18;
	IMAGEMANAGER->addImage("stage18", "image/undertale/stage/stage18.bmp", 797, 859, false, false);
	nextdoor = RectMake(490, 840, 50, 50);
	
	if (_player->getPlayer()->istraproom && !_player->getPlayer()->battleend)
	{
		_player->getPlayer()->x = 300;
		_player->getPlayer()->y = 330;
		_camera->getCam()->x = 0;
		_camera->getCam()->y = 120;
	}
	if (!_player->getPlayer()->istraproom && !_player->getPlayer()->battleend)
	{
		_player->getPlayer()->x = 10;
		_player->getPlayer()->y = 330;
		_camera->getCam()->x = 0;
		_camera->getCam()->y = 0;
	}
	if (_player->getPlayer()->battleend)
	{
		_player->getPlayer()->x = _player->getPlayer()->SaveX;
		_player->getPlayer()->y = _player->getPlayer()->SaveY;
		//_player->getPlayer()->changeScene = true;
		_player->getPlayer()->playertor = false;
		_player->getPlayer()->battleScene = false;
		_player->getPlayer()->battleend = false;
		_player->getPlayer()->walkcount = 0;
		_player->getPlayer()->control = true;
		_player->getPlayer()->dontpix = false;
		_camera->getCam()->x = _player->getPlayer()->savecamx;
		_camera->getCam()->y = _player->getPlayer()->savecamy;
		_camera->getCam()->cameramove = true;
	}
	
	_camera->getCam()->overviewX = true;
	_camera->getCam()->overviewY = true;

	blue = RectMake(150, 430, 50, 70);
	yellow = RectMake(480, 320, 70, 50);
	red = RectMake(590, 620, 50, 80);
	text = RectMake(150, 180, 70, 40);

	heartcontrol = 150;

	tindex = 0;
	tcount = 0;
	textnum = 0;

	return S_OK;
}

void stage18::release()
{
}

void stage18::update()
{
	textrc = RectMake(_camera->getCam()->x + 80, _camera->getCam()->y + 20, 500, 150);
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("stage19");
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &blue))
	{
		if (_player->getPlayer()->pressZ)
		{
			textnum = 2;
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &red))
	{
		if (_player->getPlayer()->pressZ)
		{
			textnum = 2;
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &yellow))
	{
		if (_player->getPlayer()->pressZ)
		{
			textnum = 2;
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &text))
	{
		if (_player->getPlayer()->pressZ)
		{
			textnum = 1;
		}
	}
	TextControlUpdate();
	if (textnum != 0)_player->getPlayer()->control = false;
	if (textnum == 0)_player->getPlayer()->control = true;

	
}

void stage18::render()
{
	IMAGEMANAGER->findImage("stage18")->render(getMemDC());
	if(textnum != 0)IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
	TextControl();
	if (textnum == 2 && tindex > 60)
	{
		IMAGEMANAGER->findImage("heart")->render(getMemDC(), _camera->getCam()->x + heartcontrol, _camera->getCam()->y + 110);

		if (KEYMANAGER->isOnceDown(VK_LEFT))
		{
			heartcontrol = 150;
		}
		if (KEYMANAGER->isOnceDown(VK_RIGHT))
		{
			heartcontrol = 280;
		}
	}

	if (_player->getPlayer()->viewEvery)
	{
		Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
		Rectangle(getMemDC(), blue.left, blue.top, blue.right, blue.bottom);
		Rectangle(getMemDC(), yellow.left, yellow.top, yellow.right, yellow.bottom);
		Rectangle(getMemDC(), red.left, red.top, red.right, red.bottom);
		Rectangle(getMemDC(), text.left, text.top, text.right, text.bottom);
	}
	else
	{

	}
}

void stage18::TextControlUpdate()
{
	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 62)
				tindex++;
		}
		if (textnum == 2)
		{
			if (tindex < 68)
				tindex++;
		}
		if (textnum == 3)
		{
			if (tindex < 31)
				tindex++;
		}



	}

	if (textnum == 1)
	{
		if (tindex == 62)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 62;
		}
	}
	if (textnum == 2)
	{
		if (textnum == 2 && tindex > 60)
		{
			if (heartcontrol == 150)
			{
				if (_player->getPlayer()->pressZ)
				{
					tindex = 0;
					textnum = 3;
				}
			}
			if (heartcontrol == 280)
			{
				if (_player->getPlayer()->pressZ)
				{
					tindex = 0;
					textnum = 0;
				}
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 68;
		}
	}
	if (textnum == 3)
	{
		if (tindex == 31)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 31;
		}
	}
}

void stage18::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/stage18/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/stage18/text2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("text/stage18/text3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

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

#include "stdafx.h"
#include "stage16.h"
#include "player.h"
#include "camera.h"

stage16::stage16()
{
}


stage16::~stage16()
{
}

HRESULT stage16::init()
{
	_player->getPlayer()->stage15skip = true;
	_player->getPlayer()->loadstagenum = 16;
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
	_player->getPlayer()->SaveStageNum = 16;
	IMAGEMANAGER->addImage("stage16", "image/undertale/stage/stage16.bmp", 1521, 598, false, false);
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
	else
	{
		_player->getPlayer()->x = 310;
		_player->getPlayer()->y = 540;
		_camera->getCam()->overviewX = true;
		_camera->getCam()->overviewY = true;

		_camera->getCam()->x = 0;
		_camera->getCam()->y = 120;
		_player->getPlayer()->playertor = false;
		_player->getPlayer()->battleScene = false;
		_player->getPlayer()->battleend = false;
		_player->getPlayer()->walkcount = 0;
		_player->getPlayer()->control = true;
		_player->getPlayer()->dontpix = false;
		_player->getPlayer()->changeindex = 0;
		_player->getPlayer()->SaveStageNum = 16;
		_player->getPlayer()->changeScene = false;
		_player->getPlayer()->changebattle = false;
		_player->getPlayer()->dontpix = false;
	}
	
	nextdoor = RectMake(1500, 320, 50, 50);
	text = RectMake(320, 270, 50, 50);
	text2 = RectMake(680, 270, 50, 50);
	tcount = 0;
	tindex = 0;
	textnum = 0;
	count = 0;
	index = 0;
	frognpc = IMAGEMANAGER->addFrameImage("frognpc", "image/undertale/npc/frognpc.bmp", 152, 40, 4, 1, true, RGB(255, 0, 255));
	



	return S_OK;
}

void stage16::release()
{
}

void stage16::update()
{
	frogFrame();
	textrc = RectMake(_camera->getCam()->x + 80, _camera->getCam()->y + 20, 500, 150);
	TextControlUpdate();
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("stage17");
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &text))
	{
		if (KEYMANAGER->isOnceDown('Z') && textnum == 0)
		{
			textnum = 1;
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &text2) && (_player->getPlayer()->killnum < 10))
	{
		if (KEYMANAGER->isOnceDown('Z') && textnum == 0)
		{
			textnum = 3;
		}
	}
	if (textnum != 0)_player->getPlayer()->control = false;
	if (textnum == 0)_player->getPlayer()->control = true;
}

void stage16::render()
{
	IMAGEMANAGER->findImage("stage16")->render(getMemDC());
	if (_player->getPlayer()->killnum < 10)
	IMAGEMANAGER->findImage("frognpc")->frameRender(getMemDC(), 680, 270);
	if(textnum != 0) IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
	TextControl();
	if (_player->getPlayer()->viewEvery)
	{
		Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
		Rectangle(getMemDC(), text.left, text.top, text.right, text.bottom);
		Rectangle(getMemDC(), text2.left, text2.top, text2.right, text2.bottom);
	}
	else
	{

	}
	
}

void stage16::TextControlUpdate()
{
	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 68)
				tindex++;
		}
		if (textnum == 2)
		{
			if (tindex < 60)
				tindex++;
		}
		if (textnum == 3)
		{
			if (tindex < 45)
				tindex++;
		}


	}

	if (textnum == 1)
	{
		if (tindex == 68)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 68;
		}
	}
	if (textnum == 2)
	{
		if (tindex == 60)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 60;
		}
	}
	if (textnum == 3)
	{
		if (tindex == 45)
		{
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
}

void stage16::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/stage16/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/stage16/text2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("text/stage16/text3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

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
void stage16::frogFrame()
{
	frognpc->setFrameX(index);
	count++;

	if (index > frognpc->getMaxFrameX())
	{
		index = 0;
	}
	else if (count % 20 == 0)index++;
}


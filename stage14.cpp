#include "stdafx.h"
#include "stage14.h"
#include "player.h"
#include "camera.h"

stage14::stage14()
{
}


stage14::~stage14()
{
}

HRESULT stage14::init()
{
	_player->getPlayer()->loadstagenum = 14;
	_player->getPlayer()->dontpix = false;
	_player->getPlayer()->battleScene = false;
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
	_player->getPlayer()->SaveStageNum = 14;
	IMAGEMANAGER->addImage("stage14", "image/undertale/stage/stage14.bmp", 640, 480, false, false);
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
		_player->getPlayer()->x = 10;
		_player->getPlayer()->y = 230;
		_camera->getCam()->x = 0;
		_camera->getCam()->y = 0;
		_camera->getCam()->overviewX = true;
		_camera->getCam()->overviewY = true;
	}

	_player->getPlayer()->dontpix = false;
	count1 = 0;
	index1 = 0;
	savestar = IMAGEMANAGER->addFrameImage("savestar", "image/undertale/object/savestar.bmp", 78, 37, 2, 1, true, RGB(255, 0, 255));
	starrc = RectMake(220, 310, 50, 50);
	cheeze = RectMake(350, 310, 80, 50);
	mouse = RectMake(220, 205, 20, 20);
	nextdoor = RectMake(620, 230, 50, 50);
	
	return S_OK;
}

void stage14::release()
{
}

void stage14::update()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성

	starFrame();
	TextControlUpdate();
	textrc = RectMake(_camera->getCam()->x + 80, _camera->getCam()->y + 20, 500, 150);
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("stage15");
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &mouse))
	{
		if (KEYMANAGER->isOnceDown('Z'))
		{
			SOUNDMANAGER->play("mouse", 1.f);
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &starrc))
	{
		if (KEYMANAGER->isOnceDown('Z'))
		{
			SOUNDMANAGER->play("heal", 1.f);
			textnum = 1;
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &cheeze))
	{
		if (KEYMANAGER->isOnceDown('Z'))
		{
			textnum = 3;
		}
	}
	if (textnum != 0)_player->getPlayer()->control = false;
	if (textnum == 0) _player->getPlayer()->control = true;
}

void stage14::render()
{
	IMAGEMANAGER->findImage("stage14")->render(getMemDC());
	IMAGEMANAGER->findImage("savestar")->frameRender(getMemDC(), 220, 320);
	if(textnum != 0) IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
	TextControl();
	if (_player->getPlayer()->viewEvery)
	{
		Rectangle(getMemDC(), mouse.left, mouse.top, mouse.right, mouse.bottom);
		Rectangle(getMemDC(), cheeze.left, cheeze.top, cheeze.right, cheeze.bottom);
		Rectangle(getMemDC(), starrc.left, starrc.top, starrc.right, starrc.bottom);
		Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
	}
	else
	{

	}
}
void stage14::starFrame()
{
	savestar->setFrameX(index1);
	count1++;

	if (index1 > savestar->getMaxFrameX())
	{
		index1 = 0;
	}
	else if (count1 % 10 == 0)index1++;
}

void stage14::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																										  //폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/stage14/stage14_1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/stage14/stage14_2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("text/stage14/stage14_3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 4)
		hInputFile = CreateFile(_T("text/stage14/stage14_4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	
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

void stage14::TextControlUpdate()
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
			if (tindex < 29)
				tindex++;
		}
		if (textnum == 3)
		{
			if (tindex < 51)
				tindex++;
		}
		if (textnum == 4)
		{
			if (tindex < 29)
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
		if (tindex == 29)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 29;
		}
	}
	if (textnum == 3)
	{
		if (tindex == 51)
		{
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
	if (textnum == 4)
	{
		if (tindex == 29)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 29;
		}
	}
	

}

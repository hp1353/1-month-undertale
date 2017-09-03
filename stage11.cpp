#include "stdafx.h"
#include "stage11.h"
#include "player.h"
#include "camera.h"

stage11::stage11()
{
}


stage11::~stage11()
{
}

HRESULT stage11::init()
{
	_player->getPlayer()->loadstagenum = 11;
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
	_player->getPlayer()->SaveStageNum = 11;
	IMAGEMANAGER->addImage("stage11", "image/undertale/stage/stage11.bmp", 959, 481, false, false);
	stone = IMAGEMANAGER->addImage("stone", "image/undertale/object/stone.bmp", 40, 36, true, RGB(255, 0, 255));
	stage11_trap = IMAGEMANAGER->addFrameImage("stage11_trap", "image/undertale/object/stage11_trap.bmp", 80, 240, 2, 1, false, false);
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
		_player->getPlayer()->y = 240;
		_camera->getCam()->x = 0;
		_camera->getCam()->y = 0;
		_camera->getCam()->overviewX = true;
		_camera->getCam()->overviewY = true;
	}
	if (_player->getPlayer()->stage11clear)
	{

	}
	else
	{
		stage11_trap->setFrameX(1);
		trapmark = RectMake(600, 160, 40, 240);
		isloadmark = true;
		stone->setX(360);
		stone->setY(280);
		stonerock = false;
		nextdoor = RectMake(950, 210, 50, 50);
		tcount = 0;
		tindex = 0;
		textnum = 0;
		t1 = RectMake(320, 100, 50, 50);
	}
	return S_OK;
}

void stage11::release()
{
}

void stage11::update()
{
	if (textnum != 0) _player->getPlayer()->control = false;
	if (textnum == 0) _player->getPlayer()->control = true;
	TextControlUpdate();
	textrc = RectMake(_camera->getCam()->x + 80, _camera->getCam()->y + 20, 500, 150);
	stonerc = RectMake(stone->getX(), stone->getY(), stone->getWidth(), stone->getHeight());
	if (isloadmark)
	{
		if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &trapmark))
		{
			_player->getPlayer()->x -= 2;
		}
	}
	else
	{

	}
	if (!stonerock)
	{
		if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &stonerc))
		{
			if (_player->getPlayer()->rc.right > stonerc.left) stone->setX(stone->getX() + 2);
			if (stone->getX() > 480) stonerock = true;
		}
	}
	if (stonerock)
	{
		isloadmark = false;
		stage11_trap->setFrameX(0);
		_player->getPlayer()->stage11clear = true;
		if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
		{
			SCENEMANAGER->changeScene("stage12");
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &t1))
	{
		if (_player->getPlayer()->pressZ)
		{
			textnum = 1;
		}
	}
}

void stage11::render()
{
	IMAGEMANAGER->findImage("stage11")->render(getMemDC());
	IMAGEMANAGER->findImage("stone")->render(getMemDC(), stone->getX(), stone->getY());
	IMAGEMANAGER->findImage("stage11_trap")->frameRender(getMemDC(), 600, 160);
	if (textnum != 0) IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);

	TextControl();
	if (_player->getPlayer()->viewEvery)
	{
		Rectangle(getMemDC(), trapmark.left, trapmark.top, trapmark.right, trapmark.bottom);
		Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
		Rectangle(getMemDC(), t1.left, t1.top, t1.right, t1.bottom);
	}
	else
	{

	}
}

void stage11::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/stage11/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	
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

void stage11::TextControlUpdate()
{
	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 59)
				tindex++;
		}
		


	}

	if (textnum == 1)
	{
		if (tindex == 59)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 59;
		}
	}
	
}

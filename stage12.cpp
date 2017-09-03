#include "stdafx.h"
#include "stage12.h"
#include "player.h"
#include "camera.h"

stage12::stage12()
{
}


stage12::~stage12()
{
}

HRESULT stage12::init()
{
	_player->getPlayer()->loadstagenum = 12;
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
	_player->getPlayer()->SaveStageNum = 12;
	IMAGEMANAGER->addImage("stage12", "image/undertale/stage/stage12.bmp", 1164, 1592, false, false);
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
	
	droprc1 = RectMake(485, 277, 180, 325);
	droprc2 = RectMake(725, 357, 30, 170);
	droprc3 = RectMake(840, 465, 30, 140);
	droprc4 = RectMake(970, 360, 60, 160);
	uprc = RectMake(300, 1050, 50, 50);
	nextdoor = RectMake(1130, 450, 50, 50);
	uptext = RectMake(920, 290, 50, 50);
	downtext = RectMake(920, 1230, 50, 50);
	drop = false;
	makehole = false;
	howmanydrop = 0;
	dropcount = 0;
	saveholex = 0;
	saveholey = 0;
	saveholex1 = 0;
	saveholey1 = 0;
	saveholex2 = 0;
	saveholey2 = 0;
	saveholex3 = 0;
	saveholey3 = 0;
	saveholex4 = 0;
	saveholey4 = 0;
	saveholex5 = 0;
	saveholey5 = 0;
	saveholex6 = 0;
	saveholey6 = 0;
	saveholex7 = 0;
	saveholey7 = 0;
	saveholex8 = 0;
	saveholey8 = 0;
	saveholex9 = 0;
	saveholey9 = 0;

	tcount = 0;
	tindex = 0;
	textnum = 0;
	return S_OK;
}

void stage12::release()
{
}

void stage12::update()
{
	
	if (textnum != 0) _player->getPlayer()->control = false;
	if (textnum == 0 && !drop) _player->getPlayer()->control = true;
	TextControlUpdate();
	textrc = RectMake(_camera->getCam()->x + 80, _camera->getCam()->y + 20, 500, 150);
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &droprc1))
	{
		beforedrop();
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &droprc2))
	{
		beforedrop();
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &droprc3))
	{
		beforedrop();
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &droprc4))
	{
		beforedrop();
	}
	afterdrop();

	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &uprc))
	{
		_player->getPlayer()->y = 240;
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("stage13");
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &uptext))
	{
		if (KEYMANAGER->isOnceDown('Z'))
		{
			textnum = 1;
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &downtext))
	{
		if (KEYMANAGER->isOnceDown('Z'))
		{
			textnum = 2;
		}
	}
}

void stage12::render()
{
	IMAGEMANAGER->findImage("stage12")->render(getMemDC());

	if (makehole)
	{
		IMAGEMANAGER->findImage("hole")->render(getMemDC(), saveholex, saveholey);
		IMAGEMANAGER->findImage("hole")->render(getMemDC(), saveholex1, saveholey1);
		IMAGEMANAGER->findImage("hole")->render(getMemDC(), saveholex2, saveholey2);
		IMAGEMANAGER->findImage("hole")->render(getMemDC(), saveholex3, saveholey3);
		IMAGEMANAGER->findImage("hole")->render(getMemDC(), saveholex4, saveholey4);
		IMAGEMANAGER->findImage("hole")->render(getMemDC(), saveholex5, saveholey5);
		IMAGEMANAGER->findImage("hole")->render(getMemDC(), saveholex6, saveholey6);
		IMAGEMANAGER->findImage("hole")->render(getMemDC(), saveholex7, saveholey7);
		IMAGEMANAGER->findImage("hole")->render(getMemDC(), saveholex8, saveholey8);
		IMAGEMANAGER->findImage("hole")->render(getMemDC(), saveholex9, saveholey9);
	}
	if(textnum != 0) IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);

	TextControl();
	if (_player->getPlayer()->viewEvery)
	{
		Rectangle(getMemDC(), droprc1.left, droprc1.top, droprc1.right, droprc1.bottom);
		Rectangle(getMemDC(), droprc2.left, droprc2.top, droprc2.right, droprc2.bottom);
		Rectangle(getMemDC(), droprc3.left, droprc3.top, droprc3.right, droprc3.bottom);
		Rectangle(getMemDC(), droprc4.left, droprc4.top, droprc4.right, droprc4.bottom);
		Rectangle(getMemDC(), uprc.left, uprc.top, uprc.right, uprc.bottom);
		Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
		Rectangle(getMemDC(), uptext.left, uptext.top, uptext.right, uptext.bottom);
		Rectangle(getMemDC(), downtext.left, downtext.top, downtext.right, downtext.bottom);
	}
	else
	{

	}
}

void stage12::beforedrop()
{
	
	_player->getPlayer()->dontpix = true;
	makehole = true;
	drop = true;
	_player->getPlayer()->control = false;
	if (saveholex == 0 && saveholey == 0)
	{
		saveholex = _player->getPlayer()->bottomrc.left;
		saveholey = _player->getPlayer()->bottomrc.top;
		SOUNDMANAGER->play("trapdown2", 1.f);
	}
	if (howmanydrop == 1 && saveholex1 == 0 && saveholey1 == 0)
	{
		saveholex1 = _player->getPlayer()->bottomrc.left;
		saveholey1 = _player->getPlayer()->bottomrc.top;
		SOUNDMANAGER->play("trapdown2", 1.f);
	}
	if (howmanydrop == 2 && saveholex2 == 0 && saveholey2 == 0)
	{
		saveholex2 = _player->getPlayer()->bottomrc.left;
		saveholey2 = _player->getPlayer()->bottomrc.top;
		SOUNDMANAGER->play("trapdown2", 1.f);
	}
	if (howmanydrop == 3 && saveholex3 == 0 && saveholey3 == 0)
	{
		saveholex3 = _player->getPlayer()->bottomrc.left;
		saveholey3 = _player->getPlayer()->bottomrc.top;
		SOUNDMANAGER->play("trapdown2", 1.f);
	}
	if (howmanydrop == 4 && saveholex4 == 0 && saveholey4 == 0)
	{
		saveholex4 = _player->getPlayer()->bottomrc.left;
		saveholey4 = _player->getPlayer()->bottomrc.top;
		SOUNDMANAGER->play("trapdown2", 1.f);
	}
	if (howmanydrop == 5 && saveholex5 == 0 && saveholey5 == 0)
	{
		saveholex5 = _player->getPlayer()->bottomrc.left;
		saveholey5 = _player->getPlayer()->bottomrc.top;
		SOUNDMANAGER->play("trapdown2", 1.f);
	}
	if (howmanydrop == 6 && saveholex6 == 0 && saveholey6 == 0)
	{
		saveholex6 = _player->getPlayer()->bottomrc.left;
		saveholey6 = _player->getPlayer()->bottomrc.top;
		SOUNDMANAGER->play("trapdown2", 1.f);
	}
	if (howmanydrop == 7 && saveholex7 == 0 && saveholey7 == 0)
	{
		saveholex7 = _player->getPlayer()->bottomrc.left;
		saveholey7 = _player->getPlayer()->bottomrc.top;
		SOUNDMANAGER->play("trapdown2", 1.f);
	}
	if (howmanydrop == 8 && saveholex8 == 0 && saveholey8 == 0)
	{
		saveholex8 = _player->getPlayer()->bottomrc.left;
		saveholey8 = _player->getPlayer()->bottomrc.top;
		SOUNDMANAGER->play("trapdown2", 1.f);
	}
	if (howmanydrop == 9 && saveholex9 == 0 && saveholey9 == 0)
	{
		saveholex9 = _player->getPlayer()->bottomrc.left;
		saveholey9 = _player->getPlayer()->bottomrc.top;
		SOUNDMANAGER->play("trapdown2", 1.f);
	}
}

void stage12::afterdrop()
{
	if (drop)
	{
		dropcount++;
		if (dropcount > 100 && _player->getPlayer()->y < 1300)
		{
			_player->getPlayer()->turn = true;
			_player->getPlayer()->y += 4;
		}
		if (_player->getPlayer()->y >= 1300)
		{
			_player->getPlayer()->turn = false;
			drop = false;
			_player->getPlayer()->control = true;
			_player->getPlayer()->dontpix = false;
			dropcount = 0;
			howmanydrop += 1;
		}


	}
}

void stage12::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																										  //폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/stage12/stage12_1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/stage12/stage12_2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	
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

void stage12::TextControlUpdate()
{
	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 40)
				tindex++;
		}
		if (textnum == 2)
		{
			if (tindex < 21)
				tindex++;
		}
		
	}

	if (textnum == 1)
	{
		if (tindex == 40)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 40;
		}
	}
	if (textnum == 2)
	{
		if (tindex == 21)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 21;
		}
	}
	
}

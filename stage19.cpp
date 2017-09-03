#include "stdafx.h"
#include "stage19.h"
#include "player.h"
#include "camera.h"

stage19::stage19()
{
}


stage19::~stage19()
{
}

HRESULT stage19::init()
{
	_player->getPlayer()->loadstagenum = 19;
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
	_player->getPlayer()->SaveStageNum = 19;
	IMAGEMANAGER->addImage("stage19", "image/undertale/stage/stage19.bmp", 800, 851, false, false);
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
		_player->getPlayer()->x = 500;
		_player->getPlayer()->y = 220;
		_camera->getCam()->x = 162;
		_camera->getCam()->y = 10;
		_camera->getCam()->overviewX = true;
		_camera->getCam()->overviewY = true;
	}
	
	if (_player->getPlayer()->stage19clear)
	{

	}
	else
	{
		nextdoor = RectMake(0, 640, 50, 50);

		blue = RectMake(390, 250, 100, 70);
		yellow = RectMake(530, 570, 70, 50);
		red = RectMake(200, 720, 80, 50);
		text = RectMake(170, 440, 70, 40);
		dooropen = false;
		heartcontrol = 150;

		tindex = 0;
		tcount = 0;
		textnum = 0;

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
		IMAGEMANAGER->addImage("trapover2", "image/undertale/object/trapover.bmp", 40, 80, false, false);
		once = false;
	}
	return S_OK;
}

void stage19::release()
{
}

void stage19::update()
{
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("stage20");
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
			beforedrop();
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &yellow))
	{
		if (_player->getPlayer()->pressZ)
		{
			beforedrop();
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &text))
	{
		if (_player->getPlayer()->pressZ)
		{
			textnum = 1;
			
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &loadmark))
	{
		_player->getPlayer()->x += 2;
	}
	afterdrop();
	TextControlUpdate();
	if (textnum != 0)_player->getPlayer()->control = false;
	if (textnum == 0)_player->getPlayer()->control = true;
	if (drop)_player->getPlayer()->control = false;
	textrc = RectMake(_camera->getCam()->x + 80, _camera->getCam()->y + 20, 500, 150);
	if (textnum == 1)_player->getPlayer()->stage19nopillar = true;
	else _player->getPlayer()->stage19nopillar = false;

	if (!dooropen)loadmark = RectMake(80, 610, 40, 80);
	if (dooropen)loadmark = RectMake(0, 0, 0, 0);
}

void stage19::render()
{
	IMAGEMANAGER->findImage("stage19")->render(getMemDC());

	if (dooropen)
	{
		IMAGEMANAGER->findImage("trapover2")->render(getMemDC(), 80, 610);
	}

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

	if (textnum != 0)IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
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
		Rectangle(getMemDC(), loadmark.left, loadmark.top, loadmark.right, loadmark.bottom);
	}
	else
	{

	}
}

void stage19::TextControlUpdate()
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
			if (tindex < 68)
				tindex++;
		}
		if (textnum == 3)
		{
			if (tindex < 25)
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
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 46;
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
					dooropen = true;
					_player->getPlayer()->stage19clear = true;
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
		if (!SOUNDMANAGER->isPlaySound("trapdown") && !once)
		{
			SOUNDMANAGER->play("trapdown", 1.f);
			once = true;
		}
		if (tindex == 25)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
				
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 25;
		}
	}
}

void stage19::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/stage19/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/stage19/text2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("text/stage19/text3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

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

void stage19::beforedrop()
{
	_player->getPlayer()->control = false;
	_player->getPlayer()->dontpix = true;
	makehole = true;
	drop = true;

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

void stage19::afterdrop()
{
	if (drop)
	{
		dropcount++;
		if (dropcount > 100 && dropcount < 130)
		{
			_player->getPlayer()->turn = true;
			_player->getPlayer()->y += 4;
		}
		if (dropcount >= 130)
		{
			_player->getPlayer()->turn = false;
			drop = false;
			_player->getPlayer()->control = true;
			_player->getPlayer()->dontpix = false;
			dropcount = 0;
			howmanydrop += 1;
			SCENEMANAGER->changeScene("stage18_21_traproom");
		}


	}
}

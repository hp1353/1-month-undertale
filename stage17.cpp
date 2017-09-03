#include "stdafx.h"
#include "stage17.h"
#include "player.h"
#include "camera.h"

stage17::stage17()
{
}


stage17::~stage17()
{
}

HRESULT stage17::init()
{
	_player->getPlayer()->loadstagenum = 17;
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
	_player->getPlayer()->SaveStageNum = 17;
	IMAGEMANAGER->addImage("stage17", "image/undertale/stage/stage17.bmp", 1283, 1322, false, false);
	IMAGEMANAGER->addImage("switchover", "image/undertale/object/switchover.bmp", 14, 36, true, RGB(255,0,255));
	IMAGEMANAGER->addImage("trapover", "image/undertale/object/trapover.bmp", 40, 80, false, false);
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
	if (_player->getPlayer()->stage17clear)
	{

	}
	else
	{
		nextdoor = RectMake(1250, 330, 50, 50);
		//770,830
		switchrc = RectMake(775, 840, 10, 20);
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
		dooropen = false;
		for (int i = 0; i < 3; i++)
		{
			holerc1[i] = RectMake(520 + i * 240, 230, 50, 50);
		}
		for (int i = 0; i < 3; i++)
		{
			holerc2[i] = RectMake(520 + i * 240, 480, 50, 50);
		}
		updoor1 = RectMake(350, 820, 30, 50);
		updoor2 = RectMake(860, 820, 30, 50);
		updoor3 = RectMake(1120, 820, 30, 50);
		updoor4 = RectMake(350, 1050, 30, 50);
		updoor5 = RectMake(860, 1050, 30, 50);
		updoor6 = RectMake(1120, 1050, 30, 50);
		tcount = 0;
		tindex = 0;
		textnum = 0;
		text = RectMake(200, 130, 50, 50);
		once = false;
	}
	return S_OK;
}

void stage17::release()
{
}

void stage17::update()
{
	if (textnum != 0)_player->getPlayer()->control = false;
	if (textnum == 0)_player->getPlayer()->control = true;
	TextControlUpdate();
	textrc = RectMake(_camera->getCam()->x + 80, _camera->getCam()->y + 20, 500, 150);
	if(!dooropen)
	loadmark = RectMake(1200, 310, 50, 80);
	if(dooropen)
		loadmark = RectMake(0, 0, 0, 0);
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("stage18");
	}
	for (int i = 0; i < 3; i++)
	{
		if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &holerc1[i]) && !_player->getPlayer()->dontpix)
		{
			beforedrop();
		}
		if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &holerc2[i]) && !_player->getPlayer()->dontpix)
		{
			beforedrop();
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &switchrc))
	{
		if (KEYMANAGER->isOnceDown('Z') && !dooropen)
		{
			dooropen = true;
			_player->getPlayer()->stage17clear = true;
			if(!SOUNDMANAGER->isPlaySound("boom") && !once)
			{
				SOUNDMANAGER->play("boom", 1.f);
				once = true;
				_player->getPlayer()->boom = true;
			}
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &loadmark) && !_player->getPlayer()->dontpix)
	{
		_player->getPlayer()->x -= 2;
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &updoor1) && !_player->getPlayer()->dontpix)
	{
		_player->getPlayer()->y = 200;
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &updoor2) && !_player->getPlayer()->dontpix)
	{
		_player->getPlayer()->y = 200;
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &updoor3) && !_player->getPlayer()->dontpix)
	{
		_player->getPlayer()->y = 200;
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &updoor4) && !_player->getPlayer()->dontpix)
	{
		_player->getPlayer()->y = 400;
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &updoor5) && !_player->getPlayer()->dontpix)
	{
		_player->getPlayer()->y = 400;
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &updoor6) && !_player->getPlayer()->dontpix)
	{
		_player->getPlayer()->y = 400;
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &text))
	{
		if (KEYMANAGER->isOnceDown('Z') && textnum == 0)
		{
			textnum = 1;
		}
	}
	afterdrop();
	if (drop)_player->getPlayer()->control = false;
}

void stage17::render()
{
	IMAGEMANAGER->findImage("stage17")->render(getMemDC());
	if(textnum != 0)IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
	TextControl();
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
	if (dooropen)
	{
		IMAGEMANAGER->findImage("switchover")->render(getMemDC(), 773, 838);
		IMAGEMANAGER->findImage("trapover")->render(getMemDC(), 1200, 320);
	}
	
	if (_player->getPlayer()->viewEvery)
	{
		Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
		for (int i = 0; i < 3; i++)Rectangle(getMemDC(), holerc1[i].left, holerc1[i].top, holerc1[i].right, holerc1[i].bottom);
		for (int i = 0; i < 3; i++)Rectangle(getMemDC(), holerc2[i].left, holerc2[i].top, holerc2[i].right, holerc2[i].bottom);
		Rectangle(getMemDC(), switchrc.left, switchrc.top, switchrc.right, switchrc.bottom);
		Rectangle(getMemDC(), loadmark.left, loadmark.top, loadmark.right, loadmark.bottom);
		Rectangle(getMemDC(), updoor1.left, updoor1.top, updoor1.right, updoor1.bottom);
		Rectangle(getMemDC(), updoor2.left, updoor2.top, updoor2.right, updoor2.bottom);
		Rectangle(getMemDC(), updoor3.left, updoor3.top, updoor3.right, updoor3.bottom);
		Rectangle(getMemDC(), updoor4.left, updoor4.top, updoor4.right, updoor4.bottom);
		Rectangle(getMemDC(), updoor5.left, updoor5.top, updoor5.right, updoor5.bottom);
		Rectangle(getMemDC(), updoor6.left, updoor6.top, updoor6.right, updoor6.bottom);
		Rectangle(getMemDC(), text.left, text.top, text.right, text.bottom);
	}
	else
	{

	}
}

void stage17::beforedrop()
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

void stage17::afterdrop()
{
	if (drop)
	{
		dropcount++;
		if (dropcount > 100 && dropcount < 270)
		{
			_player->getPlayer()->turn = true;
			_player->getPlayer()->y += 4;
		}
		if (dropcount >= 250)
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

void stage17::TextControlUpdate()
{
	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 23)
				tindex++;
		}
		


	}

	if (textnum == 1)
	{
		if (tindex == 23)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 23;
		}
	}
}

void stage17::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/stage17/text.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	
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

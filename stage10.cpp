#include "stdafx.h"
#include "stage10.h"
#include "player.h"
#include "camera.h"
stage10::stage10()
{
}


stage10::~stage10()
{
}

HRESULT stage10::init()
{
	_player->getPlayer()->loadstagenum = 10;
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
	_player->getPlayer()->SaveStageNum = 10;
	IMAGEMANAGER->addImage("stage10", "image/undertale/stage/stage10.bmp", 641, 1521, false, false);
	_camera->getCam()->x = 0;
	_camera->getCam()->y = 0;
	_camera->getCam()->overviewX = true;
	_camera->getCam()->overviewY = true;
	_player->getPlayer()->control = true;
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
	}
	else
	{
		_player->getPlayer()->x = 10;
		_player->getPlayer()->y = 240;
	}

	holerc = RectMake(270, 200, 90, 120);
	dropcount = 0;
	makehole = false;
	drop = false;
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
	index = 0;
	nextdoor = RectMake(620, 210, 50, 50);
	door1 = RectMake(130, 1150, 50, 50);
	door2 = RectMake(450, 1150, 50, 50);
	howmanydrop = 0;
	return S_OK;
}

void stage10::release()
{
}

void stage10::update()
{
	
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->bottomrc, &holerc))
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
	
	}
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
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("stage11");
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &door1))
	{
		_player->getPlayer()->y = 240;
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &door2))
	{
		_player->getPlayer()->y = 240;
	}

	
}

void stage10::render()
{
	IMAGEMANAGER->findImage("stage10")->render(getMemDC());

	if (makehole)
	{
		IMAGEMANAGER->findImage("hole")->render(getMemDC(), saveholex, saveholey);
		IMAGEMANAGER->findImage("hole")->render(getMemDC(), saveholex1, saveholey1);
		IMAGEMANAGER->findImage("hole")->render(getMemDC(), saveholex2, saveholey2);
		IMAGEMANAGER->findImage("hole")->render(getMemDC(), saveholex3, saveholey3);
		IMAGEMANAGER->findImage("hole")->render(getMemDC(), saveholex4, saveholey4);
	}

	if (_player->getPlayer()->viewEvery)
	{
		char str[128];
		sprintf_s(str, "donpix : %d", _player->getPlayer()->dontpix);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y, str, strlen(str));
		char str1[128];
		sprintf_s(str1, "dropcount : %d", dropcount);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y+20, str1, strlen(str1));
		Rectangle(getMemDC(), holerc.left, holerc.top, holerc.right, holerc.bottom);
		Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
		Rectangle(getMemDC(), door1.left, door1.top, door1.right, door1.bottom);
		Rectangle(getMemDC(), door2.left, door2.top, door2.right, door2.bottom);
	}
	else
	{

	}
}

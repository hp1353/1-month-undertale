#include "stdafx.h"
#include "stage18_21_traproom.h"
#include "player.h"
#include "camera.h"


stage18_21_traproom::stage18_21_traproom()
{
}


stage18_21_traproom::~stage18_21_traproom()
{
}

HRESULT stage18_21_traproom::init()
{
	
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
	_player->getPlayer()->SaveStageNum = 1;
	IMAGEMANAGER->addImage("stage18_21_traproom", "image/undertale/stage/stage18_21_traproom.bmp", 640, 480, false, false);

	_player->getPlayer()->x = 320;
	_player->getPlayer()->y = 240;
	_camera->getCam()->x = 0;
	_camera->getCam()->y = 0;
	_camera->getCam()->overviewX = true;
	_camera->getCam()->overviewY = true;

	nextdoor = RectMake(295, 65, 50, 50);

	_player->getPlayer()->istraproom = true;

	return S_OK;
}

void stage18_21_traproom::release()
{
}

void stage18_21_traproom::update()
{
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("stage18");
	}
}

void stage18_21_traproom::render()
{
	IMAGEMANAGER->findImage("stage18_21_traproom")->render(getMemDC());

	if (_player->getPlayer()->viewEvery)
	{
		Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
	}
	else
	{

	}
}

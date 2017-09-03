#include "stdafx.h"
#include "stage22.h"
#include "player.h"
#include "camera.h"

stage22::stage22()
{
}


stage22::~stage22()
{
}

HRESULT stage22::init()
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
	IMAGEMANAGER->addImage("stage22", "image/undertale/stage/stage22.bmp", 1203, 799, false, false);
	_player->getPlayer()->isstage22_2 = false;
	if (_player->getPlayer()->isstage22_1)
	{
		_player->getPlayer()->x = 1120;
		_player->getPlayer()->y = 540;
		_camera->getCam()->x = 564;
		_camera->getCam()->y = 326;
	}
	else
	{
		_player->getPlayer()->x = 10;
		_player->getPlayer()->y = 540;
		_camera->getCam()->x = 0;
		_camera->getCam()->y = 326;
	}
	
	_camera->getCam()->overviewX = true;
	_camera->getCam()->overviewY = true;

	nextdoor = RectMake(570, 80, 50, 50);
	itemdoor = RectMake(1190, 570, 50, 50);

	if (SOUNDMANAGER->isPauseSound("stagesound"))
	{
		SOUNDMANAGER->resume("stagesound");
	}
	if (!SOUNDMANAGER->isPlaySound("stagesound"))
	{
		SOUNDMANAGER->play("stagesound", 1.f);
	}
	return S_OK;
}

void stage22::release()
{
}

void stage22::update()
{
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("torielgarden");
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &itemdoor))
	{
		SCENEMANAGER->changeScene("stage22_1");
	}
}

void stage22::render()
{
	IMAGEMANAGER->findImage("stage22")->render(getMemDC());
	if (_player->getPlayer()->viewEvery)
	{
		Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
		Rectangle(getMemDC(), itemdoor.left, itemdoor.top, itemdoor.right, itemdoor.bottom);
	}
	else
	{

	}
}

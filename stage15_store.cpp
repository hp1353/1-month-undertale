#include "stdafx.h"
#include "stage15_store.h"
#include "player.h"
#include "camera.h"

stage15_store::stage15_store()
{
}


stage15_store::~stage15_store()
{
}

HRESULT stage15_store::init()
{
	
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
	_player->getPlayer()->dontpix = false;
	_player->getPlayer()->SaveStageNum = 1;
	IMAGEMANAGER->addImage("stage15_store", "image/undertale/stage/stage15_store.bmp", 640, 480, false, false);
	_player->getPlayer()->x = 40;
	_player->getPlayer()->y = 230;
	_camera->getCam()->x = 0;
	_camera->getCam()->y = 0;
	_camera->getCam()->overviewX = true;
	_camera->getCam()->overviewY = true;
	nextdoor = RectMake(-30, 230, 50, 50);
	_player->getPlayer()->isstage15_store = true;
	return S_OK;
}

void stage15_store::release()
{
}

void stage15_store::update()
{
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("stage15");
	}
}

void stage15_store::render()
{
	IMAGEMANAGER->findImage("stage15_store")->render(getMemDC());
	if (_player->getPlayer()->viewEvery)
	{
		Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
	}
	else
	{

	}
}

#include "stdafx.h"
#include "last.h"
#include "player.h"
#include "camera.h"

last::last()
{
}


last::~last()
{
}

HRESULT last::init()
{
	IMAGEMANAGER->addImage("lastload", "image/undertale/last/lasload.bmp", 641, 3837, false, false);
	_player->getPlayer()->x = 300;
	_player->getPlayer()->y = 3750;
	_camera->getCam()->x = 0;
	_camera->getCam()->y = 3358;
	_camera->getCam()->overviewX = true;
	_camera->getCam()->overviewY = true;
	nextdoor = RectMake(300, 160, 50, 50);
	return S_OK;
}

void last::release()
{
}

void last::update()
{
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("ending");
	}

}

void last::render()
{
	IMAGEMANAGER->findImage("lastload")->render(getMemDC());
	//Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
}

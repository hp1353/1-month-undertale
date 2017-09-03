#include "stdafx.h"
#include "stage1.h"
#include "player.h"

stage1::stage1()
{
}


stage1::~stage1()
{
}

HRESULT stage1::init()
{
	if (SOUNDMANAGER->isPlaySound("opening"))
	{
		SOUNDMANAGER->stop("opening");
	}
	mapx = 0;
	mapy = 0;
	IMAGEMANAGER->addImage("stage1", "image/undertale/stage/stage1.bmp", 1360, 520, false,false);//1360,520
	door = RectMakeCenter(1235, 250, 100, 100);
	_player->getPlayer()->SaveStageNum = 1;
	return S_OK;
}

void stage1::release()
{
}

void stage1::update()
{
	
	
	pixelCollision();
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &door))
	{
		
		SCENEMANAGER->changeScene("stage2");
	}
	if (KEYMANAGER->isOnceDown('3'))
	{
		SCENEMANAGER->changeScene("stage5");
	}

}

void stage1::render()
{
	//PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	
	
	if (SCENEMANAGER->CurrentScene("stage1"))
	{
		IMAGEMANAGER->findImage("stage1")->render(getMemDC());
		if (_player->getPlayer()->viewEvery)
			Rectangle(getMemDC(), door.left, door.top, door.right, door.bottom);


		
	}
	

}

void stage1::pixelCollision()
{
	for (int i = _player->getPlayer()->rc.bottom-1; i < _player->getPlayer()->rc.bottom + 2; i++)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("stage1")->getMemDC(), _player->getPlayer()->rc.right, i);
		if (color == RGB(0, 0, 0))
		{
			_player->getPlayer()->y -= 2;
			
		}
	}
	for (int i = _player->getPlayer()->rc.bottom-1; i < _player->getPlayer()->rc.bottom + 2; i++)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("stage1")->getMemDC(), _player->getPlayer()->rc.left, i);
		if (color == RGB(0, 0, 0))
		{
			_player->getPlayer()->y -= 2;
			
		}
	}
	for (int i = _player->getPlayer()->rc.right; i < _player->getPlayer()->rc.right + 2; i++)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("stage1")->getMemDC(), i, _player->getPlayer()->rc.top + 30);
		if (color == RGB(0, 0, 0))
		{
			_player->getPlayer()->x -= 2;

		}
	}
	for (int i = _player->getPlayer()->rc.right; i < _player->getPlayer()->rc.right + 2; i++)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("stage1")->getMemDC(), i, _player->getPlayer()->rc.bottom);
		if (color == RGB(0, 0, 0))
		{
			_player->getPlayer()->x -= 2;

		}
	}
	for (int i = _player->getPlayer()->rc.top + 30; i > _player->getPlayer()->rc.top + 27; i--)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("stage1")->getMemDC(), _player->getPlayer()->rc.left, i);
		if (color == RGB(0, 0, 0))
		{
			_player->getPlayer()->y += 3;

		}
	}
	for (int i = _player->getPlayer()->rc.top + 30; i > _player->getPlayer()->rc.top + 27; i--)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("stage1")->getMemDC(), _player->getPlayer()->rc.right, i);
		if (color == RGB(0, 0, 0))
		{
			_player->getPlayer()->y += 3;

		}
	}
	for (int i = _player->getPlayer()->rc.left; i > _player->getPlayer()->rc.left - 3; i--)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("stage1")->getMemDC(), i, _player->getPlayer()->rc.top + 30);
		if (color == RGB(0, 0, 0))
		{
			_player->getPlayer()->x += 3;

		}
	}
	for (int i = _player->getPlayer()->rc.left; i > _player->getPlayer()->rc.left - 3; i--)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("stage1")->getMemDC(), i, _player->getPlayer()->rc.bottom);
		if (color == RGB(0, 0, 0))
		{
			_player->getPlayer()->x += 3;

		}
	}
}

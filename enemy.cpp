#include "stdafx.h"
#include "enemy.h"


enemy::enemy()
{
}


enemy::~enemy()
{
}

HRESULT enemy::init()
{
	return S_OK;
}

HRESULT enemy::init(const char * imageName, POINT postion)
{
	_currentFrameX = _currentFrameY = 0;
	_count = 0;
	_fireCount = 0.f;
	_rndFireCount = RND->getFromIntTo(5, 5);

	_imageName = IMAGEMANAGER->findImage(imageName);
	_rc = RectMakeCenter(postion.x, postion.y, _imageName->getFrameWidth(), _imageName->getFrameHeight());

	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{
	//프레임 돌리자
	_count++;

	if (_count % 2 == 0)
	{
		_imageName->setFrameX(_imageName->getFrameX() + 1);
		_currentFrameX++;
		if (_currentFrameX > _imageName->getMaxFrameX()) _currentFrameX = 0;
	}
}

void enemy::render()
{
	draw();
}

void enemy::move()
{
}

void enemy::draw()
{
	_imageName->frameRender(getMemDC(), _rc.left, _rc.top, _currentFrameX, _currentFrameY);
}

bool enemy::bulletCountFire()
{
	_fireCount += TIMEMANAGER->getElapsedTime();

	if (_fireCount > 0.f && ((int)_fireCount % _rndFireCount == 0))
	{
		_fireCount = 0.f;
		_rndFireCount = RND->getFromIntTo(5, 5);
		return true;
	}

	return false;
}

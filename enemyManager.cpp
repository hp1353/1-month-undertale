#include "stdafx.h"
#include "enemyManager.h"
#include "spaceShip.h"

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}

HRESULT enemyManager::init()
{
	_bullet = new bullet;
	_bullet->init("bullet", 100, 700);

	return S_OK;
}

void enemyManager::release()
{
	for(_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		SAFE_DELETE((*_viMinion));
	}

	_vMinion.clear();
}

void enemyManager::update()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->update();
	}

	minionBulletFire();

	_bullet->update();

	collision();
}

void enemyManager::render()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->render();
	}

	_bullet->render();
}

void enemyManager::setMinion()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			enemy* ufo;
			ufo = new minion;
			ufo->init("ufo", pointMake(80 + j * 80, 80 + i * 100));

			_vMinion.push_back(ufo);
		}
	}
}

void enemyManager::minionBulletFire()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		_direction = RND->getInt(4);

		switch (_direction)
		{
		case 0://화면 왼쪽
			_pt = pointMake(0, RND->getInt(WINSIZEY));
			break;

		case 1://화면 오른쪽
			_pt = pointMake(WINSIZEX, RND->getInt(WINSIZEY));
			break;

		case 2://화면 위쪽
			_pt = pointMake(RND->getInt(WINSIZEX), 0);
			break;

		case 3://화면 아래쪽
			_pt = pointMake(RND->getInt(WINSIZEX), WINSIZEY);
			break;
		}

		if ((*_viMinion)->bulletCountFire())
		{
			RECT rc = (*_viMinion)->getRect();
			_bullet->fire(_pt.x, _pt.y, 
				MY_UTIL::getAngle(_pt.x, _pt.y,	
				_ship->getShipImage()->getCenterX(),
				_ship->getShipImage()->getCenterY()), 5.f);
		}
	}
}

void enemyManager::removeMinion(int arrayNum)
{
	SAFE_DELETE(_vMinion[arrayNum]);
	_vMinion.erase(_vMinion.begin() + arrayNum);
}

void enemyManager::collision()
{
	for (int i = 0; i < _bullet->getVBullet().size(); i++)
	{
		if (IntersectRect(&RectMake(0, 0, 0, 0), &_ship->getShipImage()->boundingBox(), &_bullet->getVBullet()[i].rc))
		{
			_bullet->removeBullet(i);
			_ship->hitDamage( 10 );
			//break;
		}
	}
}

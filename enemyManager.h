#pragma once

#include "gameNode.h"
#include "minion.h"
#include "bullets.h"
#include <vector>

class spaceShip;

class enemyManager : public gameNode
{
private:
	typedef vector<enemy*> vEnemy;
	typedef vector<enemy*>::iterator viEnemy;

private:
	vEnemy _vMinion;
	viEnemy _viMinion;

	bullet* _bullet;

	spaceShip* _ship;

	bool _stop;
	POINT _pt;
	int _direction;

public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//�̴Ͼ� �¾� ������
	void setMinion();
	void minionBulletFire();
	void removeMinion(int arrayNum);

	void collision();

	inline vector<enemy*> getVMinion() { return _vMinion; }
	inline vector<enemy*>::iterator getVIMinion() { return _viMinion; }

	bool getStop() { return _stop; }

	void setShipMemoryLink(spaceShip* ss) { _ship = ss; }
};


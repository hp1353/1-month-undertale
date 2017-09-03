#pragma once

#include "gameNode.h"

class pixelCollision : public gameNode
{
private:
	image* _mountain;
	image* _ball;

	RECT _rc;

	float _x;
	float _y;

	int _probeY;

	bool _collision;

public:
	pixelCollision();
	~pixelCollision();

	HRESULT init();
	void release();
	void update();
	void render();
};


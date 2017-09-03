#pragma once

#include "gameNode.h"
class ed :public gameNode
{

private:
	image* rmx;

public:
	ed();
	~ed();

	HRESULT init();
	void release();
	void update();
	void render();
};
#pragma once

#include "gameNode.h"
class op :public gameNode
{

private:
	image* tt;

public:
	op();
	~op();

	HRESULT init();
	void release();
	void update();
	void render();
};


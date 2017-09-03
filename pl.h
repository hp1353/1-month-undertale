#pragma once

#include "gameNode.h"
class pl :public gameNode
{

private:
	image* lu;
	RECT re;
	RECT ro;
	RECT rw;
public:
	pl();
	~pl();

	HRESULT init();
	void release();
	void update();
	void render();
};
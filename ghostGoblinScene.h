#pragma once

#include "knight.h"

class ghostGoblinScene : public gameNode
{
private:
	knight* _knight;

public:
	ghostGoblinScene();
	~ghostGoblinScene();

	HRESULT init();
	void release();
	void update();
	void render();
};


#include "stdafx.h"
#include "op.h"


op::op()
{
}


op::~op()
{
}

HRESULT op::init()
{
	tt = IMAGEMANAGER->addImage("ttl", "image/tttt.bmp", WINSIZEX, WINSIZEY, false, false);


	return S_OK;
}

void op::release()
{
}

void op::update()
{
	if (KEYMANAGER->isOnceDown(VK_RETURN))
	{
		SCENEMANAGER->changeScene("ÇÃ·¹ÀÌ");
	}

}

void op::render()
{

	IMAGEMANAGER->findImage("ttl")->render(getMemDC());
}

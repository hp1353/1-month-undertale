#include "stdafx.h"
#include "ed.h"


ed::ed()
{
}


ed::~ed()
{
}

HRESULT ed::init()
{
	rmx = IMAGEMANAGER->addImage("rmx2", "image/aazz.bmp", WINSIZEX, WINSIZEY, false, false);
	return S_OK;
}

void ed::release()
{
}

void ed::update()
{
	if (KEYMANAGER->isOnceDown(VK_RETURN))
	{
		SCENEMANAGER->changeScene("¿ÀÇÁ´×");
	}
}

void ed::render()
{
	IMAGEMANAGER->findImage("rmx2")->render(getMemDC());
}

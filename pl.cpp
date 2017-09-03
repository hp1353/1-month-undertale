#include "stdafx.h"
#include "pl.h"


pl::pl()
{
}


pl::~pl()
{
}

HRESULT pl::init()
{

	lu = IMAGEMANAGER->addFrameImage("luf", "image/luffy_run.bmp", 456, 188, 8, 2, true, RGB(255, 0, 255));
	re = RectMakeCenter(300, 300, 50, 100);
	ro = RectMakeCenter(600, 300, 50, 100);
	return S_OK;
}

void pl::release()
{
}

void pl::update()
{
	if (KEYMANAGER->isStayDown(VK_LEFT))
	{
		re.left -= 5;
		re.right -= 5;
	}
	if (KEYMANAGER->isStayDown(VK_RIGHT))
	{
		re.left += 5;
		re.right += 5;
	}
	if (IntersectRect(&rw, &re, &ro))
	{
		SCENEMANAGER->changeScene("¿£µù");
	}

}
void pl::render()
{
	
	Rectangle(getMemDC(), ro.left, ro.top, ro.right, ro.bottom);
	IMAGEMANAGER->findImage("luf")->frameRender(getMemDC(), re.left, re.top);

}

#include "stdafx.h"
#include "opening.h"


opening::opening()
{
}


opening::~opening()
{
}

HRESULT opening::init()
{
	IMAGEMANAGER->addImage("logo", "image/undertale/opening/logo.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("op1", "image/undertale/opening/op1.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("op2", "image/undertale/opening/op2.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("op3", "image/undertale/opening/op3.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("op4", "image/undertale/opening/op4.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("op5", "image/undertale/opening/op5.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("op6", "image/undertale/opening/op6.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("op7", "image/undertale/opening/op7.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("op8", "image/undertale/opening/op8.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("op9", "image/undertale/opening/op9.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("op10", "image/undertale/opening/op10.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("op11", "image/undertale/opening/op11.bmp", 640, 904, true, RGB(255,0,255));
	IMAGEMANAGER->addImage("base", "image/undertale/opening/base.bmp", 640, 480, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("press", "image/undertale/opening/press.bmp", 184, 34, false, false);
	tcount = 0;
	tindex = 0;
	textrc = RectMake(120, 300, 400, 200);
	textnum = 0;
	imagecount = 0;
	imagemovey = -424;
	alpha = 5;
	alphacount = 0;
	alphadown = false;
	alphaup = true;
	once = false;
	
	return S_OK;
}

void opening::release()
{
}

void opening::update()
{
	//TextControlUpdate();
	if (imagecount < 11)
	{
		if (alphaup)
		{
			if (alpha < 254)
			{
				alpha+=2;
			}
		}
		if (alphadown)
		{
			if (alpha > 1)
			{
				alpha-=2;
			}
		}
		if (alpha > 250)
		{
			alphaup = false;
			alphadown = true;
		}
		if (alpha < 5)
		{
			alphadown = false;
			alphaup = true;
			imagecount += 1;
		}
	}
	if (imagecount == 11)
	{
		alpha = 250;
		alphacount++;
		if (alphacount > 200  && imagemovey < 0)
		{
			imagemovey += 1;
		}
		if (alphacount > 1000)
		{
			imagecount = 12;
			
		}
	}
	if (imagecount == 12)
	{
		alphacount++;
		if (alphacount > 1200)
		{
			if(alpha2 < 250)
			alpha2++;
		}
	}
	if (KEYMANAGER->isOnceDown('Z') || KEYMANAGER->isOnceDown(VK_RETURN))
	{
		SCENEMANAGER->changeScene("stage1");
	}
	if (imagecount >= 1 && !once)
	{
		if (!SOUNDMANAGER->isPlaySound("opening"))
		{
			SOUNDMANAGER->play("opening", 1.f);
			once = true;
		}
	}
}

void opening::render()
{
	IMAGEMANAGER->findImage("dark")->render(getMemDC());
	if(imagecount == 0)
	IMAGEMANAGER->findImage("logo")->alphaRender(getMemDC(),alpha);
	if(imagecount == 1)
		IMAGEMANAGER->findImage("op1")->alphaRender(getMemDC(), alpha);
	if (imagecount == 2)
		IMAGEMANAGER->findImage("op2")->alphaRender(getMemDC(), alpha);
	if (imagecount == 3)
		IMAGEMANAGER->findImage("op3")->alphaRender(getMemDC(), alpha);
	if (imagecount == 4)
		IMAGEMANAGER->findImage("op4")->alphaRender(getMemDC(), alpha);
	if (imagecount == 5)
		IMAGEMANAGER->findImage("op5")->alphaRender(getMemDC(), alpha);
	if (imagecount == 6)
		IMAGEMANAGER->findImage("op6")->alphaRender(getMemDC(), alpha);
	if (imagecount == 7)
		IMAGEMANAGER->findImage("op7")->alphaRender(getMemDC(), alpha);
	if (imagecount == 8)
		IMAGEMANAGER->findImage("op8")->alphaRender(getMemDC(), alpha);
	if (imagecount == 9)
		IMAGEMANAGER->findImage("op9")->alphaRender(getMemDC(), alpha);
	if (imagecount == 10)
		IMAGEMANAGER->findImage("op10")->alphaRender(getMemDC(), alpha);
	if (imagecount == 11)
	{
		IMAGEMANAGER->findImage("op11")->alphaRender(getMemDC(), 0,imagemovey,alpha);
		IMAGEMANAGER->findImage("base")->render(getMemDC());
	}
	if (imagecount == 12)
	{
		IMAGEMANAGER->findImage("logo")->render(getMemDC());
		IMAGEMANAGER->findImage("press")->alphaRender(getMemDC(), 200, 300, alpha2);
	}
	
	//Rectangle(getMemDC(),textrc.left, textrc.top, textrc.right, textrc.bottom);
	/*char str[128];
	sprintf_s(str, "imagecount : %d",imagecount);
	TextOut(getMemDC(), 200, 10, str, strlen(str));*/
	//TextControl();
}

void opening::TextControlUpdate()
{
	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 54)
				tindex++;
		}
		if (textnum == 2)
		{
			if (tindex < 42)
				tindex++;
		}
		if (textnum == 3)
		{
			if (tindex < 40)
				tindex++;
		}
		if (textnum == 4)
		{
			if (tindex < 60)
				tindex++;
		}
		if (textnum == 5)
		{
			if (tindex < 22)
				tindex++;
		}

		if (textnum == 6)
		{
			if (tindex < 37)
				tindex++;
		}
		if (textnum == 7)
		{
			if (tindex < 61)
				tindex++;
		}

	}

	if (textnum == 1)
	{
		if (tindex == 54)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		
	}
	if (textnum == 2)
	{
		if (tindex == 42)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		
	}
	if (textnum == 3)
	{
		if (tindex == 40)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		
	}
	if (textnum == 4)
	{
		if (tindex == 60)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		
	}
	if (textnum == 5)
	{
		if (tindex == 22)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		
	}
	if (textnum == 6)
	{
		if (tindex == 37)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		
	}
	if (textnum == 7)
	{
		if (tindex == 61)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		
	}
}

void opening::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/opening/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/opening/text2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("text/opening/text3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 4)
		hInputFile = CreateFile(_T("text/opening/text4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 5)
		hInputFile = CreateFile(_T("text/opening/text5.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 6)
		hInputFile = CreateFile(_T("text/opening/text6.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 7)
		hInputFile = CreateFile(_T("text/opening/text7.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

	ReadFile(hInputFile, buf, 999 * sizeof(TCHAR), &dwRead, NULL);
	CloseHandle(hInputFile);

	//TextOut(getMemDC(), 80, 200, buf, 2 * tindex);
	DrawText(getMemDC(), buf, tindex, &textrc, DT_LEFT);
	DeleteObject(font);
	font = CreateFont(20, 0, 0, 0, 0, 0, 0, 00, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, NULL);
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	DeleteObject(font);
}

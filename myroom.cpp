#include "stdafx.h"
#include "myroom.h"
#include "player.h"
#include "camera.h"

myroom::myroom()
{
}


myroom::~myroom()
{
}

HRESULT myroom::init()
{
	_player->getPlayer()->SaveStageNum = 1;
	IMAGEMANAGER->addImage("myroom", "image/undertale/stage/myroom.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("myroom2", "image/undertale/stage/myroom2.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("pie", "image/undertale/object/pie.bmp", 40, 28, true, RGB(255, 0, 255));
	_player->getPlayer()->x = 410;
	_player->getPlayer()->y = 370;
	_camera->getCam()->x = 0;
	_camera->getCam()->y = 0;
	_camera->getCam()->overviewX = true;
	_camera->getCam()->overviewY = true;
	backdoor = RectMake(410, 470, 50, 50);
	_player->getPlayer()->isbefroemyroom = true;
	light = RectMake(120, 190, 30, 50);
	lightswitch = true;
	lightnum = 0;
	t1 = RectMake(430, 280, 30, 50);
	t2 = RectMake(180, 150, 30, 50);
	t3 = RectMake(240, 180, 30, 50);
	sleeping = false;
	
	gosleep = false;
	alpha = 0;
	getup = false;
	return S_OK;
}

void myroom::release()
{
}

void myroom::update()
{
	if(!_player->getPlayer()->isgetpie)
	sleep = RectMake(370, 230, 100, 50);
	if (_player->getPlayer()->isgetpie || _player->getPlayer()->alpha == 1)
	{
		sleep = RectMake(0, 0, 0, 0);
	}
	textrc = RectMake(_camera->getCam()->x + 80, _camera->getCam()->y + 20, 500, 150);
	if(textnum != 0) _player->getPlayer()->control = false;
	if(textnum == 0 && !sleeping) _player->getPlayer()->control = true;
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &backdoor))
	{
		SCENEMANAGER->changeScene("rightroom");
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &light))
	{
		if (_player->getPlayer()->pressZ )
		{
			lightnum += 1;
			if(lightnum % 2 == 0)
			lightswitch = false;
			if (lightnum % 2 == 1)
			lightswitch = true;
		}
		
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &t1))
	{
		if (_player->getPlayer()->pressZ)
		{
			textnum = 1;
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &t2))
	{
		if (_player->getPlayer()->pressZ)
		{
			textnum = 2;
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &t3))
	{
		if (_player->getPlayer()->pressZ)
		{
			textnum = 3;
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &sleep))
	{
		if (_player->getPlayer()->pressZ && !getup)
		{
			sleeping = true;
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &pie))
	{
		if (_player->getPlayer()->pressZ)
		{
			textnum = 4;
			_player->getPlayer()->isgetpie = true;
			showpie = false;

		}
	}
	if (sleeping)
	{
		_player->getPlayer()->dontpix = true;
		_player->getPlayer()->frameReset = true;
		_player->getPlayer()->isDown = false;
		_player->getPlayer()->isLeft = false;
		_player->getPlayer()->isRight = false;
		_player->getPlayer()->isUp = true;
		_player->getPlayer()->control = false;
		if (_player->getPlayer()->x < 400 && !gosleep )
		{
			_player->getPlayer()->x += 1;
			if (_player->getPlayer()->y > 210)
				_player->getPlayer()->y -= 1;
			if (_player->getPlayer()->y <= 210)
				_player->getPlayer()->y += 1;
		}
		if (_player->getPlayer()->x >= 400 &&_player->getPlayer()->alpha !=1)
		{
			_player->getPlayer()->gosleep = true;
			gosleep = true;
		}
	}
	if (_player->getPlayer()->alpha == 1 && !getup &&sleeping)
	{
		lightswitch = false;
		if (_player->getPlayer()->pressZ)
		{
			getup = true;
			
		}
	}
	if (getup)
	{
		_player->getPlayer()->isLeft = true;
		_player->getPlayer()->image->setFrameY(2);
		if (_player->getPlayer()->x  > 340)
			_player->getPlayer()->x -= 1;
		if (_player->getPlayer()->x <= 340)
		{
			getup = false;
			gosleep = false;
			sleeping = false;
			_player->getPlayer()->control = true;
			_player->getPlayer()->dontpix = false;
		}
	}
	if (_player->getPlayer()->alpha > 250 && !_player->getPlayer()->isgetpie)
	{
		showpie = true;
	}
	if (showpie)
	{
		pie = RectMake(200, 300, 40, 28);
	}
	if(_player->getPlayer()->isgetpie)pie = RectMake(0, 0, 0, 0);

	TextControlUpdate();
}

void myroom::render()
{
	if(lightswitch)
	IMAGEMANAGER->findImage("myroom")->render(getMemDC());
	if (!lightswitch)
	{
		IMAGEMANAGER->findImage("myroom2")->render(getMemDC());
	}
	if (showpie)
	{
		IMAGEMANAGER->findImage("pie")->render(getMemDC(), 200, 300);
	}
	if (textnum != 0)IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
	TextControl();
	
	if (_player->getPlayer()->viewEvery)
	{
		
		Rectangle(getMemDC(), backdoor.left, backdoor.top, backdoor.right, backdoor.bottom);
		Rectangle(getMemDC(), light.left, light.top, light.right, light.bottom);
		Rectangle(getMemDC(), t1.left, t1.top, t1.right, t1.bottom);
		Rectangle(getMemDC(), t2.left, t2.top, t2.right, t2.bottom);
		Rectangle(getMemDC(), t3.left, t3.top, t3.right, t3.bottom);
		Rectangle(getMemDC(), sleep.left, sleep.top, sleep.right, sleep.bottom);
		Rectangle(getMemDC(), pie.left, pie.top, pie.right, pie.bottom);
		
	}
	else
	{

	}
}

void myroom::TextControlUpdate()
{
	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 45)
			{
				talkend = false;
				tindex++;
			}
		}
		if (textnum == 2)
		{
			if (tindex < 56)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 3)
		{
			if (tindex < 47)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 4)
		{
			if (tindex < 42)
			{
				tindex++;
				talkend = false;
			}
		}


	}

	if (textnum == 1)
	{
		if (tindex == 45)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{

				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 45;
		}
	}
	if (textnum == 2)
	{
		if (tindex == 56)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{

				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 56;
		}
	}
	if (textnum == 3)
	{
		if (tindex == 47)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 47;
		}
	}
	if (textnum == 4)
	{
		if (tindex == 42)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				for (int i = 1; i < 8; i++) //아이템칸 10개
				{
					if (_player->getPlayer()->itemarr[i - 1] == 0) //비어있을때
					{
						_player->getPlayer()->itemarr[i - 1] = 5; //순서대로 아이템번호5 부여
						break;
					}
				}
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 42;
		}
	}
}

void myroom::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/myroom/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/myroom/text2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("text/myroom/text3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 4)
		hInputFile = CreateFile(_T("text/myroom/text4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

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

#include "stdafx.h"
#include "stage8.h"
#include "player.h"
#include "camera.h"
#include "stage3.h"

stage8::stage8()
{
}


stage8::~stage8()
{
}

HRESULT stage8::init()
{
	if (!SOUNDMANAGER->isPauseSound("stagesound"))
	{
		SOUNDMANAGER->resume("stagesound");
	}
	_player->getPlayer()->SaveStageNum = 8;
	IMAGEMANAGER->addImage("stage8", "image/undertale/stage/stage8.bmp", 5295, 480, false, false);
	_player->getPlayer()->x = 20;
	_player->getPlayer()->y = CENTERY - 50;
	_player->getPlayer()->isRight = true;
	_player->getPlayer()->isUp = false;
	
	_camera->getCam()->x = 0;
	_camera->getCam()->y = 0;
	_camera->getCam()->overviewX = true;
	_camera->getCam()->overviewY = true;

	_stage3->_torielMotion.idle = true;
	_stage3->_torielMotion.walk = false;
	_stage3->_torielMotion.moveup = false;

	toriel = IMAGEMANAGER->addFrameImage("toriel", "image/undertale/npc/toriel.bmp", 200, 416, 4, 4, true, RGB(255, 242, 0));
	toriel->setX(200);
	toriel->setY(CENTERY - 90);
	toriel->setFrameX(0);
	toriel->setFrameY(2);
	_stage3->_torielMotion.idle = true;
	_stage3->_torielMotion.walk = false;
	_stage3->_torielMotion.moveright = false;
	_stage3->_torielMotion.moveleft = true;
	tcount = 0;
	tindex = 0;
	tindex2 = 0;
	textnum = 0;
	textnum2 = 0;
	count = 0;
	index = 0;
	tospeed = 1.4f;
	tomove = false;
	nextdoor = RectMake(5250, CENTERY - 25, 50, 50);
	_player->getPlayer()->changeScene = true;
	_player->getPlayer()->playertor = false;
	_player->getPlayer()->battleScene = false;

	if (SOUNDMANAGER->isPlaySound("stagesound"))
	{
		SOUNDMANAGER->stop("stagesound");
	}
	
	
	return S_OK;
}

void stage8::release()
{
}

void stage8::update()
{
	
	textrc = RectMake(_camera->getCam()->x + 200, _camera->getCam()->y + 20, 400, 150);
	TextControlUpdate();
	torielFrame();
	torielMove();
	if (textnum < 5)_player->getPlayer()->control = false;
	if (textnum >= 5 && _player->getPlayer()->x < 5000)
	{
		if (!SOUNDMANAGER->isPlaySound(("stage8sound")))
		{
			SOUNDMANAGER->play("stage8sound", 1.f);
		}
		_player->getPlayer()->control = true;
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("stage9");
	}
}

void stage8::render()
{
	IMAGEMANAGER->findImage("stage8")->render(getMemDC());
	IMAGEMANAGER->findImage("toriel")->frameRender(getMemDC(), toriel->getX(), toriel->getY());
	if(_player->getPlayer()->x > 5000 ) IMAGEMANAGER->findImage("pillar")->render(getMemDC(), 4898, 70);
	if(textnum < 5 || textnum2 >= 1 && textnum2 < 9) IMAGEMANAGER->findImage("textnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
	TextControl();
	TextControl2();
	if (_player->getPlayer()->viewEvery)
	{
		SetBkMode(getMemDC(), OPAQUE); //문자열 배경색 출력되게
		char str[128];
		sprintf_s(str, "textnum2 : %d", textnum2);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y, str, strlen(str));
		char str1[128];
		sprintf_s(str1, "tindex2 : %d", tindex2);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y + 20, str1, strlen(str1));
		Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
	}
	else
	{
		SetBkMode(getMemDC(), TRANSPARENT); //문자열 배경색 출력안되게
	}
}
void stage8::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 0)
		hInputFile = CreateFile(_T("text/stage8/stage8_1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/stage8/stage8_2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/stage8/stage8_3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("text/stage8/stage8_4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 4)
		hInputFile = CreateFile(_T("text/stage8/stage8_5.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

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

void stage8::TextControl2()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum2 == 1)
		hInputFile = CreateFile(_T("text/stage8/stage8_6.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum2 == 2)
		hInputFile = CreateFile(_T("text/stage8/stage8_7.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum2 == 3)
		hInputFile = CreateFile(_T("text/stage8/stage8_8.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum2 == 4)
		hInputFile = CreateFile(_T("text/stage8/stage8_9.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum2 == 5)
		hInputFile = CreateFile(_T("text/stage8/stage8_10.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum2 == 6)
		hInputFile = CreateFile(_T("text/stage8/stage8_11.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum2 == 7)
		hInputFile = CreateFile(_T("text/stage8/stage8_12.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum2 == 8)
		hInputFile = CreateFile(_T("text/stage8/stage8_13.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

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

void stage8::TextControlUpdate()
{

	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 0)
		{
			if (tindex < 38)
				tindex++;
		}
		if (textnum == 1)
		{
			if (tindex < 35)
				tindex++;
		}
		if (textnum == 2)
		{
			if (tindex < 31)
				tindex++;
		}
		if (textnum == 3)
		{
			if (tindex < 30)
				tindex++;
		}
		if (textnum == 4)
		{
			if (tindex < 46)
				tindex++;
		}

	
		if (textnum2 == 1)
		{
			if (tindex < 57)
				tindex++;
		}
		if (textnum2 == 2)
		{
			if (tindex < 40)
				tindex++;
		}
		if (textnum2 == 3)
		{
			if (tindex < 25)
				tindex++;
		}
		if (textnum2 == 4)
		{
			if (tindex < 58)
				tindex++;
		}
		if (textnum2 == 5)
		{
			if (tindex < 42)
				tindex++;
		}
		if (textnum2 == 6)
		{
			if (tindex < 58)
				tindex++;
		}
		if (textnum2 == 7)
		{
			if (tindex < 56)
				tindex++;
		}
		if (textnum2 == 8)
		{
			if (tindex < 32)
				tindex++;
		}

	}

	if (textnum == 0)
	{
		if (tindex == 40)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 40;
		}
	}
	if (textnum == 1)
	{
		if (tindex == 50)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 50;
		}
	}
	if (textnum == 2)
	{
		if (tindex >= 5)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 5;
		}
	}
	if (textnum == 3)
	{
		if (tindex == 47)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 47;
		}
	}
	if (textnum == 4)
	{
		if (tindex >= 18)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
				if (!SOUNDMANAGER->isPlaySound("stage8sound"))
				{
					SOUNDMANAGER->play("stage8sound", 1.f);
				}
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 18;
		}
	}



	if (textnum2 == 1)
	{
		if (tindex == 57)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum2 += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 57;
		}
	}
	if (textnum2 == 2)
	{
		if (tindex >= 40)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum2 += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex= 40;
		}
	}
	
	if (textnum2 == 3)
	{
		if (tindex == 25)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum2 += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 25;
		}
	}
	if (textnum2 == 4)
	{
		if (tindex >= 58)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum2 += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 58;
		}
	}

	if (textnum2 == 5)
	{
		if (tindex == 42)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum2 += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 42;
		}
	}
	if (textnum2 == 6)
	{
		if (tindex >= 58)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum2 += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 58;
		}
	}

	if (textnum2 == 7)
	{
		if (tindex == 56)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum2 += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 56;
		}
	}
	if (textnum2 == 8)
	{
		if (tindex >= 32)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum2 += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 32;
		}
	}

}

void stage8::torielFrame()
{
	if (_stage3->_torielMotion.idle)
	{
		toriel->setFrameX(0);
		toriel->setFrameY(0);
	}
	
	if (_stage3->_torielMotion.walk)
	{
		count++;
		if (count % 10 == 0)
		{

			toriel->setFrameX(index);
			index++;
			if (index > toriel->getMaxFrameX()) index = 0;


		}

	}
	
	if (_stage3->_torielMotion.movedown)
	{
		_stage3->_torielMotion.moveleft = false;
		_stage3->_torielMotion.moveright = false;
		_stage3->_torielMotion.moveup = false;
		toriel->setFrameY(0);

	}
	if (_stage3->_torielMotion.moveleft)
	{
		_stage3->_torielMotion.movedown = false;
		_stage3->_torielMotion.moveright = false;
		_stage3->_torielMotion.moveup = false;
		toriel->setFrameY(2);
	}
	if (_stage3->_torielMotion.moveright)
	{
		_stage3->_torielMotion.movedown = false;
		_stage3->_torielMotion.moveleft = false;
		_stage3->_torielMotion.moveup = false;
		toriel->setFrameY(3);
	}
	if (_stage3->_torielMotion.moveup)
	{
		_stage3->_torielMotion.movedown = false;
		_stage3->_torielMotion.moveleft = false;
		_stage3->_torielMotion.moveright = false;
		toriel->setFrameY(1);
	}

	
}

void stage8::torielMove()
{
	if (toriel->getX() > _player->getPlayer()->x + 300 && textnum2 < 8)
	{
		tomove = false;
		toriel->setX(4900);
		toriel->setY(80);
	}
	else
	{
		if (textnum > 4)
		{
			if (toriel->getX() < 4800)
			{
				_stage3->_torielMotion.idle = false;
				_stage3->_torielMotion.walk = true;
				_stage3->_torielMotion.moveright = true;
				_stage3->_torielMotion.moveleft = false;
				toriel->setX(toriel->getX() + tospeed);
			}
		}
		if (_player->getPlayer()->x + 70 > toriel->getX())
		{
			tospeed += 0.1f;
		}
		if (_player->getPlayer()->x + 110 > toriel->getX())
		{
			tospeed += 0.1f;
		}
	}
	if (_player->getPlayer()->x > 5000)
	{
		if (SOUNDMANAGER->isPlaySound("stage8sound"))
		{
			SOUNDMANAGER->stop("stage8sound");
		}
		if (!SOUNDMANAGER->isPlaySound("flowerdie"))
		{
			SOUNDMANAGER->play("flowerdie", 1.f);
		}
		if(textnum2 < 9)
		_player->getPlayer()->control = false;
		if (textnum2 >= 9)
			_player->getPlayer()->control = true;
		if (toriel->getX() < 5100)
		{
			_stage3->_torielMotion.idle = false;
			_stage3->_torielMotion.walk = true;
			_stage3->_torielMotion.moveright = true;
			toriel->setX(toriel->getX() + 2);
		}
		if (toriel->getX() >= 5100 && toriel->getY() < CENTERY - 90)
		{
			_stage3->_torielMotion.idle = false;
			_stage3->_torielMotion.walk = true;
			_stage3->_torielMotion.moveright = false;
			_stage3->_torielMotion.movedown = true;
			toriel->setY(toriel->getY() + 2);
		}
		if (toriel->getY() >= CENTERY - 90 && textnum2 == 0)
		{
			_stage3->_torielMotion.idle = true;
			_stage3->_torielMotion.walk = false;
			_stage3->_torielMotion.movedown = false;
			_stage3->_torielMotion.moveleft = true;
			textnum2 = 1;
		}
		
	}
	if (textnum2 > 8)
	{
		_stage3->_torielMotion.idle = false;
		_stage3->_torielMotion.walk = true;
		_stage3->_torielMotion.movedown = false;
		_stage3->_torielMotion.moveleft = false;
		_stage3->_torielMotion.moveright = true;
		toriel->setX(toriel->getX() + 2);
	}
}

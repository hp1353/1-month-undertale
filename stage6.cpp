#include "stdafx.h"
#include "stage6.h"
#include "player.h"
#include "camera.h"
#include "stage3.h"

stage6::stage6()
{
}


stage6::~stage6()
{
}




HRESULT stage6::init()
{
	if (!SOUNDMANAGER->isPauseSound("stagesound"))
	{
		SOUNDMANAGER->resume("stagesound");
	}
	_player->getPlayer()->SaveStageNum = 6;
	_player->getPlayer()->changeindex = 0;
	_player->getPlayer()->battleScene = false;
	_player->getPlayer()->changeScene = false;
	_player->getPlayer()->changebattle = false;
	IMAGEMANAGER->addImage("doll", "image/undertale/object/doll.bmp", 34, 58, true, RGB(255, 242, 0));
	IMAGEMANAGER->addImage("stage6", "image/undertale/stage/stage6.bmp", 640, 480, false, false);
	toriel = IMAGEMANAGER->addFrameImage("toriel", "image/undertale/npc/toriel.bmp", 200, 416, 4, 4, true, RGB(255, 0, 255));
	if (_player->getPlayer()->ischangebattle)
	{
		_player->getPlayer()->x = _player->getPlayer()->SaveX;
		_player->getPlayer()->y = _player->getPlayer()->SaveY;
		_player->getPlayer()->changebattle = false;
		_player->getPlayer()->battleScene = false;
		_player->getPlayer()->changeScene = true;
		//_player->getPlayer()->ischangebattle = false;
	}
	else
	{
		_player->getPlayer()->x = 50;
		_player->getPlayer()->y = CENTERY;
		toriel->setX(140);
		toriel->setY(200);
		toriel->setFrameX(0);
		toriel->setFrameY(0);
		_player->getPlayer()->frame = false;
		_player->getPlayer()->frameReset = true;
		_player->getPlayer()->image->setFrameX(0);
		_player->getPlayer()->isDown = false;
		_player->getPlayer()->isRight = true;

	}
	_player->getPlayer()->isDown = false;
	_player->getPlayer()->isRight = true;
	_camera->getCam()->overviewX = true;
	_camera->getCam()->overviewY = true;
	_camera->getCam()->x = 0;
	_camera->getCam()->y = 0;
	
	_stage3->_torielMotion.idle = true;
	_stage3->_torielMotion.walk = false;
	_stage3->_torielMotion.moveright = false;
	
	
	count = 0;
	index = 0;
	tcount = 0;
	tindex = 0;
	textrc = RectMake(200, 20, 400, 150);
		textnum = 1;
	loadMark = RectMake(285, 120, 70, 70);
	introBattle = RectMake(400, 200, 90, 70);
	speed = 3.f;
	speed1 = 80;
	count2 = 0;
	count1 = 0;
	ischange = false;
	//배틀씬 전환시 하트종착지 endx,y
	endx = 46;
	endy = 454;
	// --------------

	aftertextnum1 = 1;
	aftertextindex1 = 0;
	aftertextnum2 = 1;
	aftertextindex2 = 0;
	aftertextnum3 = 1;
	aftertextindex3 = 0;
	aftertextnum4 = 1;
	aftertextindex4 = 0;

	nextdoor = RectMake(CENTERX - 35, 50, 70, 70);

	//_player->getPlayer()->dontpix = true;
	if (SOUNDMANAGER->isPlaySound("dummy"))
	{
		SOUNDMANAGER->stop("dummy");
	}
	if (SOUNDMANAGER->isPauseSound("stagesound"))
	{
		SOUNDMANAGER->resume("stagesound");
	}
	
	return S_OK;
}




void stage6::release()
{
}

void stage6::update()
{
	
	torielFrame();
	if (!_player->getPlayer()->ischangebattle)
	{
		TextControlUpdate();
		if (textnum < 8)
		{
			_player->getPlayer()->isRight = true;
			_player->getPlayer()->control = false;
		}
		else if (textnum >= 8)
		{
			if (toriel->getX() < 295)
			{
				toriel->setX(toriel->getX() + 2);
				toriel->setY(toriel->getY() - 1.5f);
				_stage3->_torielMotion.moveright = true;
				_stage3->_torielMotion.idle = false;
				_stage3->_torielMotion.walk = true;
			}
			else
			{
				_stage3->_torielMotion.moveright = false;
				_stage3->_torielMotion.idle = true;
				_stage3->_torielMotion.walk = false;
			}
			_player->getPlayer()->control = true;
			_player->getPlayer()->frame = true;
		}
		if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &loadMark))
		{
			_player->getPlayer()->y += 2;
		}

		
	}
	if (!_player->getPlayer()->stage6_patten1 && !_player->getPlayer()->stage6_patten2 &&
		!_player->getPlayer()->stage6_patten3 && !_player->getPlayer()->stage6_patten4)
	entryBattle();

	if (_player->getPlayer()->stage6_patten1 || _player->getPlayer()->stage6_patten2 ||
		_player->getPlayer()->stage6_patten3 || _player->getPlayer()->stage6_patten4)
	{
		if (_player->getPlayer()->stage6_patten1)
		{
			if (aftertextnum1 < 3)
			{
				_player->getPlayer()->control = false;
			}
			else
			{
				_player->getPlayer()->control = true;
				_stage3->_torielMotion.moveup = true;
				_stage3->_torielMotion.idle = false;
				_stage3->_torielMotion.walk = true;
				toriel->setY(toriel->getY() - 2);
			}
		}
		if (_player->getPlayer()->stage6_patten2)
		{
			if (aftertextnum2 < 4)
			{
				_player->getPlayer()->control = false;
			}
			else
			{
				_player->getPlayer()->control = true;
				_stage3->_torielMotion.moveup = true;
				_stage3->_torielMotion.idle = false;
				_stage3->_torielMotion.walk = true;
				toriel->setY(toriel->getY() - 2);
			}
		}
		if (_player->getPlayer()->stage6_patten3)
		{
			if (aftertextnum3 < 2)
			{
				_player->getPlayer()->control = false;
			}
			else 
			{
				_player->getPlayer()->control = true;
				_stage3->_torielMotion.moveup = true;
				_stage3->_torielMotion.idle = false;
				_stage3->_torielMotion.walk = true;
				toriel->setY(toriel->getY() - 2);
			}
		}
		if (_player->getPlayer()->stage6_patten4)
		{
			if (aftertextnum4 < 8)
			{
				_player->getPlayer()->control = false;
			}
			else
			{
				_player->getPlayer()->control = true;
				_stage3->_torielMotion.moveup = true;
				_stage3->_torielMotion.idle = false;
				_stage3->_torielMotion.walk = true;
				toriel->setY(toriel->getY() - 2);
			}
		}
		AfterTextControlUpdate();
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("stage7");
	}
}

void stage6::render()
{
	
	IMAGEMANAGER->findImage("stage6")->render(getMemDC());
	IMAGEMANAGER->findImage("doll")->render(getMemDC(), 420, 200);
	if(toriel->getY() > 50)
	IMAGEMANAGER->findImage("toriel")->frameRender(getMemDC(), toriel->getX(), toriel->getY());
	if (!_player->getPlayer()->ischangebattle)
	{
		if (textnum < 8)
			IMAGEMANAGER->findImage("textnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
	}
	
	if (!_player->getPlayer()->stage6_patten1 && !_player->getPlayer()->stage6_patten2 &&
		!_player->getPlayer()->stage6_patten3 && !_player->getPlayer()->stage6_patten4) 
		TextControl();
	if (_player->getPlayer()->stage6_patten1 && aftertextnum1 < 3)
	{
		IMAGEMANAGER->findImage("textnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
		patten1_text();
	}
	if (_player->getPlayer()->stage6_patten2 && aftertextnum2 < 4)
	{
		IMAGEMANAGER->findImage("textnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
		patten2_text();
	}
	if (_player->getPlayer()->stage6_patten3 && aftertextnum3 < 2)
	{
		IMAGEMANAGER->findImage("textnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
		patten3_text();
	}
	if (_player->getPlayer()->stage6_patten4 && aftertextnum4 < 8)
	{
		IMAGEMANAGER->findImage("textnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
		patten4_text();
	}
	if (_player->getPlayer()->viewEvery)
	{
		SetBkMode(getMemDC(), OPAQUE); //배경색 출력되게
		//Rectangle(getMemDC(), textrc.left, textrc.top, textrc.right, textrc.bottom);
		Rectangle(getMemDC(), loadMark.left, loadMark.top, loadMark.right, loadMark.bottom);
		Rectangle(getMemDC(), introBattle.left, introBattle.top, introBattle.right, introBattle.bottom);
		char str[128];
		sprintf_s(str, "aftertextNum1 : %d", aftertextnum1);
		TextOut(getMemDC(), _camera->getCam()->x+200, _camera->getCam()->y  , str, strlen(str));
		char str1[128];
		sprintf_s(str1, "aftertextNum2 : %d", aftertextnum2);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y+20, str1, strlen(str1));
		char str2[128];
		sprintf_s(str2, "aftertextNum3 : %d", aftertextnum3);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y+40, str2, strlen(str2));
		char str3[128];
		sprintf_s(str3, "aftertextNum4 : %d", aftertextnum4);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y+60, str3, strlen(str3));
		char str4[128];
		sprintf_s(str4, "textnum : %d", textnum);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y + 80, str4, strlen(str4));
		Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
	}
	else
	{
		SetBkMode(getMemDC(), TRANSPARENT); //문자열 배경색 출력안되게
	}
	if (_player->getPlayer()->changebattle || ischange)
	{
		PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);

	}
	
}

void stage6::torielFrame()
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


void stage6::TextControlUpdate()
{
	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 75)
				tindex++;
		}
		if (textnum == 2)
		{
			if (tindex < 54)
				tindex++;
		}
		if (textnum == 3)
		{
			if (tindex < 39)
				tindex++;
		}
		if (textnum == 4)
		{
			if (tindex < 44)
				tindex++;
		}
		if (textnum == 5)
		{
			if (tindex < 49)
				tindex++;
		}
		if (textnum == 6)
		{
			if (tindex < 48)
				tindex++;
		}
		if (textnum == 7)
		{
			if (tindex < 44)
				tindex++;
		}
		
	}

	if (textnum == 1)
	{
		if (tindex == 75)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 75;
		}
	}
	if (textnum == 2)
	{
		if (tindex == 54)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 54;
		}
	}
	if (textnum == 3)
	{
		if (tindex == 39)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 39;
		}
	}
	if (textnum == 4)
	{
		if (tindex == 44)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 44;
		}
	}
	if (textnum == 5)
	{
		if (tindex == 49)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 49;
		}
	}
	if (textnum == 6)
	{
		if (tindex == 48)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 48;
		}
	}
	if (textnum == 7)
	{
		if (tindex == 44)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 44;
		}
	}
	
}

void stage6::entryBattle()
{
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &introBattle))
	{
		if (KEYMANAGER->isOnceDown('Z'))
		{
			_player->getPlayer()->SaveX = _player->getPlayer()->x;
			_player->getPlayer()->SaveY = _player->getPlayer()->y;
			_player->getPlayer()->ischangebattle = true;

			_player->getPlayer()->changebattle = true;
			//SCENEMANAGER->changeScene("dummybattle");
			speed = (MY_UTIL::getDistance(_player->getPlayer()->x, _player->getPlayer()->y, 24, 400));
			speedx = (MY_UTIL::getDistance(_player->getPlayer()->x, _player->getPlayer()->x, endx, endx));
			speedy = (MY_UTIL::getDistance(_player->getPlayer()->y, _player->getPlayer()->y, endy, endy));
		}
	}
	if (_player->getPlayer()->changebattle)//하트 초기화
	{
		count1 += 166;
		ischange = true;
		if (_player->getPlayer()->x > endx)
		{
			if (count1 % 10000)
			{
				_player->getPlayer()->x -= speedx / 65;

			}
		}
		else if (_player->getPlayer()->x < endx)
		{
			if (count1 % 10000)
			{
				_player->getPlayer()->x += speedx / 65;

			}
		}

		if (_player->getPlayer()->y < endy)
		{
			if (count1 % 10000)
			{
				_player->getPlayer()->y += speedy / 65;

			}
		}
		else if (_player->getPlayer()->y > endy)
		{
			if (count1 % 10000)
			{
				_player->getPlayer()->y -= speedy / 65;

			}
		}

	}
	else if (ischange)
	{
		SCENEMANAGER->changeScene("dummybattle");
	}
}

void stage6::TextControl()
{

	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
	//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/stage6/say1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/stage6/say2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("text/stage6/say3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 4)
		hInputFile = CreateFile(_T("text/stage6/say4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 5)
		hInputFile = CreateFile(_T("text/stage6/say5.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 6)
		hInputFile = CreateFile(_T("text/stage6/say6.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 7)
		hInputFile = CreateFile(_T("text/stage6/say7.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
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

void stage6::patten1_text()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));//글꼴생성
																													  //폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (aftertextnum1 == 1)
		hInputFile = CreateFile(_T("text/stage6/after_say_patten1_1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (aftertextnum1 == 2)
		hInputFile = CreateFile(_T("text/stage6/after_say_patten1_2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	ReadFile(hInputFile, buf, 999 * sizeof(TCHAR), &dwRead, NULL);
	CloseHandle(hInputFile);

	//TextOut(getMemDC(), 80, 200, buf, 2 * tindex);
	DrawText(getMemDC(), buf, aftertextindex1, &textrc, DT_LEFT);
	DeleteObject(font);
	font = CreateFont(20, 0, 0, 0, 0, 0, 0, 00, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, NULL);
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	DeleteObject(font);

}

void stage6::patten2_text()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (aftertextnum2 == 1)
		hInputFile = CreateFile(_T("text/stage6/after_say_patten2_1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (aftertextnum2 == 2)
		hInputFile = CreateFile(_T("text/stage6/after_say_patten2_2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (aftertextnum2 == 3)
		hInputFile = CreateFile(_T("text/stage6/after_say_patten2_3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

	ReadFile(hInputFile, buf, 999 * sizeof(TCHAR), &dwRead, NULL);
	CloseHandle(hInputFile);

	//TextOut(getMemDC(), 80, 200, buf, 2 * tindex);
	DrawText(getMemDC(), buf, aftertextindex2, &textrc, DT_LEFT);

	DeleteObject(font);
	font = CreateFont(20, 0, 0, 0, 0, 0, 0, 00, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, NULL);
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	DeleteObject(font);
}

void stage6::patten3_text()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (aftertextnum3 == 1)
		hInputFile = CreateFile(_T("text/stage6/after_say_patten3_1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	ReadFile(hInputFile, buf, 999 * sizeof(TCHAR), &dwRead, NULL);
	CloseHandle(hInputFile);

	//TextOut(getMemDC(), 80, 200, buf, 2 * tindex);
	DrawText(getMemDC(), buf, aftertextindex3, &textrc, DT_LEFT);

	DeleteObject(font);
	font = CreateFont(20, 0, 0, 0, 0, 0, 0, 00, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, NULL);
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	DeleteObject(font);
}

void stage6::patten4_text()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (aftertextnum4 == 1)
		hInputFile = CreateFile(_T("text/stage6/after_say_patten4_1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (aftertextnum4 == 2)
		hInputFile = CreateFile(_T("text/stage6/after_say_patten4_2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (aftertextnum4 == 3)
		hInputFile = CreateFile(_T("text/stage6/after_say_patten4_3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (aftertextnum4 == 4)
		hInputFile = CreateFile(_T("text/stage6/after_say_patten4_4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (aftertextnum4 == 5)
		hInputFile = CreateFile(_T("text/stage6/after_say_patten4_5.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (aftertextnum4 == 6)
		hInputFile = CreateFile(_T("text/stage6/after_say_patten4_6.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (aftertextnum4 == 7)
		hInputFile = CreateFile(_T("text/stage6/after_say_patten4_7.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

	ReadFile(hInputFile, buf, 999 * sizeof(TCHAR), &dwRead, NULL);
	CloseHandle(hInputFile);

	//TextOut(getMemDC(), 80, 200, buf, 2 * tindex);
	DrawText(getMemDC(), buf, aftertextindex4, &textrc, DT_LEFT);

	DeleteObject(font);
	font = CreateFont(20, 0, 0, 0, 0, 0, 0, 00, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, NULL);
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	DeleteObject(font);
}

void stage6::AfterTextControlUpdate()
{
	tcount++;
	if (tcount % 3 == 0)
	{
		if (_player->getPlayer()->stage6_patten1)
		{
			if (aftertextnum1 == 1)
			{
				if (aftertextindex1 < 65)
					aftertextindex1++;
			}
			if (aftertextnum1 == 2)
			{
				if (aftertextindex1 < 75)
					aftertextindex1++;
			}
		}
		if (_player->getPlayer()->stage6_patten2)
		{
			if (aftertextnum2 == 1)
			{
				if (aftertextindex2 < 5)
					aftertextindex2++;
			}
			if (aftertextnum2 == 2)
			{
				if (aftertextindex2 < 5)
					aftertextindex2++;
			}
			if (aftertextnum2 == 3)
			{
				if (aftertextindex2 < 32)
					aftertextindex2++;
			}
		}
		if (_player->getPlayer()->stage6_patten3)
		{
			if (aftertextnum3 == 1)
			{
				if (aftertextindex3 < 36)
					aftertextindex3++;
			}
		}
		if (_player->getPlayer()->stage6_patten4)
		{
			if (aftertextnum4 == 1)
			{
				if (aftertextindex4 < 5)
					aftertextindex4++;
			}
			if (aftertextnum4 == 2)
			{
				if (aftertextindex4 < 19)
					aftertextindex4++;
			}
			if (aftertextnum4 == 3)
			{
				if (aftertextindex4 < 44)
					aftertextindex4++;
			}
			if (aftertextnum4 == 4)
			{
				if (aftertextindex4 < 42)
					aftertextindex4++;
			}
			if (aftertextnum4 == 5)
			{
				if (aftertextindex4 < 60)
					aftertextindex4++;
			}
			if (aftertextnum4 == 6)
			{
				if (aftertextindex4 < 61)
					aftertextindex4++;
			}
			if (aftertextnum4 == 7)
			{
				if (aftertextindex4 < 54)
					aftertextindex4++;
			}
		}
		
	}
	if (_player->getPlayer()->stage6_patten1)
	{
		if (aftertextnum1 == 1)
		{
			if (aftertextindex1 == 65)
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					aftertextindex1 = 0;
					aftertextnum1 += 1;
				}
			}
			else
			{
				if (KEYMANAGER->isOnceDown('X'))aftertextindex1 = 65;
			}
		}
		if (aftertextnum1 == 2)
		{
			if (aftertextindex1 == 75)
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					aftertextindex1 = 0;
					aftertextnum1 += 1;
				}
			}
			else
			{
				if (KEYMANAGER->isOnceDown('X'))aftertextindex1 = 75;
			}
		}


		//p1
	}
	if (_player->getPlayer()->stage6_patten2)
	{
		if (aftertextnum2 == 1)
		{
			if (aftertextindex2 == 5)
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					aftertextindex2 = 0;
					aftertextnum2 += 1;
				}
			}
			else
			{
				if (KEYMANAGER->isOnceDown('X'))aftertextindex2 = 5;
			}
		}
		if (aftertextnum2 == 2)
		{
			if (aftertextindex2 == 5)
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					aftertextindex2 = 0;
					aftertextnum2 += 1;
				}
			}
			else
			{
				if (KEYMANAGER->isOnceDown('X'))aftertextindex2 = 5;
			}
		}
		if (aftertextnum2 == 3)
		{
			if (aftertextindex2 == 32)
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					aftertextindex2 = 0;
					aftertextnum2 += 1;
				}
			}
			else
			{
				if (KEYMANAGER->isOnceDown('X'))aftertextindex2 = 32;
			}
		}
		//p2
	}
	if (_player->getPlayer()->stage6_patten3)
	{
		if (aftertextnum3 == 1)
		{
			if (aftertextindex3 == 36)
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					aftertextindex3 = 0;
					aftertextnum3 += 1;
				}
			}
			else
			{
				if (KEYMANAGER->isOnceDown('X'))aftertextindex3 = 36;
			}
		}
		//p3
	}
	if (_player->getPlayer()->stage6_patten4)
	{
		if (aftertextnum4 == 1)
		{
			if (aftertextindex4 == 5)
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					aftertextindex4 = 0;
					aftertextnum4 += 1;
				}
			}
			else
			{
				if (KEYMANAGER->isOnceDown('X'))aftertextindex4 = 5;
			}
		}
		if (aftertextnum4 == 2)
		{
			if (aftertextindex4 == 19)
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					aftertextindex4 = 0;
					aftertextnum4 += 1;
				}
			}
			else
			{
				if (KEYMANAGER->isOnceDown('X'))aftertextindex4 = 19;
			}
		}
		if (aftertextnum4 == 3)
		{
			if (aftertextindex4 == 44)
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					aftertextindex4 = 0;
					aftertextnum4 += 1;
				}
			}
			else
			{
				if (KEYMANAGER->isOnceDown('X'))aftertextindex4 = 44;
			}
		}
		if (aftertextnum4 == 4)
		{
			if (aftertextindex4 == 42)
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					aftertextindex4 = 0;
					aftertextnum4 += 1;
				}
			}
			else
			{
				if (KEYMANAGER->isOnceDown('X'))aftertextindex4 = 42;
			}
		}
		if (aftertextnum4 == 5)
		{
			if (aftertextindex4 == 60)
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					aftertextindex4 = 0;
					aftertextnum4 += 1;
				}
			}
			else
			{
				if (KEYMANAGER->isOnceDown('X'))aftertextindex4 = 60;
			}
		}
		if (aftertextnum4 == 6)
		{
			if (aftertextindex4 == 61)
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					aftertextindex4 = 0;
					aftertextnum4 += 1;
				}
			}
			else
			{
				if (KEYMANAGER->isOnceDown('X'))aftertextindex4 = 61;
			}
		}
		if (aftertextnum4 == 7)
		{
			if (aftertextindex4 == 54)
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					aftertextindex4 = 0;
					aftertextnum4 += 1;
				}
			}
			else
			{
				if (KEYMANAGER->isOnceDown('X'))aftertextindex4 = 54;
			}
		}
	}
}

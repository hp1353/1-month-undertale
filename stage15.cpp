#include "stdafx.h"
#include "stage15.h"
#include "player.h"
#include "camera.h"

stage15::stage15()
{
}


stage15::~stage15()
{
}

HRESULT stage15::init()
{
	//_player->getPlayer()->loadstagenum = 15;
	_player->getPlayer()->dontpix = false;
	if (SOUNDMANAGER->isPlaySound("battlesound"))
	{
		SOUNDMANAGER->stop("battlesound");
	}
	if (SOUNDMANAGER->isPlaySound("midbosssound"))
	{
		SOUNDMANAGER->stop("midbosssound");
	}
	if (_player->getPlayer()->killnum < 10)
	{
		if (!SOUNDMANAGER->isPlaySound("stagesound"))
		{
			SOUNDMANAGER->play("stagesound", 1.f);
		}
		if (SOUNDMANAGER->isPauseSound("stagesound"))
		{
			SOUNDMANAGER->resume("stagesound");
		}
	}
	_player->getPlayer()->SaveStageNum = 15;
	IMAGEMANAGER->addImage("stage15", "image/undertale/stage/stage15.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("ghostalpha", "image/undertale/npc/ghost.bmp", 66, 34, true, RGB(255, 0, 255));
	if (!_player->getPlayer()->stage15skip)
	{
		if (_player->getPlayer()->isstage15_store)
		{
			textnum = 0;
			_player->getPlayer()->x = 580;
			_player->getPlayer()->y = 230;
			loadmark = RectMake(295, 255, 50, 50);

		}
		else if (!_player->getPlayer()->ghostend)
		{
			textnum = 0;
			_player->getPlayer()->x = 10;
			_player->getPlayer()->y = 230;
			loadmark = RectMake(295, 255, 50, 50);


		}
		else if (_player->getPlayer()->ghostend)
		{
			//loadmark = RectMake(295, 255, 50, 50);
			_player->getPlayer()->ischangebattle = false;
			_player->getPlayer()->changebattle = false;
			_player->getPlayer()->dontpix = false;
			_player->getPlayer()->changeScene = true;
			_player->getPlayer()->changeindex = 0;
			_camera->getCam()->cameramove = true;
			_player->getPlayer()->x = 260;
			_player->getPlayer()->y = 230;
			_player->getPlayer()->control = false;
			SOUNDMANAGER->stop("midbosssound");
			if (!SOUNDMANAGER->isPauseSound("stagesound"))
			{
				SOUNDMANAGER->resume("stagesound");
			}
			textnum = 5;
		}
		if (_player->getPlayer()->killghost)
		{
			alpha = true;
			ischange = false;
			textnum = 0;
			_player->getPlayer()->ischangebattle = false;
			_player->getPlayer()->changebattle = false;
			_player->getPlayer()->dontpix = false;
			_player->getPlayer()->changeScene = true;
			_player->getPlayer()->changeindex = 0;
			_player->getPlayer()->battleScene = false;
			_camera->getCam()->cameramove = true;
			_player->getPlayer()->x = 260;
			_player->getPlayer()->y = 230;

		}
		if (_player->getPlayer()->killnum > 9)
		{
			alpha = true;
		}
	}
	if (_player->getPlayer()->stage15skip)
	{
		//alpha = true;
		ischange = false;
		textnum = 0;
		_player->getPlayer()->ischangebattle = false;
		_player->getPlayer()->changebattle = false;
		_player->getPlayer()->dontpix = false;
		_player->getPlayer()->changeScene = true;
		_player->getPlayer()->changeindex = 0;
		_player->getPlayer()->battleScene = false;
		_camera->getCam()->cameramove = true;
		_player->getPlayer()->x = 10;
		_player->getPlayer()->y = 230;
		loadmark = RectMake(0, 0, 0, 0);
		ghostalpha = 0;
	}
	
	_camera->getCam()->x = 0;
	_camera->getCam()->y = 0;
	_camera->getCam()->overviewX = true;
	_camera->getCam()->overviewY = true;
	_player->getPlayer()->dontpix = false;

		GhostTextrc = RectMake(270, 230, 100, 100);
	storedoor = RectMake(630, 270, 50, 50);
	nextdoor = RectMake(425, 80, 50, 50);


	tcount = 0;
	tindex = 0;
	
	textrc = RectMake(_camera->getCam()->x + 80, _camera->getCam()->y + 20, 500, 150);
	heartcontrolnum = 150;

	count2 = 0;
	select = false;
	test = 0;
	gobattle = false;
	playonce = false;
	playonce2 = false;
	ghostalpha = 250;
	alphacount = 0;
	alpha = false;
	return S_OK;
}

void stage15::release()
{
}

void stage15::update()
{
	if (_player->getPlayer()->killnum > 9)
	{
		loadmark = RectMake(0, 0, 0, 0);
		alpha = true;
	}
	if (_player->getPlayer()->killghost)
	{
		loadmark = RectMake(0, 0, 0, 0);
		alpha = true;
	}
	if (alpha)
	{
		loadmark = RectMake(0, 0, 0, 0);

		if (ghostalpha > 1)
		{
			ghostalpha-=3;
		}
		else
		{
			_player->getPlayer()->control = true;
		}
	}
	TextControlUpdate();
	if (!_player->getPlayer()->ghostend || !(_player->getPlayer()->killnum > 9) || !_player->getPlayer()->killghost)
	{
		if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &loadmark))
		{
			_player->getPlayer()->x -= 2;
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &GhostTextrc) && textnum == 0 && !select && !_player->getPlayer()->ghostend
		&& !_player->getPlayer()->killghost && _player->getPlayer()->killnum < 10)
	{
		if (KEYMANAGER->isOnceDown('Z') && textnum == 0)
		{
			textnum = 1;
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("stage16");
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &storedoor))
	{
		SCENEMANAGER->changeScene("stage15_store");
	}
	if (textnum != 0) _player->getPlayer()->control = false;
	if (textnum == 0) _player->getPlayer()->control = true;

	if (textnum == 4 && tindex > 40)
	{
		select = true;
		
	}
	if (select)
	{
		
		if (heartcontrolnum == 150)
		{
			if (KEYMANAGER->isStayDown('Z'))
			{
				test = 1;
				gobattle = true;
				
			}

		}
		if (heartcontrolnum == 270)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				textnum = 0;
				test = 2;
			}
		}
		
	}
	if (gobattle)entryBattle();
}

void stage15::render()
{
	IMAGEMANAGER->findImage("stage15")->render(getMemDC());
	if(!_player->getPlayer()->stage15skip)
	IMAGEMANAGER->findImage("ghostalpha")->alphaRender(getMemDC(), 287, 265,ghostalpha);
	if (textnum != 0) IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
	TextControl();
	if (textnum == 4 && tindex > 40)
	{
		IMAGEMANAGER->findImage("heart")->render(getMemDC(), _camera->getCam()->x + heartcontrolnum, _camera->getCam()->y + 75);
		if (KEYMANAGER->isOnceDown(VK_LEFT))
		{
			heartcontrolnum = 150; //예
		}
		if (KEYMANAGER->isOnceDown(VK_RIGHT))
		{
			heartcontrolnum = 270; //아니
		}
	}
	if (_player->getPlayer()->changebattle || ischange && !_player->getPlayer()->ghostend)
	{
		PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);

	}
	if (_player->getPlayer()->viewEvery)
	{
		Rectangle(getMemDC(), loadmark.left, loadmark.top, loadmark.right, loadmark.bottom);
		char str[128];
		sprintf_s(str, "test : %d",test);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y, str, strlen(str));
		char str1[128];
		sprintf_s(str1, "count2 : %d", count2);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y+20, str1, strlen(str1));
		char str2[128];
		sprintf_s(str2, "playertor : %d", _player->getPlayer()->playertor);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y+100, str2, strlen(str2));
		char str3[128];
		sprintf_s(str3, "changescnene : %d", _player->getPlayer()->changeScene);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y + 120, str3, strlen(str3));
		Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
		Rectangle(getMemDC(), storedoor.left, storedoor.top, storedoor.right, storedoor.bottom);
		
	}
}

void stage15::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																										  //폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/stage15/stage15_1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/stage15/stage15_2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("text/stage15/stage15_3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 4)
		hInputFile = CreateFile(_T("text/stage15/stage15_4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

	if (textnum == 5)
		hInputFile = CreateFile(_T("text/stage15/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 6)
		hInputFile = CreateFile(_T("text/stage15/text2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 7)
		hInputFile = CreateFile(_T("text/stage15/text3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 8)
		hInputFile = CreateFile(_T("text/stage15/text4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 9)
		hInputFile = CreateFile(_T("text/stage15/text5.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

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

void stage15::TextControlUpdate()
{
	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 43)
				tindex++;
		}
		if (textnum == 2)
		{
			if (tindex < 50)
				tindex++;
		}
		if (textnum == 3)
		{
			if (tindex < 79)
				tindex++;
		}
		if (textnum == 4)
		{
			if (tindex < 46)
				tindex++;
		}

		if (textnum == 5)
		{
			if (tindex < 45)
				tindex++;
		}
		if (textnum == 6)
		{
			if (tindex < 35)
				tindex++;
		}
		if (textnum == 7)
		{
			if (tindex < 5)
				tindex++;
		}
		if (textnum == 8)
		{
			if (tindex < 33)
				tindex++;
		}
		if (textnum == 9)
		{
			if (tindex < 17)
				tindex++;
		}

	}

	if (textnum == 1)
	{
		if (tindex == 43)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 43;
		}
	}
	if (textnum == 2)
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
	if (textnum == 3)
	{
		if (tindex == 79)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 79;
		}
	}
	if (textnum == 4)
	{
		if (tindex == 46)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 46;
		}
	}


	if (textnum == 5)
	{
		if (tindex == 45)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 45;
		}
	}
	if (textnum == 6)
	{
		if (tindex == 35)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 35;
		}
	}
	if (textnum == 7)
	{
		if (tindex == 5)
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
	if (textnum == 8)
	{
		if (tindex == 33)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 33;
		}
	}
	if (textnum == 9)
	{
		if (tindex == 17)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
				alpha = true;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 17;
		}
	}

}
void stage15::entryBattle()
{
	if (!SOUNDMANAGER->isPlaySound("entrybattle") && !playonce)
	{
		SOUNDMANAGER->play("entrybattle", 1.f);
		playonce = true;
	}
	
	_camera->cam.cameramove = false;
	endx = _camera->getCam()->x - 20;
	endy = _camera->getCam()->y + 504;


	_player->getPlayer()->SaveX = _player->getPlayer()->x;
	_player->getPlayer()->SaveY = _player->getPlayer()->y;

	_player->getPlayer()->ischangebattle = true;
	_player->getPlayer()->changebattle = true;
	_player->getPlayer()->dontpix = true;
	speed = (MY_UTIL::getDistance(_player->getPlayer()->x, _player->getPlayer()->y, _camera->getCam()->x + 24, _camera->getCam()->y + 400));
	speedx = (MY_UTIL::getDistance(_player->getPlayer()->x, _player->getPlayer()->x, endx, endx));
	speedy = (MY_UTIL::getDistance(_player->getPlayer()->y, _player->getPlayer()->y, endy, endy));



	if (_player->getPlayer()->changebattle)//하트 초기화
	{
		_player->getPlayer()->control = false;
		count2 += 166;
		ischange = true;
		if (_player->getPlayer()->x > endx)
		{
			if (count2 % 10000)
			{
				_player->getPlayer()->x -= speedx / 65;

			}
		}
		else if (_player->getPlayer()->x < endx)
		{
			if (count2 % 10000)
			{
				_player->getPlayer()->x += speedx / 65;

			}
		}

		if (_player->getPlayer()->y < endy)
		{
			if (count2 % 10000)
			{
				_player->getPlayer()->y += speedy / 65;

			}
		}
		else if (_player->getPlayer()->y > endy)
		{
			if (count2 % 10000)
			{
				_player->getPlayer()->y -= speedy / 65;

			}
		}

	}
	if (ischange && count2 > 8000)
	{
		SCENEMANAGER->changeScene("stage15battle");
	}
}
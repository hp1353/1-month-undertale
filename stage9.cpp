#include "stdafx.h"
#include "stage9.h"
#include "player.h"
#include "camera.h"

stage9::stage9()
{
}


stage9::~stage9()
{
}

HRESULT stage9::init()
{
	_player->getPlayer()->loadstagenum = 9;
	_player->getPlayer()->playertor = false;
	_player->getPlayer()->battleScene = false;
	
	_player->getPlayer()->walkcount = 0;
	_player->getPlayer()->control = true;
	_player->getPlayer()->dontpix = false;
	_player->getPlayer()->changeindex = 0;
	_player->getPlayer()->SaveStageNum = 9;
	_player->getPlayer()->changeScene = false;
	_player->getPlayer()->changebattle = false;
	IMAGEMANAGER->addImage("stage9", "image/undertale/stage/stage9.bmp", 640, 1002, false, false);
	frognpc = IMAGEMANAGER->addFrameImage("frognpc", "image/undertale/npc/frognpc.bmp", 152, 40, 4, 1, true, RGB(255, 0, 255));
	savestar = IMAGEMANAGER->addFrameImage("savestar", "image/undertale/object/savestar.bmp", 78, 37, 2, 1, true, RGB(255, 0, 255));

	
	
	if (_player->getPlayer()->battleend)
	{
		_player->getPlayer()->x = _player->getPlayer()->SaveX;
		_player->getPlayer()->y = _player->getPlayer()->SaveY;
		//_player->getPlayer()->changeScene = true;
		_player->getPlayer()->playertor = false;
		_player->getPlayer()->battleScene = false;
		_player->getPlayer()->battleend = false;
		_player->getPlayer()->walkcount = 0;
		_player->getPlayer()->control = true;
		_player->getPlayer()->dontpix = false;
		_camera->getCam()->x = _player->getPlayer()->savecamx;
		_camera->getCam()->y = _player->getPlayer()->savecamy;
		_camera->getCam()->cameramove = true;
	}
	else
	{
		if (!_player->getPlayer()->isstage9_1&& !_player->getPlayer()->badending)
		{
			_player->getPlayer()->x = 30;
			_player->getPlayer()->y = 230;
			_camera->getCam()->x = 0;
			_camera->getCam()->y = 0;
			_camera->getCam()->overviewX = true;
			_camera->getCam()->overviewY = true;
		}
		if (_player->getPlayer()->isstage9_1&& !_player->getPlayer()->badending)
		{
			_player->getPlayer()->x = 300;
			_player->getPlayer()->y = 140;
			_camera->getCam()->x = 0;
			_camera->getCam()->y = 0;
			_camera->getCam()->overviewX = true;
			_camera->getCam()->overviewY = true;
		}

	}
	intro9_1 = RectMake(290, 80, 50, 50);
	count = 0;
	index = 0;
	
	if (!_player->getPlayer()->killstage7frog) frogrc = RectMake(210, 160, 40, 40);
	textnum = 0;
	tcount = 0;
	tindex = 0;
	count1 = 0;
	index1 = 0;
	starrc = RectMake(420, 280, 50, 50);
	tindex2 = 0;
	textnum2 = 0;
	nextdoor = RectMake(620, 720, 50, 50);
	if (SOUNDMANAGER->isPlaySound("flowerdie"))
	{
		SOUNDMANAGER->stop("flowerdie");
	}
	if (SOUNDMANAGER->isPlaySound("battlesound"))
	{
		SOUNDMANAGER->stop("battlesound");
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
	return S_OK;
}

void stage9::release()
{
}

void stage9::update()
{
	
	textrc = RectMake(_camera->getCam()->x + 80, _camera->getCam()->y + 20, 500, 150);
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &intro9_1))
	{
		
		SCENEMANAGER->changeScene("stage9_1");
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &frogrc) && textnum == 0)
	{
		if (KEYMANAGER->isOnceDown('Z') && textnum == 0 && (_player->getPlayer()->killnum < 10))
		{
			textnum = 1;
		}
	}
	else if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &starrc) && textnum2 == 0)
	{
		if (KEYMANAGER->isOnceDown('Z') && textnum == 0)
		{
			_player->getPlayer()->CurHp = _player->getPlayer()->MaxHp;
			SOUNDMANAGER->play("heal",1.f);
			textnum2 = 1;
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("stage10");
	}
	frogFrame();
	starFrame();
	TextControlUpdate();
	if (textnum != 0)_player->getPlayer()->control = false;
	else if (textnum2 != 0) _player->getPlayer()->control = false;
	else if (textnum2 == 0 && textnum == 0) _player->getPlayer()->control = true;
}

void stage9::render()
{
	IMAGEMANAGER->findImage("stage9")->render(getMemDC());
	if (!_player->getPlayer()->killstage7frog && (_player->getPlayer()->killnum < 10))
	{
		IMAGEMANAGER->findImage("frognpc")->frameRender(getMemDC(), 210, 160);
	}
	IMAGEMANAGER->findImage("savestar")->frameRender(getMemDC(), 420, 280);
	if (textnum !=0 || textnum2 !=0)IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
	TextControl();
	TextControl2();
	if (_player->getPlayer()->viewEvery)
	{
		Rectangle(getMemDC(), intro9_1.left, intro9_1.top, intro9_1.right, intro9_1.bottom);
		Rectangle(getMemDC(), frogrc.left, frogrc.top, frogrc.right, frogrc.bottom);
		Rectangle(getMemDC(), starrc.left, starrc.top, starrc.right, starrc.bottom);
		Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
	}
}

void stage9::frogFrame()
{
	frognpc->setFrameX(index);
	count++;
	
	if (index > frognpc->getMaxFrameX())
	{
		index = 0;
	}
	else if (count % 20 == 0)index++;
}
void stage9::starFrame()
{
	savestar->setFrameX(index1);
	count1++;

	if (index1 > savestar->getMaxFrameX())
	{
		index1 = 0;
	}
	else if (count1 % 10 == 0)index1++;
}
void stage9::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/stage9/frogtext1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/stage9/frogtext2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)						  
		hInputFile = CreateFile(_T("text/stage9/frogtext3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 4)						  
		hInputFile = CreateFile(_T("text/stage9/frogtext4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 5)						  
		hInputFile = CreateFile(_T("text/stage9/frogtext5.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 6)						  
		hInputFile = CreateFile(_T("text/stage9/frogtext6.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

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
void stage9::TextControlUpdate()
{

	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 34)
				tindex++;
		}
		if (textnum == 2)
		{
			if (tindex < 50)
				tindex++;
		}
		if (textnum == 3)
		{
			if (tindex < 68)
				tindex++;
		}
		if (textnum == 4)
		{
			if (tindex < 51)
				tindex++;
		}
		if (textnum == 5)
		{
			if (tindex < 57)
				tindex++;
		}
		if (textnum == 6)
		{
			if (tindex < 35)
				tindex++;
		}
		if (textnum2 == 1)
		{
			if (tindex2 < 83)
				tindex2++;
		}
		if (textnum2 == 2)
		{
			if (tindex2 < 27)
				tindex2++;
		}
	}

	if (textnum == 1)
	{
		if (tindex == 34)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 34;
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
		if (tindex == 68)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 68;
		}
	}
	if (textnum == 4)
	{
		if (tindex == 51)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 51;
		}
	}
	if (textnum == 5)
	{
		if (tindex == 57)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 57;
		}
	}
	if (textnum == 6)
	{
		if (tindex == 35)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 35;
		}
	}
	if (textnum2 == 1)
	{
		if (tindex2 == 83)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex2 = 0;
				textnum2 += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex2 = 83;
		}
	}
	if (textnum2 == 2)
	{
		
		if (tindex2 == 27)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex2 = 0;
				textnum2 = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex2 = 27;
		}
	}
}

void stage9::TextControl2()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum2 == 1)
		hInputFile = CreateFile(_T("text/stage9/star1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum2 == 2)
		hInputFile = CreateFile(_T("text/stage9/star2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	
	ReadFile(hInputFile, buf, 999 * sizeof(TCHAR), &dwRead, NULL);
	CloseHandle(hInputFile);

	//TextOut(getMemDC(), 80, 200, buf, 2 * tindex);
	DrawText(getMemDC(), buf, tindex2, &textrc, DT_LEFT);

	DeleteObject(font);
	font = CreateFont(20, 0, 0, 0, 0, 0, 0, 00, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, NULL);
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	DeleteObject(font);
}
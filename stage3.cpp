#include "stdafx.h"
#include "stage3.h"
#include "player.h"
#include "camera.h"
stage3::stage3()
{
}


stage3::~stage3()
{
}

HRESULT stage3::init()
{
	_player->getPlayer()->SaveStageNum = 3;
	IMAGEMANAGER->addImage("stage3", "image/undertale/stage/stage3.bmp", 640, 959, false, false);
	savestar = IMAGEMANAGER->addFrameImage("savestar", "image/undertale/object/savestar.bmp", 78, 37, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("save1", "image/undertale/event/stage3Event/save1.bmp", 578, 152, false, false);
	IMAGEMANAGER->addImage("save2", "image/undertale/event/stage3Event/save2.bmp", 578, 152, false, false);
	IMAGEMANAGER->addImage("save3", "image/undertale/event/stage3Event/save3.bmp", 424, 174, false, false);

	//  ------ 카메라 초기화  -------
	_player->getPlayer()->x = CENTERX - _player->getPlayer()->image->getFrameWidth()/2;
	_player->getPlayer()->y = 894; 
	_camera->cam.overviewY = true;
	_camera->getCam()->x = 0;
	_camera->getCam()->y = 481;
	// ------------------------------
	toriel = IMAGEMANAGER->addFrameImage("toriel", "image/undertale/npc/toriel.bmp", 200, 416, 4, 4, true, RGB(255, 242, 0));
	toriel->setX(CENTERX - toriel->getFrameWidth() / 2);
	toriel->setY(650);
	_torielMotion.idle = true;
	_torielMotion.walk = false;
	_torielMotion.movedown = false;
	_torielMotion.moveleft = false;
	_torielMotion.moveright = false;
	_torielMotion.moveup = false;
	
	count = 0;
	count1 = 0;
	index = 0;
	index1 = 0;

	save = RectMake(295, 400, 50, 50);
	nextdoor = RectMake(295, 70, 50, 100);

	talkcountreset = false;
	SOUNDMANAGER->stop("flowerdie");
	SOUNDMANAGER->play("stagesound", 1.f);

	return S_OK;
}

void stage3::release()
{
}

void stage3::update()
{
	textrc = RectMake(_camera->getCam()->x + 80, _camera->getCam()->y + 20, 500, 150);
	if (textnum != 0)_player->getPlayer()->control = false;
	if (textnum == 0)_player->getPlayer()->control = true;
	TextControlUpdate();
	FrameUpdate();
	EventMove();
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("stage4");
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &save) && textnum == 0)
	{
		if (_player->getPlayer()->pressZ)
		{
			if(!SOUNDMANAGER->isPlaySound("heal"))
			SOUNDMANAGER->play("heal", 1.f);
			_player->getPlayer()->CurHp = _player->getPlayer()->MaxHp;
			textnum = 1;
		}
	}

}

void stage3::render()
{
	IMAGEMANAGER->findImage("stage3")->render(getMemDC());
	IMAGEMANAGER->findImage("savestar")->frameRender(getMemDC(), 300, 400);
	if(toriel->getY() > 120)
	IMAGEMANAGER->findImage("toriel")->frameRender(getMemDC(),toriel->getX(),toriel->getY());

	if (textnum != 0)IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
	TextControl();
	if (_player->getPlayer()->viewEvery)
	{
		Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
		Rectangle(getMemDC(), save.left, save.top, save.right, save.bottom);
		char str[128];
		sprintf_s(str, "to.x : %f", toriel->getX());
		TextOut(getMemDC(), toriel->getX(), toriel->getY() - 40, str, strlen(str));
		char str1[128];
		sprintf_s(str1, "to.y : %f", toriel->getY());
		TextOut(getMemDC(), toriel->getX(), toriel->getY() - 20, str1, strlen(str1));
		char str2[128];
		sprintf_s(str2, "talkIndex : %d", _player->getPlayer()->talkindex);
		TextOut(getMemDC(), _camera->getCam()->x+200, _camera->getCam()->y +20, str2, strlen(str2));
		
	}
	
	
	
}

void stage3::FrameUpdate()
{
	if (_torielMotion.idle)
	{
		toriel->setFrameX(0);
		toriel->setFrameY(0);
	}
	if (_torielMotion.walk)
	{
		count++;
		if (count % 10 == 0)
		{
			
		   toriel->setFrameX(index);
		   index++;
		   if (index > toriel->getMaxFrameX()) index = 0;
			
		
		}

	}

	if (_torielMotion.movedown)
	{
		toriel->setFrameY(0);
	}
	if (_torielMotion.moveleft)
	{
		toriel->setFrameY(2);
	}
	if (_torielMotion.moveright)
	{
		toriel->setFrameY(3);
	}
	if (_torielMotion.moveup)
	{
		toriel->setFrameY(1);
	}
	count1++;
	if (count1 % 10 == 0)
	{
		savestar->setFrameX(index1);
		index1++;
		if (index1 > savestar->getMaxFrameX())index1 = 0;
	}
	
}

void stage3::EventMove()
{
	if (toriel->getY() > 550)
	{
		
		if (_player->getPlayer()->y < 820)
		{
			_torielMotion.idle = false;
			_torielMotion.walk = true;
			_torielMotion.moveup = true;
			toriel->setY(toriel->getY() - 2);
		}
		
	}
	else
	{
		_torielMotion.idle = true;
		_torielMotion.walk = false;
		_torielMotion.moveup = false;
	}
	if (toriel->getY() > 420)
	{
		if (_player->getPlayer()->y < 700)
		{
			_torielMotion.idle = false;
			_torielMotion.walk = true;
			_torielMotion.moveup = true;
			toriel->setY(toriel->getY() - 2);
		}
	}
	else
	{
		_torielMotion.idle = true;
		_torielMotion.walk = false;
		_torielMotion.moveup = false;
	}
	if (toriel->getY() > 370 && toriel->getX() < 380)
	{
		if (_player->getPlayer()->y < 600)
		{
			_torielMotion.idle = false;
			_torielMotion.walk = true;
			_torielMotion.moveup = true;
			toriel->setY(toriel->getY() - 2);
			toriel->setX(toriel->getX() + 2);
		}
	}
	else
	{
		_torielMotion.idle = true;
		_torielMotion.walk = false;
		_torielMotion.moveup = false;
	}
	if (toriel->getY() > 300 || toriel->getX() < 300)
	{
		if (_player->getPlayer()->y < 520)
		{
			_torielMotion.idle = false;
			_torielMotion.walk = true;
			_torielMotion.moveup = true;
			toriel->setY(toriel->getY() - 2);
			toriel->setX(toriel->getX() + 2);
		}
	}
	else
	{
		_torielMotion.idle = true;
		_torielMotion.walk = false;
		_torielMotion.moveup = false;
	}
	if (toriel->getY() > 230 || toriel->getX() < 250)
	{
		if (_player->getPlayer()->y < 430)
		{
			_torielMotion.idle = false;
			_torielMotion.walk = true;
			_torielMotion.moveup = true;
			toriel->setY(toriel->getY() - 2);
			toriel->setX(toriel->getX() + 2);
		}
	}
	else
	{
		_torielMotion.idle = true;
		_torielMotion.walk = false;
		_torielMotion.moveup = false;
	}
	if (toriel->getY() > 160 || toriel->getX() < 180)
	{
		if (_player->getPlayer()->y < 370)
		{
			_torielMotion.idle = false;
			_torielMotion.walk = true;
			_torielMotion.moveup = true;
			toriel->setY(toriel->getY() - 2);
			toriel->setX(toriel->getX() - 2);
		}
	}
	else
	{
		_torielMotion.idle = true;
		_torielMotion.walk = false;
		_torielMotion.moveup = false;
	}
	if (toriel->getX() > 300)
	{
		if (_player->getPlayer()->y < 300)
		{
			_torielMotion.idle = false;
			_torielMotion.walk = true;
			_torielMotion.moveleft = true;
			toriel->setX(toriel->getX() - 2);
		}
		if (toriel->getX() < 300)
		{
			_torielMotion.idle = false;
			_torielMotion.walk = true;
			_torielMotion.moveup = true;
			//toriel->setY(toriel->getY() - 2);
		}
	}
}

void stage3::TextControlUpdate()
{
	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 78)
				tindex++;
		}
		if (textnum == 2)
		{
			if (tindex < 29)
				tindex++;
		}
	


	}

	if (textnum == 1)
	{
		if (tindex == 78)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 78;
		}
	}
	if (textnum == 2)
	{
		if (tindex == 29)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 29;
		}
	}
	
}

void stage3::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/stage3/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/stage3/text2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

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

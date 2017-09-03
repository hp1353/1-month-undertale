#include "stdafx.h"
#include "stage13.h"
#include "player.h"
#include "camera.h"

stage13::stage13()
{
}


stage13::~stage13()
{
}

HRESULT stage13::init()
{
	_player->getPlayer()->loadstagenum = 13;
	_player->getPlayer()->dontpix = false;
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
	_player->getPlayer()->SaveStageNum = 13;
	IMAGEMANAGER->addImage("stage13", "image/undertale/stage/stage13.bmp", 1119, 480, false, false);
	stone1 = IMAGEMANAGER->addImage("stone1", "image/undertale/object/stone.bmp", 40, 36, true, RGB(255, 0, 255));
	

	stone2 = IMAGEMANAGER->addImage("stone2", "image/undertale/object/stone.bmp", 40, 36, true, RGB(255, 0, 255));
	
	
	stoneAI = IMAGEMANAGER->addImage("stoneAI", "image/undertale/object/stone.bmp", 40, 36, true, RGB(255, 0, 255));


	stage13_trap = IMAGEMANAGER->addFrameImage("stage13_trap", "image/undertale/object/stage13_trap.bmp", 160, 123, 2, 1, false, false);
	stage13_trap->setFrameX(1);
	stage13_trap->setX(760);
	stage13_trap->setY(240);
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
		_player->getPlayer()->x = 10;
		_player->getPlayer()->y = 230;
		_camera->getCam()->x = 0;
		_camera->getCam()->y = 0;
		_camera->getCam()->overviewX = true;
		_camera->getCam()->overviewY = true;
		stone1->setX(400);
		stone1->setY(195);
		stone2->setX(360);
		stone2->setY(275);
		stoneAI->setX(440);
		stoneAI->setY(358);

	}
	
	if (_player->getPlayer()->stage13clear)
	{

	}
	else
	{
		loadmark = RectMake(760, 240, 80, 120);
		switchon = false;
		tcount = 0;
		tindex = 0;
		textnum = 0;

		move1 = false;
		move2 = false;
		move3 = false;
		move4 = false;

		nextdoor = RectMake(1100, 230, 50, 50);
	}
	return S_OK;
}

void stage13::release()
{
}

void stage13::update()
{
	
	TextControlUpdate();
	textrc = RectMake(_camera->getCam()->x + 80, _camera->getCam()->y + 20, 500, 150);
	stone1rc = RectMake(stone1->getX(), stone1->getY(), stone1->getWidth(), stone1->getHeight());
	stone2rc = RectMake(stone2->getX(), stone2->getY(), stone2->getWidth(), stone2->getHeight());
	stoneAIrc = RectMake(stoneAI->getX(), stoneAI->getY(), stoneAI->getWidth(), stoneAI->getHeight());
	if (!switchon)
	{
		if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &loadmark))
		{
			_player->getPlayer()->x -= 2;
		}
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &stone1rc))
	{
		if(stone1->getX() < 555)
		stone1->setX(stone1->getX() + 2);
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &stone2rc))
	{
		if(stone2->getX() < 555)
		stone2->setX(stone2->getX() + 2);
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &stoneAIrc) && textnum == 0 && !moving)
	{
		
		if(!move1 && !move2 && !move3 && !move4) textnum = 1;
		if (move1 && !move2 && !move3 && !move4 && !moving && stoneAI->getX() >= 480) textnum = 4;
		if (move1 && move2 && !move3 && !move4 && stoneAI->getY() <= 330) textnum = 6;
		
		if (move1 && move2 && move3 && !move4 && stoneAI->getX() >= 555)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			textnum = 8;
		}
		if (move4)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			textnum = 9;
		}
		if (move5)
		{
			if (KEYMANAGER->isOnceDown('Z'))
				textnum = 11;
		}
	}
	if (textnum != 0) _player->getPlayer()->control = false;
	if (textnum == 0) _player->getPlayer()->control = true;
	if (move1 && !move2)
	{
		if (stoneAI->getX() < 480)
		{
			stoneAI->setX(stoneAI->getX() + 1);
			moving = true;
		}
		if (stoneAI->getX() >= 480) moving = false;
	}
	if (move2 && !move3)
	{
		if(stoneAI->getY() > 330)
		stoneAI->setY(stoneAI->getY() - 1);
	}
	if (move3)
	{
		if (stoneAI->getY() < 358)
			stoneAI->setY(stoneAI->getY() + 1);
		if (stoneAI->getY() >= 358 && stoneAI->getX() < 555)
		{
			stoneAI->setX(stoneAI->getX() + 1);
		}
		
	}
	if (stoneAI->getX() >= 555)
	{
		stage13_trap->setFrameX(0);
		switchon = true;
	}
	else
	{
		switchon = false;
		stage13_trap->setFrameX(1);
	}
	if (_player->getPlayer()->x > 680)
	{
		move4 = true;
		
	}
	if (move4)
	{
		if (stoneAI->getX() > 480)
			stoneAI->setX(stoneAI->getX() - 2);
	}
	if (move5)
	{
		if (stoneAI->getX() < 555)
			stoneAI->setX(stoneAI->getX() + 2);
		_player->getPlayer()->stage13clear = true;
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("stage14");
	}
}

void stage13::render()
{
	IMAGEMANAGER->findImage("stage13")->render(getMemDC());
	
	IMAGEMANAGER->findImage("stone1")->render(getMemDC(), stone1->getX(), stone1->getY());
	IMAGEMANAGER->findImage("stone2")->render(getMemDC(), stone2->getX(), stone2->getY());
	IMAGEMANAGER->findImage("stoneAI")->render(getMemDC(), stoneAI->getX(), stoneAI->getY());
	IMAGEMANAGER->findImage("stage13_trap")->frameRender(getMemDC(), stage13_trap->getX(), stage13_trap->getY());

	if(textnum != 0) IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
	TextControl();
	if (_player->getPlayer()->viewEvery)
	{
		Rectangle(getMemDC(), loadmark.left, loadmark.top, loadmark.right, loadmark.bottom);
	}
	else
	{

	}
}

void stage13::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																										  //폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/stage13/stone1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/stage13/stone2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("text/stage13/stone3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 4)
		hInputFile = CreateFile(_T("text/stage13/stone4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 5)
		hInputFile = CreateFile(_T("text/stage13/stone5.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 6)
		hInputFile = CreateFile(_T("text/stage13/stone6.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 7)
		hInputFile = CreateFile(_T("text/stage13/stone7.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 8)
		hInputFile = CreateFile(_T("text/stage13/stone8.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 9)
		hInputFile = CreateFile(_T("text/stage13/stone9.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 10)
		hInputFile = CreateFile(_T("text/stage13/stone10.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 11)
		hInputFile = CreateFile(_T("text/stage13/stone11.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

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

void stage13::TextControlUpdate()
{
	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 46)
				tindex++;
		}
		if (textnum == 2)
		{
			if (tindex < 45)
				tindex++;
		}
		if (textnum == 3)
		{
			if (tindex < 36)
				tindex++;
		}
		if (textnum == 4)
		{
			if (tindex < 31)
				tindex++;
		}
		if (textnum == 5)
		{
			if (tindex < 20)
				tindex++;
		}
		if (textnum == 6)
		{
			if (tindex < 28)
				tindex++;
		}
		if (textnum == 7)
		{
			if (tindex < 20)
				tindex++;
		}
		if (textnum == 8)
		{
			if (tindex < 15)
				tindex++;
		}
		if (textnum == 9)
		{
			if (tindex < 35)
				tindex++;
		}
		if (textnum == 10)
		{
			if (tindex < 32)
				tindex++;
		}
		if (textnum == 11)
		{
			if (tindex < 31)
				tindex++;
		}
		

	}

	if (textnum == 1)
	{
		if (tindex == 46)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 46;
		}
	}
	if (textnum == 2)
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
	if (textnum == 3)
	{
		if (tindex == 36)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				move1 = true;
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 36;
		}
	}
	if (textnum == 4)
	{
		if (tindex == 31)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 31;
		}
	}
	if (textnum == 5)
	{
		
		if (tindex == 20)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				move2 = true;
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 20;
		}
	}
	if (textnum == 6)
	{
		if (tindex == 28)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 28;
		}
	}
	if (textnum == 7)
	{
		if (tindex == 20)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				move3 = true;
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 20;
		}
	}
	if (textnum == 8)
	{
		if (tindex == 15)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 15;
		}
	}
	if (textnum == 9)
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
	if (textnum == 10)
	{
		if (tindex == 32)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				move5 = true;
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 32;
		}
	}
	if (textnum == 11)
	{
		if (tindex == 31)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 31;
		}
	}
	

}

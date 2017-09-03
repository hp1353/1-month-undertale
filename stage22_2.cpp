#include "stdafx.h"
#include "stage22_2.h"
#include "player.h"
#include "camera.h"

stage22_2::stage22_2()
{
}


stage22_2::~stage22_2()
{
}

HRESULT stage22_2::init()
{
	_player->getPlayer()->SaveStageNum = 1;
	IMAGEMANAGER->addImage("stage22_2", "image/undertale/stage/stage22_2.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("knife", "image/undertale/item/knife.bmp", 41, 35, false, false);
	_player->getPlayer()->x = 320;
	_player->getPlayer()->y = 400;
	_camera->getCam()->x = 0;
	_camera->getCam()->y = 0;
	_camera->getCam()->overviewX = true;
	_camera->getCam()->overviewY = true;

	backdoor = RectMake(320, 490, 50, 50);
	

	_player->getPlayer()->isstage22_2 = true;

	tcount = 0;
	tindex = 0;
	textnum = 0;
	

	return S_OK;
}

void stage22_2::release()
{
}

void stage22_2::update()
{
	TextControlUpdate();
	textrc = RectMake(_camera->getCam()->x + 80, _camera->getCam()->y + 20, 500, 150);
	if (!_player->getPlayer()->haveknife)
	knife = RectMake(80, 360, 50, 50);
	if (_player->getPlayer()->haveknife)
		knife = RectMake(0, 0, 0, 0);
	if (textnum != 0)_player->getPlayer()->control = false;
	if (textnum == 0)_player->getPlayer()->control = true;
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &backdoor))
	{
		SCENEMANAGER->changeScene("stage22_1");
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &knife))
	{
		if (_player->getPlayer()->pressZ)
		{
			textnum = 1;
		}
	}
	if (_player->getPlayer()->haveknife)
	{

	}
}

void stage22_2::render()
{
	IMAGEMANAGER->findImage("stage22_2")->render(getMemDC());
	if(!_player->getPlayer()->haveknife)
	IMAGEMANAGER->findImage("knife")->render(getMemDC(), 82, 370);

	if (textnum != 0)IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
	TextControl();

	if (_player->getPlayer()->viewEvery)
	{
		Rectangle(getMemDC(), backdoor.left, backdoor.top, backdoor.right, backdoor.bottom);
		Rectangle(getMemDC(), knife.left, knife.top, knife.right, knife.bottom);
	}
	else
	{

	}
}

void stage22_2::TextControlUpdate()
{
	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 23)
				tindex++;
		}
		


	}

	if (textnum == 1)
	{
		if (tindex == 23)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				_player->getPlayer()->haveknife = true;
				tindex = 0;
				textnum = 0;
				for (int i = 1; i < 8; i++) //아이템칸 10개
				{
					if (_player->getPlayer()->itemarr[i - 1] == 0) //비어있을때
					{
						_player->getPlayer()->itemarr[i - 1] = 4; //순서대로 아이템번호4 부여
						break;
					}
				}
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 23;
		}
	}
}

void stage22_2::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/stage22_2/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	
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

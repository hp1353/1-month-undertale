#include "stdafx.h"
#include "stage9_1.h"
#include "player.h"
#include "camera.h"


stage9_1::stage9_1()
{
}


stage9_1::~stage9_1()
{
}

HRESULT stage9_1::init()
{
	
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
	_player->getPlayer()->dontpix = false;
	_player->getPlayer()->SaveStageNum = 1;
	IMAGEMANAGER->addImage("stage9_1", "image/undertale/stage/stage9_1.bmp", 640, 480, false, false);
	stage9_1_river = IMAGEMANAGER->addFrameImage("stage9_1_river", "image/undertale/object/stage9_1_river.bmp", 192, 236, 3, 1, false, false);
	IMAGEMANAGER->addImage("fuckcandy", "image/undertale/object/fuckcandy.bmp", 92, 75, false, false);
	_player->getPlayer()->x = 300;
	_player->getPlayer()->y = 400;
	intro9 = RectMake(300, 470, 50, 50);
	candy = RectMake(290, 190, 50, 50);
	_player->getPlayer()->isstage9_1 = true;
	count = 0;
	index = 0;
	tcount = 0;
	tindex = 0;
	textnum = 0;
	yes = 0;
	no = 0;
	candynum = 0;
	talking = false;
	isfuckcandy = false;
	
	return S_OK;
}

void stage9_1::release()
{
}

void stage9_1::update()
{
	
	textrc = RectMake(_camera->getCam()->x + 80, _camera->getCam()->y + 20, 500, 150);
	shehavecandynum = _player->getPlayer()->shehavecandy;
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &intro9))
	{
		SCENEMANAGER->changeScene("stage9");
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &candy) && !talking && !_player->getPlayer()->viewInven )
	{
		if (KEYMANAGER->isOnceDown('Z') &&!_player->getPlayer()->viewInven)
		{
			
			if (_player->getPlayer()->candynum == 0) textnum = 1;
			if (_player->getPlayer()->candynum == 1) textnum = 1;
			if (_player->getPlayer()->candynum == 2) textnum = 1;
			if (_player->getPlayer()->candynum == 3) textnum = 1;
			if (_player->getPlayer()->candynum == 4) textnum = 7;
			
		}
	}
	if (tindex > 0)
	{
		talking = true;
		_player->getPlayer()->control = false;
		_player->getPlayer()->frame = false;
	}
	else
	{
		talking = false;
		_player->getPlayer()->control = true;
		_player->getPlayer()->frame = true;
	}
	riverFrame();
	TextControlUpdate();
}

void stage9_1::render()
{
	IMAGEMANAGER->findImage("stage9_1")->render(getMemDC());
	IMAGEMANAGER->findImage("stage9_1_river")->frameRender(getMemDC(), 166, 164);
	IMAGEMANAGER->findImage("stage9_1_river")->frameRender(getMemDC(), 406, 164);
	if (isfuckcandy || _player->getPlayer()->candynum == 4 || shehavecandynum == 0) IMAGEMANAGER->findImage("fuckcandy")->render(getMemDC(), 300, 180);
	if (textnum != 0)IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
	TextControl();
	if (textnum == 1 || textnum == 4 || textnum == 5 || textnum == 6)
	{
		if(tindex > 80)
		IMAGEMANAGER->findImage("heart")->render(getMemDC(), 155 + no, 110); //네
		
		if (KEYMANAGER->isOnceDown(VK_RIGHT))
		{
			no = 160; //아니
		}
		if (KEYMANAGER->isOnceDown(VK_LEFT))
		{
			no = 0; //예
		}
		
	}
	if (_player->getPlayer()->viewEvery)
	{
		SetBkMode(getMemDC(), OPAQUE);
		char str[128];
		sprintf_s(str, "textnum : %d", textnum);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y, str, strlen(str));
		char str1[128];
		sprintf_s(str1, "tindex : %d", tindex);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y + 20, str1, strlen(str1));
		char str2[128];
		sprintf_s(str2, "candynum : %d", _player->getPlayer()->candynum);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y + 40, str2, strlen(str2));
		char str3[128];
		sprintf_s(str3, "no : %d", no);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y + 60, str3, strlen(str3));
		Rectangle(getMemDC(), intro9.left, intro9.top, intro9.right, intro9.bottom);
		Rectangle(getMemDC(), candy.left, candy.top, candy.right, candy.bottom);
	}
	else
	{
		SetBkMode(getMemDC(), TRANSPARENT);
	}
}

void stage9_1::riverFrame()
{
	count++;
	if (count % 15 == 0)
	{
		stage9_1_river->setFrameX(index);
		index++;
		if (index > stage9_1_river->getMaxFrameX())index = 0;
		
	}
	
}
void stage9_1::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																										  //폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/stage9_1/stage9_1_1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/stage9_1/stage9_1_no.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("text/stage9_1/stage9_1_yes1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 4)
		hInputFile = CreateFile(_T("text/stage9_1/stage9_1_yes2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 5)
		hInputFile = CreateFile(_T("text/stage9_1/stage9_1_yes3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 6)
		hInputFile = CreateFile(_T("text/stage9_1/stage9_1_yes4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 7)
		hInputFile = CreateFile(_T("text/stage9_1/stage9_1_over.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

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

void stage9_1::TextControlUpdate()
{

	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 88)
				tindex++;
		}
		if (textnum == 2)
		{
			if (tindex < 23)
				tindex++;
		}
		if (textnum == 3)
		{
			if (tindex < 63)
				tindex++;
		}
		if (textnum == 4)
		{
			if (tindex < 45)
				tindex++;
		}
		if (textnum == 5)
		{
			if (tindex < 61)
				tindex++;
		}
		if (textnum == 6)
		{
			if (tindex < 57)
				tindex++;
		}
		if (textnum == 7)
		{
			if (tindex < 26)
				tindex++;
		}
	}

	
	if (textnum == 1)
	{
		if (tindex == 88)
		{
			
			if (KEYMANAGER->isOnceDown('Z'))
			{
				if (no == 160) //아니
				{
					tindex = 0;
					textnum = 2;
				}
				if (no == 0) //예
				{
					tindex = 0;
					if (_player->getPlayer()->candynum == 0) textnum = 3;
					if (_player->getPlayer()->candynum == 1) textnum = 4;
					if (_player->getPlayer()->candynum == 2) textnum = 5;
					if (_player->getPlayer()->candynum == 3) textnum = 6;
					
					_player->getPlayer()->candynum += 1;
					_player->getPlayer()->shehavecandy -= 1;
					for (int i = 1; i < 8; i++) //아이템칸 10개
					{
						if (_player->getPlayer()->itemarr[i - 1] == 0) //비어있을때
						{
							if (_player->getPlayer()->candynum == i) _player->getPlayer()->itemarr[i - 1] = 1; //순서대로 아이템번호1 부여
						}
					}
				}
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 88;
		}
	}
	if (textnum == 2)
	{
		if (tindex == 23)
		{

			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 23;
		}
	}
	if (textnum == 3)
	{
		if (tindex == 63)
		{

			if (KEYMANAGER->isOnceDown('Z'))
			{
				
				tindex = 0;
				textnum = 0;
				
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 63;
		}
	}
	if (textnum == 4)
	{
		if (tindex == 45)
		{

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
	if (textnum == 5)
	{
		if (tindex == 61)
		{

			if (KEYMANAGER->isOnceDown('Z'))
			{
				
				tindex = 0;
				textnum = 0;
				
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 61;
		}
	}
	if (textnum == 6)
	{
		isfuckcandy = true;
		if (tindex == 57)
		{

			if (KEYMANAGER->isOnceDown('Z'))
			{
				
					tindex = 0;
					textnum = 0;
				
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 57;
		}
	}
	if (textnum == 7)
	{
		if (tindex == 26)
		{

			if (KEYMANAGER->isOnceDown('Z'))
			{

				tindex = 0;
				textnum = 0;

			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 26;
		}
	}
}
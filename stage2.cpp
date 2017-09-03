#include "stdafx.h"
#include "stage2.h"
#include "player.h"
#include "camera.h"
stage2::stage2()
{
}


stage2::~stage2()
{
}
HRESULT stage2::init()
{
	_player->getPlayer()->SaveStageNum = 2;
	IMAGEMANAGER->addImage("flower", "image/undertale/enemy/flower.bmp", 40, 42, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("stage2", "image/undertale/stage/stage2.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("flower1", "image/undertale/event/stage2Event/flower1.bmp", 640, 170, false, false);
	IMAGEMANAGER->addImage("flower2", "image/undertale/event/stage2Event/flower2.bmp", 640, 170, false, false);
	IMAGEMANAGER->addImage("flower3", "image/undertale/event/stage2Event/flower3.bmp", 640, 170, false, false);
	IMAGEMANAGER->addImage("flower4", "image/undertale/event/stage2Event/flower4.bmp", 640, 170, false, false);
	IMAGEMANAGER->addImage("flower5", "image/undertale/event/stage2Event/flower5.bmp", 640, 170, false, false);
	IMAGEMANAGER->addImage("flower6", "image/undertale/event/stage2Event/flower6.bmp", 640, 170, false, false);
	IMAGEMANAGER->addImage("flower7", "image/undertale/event/stage2Event/flower7.bmp", 640, 170, false, false);
	flowerFrame = IMAGEMANAGER->addFrameImage("flowerFrame", "image/undertale/event/stage2Event/flowerFrame.bmp", 252, 88, 3, 1, false, false);
	IMAGEMANAGER->addImage("1-1", "image/undertale/event/stage2Event/1-1.bmp", 154, 40, false, false);
	IMAGEMANAGER->addImage("1-2", "image/undertale/event/stage2Event/1-2.bmp", 311, 40, false, false);
	IMAGEMANAGER->addImage("1-3", "image/undertale/event/stage2Event/1-3.bmp", 325, 40, false, false);
	IMAGEMANAGER->addImage("heart", "image/undertale/battle/heart.bmp", 16, 16, true, RGB(255, 0, 255));
	//_player->getPlayer()->x = CENTERX - _player->getPlayer()->image->getFrameWidth() / 2;
	//_player->getPlayer()->y = WINSIZEY - _player->getPlayer()->image->getFrameHeight();
	_player->getPlayer()->x = CENTERX - 20;
	_player->getPlayer()->y = CENTERY + 160;
	_player->getPlayer()->isUp = true;
	_player->getPlayer()->isRight = false;
	_player->getPlayer()->isLeft = false;
	_player->getPlayer()->isDown = false;
	_camera->getCam()->overviewX = false;
	_camera->getCam()->overviewY = true;
	
	Eventrc = RectMakeCenter(CENTERX, CENTERY, 300, 200);

	playevent = false;
	eventnum = 0;
	textcount = 0;
	textindex = 0;
	index = 0;
	count = 0;
	textnum = 0;
	tcount = 0;
	tindex = 0;
	for (int i = 0; i < 7; i++)
	{
		eventtext[i] = false;
	}
	return S_OK;
}

void stage2::release()
{
}

void stage2::update()
{
	textrc = RectMake(_camera->getCam()->x + 170, _camera->getCam()->y + 20, 500, 150);
	if (IntersectRect(&RectMake(0, 0, 0, 0), &Eventrc, &_player->getPlayer()->rc) && textnum == 0)
	{
		if(!SOUNDMANAGER->isPlaySound("flower1"))
		SOUNDMANAGER->play("flower1", 1.f);
		Event();
		textnum = 1;
	}
	TextControlUpdate();
	if (playevent)
	{
		textcount++;
		if (textcount % 10 == 0)
			textindex++;
		if (KEYMANAGER->isOnceDown('Z'))
		{
			eventnum++;
			textindex = 0;
		}
	}
	FrameUpdate();

	
}

void stage2::render()
{

	IMAGEMANAGER->findImage("stage2")->render(getMemDC());
	IMAGEMANAGER->findImage("flower")->render(getMemDC(), CENTERX - IMAGEMANAGER->findImage("flower")->getWidth() / 2, CENTERY - IMAGEMANAGER->findImage("flower")->getHeight() / 2 );
	if (textnum != 0)
	{


		IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
		//if (!talkend)
		{
			//IMAGEMANAGER->findImage("torielface_talk")->frameRender(getMemDC(), _camera->getCam()->x + 50, _camera->getCam()->y + 30);
		}
		//if (talkend)
			//IMAGEMANAGER->findImage("torielface_1")->frameRender(getMemDC(), _camera->getCam()->x + 48, _camera->getCam()->y + 34);


	}
	TextControl();
	if (KEYMANAGER->isToggle('1'))
	{
		Rectangle(getMemDC(), Eventrc.left, Eventrc.top, Eventrc.right, Eventrc.bottom);
		char str[128];
		sprintf_s(str, "eventNum : %d", eventnum);
		TextOut(getMemDC(), 0, 180, str, strlen(str));

		char str1[128];
		sprintf_s(str1, "textindex : %d", textindex);
		TextOut(getMemDC(), 0, 200, str1, strlen(str1));

	}

	EventRender();


}

void stage2::Event()
{
	
	_player->getPlayer()->frameReset = true;
	_player->getPlayer()->control = false;
	playevent = true;
	

}

void stage2::EventRender()
{
	if (playevent && eventnum < 7)
	{
		
		if (eventnum == 0)
		{
			if (textindex > 35) eventtext[0] = false;
			else eventtext[0] = true;
			//IMAGEMANAGER->findImage("flower1")->render(getMemDC(),0,50);

		}
		/*if (eventnum == 1)
			IMAGEMANAGER->findImage("flower2")->render(getMemDC(),0,50);
		if (eventnum == 2)
			IMAGEMANAGER->findImage("flower3")->render(getMemDC(), 0, 50);
		if (eventnum == 3)
			IMAGEMANAGER->findImage("flower4")->render(getMemDC(), 0, 50);
		if (eventnum == 4)
			IMAGEMANAGER->findImage("flower5")->render(getMemDC(), 0, 50);
		if (eventnum == 5)
			IMAGEMANAGER->findImage("flower6")->render(getMemDC(), 0, 50);
		if (eventnum == 6)
			IMAGEMANAGER->findImage("flower7")->render(getMemDC(), 0, 50);
*/
		IMAGEMANAGER->findImage("flowerFrame")->frameRender(getMemDC(), 62, 82);

	}
}

void stage2::FrameUpdate()
{

	if (playevent)
	{

		count++;
		if (textnum == 5)
		{
			flowerFrame->setFrameX(2);
		}
		else if (count % 10 == 0 && !talkend)
		{
			if (index > flowerFrame->getMaxFrameX() - 2) index = 0;
			else index++;
			flowerFrame->setFrameX(index);


		}


	}
}

void stage2::TextControlUpdate()
{
	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 52)
			{
				talkend = false;
				tindex++;
			}
		}
		if (textnum == 2)
		{
			if (tindex < 9)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 3)
		{
			if (tindex < 50)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 4)
		{
			if (tindex < 27)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 5)
		{
			if (tindex < 46)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 6)
		{
			if (tindex < 37)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 7)
		{
			if (tindex < 21)
			{
				tindex++;
				talkend = false;
			}
		}



	}

	if (textnum == 1)
	{
		if (tindex == 52)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{

				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 52;
		}
	}
	if (textnum == 2)
	{
		if (tindex == 9)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{

				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 9;
		}
	}
	if (textnum == 3)
	{
		if (tindex == 50)
		{
			talkend = true;
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
	if (textnum == 4)
	{

		if (tindex == 27)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 27;
		}
	}
	if (textnum == 5)
	{
		if (tindex == 46)
		{
			talkend = true;
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
	if (textnum == 6)
	{
		if (tindex == 37)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 37;
		}
	}
	if (textnum == 7)
	{
		if (tindex == 21)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
				_player->getPlayer()->control = true;
				_player->getPlayer()->frame = true;
				_player->getPlayer()->changebattle = true;
				SCENEMANAGER->changeScene("battle1");
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 21;
		}
	}

}

void stage2::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/stage2/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/stage2/text2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("text/stage2/text3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 4)
		hInputFile = CreateFile(_T("text/stage2/text4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 5)
		hInputFile = CreateFile(_T("text/stage2/text5.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 6)
		hInputFile = CreateFile(_T("text/stage2/text6.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 7)
		hInputFile = CreateFile(_T("text/stage2/text7.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

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

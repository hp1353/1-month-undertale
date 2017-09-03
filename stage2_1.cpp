#include "stdafx.h"
#include "stage2_1.h"
#include "camera.h"
#include "player.h"


stage2_1::stage2_1()
{
}


stage2_1::~stage2_1()
{
}

HRESULT stage2_1::init()
{
	_player->getPlayer()->SaveStageNum = 2;
	torielface_1 = IMAGEMANAGER->addFrameImage("torielface_1", "image/undertale/npc/torielface_0.bmp", 288, 88, 3, 1, false, false);
	torielface_talk = IMAGEMANAGER->addFrameImage("torielface_talk", "image/undertale/npc/torielface_talk.bmp", 192, 88, 2, 1, false, false);

	IMAGEMANAGER->addImage("stage2_1", "image/undertale/stage/stage2_1.bmp", 640, 740, false, false);
	toriel_speak = IMAGEMANAGER->addFrameImage("toriel_speak", "image/undertale/npc/toriel_speak.bmp", 100, 103, 2, 1, true, RGB(255, 242, 0));
	IMAGEMANAGER->addImage("to1", "image/undertale/event/stage2Event/to1.bmp", 578, 152, false, false);
	toriel = IMAGEMANAGER->addFrameImage("toriel", "image/undertale/npc/toriel.bmp", 200, 416, 4, 4, true, RGB(255, 0, 255));
	toriel->setX(CENTERX - toriel_speak->getFrameWidth() / 2);
	toriel->setY(CENTERY - toriel_speak->getFrameHeight() / 2 + 220);
	_player->getPlayer()->isUp = true;
	_player->getPlayer()->isRight = false;
	_player->getPlayer()->isLeft = false;
	_player->getPlayer()->isDown = false;
	_player->getPlayer()->battleScene = false;
	_player->getPlayer()->changebattle = false;
	//_player->getPlayer()->changeScene = true;
	_camera->getCam()->overviewX = false;
	_camera->getCam()->overviewY = true;
	_player->getPlayer()->x = CENTERX - _player->getPlayer()->image->getFrameWidth() / 2;
	_player->getPlayer()->y = 640;
	_camera->getCam()->y = 250;
	chat = false;
	count = 0;
	index = 0;
	tcount = 0;
	tindex = 0;
	textnum = 1;
	index1 = 0;
	count1 = 0;
	move = false;
	
	nextdoor = RectMake(CENTERX-50, 100, 100, 100);

	
	return S_OK;
}

void stage2_1::release()
{
}

void stage2_1::update()
{
	_player->getPlayer()->playertor = false;
	_player->getPlayer()->battleScene = false;
	_player->getPlayer()->battleend = false;
	_player->getPlayer()->walkcount = 0;
	_player->getPlayer()->control = true;
	_player->getPlayer()->dontpix = false;
	_player->getPlayer()->changeindex = 0;
	textrc = RectMake(_camera->getCam()->x + 170, _camera->getCam()->y + 20, 500, 150);
	TextControlUpdate();
	if (textnum != 0)_player->getPlayer()->control = false;
	if (textnum == 0)_player->getPlayer()->control = true;
	
	count++;
	toriel_speak->setFrameX(index);
	if (count % 10 == 0)index++;
	if (toriel_speak->getMaxFrameX() < index)index = 0;
	
	if (move)
	{
		toriel->setY(toriel->getY() - 2);
		toriel->setFrameY(1);
		count1++;
		toriel->setFrameX(index1);
		if (count1 % 10 == 0)index1++;
		if (toriel->getMaxFrameX() < index1)index1 = 0;
	}
	
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
		SCENEMANAGER->changeScene("stage3");
}

void stage2_1::render()
{
	IMAGEMANAGER->findImage("stage2_1")->render(getMemDC());
	if (textnum != 0)
	{
		IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
		if (!talkend)
		{
			IMAGEMANAGER->findImage("torielface_talk")->frameRender(getMemDC(), _camera->getCam()->x + 50, _camera->getCam()->y + 30);
		}
		if (talkend)
			IMAGEMANAGER->findImage("torielface_1")->frameRender(getMemDC(), _camera->getCam()->x + 48, _camera->getCam()->y + 34);

	}
	TextControl();
	if (!chat)
	{
		IMAGEMANAGER->findImage("toriel_speak")->frameRender(getMemDC(), CENTERX - toriel_speak->getFrameWidth() / 2, CENTERY - toriel_speak->getFrameHeight() / 2 + 220);
		//IMAGEMANAGER->findImage("to1")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
	}
	if(chat && toriel->getY() > 100)
	IMAGEMANAGER->findImage("toriel")->frameRender(getMemDC(), toriel->getX(), toriel->getY());

	if (_player->getPlayer()->viewEvery)
	{
		Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
	}
}

void stage2_1::TextControlUpdate()
{
	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 13)
			{
				talkend = false;
				tindex++;
			}
		}
		



	}

	if (textnum == 1)
	{
		if (tindex == 13)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				move = true;
				chat = true;
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 13;
		}
	}
}

void stage2_1::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/stage2_1/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	
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

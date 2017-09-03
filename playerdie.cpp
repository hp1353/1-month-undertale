#include "stdafx.h"
#include "playerdie.h"
#include "player.h"
#include "camera.h"

playerdie::playerdie()
{
}


playerdie::~playerdie()
{
}

HRESULT playerdie::init()
{
	_player->getPlayer()->control = false;

	once = false;
	//IMAGEMANAGER->addImage("torielheart", "image/undertale/battle/torielbattle/torielheart.bmp", 16, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("playerdieheartbreak", "image/undertale/battle/playerdie/playerdieheartbreak.bmp", 20, 17, false, false);
	alpha = 100;
	heartx = 0;
	hearty = 0;
	heartxcount = 0;
	heartycount = 0;
	once2 = false;
	once3 = false;
	playerheartbreakframe = IMAGEMANAGER->addFrameImage("playerdieheartbreakframe", "image/undertale/battle/playerdie/playerdieheartbreakframe.bmp", 28, 8, 4, 1, true, RGB(255, 0, 255));
	playerheartbreakframe2 = IMAGEMANAGER->addFrameImage("playerdieheartbreakframe2", "image/undertale/battle/playerdie/playerdieheartbreakframe.bmp", 28, 8, 4, 1, true, RGB(255, 0, 255));
	playerheartbreakframe3 = IMAGEMANAGER->addFrameImage("playerdieheartbreakframe3", "image/undertale/battle/playerdie/playerdieheartbreakframe.bmp", 28, 8, 4, 1, true, RGB(255, 0, 255));
	playerheartbreakframe4 = IMAGEMANAGER->addFrameImage("playerdieheartbreakframe4", "image/undertale/battle/playerdie/playerdieheartbreakframe.bmp", 28, 8, 4, 1, true, RGB(255, 0, 255));
	playerheartbreakframe5 = IMAGEMANAGER->addFrameImage("playerdieheartbreakframe5", "image/undertale/battle/playerdie/playerdieheartbreakframe.bmp", 28, 8, 4, 1, true, RGB(255, 0, 255));

	count = 0;
	index = 0;

	break1x = 0.f;
	break2x = 0.f;
	break3x = 0.f;
	break4x = 0.f;
	break5x = 0.f;
	breaky = 0.f;
	breakynum = 0.f;

	break1y = 0.f;
	break2y = 0.f;
	break3y = 0.f;
	break4y = 0.f;
	break5y = 0.f;

	bugfixcount = 0;
	heartbreak = false;
	play = false;
	soundcount = 0;

	_player->getPlayer()->playertor = true;
	gameover = false;
	alpha2 = 0;
	tcount = 0;
	tindex = 0;
	textnum = 0;
	over = false;
	textrc = RectMake(200, 300, 400, 200);

	IMAGEMANAGER->addImage("gameover", "image/undertale/battle/playerdie/gameover.bmp", 422, 182, false, false);
	return S_OK;
}

void playerdie::release()
{
}

void playerdie::update()
{
	TextControlUpdate();
	if (SOUNDMANAGER->isPlaySound("boss"))
	{
		SOUNDMANAGER->stop("boss");
	}
	if (SOUNDMANAGER->isPlaySound("stagesound"))
	{
		SOUNDMANAGER->stop("stagesound");
	}
	if (SOUNDMANAGER->isPlaySound("alldie"))
	{
		SOUNDMANAGER->stop("alldie");
	}
	if (SOUNDMANAGER->isPlaySound("midbosssound"))
	{
		SOUNDMANAGER->stop("midbosssound");
	}
	if (SOUNDMANAGER->isPlaySound("battlesound"))
	{
		SOUNDMANAGER->stop("battlesound");
	}
	_camera->getCam()->x = 0;
	_camera->getCam()->y = 0;
	
		//alpha++;
		if (alpha > 250)
		{
			heartx = 0;
			hearty = 0;
			heartbreak = true;
		}
		else
		{
			heartxcount++;
			heartycount++;
			if (heartxcount % 4 == 0)
				heartx = 2;
			if (heartxcount % 4 == 1)
				heartx = -2;
			if (heartycount % 5 == 0)
				hearty = -2;
			if (heartycount % 5 == 1)
				hearty = 2;

			alpha++;
		}
	
	if (heartbreak)
	{
		bugfixcount++;
		if (!SOUNDMANAGER->isPlaySound("heartbreak") && !once2)
		{

			SOUNDMANAGER->play("heartbreak", 1.f);
			once2 = true;
		}
		if (once2)
		{
			soundcount++;
		}
		if (soundcount > 50 && !once3)
		{
			SOUNDMANAGER->play("heartbreak2", 1.f);
			once3 = true;
		}
		if (bugfixcount > 50)once3 = true;
	}
	if (once3)
	{
		playerheartbreakframe->setFrameX(index);
		playerheartbreakframe2->setFrameX(index);
		playerheartbreakframe3->setFrameX(index);
		playerheartbreakframe4->setFrameX(index);
		playerheartbreakframe5->setFrameX(index);
		count++;

		if (index > playerheartbreakframe->getMaxFrameX())
		{
			index = 0;
		}
		else if (count % 5 == 0)index++;

		if (breakynum < 3.f)
			breakynum += 0.1f;
		breaky += breakynum;
		break1x += 2;
		break2x += 3;
		break3x -= 2;
		break4x -= 3;
		break5x -= 1;
		break1y += 0.5f;
		break2y -= 1.4f;
		break3y += 0.2f;
		break4y -= 0.7f;
		break5y += 2.2f;

		if (158 + breaky + break2y > 480)
		{
			gameover = true;
			_player->getPlayer()->CurHp = _player->getPlayer()->MaxHp;
			
		}
		if (gameover && !over)
		{
			if (!SOUNDMANAGER->isPlaySound("deadsound"))
			{
				SOUNDMANAGER->play("deadsound", 1.f);
			}
			if(alpha2 < 250)
			alpha2++;
		}
		if (alpha2 > 240 && textnum == 0 && !over)
		{
			textnum = 1;
		}
		if (over)
		{
			alpha2 -= 2;
			if (alpha2 < 10)
			{
				SOUNDMANAGER->stop("deadsound");
				_player->getPlayer()->control = true;
				_player->getPlayer()->playertor = false;
				_player->getPlayer()->battleScene = false;
				_player->getPlayer()->changeindex = 0;
				_player->getPlayer()->dontpix = false;
				if(_player->getPlayer()->loadstagenum == 100)
				SCENEMANAGER->changeScene("torielgarden");
				else if (_player->getPlayer()->loadstagenum == 50 || _player->getPlayer()->loadstagenum > 14)
					SCENEMANAGER->changeScene("stage14");
				else
				{
					if(_player->getPlayer()->loadstagenum < 14)
						SCENEMANAGER->changeScene("stage9");
				}
			}
		}
	}
}

void playerdie::render()
{
	IMAGEMANAGER->findImage("dark")->render(getMemDC(), _camera->getCam()->x, _camera->getCam()->y);

	//IMAGEMANAGER->findImage("heart")->render(getMemDC(), _player->getPlayer()->x, _player->getPlayer()->y);
	if (!heartbreak)
		IMAGEMANAGER->findImage("heart")->alphaRender(getMemDC(), _player->getPlayer()->x + heartx, _player->getPlayer()->y + hearty, alpha);
	if (heartbreak && !once3)
		IMAGEMANAGER->findImage("playerdieheartbreak")->render(getMemDC(), _player->getPlayer()->x, _player->getPlayer()->y);
	if (once3)
	{
		IMAGEMANAGER->findImage("playerdieheartbreakframe")->frameRender(getMemDC(), _player->getPlayer()->x + break1x,  _player->getPlayer()->y + breaky + break1y);
		IMAGEMANAGER->findImage("playerdieheartbreakframe2")->frameRender(getMemDC(),_player->getPlayer()->x + break2x,  _player->getPlayer()->y + breaky + break2y);
		IMAGEMANAGER->findImage("playerdieheartbreakframe3")->frameRender(getMemDC(),_player->getPlayer()->x + break3x,  _player->getPlayer()->y + breaky + break3y);
		IMAGEMANAGER->findImage("playerdieheartbreakframe4")->frameRender(getMemDC(),_player->getPlayer()->x + break4x,  _player->getPlayer()->y + breaky + break4y);
		IMAGEMANAGER->findImage("playerdieheartbreakframe5")->frameRender(getMemDC(),_player->getPlayer()->x + break5x,  _player->getPlayer()->y + breaky + break5y);
	}

	if (gameover)
	{
		IMAGEMANAGER->findImage("gameover")->alphaRender(getMemDC(), 120, 20, alpha2);
	}
	TextControl();

}

void playerdie::TextControlUpdate()
{
	tcount++;
	if (tcount % 5 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 48)
				tindex++;
		}
		if (textnum == 2)
		{
			if (tindex < 24)
				tindex++;
		}
		


	}

	if (textnum == 1)
	{
		if (tindex == 48)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		
	}
	if (textnum == 2)
	{
		if (tindex == 24)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
				over = true;
			}
		}
		
	}
	
}

void playerdie::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/playerdie/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/playerdie/text2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	
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

#include "stdafx.h"
#include "stage7.h"
#include "camera.h"
#include "player.h"
#include "stage3.h"

stage7::stage7()
{
}


stage7::~stage7()
{
}

HRESULT stage7::init()
{
	if (!SOUNDMANAGER->isPauseSound("stagesound"))
	{
		SOUNDMANAGER->resume("stagesound");
	}
	_player->getPlayer()->SaveStageNum = 7;
	IMAGEMANAGER->addImage("stage7", "image/undertale/stage/stage7.bmp", 2411, 480, false, false);
	torplus = IMAGEMANAGER->addFrameImage("player+", "image/undertale/player/player+tor.bmp", 352, 424, 4, 4, true, RGB(255, 0, 255));
	_player->getPlayer()->playertor = false;
	_player->getPlayer()->ischangebattle = false;
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			traprc[i][j] = RectMake(1691 + i * 40, 201 + j * 40, 40, 40);

		}
	}
	{

		trap[0][0] = IMAGEMANAGER->addFrameImage("trap3-1", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[1][0] = IMAGEMANAGER->addFrameImage("trap3-2", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[2][0] = IMAGEMANAGER->addFrameImage("trap3-3", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[3][0] = IMAGEMANAGER->addFrameImage("trap3-4", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[4][0] = IMAGEMANAGER->addFrameImage("trap3-5", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[5][0] = IMAGEMANAGER->addFrameImage("trap3-6", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[6][0] = IMAGEMANAGER->addFrameImage("trap3-7", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[7][0] = IMAGEMANAGER->addFrameImage("trap3-8", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[8][0] = IMAGEMANAGER->addFrameImage("trap3-9", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[9][0] = IMAGEMANAGER->addFrameImage("trap3-10", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[10][0] = IMAGEMANAGER->addFrameImage("trap3-11", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[11][0] = IMAGEMANAGER->addFrameImage("trap3-12", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[12][0] = IMAGEMANAGER->addFrameImage("trap3-13", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[13][0] = IMAGEMANAGER->addFrameImage("trap3-14", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);

		trap[0][1] = IMAGEMANAGER->addFrameImage("trap3-15", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[1][1] = IMAGEMANAGER->addFrameImage("trap3-16", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[2][1] = IMAGEMANAGER->addFrameImage("trap3-17", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[3][1] = IMAGEMANAGER->addFrameImage("trap3-18", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[4][1] = IMAGEMANAGER->addFrameImage("trap3-19", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[5][1] = IMAGEMANAGER->addFrameImage("trap3-20", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[6][1] = IMAGEMANAGER->addFrameImage("trap3-21", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[7][1] = IMAGEMANAGER->addFrameImage("trap3-22", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[8][1] = IMAGEMANAGER->addFrameImage("trap3-23", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[9][1] = IMAGEMANAGER->addFrameImage("trap3-24", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[10][1] = IMAGEMANAGER->addFrameImage("trap3-25", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[11][1] = IMAGEMANAGER->addFrameImage("trap3-26", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[12][1] = IMAGEMANAGER->addFrameImage("trap3-27", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[13][1] = IMAGEMANAGER->addFrameImage("trap3-28", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);

		trap[0][2] = IMAGEMANAGER->addFrameImage("trap3-29", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[1][2] = IMAGEMANAGER->addFrameImage("trap3-30", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[2][2] = IMAGEMANAGER->addFrameImage("trap3-31", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[3][2] = IMAGEMANAGER->addFrameImage("trap3-32", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[4][2] = IMAGEMANAGER->addFrameImage("trap3-33", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[5][2] = IMAGEMANAGER->addFrameImage("trap3-34", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[6][2] = IMAGEMANAGER->addFrameImage("trap3-35", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[7][2] = IMAGEMANAGER->addFrameImage("trap3-36", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[8][2] = IMAGEMANAGER->addFrameImage("trap3-37", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[9][2] = IMAGEMANAGER->addFrameImage("trap3-38", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[10][2] = IMAGEMANAGER->addFrameImage("trap3-39", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[11][2] = IMAGEMANAGER->addFrameImage("trap3-40", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[12][2] = IMAGEMANAGER->addFrameImage("trap3-41", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[13][2] = IMAGEMANAGER->addFrameImage("trap3-42", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);

		trap[0][3] = IMAGEMANAGER->addFrameImage("trap3-43", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[1][3] = IMAGEMANAGER->addFrameImage("trap3-44", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[2][3] = IMAGEMANAGER->addFrameImage("trap3-45", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[3][3] = IMAGEMANAGER->addFrameImage("trap3-46", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[4][3] = IMAGEMANAGER->addFrameImage("trap3-47", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[5][3] = IMAGEMANAGER->addFrameImage("trap3-48", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[6][3] = IMAGEMANAGER->addFrameImage("trap3-49", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[7][3] = IMAGEMANAGER->addFrameImage("trap3-50", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[8][3] = IMAGEMANAGER->addFrameImage("trap3-51", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[9][3] = IMAGEMANAGER->addFrameImage("trap3-52", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[10][3] = IMAGEMANAGER->addFrameImage("trap3-53", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[11][3] = IMAGEMANAGER->addFrameImage("trap3-54", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[12][3] = IMAGEMANAGER->addFrameImage("trap3-55", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);
		trap[13][3] = IMAGEMANAGER->addFrameImage("trap3-56", "image/undertale/object/trap3.bmp", 80, 40, 2, 1, false, false);

	}

	toriel = IMAGEMANAGER->addFrameImage("toriel", "image/undertale/npc/toriel.bmp", 200, 416, 4, 4, true, RGB(255, 242, 0));

	toriel->setFrameX(0);
	toriel->setFrameY(0);

	if (_player->getPlayer()->stage7return)
	{
		_player->getPlayer()->x = _player->getPlayer()->SaveX;
		_player->getPlayer()->y = _player->getPlayer()->SaveY;
		_player->getPlayer()->changebattle = false;
		_player->getPlayer()->battleScene = false;
		//_player->getPlayer()->changeScene = true;
		introbattle = RectMake(0, 0, 0, 0);
		_camera->getCam()->cameramove = true;
		textnum = 2;
		_player->getPlayer()->playertor = false;
		_player->getPlayer()->changeScene = true;
		if (SOUNDMANAGER->isPauseSound("stagesound"))
		{
			SOUNDMANAGER->resume("stagesound");

		}
		
		if (SOUNDMANAGER->isPlaySound("dummy"))
		{
			SOUNDMANAGER->stop("dummy");
		}
		//_player->getPlayer()->ischangebattle = false;
		//toriel->setX(CENTERX - toriel->getFrameWidth() / 2 + 100);
		//toriel->setY(200);
	}
	else
	{
		if (!SOUNDMANAGER->isPlaySound("stagesound"))
		{
			SOUNDMANAGER->play("stagesound", 1.f);
		}
		_camera->getCam()->x = 0;
		_camera->getCam()->y = 0;
		_camera->getCam()->overviewY = true;
		_player->getPlayer()->x = 320;
		_player->getPlayer()->y = 400;
		_player->getPlayer()->isUp = true;
		_player->getPlayer()->isDown = false;
		introbattle = RectMake(980, 300, 50, 50);
		textnum = 0;
		toriel->setX(CENTERX - toriel->getFrameWidth() / 2 + 100);
		toriel->setY(200);
	}

	
	
	_stage3->_torielMotion.idle = true;
	_stage3->_torielMotion.walk = false;
	_stage3->_torielMotion.moveup = false;
	
	

	tcount = 0;
	tindex = 0;
	
	count = 0;
	index = 0;
	
	count1 = 0;
	index1 = 0;


	isfirstevent = false;
	islastevent = false;

	loadmark = RectMake(1620, 300, 70, 70);

	_torielplus.idle = true;
	_torielplus.walk = false;
	_torielplus.moveright = false;
	_torielplus.movedown = false;
	_torielplus.moveup = false;
	_torielplus.moveleft = false;

	torplus->setFrameY(2);

	for (int i = 0; i < 6; i++)
	{
		move[i] = false;
	}
	lastmove = false;
	nextdoor = RectMake(2400, 200, 50, 50);

	
	ischange = false;
	count2 = 0;
	
	return S_OK;
}
void stage7::release()
{

}
void stage7::update()
{
	
	textrc = RectMake(_camera->getCam()->x + 200, _camera->getCam()->y + 20, 400, 150);
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->bottomrc, &traprc[i][j]))
			{
				trap[i][j]->setFrameX(1);
			}
		
			else if (IntersectRect(&RectMake(0, 0, 0, 0), &bottomrc, &traprc[i][j]))
			{
				trap[i][j]->setFrameX(1);
			}
			else
			{
				trap[i][j]->setFrameX(0);
			}

		}
	}
	TextControlUpdate();
	torielFrame();
	if (textnum < 2)
	{
		_player->getPlayer()->control = false;
	}
	else if (textnum >= 2)
	{
		_player->getPlayer()->control = true;
		
		if (!isfirstevent)
		{
			if (_player->getPlayer()->x + 150 > toriel->getX() && toriel->getX() < 980) //첫번쨰 토리엘 움직임
			{
				toriel->setX(toriel->getX() + 2);
				_stage3->_torielMotion.walk = true;
				_stage3->_torielMotion.idle = false;
				_stage3->_torielMotion.moveright = true;
			}
			else if (_player->getPlayer()->x + 150 < toriel->getX())
			{
				_stage3->_torielMotion.walk = false;
				_stage3->_torielMotion.idle = true;
				_stage3->_torielMotion.moveright = false;
				toriel->setFrameY(2);
			}
			if (_player->getPlayer()->x + 150 > toriel->getX() && toriel->getY() < 250 && toriel->getX() > 980)
			{
				toriel->setY(toriel->getY() + 2);
				_stage3->_torielMotion.walk = true;
				_stage3->_torielMotion.idle = false;
				_stage3->_torielMotion.movedown = true;
			}
			if (_player->getPlayer()->x + 150 > toriel->getX() && toriel->getY() >= 250 && toriel->getX() > 980 && toriel->getX() < 1640)
			{
				toriel->setX(toriel->getX() + 2);
				_stage3->_torielMotion.movedown = false;
				_stage3->_torielMotion.walk = true;
				_stage3->_torielMotion.idle = false;
				_stage3->_torielMotion.moveright = true;
			}
		}
		if (toriel->getX() >= 1640)
		{
			//isfirstevent = true;
			_stage3->_torielMotion.walk = false;
			_stage3->_torielMotion.idle = true;
			_stage3->_torielMotion.moveright = false;
			toriel->setFrameY(2);
		}

		
	}
	bottomrc = RectMake(toriel->getX(), toriel->getY()+ 65, 50, 50);
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &loadmark))
	{
		if (_player->getPlayer()->pressZ) isfirstevent = true;

		if (_player->getPlayer()->rc.right - 30 > loadmark.left) //길막
		{
			_player->getPlayer()->x -= 2;
		}
	}
	if (!islastevent && textnum > 3) // 합체
	{
		_player->getPlayer()->changeScene = false;
		if (!lastmove)
		{
			_player->getPlayer()->control = false;
			_player->getPlayer()->playertor = true;
			_torielplus.walk = true;
			_torielplus.moveright = true;
			_torielplus.idle = false;
			_player->getPlayer()->x = toriel->getX();
			_player->getPlayer()->y = toriel->getY();
			if (_player->getPlayer()->x < 1820)
				toriel->setX(toriel->getX() + 1); // 첫번째움직임
			if (_player->getPlayer()->x >= 1820 && _player->getPlayer()->y > 150 && !move[0])
			{
				toriel->setY(toriel->getY() - 1);
				torplus->setFrameY(3);
			}
			if (_player->getPlayer()->y <= 150 && _player->getPlayer()->x < 1900 && !move[1])
			{
				move[0] = true;
				toriel->setX(toriel->getX() + 1);
				torplus->setFrameY(2);
			}

			if (_player->getPlayer()->x >= 1900 && _player->getPlayer()->y < 220 && !move[2])
			{
				move[1] = true;
				toriel->setY(toriel->getY() + 1);
				torplus->setFrameY(0);
			}

			if (_player->getPlayer()->y >= 220 && _player->getPlayer()->x < 2090 && !move[3] && move[0] && move[1])
			{
				move[2] = true;
				toriel->setX(toriel->getX() + 1);
				torplus->setFrameY(2);
			}

			if (_player->getPlayer()->x >= 2090 && _player->getPlayer()->y > 150 && !move[4] && move[2])
			{
				move[3] = true;
				toriel->setY(toriel->getY() - 1);
				torplus->setFrameY(3);
			}

			if (_player->getPlayer()->y <= 150 && _player->getPlayer()->x < 2270 && move[3])
			{
				move[4] = true;
				toriel->setX(toriel->getX() + 1);
				torplus->setFrameY(2);
			}
		}
		if (_player->getPlayer()->x >= 2270 && !lastmove)
		{
			_torielplus.idle = true;
			_torielplus.walk = false;
			_player->getPlayer()->playertor = false;
			_player->getPlayer()->changeScene = true;
			_player->getPlayer()->control = true;
			_player->getPlayer()->x = 2250;
			_player->getPlayer()->y = 190;
			toriel->setX(2300);
			lastmove = true;
			islastevent = true;
		}
	}

	if (islastevent && textnum >= 5)
	{
		_stage3->_torielMotion.moveright = true;
		_stage3->_torielMotion.moveleft = false;
		toriel->setFrameY(3);
         toriel->setX(toriel->getX() + 2);
		_stage3->_torielMotion.walk = true;
		_stage3->_torielMotion.idle = false;
		_player->getPlayer()->control = true;
	}
	if (textnum < 2 || isfirstevent && textnum < 4 || islastevent && textnum < 5)
		_player->getPlayer()->control = false;

	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("stage8");
	}
	entryBattle();
	

}
void stage7::render()
{
	IMAGEMANAGER->findImage("stage7")->render(getMemDC());
	traprender();
	if(!_player->getPlayer()->playertor && toriel->getX() < 2500)
	IMAGEMANAGER->findImage("toriel")->frameRender(getMemDC(), toriel->getX(), toriel->getY());
	else
	{
		IMAGEMANAGER->findImage("player+")->frameRender(getMemDC(), toriel->getX() - 10, toriel->getY());
	}
	if (textnum < 2 || isfirstevent && textnum < 4 || islastevent && textnum < 5 )
	{
		IMAGEMANAGER->findImage("textnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
		_player->getPlayer()->control = false;
	}
	
	TextControl();
	if (isfirstevent)TextControl2();
	if (islastevent)TextControl3();

	if (_player->getPlayer()->changebattle || ischange)
	{
		PatBlt(getMemDC(), _camera->getCam()->x, _camera->getCam()->y, WINSIZEX, WINSIZEY, BLACKNESS);

	}
	if (_player->getPlayer()->viewEvery)
	{
		SetBkMode(getMemDC(), OPAQUE); //문자열 배경색 출력되게
		for (int i = 0; i < 14; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Rectangle(getMemDC(), traprc[i][j].left, traprc[i][j].top, traprc[i][j].right, traprc[i][j].bottom);
			}
		}
		char str[128];
		sprintf_s(str, "textnum : %d", textnum);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y, str, strlen(str));
		char str1[128];
		sprintf_s(str1, "tindex : %d", tindex);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y + 20, str1, strlen(str1));
		Rectangle(getMemDC(), loadmark.left, loadmark.top, loadmark.right, loadmark.bottom);
		Rectangle(getMemDC(), bottomrc.left, bottomrc.top, bottomrc.right, bottomrc.bottom);
		char str2[128];
		sprintf_s(str2, "move1 : %d", move[0]);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y + 40, str2, strlen(str2));
		char str3[128];
		sprintf_s(str3, "move2 : %d", move[1]);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y + 60, str3, strlen(str3));
		char str4[128];
		sprintf_s(str4, "move3 : %d", move[2]);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y + 80, str4, strlen(str4));
		char str5[128];
		sprintf_s(str5, "move4 : %d", move[3]);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y + 100, str5, strlen(str5));
		char str6[128];
		sprintf_s(str6, "move5 : %d", move[4]);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y + 120, str6, strlen(str6));
		char str7[128];
		sprintf_s(str7, "ischangebattle : %d", _player->getPlayer()->ischangebattle);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y + 140, str7, strlen(str7));

		Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
		Rectangle(getMemDC(), introbattle.left, introbattle.top, introbattle.right, introbattle.bottom);
	}
	else
	{
		SetBkMode(getMemDC(), TRANSPARENT); //문자열 배경색 출력안되게
		
	}
}



void stage7::traprender()
{
	IMAGEMANAGER->findImage("trap3-1")->frameRender(getMemDC(), 1691, 201);
	IMAGEMANAGER->findImage("trap3-2")->frameRender(getMemDC(), 1691 + 40, 201);
	IMAGEMANAGER->findImage("trap3-3")->frameRender(getMemDC(), 1691 + 80, 201);
	IMAGEMANAGER->findImage("trap3-4")->frameRender(getMemDC(), 1691 + 120, 201);
	IMAGEMANAGER->findImage("trap3-5")->frameRender(getMemDC(), 1691 + 160, 201);
	IMAGEMANAGER->findImage("trap3-6")->frameRender(getMemDC(), 1691 + 200, 201);
	IMAGEMANAGER->findImage("trap3-7")->frameRender(getMemDC(), 1691 + 240, 201);
	IMAGEMANAGER->findImage("trap3-8")->frameRender(getMemDC(), 1691 + 280, 201);
	IMAGEMANAGER->findImage("trap3-9")->frameRender(getMemDC(), 1691 + 320, 201);
	IMAGEMANAGER->findImage("trap3-10")->frameRender(getMemDC(), 1691 + 360, 201);
	IMAGEMANAGER->findImage("trap3-11")->frameRender(getMemDC(), 1691 + 400, 201);
	IMAGEMANAGER->findImage("trap3-12")->frameRender(getMemDC(), 1691 + 440, 201);
	IMAGEMANAGER->findImage("trap3-13")->frameRender(getMemDC(), 1691 + 480, 201);
	IMAGEMANAGER->findImage("trap3-14")->frameRender(getMemDC(), 1691 + 520, 201);

	IMAGEMANAGER->findImage("trap3-15")->frameRender(getMemDC(), 1691, 201 + 40);
	IMAGEMANAGER->findImage("trap3-16")->frameRender(getMemDC(), 1691 + 40, 201 + 40);
	IMAGEMANAGER->findImage("trap3-17")->frameRender(getMemDC(), 1691 + 80, 201 + 40);
	IMAGEMANAGER->findImage("trap3-18")->frameRender(getMemDC(), 1691 + 120, 201 + 40);
	IMAGEMANAGER->findImage("trap3-19")->frameRender(getMemDC(), 1691 + 160, 201 + 40);
	IMAGEMANAGER->findImage("trap3-20")->frameRender(getMemDC(), 1691 + 200, 201 + 40);
	IMAGEMANAGER->findImage("trap3-21")->frameRender(getMemDC(), 1691 + 240, 201 + 40);
	IMAGEMANAGER->findImage("trap3-22")->frameRender(getMemDC(), 1691 + 280, 201 + 40);
	IMAGEMANAGER->findImage("trap3-23")->frameRender(getMemDC(), 1691 + 320, 201 + 40);
	IMAGEMANAGER->findImage("trap3-24")->frameRender(getMemDC(), 1691 + 360, 201 + 40);
	IMAGEMANAGER->findImage("trap3-25")->frameRender(getMemDC(), 1691 + 400, 201 + 40);
	IMAGEMANAGER->findImage("trap3-26")->frameRender(getMemDC(), 1691 + 440, 201 + 40);
	IMAGEMANAGER->findImage("trap3-27")->frameRender(getMemDC(), 1691 + 480, 201 + 40);
	IMAGEMANAGER->findImage("trap3-28")->frameRender(getMemDC(), 1691 + 520, 201 + 40);

	IMAGEMANAGER->findImage("trap3-29")->frameRender(getMemDC(), 1691, 201 + 80);
	IMAGEMANAGER->findImage("trap3-30")->frameRender(getMemDC(), 1691 + 40, 201 + 80);
	IMAGEMANAGER->findImage("trap3-31")->frameRender(getMemDC(), 1691 + 80, 201 + 80);
	IMAGEMANAGER->findImage("trap3-32")->frameRender(getMemDC(), 1691 + 120, 201 + 80);
	IMAGEMANAGER->findImage("trap3-33")->frameRender(getMemDC(), 1691 + 160, 201 + 80);
	IMAGEMANAGER->findImage("trap3-34")->frameRender(getMemDC(), 1691 + 200, 201 + 80);
	IMAGEMANAGER->findImage("trap3-35")->frameRender(getMemDC(), 1691 + 240, 201 + 80);
	IMAGEMANAGER->findImage("trap3-36")->frameRender(getMemDC(), 1691 + 280, 201 + 80);
	IMAGEMANAGER->findImage("trap3-37")->frameRender(getMemDC(), 1691 + 320, 201 + 80);
	IMAGEMANAGER->findImage("trap3-38")->frameRender(getMemDC(), 1691 + 360, 201 + 80);
	IMAGEMANAGER->findImage("trap3-39")->frameRender(getMemDC(), 1691 + 400, 201 + 80);
	IMAGEMANAGER->findImage("trap3-40")->frameRender(getMemDC(), 1691 + 440, 201 + 80);
	IMAGEMANAGER->findImage("trap3-41")->frameRender(getMemDC(), 1691 + 480, 201 + 80);
	IMAGEMANAGER->findImage("trap3-42")->frameRender(getMemDC(), 1691 + 520, 201 + 80);

	IMAGEMANAGER->findImage("trap3-43")->frameRender(getMemDC(), 1691, 201 + 120);
	IMAGEMANAGER->findImage("trap3-44")->frameRender(getMemDC(), 1691 + 40, 201 + 120);
	IMAGEMANAGER->findImage("trap3-45")->frameRender(getMemDC(), 1691 + 80, 201 + 120);
	IMAGEMANAGER->findImage("trap3-46")->frameRender(getMemDC(), 1691 + 120, 201 + 120);
	IMAGEMANAGER->findImage("trap3-47")->frameRender(getMemDC(), 1691 + 160, 201 + 120);
	IMAGEMANAGER->findImage("trap3-48")->frameRender(getMemDC(), 1691 + 200, 201 + 120);
	IMAGEMANAGER->findImage("trap3-49")->frameRender(getMemDC(), 1691 + 240, 201 + 120);
	IMAGEMANAGER->findImage("trap3-50")->frameRender(getMemDC(), 1691 + 280, 201 + 120);
	IMAGEMANAGER->findImage("trap3-51")->frameRender(getMemDC(), 1691 + 320, 201 + 120);
	IMAGEMANAGER->findImage("trap3-52")->frameRender(getMemDC(), 1691 + 360, 201 + 120);
	IMAGEMANAGER->findImage("trap3-53")->frameRender(getMemDC(), 1691 + 400, 201 + 120);
	IMAGEMANAGER->findImage("trap3-54")->frameRender(getMemDC(), 1691 + 440, 201 + 120);
	IMAGEMANAGER->findImage("trap3-55")->frameRender(getMemDC(), 1691 + 480, 201 + 120);
	IMAGEMANAGER->findImage("trap3-56")->frameRender(getMemDC(), 1691 + 520, 201 + 120);
}

void stage7::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));//글꼴생성
																													  //폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 0)
		hInputFile = CreateFile(_T("text/stage7/stage7_1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/stage7/stage7_2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
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

void stage7::TextControl2()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/stage7/stage7_3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("text/stage7/stage7_4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
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

void stage7::TextControl3()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
		if (textnum == 4 && islastevent)
		hInputFile = CreateFile(_T("text/stage7/stage7_5.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
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

void stage7::TextControlUpdate()
{

	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 0)
		{
			if (tindex < 38)
				tindex++;
		}
		if (textnum == 1)
		{
			if (tindex < 35)
				tindex++;
		}
		if (textnum == 2)
		{
			if (tindex < 31 && isfirstevent)
				tindex++;
		}
		if (textnum == 3)
		{
			if (tindex < 30 && isfirstevent)
				tindex++;
		}
		if (textnum == 4)
		{
			if (tindex < 46 && islastevent)
				tindex++;
		}

	}

	if (textnum == 0)
	{
		if (tindex == 38)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 38;
		}
	}
	if (textnum == 1)
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
	if (textnum == 2)
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
			if (KEYMANAGER->isOnceDown('X') && isfirstevent) tindex = 31;
		}
	}
	if (textnum == 3)
	{
		if (tindex == 30)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum += 1;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X') && isfirstevent) tindex = 30;
		}
	}
	if (textnum == 4)
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
			if (KEYMANAGER->isOnceDown('X') && islastevent) tindex = 46;
		}
	}
}

void stage7::torielFrame()
{
	if (_stage3->_torielMotion.idle)
	{
		toriel->setFrameX(0);
		toriel->setFrameY(0);
	}
	if (_torielplus.idle)
	{
		torplus->setFrameX(0);
		torplus->setFrameY(0);
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
	if (_torielplus.walk)
	{
		count1++;
		if (count1 % 10 == 0)
		{

			torplus->setFrameX(index1);
			index1++;
			if (index1 > torplus->getMaxFrameX()) index1 = 0;


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

	if (_torielplus.movedown)
	{
		_torielplus.moveleft = false;
		_torielplus.moveright = false;
		_torielplus.moveup = false;
		torplus->setFrameY(0);

	}
	if (_torielplus.moveleft)
	{
		_torielplus.movedown = false;
		_torielplus.moveright = false;
		_torielplus.moveup = false;
		torplus->setFrameY(1);
	}
	if (_torielplus.moveright)
	{
		_torielplus.movedown = false;
		_torielplus.moveleft = false;
		_torielplus.moveup = false;
		torplus->setFrameY(2);
	}
	if (_torielplus.moveup)
	{
		_torielplus.movedown = false;
		_torielplus.moveleft = false;
		_torielplus.moveright = false;
		torplus->setFrameY(3);
	}
}
void stage7::entryBattle()
{
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &introbattle))
	{
		_player->getPlayer()->playertor = true;
		_player->getPlayer()->changeScene = false;
		_camera->cam.cameramove = false;
		endx = _camera->getCam()->x + 6;
		endy = _camera->getCam()->y + 454;
		
		
	  _player->getPlayer()->SaveX = _player->getPlayer()->x;
	  _player->getPlayer()->SaveY = _player->getPlayer()->y;
	  
	  _player->getPlayer()->ischangebattle = true;
	  _player->getPlayer()->changebattle = true;
	
	  speed = (MY_UTIL::getDistance(_player->getPlayer()->x, _player->getPlayer()->y, _camera->getCam()->x + 24,_camera->getCam()->y + 400));
	  speedx = (MY_UTIL::getDistance(_player->getPlayer()->x, _player->getPlayer()->x, endx, endx));
	  speedy = (MY_UTIL::getDistance(_player->getPlayer()->y, _player->getPlayer()->y, endy, endy));
	  
	 
	}
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
	else if (ischange)
	{
		_player->getPlayer()->stage7return = true;
		SCENEMANAGER->changeScene("stage7battle");
	}
}
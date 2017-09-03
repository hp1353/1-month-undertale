#include "stdafx.h"
#include "stage4.h"
#include "camera.h"
#include "player.h"
#include "stage3.h"
stage4::stage4()
{
}


stage4::~stage4()
{
}

HRESULT stage4::init()
{
	if (!SOUNDMANAGER->isPauseSound("stagesound"))
	{
		SOUNDMANAGER->resume("stagesound");
	}
	_player->getPlayer()->SaveStageNum = 4;
	torielface_1 = IMAGEMANAGER->addFrameImage("torielface_1", "image/undertale/npc/torielface_0.bmp", 288, 88, 3, 1, false, false);
	torielface_talk = IMAGEMANAGER->addFrameImage("torielface_talk", "image/undertale/npc/torielface_talk.bmp", 192, 88, 2, 1, false, false);

	IMAGEMANAGER->addImage("stage4", "image/undertale/stage/stage4.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("trapdoor", "image/undertale/object/trapdoor.bmp", 80, 121, false, false);
	IMAGEMANAGER->addImage("stage4event1", "image/undertale/event/stage4Event/stage4event1.bmp", 578, 152, false, false);
	IMAGEMANAGER->addImage("stage4event2", "image/undertale/event/stage4Event/stage4event2.bmp", 578, 152, false, false);
	IMAGEMANAGER->addImage("afterevent", "image/undertale/event/stage4Event/afterevent.bmp", 578, 152, false, false);
	IMAGEMANAGER->addImage("afterevent2", "image/undertale/event/stage4Event/afterevent2.bmp", 578, 152, false, false);
	IMAGEMANAGER->addImage("afterevent3", "image/undertale/event/stage4Event/afterevent3.bmp", 578, 152, false, false);
	IMAGEMANAGER->addImage("afterevent4", "image/undertale/event/stage4Event/afterevent4.bmp", 578, 152, false, false);
	IMAGEMANAGER->addImage("objectText", "image/undertale/event/stage4Event/objectText.bmp", 578, 152, false, false);
	trap1[0] =IMAGEMANAGER->addFrameImage("trap0", "image/undertale/object/trap1.bmp", 64, 28, 2, 1, true, RGB(255, 0, 255));
	trap1[0]->setFrameX(0);

	trap1[1] = IMAGEMANAGER->addFrameImage("trap1", "image/undertale/object/trap1.bmp", 64, 28, 2, 1, true, RGB(255, 0, 255));
	trap1[1]->setFrameX(0);

	trap1[2] = IMAGEMANAGER->addFrameImage("trap2", "image/undertale/object/trap1.bmp", 64, 28, 2, 1, true, RGB(255, 0, 255));
	trap1[2]->setFrameX(0);

	trap1[3] = IMAGEMANAGER->addFrameImage("trap3", "image/undertale/object/trap1.bmp", 64, 28, 2, 1, true, RGB(255, 0, 255));
	trap1[3]->setFrameX(0);

	trap1[4] = IMAGEMANAGER->addFrameImage("trap4", "image/undertale/object/trap1.bmp", 64, 28, 2, 1, true, RGB(255, 0, 255));
	trap1[4]->setFrameX(0);

	trap1[5] = IMAGEMANAGER->addFrameImage("trap5", "image/undertale/object/trap1.bmp", 64, 28, 2, 1, true, RGB(255, 0, 255));
	trap1[5]->setFrameX(0);
	
	switchimage = IMAGEMANAGER->addFrameImage("switch0", "image/undertale/object/switch1.bmp", 28, 36, 2, 1, true, RGB(255, 0, 255));
	toriel = IMAGEMANAGER->addFrameImage("toriel", "image/undertale/npc/toriel.bmp", 200, 416, 4, 4, true, RGB(255, 242, 0));
	toriel->setX(CENTERX - toriel->getFrameWidth() / 2);
	toriel->setY(210);
	toriel->setFrameX(0);
	toriel->setFrameY(0);
	torielrc = RectMakeCenter(toriel->getX()+25, toriel->getY()+90, 15, 15);
	_player->getPlayer()->x = CENTERX - _player->getPlayer()->image->getFrameX() / 2 - 20;
	_player->getPlayer()->y = 420;
	
	_camera->cam.overviewY = true;
	_camera->getCam()->x = 0;
	_camera->getCam()->y = 0;
	
	trap[0] = RectMake(363, 210, 35, 30);
	trap[1] = RectMake(447, 210, 35, 30);
	trap[2] = RectMake(405, 250, 35, 30);
	trap[3] = RectMake(363, 290, 35, 30);
	trap[4] = RectMake(447, 290, 35, 30);
	trap[5] = RectMake(405, 330, 35, 30);

	textevent = false;
	talkcountreset = false;

	_stage3->_torielMotion.idle = true;
	_stage3->_torielMotion.walk = false;
	_stage3->_torielMotion.movedown = false;
	_stage3->_torielMotion.moveleft = false;
	_stage3->_torielMotion.moveright = false;
	_stage3->_torielMotion.moveup = false;

	eventmove = false;
	

	for (int i = 0; i < 10; i++)
	{
		move[i] = false;
	}
	count = 0;
	index = 0;
	opencount = 0;
	allover = false;
	talkcountreset2 = false;
	onceEvent = false;
	alleventover = false;

	objectText2 = RectMakeCenter(180, 120, 50, 50);
	objectText2Event = false;

	talkcountreset3 = false;

	nextdoor = RectMake(250, 70, 50, 50);
	tindex = 0;
	tcount = 0;
	textnum = 0;
	count1 = 0;
	count2 = 0;
	index1 = 0;
	talkcount = 0;
	talkindex = 0;
	sound2 = false;

	for (int i = 0; i < 6; i++)
	{
		sound[i] = false;
	}
	return S_OK;
}

void stage4::release()
{
}

void stage4::update()
{
	if(textnum == 7)textrc = RectMake(_camera->getCam()->x + 80, _camera->getCam()->y + 20, 500, 150);
	else textrc = RectMake(_camera->getCam()->x + 170, _camera->getCam()->y + 20, 500, 150);
	TextControlUpdate();
	if (textnum != 0)_player->getPlayer()->control = false;
	if (textnum == 0)_player->getPlayer()->control = true;
	torielrc = RectMakeCenter(toriel->getX() + 25, toriel->getY() + 90, 15, 15);
	if(eventmove && !allover)
	EventMove();
	trapFrame();
	torielFrame();
	if (_player->getPlayer()->y < 380 && textnum == 0 && !onceEvent)
	{
		//if(!onceEvent)
		//textevent = true;
		textnum = 1;
	}
	
	if (alleventover)
	{
		_stage3->_torielMotion.moveup = true;
		_stage3->_torielMotion.moveleft = false;
		_stage3->_torielMotion.moveright = false;
		_stage3->_torielMotion.movedown = false;
		_stage3->_torielMotion.walk = true;
		_stage3->_torielMotion.idle = false;
		toriel->setY(toriel->getY() - 2);
		_player->getPlayer()->control = true;

	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &objectText2) &&textnum == 0)
	{
		if(_player->getPlayer()->pressZ)
		textnum = 7;
	}

	if (allover && !eventmove && textnum == 0 && !alleventover) textnum = 3;
}

void stage4::render()
{
	IMAGEMANAGER->findImage("stage4")->render(getMemDC());
	if(!dooropen)
	IMAGEMANAGER->findImage("trapdoor")->render(getMemDC(), 240, 38);
	IMAGEMANAGER->findImage("trap0")->frameRender(getMemDC(), 363, 210);
	IMAGEMANAGER->findImage("trap1")->frameRender(getMemDC(), 447, 210);
	IMAGEMANAGER->findImage("trap2")->frameRender(getMemDC(), 405, 250);
	IMAGEMANAGER->findImage("trap3")->frameRender(getMemDC(), 363, 290);
	IMAGEMANAGER->findImage("trap4")->frameRender(getMemDC(), 447, 290);
	IMAGEMANAGER->findImage("trap5")->frameRender(getMemDC(), 405, 330);
	
	IMAGEMANAGER->findImage("switch0")->frameRender(getMemDC(), 414, 100);
	
	if(toriel->getY() > 50)
	IMAGEMANAGER->findImage("toriel")->frameRender(getMemDC(), toriel->getX(), toriel->getY());

	
	if (textnum != 0 && textnum !=7)
	{


		IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
		if (!talkend)
		{
			IMAGEMANAGER->findImage("torielface_talk")->frameRender(getMemDC(), _camera->getCam()->x + 50, _camera->getCam()->y + 30);
		}
		if (talkend)
			IMAGEMANAGER->findImage("torielface_1")->frameRender(getMemDC(), _camera->getCam()->x + 48, _camera->getCam()->y + 34);


	}
	if (textnum == 7)IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
	TextControl();
	if (_player->getPlayer()->viewEvery)
	{
		for (int i = 0; i < 6; i++)
		{
			Rectangle(getMemDC(), trap[i].left, trap[i].top, trap[i].right, trap[i].bottom);
		}
		Rectangle(getMemDC(), torielrc.left, torielrc.top, torielrc.right, torielrc.bottom);
		Rectangle(getMemDC(), nextdoor.left, nextdoor.top, nextdoor.right, nextdoor.bottom);
		char str[128];
		sprintf_s(str, "to.x : %f", toriel->getX());
		TextOut(getMemDC(), toriel->getX(), toriel->getY() - 40, str, strlen(str));
		char str1[128];
		sprintf_s(str1, "to.y : %f", toriel->getY());
		TextOut(getMemDC(), toriel->getX(), toriel->getY() - 20, str1, strlen(str1));
		char str2[128];
		sprintf_s(str2, "talkIndex : %d", _player->getPlayer()->talkindex);
		TextOut(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y + 20, str2, strlen(str2));
		Rectangle(getMemDC(), objectText2.left, objectText2.top, objectText2.right, objectText2.bottom);
	}
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->rc, &nextdoor))
	{
		SCENEMANAGER->changeScene("stage5");
	}
}

void stage4::trapFrame()
{
	for (int i = 0; i < 6; i++)
	{
		if (IntersectRect(&RectMake(0, 0, 0, 0), &_player->getPlayer()->bottomrc, &trap[i]))
		{
			if (!SOUNDMANAGER->isPlaySound("trapdown3") && !sound[i])
			{
				SOUNDMANAGER->play("trapdown3", 1.f);
				sound[i] = true;
			}
			trap1[i]->setFrameX(1);

		}
		if (IntersectRect(&RectMake(0, 0, 0, 0), &torielrc, &trap[i]))
		{
			if (!SOUNDMANAGER->isPlaySound("trapdown3") && !sound[i])
			{
				sound[i] = true;
				SOUNDMANAGER->play("trapdown3", 1.f);
			}
			trap1[i]->setFrameX(1);
		}
	}
}

void stage4::torielFrame()
{
	//토리엘 입모양
	if (!talkend)
	{
		talkcount++;
		if (talkcount % 10 == 0)
		{

			torielface_talk->setFrameX(talkindex);
			talkindex++;
			if (talkindex > torielface_talk->getMaxFrameX()) talkindex = 0;


		}
	}
	if (talkend) //토리엘 눈감빡이는얼굴
	{
		torielface_talk->setFrameX(0);
		count1++;
		count2++;
		if (count1 % 10 == 0)
		{

			torielface_1->setFrameX(index1);
			if (index1 == 0)
			{
				if (count2 % 100 == 0) index1++;
			}
			else index1++;
			if (index1 > torielface_1->getMaxFrameX()) index1 = 0;


		}
	}
	if (_stage3->_torielMotion.idle)
	{
		toriel->setFrameX(0);
		toriel->setFrameY(0);
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
}

void stage4::EventMove()
{
	_player->getPlayer()->frameReset = true;
	_player->getPlayer()->control = false;

	if (toriel->getX() < 450 && !move[0])
	{
		_stage3->_torielMotion.idle = false;
		_stage3->_torielMotion.walk = true;
		_stage3->_torielMotion.moveright = true;
		toriel->setX(toriel->getX() + 2);
		

	}
	if (toriel->getX() > 450 && !move[1])
	{
		if (toriel->getY() > 135)
		{
			_stage3->_torielMotion.idle = false;
			_stage3->_torielMotion.walk = true;
			_stage3->_torielMotion.moveright = false;
			_stage3->_torielMotion.moveup = true;
			toriel->setY(toriel->getY() - 2);
			move[0] = true;
		}
	}
	if (toriel->getY() <= 135 && !move[2] && move[0])
	{
		if (toriel->getX() > 370)
		{
			_stage3->_torielMotion.idle = false;
			_stage3->_torielMotion.walk = true;
			_stage3->_torielMotion.moveup = false;
			_stage3->_torielMotion.moveleft = true;
			toriel->setX(toriel->getX() - 2);
			move[1] = true;
		}
	}
	if (toriel->getX() < 370  && move[1] && move[0] )
	{
		if (toriel->getY() > 95)
		{
			_stage3->_torielMotion.idle = false;
			_stage3->_torielMotion.walk = true;
			_stage3->_torielMotion.moveleft = false;
			_stage3->_torielMotion.moveup = true;
			toriel->setY(toriel->getY() - 2);
		}
		move[2] = true;
	}
	if (toriel->getY() < 95 && move[1] && move[0] &&move[2])
	{
		if (toriel->getX() < 390)
		{
			_stage3->_torielMotion.idle = false;
			_stage3->_torielMotion.walk = true;
			_stage3->_torielMotion.moveup = false;
			_stage3->_torielMotion.moveright = true;
			toriel->setX(toriel->getX() + 2);
		}
		move[3] = true;
	}
	if (toriel->getX() > 390 && move[1] && move[0] &&move[2] && move[3])
	{
		//_stage3->_torielMotion.idle = true;
		_stage3->_torielMotion.moveright = false;
		_stage3->_torielMotion.walk = false;
		if (opencount < 100)
		{
			toriel->setFrameY(1);
			toriel->setFrameX(0);
		}
		switchimage->setFrameX(1);
		dooropen = true;
		opencount++;
		if (!SOUNDMANAGER->isPlaySound("trapdown3") && !sound2)
		{
			SOUNDMANAGER->play("trapdown3", 1.f);
			sound2 = true;
		}
	}
	if (opencount > 50 && move[1] && move[0] && move[2] && move[3])
	{
		if (toriel->getX() > 250)
		{
			_stage3->_torielMotion.idle = false;
			_stage3->_torielMotion.walk = true;
			_stage3->_torielMotion.moveleft = true;
			toriel->setX(toriel->getX() - 4);
		}
		if (toriel->getX() < 250)
		{
			if (toriel->getY() < 180)
			{
				_stage3->_torielMotion.idle = false;
				_stage3->_torielMotion.walk = true;
				_stage3->_torielMotion.moveleft = false;
				_stage3->_torielMotion.movedown = true;
				toriel->setY(toriel->getY() + 4);
			}
			if (toriel->getY() > 180)
			{
				_stage3->_torielMotion.movedown = true;
				_stage3->_torielMotion.idle = true;
				_stage3->_torielMotion.walk = false;
				eventmove = false;
				allover = true;
				toriel->setFrameY(0);
			}
		}
	}
	
	
}

void stage4::EventTalk()
{
	/*_player->getPlayer()->talking = true;
	_player->getPlayer()->talk = true;
	
	


	if (_player->getPlayer()->talk)
	{
		_player->getPlayer()->talking = true;
		if (!talkcountreset)
		{
			_player->getPlayer()->talkindex = 2;
			talkcountreset = true;
		}

		if (_player->getPlayer()->talkindex == 2)
			IMAGEMANAGER->findImage("stage4event1")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
		if (_player->getPlayer()->talkindex == 1)
			IMAGEMANAGER->findImage("stage4event2")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
		if (_player->getPlayer()->talkindex <= 0)
		{
			_player->getPlayer()->talking = false;
			eventmove = true;
			onceEvent = true;

		}
	}*/
	
}

void stage4::EventTalk2()
{
	/*_player->getPlayer()->talking = true;
	_player->getPlayer()->talk = true;

	if (_player->getPlayer()->talk)
	{
		_player->getPlayer()->talking = true;
		if (!talkcountreset2)
		{
			_player->getPlayer()->talkindex = 4;
			talkcountreset2 = true;
		}

		if (_player->getPlayer()->talkindex == 4)
			IMAGEMANAGER->findImage("afterevent")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
		if (_player->getPlayer()->talkindex == 3)
			IMAGEMANAGER->findImage("afterevent2")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
		if (_player->getPlayer()->talkindex == 2)
			IMAGEMANAGER->findImage("afterevent3")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
		if (_player->getPlayer()->talkindex == 1)
			IMAGEMANAGER->findImage("afterevent4")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
		if (_player->getPlayer()->talkindex <= 0)
		{
			_player->getPlayer()->talking = false;
			eventmove = true;
			alleventover = true;
		}
	}*/

}

void stage4::TextControlUpdate()
{

	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 1)
		{
			if (tindex < 47)
			{
				talkend = false;
				tindex++;
			}
		}
		if (textnum == 2)
		{
			if (tindex < 43)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 3)
		{
			if (tindex < 30)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 4)
		{
			if (tindex < 46)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 5)
		{
			if (tindex < 55)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 6)
		{
			if (tindex < 30)
			{
				tindex++;
				talkend = false;
			}
		}
		if (textnum == 7)
		{
			if (tindex < 91)
			{
				tindex++;
				talkend = false;
			}
		}



	}

	if (textnum == 1)
	{
		if (tindex == 47)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 47;
		}
	}
	if (textnum == 2)
	{
		if (tindex == 43)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{

				tindex = 0;
				textnum = 0;
				EventMove();
				 onceEvent = true;
				 eventmove = true;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 43;
		}
	}
	if (textnum == 3)
	{
		if (tindex == 30)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 30;
		}
	}
	if (textnum == 4)
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
	if (textnum == 5)
	{
		if (tindex == 55)
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
			if (KEYMANAGER->isOnceDown('X')) tindex = 55;
		}
	}
	if (textnum == 6)
	{
		if (tindex == 30)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
				alleventover = true;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 30;
		}
	}
	if (textnum == 7)
	{
		if (tindex == 91)
		{
			talkend = true;
			if (KEYMANAGER->isOnceDown('Z'))
			{
				tindex = 0;
				textnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) tindex = 91;
		}
	}
}

void stage4::TextControl()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																												//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;
	if (textnum == 1)
		hInputFile = CreateFile(_T("text/stage4/text1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("text/stage4/text2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("text/stage4/text3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 4)
		hInputFile = CreateFile(_T("text/stage4/text4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 5)
		hInputFile = CreateFile(_T("text/stage4/text5.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 6)
		hInputFile = CreateFile(_T("text/stage4/text6.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 7)
		hInputFile = CreateFile(_T("text/stage4/text7.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

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

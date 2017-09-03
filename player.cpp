#include "stdafx.h"
#include "player.h"
#include "camera.h"

player::player()
{
}


player::~player()
{
}

HRESULT player::init()
{
	_player.battleend = false;
	_player.walkcount = 0;
	intro2 = false;
	introonce = false;
	entryonce = false;
	IMAGEMANAGER->addImage("stage3_pix", "image/undertale/stage/stage3_pix.bmp", 640, 959, false, false);
	IMAGEMANAGER->addImage("stage4_pix", "image/undertale/stage/stage4_pix.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("stage5_pix", "image/undertale/stage/stage5_pix.bmp", 1503, 481, false, false);
	IMAGEMANAGER->addImage("stage6_pix", "image/undertale/stage/stage6_pix.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("stage7_pix", "image/undertale/stage/stage7_pix.bmp", 2411, 480, false, false);
	IMAGEMANAGER->addImage("stage8_pix", "image/undertale/stage/stage8_pix.bmp", 5295, 480, false, false);
	IMAGEMANAGER->addImage("stage9_pix", "image/undertale/stage/stage9_pix.bmp", 640, 1002, false, false);
	IMAGEMANAGER->addImage("stage9_1_pix", "image/undertale/stage/stage9_1_pix.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("stage10_pix", "image/undertale/stage/stage10_pix.bmp", 641, 1521, false, false);
	IMAGEMANAGER->addImage("stage11_pix", "image/undertale/stage/stage11_pix.bmp", 959, 481, false, false);
	IMAGEMANAGER->addImage("stage12_pix", "image/undertale/stage/stage12_pix.bmp", 1164, 1592, false, false);
	IMAGEMANAGER->addImage("stage13_pix", "image/undertale/stage/stage13_pix.bmp", 1119, 480, false, false);
	IMAGEMANAGER->addImage("stage14_pix", "image/undertale/stage/stage14_pix.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("stage15_pix", "image/undertale/stage/stage15_pix.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("stage15_store_pix", "image/undertale/stage/stage15_store_pix.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("stage16_pix", "image/undertale/stage/stage16_pix.bmp", 1521, 598, false, false);
	IMAGEMANAGER->addImage("stage17_pix", "image/undertale/stage/stage17_pix.bmp", 1283, 1322, false, false);
	IMAGEMANAGER->addImage("stage18_pix", "image/undertale/stage/stage18_pix.bmp", 797, 859, false, false);
	IMAGEMANAGER->addImage("stage19_pix", "image/undertale/stage/stage19_pix.bmp", 800, 851, false, false);
	IMAGEMANAGER->addImage("stage20_pix", "image/undertale/stage/stage20_pix.bmp", 800, 875, false, false);
	IMAGEMANAGER->addImage("stage21_pix", "image/undertale/stage/stage21_pix.bmp", 820, 962, false, false);
	IMAGEMANAGER->addImage("stage18_21_traproom_pix", "image/undertale/stage/stage18_21_traproom_pix.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("stage22_pix", "image/undertale/stage/stage22_pix.bmp", 1203, 799, false, false);
	IMAGEMANAGER->addImage("stage22_1_pix", "image/undertale/stage/stage22_1_pix.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("stage22_2_pix", "image/undertale/stage/stage22_2_pix.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("torielgarden_pix", "image/undertale/stage/torielgarden_pix.bmp", 642, 962, false, false);
	IMAGEMANAGER->addImage("torielhome_pix", "image/undertale/stage/torielhome_pix.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("leftroom_pix", "image/undertale/stage/leftroom_pix.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("kitchen_pix", "image/undertale/stage/kitchen_pix.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("rightroom_pix", "image/undertale/stage/rightroom_pix.bmp", 1601, 480, false, false);
	IMAGEMANAGER->addImage("myroom_pix", "image/undertale/stage/myroom_pix.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("torielroom_pix", "image/undertale/stage/torielroom_pix.bmp", 640, 480, false, false);

	IMAGEMANAGER->addImage("undertorielhome_1_pix", "image/undertale/stage/undertorielhome_1_pix.bmp", 1276, 482, false, false);
	IMAGEMANAGER->addImage("undertorielhome_2_pix", "image/undertale/stage/undertorielhome_2_pix.bmp", 1266, 481, false, false);
	IMAGEMANAGER->addImage("undertorielhome_3_pix", "image/undertale/stage/undertorielhome_3_pix.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("undertorielhome_4_pix", "image/undertale/stage/undertorielhome_4_pix.bmp", 640, 480, false, false);

	IMAGEMANAGER->addImage("torielbattle_base", "image/undertale/battle/torielbattle/torielbattle_base.bmp", 640, 480, false, false);

	IMAGEMANAGER->addImage("lastload_pix", "image/undertale/last/lastload_pix.bmp", 641, 3837, false, false);

	IMAGEMANAGER->addImage("Inven", "image/undertale/player/Inven.bmp", 142, 264, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Inven_item", "image/undertale/player/item.bmp", 346, 362, false, false);
	IMAGEMANAGER->addImage("Inven_state", "image/undertale/player/state.bmp", 346, 418, false, false);
	IMAGEMANAGER->addImage("Inven_state2", "image/undertale/player/state2.bmp", 346, 418, false, false);
	_player.image = IMAGEMANAGER->addFrameImage("player", "image/undertale/player/player.bmp", 160, 240, 4, 4, true, RGB(255, 0, 255));
	_player.x = CENTERX;
	_player.y = CENTERY;
	_player.isDown = true;
	_player.isLeft = false;
	_player.isRight = false;
	_player.isUp = false;
	_player.motion = IDLE;
	_player.rc = RectMake(_player.x, _player.y, IMAGEMANAGER->findImage("player")->getFrameWidth(), IMAGEMANAGER->findImage("player")->getFrameHeight() );
	_player.viewEvery = false;
	_player.control = true;
	_player.frame = true;
	_player.frameReset = false;
	_player.changebattle = false;
	_player.battleScene = false;
	_player.talk = false;
	_player.talking = false;
	changecount = 0;
	changeindex = 0;
	index = 0;
	count = 0;
	_player.chagne = false;
	_player.talkindex = 0;
	_player.changeScene = false;
	_player.ischangebattle = false;
	_player.playerRender = true;
	_player.stage6_patten1 = false;
	_player.stage6_patten2 = false;
	_player.stage6_patten3 = false;
	_player.stage6_patten4 = false;
	_player.playertor = false;
	_player.changeindex = 0;
	_player.isstage9_1 = false;
	_player.viewInven = false;
	index = 0;
	count = 0;
	point = 0;
	itemview = false;
	stateview = false;
	itemarr = 0;
	for (int i = 0; i < 8; i++)
		_player.itemarr[i] = 0;
	infomonstercandy = false;
	iteminfoarr = 0;
	usecandy = false;
	infocandy = false;
	itemnum = 0;
	_player.candynum = 0;
	candycount = 0;
	candytextnum = 0;
	candyindex = 0;
	_player.shehavecandy = 4;
	_player.killstage7frog = false;
	_player.dontpix = false;
	turncount = 0;
	turnindex = 0;
	fuckingturn = 0;
	isturn = false;
	_player.turn = false;
	_player.Gold = 0;
	_player.stage7return = false;
	_player.isstage15_store = false;
	_player.istraproom = false;
	_player.isstage22_1 = false;
	_player.isstage22_2 = false;
	_player.pressZ = false;
	_player.stage19nopillar = false;
	_player.stage20nopillar = false;
	_player.stage21nopillar = false;
	_player.haveknife = false;
	infoknife = false;
	useknife = false;
	knifetextnum = 0;
	_player.At = 0;
	_player.notree = false;
	IMAGEMANAGER->addImage("knifetext", "image/undertale/item/knifetext.bmp", 138, 31, false, false);
	_player.viewrightroomEvent = false;
	_player.viewtorielhomeEvent = false;
	_player.isbeforerightroom = false;
	_player.isbeforeleftroom = false;
	_player.isbeforekitchen = false;
	_player.isbeforeunderroom = false;
	_player.isbefroemyroom = false;
	_player.isbeforetorielroom = false;
	_player.alpha = 0;
	_player.gosleep = false;
	_player.isgetpie = false;
	IMAGEMANAGER->addImage("pietext", "image/undertale/item/pietext.bmp", 265, 47, false, false);
	pietextnum = 0;
	infopie = 0;
	_player.angrytoriel = false;
	_player.under1event = false;
	_player.under2event = false;
	_player.under3event = false;
	_player.under4event = false;
	_player.boom = false;
	once = false;


	_player.Lv = 1;
	_player.CurHp = 20;
	_player.MaxHp = 20;

	_player.goodending = false;
	_player.badending = false;

	_player.ghostend = false;
	_player.killnum = 0;
	RndMonsterNum = 0;
	RndWalkNum = 0;
	Walkcount = 0;
	Walkindex = 0;
	monsterbeforecount = 0;
	introcount = 0;
	introindex = 0;

	IMAGEMANAGER->addImage("!", "image/undertale/object/!.bmp", 10, 10, true, RGB(255, 0, 255));


	endx = 0;
	endy = 0;
	speed = 0;
	speedx = 0;

	speedy = 0;
	count2 = 0;
	ischange = false;

	_player.stage11clear = false;
	_player.stage13clear = false;
	_player.stage17clear = false;
	_player.stage19clear = false;
	_player.stage20clear = false;
	_player.stage21clear = false;
	_player.killghost = false;
	_player.loadstagenum = 0;
	_player.stage15skip = false;
	return S_OK;
}

void player::release()
{
}

void player::update()
{
	if (KEYMANAGER->isOnceDown('0'))
	{
		_player.killnum += 1;
	}
	MonsterMeet();
	Turn();
	candytextrc = RectMake(_camera->getCam()->x + 80, _camera->getCam()->y + 20, 500, 150);
	candytextupdate();
	_player.rc = RectMake(_player.x, _player.y, IMAGEMANAGER->findImage("player")->getFrameWidth(), IMAGEMANAGER->findImage("player")->getFrameHeight());
	_player.bottomrc = RectMake(_player.x+15, _player.y + 50, 10, 10);
	if (_player.control && !_player.talking && !_player.viewInven)
		KeyControl();
	if (_player.frame && !_player.talking && _player.control)
		FrameUpdate();
	//if(SCENEMANAGER->CurrentScene("stage5"))
	//talkControl();
	entrybattle();
	InvenUpdate();
	
	
	if (KEYMANAGER->isToggle('1'))
	{
		
		_player.viewEvery = true;
	}
	else _player.viewEvery = false;

	if (SCENEMANAGER->CurrentScene("stage3"))piximage = IMAGEMANAGER->findImage("stage3_pix");
	if (SCENEMANAGER->CurrentScene("stage4"))piximage = IMAGEMANAGER->findImage("stage4_pix");
	if (SCENEMANAGER->CurrentScene("stage5"))piximage = IMAGEMANAGER->findImage("stage5_pix");
	if (SCENEMANAGER->CurrentScene("stage6"))piximage = IMAGEMANAGER->findImage("stage6_pix");
	if (SCENEMANAGER->CurrentScene("stage7"))piximage = IMAGEMANAGER->findImage("stage7_pix");
	if (SCENEMANAGER->CurrentScene("stage8"))piximage = IMAGEMANAGER->findImage("stage8_pix");
	if (SCENEMANAGER->CurrentScene("stage9"))piximage = IMAGEMANAGER->findImage("stage9_pix");
	if (SCENEMANAGER->CurrentScene("stage9_1"))piximage = IMAGEMANAGER->findImage("stage9_1_pix");
	if (SCENEMANAGER->CurrentScene("stage10"))piximage = IMAGEMANAGER->findImage("stage10_pix");
	if (SCENEMANAGER->CurrentScene("stage11"))piximage = IMAGEMANAGER->findImage("stage11_pix");
	if (SCENEMANAGER->CurrentScene("stage12"))piximage = IMAGEMANAGER->findImage("stage12_pix");
	if (SCENEMANAGER->CurrentScene("stage13"))piximage = IMAGEMANAGER->findImage("stage13_pix");
	if (SCENEMANAGER->CurrentScene("stage14"))piximage = IMAGEMANAGER->findImage("stage14_pix");
	if (SCENEMANAGER->CurrentScene("stage15"))piximage = IMAGEMANAGER->findImage("stage15_pix");
	if (SCENEMANAGER->CurrentScene("stage15_store"))piximage = IMAGEMANAGER->findImage("stage15_store_pix");
	if (SCENEMANAGER->CurrentScene("stage16"))piximage = IMAGEMANAGER->findImage("stage16_pix");
	if (SCENEMANAGER->CurrentScene("stage17"))piximage = IMAGEMANAGER->findImage("stage17_pix");
	if (SCENEMANAGER->CurrentScene("stage18"))piximage = IMAGEMANAGER->findImage("stage18_pix");
	if (SCENEMANAGER->CurrentScene("stage19"))piximage = IMAGEMANAGER->findImage("stage19_pix");
	if (SCENEMANAGER->CurrentScene("stage20"))piximage = IMAGEMANAGER->findImage("stage20_pix");
	if (SCENEMANAGER->CurrentScene("stage21"))piximage = IMAGEMANAGER->findImage("stage21_pix");
	if (SCENEMANAGER->CurrentScene("stage18_21_traproom"))piximage = IMAGEMANAGER->findImage("stage18_21_traproom_pix");
	if (SCENEMANAGER->CurrentScene("stage22"))piximage = IMAGEMANAGER->findImage("stage22_pix");
	if (SCENEMANAGER->CurrentScene("stage22_1"))piximage = IMAGEMANAGER->findImage("stage22_1_pix");
	if (SCENEMANAGER->CurrentScene("stage22_2"))piximage = IMAGEMANAGER->findImage("stage22_2_pix");
	if (SCENEMANAGER->CurrentScene("torielgarden"))piximage = IMAGEMANAGER->findImage("torielgarden_pix");
	if (SCENEMANAGER->CurrentScene("torielhome"))piximage = IMAGEMANAGER->findImage("torielhome_pix");
	if (SCENEMANAGER->CurrentScene("leftroom"))piximage = IMAGEMANAGER->findImage("leftroom_pix");
	if (SCENEMANAGER->CurrentScene("kitchen"))piximage = IMAGEMANAGER->findImage("kitchen_pix");
	if (SCENEMANAGER->CurrentScene("rightroom"))piximage = IMAGEMANAGER->findImage("rightroom_pix");
	if (SCENEMANAGER->CurrentScene("myroom"))piximage = IMAGEMANAGER->findImage("myroom_pix");
	if (SCENEMANAGER->CurrentScene("torielroom"))piximage = IMAGEMANAGER->findImage("torielroom_pix");
	if (SCENEMANAGER->CurrentScene("undertorielhome_1"))piximage = IMAGEMANAGER->findImage("undertorielhome_1_pix");
	if (SCENEMANAGER->CurrentScene("undertorielhome_2"))piximage = IMAGEMANAGER->findImage("undertorielhome_2_pix");
	if (SCENEMANAGER->CurrentScene("undertorielhome_3"))piximage = IMAGEMANAGER->findImage("undertorielhome_3_pix");
	if (SCENEMANAGER->CurrentScene("undertorielhome_4"))piximage = IMAGEMANAGER->findImage("undertorielhome_4_pix");
	if (SCENEMANAGER->CurrentScene("torielbattle"))piximage = IMAGEMANAGER->findImage("torielbattle_base");
	if (SCENEMANAGER->CurrentScene("torieldie"))piximage = IMAGEMANAGER->findImage("torielbattle_base");
	if (SCENEMANAGER->CurrentScene("stage15battle"))piximage = IMAGEMANAGER->findImage("torielbattle_base");
	if (SCENEMANAGER->CurrentScene("molbattle"))piximage = IMAGEMANAGER->findImage("torielbattle_base");
	if (SCENEMANAGER->CurrentScene("torielbattle"))piximage = IMAGEMANAGER->findImage("torielbattle_base");
	if (SCENEMANAGER->CurrentScene("monster1"))piximage = IMAGEMANAGER->findImage("torielbattle_base");
	if (SCENEMANAGER->CurrentScene("monster2"))piximage = IMAGEMANAGER->findImage("torielbattle_base");
	if (SCENEMANAGER->CurrentScene("nobody"))piximage = IMAGEMANAGER->findImage("torielbattle_base");
	if (SCENEMANAGER->CurrentScene("last"))piximage = IMAGEMANAGER->findImage("lastload_pix");
	if (SCENEMANAGER->CurrentScene("playerdie"))piximage = IMAGEMANAGER->findImage("dark");
	if (!SCENEMANAGER->CurrentScene("stage1") && !SCENEMANAGER->CurrentScene("stage2") && 
		!SCENEMANAGER->CurrentScene("battle1") && !SCENEMANAGER->CurrentScene("stage2_1") && 
		!SCENEMANAGER->CurrentScene("dummybattle") && !SCENEMANAGER->CurrentScene("ending") 
		&&!_player.changebattle && !_player.playertor
		&& !_player.dontpix )
	{
		for (int i = _player.rc.bottom; i < _player.rc.bottom + 2; i++)
		{

			COLORREF color = GetPixel(piximage->getMemDC(), _player.rc.right, i);

			if (color == RGB(255, 0, 255))
			{
				_player.y -= 2;

			}
		}
		for (int i = _player.rc.bottom; i < _player.rc.bottom + 2; i++)
		{
			COLORREF color = GetPixel(piximage->getMemDC(), _player.rc.left, i);
			if (color == RGB(255, 0, 255))
			{
				_player.y -= 2;

			}
		}
		for (int i = _player.rc.right; i < _player.rc.right + 2; i++)
		{
			COLORREF color = GetPixel(piximage->getMemDC(), i, _player.rc.top + 30);
			if (color == RGB(255, 0, 255))
			{
				_player.x -= 2;

			}
		}
		for (int i = _player.rc.right; i < _player.rc.right + 2; i++)
		{
			COLORREF color = GetPixel(piximage->getMemDC(), i, _player.rc.bottom);
			if (color == RGB(255, 0, 255))
			{
				_player.x -= 2;

			}
		}
		for (int i = _player.rc.top + 30; i > _player.rc.top + 27; i--)
		{
			COLORREF color = GetPixel(piximage->getMemDC(), _player.rc.left, i);
			if (color == RGB(255, 0, 255))
			{
				_player.y += 2;

			}
		}
		for (int i = _player.rc.top + 30; i > _player.rc.top + 27; i--)
		{
			COLORREF color = GetPixel(piximage->getMemDC(), _player.rc.right, i);
			if (color == RGB(255, 0, 255))
			{
				_player.y += 2;

			}
		}
		for (int i = _player.rc.left; i > _player.rc.left - 3; i--)
		{
			COLORREF color = GetPixel(piximage->getMemDC(), i, _player.rc.top + 30);
			if (color == RGB(255, 0, 255))
			{
				_player.x += 2;

			}
		}
		for (int i = _player.rc.left; i > _player.rc.left - 3; i--)
		{
			COLORREF color = GetPixel(piximage->getMemDC(), i, _player.rc.bottom);
			if (color == RGB(255, 0, 255))
			{
				_player.x += 2;

			}
		}
	}
	if (KEYMANAGER->isOnceDown('Z'))
	{
		_player.pressZ = true;
	}
	else
	{
		_player.pressZ = false;
	}
}

void player::render()
{
	if (monsterbeforecount != 0) IMAGEMANAGER->findImage("!")->render(getMemDC(), _player.x + 20, _player.y - 20);
	if (candytextnum != 0)
	{
		IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
	}
	if (knifetextnum != 0)
	{
		IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
	}
	if (pietextnum != 0)
	{
		IMAGEMANAGER->findImage("overtextnull")->render(getMemDC(), _camera->getCam()->x + 30, _camera->getCam()->y + 10);
	}
	candyinfo();
	if (_player.viewEvery )
	{
		SetBkMode(getMemDC(), OPAQUE);
		Rectangle(getMemDC(), _player.rc.left, _player.rc.top, _player.rc.right, _player.rc.bottom);
		Rectangle(getMemDC(), _player.bottomrc.left, _player.bottomrc.top, _player.bottomrc.right, _player.bottomrc.bottom);
		char str[128];
		sprintf_s(str, "_player.x : %d", _player.x);
		TextOut(getMemDC(), _camera->getCam()->x , _camera->getCam()->y, str, strlen(str));

		char str1[128];
		sprintf_s(str1, "_player.y : %d", _player.y);
		TextOut(getMemDC(), _camera->getCam()->x, _camera->getCam()->y +20, str1, strlen(str1));

		if (_player.motion == IDLE)
		{
			char str[128];
			sprintf_s(str, "_player.motion : IDLE");
			TextOut(getMemDC(), _camera->getCam()->x, _camera->getCam()->y +40, str, strlen(str));
		}
		else if (_player.motion == WALK)
		{
			char str[128];
			sprintf_s(str, "_player.motion : WALK");
			TextOut(getMemDC(), _camera->getCam()->x, _camera->getCam()->y + 40, str, strlen(str));
		}

		char str2[128];
		sprintf_s(str2, "_player.isRight : %d", _player.isRight);
		TextOut(getMemDC(), _camera->getCam()->x, _camera->getCam()->y + 60, str2, strlen(str2));

		char str3[128];
		sprintf_s(str3, "_player.isLeft : %d", _player.isLeft);
		TextOut(getMemDC(), _camera->getCam()->x, _camera->getCam()->y + 80, str3, strlen(str3));

		char str4[128];
		sprintf_s(str4, "_player.isUp : %d", _player.isUp);
		TextOut(getMemDC(), _camera->getCam()->x, _camera->getCam()->y + 100, str4, strlen(str4));

		char str5[128];
		sprintf_s(str5, "_player.isDown : %d", _player.isDown);
		TextOut(getMemDC(), _camera->getCam()->x, _camera->getCam()->y + 120, str5, strlen(str5));

		if (SCENEMANAGER->CurrentScene("stage1"))
		{
			char str6[128];
			sprintf_s(str6, "current Scene : stage1");
			TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y, str6, strlen(str6));
		}
		if (SCENEMANAGER->CurrentScene("stage2"))
		{
			char str6[128];
			sprintf_s(str6, "current Scene : stage2");
			TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y, str6, strlen(str6));
		}
		if (SCENEMANAGER->CurrentScene("battle1"))
		{
			char str6[128];
			sprintf_s(str6, "current Scene : battle1");
			TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y, str6, strlen(str6));
		}
		if (SCENEMANAGER->CurrentScene("stage3"))
		{
			char str6[128];
			sprintf_s(str6, "current Scene : stage3");
			TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y, str6, strlen(str6));

		}
		if (SCENEMANAGER->CurrentScene("stage4"))
		{
			char str6[128];
			sprintf_s(str6, "current Scene : stage4");
			TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y, str6, strlen(str6));

		}
		if (SCENEMANAGER->CurrentScene("stage5"))
		{
			char str6[128];
			sprintf_s(str6, "current Scene : stage5");
			TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y, str6, strlen(str6));

		}
		if (SCENEMANAGER->CurrentScene("stage6"))
		{
			char str6[128];
			sprintf_s(str6, "current Scene : stage6");
			TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y, str6, strlen(str6));

		}
		if (SCENEMANAGER->CurrentScene("stage7"))
		{
			char str6[128];
			sprintf_s(str6, "current Scene : stage7");
			TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y, str6, strlen(str6));

		}

		if (SCENEMANAGER->CurrentScene("stage8"))
		{
			char str6[128];
			sprintf_s(str6, "current Scene : stage8");
			TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y, str6, strlen(str6));

		}
		if (SCENEMANAGER->CurrentScene("stage9"))
		{
			char str6[128];
			sprintf_s(str6, "current Scene : stage9");
			TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y, str6, strlen(str6));

		}
		char str7[128];
		sprintf_s(str7, "itemnum0 :%d ", _player.itemarr[0]);
		TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y + 20, str7, strlen(str7));

		char str8[128];
		sprintf_s(str8, "itemnum1 : %d", _player.itemarr[1]);
		TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y + 40, str8, strlen(str8));

		char str9[128];
		sprintf_s(str9, "itemnum2 : %d", _player.itemarr[2]);
		TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y + 60, str9, strlen(str9));

		char str10[128];
		sprintf_s(str10, "itemnum3 : %d", _player.itemarr[3]);
		TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y + 80, str10, strlen(str10));

		char str11[128];
		sprintf_s(str11, "walkcount : %d", Walkcount);
		TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y + 100, str11, strlen(str11));

		char str12[128];
		sprintf_s(str12, "donpix : %d", _player.dontpix);
		TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y + 120, str12, strlen(str12));


		char str13[128];
		sprintf_s(str13, "_player.changebattle : %d", _player.changebattle);
		TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y + 140, str13, strlen(str13));

		char str14[128];
		sprintf_s(str14, "_player.changeindex : %d",_player.changeindex);
		TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y + 160, str14, strlen(str14));

		char str15[128];
		sprintf_s(str15, "_player.battlescnee : %d", _player.battleScene);
		TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y + 180, str15, strlen(str15));

		char str16[128];
		sprintf_s(str16, "_player.tor : %d", _player.playertor);
		TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y + 200, str16, strlen(str16));

		char str17[128];
		sprintf_s(str17, "saveStageNum : %d", _player.SaveStageNum);
		TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y + 220, str17, strlen(str17));

		char str18[128];
		sprintf_s(str18, "killnum : %d", _player.killnum);
		TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y + 320, str18, strlen(str18));

		char str19[128];
		sprintf_s(str19, "monsternum : %d", RndMonsterNum);
		TextOut(getMemDC(), _camera->getCam()->x + 300, _camera->getCam()->y + 340, str19, strlen(str19));

	}
	else
	{
		SetBkMode(getMemDC(), TRANSPARENT);
	}
	if (intro2)
	{
		IMAGEMANAGER->findImage("dark")->render(getMemDC(), _camera->getCam()->x, _camera->getCam()->y);
	}
	if (_player.changeScene)
	{
		IMAGEMANAGER->findImage("player")->frameRender(getMemDC(), _player.x, _player.y);
	}
	if (!_player.changebattle || _player.changeindex >= 7)
	{
		if (!_player.battleScene && !_player.playertor)
			IMAGEMANAGER->findImage("player")->frameRender(getMemDC(), _player.x, _player.y);
	}
	if (_player.changebattle && _player.changeindex < 7)
	{
		changecount++;
		if (changecount % 6 == 0)
			_player.changeindex++;
		if (_player.changeindex % 2 == 0)
			IMAGEMANAGER->findImage("player")->frameRender(getMemDC(), _player.x, _player.y);
		else
			IMAGEMANAGER->findImage("heart")->render(getMemDC(), _player.x + IMAGEMANAGER->findImage("heart")->getWidth() / 2 + 2, _player.y + IMAGEMANAGER->findImage("heart")->getHeight() / 2 + 15);

	}
	
	if (_player.changeindex > 6 && !SCENEMANAGER->CurrentScene("stage15battle"))
	{
		IMAGEMANAGER->findImage("heart")->render(getMemDC(), _player.x + IMAGEMANAGER->findImage("heart")->getWidth() / 2 + 2, _player.y + IMAGEMANAGER->findImage("heart")->getHeight() / 2 + 15);

	}
	if (_player.playerRender)
	{
		//IMAGEMANAGER->findImage("player")->frameRender(getMemDC(), _player.x, _player.y);
	}
	InvenRender();
}

void player::FrameUpdate()
{
	count++;
	//if (count > 1000) count = 0;
	if (_player.isDown)
		_player.image->setFrameY(0);
	else if (_player.isUp)
		_player.image->setFrameY(1);
	else if (_player.isLeft)
		_player.image->setFrameY(2);
	else if (_player.isRight)
		_player.image->setFrameY(3);
	if (count % 10 == 0)
	{
		if (_player.motion == WALK)
		{
			_player.image->setFrameX(index);
			index++;
			if (index > _player.image->getMaxFrameX()) index = 0;
		}
		else if (_player.motion == IDLE)
		{
			_player.image->setFrameX(0);
		}
	}
	if (_player.frameReset)
	{
		_player.image->setFrameX(0);
		_player.frameReset = false;
	}
}

void player::KeyControl()
{
	if (KEYMANAGER->isStayDown(VK_LEFT))
	{
		_player.motion = WALK;
		_player.isDown = false;
		_player.isRight = false;
		_player.isUp = false;
		_player.isLeft = true;
		_player.x -= 2;
	}
	if (KEYMANAGER->isStayDown(VK_RIGHT))
	{
		_player.motion = WALK;
		_player.isDown = false;
		_player.isLeft = false;
		_player.isUp = false;
		_player.isRight = true;
		_player.x += 2;
	}
	if (KEYMANAGER->isStayDown(VK_DOWN))
	{
		_player.motion = WALK;
		_player.isLeft = false;
		_player.isRight = false;
		_player.isUp = false;
		_player.isDown = true;
		_player.y += 2;
	}
	if (KEYMANAGER->isStayDown(VK_UP))
	{
		_player.motion = WALK;
		_player.isDown = false;
		_player.isLeft = false;
		_player.isRight = false;
		_player.isUp = true;
		_player.y -= 2;
	}
	if(!KEYMANAGER->isStayDown(VK_LEFT) && !KEYMANAGER->isStayDown(VK_RIGHT) && !KEYMANAGER->isStayDown(VK_UP) 
		&& !KEYMANAGER->isStayDown(VK_DOWN))
	{
		_player.motion = IDLE;
	}
	

}
void player::entrybattle()
{
	if (_player.changeindex > 6)
	{
		_player.changebattle = false;
		_player.battleScene = true;
	}
}

void player::talkControl()
{
	
	if (KEYMANAGER->isOnceDown('Z'))
	{
		_player.talk = true;
		
		_player.image->setFrameX(0);
		if (_player.talkindex < 0)
		{
			_player.talk = false;
			_player.talkindex = 0;
			
		}
		else _player.talkindex -= 1;
	}
}

void player::InvenUpdate() //아이템번호1 - > 괴물사탕 // 4 - > 장난감칼 //5 - > 파이
{
	if (KEYMANAGER->isOnceDown('C') && !SCENEMANAGER->CurrentScene("torielbattle") 
		&& !SCENEMANAGER->CurrentScene("battle1") 
		&& !SCENEMANAGER->CurrentScene("stage7battle") 
		&& !SCENEMANAGER->CurrentScene("stage15battle") 
		&& !SCENEMANAGER->CurrentScene("dummybattle")
		&& !SCENEMANAGER->CurrentScene("stage7"))
	{
		_player.viewInven = true;
	}
	
	if (_player.viewInven)
	{
	
		if (!itemview && !stateview)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				if (point == 0) itemview = true;
				if (point == 35) stateview = true;
			}
		}
		if (!infomonstercandy)
		{
			if (KEYMANAGER->isOnceDown('X'))
			{
				if (itemview || stateview)
				{
					itemview = false;
					stateview = false;
				}
				else
				{
					_player.viewInven = false;
				}
			}
		}
		if (!itemview && !stateview)
		{
			if (KEYMANAGER->isOnceDown(VK_DOWN))
			{
				point = 35; // 스텟
			}
			if (KEYMANAGER->isOnceDown(VK_UP))
			{
				point = 0; //물품
			}
		}
		if (itemview) //1번자리 222,78 에 y값 30씩 추가
		{
			if (!infomonstercandy)
			{
				if (KEYMANAGER->isOnceDown(VK_DOWN))
				{
					if (itemarr < 240)
						itemarr += 30;
				}
				if (KEYMANAGER->isOnceDown(VK_UP))
				{
					if (itemarr > 0)
						itemarr -= 30;
				}

				for (int i = 0; i < 8; i++)
				{
					if (_player.itemarr[i] != 0) //아이템창이 빈칸이 아닐때
					{
						if (itemarr == i * 30) //아이템커서가 0~8 에 있을때
						{
							if (_player.itemarr[i] == 1) //괴물사탕일때
							{
								if (KEYMANAGER->isOnceDown('Z')) //z누르면
								{
									infomonstercandy = true;
									itemnum = i;
								}
							}
							
						}
					}

				}
			}
			if (!infoknife)
			{
				if (KEYMANAGER->isOnceDown(VK_DOWN))
				{
					if (itemarr < 240)
						itemarr += 30;
				}
				if (KEYMANAGER->isOnceDown(VK_UP))
				{
					if (itemarr > 0)
						itemarr -= 30;
				}

				for (int i = 0; i < 8; i++)
				{
					if (_player.itemarr[i] != 0) //아이템창이 빈칸이 아닐때
					{
						if (itemarr == i * 30) //아이템커서가 0~8 에 있을때
						{
							if (_player.itemarr[i] == 4) //장난감 칼일때
							{
								if (KEYMANAGER->isOnceDown('Z')) //z누르면
								{
									infoknife = true;
									itemnum = i;
								}
							}

						}
					}

				}
				
			}

			if (!infopie)
			{
				if (KEYMANAGER->isOnceDown(VK_DOWN))
				{
					if (itemarr < 240)
						itemarr += 30;
				}
				if (KEYMANAGER->isOnceDown(VK_UP))
				{
					if (itemarr > 0)
						itemarr -= 30;
				}

				for (int i = 0; i < 8; i++)
				{
					if (_player.itemarr[i] != 0) //아이템창이 빈칸이 아닐때
					{
						if (itemarr == i * 30) //아이템커서가 0~8 에 있을때
						{
							if (_player.itemarr[i] == 5) //파이 일때
							{
								if (KEYMANAGER->isOnceDown('Z')) //z누르면
								{
									infopie = true;
									itemnum = i;
								}
							}

						}
					}

				}

			}

		}
		if (stateview)
		{
			
		}
		if (infomonstercandy) //iteminfoarr 0 일때 사용 100일때 정보 200일때 버림
		{
			if (KEYMANAGER->isOnceDown(VK_RIGHT))
			{
				if (iteminfoarr < 200)
				    iteminfoarr += 100;
			}
			if (KEYMANAGER->isOnceDown(VK_LEFT))
			{
				if (iteminfoarr > 0)
					iteminfoarr -= 100;
			}
			if (KEYMANAGER->isOnceDown('Z'))
			{
				if (iteminfoarr == 0) //사용
				{
					_player.CurHp += 10;
					usecandy = true;
					_player.itemarr[itemnum] = 0;
					_player.viewInven = false;
					itemview = false;
					stateview = false;
					infomonstercandy = false;
					candytextnum = 1;
					if (SCENEMANAGER->CurrentScene("stage9_1"))_player.candynum -= 1;
				}

				if (iteminfoarr == 100) //정보
				{
					infocandy = true;
					_player.viewInven = false;
					itemview = false;
					stateview = false;
					infomonstercandy = false;
					candytextnum = 2;
				}
				if (iteminfoarr == 200) //버림
				{
					_player.itemarr[itemnum] = 0;
					_player.viewInven = false;
					itemview = false;
					stateview = false;
					infomonstercandy = false;
					candytextnum = 3;
					if (SCENEMANAGER->CurrentScene("stage9_1"))_player.candynum -= 1;
				}
			}
			if (KEYMANAGER->isOnceDown('X'))
			{
				infomonstercandy = false;
				infoknife = false;
				infopie = false;
			}
		}

		if (infoknife) //iteminfoarr 0 일때 사용 100일때 정보 200일때 버림
		{
			if (KEYMANAGER->isOnceDown(VK_RIGHT))
			{
				if (iteminfoarr < 200)
					iteminfoarr += 100;
			}
			if (KEYMANAGER->isOnceDown(VK_LEFT))
			{
				if (iteminfoarr > 0)
					iteminfoarr -= 100;
			}
			if (KEYMANAGER->isOnceDown('Z'))
			{
				if (iteminfoarr == 0) //사용
				{
					
					useknife = true;
					_player.itemarr[itemnum] = 0;
					_player.viewInven = false;
					itemview = false;
					stateview = false;
					infoknife = false;
					knifetextnum = 1;
					_player.At = 3;
					
				}

				if (iteminfoarr == 100) //정보
				{
					
					_player.viewInven = false;
					itemview = false;
					stateview = false;
					infoknife = false;
					knifetextnum = 2;
				}
				if (iteminfoarr == 200) //버림
				{
					_player.itemarr[itemnum] = 0;
					_player.viewInven = false;
					itemview = false;
					stateview = false;
					infoknife = false;
					knifetextnum = 3;
					
				}
			}
			if (KEYMANAGER->isOnceDown('X'))
			{
				infomonstercandy = false;
				infoknife = false;
				infopie = false;
			}
		}

		if (infopie) //iteminfoarr 0 일때 사용 100일때 정보 200일때 버림
		{
			if (KEYMANAGER->isOnceDown(VK_RIGHT))
			{
				if (iteminfoarr < 200)
					iteminfoarr += 100;
			}
			if (KEYMANAGER->isOnceDown(VK_LEFT))
			{
				if (iteminfoarr > 0)
					iteminfoarr -= 100;
			}
			if (KEYMANAGER->isOnceDown('Z'))
			{
				if (iteminfoarr == 0) //사용
				{

					
					_player.itemarr[itemnum] = 0;
					_player.viewInven = false;
					itemview = false;
					stateview = false;
					infopie = false;
					pietextnum = 1;
					_player.CurHp = _player.MaxHp;
					//먹는사운드

				}

				if (iteminfoarr == 100) //정보
				{

					_player.viewInven = false;
					itemview = false;
					stateview = false;
					infopie = false;
					pietextnum = 2;
				}
				if (iteminfoarr == 200) //버림
				{
					_player.itemarr[itemnum] = 0;
					_player.viewInven = false;
					itemview = false;
					stateview = false;
					infopie = false;
					pietextnum = 3;

				}
			}
			if (KEYMANAGER->isOnceDown('X'))
			{
				infomonstercandy = false;
				infoknife = false;
				infopie = false;
			}
		}
	}

}

void player::InvenRender()
{
	if (_player.viewInven)
	{
		IMAGEMANAGER->findImage("Inven")->render(getMemDC(),_camera->getCam()->x + 20,_camera->getCam()->y + 50);
		IMAGEMANAGER->findImage("heart")->render(getMemDC(), _camera->getCam()->x + 45, _camera->getCam()->y + 190 + point);
		
		if (!itemview && !stateview)
		{
			if (KEYMANAGER->isOnceDown(VK_DOWN))
			{
				point = 35; // 스텟
			}
			if (KEYMANAGER->isOnceDown(VK_UP))
			{
				point = 0; //물품
			}
		}
		if (itemview) //1번자리 222,78 에 y값 30씩 추가
		{
			IMAGEMANAGER->findImage("Inven_item")->render(getMemDC(), _camera->getCam()->x + 180, _camera->getCam()->y + 50);
			
			IMAGEMANAGER->findImage("heart")->render(getMemDC(), _camera->getCam()->x + 200, _camera->getCam()->y + 85 + itemarr);
			
			for (int i = 0; i < 8; i++)
			{
				
				if(_player.itemarr[i] == 1) IMAGEMANAGER->findImage("monstercandy")->render(getMemDC(), _camera->getCam()->x + 222, _camera->getCam()->y + 78 + 30 * i);
				if (_player.itemarr[i] == 4) IMAGEMANAGER->findImage("knifetext")->render(getMemDC(), _camera->getCam()->x + 222, _camera->getCam()->y + 78 + 30 * i);
				if (_player.itemarr[i] == 5) IMAGEMANAGER->findImage("pietext")->render(getMemDC(), _camera->getCam()->x + 222, _camera->getCam()->y + 73 + 30 * i);

			}
			
		}
		if (stateview)
		{
			if(_player.At == 0)
			IMAGEMANAGER->findImage("Inven_state")->render(getMemDC(), _camera->getCam()->x + 180, _camera->getCam()->y + 50);
			if (_player.At == 3)
			IMAGEMANAGER->findImage("Inven_state2")->render(getMemDC(), _camera->getCam()->x + 180, _camera->getCam()->y + 50);
		}
		if (infomonstercandy && itemview)
		{
			IMAGEMANAGER->findImage("heart")->render(getMemDC(), _camera->getCam()->x + 200 + iteminfoarr, _camera->getCam()->y + 365);
			
		}
		if (infoknife && itemview)
		{
			IMAGEMANAGER->findImage("heart")->render(getMemDC(), _camera->getCam()->x + 200 + iteminfoarr, _camera->getCam()->y + 365);

		}
		if (infopie && itemview)
		{
			IMAGEMANAGER->findImage("heart")->render(getMemDC(), _camera->getCam()->x + 200 + iteminfoarr, _camera->getCam()->y + 365);

		}
	}
}



void player::candyinfo()
{
	HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																										  //폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR buf[100] = _T("");
	DWORD dwRead;

	HANDLE hInputFile;

	if (candytextnum == 1)
		hInputFile = CreateFile(_T("text/item/eatcandy.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (candytextnum == 2)
		hInputFile = CreateFile(_T("text/item/infocandy.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (candytextnum == 3)
		hInputFile = CreateFile(_T("text/item/dropcandy.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (knifetextnum == 1)
		hInputFile = CreateFile(_T("text/item/eatknife.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (knifetextnum == 2)
		hInputFile = CreateFile(_T("text/item/infoknife.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (knifetextnum == 3)
		hInputFile = CreateFile(_T("text/item/dropknife.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (pietextnum == 1)
		hInputFile = CreateFile(_T("text/item/usepie.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (pietextnum == 2)
		hInputFile = CreateFile(_T("text/item/infopie.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (pietextnum == 3)
		hInputFile = CreateFile(_T("text/item/droppie.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

	ReadFile(hInputFile, buf, 999 * sizeof(TCHAR), &dwRead, NULL);
	CloseHandle(hInputFile);

	//TextOut(getMemDC(), 80, 200, buf, 2 * tindex);
	DrawText(getMemDC(), buf, candyindex, &candytextrc, DT_LEFT);
	DeleteObject(font);
	font = CreateFont(20, 0, 0, 0, 0, 0, 0, 00, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, NULL);
	SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	DeleteObject(font);
}

void player::candytextupdate()
{

	candycount++;
	if (candycount > 1000) candycount = 0;
	if (candycount % 3 == 0)
	{
		if (candytextnum == 1)
		{
			if (candyindex < 79)
				candyindex++;
		}
		if (candytextnum == 2)
		{
			if (candyindex < 23)
				candyindex++;
		}
		if (candytextnum == 3)
		{
			if (candyindex < 63)
				candyindex++;
		}
		if (knifetextnum == 1)
		{
			if (candyindex < 23)
				candyindex++;
		}
		if (knifetextnum == 2)
		{
			if (candyindex < 65)
				candyindex++;
		}
		if (knifetextnum == 3)
		{
			if (candyindex < 23)
				candyindex++;
		}
		if (pietextnum == 1)
		{
			if (candyindex < 52)
				candyindex++;
		}
		if (pietextnum == 2)
		{
			if (candyindex < 74)
				candyindex++;
		}
		if (pietextnum == 3)
		{
			if (candyindex < 33)
				candyindex++;
		}
		
	}


	if (candytextnum == 1)
	{
		if (candyindex == 79)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				candyindex = 0;
				candytextnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) candyindex = 79;
		}
	}
	if (candytextnum == 2)
	{
		if (candyindex == 67)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				candyindex = 0;
				candytextnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) candyindex = 67;
		}
	}
	if (candytextnum == 3)
	{
		if (candyindex >= 23)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				candyindex = 0;
				candytextnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) candyindex = 23;
		}
	}

	if (knifetextnum == 1)
	{
		if (candyindex == 23)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				candyindex = 0;
				knifetextnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) candyindex = 23;
		}
	}
	if (knifetextnum == 2)
	{
		if (candyindex == 65)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				candyindex = 0;
				knifetextnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) candyindex = 65;
		}
	}
	if (knifetextnum == 3)
	{
		if (candyindex >= 23)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				candyindex = 0;
				knifetextnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) candyindex = 23;
		}
	}
	if (pietextnum == 1)
	{
		if (candyindex == 52)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				candyindex = 0;
				pietextnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) candyindex = 52;
		}
	}
	if (pietextnum == 2)
	{
		if (candyindex == 74)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				candyindex = 0;
				pietextnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) candyindex = 74;
		}
	}
	if (pietextnum == 3)
	{
		if (candyindex >= 33)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				candyindex = 0;
				pietextnum = 0;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceDown('X')) candyindex = 33;
		}
	}
}

void player::Turn()
{
	
	if (_player.turn)
	{
		if (!SOUNDMANAGER->isPlaySound("fall") && !once)
		{
			SOUNDMANAGER->play("fall", 1.f);
			once = true;
		}
		turncount++;
		if (turnindex > 3)turnindex = 0;
		else
		{
			if (turncount % 10 == 0) turnindex++;
		}
		if (turnindex == 0) fuckingturn = 0;
		if (turnindex == 1) fuckingturn = 3;
		if (turnindex == 2) fuckingturn = 1;
		if (turnindex == 3) fuckingturn = 2;
		_player.image->setFrameY(fuckingturn);
	}
	else if(!_player.turn)
	{
		_player.frame = true;
		once = false;
	}
}

void player::MonsterMeet()
{
	if (_player.SaveStageNum >= 9 && _player.SaveStageNum != 10 && _player.SaveStageNum != 13 
		&& _player.SaveStageNum != 14 && _player.SaveStageNum !=15 && _player.SaveStageNum != 18 
		&& _player.SaveStageNum != 19 && _player.SaveStageNum != 20 && _player.SaveStageNum != 21)
	{
		if (_player.motion == WALK)
		{
			if(_player.control)
			_player.walkcount++;
			if (_player.walkcount > 1000)
			{
				if (monsterbeforecount < 50)
				{
					_player.control = false;

					if (!SOUNDMANAGER->isPlaySound("introbattle")&&!introonce)
					{
						SOUNDMANAGER->play("introbattle",1.f);
						introonce = true;
					}
					monsterbeforecount++;
				}
				if (monsterbeforecount >= 50)
				{
					_player.control = true;

					_player.SaveX = _player.x;
					_player.SaveY = _player.y;
					_player.savecamx = _camera->getCam()->x;
					_player.savecamy = _camera->getCam()->y;
					//if (RndMonsterNum == 0)
						RndMonsterNum = RND->getFromIntTo(1, 3);
					intro2 = true;
					
					monsterbeforecount = 0;
					_player.walkcount = 0;
				}
			}
		}
		if (intro2)
		{
			introcount++;

			_player.changebattle = true;
			if(!SOUNDMANAGER->isPlaySound("entrybattle") && !entryonce)
			{
				SOUNDMANAGER->play("entrybattle", 1.f);
				entryonce = true;
			}
			if (_player.changeindex > 6)
			{
				_camera->cam.cameramove = false;
				endx = _camera->getCam()->x - 120;
				endy = _camera->getCam()->y + 554;


				

				_player.ischangebattle = true;
				_player.dontpix= true;
				speed = (MY_UTIL::getDistance(_player.x, _player.y, _camera->getCam()->x + 24, _camera->getCam()->y + 400));
				speedx = (MY_UTIL::getDistance(_player.x, _player.x, endx, endx));
				speedy = (MY_UTIL::getDistance(_player.y, _player.y, endy, endy));

				count2 += 166;
				ischange = true;
				if (_player.x > endx)
				{
					if (count2 % 10000)
					{
						_player.x -= speedx / 65;

					}
				}
				else if (_player.x < endx)
				{
					if (count2 % 10000)
					{
						_player.x += speedx / 65;

					}
				}

				if (_player.y < endy)
				{
					if (count2 % 10000)
					{
						_player.y += speedy / 65;

					}
				}
				else if (_player.y > endy)
				{
					if (count2 % 10000)
					{
						_player.y -= speedy / 65;

					}
				}


				
				if (ischange && count2 > 8000)
				{
					_camera->getCam()->cameramove = true;
					intro2 = false;
					_player.changeindex = 0;
					_player.changebattle = false;
					_player.changeScene = false;
					_player.battleScene = false;
					entryonce = false;
					introonce = false;
					count2 = 0;
					ischange = false;
					if (_player.killnum < 10)
					{
						if (RndMonsterNum == 1)SCENEMANAGER->changeScene("monster1");
						if (RndMonsterNum == 2)SCENEMANAGER->changeScene("monster2");
						if (RndMonsterNum == 3)SCENEMANAGER->changeScene("molbattle");
					}
					else
					{
						SCENEMANAGER->changeScene("nobody");
					}
				}
			}
		
		}
	}
}

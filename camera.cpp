#include "stdafx.h"
#include "camera.h"
#include "player.h"

camera::camera()
{
}


camera::~camera()
{
}

HRESULT camera::init()
{

	IMAGEMANAGER->addImage("torielbattle_base", "image/undertale/battle/torielbattle/torielbattle_base.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("lastload", "image/undertale/last/lastload.bmp", 641, 3837, false, false);
	cam.overviewX = false;
	cam.overviewY = false;
	cam.cameramove = true;
	boomx = 0;
	boomy = 0;
	countx = 0;
	county = 0;
	indexx = 0;
	indexy = 0;
	boomover = false;
	return S_OK;
}

void camera::release()
{
}

void camera::update()
{
	if (cam.cameramove)
	{
		if (SCENEMANAGER->CurrentScene("stage1")) cam.maprc = IMAGEMANAGER->findImage("stage1")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage2"))
		{
			cam.maprc = IMAGEMANAGER->findImage("stage2")->boundingBox();
		}
		if (SCENEMANAGER->CurrentScene("stage2_1"))cam.maprc = IMAGEMANAGER->findImage("stage2_1")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage3"))cam.maprc = IMAGEMANAGER->findImage("stage3")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage4"))cam.maprc = IMAGEMANAGER->findImage("stage4")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage5"))cam.maprc = IMAGEMANAGER->findImage("stage5")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage6"))cam.maprc = IMAGEMANAGER->findImage("stage6")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage7"))cam.maprc = IMAGEMANAGER->findImage("stage7")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage8"))cam.maprc = IMAGEMANAGER->findImage("stage8")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage9"))cam.maprc = IMAGEMANAGER->findImage("stage9")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage9_1"))cam.maprc = IMAGEMANAGER->findImage("stage9_1")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage10"))cam.maprc = IMAGEMANAGER->findImage("stage10")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage11"))cam.maprc = IMAGEMANAGER->findImage("stage11")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage12"))cam.maprc = IMAGEMANAGER->findImage("stage12")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage13"))cam.maprc = IMAGEMANAGER->findImage("stage13")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage14"))cam.maprc = IMAGEMANAGER->findImage("stage14")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage15"))cam.maprc = IMAGEMANAGER->findImage("stage15")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage15battle"))cam.maprc = IMAGEMANAGER->findImage("stage15")->boundingBox();
        if (SCENEMANAGER->CurrentScene("stage15_store"))cam.maprc = IMAGEMANAGER->findImage("stage15_store")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage16"))cam.maprc = IMAGEMANAGER->findImage("stage16")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage17"))cam.maprc = IMAGEMANAGER->findImage("stage17")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage18"))cam.maprc = IMAGEMANAGER->findImage("stage18")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage19"))cam.maprc = IMAGEMANAGER->findImage("stage19")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage20"))cam.maprc = IMAGEMANAGER->findImage("stage20")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage21"))cam.maprc = IMAGEMANAGER->findImage("stage21")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage18_21_traproom"))cam.maprc = IMAGEMANAGER->findImage("stage18_21_traproom")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage22"))cam.maprc = IMAGEMANAGER->findImage("stage22")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage22_1"))cam.maprc = IMAGEMANAGER->findImage("stage22_1")->boundingBox();
		if (SCENEMANAGER->CurrentScene("stage22_2"))cam.maprc = IMAGEMANAGER->findImage("stage22_2")->boundingBox();
		if (SCENEMANAGER->CurrentScene("torielgarden"))cam.maprc = IMAGEMANAGER->findImage("torielgarden")->boundingBox();
		if (SCENEMANAGER->CurrentScene("torielhome"))cam.maprc = IMAGEMANAGER->findImage("torielhome")->boundingBox();
		if (SCENEMANAGER->CurrentScene("leftroom"))cam.maprc = IMAGEMANAGER->findImage("leftroom")->boundingBox();
		if (SCENEMANAGER->CurrentScene("kitchen"))cam.maprc = IMAGEMANAGER->findImage("kitchen")->boundingBox();
		if (SCENEMANAGER->CurrentScene("rightroom"))cam.maprc = IMAGEMANAGER->findImage("rightroom")->boundingBox();
		if (SCENEMANAGER->CurrentScene("myroom"))cam.maprc = IMAGEMANAGER->findImage("myroom")->boundingBox();
		if (SCENEMANAGER->CurrentScene("torielroom"))cam.maprc = IMAGEMANAGER->findImage("torielroom")->boundingBox();
		if (SCENEMANAGER->CurrentScene("undertorielhome_1"))cam.maprc = IMAGEMANAGER->findImage("undertorielhome_1")->boundingBox();
		if (SCENEMANAGER->CurrentScene("undertorielhome_2"))cam.maprc = IMAGEMANAGER->findImage("undertorielhome_2")->boundingBox();
		if (SCENEMANAGER->CurrentScene("undertorielhome_3"))cam.maprc = IMAGEMANAGER->findImage("undertorielhome_3")->boundingBox();
		if (SCENEMANAGER->CurrentScene("undertorielhome_4"))cam.maprc = IMAGEMANAGER->findImage("undertorielhome_4")->boundingBox();
		if (SCENEMANAGER->CurrentScene("torielbattle"))cam.maprc = IMAGEMANAGER->findImage("torielbattle_base")->boundingBox();
		if (SCENEMANAGER->CurrentScene("torieldie"))cam.maprc = IMAGEMANAGER->findImage("dark")->boundingBox();
		if (SCENEMANAGER->CurrentScene("molbattle"))cam.maprc = IMAGEMANAGER->findImage("dark")->boundingBox();
		if (SCENEMANAGER->CurrentScene("monster1"))cam.maprc = IMAGEMANAGER->findImage("dark")->boundingBox();
		if (SCENEMANAGER->CurrentScene("monster2"))cam.maprc = IMAGEMANAGER->findImage("dark")->boundingBox();
		if (SCENEMANAGER->CurrentScene("nobody"))cam.maprc = IMAGEMANAGER->findImage("dark")->boundingBox();
		if (SCENEMANAGER->CurrentScene("last"))cam.maprc = IMAGEMANAGER->findImage("lastload")->boundingBox();
		if (SCENEMANAGER->CurrentScene("ending"))cam.maprc = IMAGEMANAGER->findImage("lastending")->boundingBox();
		//if (SCENEMANAGER->CurrentScene("dummybattle"))cam.maprc = IMAGEMANAGER->findImage("stage2")->boundingBox();
		if (SCENEMANAGER->CurrentScene("playerdie"))cam.maprc = IMAGEMANAGER->findImage("dark")->boundingBox();
		if (!cam.overviewX) cam.x = _player->getPlayer()->x - WINSIZEX / 2 + _player->getPlayer()->image->getFrameWidth() / 2;
		if (!cam.overviewY) cam.y = _player->getPlayer()->y - WINSIZEY / 2 + _player->getPlayer()->image->getFrameHeight() / 2;

		cam.rc = RectMake(cam.x, cam.y, WINSIZEX, WINSIZEY);

		if (cam.rc.left < 0 || cam.rc.right > cam.maprc.right)
		{
			cam.overviewX = true;

		}
		if (cam.overviewX)
		{



			if (cam.maprc.right > _player->getPlayer()->x + WINSIZEX / 2 + _player->getPlayer()->image->getFrameWidth() / 2 &&
				cam.maprc.left < _player->getPlayer()->x - WINSIZEX / 2 + _player->getPlayer()->image->getFrameWidth() / 2)
				cam.overviewX = false;

		}


		if (cam.rc.top < 0 || cam.rc.bottom > cam.maprc.bottom)
		{
			cam.overviewY = true;
			if (saveY == 0)saveY = _player->getPlayer()->y - WINSIZEY / 2 + _player->getPlayer()->image->getFrameHeight() / 2;
		}
		if (cam.overviewY)
		{


			if (cam.maprc.top < _player->getPlayer()->y - WINSIZEY / 2 + _player->getPlayer()->image->getFrameHeight() / 2 &&
				cam.maprc.bottom >_player->getPlayer()->y + WINSIZEY / 2 + _player->getPlayer()->image->getFrameHeight() / 2)
				cam.overviewY = false;


		}
	}
	else 
	{
		
	}

	if (_player->getPlayer()->boom)
	{
		if (indexx > 10)
		{
			boomover = true;

			
		}
		else if(indexx <= 10)
		{
			cam.x += boomx;
			countx++;
			if (countx % 2 == 0)
			{
				indexx++;
			}
			if (indexx % 2 == 1) boomx = 10;
			else if (indexx % 2 == 0) boomx = -10;
		}
		
	}
	if (boomover)
	{
		_player->getPlayer()->boom = false;
		countx = 0;
		indexx = 0;
		boomx = 0;
		boomover = false;
	}
	
	
}

void camera::render()
{
	if (_player->getPlayer()->viewEvery)
	{
		char str[128];
		sprintf_s(str, "cam.x : %d", cam.x);
		TextOut(getMemDC(), cam.x, cam.y + 140, str, strlen(str));

		char str1[128];
		sprintf_s(str1, "cam.y : %d", cam.y);
		TextOut(getMemDC(), cam.x, cam.y + 160, str1, strlen(str1));

		char str2[128];
		sprintf_s(str2, "cam.rc.left : %d", cam.rc.left);
		TextOut(getMemDC(), cam.x, cam.y + 180, str2, strlen(str2));

		char str3[128];
		sprintf_s(str3, "cam.rc.top : %d", cam.rc.top);
		TextOut(getMemDC(), cam.x, cam.y + 200, str3, strlen(str3));

		char str4[128];
		sprintf_s(str4, "cam.rc.right : %d", cam.rc.right);
		TextOut(getMemDC(), cam.x, cam.y + 220, str4, strlen(str4));

		char str5[128];
		sprintf_s(str5, "cam.rc.bottom : %d", cam.rc.bottom);
		TextOut(getMemDC(), cam.x, cam.y + 240, str5, strlen(str5));

		char str6[128];
		sprintf_s(str6, "isOverViewX ? : %d", cam.overviewX);
		TextOut(getMemDC(), cam.x, cam.y + 260, str6, strlen(str6));

		char str7[128];
		sprintf_s(str7, "isOverViewY ? : %d", cam.overviewY);
		TextOut(getMemDC(), cam.x, cam.y + 280, str7, strlen(str7));

		char str8[128];
		sprintf_s(str8, "cam.maprc.width : %d", cam.maprc.right - cam.maprc.left);
		TextOut(getMemDC(), cam.x, cam.y + 300, str8, strlen(str8));

		char str9[128];
		sprintf_s(str9, "cam.maprc.height : %d", cam.maprc.bottom - cam.maprc.top);
		TextOut(getMemDC(), cam.x, cam.y + 320, str9, strlen(str9));
	}


}

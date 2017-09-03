#include "stdafx.h"
#include "gameStudy.h"


gameStudy::gameStudy()
{
}


gameStudy::~gameStudy()
{
}

//초기화는 여기서 한다
HRESULT gameStudy::init()
{ 
	gameNode::init(true);
	//bgm
	SOUNDMANAGER->addSound("flower1", "sound/flower1.mp3", true, true);
	SOUNDMANAGER->addSound("stagesound", "sound/stagesound.mp3", true, true);
	SOUNDMANAGER->addSound("stage8sound", "sound/stage8sound.ogg", true, true);
	SOUNDMANAGER->addSound("battlesound", "sound/battlesound.mp3", true, true);
	SOUNDMANAGER->addSound("midbosssound", "sound/midbosssound.mp3", true, true);
	SOUNDMANAGER->addSound("deadsound", "sound/deadsound.mp3", true, true);
	SOUNDMANAGER->addSound("torhome", "sound/torhome.mp3", true, true);
	SOUNDMANAGER->addSound("boss", "sound/boss.mp3", true, true);
	SOUNDMANAGER->addSound("alldie", "sound/alldie.mp3", true, true);
	SOUNDMANAGER->addSound("flowerdie", "sound/flowerdie.mp3", true, true);
	SOUNDMANAGER->addSound("dummy", "sound/dummy.ogg", true, true);
	SOUNDMANAGER->addSound("undersound", "sound/undersound.ogg", true, true);
	SOUNDMANAGER->addSound("opening", "sound/opening.mp3", false, false);
	//soundeffect
	SOUNDMANAGER->addSound("attacksound", "sound/attacksound.wav", false, false);
	SOUNDMANAGER->addSound("flowerlaugh", "sound/flowerlaugh.wav", false, false);
	SOUNDMANAGER->addSound("heal", "sound/heal.wav", false, false);
	SOUNDMANAGER->addSound("heartbreak", "sound/heartbreak.wav", false, false);
	SOUNDMANAGER->addSound("heartbreak2", "sound/heartbreak2.wav", false, false);
	SOUNDMANAGER->addSound("flowerbullet", "sound/flowerbullet.wav", false, false);
	SOUNDMANAGER->addSound("introbattle", "sound/introbattle.wav", false, false);
	SOUNDMANAGER->addSound("introbattle2", "sound/introbattle2.wav", false, false);
	SOUNDMANAGER->addSound("playerattack", "sound/playerattack.wav", false, false);
	SOUNDMANAGER->addSound("playerhit", "sound/playerhit.wav", false, false);
	SOUNDMANAGER->addSound("trapdown", "sound/trapdown.wav", false, false);
	SOUNDMANAGER->addSound("underattack", "sound/underattack.wav", false, false);
	SOUNDMANAGER->addSound("flowermakebullet", "sound/flowermakebullet.wav", false, false);
	SOUNDMANAGER->addSound("talksound", "sound/talksound.wav", false, false);
	SOUNDMANAGER->addSound("trapdown2", "sound/trapdown2.wav", false, false);
	SOUNDMANAGER->addSound("mouse", "sound/mouse.wav", false, false);
	SOUNDMANAGER->addSound("save", "sound/save.wav", false, false);
	SOUNDMANAGER->addSound("monsterdead", "sound/monsterdead.wav", false, false);
	SOUNDMANAGER->addSound("entrybattle", "sound/entrybattle.wav", false, false);
	SOUNDMANAGER->addSound("trapdown3", "sound/trapdown3.wav", false, false);
	SOUNDMANAGER->addSound("boom", "sound/boom.wav", false, false);
	SOUNDMANAGER->addSound("fall", "sound/fall.ogg", false, false);
	SOUNDMANAGER->addSound("pointmove", "sound/pointmove.wav", false, false);
	SOUNDMANAGER->addSound("pointselect", "sound/pointselect.wav", false, false);
	SOUNDMANAGER->addSound("runout", "sound/runout.wav", false, false);
	SOUNDMANAGER->addSound("lastflowerfun", "sound/lastflowerfun.wav", false, false);

	IMAGEMANAGER->addImage("heart", "image/undertale/battle/heart.bmp", 16, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pillar", "image/undertale/object/pillar.bmp", 72, 120, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("textnull", "image/undertale/event/stage6Event/textnull.bmp", 578, 151, false, false);
	IMAGEMANAGER->addImage("overtextnull", "image/undertale/event/overtextnull.bmp", 578, 151, false, false);
	IMAGEMANAGER->addImage("monstercandy", "image/undertale/item/monstercandy.bmp", 138, 31, false, false); //괴물사탕 아이템번호 1번
	IMAGEMANAGER->addImage("hole", "image/undertale/object/hole.bmp", 40, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tree", "image/undertale/object/tree.bmp", 198, 127, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("!", "image/undertale/object/!.bmp", 20, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("dark", "image/undertale/stage/dark.bmp", 640, 480, false, false);
	IMAGEMANAGER->addImage("cover", "image/undertale/object/cover.bmp", 62, 67, false, false);
	IMAGEMANAGER->addImage("Mirror", "image/undertale/object/Mirror.bmp", 188, 157, true, RGB(255,0,255));
	
	IMAGEMANAGER->addImage("lv", "image/undertale/battle/lv.bmp", 27, 15, false, false);
	IMAGEMANAGER->addImage("hpnull", "image/undertale/battle/hpnull.bmp", 126, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("hpmin", "image/undertale/battle/hpmin.bmp", 25, 21, false, false);
	IMAGEMANAGER->addImage("hpmax", "image/undertale/battle/hpmax.bmp", 25, 21, false, false);
	
	_opening = new opening;
	
	SCENEMANAGER->addScene("opening", _opening);
	SCENEMANAGER->changeScene("opening");
	
	_player = new player;
	_player->init();

	_stage1 = new stage1;
	_stage1->PlayerLink(_player);

	_stage2 = new stage2;
	_stage2->PlayerLink(_player);
	
	_stage2_1 = new stage2_1;
	_stage2_1->PlayerLink(_player);
	
	_camera = new camera;
	_camera->PlayerLink(_player);
	_camera->init();

	_player->CameraLink(_camera);
	_stage2->CameraLink(_camera);
	_stage2_1->CameraLink(_camera);

	SCENEMANAGER->addScene("stage1", _stage1);
    //SCENEMANAGER->changeScene("stage1");

	SCENEMANAGER->addScene("stage2", _stage2);
	//SCENEMANAGER->changeScene("stage2");

	SCENEMANAGER->addScene("stage2_1", _stage2_1);
	//SCENEMANAGER->changeScene("stage2_1");
	_battle = new firstbattle;
	_battle->PlayerLink(_player);
	_battle->CameraLink(_camera);
	SCENEMANAGER->addScene("battle1", _battle);
	//SCENEMANAGER->changeScene("battle1");
	_stage3 = new stage3;
	_stage3->PlayerLink(_player);
	_stage3->CameraLink(_camera);
	SCENEMANAGER->addScene("stage3", _stage3);
	//SCENEMANAGER->changeScene("stage3");

	_stage4 = new stage4;
	_stage4->PlayerLink(_player);
	_stage4->CameraLink(_camera);
	_stage4->Stage3Link(_stage3);
	SCENEMANAGER->addScene("stage4", _stage4);
	//SCENEMANAGER->changeScene("stage4");

	_stage5 = new stage5;
	_stage5->PlayerLink(_player);
	_stage5->CameraLink(_camera);
	_stage5->Stage3Link(_stage3);
	SCENEMANAGER->addScene("stage5", _stage5);
	//SCENEMANAGER->changeScene("stage5");

	_stage6 = new stage6;
	_stage6->PlayerLink(_player);
	_stage6->CameraLink(_camera);
	_stage6->Stage3Link(_stage3);
	SCENEMANAGER->addScene("stage6", _stage6);
	//SCENEMANAGER->changeScene("stage6");

	_dummybattle = new dummy;
	_dummybattle->cameralink(_camera);
	_dummybattle->playerlink(_player);
	SCENEMANAGER->addScene("dummybattle", _dummybattle);
	//SCENEMANAGER->changeScene("dummybattle");

	_stage7 = new stage7;
	_stage7->PlayerLink(_player);
	_stage7->CameraLink(_camera);
	_stage7->Stage3Link(_stage3);
	SCENEMANAGER->addScene("stage7", _stage7);
	//SCENEMANAGER->changeScene("stage7");

	_stage7battle = new stage7battle;
	_stage7battle->PlayerLink(_player);
	_stage7battle->CameraLink(_camera);
	SCENEMANAGER->addScene("stage7battle", _stage7battle);
	/*SCENEMANAGER->changeScene("stage7battle");*/

	_stage8 = new stage8;
	_stage8->PlayerLink(_player);
	_stage8->CameraLink(_camera);
	_stage8->Stage3Link(_stage3);
	SCENEMANAGER->addScene("stage8", _stage8);
	//SCENEMANAGER->changeScene("stage8");

	_stage9 = new stage9;
	_stage9->PlayerLink(_player);
	_stage9->CameraLink(_camera);
	SCENEMANAGER->addScene("stage9", _stage9);
	//SCENEMANAGER->changeScene("stage9");

	_stage9_1 = new stage9_1;
	_stage9_1->PlayerLink(_player);
	_stage9_1->CameraLink(_camera);
	SCENEMANAGER->addScene("stage9_1", _stage9_1);
	//SCENEMANAGER->changeScene("stage9_1");

	_stage10 = new stage10;
	_stage10->PlayerLink(_player);
	_stage10->CameraLink(_camera);
	SCENEMANAGER->addScene("stage10", _stage10);
	//SCENEMANAGER->changeScene("stage10");

	_stage11 = new stage11;
	_stage11->PlayerLink(_player);
	_stage11->CameraLink(_camera);
	SCENEMANAGER->addScene("stage11", _stage11);
	//SCENEMANAGER->changeScene("stage11");

	_stage12 = new stage12;
	_stage12->PlayerLink(_player);
	_stage12->CameraLink(_camera);
	SCENEMANAGER->addScene("stage12", _stage12);
	//SCENEMANAGER->changeScene("stage12");

	_stage13 = new stage13;
	_stage13->PlayerLink(_player);
	_stage13->CameraLink(_camera);
	SCENEMANAGER->addScene("stage13", _stage13);
	//SCENEMANAGER->changeScene("stage13");

	_stage14 = new stage14;
	_stage14->PlayerLink(_player);
	_stage14->CameraLink(_camera);
	SCENEMANAGER->addScene("stage14", _stage14);
	//SCENEMANAGER->changeScene("stage14");

	_stage15 = new stage15;
	_stage15->PlayerLink(_player);
	_stage15->CameraLink(_camera);
	SCENEMANAGER->addScene("stage15", _stage15);
	SCENEMANAGER->changeScene("stage15");

	_stage15battle = new stage15battle;
	_stage15battle->PlayerLink(_player);
	_stage15battle->CameraLink(_camera);
	SCENEMANAGER->addScene("stage15battle", _stage15battle);
	//SCENEMANAGER->changeScene("stage15battle");

	_stage15_store = new stage15_store;
	_stage15_store->PlayerLink(_player);
	_stage15_store->CameraLink(_camera);
	SCENEMANAGER->addScene("stage15_store", _stage15_store);

	_stage16 = new stage16;
	_stage16->PlayerLink(_player);
	_stage16->CameraLink(_camera);
	SCENEMANAGER->addScene("stage16", _stage16);
	//SCENEMANAGER->changeScene("stage16");

	_stage17 = new stage17;
	_stage17->PlayerLink(_player);
	_stage17->CameraLink(_camera);
	SCENEMANAGER->addScene("stage17", _stage17);
	//SCENEMANAGER->changeScene("stage17");

	_stage18 = new stage18;
	_stage18->PlayerLink(_player);
	_stage18->CameraLink(_camera);
	SCENEMANAGER->addScene("stage18", _stage18);
	//SCENEMANAGER->changeScene("stage18");

	_stage18_21_traproom = new stage18_21_traproom;
	_stage18_21_traproom->PlayerLink(_player);
	_stage18_21_traproom->CameraLink(_camera);
	SCENEMANAGER->addScene("stage18_21_traproom",_stage18_21_traproom);

	_stage19 = new stage19;
	_stage19->PlayerLink(_player);
	_stage19->CameraLink(_camera);
	SCENEMANAGER->addScene("stage19", _stage19);
	//SCENEMANAGER->changeScene("stage19");

	_stage20 = new stage20;
	_stage20->PlayerLink(_player);
	_stage20->CameraLink(_camera);
	SCENEMANAGER->addScene("stage20", _stage20);
	//SCENEMANAGER->changeScene("stage20");

	_stage21 = new stage21;
	_stage21->PlayerLink(_player);
	_stage21->CameraLink(_camera);
	SCENEMANAGER->addScene("stage21", _stage21);
	//SCENEMANAGER->changeScene("stage21");

	_stage22 = new stage22;
	_stage22->PlayerLink(_player);
	_stage22->CameraLink(_camera);
	SCENEMANAGER->addScene("stage22", _stage22);
	//SCENEMANAGER->changeScene("stage22");

	_stage22_1 = new stage22_1;
	_stage22_1->PlayerLink(_player);
	_stage22_1->CameraLink(_camera);
	SCENEMANAGER->addScene("stage22_1", _stage22_1);
	//SCENEMANAGER->changeScene("stage22_1");

	_stage22_2 = new stage22_2;
	_stage22_2->PlayerLink(_player);
	_stage22_2->CameraLink(_camera);
	SCENEMANAGER->addScene("stage22_2", _stage22_2);
	//SCENEMANAGER->changeScene("stage22_2");

	_torielgarden = new torielgarden;
	_torielgarden->PlayerLink(_player);
	_torielgarden->CameraLink(_camera);
	_torielgarden->stage3Link(_stage3);
	SCENEMANAGER->addScene("torielgarden", _torielgarden);
	//SCENEMANAGER->changeScene("torielgarden");

	_torielhome = new torielhome;
	_torielhome->PlayerLink(_player);
	_torielhome->CameraLink(_camera);
	_torielhome->stage3Link(_stage3);
	SCENEMANAGER->addScene("torielhome", _torielhome);
	//SCENEMANAGER->changeScene("torielhome");

	_leftroom = new leftroom;
	_leftroom->PlayerLink(_player);
	_leftroom->CameraLink(_camera);
	_leftroom->Stage3Link(_stage3);
	SCENEMANAGER->addScene("leftroom", _leftroom);
	//SCENEMANAGER->changeScene("leftroom");

	_kitchen = new kitchen;
	_kitchen->PlayerLink(_player);
	_kitchen->CameraLink(_camera);
	SCENEMANAGER->addScene("kitchen", _kitchen);
	//SCENEMANAGER->changeScene("kitchen");

	_rightroom = new rightroom;
	_rightroom->PlayerLink(_player);
	_rightroom->CameraLink(_camera);
	_rightroom->Stage3Link(_stage3);
	SCENEMANAGER->addScene("rightroom", _rightroom);
	//SCENEMANAGER->changeScene("rightroom");

	_myroom = new myroom;
	_myroom->PlayerLink(_player);
	_myroom->CameraLink(_camera);
	SCENEMANAGER->addScene("myroom", _myroom);
	//SCENEMANAGER->changeScene("myroom");

	_torielroom = new torielroom;
	_torielroom->PlayerLink(_player);
	_torielroom->CameraLink(_camera);
	SCENEMANAGER->addScene("torielroom", _torielroom);
	//SCENEMANAGER->changeScene("torielroom");

	_undertorielhome_1 = new undertorielhome_1;
	_undertorielhome_1->PlayerLink(_player);
	_undertorielhome_1->CameraLink(_camera);
	_undertorielhome_1->Stage3Link(_stage3);
	SCENEMANAGER->addScene("undertorielhome_1", _undertorielhome_1);
	//SCENEMANAGER->changeScene("undertorielhome_1");

	_undertorielhome_2 = new undertorielhome_2;
	_undertorielhome_2->PlayerLink(_player);
	_undertorielhome_2->CameraLink(_camera);
	_undertorielhome_2->Stage3Link(_stage3);
	SCENEMANAGER->addScene("undertorielhome_2", _undertorielhome_2);

	_undertorielhome_3 = new undertorielhome_3;
	_undertorielhome_3->PlayerLink(_player);
	_undertorielhome_3->CameraLink(_camera);
	_undertorielhome_3->Stage3Link(_stage3);
	SCENEMANAGER->addScene("undertorielhome_3", _undertorielhome_3);

	_undertorielhome_4 = new undertorielhome_4;
	_undertorielhome_4->PlayerLink(_player);
	_undertorielhome_4->CameraLink(_camera);
	_undertorielhome_4->Stage3Link(_stage3);
	SCENEMANAGER->addScene("undertorielhome_4", _undertorielhome_4);
	//SCENEMANAGER->changeScene("undertorielhome_4");

	_torielbattle = new torielbattle;
	_torielbattle->PlayerLink(_player);
	_torielbattle->CameraLink(_camera);
	SCENEMANAGER->addScene("torielbattle", _torielbattle);
	//SCENEMANAGER->changeScene("torielbattle");

	_torieldie = new torieldie;
	_torieldie->PlayerLink(_player);
	_torieldie->CameraLink(_camera);
	SCENEMANAGER->addScene("torieldie", _torieldie);

	_molbattle = new molbattle;
	_molbattle->PlayerLink(_player);
	_molbattle->CameraLink(_camera);
	SCENEMANAGER->addScene("molbattle", _molbattle);
	//SCENEMANAGER->changeScene("molbattle");

	_monster1 = new monster1;
	_monster1->PlayerLink(_player);
	_monster1->CameraLink(_camera);
	SCENEMANAGER->addScene("monster1", _monster1);
	//SCENEMANAGER->changeScene("monster1");

	_monster2 = new monster2;
	_monster2->PlayerLink(_player);
	_monster2->CameraLink(_camera);
	SCENEMANAGER->addScene("monster2", _monster2);
	//SCENEMANAGER->changeScene("monster2");

	_nobody = new nobody;
	_nobody->PlayerLink(_player);
	_nobody->CameraLink(_camera);
	SCENEMANAGER->addScene("nobody", _nobody);

	_last = new last;
	_last->PlayerLink(_player);
	_last->CameraLink(_camera);
	SCENEMANAGER->addScene("last", _last);
	//SCENEMANAGER->changeScene("last");
	_ending = new ending;
	_ending->PlayerLink(_player);
	_ending->CameraLink(_camera);
	SCENEMANAGER->addScene("ending", _ending);
	//SCENEMANAGER->changeScene("ending");

	_playerdie = new playerdie;
	_playerdie->PlayerLink(_player);
	_playerdie->CameraLink(_camera);
	SCENEMANAGER->addScene("playerdie", _playerdie);

	sleepcount = 0;
	cover = false;
	nocover = false;
	return S_OK;
}

//메모리 해제는 여기서
void gameStudy::release()
{
	//SAFE_DELETE(_player);
	//SAFE_DELETE(_camera);
	
	gameNode::release();
	

	

}

//계속 무한 반복 되어야 할 것들 여기서
void gameStudy::update()
{
	
	SOUNDMANAGER->update();
	SCENEMANAGER->update();
	if (_player->getPlayer()->CurHp <= 0)
	{
		SCENEMANAGER->changeScene("playerdie");
	}
	if (!SCENEMANAGER->CurrentScene("opening"))
	{
		_player->update();
		_camera->update();
	}
	if (_player->getPlayer()->gosleep)
	{
		if (sleepcount <= 150)
		{
		
		if (_player->getPlayer()->alpha < 255)
			_player->getPlayer()->alpha += 3;
		sleepcount += 1;
	    }
		if (sleepcount > 150)
		{
			_player->getPlayer()->gosleep = false;
			_player->getPlayer()->alpha = 1;
			sleepcount = 0;
		}
		if (_player->getPlayer()->alpha > 250)
		{
			cover = true;
		}
		
	}
	if (_player->getPlayer()->isgetpie)
	{
		nocover = true;
	}
	if (nocover)
	{
		cover = false;

	}
	
	gameNode::update();
}

//그려주는 건 여기서
void gameStudy::render()
{
	//배경 색
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);

	SCENEMANAGER->render();
	if (SCENEMANAGER->CurrentScene("rightroom"))
	{
		IMAGEMANAGER->findImage("Mirror")->render(getMemDC(), 1245, 188);
	}
	if (!SCENEMANAGER->CurrentScene("opening"))
	{
		_camera->render();
		_player->render();
	}
	if(SCENEMANAGER->CurrentScene("stage8") && _player->getPlayer()->x < 5000) IMAGEMANAGER->findImage("pillar")->render(getMemDC(),4898,70);
	if (SCENEMANAGER->CurrentScene("stage18"))
	{
		IMAGEMANAGER->findImage("pillar")->render(getMemDC(), 200, 360);
		IMAGEMANAGER->findImage("pillar")->render(getMemDC(), 420, 240);
		IMAGEMANAGER->findImage("pillar")->render(getMemDC(), 520, 560);
	}
	if (SCENEMANAGER->CurrentScene("stage19"))
	{
		IMAGEMANAGER->findImage("pillar")->render(getMemDC(), 205, 610);
		if(!_player->getPlayer()->stage19nopillar)
		IMAGEMANAGER->findImage("pillar")->render(getMemDC(), 405, 240);
		IMAGEMANAGER->findImage("pillar")->render(getMemDC(), 523, 450);
	}
	if (SCENEMANAGER->CurrentScene("stage20"))
	{
		IMAGEMANAGER->findImage("pillar")->render(getMemDC(), 325, 595);
		if (!_player->getPlayer()->stage20nopillar)
		IMAGEMANAGER->findImage("pillar")->render(getMemDC(), 203, 277);
		IMAGEMANAGER->findImage("pillar")->render(getMemDC(), 525, 475);
	}

	if (SCENEMANAGER->CurrentScene("stage21"))
	{
		IMAGEMANAGER->findImage("pillar")->render(getMemDC(), 325, 640);
		IMAGEMANAGER->findImage("pillar")->render(getMemDC(), 223, 280);
		if (!_player->getPlayer()->stage21nopillar)
		IMAGEMANAGER->findImage("pillar")->render(getMemDC(), 545, 200);
	}
	if (SCENEMANAGER->CurrentScene("torielgarden"))
	{
		if(!_player->getPlayer()->notree)
		IMAGEMANAGER->findImage("tree")->render(getMemDC(), 230, 505);
	}
	if (SCENEMANAGER->CurrentScene("myroom"))
	{
		if(cover)
		IMAGEMANAGER->findImage("cover")->render(getMemDC(), 390, 225);
		if (_player->getPlayer()->gosleep)
		{
			
		IMAGEMANAGER->findImage("dark")->alphaRender(getMemDC(), _player->getPlayer()->alpha);
			
		}
	}
	

	this->getBackBuffer()->render(getHDC(), 0, 0,_camera->getCam()->x, _camera->getCam()->y , WINSIZEX  , WINSIZEY);
	

}









#pragma once
#include "gameNode.h"
class player;
class camera;
class stage3;
class stage4 : public gameNode
{
private:
	image* toriel;
	image* trap1[6];
	RECT trap[6];
	RECT switch1;
	RECT objectText;
	RECT torielrc;
	RECT objectText2;
	RECT nextdoor;
	bool objectText2Event;
	bool textevent;
	bool talkcountreset;
	bool talkcountreset2;
	bool talkcountreset3;
	bool eventmove;
	bool move[10];
	bool onceEvent;
	bool alleventover;
	int index;
	int count;
	image* switchimage;
	bool dooropen;
	int opencount;
	bool allover;
	int aftercount;
	int tcount;
	int tindex;
	int textnum;
	RECT textrc;
	image* torielface_1;
	image* torielface_talk;
	bool talkend;
	int talkcount;
	int talkindex;
	int count1;
	int count2;
	int index1;
	bool sound[6];
	bool sound2;
public:
	stage4();
	~stage4();
	player* _player;
	camera* _camera;
	stage3* _stage3;

	HRESULT init();
	void release();
	void update();
	void render();

	void trapFrame();
	void torielFrame();
	void EventMove();
	void EventTalk();
	void EventTalk2();

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
	void Stage3Link(stage3* stage3) { _stage3 = stage3; }
	void TextControlUpdate();
	void TextControl();
};


#pragma once
#include "gameNode.h"

class player;
class camera;
class stage3;

class stage5 : public gameNode
{
private:
	image* river;
	image* switch1;
	image* switch2;
	image* switch3;
	image* toriel;
	image* trap2;
	RECT loadmark;
	RECT obrc1;
	RECT obrc2;
	RECT obrc3;
	RECT obtrc1;
	RECT obtrc2;
	RECT nextdoor;
	int count;
	int index;
	int obcount;
	int obindex;
	bool firstsay;
	bool secondsay;
	bool thirdsay;
	bool talkcountreset1;
	bool talkcountreset2;
	bool talkcountreset3;
	bool talkcountreset4;
	bool talkcountreset5;
	bool talkcountreset6;
	bool talkcountreset7;
	bool sayonceagain;
	bool firstmove;
	bool viewFirstEvent;
	bool fuck;
	bool switch1on;
	bool switch2on;
	bool switch3on;
	bool lastmove;
	bool obtext1;
	bool obtext2;
	bool says;
	bool says2;
	bool says3;
	bool says4;
	bool says5;
	bool says6;
	bool obt1;
	bool obt2;
	bool nexts;
	bool nexts2;
	int textcount;
	int textcount1;
	int textcount2;
	bool talk;
	bool keys;
	bool isfirstsay;
	int tcount;
	int tindex;
	int textnum;
	RECT textrc;
	bool talkend;
	image* torielface_1;
	image* torielface_talk;
	bool once;
	bool once2;
	bool nexttext1;
	bool nexttext2;
	bool nexttext3;
	bool sound;
	int talkcount;
	int talkindex;
	int count1;
	int count2;
	int index1;
public:
	stage5();
	~stage5();

	player* _player;
	camera* _camera;
	stage3* _stage3;
	HRESULT init();
	void release();
	void update();
	void render();

	void FrameUpdate();
	void Event();
	void FirstSay();
	void SecondSay();
	void ThirdSay();
	void torielFrame();
	void LoadMark();
	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
	void Stage3Link(stage3* stage3) { _stage3 = stage3; }
	void TextControlUpdate();
	void TextControl();
};


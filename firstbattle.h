#pragma once
#include "gameNode.h"

#define BULLETMAX 100
class player;
class camera;
struct tagBullet
{
	RECT rcBullet;
	float homing;
	bool isFire;
	
};

class firstbattle : public gameNode
{
private:
	HFONT font;
	HFONT font2;
public:
	firstbattle();
	~firstbattle();

	tagBullet _bullet[BULLETMAX];

	RECT bbox;
	RECT bbox2;
	RECT pl;
	RECT wall;
	RECT wal;
	player* _player;
	camera* _camera;
	image* flw;
	image* bullet;
	image* lv;
	image* bboxr;
	image* fireball;
	image* torel;
	int stcount;
	int count;
	int index;
	int bullindex;
	int bullcount;
	int bullcount2;
	int textcount;
	int textindex;
	int fireballindex;
	int homingcount;
	int firebx;
	int fireby;
	int tox;
	bool once;
	
	float bully[100];
	float bullx[100];
	float flx;
	float fly;
	bool flface;
	bool key;
	bool patton1render;
	bool patton2render;
	bool patton3render;
	bool patton4render;
	bool patton1s;
	bool patton2s;
	bool patton3s;
	bool patton4s;
	bool fires;
	bool fireballs;
	bool starts;
	bool nots1s;
	bool nots2s;
	bool nots3s;
	bool beShots;
	bool deads;
	bool bullxy2;
	bool bullxy3;
	bool bullxy4;
	bool bullder;
	bool bullcos;
	HRESULT init();
	void release();
	void update();
	void render();

	void PlayerLink(player* player) { _player = player; }
	void CameraLink(camera* camera) { _camera = camera; }
	void start();
	void nots1();
	void nots2();
	void nots3();
	void beShot();
	void dead();
	void FrameUpdate();
	void bullrender();
	void patton1();
	void patton2();
	void patton3();
	void patton4();
	void fire();
	void bullco();
};



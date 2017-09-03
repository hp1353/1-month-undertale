#pragma once
#include "gameNode.h"
class opening : public gameNode
{
private:
	int tcount;
	int tindex;
	RECT textrc;
	int textnum;
	int imagecount;
	int imagemovey;
	int alpha;
	int alphacount;
	bool alphaup;
	bool alphadown;
	bool once;
	int alpha2;
public:
	opening();
	~opening();

	HRESULT init();
	void release();
	void update();
	void render();
	void TextControlUpdate();
	void TextControl();

};


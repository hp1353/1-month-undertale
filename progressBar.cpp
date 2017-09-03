#include "stdafx.h"
#include "progressBar.h"


progressBar::progressBar()
{
}


progressBar::~progressBar()
{
}

HRESULT progressBar::init( int x, int y, int width, int height )
{
	_x = x;
	_y = y;
	_rcProgress = RectMake( _x, _y, width, height );

	_progressBarForward = IMAGEMANAGER->addImage( "barForward", "image/hpBarTop.bmp", x, y, width, height, true, RGB( 255, 0, 255 ) );
	_progressBarBack = IMAGEMANAGER->addImage( "barBack", "image/hpBarBottom.bmp", x, y, width, height, true, 0xff00ff );

	_width = _progressBarBack->getWidth(); // width 이거 해도 됨.

	return S_OK;
}

void progressBar::release()
{

}

void progressBar::update()
{
	//렉트 위치 갱신
	_rcProgress = RectMakeCenter( _x, _y, _progressBarBack->getWidth(), _progressBarBack->getHeight() );
}

void progressBar::render()
{
	IMAGEMANAGER->render( "barBack", getMemDC(),
		_rcProgress.left + _progressBarBack->getWidth() / 2,
		_y + _progressBarBack->getHeight() / 2,
		0, 0,
		_progressBarBack->getWidth(), _progressBarBack->getHeight() );

	IMAGEMANAGER->render( "barForward", getMemDC(),
		_rcProgress.left + _progressBarForward->getWidth() / 2,
		_y + _progressBarForward->getHeight() / 2,
		0, 0,
		_width, _progressBarForward->getHeight() );

}

//체력바 게이지
void progressBar::gauge( float currentGauge, float maxGauge )
{
	_width = ( currentGauge / maxGauge ) * _progressBarBack->getWidth();
}


#include "stdafx.h"
#include "pixelCollision.h"


pixelCollision::pixelCollision()
{
}


pixelCollision::~pixelCollision()
{
}

HRESULT pixelCollision::init()
{
	IMAGEMANAGER->addImage( "mountain", "image/mountain.bmp", 800, 600, true, 0xff00ff );

	_ball = IMAGEMANAGER->addImage( "ball", "image/ball.bmp", 60, 60, true, 0xff00ff );

	_x = WINSIZEX / 2 - 100;
	_y = WINSIZEY / 2 + 80;

	_rc = RectMakeCenter( _x, _y, _ball->getWidth(), _ball->getHeight() );

	_probeY = _y + _ball->getHeight() / 2;

	return S_OK;
}

void pixelCollision::release()
{
}

void pixelCollision::update()
{
	if ( KEYMANAGER->isStayDown( VK_RIGHT ) )
	{
		_x += 2.0f;
	}

	if ( KEYMANAGER->isStayDown( VK_LEFT ) )
	{
		_x -= 2.0f;
	}

	_probeY = (int)_y + _ball->getHeight() / 2;

	for ( int i = _probeY - 50; i < _probeY + 50; i++ )
	{
		COLORREF color = GetPixel( IMAGEMANAGER->findImage( "mountain" )->getMemDC(), _x, i );

		int r = GetRValue( color );
		int g = GetGValue( color );
		int b = GetBValue( color );

		if ( !( r == 255 && g == 0 && b == 255 ) )
		{
			_y = i - _ball->getHeight() / 2;
			break;
		}
	}

	_rc = RectMakeCenter( _x, _y, _ball->getWidth(), _ball->getHeight() );
}

void pixelCollision::render()
{
	IMAGEMANAGER->findImage( "mountain" )->render( getMemDC() );

	_ball->render( getMemDC(), _rc.left, _rc.top );

	Rectangle( getMemDC(), _x, _probeY, _x + 10, _probeY + 10 );
}

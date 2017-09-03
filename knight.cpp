#include "stdafx.h"
#include "knight.h"


knight::knight()
{
}


knight::~knight()
{
}

HRESULT knight::init()
{
	_jump = new jump;
	_jump->init();

	_image = IMAGEMANAGER->addFrameImage( "knight", "image/knight.bmp", 0, 0, 612, 312, 9, 4, true, 0xff00ff );

	//나이트 방향
	_knightDirection = KNIGHTDIRECTION_RIGHT_STOP;

	//좌표 셋팅
	_x = CENTERX;
	_y = CENTERY;
	_rc = RectMakeCenter( _x, _y, _image->getFrameWidth(), _image->getFrameHeight() );

	//애니메이션 등록해주자
	int rightStop[] = {0}; //_countof( 배열이름 ) -> 배열의 길이가 리턴
	KEYANIMANAGER->addArrayFrameAnimation( "knightRightStop", "knight", rightStop, 1, 5, true );

	int leftStop[] = {9};
	KEYANIMANAGER->addArrayFrameAnimation( "knightLeftStop", "knight", leftStop, 1, 5, true );

	//무브 애니메이션
	int rightMove[] = {1, 2, 3, 4, 5, 6};
	KEYANIMANAGER->addArrayFrameAnimation( "knightRightMove", "knight", rightMove, 6, 5, true );

	int leftMove[] = {10, 11, 12, 13, 14, 15};
	KEYANIMANAGER->addArrayFrameAnimation( "knightLeftMove", "knight", leftMove, 6, 5, true );

	//앉기 애니메이션
	int rightSit[] = {18};
	KEYANIMANAGER->addArrayFrameAnimation( "knightRightSit", "knight", rightSit, 1, 5, true );

	int leftSit[] = {27};
	KEYANIMANAGER->addArrayFrameAnimation( "knightLeftSit", "knight", leftSit, 1, 5, true );

	//공격 애니메이션
	int arrRightFire[] = {7, 8};
	KEYANIMANAGER->addArrayFrameAnimation( "knightRightFire", "knight", arrRightFire, 2, 5, false, rightFire, this );

	int arrLeftFire[] = {16, 17};
	KEYANIMANAGER->addArrayFrameAnimation( "knightLeftFire", "knight", arrLeftFire, 2, 5, false, leftFire, this );

	int arrRightSitFire[] = {19, 20};
	KEYANIMANAGER->addArrayFrameAnimation( "knightRightSitFire", "knight", arrRightSitFire, 2, 5, false, rightSitFire, this );

	int arrLeftSitFire[] = {28, 29};
	KEYANIMANAGER->addArrayFrameAnimation( "knightLeftSitFire", "knight", arrLeftSitFire, 2, 5, false, leftSitFire, this );

	//점프
	int arrRightJump[] = {24, 25};
	KEYANIMANAGER->addArrayFrameAnimation( "knightRightJump", "knight", arrRightJump, 2, 5, false, rightJump, this );

	int arrLeftJump[] = {33, 34};
	KEYANIMANAGER->addArrayFrameAnimation( "knightLeftJump", "knight", arrLeftJump, 2, 5, false, leftJump, this );

	int arrRightRunJump[] = {21, 22, 23};
	KEYANIMANAGER->addArrayFrameAnimation( "knightRightRunJump", "knight", arrRightRunJump, 3, 5, false, rightRunJump, this );

	int arrLeftRunJump[] = {30, 31, 32};
	KEYANIMANAGER->addArrayFrameAnimation( "knightLeftRunJump", "knight", arrLeftRunJump, 3, 5, false, leftRunJump, this );

	_knightMotion = KEYANIMANAGER->findAnimation( "knightRightStop" );

	return S_OK;
}

void knight::release()
{
	_jump->release();
	SAFE_DELETE( _jump );
}

void knight::update()
{
	//오른쪽으로 움직
	if ( KEYMANAGER->isOnceDown( VK_RIGHT ) )
	{
		_knightDirection = KNIGHTDIRECTION_RIGHT_MOVE;
		_knightMotion = KEYANIMANAGER->findAnimation( "knightRightMove" );
		_knightMotion->start();
	}
	if ( KEYMANAGER->isOnceUp( VK_RIGHT ) )
	{
		_knightDirection = KNIGHTDIRECTION_RIGHT_STOP;
		_knightMotion = KEYANIMANAGER->findAnimation( "knightRightStop" );
		_knightMotion->start();
	}

	//오른쪽으로 움직
	if ( KEYMANAGER->isOnceDown( VK_LEFT ) )
	{
		_knightDirection = KNIGHTDIRECTION_LEFT_MOVE;
		_knightMotion = KEYANIMANAGER->findAnimation( "knightLeftMove" );
		_knightMotion->start();
	}
	if ( KEYMANAGER->isOnceUp( VK_LEFT ) )
	{
		_knightDirection = KNIGHTDIRECTION_LEFT_STOP;
		_knightMotion = KEYANIMANAGER->findAnimation( "knightLeftStop" );
		_knightMotion->start();
	}

	if ( KEYMANAGER->isOnceDown( VK_UP ) )
	{
		_jump->jumping( &_x, &_y, 8.f, 0.5f );

		if ( _knightDirection == KNIGHTDIRECTION_RIGHT_STOP )
		{
			_knightDirection = KNIGHTDIRECTION_RIGHT_JUMP;
			_knightMotion = KEYANIMANAGER->findAnimation( "knightRightJump" );
			_knightMotion->start();
		}

		else if ( _knightDirection == KNIGHTDIRECTION_LEFT_STOP )
		{
			_knightDirection = KNIGHTDIRECTION_LEFT_JUMP;
			_knightMotion = KEYANIMANAGER->findAnimation( "knightLeftJump" );
			_knightMotion->start();
		}

		else if ( _knightDirection == KNIGHTDIRECTION_RIGHT_MOVE )
		{
			_knightDirection = KNIGHTDIRECTION_RIGHT_MOVE_JUMP;
			_knightMotion = KEYANIMANAGER->findAnimation( "knightRightRunJump" );
			_knightMotion->start();
		}

		else if ( _knightDirection == KNIGHTDIRECTION_LEFT_MOVE )
		{
			_knightDirection = KNIGHTDIRECTION_LEFT_MOVE_JUMP;
			_knightMotion = KEYANIMANAGER->findAnimation( "knightLeftRunJump" );
			_knightMotion->start();
		}
	}

	_jump->update();
	_rc = RectMakeCenter( _x, _y, _image->getFrameWidth(), _image->getFrameHeight() );

	switch ( _knightDirection )
	{
	case KNIGHTDIRECTION_RIGHT_STOP: case KNIGHTDIRECTION_LEFT_STOP:
		break;

	case KNIGHTDIRECTION_RIGHT_MOVE: case KNIGHTDIRECTION_RIGHT_MOVE_JUMP:
		_x += SPEED;
		_rc = RectMakeCenter( _x, _y, _image->getFrameWidth(), _image->getFrameHeight() );
		break;

	case KNIGHTDIRECTION_LEFT_MOVE: case KNIGHTDIRECTION_LEFT_MOVE_JUMP:
		_x -= SPEED;
		_rc = RectMakeCenter( _x, _y, _image->getFrameWidth(), _image->getFrameHeight() );
		break;
	}

	KEYANIMANAGER->update();
}

void knight::render()
{
	_image->aniRender( getMemDC(), _rc.left, _rc.top, _knightMotion );
}

void knight::rightFire( void * obj )
{
}

void knight::leftFire( void * obj )
{
}

void knight::rightSitFire( void * obj )
{
}

void knight::leftSitFire( void * obj )
{
}

void knight::rightJump( void * obj )
{
	knight* k = (knight*)obj;

	k->setKnightDirection( KNIGHTDIRECTION_RIGHT_STOP );
	k->setKnightMotion( KEYANIMANAGER->findAnimation( "knightRightStop" ) );
	k->getKnightMotion()->start();
}

void knight::leftJump( void * obj )
{
}

void knight::rightRunJump( void * obj )
{
}

void knight::leftRunJump( void * obj )
{
}

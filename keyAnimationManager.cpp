#include "stdafx.h"
#include "keyAnimationManager.h"


keyAnimationManager::keyAnimationManager()
{
}


keyAnimationManager::~keyAnimationManager()
{
}

HRESULT keyAnimationManager::init()
{
	return S_OK;
}

void keyAnimationManager::release()
{
	deleteAll();
}

void keyAnimationManager::update()
{
	//프레임 애니메이션을 돌려준다
	iterAnimation iter = _mTotalAnimations.begin();

	for ( ; iter != _mTotalAnimations.end(); iter++ )
	{
		if ( !iter->second->isPlay() )continue;

		//초당 60프레임으로 돌리자
		iter->second->frameUpdate( TIMEMANAGER->getElapsedTime() * 1.0f );
	}
}

void keyAnimationManager::render()
{
}

void keyAnimationManager::addDefaultFrameAnimation( string animationKeyName, char * imageKeyName, int fps, bool reverse, bool loop )
{
	image* img = IMAGEMANAGER->findImage( imageKeyName );
	animation* ani = new animation;

	ani->init( img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight() );
	ani->setDefPlayFrame( reverse, loop );
	ani->setFPS( fps );

	//_mTotalAnimations.insert( pair<string, animation*>( animationKeyName, ani ) );
	//_mTotalAnimations.insert( make_pair( animationKeyName, ani ) );
	_mTotalAnimations[animationKeyName] = ani;
}

void keyAnimationManager::addDefaultFrameAnimation( string animationKeyName, char * imageKeyName, int fps, bool reverse, bool loop, void * cbFunction )
{
	image* img = IMAGEMANAGER->findImage( imageKeyName );
	animation* ani = new animation;

	ani->init( img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight() );
	ani->setDefPlayFrame( reverse, loop, (CALLBACK_FUNCTION)cbFunction );
	ani->setFPS( fps );

	_mTotalAnimations[animationKeyName] = ani;
}

void keyAnimationManager::addDefaultFrameAnimation( string animationKeyName, char * imageKeyName, int fps, bool reverse, bool loop, void * cbFunction, void * obj )
{
	image* img = IMAGEMANAGER->findImage( imageKeyName );
	animation* ani = new animation;

	ani->init( img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight() );
	ani->setDefPlayFrame( reverse, loop, (CALLBACK_FUNCTION_PARAMETER) cbFunction, obj );
	ani->setFPS( fps );

	_mTotalAnimations[animationKeyName] = ani;
}

void keyAnimationManager::addArrayFrameAnimation( string animationKeyName, char * imageKeyName, int * playArr, int arrLen, int fps, BOOL bLoop )
{
	image* img = IMAGEMANAGER->findImage( imageKeyName );
	animation* ani = new animation;

	ani->init( img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight() );
	ani->setPlayFrame( playArr, arrLen, bLoop );
	ani->setFPS( fps );

	_mTotalAnimations[animationKeyName] = ani;
}

void keyAnimationManager::addArrayFrameAnimation( string animationKeyName, char * imageKeyName, int * playArr, int arrLen, int fps, BOOL bLoop, void * cbFunction )
{
	image* img = IMAGEMANAGER->findImage( imageKeyName );
	animation* ani = new animation;

	ani->init( img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight() );
	ani->setPlayFrame( playArr, arrLen, bLoop, (CALLBACK_FUNCTION)cbFunction );
	ani->setFPS( fps );

	_mTotalAnimations[animationKeyName] = ani;
}

void keyAnimationManager::addArrayFrameAnimation( string animationKeyName, char * imageKeyName, int * playArr, int arrLen, int fps, BOOL bLoop, void * cbFunction, void * obj )
{
	image* img = IMAGEMANAGER->findImage( imageKeyName );
	animation* ani = new animation;

	ani->init( img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight() );
	ani->setPlayFrame( playArr, arrLen, bLoop, (CALLBACK_FUNCTION_PARAMETER) cbFunction, obj );
	ani->setFPS( fps );

	_mTotalAnimations[animationKeyName] = ani;
}

void keyAnimationManager::addCoordinateFrameAnimation( string animationKeyName, char * imageKeyName, int start, int end, int fps, BOOL reverse, BOOL loop )
{
	image* img = IMAGEMANAGER->findImage( imageKeyName );
	animation* ani = new animation;

	ani->init( img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight() );
	ani->setPlayFrame( start, end, reverse, loop);
	ani->setFPS( fps );

	_mTotalAnimations[animationKeyName] = ani;
}

void keyAnimationManager::addCoordinateFrameAnimation( string animationKeyName, char * imageKeyName, int start, int end, BOOL reverse, int fps, BOOL loop, void * cbFunction )
{
	image* img = IMAGEMANAGER->findImage( imageKeyName );
	animation* ani = new animation;

	ani->init( img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight() );
	ani->setPlayFrame( start, end, reverse, loop, (CALLBACK_FUNCTION)cbFunction );
	ani->setFPS( fps );

	_mTotalAnimations[animationKeyName] = ani;
}

void keyAnimationManager::addCoordinateFrameAnimation( string animationKeyName, char * imageKeyName, int start, int end, BOOL reverse, int fps, BOOL loop, void * cbFunction, void * obj )
{
	image* img = IMAGEMANAGER->findImage( imageKeyName );
	animation* ani = new animation;

	ani->init( img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight() );
	ani->setPlayFrame( start, end, reverse, loop, (CALLBACK_FUNCTION_PARAMETER) cbFunction, obj );
	ani->setFPS( fps );

	_mTotalAnimations[animationKeyName] = ani;
}

void keyAnimationManager::start( string animationKeyName )
{
	iterAnimation iter = _mTotalAnimations.find( animationKeyName );

	iter->second->start();
}

void keyAnimationManager::stop( string animationKeyName )
{
	iterAnimation iter = _mTotalAnimations.find( animationKeyName );

	iter->second->stop();
}

void keyAnimationManager::pause( string animationKeyName )
{
	iterAnimation iter = _mTotalAnimations.find( animationKeyName );

	iter->second->pause();
}

void keyAnimationManager::resume( string animationKeyName )
{
	iterAnimation iter = _mTotalAnimations.find( animationKeyName );

	iter->second->resume();
}

animation * keyAnimationManager::findAnimation( string animationKeyName )
{
	iterAnimation iter = _mTotalAnimations.find( animationKeyName );

	if ( iter != _mTotalAnimations.end() )
	{
		return iter->second;
	}

	return NULL;
}

void keyAnimationManager::deleteAll()
{
	iterAnimation iter = _mTotalAnimations.begin();

	for ( ; iter != _mTotalAnimations.end(); )
	{
		if ( iter->second != NULL )
		{
			iter->second->release();
			SAFE_DELETE( iter->second );
			iter = _mTotalAnimations.erase( iter );
		}
		else
		{
			++iter;
		}
	}

	_mTotalAnimations.clear();
}

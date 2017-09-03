#pragma once

#include "singletonBase.h"
#include <map>

class image;
class animation;

class keyAnimationManager : public  singletonBase<keyAnimationManager>
{
public:
	typedef map<string, animation*> arrAnimation;
	typedef map<string, animation*>::iterator iterAnimation;

private:
	arrAnimation _mTotalAnimations;

public:
	keyAnimationManager();
	~keyAnimationManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//디폴트 애니메이션 3종
	void addDefaultFrameAnimation( string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop );
	void addDefaultFrameAnimation( string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction);
	void addDefaultFrameAnimation( string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction, void* obj);

	//배열 애니메이션 3종
	void addArrayFrameAnimation( string animationKeyName, char* imageKeyName, int* playArr, int arrLen, int fps, BOOL bLoop );
	void addArrayFrameAnimation( string animationKeyName, char* imageKeyName, int* playArr, int arrLen, int fps, BOOL bLoop, void* cbFunction );
	void addArrayFrameAnimation( string animationKeyName, char* imageKeyName, int* playArr, int arrLen, int fps, BOOL bLoop, void* cbFunction, void* obj );

	//구간 애니메이션 3종
	void addCoordinateFrameAnimation( string animationKeyName, char* imageKeyName, int start, int end, BOOL reverse, int fps, BOOL loop );
	void addCoordinateFrameAnimation( string animationKeyName, char* imageKeyName, int start, int end, BOOL reverse, int fps, BOOL loop, void* cbFunction );
	void addCoordinateFrameAnimation( string animationKeyName, char* imageKeyName, int start, int end, BOOL reverse, int fps, BOOL loop, void* cbFunction, void* obj );

	void start( string animationKeyName );
	void stop( string animationKeyName );
	void pause( string animationKeyName );
	void resume( string animationKeyName );

	animation* findAnimation( string animationKeyName );

	void deleteAll();
};


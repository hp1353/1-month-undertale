#pragma once

#include "gameNode.h"
#define TILE_X 20              //가로 타일 수
#define TILE_Y 20              //세로 타일 수
#define WIDTH 40               //타일 가로 길이
#define HEIGHT 40              //타일 세로 길이
#define BIGNUM 5000            //충분히 큰 F값 (초기값)

enum TILE_TYPE                        //타일 속성
{
	TILE_TYPE_EMPTY,        //빈 타일(지나갈 수 있는)
	TILE_TYPE_START,        //시작지점
	TILE_TYPE_END,                 //도착지점
	TILE_TYPE_WALL                 //벽
};

enum ASTAR_STATE                //aStar 알고리즘 상태
{
	ASTAR_STATE_SEARCHING,  //검색 중
	ASTAR_STATE_FOUND,            //경로 발견
	ASTAR_STATE_NOWAY,            //경로가 없다
	ASTAR_STATE_END                //타일 배치 완료 전
};

struct tagTile                        //타일 구조체
{
	RECT rc;                       //렉트
	COLORREF color;                //색
	bool walkable;                 //지나갈 수 있는지 여부
	bool listOn;                   //openList에 추가되었는지 여부
	int i, j;                      //배열 인덱스 i, j값
	int F, G, H;                   //F, G, H값
	char str[128];
	tagTile* parent;        //부모 타일 주소
	TILE_TYPE type;                //타일 속성
};

class aStar : public gameNode
{
private:
	tagTile _tile[TILE_X][TILE_Y];             //타일 배열
	vector<tagTile *> _openList;                //오픈 리스트 벡터
	vector<tagTile *> _closeList;         //클로즈 리스트 벡터

	ASTAR_STATE _aStarState;                   //aStar 알고리즘 상태를 담는 변수

	TILE_TYPE _selectedType;                   //타일 배치할 때 사용할 타일 속성
	COLORREF _selectedTypeColor;        //타일 배치할 때 사용할 타일 색

	int _startX, _startY;                      //시작지점의 i, j인덱스값
	int _endX, _endY;                          //도착지점의 i, j인덱스값
	int _lastIndex;                                  //가장 나중에 추가된 클로즈 리스트의 인덱스

	bool _startPointSet;                       //시작지점이 배치 되었는지 여부
	bool _endPointSet;                               //도착지점이 배치 되었는지 여부

	int Ci;                                                //마지막으로 추가된 클로즈 리스트의 i
	int Cj;                                                //마지막으로 추가된 클로즈 리스트의 j
	int Cg;                                                //마지막으로 추가된 클로즈 리스트의 G

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void tileComposition();                    //타일 배치
	void tileInitializing();                   //타일 배치 후 타일 속성에 맞게 타일 초기화
	void addOpenList();                              //오픈리스트에 추가
	void calculateH();                               //오픈리스트 내 타일의 H값 계산
	void calculateF();                               //오픈리스트 내 타일의 F값 계산
	void addCloseList();                       //가장 작은 F 선택 후 클로즈 리스트에 추가
	void checkArrive();                              //도착했는지 여부를 체크
	void showWay( tagTile* tile );         //도착 후 시작지점과 도착지점을 잇는 경로를 보여주는 함수

	aStar();
	~aStar();
};



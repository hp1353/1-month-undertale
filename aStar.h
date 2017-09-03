#pragma once

#include "gameNode.h"
#define TILE_X 20              //���� Ÿ�� ��
#define TILE_Y 20              //���� Ÿ�� ��
#define WIDTH 40               //Ÿ�� ���� ����
#define HEIGHT 40              //Ÿ�� ���� ����
#define BIGNUM 5000            //����� ū F�� (�ʱⰪ)

enum TILE_TYPE                        //Ÿ�� �Ӽ�
{
	TILE_TYPE_EMPTY,        //�� Ÿ��(������ �� �ִ�)
	TILE_TYPE_START,        //��������
	TILE_TYPE_END,                 //��������
	TILE_TYPE_WALL                 //��
};

enum ASTAR_STATE                //aStar �˰��� ����
{
	ASTAR_STATE_SEARCHING,  //�˻� ��
	ASTAR_STATE_FOUND,            //��� �߰�
	ASTAR_STATE_NOWAY,            //��ΰ� ����
	ASTAR_STATE_END                //Ÿ�� ��ġ �Ϸ� ��
};

struct tagTile                        //Ÿ�� ����ü
{
	RECT rc;                       //��Ʈ
	COLORREF color;                //��
	bool walkable;                 //������ �� �ִ��� ����
	bool listOn;                   //openList�� �߰��Ǿ����� ����
	int i, j;                      //�迭 �ε��� i, j��
	int F, G, H;                   //F, G, H��
	char str[128];
	tagTile* parent;        //�θ� Ÿ�� �ּ�
	TILE_TYPE type;                //Ÿ�� �Ӽ�
};

class aStar : public gameNode
{
private:
	tagTile _tile[TILE_X][TILE_Y];             //Ÿ�� �迭
	vector<tagTile *> _openList;                //���� ����Ʈ ����
	vector<tagTile *> _closeList;         //Ŭ���� ����Ʈ ����

	ASTAR_STATE _aStarState;                   //aStar �˰��� ���¸� ��� ����

	TILE_TYPE _selectedType;                   //Ÿ�� ��ġ�� �� ����� Ÿ�� �Ӽ�
	COLORREF _selectedTypeColor;        //Ÿ�� ��ġ�� �� ����� Ÿ�� ��

	int _startX, _startY;                      //���������� i, j�ε�����
	int _endX, _endY;                          //���������� i, j�ε�����
	int _lastIndex;                                  //���� ���߿� �߰��� Ŭ���� ����Ʈ�� �ε���

	bool _startPointSet;                       //���������� ��ġ �Ǿ����� ����
	bool _endPointSet;                               //���������� ��ġ �Ǿ����� ����

	int Ci;                                                //���������� �߰��� Ŭ���� ����Ʈ�� i
	int Cj;                                                //���������� �߰��� Ŭ���� ����Ʈ�� j
	int Cg;                                                //���������� �߰��� Ŭ���� ����Ʈ�� G

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void tileComposition();                    //Ÿ�� ��ġ
	void tileInitializing();                   //Ÿ�� ��ġ �� Ÿ�� �Ӽ��� �°� Ÿ�� �ʱ�ȭ
	void addOpenList();                              //���¸���Ʈ�� �߰�
	void calculateH();                               //���¸���Ʈ �� Ÿ���� H�� ���
	void calculateF();                               //���¸���Ʈ �� Ÿ���� F�� ���
	void addCloseList();                       //���� ���� F ���� �� Ŭ���� ����Ʈ�� �߰�
	void checkArrive();                              //�����ߴ��� ���θ� üũ
	void showWay( tagTile* tile );         //���� �� ���������� ���������� �մ� ��θ� �����ִ� �Լ�

	aStar();
	~aStar();
};



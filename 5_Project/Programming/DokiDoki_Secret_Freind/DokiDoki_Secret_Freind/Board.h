#pragma once
#include "Stage2Obj.h"
#include "WInApp.h"

class Board : public Stage2Obj
{
public:
	HRGN boardPos; //board�� ��ġ
	BOOL isInsideBoard;

	BOOL isShow = false; //second IMG ��� ���� �� first IMG ���ֱ� ���� �뵵
	BOOL isDestroy = false;
	BOOL isNext = false; //second IMG ȭ�鿡 ��� ���� Bool��


	Stage2Obj* img; //���� �Ⱦ�

public:
	Board() { Init(); };
	~Board() {};
	
public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

	void BoardLogic();
};


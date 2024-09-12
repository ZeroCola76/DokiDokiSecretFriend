#pragma once
#include "Stage2Obj.h"
#include "WInApp.h"

class Board : public Stage2Obj
{
public:
	HRGN boardPos; //board의 위치
	BOOL isInsideBoard;

	BOOL isShow = false; //second IMG 출력 됐을 때 first IMG 없애기 위한 용도
	BOOL isDestroy = false;
	BOOL isNext = false; //second IMG 화면에 출력 유무 Bool값


	Stage2Obj* img; //아직 안씀

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


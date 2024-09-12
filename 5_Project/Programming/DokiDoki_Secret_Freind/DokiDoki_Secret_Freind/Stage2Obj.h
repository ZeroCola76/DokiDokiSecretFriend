#pragma once
#include "Object.h"

class Stage2Obj : public Object
{
public:
	BOOL isClick = false; // 클릭이 됐는지 안됐는지 확인하기 위함
	BOOL isDestroy = false; //팝업창 없애기 위한 용도

	POINTS pt;
	static int cnt; //clue가 눌릴 때 count++ 됨


public:
	Stage2Obj() {};
	~Stage2Obj() {};

};


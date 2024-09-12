#pragma once
#include "Object.h"
class Stage1Obj : public Object
{
public:
	BOOL inGame = FALSE; //게임중
	BOOL isEnd = FALSE; //1스테이지 끝
	BOOL isClickStage1 = FALSE;

	bool isDone = false;

	static int lateScore;
	static int perfectScore;

	Stage1Obj() {};
	~Stage1Obj() {};
};
#pragma once
#include "Object.h"
class Stage1Obj : public Object
{
public:
	BOOL inGame = FALSE; //������
	BOOL isEnd = FALSE; //1�������� ��
	BOOL isClickStage1 = FALSE;

	bool isDone = false;

	static int lateScore;
	static int perfectScore;

	Stage1Obj() {};
	~Stage1Obj() {};
};
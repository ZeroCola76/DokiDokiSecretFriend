#pragma once
#include "Object.h"

class Stage2Obj : public Object
{
public:
	BOOL isClick = false; // Ŭ���� �ƴ��� �ȵƴ��� Ȯ���ϱ� ����
	BOOL isDestroy = false; //�˾�â ���ֱ� ���� �뵵

	POINTS pt;
	static int cnt; //clue�� ���� �� count++ ��


public:
	Stage2Obj() {};
	~Stage2Obj() {};

};


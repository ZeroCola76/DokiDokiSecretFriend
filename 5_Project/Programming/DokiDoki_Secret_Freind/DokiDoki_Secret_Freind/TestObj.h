#pragma once
#include "Object.h"

class TestObj : public Object
{
public:
	int myX;
	int myY;
	BOOL isClick = false; //��ư Ŭ�� �Ƴ� �ȵƳ� Ȯ��


public:
	TestObj() {};
	~TestObj() {};

public:
	void myFunc1() {};
	void myFunc2() {};


};


#pragma once
#include "Object.h"

class TestObj : public Object
{
public:
	int myX;
	int myY;
	BOOL isClick = false; //버튼 클릭 됐나 안됐나 확인


public:
	TestObj() {};
	~TestObj() {};

public:
	void myFunc1() {};
	void myFunc2() {};


};


#pragma once
#include "Object.h"
class Stage3Obj : public Object
{
public:
	float angle = 0;
	bool isDone = false;


	RECT collider;
	BITMAP bm;
	POINT objectCenter;

public:
	void SetPos(double _x, double _y);
	RECT GetCollider() { return collider; }
	POINT GetObjectCenter() { return objectCenter; }

public:
	Stage3Obj() {};
	~Stage3Obj() {};
};


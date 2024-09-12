#pragma once
#include "Monobehaviour.h"
#include "WInApp.h"
class Object : public Monobehaviour
{
public:
	double x,y;
	HBITMAP image;

	Object() {};
	virtual ~Object() {};
};


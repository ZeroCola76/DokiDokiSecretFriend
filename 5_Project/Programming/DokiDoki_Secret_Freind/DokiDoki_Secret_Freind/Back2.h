#pragma once
#include "Stage2Obj.h"

class Back2 : public Stage2Obj
{
public:
	Back2() {};
	Back2(double _x, double _y, HBITMAP _hbm) { x = _x; y = _y; image = _hbm; };
	~Back2() {};


public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

};


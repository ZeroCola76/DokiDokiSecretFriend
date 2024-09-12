#pragma once
#include "TitleObj.h"

class TitleBack : public TitleObj
{
public:
	TitleBack() {};
	TitleBack(double _x, double _y, HBITMAP _hbm) { x = _x; y = _y; image = _hbm; };
	~ TitleBack() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();
};


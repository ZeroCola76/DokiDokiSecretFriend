#pragma once
#include "Stage3Obj.h"

class St3Bk : public Stage3Obj
{
public:

public:
	St3Bk(HBITMAP _image, double _x, double _y) { image = _image; x = _x; y = _y; };
	~St3Bk() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

};


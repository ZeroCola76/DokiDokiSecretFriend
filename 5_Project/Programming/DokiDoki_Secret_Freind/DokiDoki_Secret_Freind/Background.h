#pragma once
#include "Stage1Obj.h"

class Background : public Stage1Obj
{
public:
	Background() {};
	~Background() {};

	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();
};


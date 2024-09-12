#pragma once
#include "Stage1Obj.h"

class RBG : public Stage1Obj
{
public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();
};


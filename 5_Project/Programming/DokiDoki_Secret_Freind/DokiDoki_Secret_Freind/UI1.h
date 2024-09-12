#pragma once
#include "Stage2Obj.h"

class UI1 : public Stage2Obj
{
public:
	UI1() {};
	~UI1() {};
public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();
};


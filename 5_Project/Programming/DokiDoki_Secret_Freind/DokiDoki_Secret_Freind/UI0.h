#pragma once
#include "Stage2Obj.h"

class UI0 : public Stage2Obj
{
public:
	UI0() {};
	~UI0() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();
};


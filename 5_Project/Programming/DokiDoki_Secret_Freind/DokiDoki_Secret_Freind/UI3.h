#pragma once
#include "Stage2Obj.h"

class UI3 : public Stage2Obj
{
public:
	UI3() {};
	~UI3() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();
};


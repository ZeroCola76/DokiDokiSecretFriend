#pragma once
#include "Stage2Obj.h"

class FindUI : public Stage2Obj
{
public:
	FindUI() {};
	~ FindUI() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();
};


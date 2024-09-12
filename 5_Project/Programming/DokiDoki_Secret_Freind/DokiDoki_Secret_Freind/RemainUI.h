#pragma once
#include "Stage2Obj.h"

class RemainUI : public Stage2Obj
{
public:
	RemainUI() {};
	~ RemainUI() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();
};


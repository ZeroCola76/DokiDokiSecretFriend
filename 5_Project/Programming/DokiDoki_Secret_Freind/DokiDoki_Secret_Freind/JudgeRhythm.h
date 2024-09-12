#pragma once
#include "Stage1Obj.h"
#include "RenderSystem.h"
class JudgeRhythm : public Stage1Obj
{
public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();
};
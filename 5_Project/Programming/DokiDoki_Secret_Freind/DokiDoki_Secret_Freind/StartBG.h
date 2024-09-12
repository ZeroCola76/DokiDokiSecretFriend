#pragma once
#include "Stage1Obj.h"
class StartBG : public Stage1Obj
{
public:
	HRGN boxPos;
	BOOL isInsideBox;
	POINTS pt;

	StartBG() {};
	~StartBG() {};

	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

	void GetStartButton();
};


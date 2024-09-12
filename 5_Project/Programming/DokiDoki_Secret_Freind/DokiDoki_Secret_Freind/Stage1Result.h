#pragma once
#include "Stage1Obj.h"
class Stage1Result : public Stage1Obj
{
public:
	HRGN boxPos;
	BOOL isInsideBox;
	POINTS pt;

	Stage1Result() {};
	~Stage1Result() {};

	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

	void GetEndButton();
};


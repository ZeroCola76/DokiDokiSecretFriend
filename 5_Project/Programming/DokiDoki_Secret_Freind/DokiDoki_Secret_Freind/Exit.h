#pragma once
#include "TitleObj.h"
#include "WInApp.h"

class Exit : public TitleObj
{
public:
	HRGN exitPos;
	POINTS pt;
	BOOL isInsideExit;

public:
	Exit() { Init(); };
	~Exit() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

	void ExitLogic();
};


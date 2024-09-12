#pragma once
#include "TitleObj.h"
#include "WInApp.h"

class Start : public TitleObj
{
public:
	HRGN startPos;
	POINTS pt;
	BOOL isInsideStart;

public:
	Start() { Init();  };
	~Start() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

	void StartLogic();
};


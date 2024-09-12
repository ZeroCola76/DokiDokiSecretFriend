#pragma once
#include "TitleObj.h"
#include "WInApp.h"

class Credit : public TitleObj
{
public:
	HRGN creditPos;
	POINTS pt;
	BOOL isInsideCredit;

public:
	Credit() { Init(); };
	~Credit() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

	void CreditLogic();
};


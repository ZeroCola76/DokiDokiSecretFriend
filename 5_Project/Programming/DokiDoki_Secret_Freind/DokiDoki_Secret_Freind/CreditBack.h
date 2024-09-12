#pragma once
#include "Object.h"

class CreditBack : public Object
{
public:
	HRGN escPos;
	BOOL isOutCredit;
	POINTS pt;
	BOOL isClick = false;

public:
	CreditBack() {};
	~CreditBack() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

	void EscBtn();
};


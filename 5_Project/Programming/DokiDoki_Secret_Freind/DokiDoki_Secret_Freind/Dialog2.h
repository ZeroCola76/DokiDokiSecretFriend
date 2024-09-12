#pragma once
#include "Dialog.h"

class Dialog2 : public Dialog
{
public:
	HBITMAP dialogText[10];

	int dialogCount = 0;
	const int dialogMaxConut = 10;
	bool isPaid;

public:
	Dialog2() {};
	~Dialog2() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();
};


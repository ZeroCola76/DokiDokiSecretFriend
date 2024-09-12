#pragma once
#include "Dialog.h"

class Dialog3 : public Dialog
{
public:
	HBITMAP dialogText[8];

	int dialogCount = 0;
	const int dialogMaxConut = 8;

	bool isPaid;

public:
	Dialog3() {};
	~Dialog3() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();
};


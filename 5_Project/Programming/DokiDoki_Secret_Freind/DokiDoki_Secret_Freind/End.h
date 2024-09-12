#pragma once
#include "Dialog.h"

class End : public Dialog
{
public:
	HBITMAP dialogText[24];

	int dialogCount = 0;
	const int dialogMaxConut = 24;
	bool isPaid;

public:
	End() {};
	~ End() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();
};


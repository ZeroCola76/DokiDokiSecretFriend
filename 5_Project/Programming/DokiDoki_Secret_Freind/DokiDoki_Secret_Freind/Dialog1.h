#pragma once
#include "Dialog.h"

class Dialog1 : public Dialog
{
public:
	HBITMAP dialogText[15];

	int dialogCount = 0;
	const int dialogMaxConut = 15;

	bool isPaid;

public:
	Dialog1() {};
	~ Dialog1() {};


public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();
};


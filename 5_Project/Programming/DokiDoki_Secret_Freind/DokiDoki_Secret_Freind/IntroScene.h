#pragma once
#include "Dialog.h"

class IntroScene : public Dialog
{
public:
	HBITMAP dialogText[9];

	bool isPaid;
	int dialogCount = 0;
	const int dialogMaxConut = 9;

public:
	IntroScene() {};
	~IntroScene() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();
};


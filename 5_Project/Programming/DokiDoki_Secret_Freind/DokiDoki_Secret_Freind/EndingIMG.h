#pragma once
#include "Dialog.h"

class EndingIMG : public Dialog
{
public:
	bool isPaid;

public:
	EndingIMG() {};
	~EndingIMG() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();
};
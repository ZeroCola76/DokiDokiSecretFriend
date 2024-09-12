#pragma once
#include "Dialog.h"

class D_Before_Stage2 : public Dialog
{
public:
	D_Before_Stage2() {};
	~ D_Before_Stage2() {};
	
public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

};


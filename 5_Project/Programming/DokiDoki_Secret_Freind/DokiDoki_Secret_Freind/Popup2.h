#pragma once
#include "Stage2Obj.h"

class Popup2 : public Stage2Obj
{
public:
	HRGN okPos; //확인 위치

public:
	Popup2() { Init(); };
	~ Popup2() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

	void PopUp2Logic();
};


#pragma once
#include "Stage2Obj.h"

class Popup0 : public Stage2Obj
{
public:
	HRGN okPos; //확인 위치

public:
	Popup0() { Init(); };
	~ Popup0() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

	void PopUp0Logic();

};


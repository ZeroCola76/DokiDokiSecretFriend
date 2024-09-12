#pragma once
#include "Stage2Obj.h"

class Popup1 : public Stage2Obj
{
public:
	HRGN okPos; //확인 위치

public:
	Popup1() { Init(); };
	~Popup1() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

	void PopUp1Logic();
};
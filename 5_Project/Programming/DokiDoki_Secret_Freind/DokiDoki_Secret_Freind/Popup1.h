#pragma once
#include "Stage2Obj.h"

class Popup1 : public Stage2Obj
{
public:
	HRGN okPos; //Ȯ�� ��ġ

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
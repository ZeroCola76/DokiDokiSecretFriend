#pragma once
#include "Stage2Obj.h"

class Popup3 : public Stage2Obj
{
public:
	HRGN okPos; //Ȯ�� ��ġ

public:
	Popup3() { Init(); };
	~ Popup3() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

	void PopUp3Logic();

};


#pragma once
#include "Stage2Obj.h"

class Popup4 : public Stage2Obj
{
public:
	bool isPaid;
	HRGN okPos; //확인 위치
	BOOL isDestroy; //팝업창 없애기 위한 용도

public:
	Popup4() { Init(); };
	~ Popup4() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

	void PopUp4Logic();

};


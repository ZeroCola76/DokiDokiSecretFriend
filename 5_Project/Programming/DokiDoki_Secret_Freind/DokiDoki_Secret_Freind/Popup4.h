#pragma once
#include "Stage2Obj.h"

class Popup4 : public Stage2Obj
{
public:
	bool isPaid;
	HRGN okPos; //Ȯ�� ��ġ
	BOOL isDestroy; //�˾�â ���ֱ� ���� �뵵

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


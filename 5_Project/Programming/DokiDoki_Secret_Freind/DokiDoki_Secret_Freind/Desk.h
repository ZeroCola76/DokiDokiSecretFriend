#pragma once
#include "Stage2Obj.h"
#include "WInApp.h"

class Desk : public Stage2Obj
{
public:
	HRGN deskPos1;
	HRGN deskPos2;
	HRGN deskPos3;
	HRGN deskPos4;
	HRGN deskPos5;
	HRGN deskPos6;
	HRGN deskPos7;
	HRGN deskPos8;

	HRGN deskPos10;

	BOOL isInsideDesk1;
	BOOL isInsideDesk2;
	BOOL isInsideDesk3;
	BOOL isInsideDesk4;
	BOOL isInsideDesk5;
	BOOL isInsideDesk6;
	BOOL isInsideDesk7;
	BOOL isInsideDesk8;

	BOOL isInsideDesk10;

	BOOL isShow = false; //second IMG ��� ���� �� first IMG ���ֱ� ���� �뵵
	BOOL isDestroy = false;
	BOOL isNext = false; //second IMG ȭ�鿡 ��� ���� Bool��


public:
	Desk() { Init(); };
	~Desk() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

	void DeskLogic();
};


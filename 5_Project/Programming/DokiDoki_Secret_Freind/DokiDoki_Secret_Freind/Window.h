#pragma once
#include "Stage2Obj.h"
#include "WInApp.h"

class Window : public Stage2Obj
{
public:
	HRGN windowPos; //object1�� ��ġ
	BOOL isInsideWindow;

	BOOL isShow = false; //second IMG ��� ���� �� first IMG ���ֱ� ���� �뵵
	BOOL isDestroy = false;
	BOOL isNext = false; //second IMG ȭ�鿡 ��� ���� Bool��


public:
	Window() { Init(); };
	~Window() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

	void WindowLogic();
};


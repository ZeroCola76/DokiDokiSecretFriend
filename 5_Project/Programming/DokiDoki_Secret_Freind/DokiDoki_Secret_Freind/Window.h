#pragma once
#include "Stage2Obj.h"
#include "WInApp.h"

class Window : public Stage2Obj
{
public:
	HRGN windowPos; //object1의 위치
	BOOL isInsideWindow;

	BOOL isShow = false; //second IMG 출력 됐을 때 first IMG 없애기 위한 용도
	BOOL isDestroy = false;
	BOOL isNext = false; //second IMG 화면에 출력 유무 Bool값


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


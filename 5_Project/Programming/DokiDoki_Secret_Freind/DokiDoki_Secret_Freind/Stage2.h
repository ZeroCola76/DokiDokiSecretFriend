#pragma once
#include "Stage2Obj.h"
#include "Scene.h"
#include "WInApp.h"


class Stage2 : public Scene
{
public:
	Stage2Obj* back2;

	Stage2Obj* window;
	Stage2Obj* board;
	Stage2Obj* desk;
	Stage2Obj* note;

	Stage2Obj* popUp0;
	Stage2Obj* popUp1;
	Stage2Obj* popUp2;
	Stage2Obj* popUp3;
	Stage2Obj* popUp4;

	Stage2Obj* ui0;
	Stage2Obj* ui1;
	Stage2Obj* ui2;
	Stage2Obj* ui3;


	BOOL showPopup = false;


public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

	void GameLogic();
};
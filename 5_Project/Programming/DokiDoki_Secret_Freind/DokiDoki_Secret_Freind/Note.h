#pragma once
#include "Stage2Obj.h"
#include "WInApp.h"

class Note : public Stage2Obj
{
public:
	HRGN notePos; //board의 위치
	BOOL isInsideNote;

	BOOL isShow = false; //second IMG 출력 됐을 때 first IMG 없애기 위한 용도
	BOOL isDestroy = false;
	BOOL isNext = false; //second IMG 화면에 출력 유무 Bool값


public:
	Note() { Init(); };
	~Note() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

	void NoteLogic();
};


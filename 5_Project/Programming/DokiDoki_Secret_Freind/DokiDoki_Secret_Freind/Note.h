#pragma once
#include "Stage2Obj.h"
#include "WInApp.h"

class Note : public Stage2Obj
{
public:
	HRGN notePos; //board�� ��ġ
	BOOL isInsideNote;

	BOOL isShow = false; //second IMG ��� ���� �� first IMG ���ֱ� ���� �뵵
	BOOL isDestroy = false;
	BOOL isNext = false; //second IMG ȭ�鿡 ��� ���� Bool��


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


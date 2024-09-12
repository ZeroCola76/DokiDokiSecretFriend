#pragma once
#include "Stage1Obj.h"
#include "Scene.h"

class HObject
{
public:
	int x; //키입력
	double y; //노트
	int rTime; //몇초에 생성
	int type; //안쓸거야
	int hit_sound; //안씀
};

class Stage1 : public Scene
{
public:
	Stage1Obj* arrow[100];
	Stage1Obj* bg;
	Stage1Obj* rbg;
	Stage1Obj* judge;
	Stage1Obj* startBg;
	Stage1Obj* result;
	Stage1Obj* parcingObj;
	ULONGLONG rhythmTime;
	HObject hObject[100];
	int rNumberCount = 0;
	bool isMusic = false;

	Stage1() {};
	~Stage1() {};

	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

	void GetNoteMap();
	void RhythmTimer(ULONGLONG maxTime);
};


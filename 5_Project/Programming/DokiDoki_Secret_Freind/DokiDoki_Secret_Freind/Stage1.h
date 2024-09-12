#pragma once
#include "Stage1Obj.h"
#include "Scene.h"

class HObject
{
public:
	int x; //Ű�Է�
	double y; //��Ʈ
	int rTime; //���ʿ� ����
	int type; //�Ⱦ��ž�
	int hit_sound; //�Ⱦ�
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


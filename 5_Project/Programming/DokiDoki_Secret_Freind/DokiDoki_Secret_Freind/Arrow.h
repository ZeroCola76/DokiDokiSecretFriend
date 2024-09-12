#pragma once

//#define Max 1000

#include "Stage1Obj.h"
#include "SoundManager.h"
#include "PathManager.h"
#include "WInApp.h"


class Arrow : public Stage1Obj
{

public:
	double arrowX;
	double arrowY;
	int arrowShape = 0;
	bool isSet = false;
	//판정 체크
	ULONGLONG rhythmTimeArrow = 0;

public:
	Arrow() { Init(); };
	~Arrow() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

	void MoveArrow();
	void DrawArrow(int _x);
	void RandomSet();
	void JudgeNote();
	void JudegeTimer(ULONGLONG maxTime);
	void JudgeLogic();
};

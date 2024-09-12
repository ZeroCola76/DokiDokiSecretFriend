#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Stage1Obj.h"



class ParcingObj : public Stage1Obj
{
public:
	//HObject hObject[100];
	

	ParcingObj() {};
	~ParcingObj() {};

	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();
	//void GetNoteMap();
};


#pragma once
#include "Stage1Obj.h"

class LateScore : public Stage1Obj
{
public:

	LateScore() {};
	~LateScore() {};

	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

	static void countLScore();
};


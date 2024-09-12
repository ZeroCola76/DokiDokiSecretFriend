#pragma once
#include "Stage1Obj.h"
class PerfectScore : public Stage1Obj
{
public:

	PerfectScore() {};
	~PerfectScore() {};

	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

	static void countPScore();
};


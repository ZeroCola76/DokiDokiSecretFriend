#pragma once
#include "TestObj.h"


class Player2 : public TestObj
{
public:
	Player2() {};
	~Player2() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

};


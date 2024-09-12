#pragma once
#include "Object.h"
#include "Winapp.h"
class Player : public Object
{
public:

	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

	void PlayerLogic();
	void PlayerFixedLogic();
	void PlayerRender(int _x, int _y);
};


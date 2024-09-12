#pragma once
#include "Scene.h"
#include "Object.h"
#include "WInApp.h"

class CreditScene : public Scene
{
public:
	Object* creditBack;

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();
};


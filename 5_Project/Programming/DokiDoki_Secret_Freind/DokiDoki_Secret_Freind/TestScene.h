#pragma once
#include "Scene.h"
#include "Object.h"

class TestScene : public Scene
{
public:
	int x = 0;
	int y = 0;

	int x2 = 0;
	int y2 = 0;

	Object* obj;
	Object* myObject;


public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();


public:
	void func1();
	void func2();

};


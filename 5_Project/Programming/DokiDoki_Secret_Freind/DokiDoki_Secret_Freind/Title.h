#pragma once
#include "Scene.h"
#include "TitleObj.h"
#include "WInApp.h"

class Title : public Scene
{
public:
	TitleObj* start;
	TitleObj* credit;
	TitleObj* exit;
	TitleObj* titleBack;
	BOOL isMusic = false;

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();
};


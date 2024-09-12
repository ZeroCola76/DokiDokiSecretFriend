#pragma once
#include "WInApp.h"
#include "Scene.h"

class Dialog : public Scene
{
public:
	HBITMAP girl;
	HBITMAP boy;
	HBITMAP dialogBox;
	HBITMAP txtBtn;

	HBITMAP BackGround;

	WCHAR* dialogTxt;

public:
	Dialog() {};
	~Dialog() {};

public:
	void LoadCore();

	void DrawGirl();
	void DrawGirl_s();
	void DrawGirl_b();
	void DrawBoy();
	void DrawBoy_s();
	void DrawdialogBox();
	void DrawtxtBtn();
};
#pragma once
#include "PuzzleObj.h"

class TreePuzzle : public PuzzleObj
{
public:
	TreePuzzle(double _x, double _y, float _angle, HBITMAP _hbm, int _puzzleNumber);
	~TreePuzzle() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();
};
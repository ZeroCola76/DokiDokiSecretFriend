#pragma once
#include "PuzzleObj.h"

class AirplanePuzzle : public PuzzleObj
{
public:
	AirplanePuzzle(double _x, double _y, float _angle, HBITMAP _hbm, int _puzzleNumber);
	~AirplanePuzzle() {};
public:

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();
};


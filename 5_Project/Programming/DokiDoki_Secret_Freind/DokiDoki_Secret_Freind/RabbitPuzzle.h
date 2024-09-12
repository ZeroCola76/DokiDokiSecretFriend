#pragma once
#include "PuzzleObj.h"

class RabbitPuzzle : public PuzzleObj
{
public:
	RabbitPuzzle(double _x, double _y, float _angle, HBITMAP _hbm, int _puzzleNumber);
	~RabbitPuzzle() {};

public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

};
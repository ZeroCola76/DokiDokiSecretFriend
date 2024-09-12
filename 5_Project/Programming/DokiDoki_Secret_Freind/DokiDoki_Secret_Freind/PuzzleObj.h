#pragma once
#include "Stage3Obj.h"

class PuzzleObj : public Stage3Obj
{
public:
	int puzzleNumber;

public:
	PuzzleObj() {};
	PuzzleObj(double _x, double _y, HBITMAP _hbm)
	{
		x = _x; y = _y; image = _hbm;
	};
	~PuzzleObj() {};

protected:
	void SetCollider();
};


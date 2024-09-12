#include "TreePuzzle.h"
#include "RenderSystem.h"
#include <string>

using namespace std;

TreePuzzle::TreePuzzle(double _x, double _y, float _angle, HBITMAP _hbm, int _puzzleNumber)
{
	x = _x;
	y = _y;
	angle = _angle;
	image = _hbm;
	puzzleNumber = _puzzleNumber;
}

void TreePuzzle::Init()
{
}

void TreePuzzle::FixedUpdate()
{
	SetCollider();
}

void TreePuzzle::Update()
{
	isDone = false;

	switch (puzzleNumber)
	{
	case 0:
		if (x > 430 && x < 470 && y > -90 && y < -50 && (angle > 355 || angle < 5))
		{
			isDone = true;
		}
		break;
	case 1:
		if (x > 490 && x < 530 && y > 310 && y < 350 && (((int)angle % 90) < 5 || ((int)angle % 90) > 85))
		{
			isDone = true;
		}
		break;

	case 2:
		if (x > 475 && x < 515 && y > -25 && y <15 && (angle > 355 || angle < 5))
		{
			isDone = true;
		}
		break;

	case 3:
		if (x > 490 && x < 530 && y > -220 && y < -180 && (angle > 355 || angle < 5))
		{
			isDone = true;
		}
		break;

	case 4:
		if (x > 515 && x < 555 && y > -20 && y < 20 && (angle > 355 || angle < 5))
		{
			isDone = true;
		}
		break;

	case 5:
		if (x > 595 && x < 635 && y > -75 && y < -35 && (angle > 355 || angle < 5))
		{
			isDone = true;
		}
		break;

	case 6:
		if (x > 410 && x < 450 && y > -105 && y < -65 && (angle > 355 || angle < 5))
		{
			isDone = true;
		}
		break;
	}
}

void TreePuzzle::Render()
{
	RenderSystem::GetInstance()->RotateBitmap(x, y, angle, image);

}

void TreePuzzle::Destroy()
{
}
#include "AirplanePuzzle.h"
#include "RenderSystem.h"
#include <string>

using namespace std;

AirplanePuzzle::AirplanePuzzle(double _x, double _y, float _angle, HBITMAP _hbm, int _puzzleNumber)
{
	x = _x;
	y = _y;
	angle = _angle;
	image = _hbm;
	puzzleNumber = _puzzleNumber;
}

void AirplanePuzzle::Init()
{
}

void AirplanePuzzle::FixedUpdate()
{
	SetCollider();
}

void AirplanePuzzle::Update()
{
	isDone = false;
	switch (puzzleNumber)
	{
	case 0:
		if (x > 300 && x < 330 && y > -250 && y < -220 && (angle > 355 || angle < 5))
		{
			isDone = true;
		}
		break;
	case 1:
		if (x > 960 && x < 990 && y > 210 && y < 240 && (angle > 355 || angle < 5))
		{
			isDone = true;
		}
		break;

	case 2:
		if (x > 1165 && x < 1195 && y > 245 && y < 275 && (angle > 355 || angle < 5))
		{
			isDone = true;
		}
		break;

	case 3:
		if (x > 1115 && x < 1145 && y > 120 && y < 150 && (angle > 355 || angle < 5))
		{
			isDone = true;
		}
		break;

	case 4:
		if (x > 545 && x < 575 && y > 375 && y < 405 && (angle > 355 || angle < 5))
		{
			isDone = true;
		}
		break;

	case 5:
		if (x > 955 && x < 985 && y > 605 && y < 635 && (angle > 355 || angle < 5))
		{
			isDone = true;
		}
		break;

	case 6:
		if (x > 425 && x < 455 && y > 155 && y < 185 && (angle > 355 || angle < 5))
		{
			isDone = true;
		}
		break;
	}
	

}

void AirplanePuzzle::Render()
{
	RenderSystem::GetInstance()->RotateBitmap(x, y, angle, image);
}

void AirplanePuzzle::Destroy()
{
}

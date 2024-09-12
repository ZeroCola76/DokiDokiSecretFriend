#include "RabbitPuzzle.h"
#include "RenderSystem.h"
#include <string>

using namespace std;

RabbitPuzzle::RabbitPuzzle(double _x, double _y, float _angle, HBITMAP _hbm, int _puzzleNumber)
{
	x = _x;
	y = _y;
	angle = _angle;
	image = _hbm;
	puzzleNumber = _puzzleNumber;
}

void RabbitPuzzle::Init()
{
}

void RabbitPuzzle::FixedUpdate()
{
	SetCollider();
}

void RabbitPuzzle::Update()
{
	isDone = false;

	switch (puzzleNumber)
	{
	case 0:
		if (x > 555 && x < 585 && y > 325 && y < 355 && (angle > 355 || angle < 5))
		{
			isDone = true;
		}
		break;
	case 1:
		if (x > 365 && x < 395 && y > 315 && y < 345 && (angle > 355 || angle < 5))
		{
			isDone = true;
		}
		break;

	case 2:
		if (x > 460 && x < 490 && y > -50 && y < -20 && (angle > 355 || angle < 5))
		{
			isDone = true;
		}
		break;

	case 3:
		if (x > 315 && x < 345 && y > 355 && y < 385 && (angle > 355 || angle < 5))
		{
			isDone = true;
		}
		break;

	case 4:
		if (x > 785 && x < 815 && y > 335 && y < 365 && (angle > 355 || angle < 5))
		{
			isDone = true;
		}
		break;

	case 5:
		if (x > 395 && x < 425 && y > 115 && y < 145 && (angle > 355 || angle < 5))
		{
			isDone = true;
		}
		break;

	case 6:
		if (x > 400 && x < 430 && ((y > 55 && y < 85) || (y > 5 && y < 35)) && (((int)angle % 180) < 5 || ((int)angle % 180) > 175))
		{
			isDone = true;
		}
		break;
	}
}

void RabbitPuzzle::Render()
{
	RenderSystem::GetInstance()->RotateBitmap(x, y, angle, image);
}

void RabbitPuzzle::Destroy()
{
}
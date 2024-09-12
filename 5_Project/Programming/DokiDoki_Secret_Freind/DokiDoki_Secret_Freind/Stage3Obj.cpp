#include "Stage3Obj.h"

void Stage3Obj::SetPos(double _x, double _y)
{
	BITMAP bm;
	GetObject(image, sizeof(BITMAP), &bm);

	x = _x - bm.bmWidth / 2;
	y = _y - bm.bmHeight / 2;
}
#include "PuzzleObj.h"
#include "RenderSystem.h"
#include <string>

using namespace std;

void PuzzleObj::SetCollider()
{
	if (angle > 360)
	{
		angle -= 360;
	}

	if (angle < 0)
	{
		angle += 360;
	}

	GetObject(image, sizeof(BITMAP), &bm);


	collider.left = x+(bm.bmWidth/4);
	collider.right = x + bm.bmWidth - (bm.bmWidth / 4);
	collider.top = y + (bm.bmHeight / 4);
	collider.bottom = y + bm.bmHeight - (bm.bmHeight / 4);

	objectCenter.x = (x + bm.bmWidth) / 2;
	objectCenter.y = (y + bm.bmHeight) / 2;


}

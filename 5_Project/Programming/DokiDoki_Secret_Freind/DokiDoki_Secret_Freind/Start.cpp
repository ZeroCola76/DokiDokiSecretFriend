#include "Start.h"
#include "InputSystem.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"

void Start::Init()
{
	startPos = CreateRectRgn(1380, 632, 1900, 732);
}

void Start::FixedUpdate()
{
}

void Start::Update()
{
	StartLogic();
}

void Start::Render()
{
	StartLogic();
}

void Start::Destroy()
{
}

void Start::StartLogic()
{
	pt.x = MouseInputSystem::GetInstance()->curMouse.x;
	pt.y = MouseInputSystem::GetInstance()->curMouse.y;

	isInsideStart = PtInRegion(startPos, pt.x, pt.y);
	
	if (isInsideStart == true)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->title.start, 0, 0);

		if (isClick == false)
		{
			if (MouseInputSystem::GetInstance()->curMouse.left)
			{
				isClick = true;
			}
		}
	}
}

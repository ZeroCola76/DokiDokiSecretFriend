#include "StartBG.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"
#include "InputSystem.h"

void StartBG::Init()
{
	boxPos = CreateRectRgn(850, 550, 950, 600);
}

void StartBG::FixedUpdate()
{
}

void StartBG::Update()
{
	GetStartButton();
}

void StartBG::Render()
{
	if (!inGame)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage1.popupBox, 650, 300);
	}
	if (isInsideBox)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage1.Check, 650, 300);
	}
}

void StartBG::Destroy()
{
}

void StartBG::GetStartButton()
{
	pt.x = MouseInputSystem::GetInstance()->curMouse.x;
	pt.y = MouseInputSystem::GetInstance()->curMouse.y;

	isInsideBox = PtInRegion(boxPos, pt.x, pt.y);

	if (isInsideBox)
	{
		if (!inGame)
		{
			if (MouseInputSystem::GetInstance()->curMouse.left) // 마우스 좌클릭이 되었다면
			{
				inGame = true;

				DeleteObject(boxPos);
			}
		}
	}
}


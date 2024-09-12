#include "Exit.h"
#include "InputSystem.h"
#include "WInApp.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"


void Exit::Init()
{
	exitPos = CreateRectRgn(1470, 900, 1900, 986);

}

void Exit::FixedUpdate()
{
}

void Exit::Update()
{
	ExitLogic();
}

void Exit::Render()
{
	ExitLogic();
}

void Exit::Destroy()
{
}

void Exit::ExitLogic()
{
	pt.x = MouseInputSystem::GetInstance()->curMouse.x;
	pt.y = MouseInputSystem::GetInstance()->curMouse.y;

	isInsideExit = PtInRegion(exitPos, pt.x, pt.y);

	if (isInsideExit == true)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->title.exit, 0, 0);

		if (isClick == false)
		{
			if (MouseInputSystem::GetInstance()->curMouse.left)
			{
				isClick = true;
			}
		}
	}

	if (isClick == true)
	{
		DestroyWindow(WinApp::GetInstance()->GetWindow());
	}
}

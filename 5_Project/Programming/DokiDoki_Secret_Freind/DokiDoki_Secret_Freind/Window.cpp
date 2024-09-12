#include "Window.h"
#include "RenderSystem.h"
#include "InputSystem.h"
#include "ResourcesManager.h"


void Window::Init()
{
	windowPos = CreateRectRgn(515, 160, 645, 320); //Window 위치값 한번만 정의됨

}

void Window::FixedUpdate()
{
}

void Window::Update()
{
	WindowLogic();
}

void Window::Render()
{
	WindowLogic();
}

void Window::Destroy()
{
}

void Window::WindowLogic()
{

	pt.x = MouseInputSystem::GetInstance()->curMouse.x;
	pt.y = MouseInputSystem::GetInstance()->curMouse.y;

	isInsideWindow = PtInRegion(windowPos, pt.x, pt.y); //마우스가 그 위치에 들어갔는지 확인


	if (isInsideWindow == true)
	{
		if (isClick == false)
		{
			if (MouseInputSystem::GetInstance()->curMouse.left)
			{
				isClick = true;
				isShow = true;
			}
		}
	}


	if (isClick == true && isShow == true) // 클릭이 되었다면 (isClick이 true 라면)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.backGround, 0, 0);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.girl, 0, 0);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.dialog, 0, 1080 - 400);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.window1, 0, 1080 - 230);


	}


	if (isClick == true) //좌클릭을 하여 clue는 눌린 상태에서
	{
		if (InputSystem::GetInstance()->GetKeyDown(SELECT)) //만약 스페이스바 눌린다면
		{
			isShow = false;
			isNext = true;
		}
	}



	if (isNext == true && isDestroy == false) //만약 마우스 좌클릭이 되었다면
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.backGround, 0, 0);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.dialog, 0, 1080 - 400);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.window2, 0, 1080 - 230);
	}


	if (InputSystem::GetInstance()->GetKeyDown(SELECT) && isNext == true)
	{
		isDestroy = true;
		isNext = false;
		cnt++;
	}
}


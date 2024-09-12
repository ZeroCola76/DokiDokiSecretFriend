#include "Window.h"
#include "RenderSystem.h"
#include "InputSystem.h"
#include "ResourcesManager.h"


void Window::Init()
{
	windowPos = CreateRectRgn(515, 160, 645, 320); //Window ��ġ�� �ѹ��� ���ǵ�

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

	isInsideWindow = PtInRegion(windowPos, pt.x, pt.y); //���콺�� �� ��ġ�� ������ Ȯ��


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


	if (isClick == true && isShow == true) // Ŭ���� �Ǿ��ٸ� (isClick�� true ���)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.backGround, 0, 0);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.girl, 0, 0);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.dialog, 0, 1080 - 400);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.window1, 0, 1080 - 230);


	}


	if (isClick == true) //��Ŭ���� �Ͽ� clue�� ���� ���¿���
	{
		if (InputSystem::GetInstance()->GetKeyDown(SELECT)) //���� �����̽��� �����ٸ�
		{
			isShow = false;
			isNext = true;
		}
	}



	if (isNext == true && isDestroy == false) //���� ���콺 ��Ŭ���� �Ǿ��ٸ�
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


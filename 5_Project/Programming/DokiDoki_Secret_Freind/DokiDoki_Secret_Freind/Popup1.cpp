#include "Popup1.h"
#include "InputSystem.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"

void Popup1::Init()
{
	okPos = CreateRectRgn(881, 602, 1015, 659);
}

void Popup1::FixedUpdate()
{
}

void Popup1::Update()
{
	PopUp1Logic();
}

void Popup1::Render()
{

	PopUp1Logic();
}

void Popup1::Destroy()
{
}

void Popup1::PopUp1Logic()
{
	//Ȯ�� ������ �� �˾�â ����(PopUp ����� -> false��)
	pt.x = MouseInputSystem::GetInstance()->curMouse.x;
	pt.y = MouseInputSystem::GetInstance()->curMouse.y;

	if (isDestroy == false)
	{
		//�������� �˾��̹��� ���
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.backGround, 0, 0);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.popUp1, 645, 355);
	}


	if (PtInRegion(okPos, pt.x, pt.y) && isDestroy == false)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.popUp1_a, 645, 355);

		if (MouseInputSystem::GetInstance()->curMouse.left)
		{
			isClick = true;
		}
	}

	if (isClick == true)
	{
		isDestroy = true;
	}
}
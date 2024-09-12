#include "Popup4.h"
#include "InputSystem.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"
#include "SceneManager.h"

void Popup4::Init()
{
	okPos = CreateRectRgn(881, 602, 1015, 659);
}

void Popup4::FixedUpdate()
{
}

void Popup4::Update()
{
	PopUp4Logic();
}

void Popup4::Render()
{
	PopUp4Logic();
}

void Popup4::Destroy()
{
}

void Popup4::PopUp4Logic()
{
	//È®ÀÎ ´­·¶À» ¶§ ÆË¾÷Ã¢ ´İÈû(PopUp »ç¶óÁü -> false°ª)
	pt.x = MouseInputSystem::GetInstance()->curMouse.x;
	pt.y = MouseInputSystem::GetInstance()->curMouse.y;

	if (isDestroy == false)
	{
		//¹è°æ»çÁø°ú ÆË¾÷ÀÌ¹ÌÁö Ãâ·Â
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.backGround, 0, 0);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.popUp4, 645, 355);
	}


	if (PtInRegion(okPos, pt.x, pt.y) && isDestroy == false)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.popUp4_a, 645, 355);

		if (MouseInputSystem::GetInstance()->curMouse.left)
		{
			isClick = true;
		}
	}

	if (isClick == true)
	{
		isDestroy = true;
		isPaid = true;
	}

	if (isPaid == true)
	{
		if (RenderSystem::GetInstance()->PaidIn(10))
		{
			SceneManager::GetInstance()->ChangeSceneState(S_DIALOG3);
		}
	}
	else
	{
		RenderSystem::GetInstance()->paidOut(10);
	}
}

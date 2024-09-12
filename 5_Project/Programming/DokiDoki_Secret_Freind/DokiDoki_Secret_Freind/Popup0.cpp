#include "Popup0.h"
#include "InputSystem.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"

void Popup0::Init()
{
	okPos = CreateRectRgn(881, 602, 1015, 659);
}

void Popup0::FixedUpdate()
{
}

void Popup0::Update()
{
	PopUp0Logic();
}

void Popup0::Render()
{
	PopUp0Logic();
}

void Popup0::Destroy()
{
}

void Popup0::PopUp0Logic()
{
	//È®ÀÎ ´­·¶À» ¶§ ÆË¾÷Ã¢ ´ÝÈû(PopUp »ç¶óÁü -> false°ª)
	pt.x = MouseInputSystem::GetInstance()->curMouse.x;
	pt.y = MouseInputSystem::GetInstance()->curMouse.y;

	if (isDestroy == false)
	{
		//¹è°æ»çÁø°ú ÆË¾÷ÀÌ¹ÌÁö Ãâ·Â
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.backGround, 0, 0);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.popUp0, 645, 355);
	}


	if (PtInRegion(okPos, pt.x, pt.y) && isDestroy == false)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.popUp0_a, 645, 355);

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

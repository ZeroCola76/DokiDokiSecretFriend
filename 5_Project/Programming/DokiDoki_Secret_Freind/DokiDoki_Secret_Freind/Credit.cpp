#include "Credit.h"
#include "InputSystem.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"


void Credit::Init()
{
	creditPos = CreateRectRgn(1430, 770, 1900, 856);
	//SoundManager::GetInstance()->SoundInit();
}

void Credit::FixedUpdate()
{
}

void Credit::Update()
{
	CreditLogic();
}

void Credit::Render()
{
	CreditLogic();
}

void Credit::Destroy()
{
	SoundManager::GetInstance()->ReleaseSound();
}

void Credit::CreditLogic()
{
	pt.x = MouseInputSystem::GetInstance()->curMouse.x;
	pt.y = MouseInputSystem::GetInstance()->curMouse.y;

	isInsideCredit = PtInRegion(creditPos, pt.x, pt.y);

	if (isInsideCredit == true)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->title.credit, 0, 0);

		if (isClick == false)
		{
			if (MouseInputSystem::GetInstance()->curMouse.left)
			{
				isClick = true;
				SceneManager::GetInstance()->ChangeSceneState(S_CREDIT);
				//SoundManager::GetInstance()->EffectPlay(SoundManager::GetInstance()->BUTTON);
			}
		}
	}

}

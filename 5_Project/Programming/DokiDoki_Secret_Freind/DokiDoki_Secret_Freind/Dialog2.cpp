#include "Dialog2.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"
#include "InputSystem.h"
#include "SceneManager.h"
#include "SoundManager.h"

void Dialog2::Init()
{
	dialogText[0] = ResourcesManager::GetInstance()->dialog2.dialog2_1;
	dialogText[1] = ResourcesManager::GetInstance()->dialog2.dialog2_2;
	dialogText[2] = ResourcesManager::GetInstance()->dialog2.dialog2_3;
	dialogText[3] = ResourcesManager::GetInstance()->dialog2.dialog2_4;
	dialogText[4] = ResourcesManager::GetInstance()->dialog2.dialog2_5;
	dialogText[5] = ResourcesManager::GetInstance()->dialog2.dialog2_6;
	dialogText[6] = ResourcesManager::GetInstance()->dialog2.dialog2_7;
	dialogText[7] = ResourcesManager::GetInstance()->dialog2.dialog2_8;
	dialogText[8] = ResourcesManager::GetInstance()->dialog2.dialog2_9;
	dialogText[9] = ResourcesManager::GetInstance()->dialog2.dialog2_10;

	SoundManager::GetInstance()->SoundInit();
	SoundManager::GetInstance()->MusicPlay(SoundManager::GetInstance()->DIALOG2);
}

void Dialog2::FixedUpdate()
{
}

void Dialog2::Update()
{
	if (InputSystem::GetInstance()->GetKeyDown(SELECT))
	{
		dialogCount++;
	}

	if (dialogCount == dialogMaxConut)
	{
		isPaid = true;
	}
}

void Dialog2::Render()
{
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.backGround, 0, 0);
	
	DrawGirl();

	if (dialogCount == 3)
	{
		DrawGirl_s();
	}

	DrawdialogBox();
	RenderSystem::GetInstance()->DrawBitmap(dialogText[dialogCount], 0, 1080 - 230);
	if (isPaid == true)
	{
		if (RenderSystem::GetInstance()->PaidIn(10))
		{
			SceneManager::GetInstance()->ChangeSceneState(S_STAGE2);
		}
	}
	else
	{
		RenderSystem::GetInstance()->paidOut(10);
	}
}

void Dialog2::Destroy()
{
	SoundManager::GetInstance()->ReleaseSound();
}

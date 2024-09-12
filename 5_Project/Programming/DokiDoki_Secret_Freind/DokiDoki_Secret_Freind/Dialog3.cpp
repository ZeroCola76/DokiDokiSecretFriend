#include "Dialog3.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"
#include "InputSystem.h"
#include "SceneManager.h"
#include "SoundManager.h"

void Dialog3::Init()
{
	dialogText[0] = ResourcesManager::GetInstance()->dialog3.dialog3_1;
	dialogText[1] = ResourcesManager::GetInstance()->dialog3.dialog3_2;
	dialogText[2] = ResourcesManager::GetInstance()->dialog3.dialog3_3;
	dialogText[3] = ResourcesManager::GetInstance()->dialog3.dialog3_4;
	dialogText[4] = ResourcesManager::GetInstance()->dialog3.dialog3_5;
	dialogText[5] = ResourcesManager::GetInstance()->dialog3.dialog3_6;
	dialogText[6] = ResourcesManager::GetInstance()->dialog3.dialog3_7;
	dialogText[7] = ResourcesManager::GetInstance()->dialog3.dialog3_8;

	SoundManager::GetInstance()->SoundInit();
	SoundManager::GetInstance()->MusicPlay(SoundManager::GetInstance()->DIALOG2);

	isPaid = false;
}

void Dialog3::FixedUpdate()
{
}

void Dialog3::Update()
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

void Dialog3::Render()
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
			SceneManager::GetInstance()->ChangeSceneState(S_STAGE3);
		}
	}
}

void Dialog3::Destroy()
{
	SoundManager::GetInstance()->ReleaseSound();
}

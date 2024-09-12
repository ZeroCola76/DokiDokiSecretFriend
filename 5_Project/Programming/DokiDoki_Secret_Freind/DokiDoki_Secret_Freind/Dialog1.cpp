#include "Dialog1.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"
#include "InputSystem.h"
#include "SceneManager.h"
#include "SoundManager.h"

void Dialog1::Init()
{
	dialogText[0] = ResourcesManager::GetInstance()->dialog1.dialog1_1;
	dialogText[1] = ResourcesManager::GetInstance()->dialog1.dialog1_2;
	dialogText[2] = ResourcesManager::GetInstance()->dialog1.dialog1_3;
	dialogText[3] = ResourcesManager::GetInstance()->dialog1.dialog1_4;
	dialogText[4] = ResourcesManager::GetInstance()->dialog1.dialog1_5;
	dialogText[5] = ResourcesManager::GetInstance()->dialog1.dialog1_6;
	dialogText[6] = ResourcesManager::GetInstance()->dialog1.dialog1_7;
	dialogText[7] = ResourcesManager::GetInstance()->dialog1.dialog1_8;
	dialogText[8] = ResourcesManager::GetInstance()->dialog1.dialog1_9;
	dialogText[9] = ResourcesManager::GetInstance()->dialog1.dialog1_10;
	dialogText[10] = ResourcesManager::GetInstance()->dialog1.dialog1_11;
	dialogText[11] = ResourcesManager::GetInstance()->dialog1.dialog1_12;
	dialogText[12] = ResourcesManager::GetInstance()->dialog1.dialog1_13;
	dialogText[13] = ResourcesManager::GetInstance()->dialog1.dialog1_14;
	dialogText[14] = ResourcesManager::GetInstance()->dialog1.dialog1_15;

	SoundManager::GetInstance()->SoundInit();
	SoundManager::GetInstance()->MusicPlay(SoundManager::GetInstance()->Intro);
	isPaid = false;
}

void Dialog1::FixedUpdate()
{
}

void Dialog1::Update()
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

void Dialog1::Render()
{
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage1.backGround, 0, 0);
	
	if (dialogCount == 4 || dialogCount == 6 || dialogCount == 13)
	{
		DrawBoy();
	}

	DrawGirl();

	if (dialogCount == 3 || dialogCount == 8)
	{
		DrawGirl_s();
	}

	if (dialogCount == 7 || dialogCount == 9)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage1.backGround, 0, 0);
		DrawBoy();
	}

	if (dialogCount == 14)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage1.backGround, 0, 0);
		DrawGirl_s();
		DrawBoy();
	}

	DrawdialogBox();
	RenderSystem::GetInstance()->DrawBitmap(dialogText[dialogCount], 0, 1080 - 230);
	if (isPaid == true)
	{
		if (RenderSystem::GetInstance()->PaidIn(10))
		{
			SceneManager::GetInstance()->ChangeSceneState(S_DIALOG2);
		}
	}
	else
	{
		RenderSystem::GetInstance()->paidOut(10);
	}
}

void Dialog1::Destroy()
{
	SoundManager::GetInstance()->ReleaseSound();
}

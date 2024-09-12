#include "End.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"
#include "InputSystem.h"
#include "SceneManager.h"
#include "SoundManager.h"

void End::Init()
{
	dialogText[0] = ResourcesManager::GetInstance()->end.end1;
	dialogText[1] = ResourcesManager::GetInstance()->end.end2;
	dialogText[2] = ResourcesManager::GetInstance()->end.end3;
	dialogText[3] = ResourcesManager::GetInstance()->end.end4;
	dialogText[4] = ResourcesManager::GetInstance()->end.end5;
	dialogText[5] = ResourcesManager::GetInstance()->end.end6;
	dialogText[6] = ResourcesManager::GetInstance()->end.end7;
	dialogText[7] = ResourcesManager::GetInstance()->end.end8;
	dialogText[8] = ResourcesManager::GetInstance()->end.end9;
	dialogText[9] = ResourcesManager::GetInstance()->end.end10;
	dialogText[10] = ResourcesManager::GetInstance()->end.end11;
	dialogText[11] = ResourcesManager::GetInstance()->end.end12;
	dialogText[12] = ResourcesManager::GetInstance()->end.end13;
	dialogText[13] = ResourcesManager::GetInstance()->end.end14;
	dialogText[14] = ResourcesManager::GetInstance()->end.end15;
	dialogText[15] = ResourcesManager::GetInstance()->end.end16;
	dialogText[16] = ResourcesManager::GetInstance()->end.end17;
	dialogText[17] = ResourcesManager::GetInstance()->end.end18;
	dialogText[18] = ResourcesManager::GetInstance()->end.end19;
	dialogText[19] = ResourcesManager::GetInstance()->end.end20;
	dialogText[20] = ResourcesManager::GetInstance()->end.end21;
	dialogText[21] = ResourcesManager::GetInstance()->end.end22;
	dialogText[22] = ResourcesManager::GetInstance()->end.end23;
	dialogText[23] = ResourcesManager::GetInstance()->end.end24;

	SoundManager::GetInstance()->SoundInit();
	SoundManager::GetInstance()->MusicPlay(SoundManager::GetInstance()->END);
}

void End::FixedUpdate()
{
}

void End::Update()
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

void End::Render()
{
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.backGround, 0, 0);

	if (dialogCount == 14 || dialogCount == 20 || dialogCount == 21)
	{
		DrawBoy();
	}

	if (dialogCount == 1 || dialogCount == 22)
	{
		DrawBoy_s();
	}

	DrawGirl();

	if (dialogCount == 6)
	{
		DrawGirl_s();
	}

	if (dialogCount == 5 || dialogCount == 7 || dialogCount == 10 || dialogCount == 13)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.backGround, 0, 0);
		DrawBoy();
	}

	if (dialogCount == 3 || dialogCount == 8 || dialogCount == 23)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.backGround, 0, 0);
		DrawBoy_s();
	}


	DrawdialogBox();
	RenderSystem::GetInstance()->DrawBitmap(dialogText[dialogCount], 0, 1080 - 230);

	if (isPaid == true)
	{
		if (RenderSystem::GetInstance()->PaidIn(10))
		{
			SceneManager::GetInstance()->ChangeSceneState(S_ENDIGIMG);
		}
	}
	else
	{
		RenderSystem::GetInstance()->paidOut(10);
	}
}

void End::Destroy()
{
	SoundManager::GetInstance()->ReleaseSound();
}

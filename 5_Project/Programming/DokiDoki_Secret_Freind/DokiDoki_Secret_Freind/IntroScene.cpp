#include "IntroScene.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"
#include "InputSystem.h"
#include "SceneManager.h"
#include "SoundManager.h"

void IntroScene::Init()
{
	dialogText[0] = ResourcesManager::GetInstance()->intro.intro1;
	dialogText[1] = ResourcesManager::GetInstance()->intro.intro2;
	dialogText[2] = ResourcesManager::GetInstance()->intro.intro3;
	dialogText[3] = ResourcesManager::GetInstance()->intro.intro4;
	dialogText[4] = ResourcesManager::GetInstance()->intro.intro5;
	dialogText[5] = ResourcesManager::GetInstance()->intro.intro6;
	dialogText[6] = ResourcesManager::GetInstance()->intro.intro7;
	dialogText[7] = ResourcesManager::GetInstance()->intro.intro8;
	dialogText[8] = ResourcesManager::GetInstance()->intro.intro9;

	SoundManager::GetInstance()->SoundInit();
	SoundManager::GetInstance()->MusicPlay(SoundManager::GetInstance()->Intro);
}

void IntroScene::FixedUpdate()
{
}

void IntroScene::Update()
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

void IntroScene::Render()
{
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage1.backGround, 0, 0);
	DrawGirl();

	if (dialogCount == 0 || dialogCount == 1 || dialogCount == 7)
	{
		DrawGirl_b();
	}

	DrawdialogBox();
	RenderSystem::GetInstance()->DrawBitmap(dialogText[dialogCount],0, 1080 - 230);

	if (isPaid == true)
	{
		if (RenderSystem::GetInstance()->PaidIn(10))
		{
			SceneManager::GetInstance()->ChangeSceneState(S_STAGE1);
		}
	}
	else
	{
		RenderSystem::GetInstance()->paidOut(10);
	}
}

void IntroScene::Destroy()
{
	SoundManager::GetInstance()->ReleaseSound();
}
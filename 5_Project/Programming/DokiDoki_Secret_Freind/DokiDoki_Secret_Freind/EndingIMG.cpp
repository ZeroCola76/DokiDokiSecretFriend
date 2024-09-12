#include "EndingIMG.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"
#include "InputSystem.h"
#include "SceneManager.h"
#include "SoundManager.h"

void EndingIMG::Init()
{
	SoundManager::GetInstance()->SoundInit();
	SoundManager::GetInstance()->MusicPlay(SoundManager::GetInstance()->ENDING);
}

void EndingIMG::FixedUpdate()
{
}

void EndingIMG::Update()
{
	if (InputSystem::GetInstance()->GetKeyDown(SELECT))
	{
		isPaid = true;

	}
}

void EndingIMG::Render()
{
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->end.ending, 0, 0);

	if (isPaid == true)
	{
		if (RenderSystem::GetInstance()->PaidIn(10))
		{
			SceneManager::GetInstance()->ChangeSceneState(S_TITLE);
		}
	}
	else
	{
		RenderSystem::GetInstance()->paidOut(10);
	}
}

void EndingIMG::Destroy()
{
	SoundManager::GetInstance()->ReleaseSound();
}

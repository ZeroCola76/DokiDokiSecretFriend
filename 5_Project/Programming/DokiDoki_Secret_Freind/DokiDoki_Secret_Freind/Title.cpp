#include "Title.h"
#include "RenderSystem.h"
#include "InputSystem.h"
#include "SceneManager.h"
#include "ResourcesManager.h"
#include "SoundManager.h"

#include "Start.h"
#include "Credit.h"
#include "Exit.h"
#include "TitleBack.h"

void Title::Init()
{
	SoundManager::GetInstance()->SoundInit();
	SoundManager::GetInstance()->MusicPlay(SoundManager::GetInstance()->TITLE);

	titleBack = new TitleBack(0, 0, ResourcesManager::GetInstance()->title.backGround);

	start = new Start();
	credit = new Credit();
	exit = new Exit();

}

void Title::FixedUpdate()
{

}

void Title::Update()
{


	if (start->isClick == false)
	{
		titleBack->Update();
		start->Update();
		credit->Update();
		exit->Update();
	}
	
}

void Title::Render()
{
	
		titleBack->Render();
		start->Render();
		credit->Render();
		exit->Render();
		if (start->isClick == true)
		{
			if (RenderSystem::GetInstance()->PaidIn(10))
			{
				SceneManager::GetInstance()->ChangeSceneState(S_INTRO);
			}

		}
}

void Title::Destroy()
{
	SAFE_DELETE(start);
	SAFE_DELETE(credit);
	SAFE_DELETE(exit);
	SAFE_DELETE(titleBack);

	SoundManager::GetInstance()->ReleaseSound();
}

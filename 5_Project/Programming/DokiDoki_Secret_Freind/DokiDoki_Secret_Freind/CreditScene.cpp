#include "CreditScene.h"
#include "RenderSystem.h"
#include "InputSystem.h"
#include "ResourcesManager.h"
#include "SoundManager.h"
#include "CreditBack.h"

void CreditScene::Init()
{
	SoundManager::GetInstance()->SoundInit();

	creditBack = new CreditBack();
	SoundManager::GetInstance()->MusicPlay(SoundManager::GetInstance()->CREDIT);
}

void CreditScene::FixedUpdate()
{
}

void CreditScene::Update()
{


	creditBack->Update();
}

void CreditScene::Render()
{
	creditBack->Render();
}

void CreditScene::Destroy()
{
	SoundManager::GetInstance()->ReleaseSound();

	SAFE_DELETE(creditBack);
}
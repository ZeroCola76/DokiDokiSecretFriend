#include "BackGround.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"

void Background::Init()
{
}

void Background::FixedUpdate()
{
}

void Background::Update()
{
}

void Background::Render()
{
	//RenderSystem::GetInstance()->DrawRect(0, 0, 1920, 1080, RGB(255, 0, 0));
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage1.backGround, 0, 0);
}

void Background::Destroy()
{
}	
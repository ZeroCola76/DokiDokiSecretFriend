#include "UI2.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"

void UI2::Init()
{
}

void UI2::FixedUpdate()
{
}

void UI2::Update()
{
}

void UI2::Render()
{
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.findUI2, 0, 0);
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.remainUI2, 1980 - 465, 0);
}

void UI2::Destroy()
{
}

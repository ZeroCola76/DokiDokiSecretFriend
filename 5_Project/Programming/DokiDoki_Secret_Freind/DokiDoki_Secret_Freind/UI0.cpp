#include "UI0.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"

void UI0::Init()
{
}

void UI0::FixedUpdate()
{
}

void UI0::Update()
{

}

void UI0::Render()
{
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.findUI0, 0, 0);
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.remainUI4, 1980 - 465, 0);
}

void UI0::Destroy()
{
}

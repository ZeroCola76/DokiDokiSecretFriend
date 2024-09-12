#include "UI1.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"

void UI1::Init()
{
}

void UI1::FixedUpdate()
{
}

void UI1::Update()
{

}

void UI1::Render()
{
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.findUI1, 0, 0);
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.remainUI3, 1980 - 465, 0);
}

void UI1::Destroy()
{
}

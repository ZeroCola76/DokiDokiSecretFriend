#include "UI3.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"

void UI3::Init()
{
}

void UI3::FixedUpdate()
{
}

void UI3::Update()
{

}

void UI3::Render()
{
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.findUI3, 0, 0);
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.remainUI1, 1980 - 465, 0);
}

void UI3::Destroy()
{
}

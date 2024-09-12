#include "RemainUI.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"

void RemainUI::Init()
{
}

void RemainUI::FixedUpdate()
{
}

void RemainUI::Update()
{
}

void RemainUI::Render()
{
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.remainUI4, 1980-465, 0);
}

void RemainUI::Destroy()
{
}

#include "FindUI.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"
#include <string>
#include <stdlib.h>

void FindUI::Init()
{
}

void FindUI::FixedUpdate()
{
}

void FindUI::Update()
{
}

void FindUI::Render()
{
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.findUI0, 0, 0);

}

void FindUI::Destroy()
{
}

#include "RBG.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"

void RBG::Init()
{
}

void RBG::FixedUpdate()
{
}

void RBG::Update()
{
}

void RBG::Render()
{
	RenderSystem::GetInstance()->DrawRect(0, 310, 2000, 300, RGB(255, 255, 254));
	//RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage1.noteBG, 0, 300);
}

void RBG::Destroy()
{
}

#include "D_Before_Stage2.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"

void D_Before_Stage2::Init()
{
}

void D_Before_Stage2::FixedUpdate()
{
}

void D_Before_Stage2::Update()
{
}

void D_Before_Stage2::Render()
{
	DrawGirl();
	DrawdialogBox();
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.)
}

void D_Before_Stage2::Destroy()
{
}

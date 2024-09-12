#include "TitleBack.h"
#include "RenderSystem.h"


void TitleBack::Init()
{
}

void TitleBack::FixedUpdate()
{
}

void TitleBack::Update()
{
}

void TitleBack::Render()
{
	RenderSystem::GetInstance()->DrawBitmap(image, x, y);
}

void TitleBack::Destroy()
{
}

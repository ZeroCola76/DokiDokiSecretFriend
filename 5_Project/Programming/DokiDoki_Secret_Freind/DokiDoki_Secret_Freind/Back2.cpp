#include "Back2.h"
#include "RenderSystem.h"


void Back2::Init()
{
	
}

void Back2::FixedUpdate()
{
}

void Back2::Update()
{
}

void Back2::Render()
{
	RenderSystem::GetInstance()->DrawBitmap(image, x, y);
}

void Back2::Destroy()
{
}

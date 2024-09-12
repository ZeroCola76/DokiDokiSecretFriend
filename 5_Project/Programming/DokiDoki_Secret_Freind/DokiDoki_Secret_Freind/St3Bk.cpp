#include "St3Bk.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"

void St3Bk::Init()
{
}

void St3Bk::FixedUpdate()
{
}

void St3Bk::Update()
{
}

void St3Bk::Render()
{
	RenderSystem::GetInstance()->DrawBitmap(image, x, y);
	//RenderSystem::GetInstance()->DrawDialogBox(image, 0, 0,255);

}

void St3Bk::Destroy()
{
}

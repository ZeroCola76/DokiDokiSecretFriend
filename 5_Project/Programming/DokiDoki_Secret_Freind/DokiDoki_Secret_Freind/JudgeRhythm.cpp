#include "JudgeRhythm.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"

void JudgeRhythm::Init()
{
}

void JudgeRhythm::FixedUpdate()
{
}

void JudgeRhythm::Update()
{
}

void JudgeRhythm::Render()
{
	//RenderSystem::GetInstance()->DrawCircle(200, 450);
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage1.noteCircle, 0, 0);
}

void JudgeRhythm::Destroy()
{
}
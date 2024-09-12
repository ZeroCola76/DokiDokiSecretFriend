#include "Dialog.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"

void Dialog::LoadCore()
{
}

void Dialog::DrawGirl()
{
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.girl,0,0);
}

void Dialog::DrawGirl_s()
{
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.girl_s, 0, 0);
}

void Dialog::DrawGirl_b()
{
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.girl_b, 0, 0);
}

void Dialog::DrawBoy()
{
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.boy, 1920-508, 0);
}

void Dialog::DrawBoy_s()
{
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.boy_s, 1920 - 508, 0);
}

void Dialog::DrawdialogBox()
{
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.dialog, 0, 1080 - 400);

}

void Dialog::DrawtxtBtn()
{
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.txtBtn, 1700, 950);

}

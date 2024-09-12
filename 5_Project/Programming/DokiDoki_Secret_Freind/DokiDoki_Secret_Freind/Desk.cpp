#include "Desk.h"
#include "RenderSystem.h"
#include "InputSystem.h"
#include "ResourcesManager.h"


void Desk::Init()
{
	deskPos1 = CreateRectRgn(1600, 830, 1640, 880);
	deskPos2 = CreateRectRgn(1670, 720, 1710, 770);
	deskPos3 = CreateRectRgn(1755, 640, 1785, 690);
	deskPos4 = CreateRectRgn(1820, 580, 1842, 630);
	deskPos5 = CreateRectRgn(1210, 890, 1275, 950);
	deskPos6 = CreateRectRgn(1310, 770, 1390, 830);
	deskPos7 = CreateRectRgn(622, 750, 702, 810);
	deskPos8 = CreateRectRgn(842, 670, 902, 720);
	deskPos10 = CreateRectRgn(140, 580, 240, 660);

}

void Desk::FixedUpdate()
{
}

void Desk::Update()
{
	DeskLogic();
}

void Desk::Render()
{
	//RenderSystem::GetInstance()->DrawRect(1600, 830, 40, 50, RGB(243, 176, 195)); //1
	//RenderSystem::GetInstance()->DrawRect(1670, 720, 60, 50, RGB(243, 176, 195)); //2
	//RenderSystem::GetInstance()->DrawRect(1755, 640, 30, 50, RGB(243, 176, 195)); //3
	//RenderSystem::GetInstance()->DrawRect(1820, 580, 22, 50, RGB(243, 176, 195)); //4
	//RenderSystem::GetInstance()->DrawRect(1210, 890, 65, 60, RGB(243, 176, 195)); //5
	//RenderSystem::GetInstance()->DrawRect(1310, 770, 80, 60, RGB(243, 176, 195)); //6
	//RenderSystem::GetInstance()->DrawRect(622, 750, 80, 60, RGB(243, 176, 195)); //7
	//RenderSystem::GetInstance()->DrawRect(842, 670, 60, 50, RGB(243, 176, 195)); //8
	//RenderSystem::GetInstance()->DrawRect(140, 580, 100, 80, RGB(243, 176, 195)); //10

	DeskLogic();
}

void Desk::Destroy()
{
}

void Desk::DeskLogic()
{
	pt.x = MouseInputSystem::GetInstance()->curMouse.x;
	pt.y = MouseInputSystem::GetInstance()->curMouse.y;


	isInsideDesk1 = PtInRegion(deskPos1, pt.x, pt.y);
	isInsideDesk2 = PtInRegion(deskPos2, pt.x, pt.y);
	isInsideDesk3 = PtInRegion(deskPos3, pt.x, pt.y);
	isInsideDesk4 = PtInRegion(deskPos4, pt.x, pt.y);
	isInsideDesk5 = PtInRegion(deskPos5, pt.x, pt.y);
	isInsideDesk6 = PtInRegion(deskPos6, pt.x, pt.y);
	isInsideDesk7 = PtInRegion(deskPos7, pt.x, pt.y);
	isInsideDesk8 = PtInRegion(deskPos8, pt.x, pt.y);
	isInsideDesk10 = PtInRegion(deskPos10, pt.x, pt.y);



	if (isInsideDesk1 || isInsideDesk2 || isInsideDesk3 || isInsideDesk4 || isInsideDesk5 ||
		isInsideDesk6 || isInsideDesk7 || isInsideDesk8 || isInsideDesk10)
	{
		if (isClick == false)
		{
			if (MouseInputSystem::GetInstance()->curMouse.left)
			{
				isClick = true;
				isShow = true;
			}
		}
	}


	if (isClick == true && isShow == true) // 클릭이 되었다면 (isClick이 true 라면)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.backGround, 0, 0);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.girl, 0, 0);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.dialog, 0, 1080 - 400);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.desk1, 0, 1080 - 230);
	}


	if (isClick == true) //좌클릭을 하여 clue는 눌린 상태에서
	{
		if (InputSystem::GetInstance()->GetKeyDown(SELECT)) //만약 스페이스바 눌린다면
		{
			isShow = false;
			isNext = true;
		}
	}



	if (isNext == true && isDestroy == false) //만약 마우스 좌클릭이 되었다면
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.backGround, 0, 0);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.dialog, 0, 1080 - 400);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.desk2, 0, 1080 - 230);
	}


	if (InputSystem::GetInstance()->GetKeyDown(SELECT) && isNext == true)
	{
		isDestroy = true;
		isNext = false;
		cnt++;
	}

}

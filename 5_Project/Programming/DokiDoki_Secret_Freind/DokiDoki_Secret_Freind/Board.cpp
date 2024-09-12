#include "Board.h"
#include "RenderSystem.h"
#include "InputSystem.h"
#include "ResourcesManager.h"

void Board::Init()
{
	boardPos = CreateRectRgn(1110, 85, 1710, 285); //board
}

void Board::FixedUpdate()
{
}

void Board::Update()
{
	BoardLogic();
}

void Board::Render()
{
	BoardLogic();
}

void Board::Destroy()
{
}

void Board::BoardLogic()
{

	pt.x = MouseInputSystem::GetInstance()->curMouse.x;
	pt.y = MouseInputSystem::GetInstance()->curMouse.y;


	isInsideBoard = PtInRegion(boardPos, pt.x, pt.y);

	if (isInsideBoard == true) // 만약에 Board 영역에 마우스가 들어왔다면
	{
		if (isClick == false) //그리고 한번도 클릭 되지 않았다면(isClick이 false이면)
		{
			if (MouseInputSystem::GetInstance()->curMouse.left) // 마우스 좌클릭이 되었다면
			{
				isClick = true; // 클릭이 되었다는 걸 체크해주고(isClick을 true로 바꾸고)
				isShow = true;
			}
		}
	}

	if (isClick == true && isShow == true) // 클릭이 되었다면 (isClick이 true 라면)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.backGround, 0, 0);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.girl, 0, 0);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.dialog, 0, 1080 - 400);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.board1, 0, 1080 - 230);

	}


	if (isClick == true) //좌클릭을 하여 clue는 눌린 상태에서
	{
		if (InputSystem::GetInstance()->GetKeyDown(SELECT)) //만약 스페이스바 눌린다면
		{
			isShow = false;
			isNext = true;
		}
	}



	if (isNext == true && isDestroy == false)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.backGround, 0, 0);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.dialog, 0, 1080 - 400);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.board2, 0, 1080 - 230);
	}

	if (InputSystem::GetInstance()->GetKeyDown(SELECT) && isNext == true)
	{
		isDestroy = true;
		isNext = false;
		cnt++;
	}

}
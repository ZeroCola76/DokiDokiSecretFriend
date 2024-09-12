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

	if (isInsideBoard == true) // ���࿡ Board ������ ���콺�� ���Դٸ�
	{
		if (isClick == false) //�׸��� �ѹ��� Ŭ�� ���� �ʾҴٸ�(isClick�� false�̸�)
		{
			if (MouseInputSystem::GetInstance()->curMouse.left) // ���콺 ��Ŭ���� �Ǿ��ٸ�
			{
				isClick = true; // Ŭ���� �Ǿ��ٴ� �� üũ���ְ�(isClick�� true�� �ٲٰ�)
				isShow = true;
			}
		}
	}

	if (isClick == true && isShow == true) // Ŭ���� �Ǿ��ٸ� (isClick�� true ���)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.backGround, 0, 0);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.girl, 0, 0);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.dialog, 0, 1080 - 400);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.board1, 0, 1080 - 230);

	}


	if (isClick == true) //��Ŭ���� �Ͽ� clue�� ���� ���¿���
	{
		if (InputSystem::GetInstance()->GetKeyDown(SELECT)) //���� �����̽��� �����ٸ�
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
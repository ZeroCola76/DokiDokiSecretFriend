#include "Note.h"
#include "RenderSystem.h"
#include "InputSystem.h"
#include "ResourcesManager.h"


void Note::Init()
{
	notePos = CreateRectRgn(950, 100, 1062, 263); //��Ʈ ��ġ
}

void Note::FixedUpdate()
{
}

void Note::Update()
{
	NoteLogic();
}

void Note::Render()
{
	NoteLogic();
}

void Note::Destroy()
{
}

void Note::NoteLogic()
{
	pt.x = MouseInputSystem::GetInstance()->curMouse.x;
	pt.y = MouseInputSystem::GetInstance()->curMouse.y;


	isInsideNote = PtInRegion(notePos, pt.x, pt.y);

	if (isInsideNote == true)
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

	if (isClick == true && isShow == true) // Ŭ���� �Ǿ��ٸ� (isClick�� true ���)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.backGround, 0, 0);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.girl, 0, 0);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.dialog, 0, 1080 - 400);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.note1, 0, 1080 - 230);

	}


	if (isClick == true) //��Ŭ���� �Ͽ� clue�� ���� ���¿���
	{
		if (InputSystem::GetInstance()->GetKeyDown(SELECT)) //���� �����̽��� �����ٸ�
		{
			isShow = false;
			isNext = true;
		}
	}



	if (isNext == true && isDestroy == false) //���� ���콺 ��Ŭ���� �Ǿ��ٸ�
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.backGround, 0, 0);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->dialog.dialog, 0, 1080 - 400);
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage2.note2, 0, 1080 - 230);
	}

	if (InputSystem::GetInstance()->GetKeyDown(SELECT) && isNext == true)
	{
		isDestroy = true;
		isNext = false;
		cnt++;
	}
}
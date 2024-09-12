#include "Stage2.h"
#include "RenderSystem.h"
#include "InputSystem.h"
#include "ResourcesManager.h"
#include "SoundManager.h"

#include "Window.h"
#include "Board.h"
#include "Desk.h"
#include "Note.h"
#include "Back2.h"

#include "Popup0.h"
#include "Popup1.h"
#include "Popup2.h"
#include "Popup3.h"
#include "Popup4.h"

#include "UI0.h"
#include "UI1.h"
#include "UI2.h"
#include "UI3.h"



void Stage2::Init()
{
	back2 = new Back2(0, 0, ResourcesManager::GetInstance()->stage2.backGround);

	window = new Window();
	board = new Board();
	desk = new Desk();
	note = new Note();


	popUp0 = new Popup0();
	popUp1 = new Popup1();
	popUp2 = new Popup2();
	popUp3 = new Popup3();
	popUp4 = new Popup4();

	ui0 = new UI0();
	ui1 = new UI1();
	ui2 = new UI2();
	ui3 = new UI3();

	Stage2Obj::cnt = 0;
	SoundManager::GetInstance()->SoundInit();
	SoundManager::GetInstance()->MusicPlay(SoundManager::GetInstance()->DIALOG2);

}

void Stage2::FixedUpdate()
{
}

void Stage2::Update()
{

	//popUp0->Update();


	if (popUp0->isDestroy) //�̰� Ȯ��
	{
		window->Update();
		board->Update();
		desk->Update();
		note->Update();
	}

	/*if (Stage2Obj::cnt == 0)
	{
		ui0->Update();
	}

	if (Stage2Obj::cnt == 1)
	{
		if (popUp0->isDestroy)
		{
			popUp1->Update();
		}
	}

	if (popUp1->isDestroy)
	{
		ui1->Update();
	}

	if (Stage2Obj::cnt == 2)
	{
		if (popUp1->isDestroy)
		{
			popUp2->Update();

		}
	}

	if (popUp2->isDestroy)
	{
		ui2->Update();
	}


	if (Stage2Obj::cnt == 3)
	{
		if (popUp2->isDestroy)
		{
			popUp3->Update();
		}
	}

	if (popUp3->isDestroy)
	{
		ui3->Update();
	}*/

}

void Stage2::Render()
{
	back2->Render(); // stage2 ����� �����ض�

	popUp0->Render(); //���� �˾�â�� �����ض�

	if (popUp0->isDestroy) // ���� �˾�â�� �ı��Ǹ� �ܼ����� �����ض�.
	{
		window->Render();
		board->Render();
		desk->Render();
		note->Render();
	}


	/* 4���� �ܼ��� �� �ϳ��� ���� �� ���� cnt�� + 1 ���״�.*/

	if (Stage2Obj::cnt == 0) //cnt�� 0�̸�
	{
		ui0->Render(); // ã�� �ܼ� 0, ���� �ܼ� 4 ui�� �����ض�.
	}

	if (Stage2Obj::cnt == 1) // cnt�� 1�̸�
	{
		if (popUp0->isDestroy) // �˾�â0�� �ı��� �Ǿ��ٸ�
		{
			popUp1->Render(); //�˾�â 1�� �����ض�.
		}
	}

	if (popUp1->isDestroy) //�˾�â1�� �ı��Ǿ��ٸ�
	{
		ui1->Render(); // ã�� �ܼ� 1, ���� �ܼ� 3 ui�� �����ض�
	}

	if (Stage2Obj::cnt == 2) // cnt�� 2�̸�
	{
		if (popUp1->isDestroy)
		{
			popUp2->Render(); //�˾�â 2�� �����ض�.
		}
	}

	if (popUp2->isDestroy)//�˾�â2�� �ı��Ǿ��ٸ�
	{
		ui2->Render();  // ã�� �ܼ� 2, ���� �ܼ� 2 ui�� �����ض�
	}

	if (Stage2Obj::cnt == 3) // cnt�� 3�̸�
	{
		if (popUp2->isDestroy)
		{
			popUp3->Render(); //�˾�â 3�� �����ض�.
		}
	}

	if (popUp3->isDestroy)//�˾�â3�� �ı��Ǿ��ٸ�
	{
		ui3->Render(); // ã�� �ܼ� 3, ���� �ܼ� 1 ui�� �����ض�
	}



	if (Stage2Obj::cnt == 4)  // cnt�� 4��
	{
		if (popUp3->isDestroy)
		{
			popUp4->Render(); // �Ϸ� �˾�â�� �����ض�.
		}
	}


}

void Stage2::Destroy()
{
	SoundManager::GetInstance()->ReleaseSound();

	SAFE_DELETE(back2);

	SAFE_DELETE(window);
	SAFE_DELETE(board);
	SAFE_DELETE(desk);
	SAFE_DELETE(note);

	SAFE_DELETE(popUp0);
	SAFE_DELETE(popUp1);
	SAFE_DELETE(popUp2);
	SAFE_DELETE(popUp3);
	SAFE_DELETE(popUp4);
	
	SAFE_DELETE(ui0);
	SAFE_DELETE(ui1);
	SAFE_DELETE(ui2);
	SAFE_DELETE(ui3);
}

void Stage2::GameLogic()
{
}

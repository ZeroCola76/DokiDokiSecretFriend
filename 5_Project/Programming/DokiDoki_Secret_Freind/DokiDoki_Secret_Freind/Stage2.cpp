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


	if (popUp0->isDestroy) //이거 확정
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
	back2->Render(); // stage2 배경을 렌더해라

	popUp0->Render(); //시작 팝업창을 렌더해라

	if (popUp0->isDestroy) // 시작 팝업창이 파괴되면 단서들을 렌더해라.
	{
		window->Render();
		board->Render();
		desk->Render();
		note->Render();
	}


	/* 4개의 단서들 중 하나가 끝날 때 마다 cnt를 + 1 시켰다.*/

	if (Stage2Obj::cnt == 0) //cnt가 0이면
	{
		ui0->Render(); // 찾은 단서 0, 남은 단서 4 ui를 렌더해라.
	}

	if (Stage2Obj::cnt == 1) // cnt가 1이면
	{
		if (popUp0->isDestroy) // 팝업창0이 파괴가 되었다면
		{
			popUp1->Render(); //팝업창 1을 렌더해라.
		}
	}

	if (popUp1->isDestroy) //팝업창1이 파괴되었다면
	{
		ui1->Render(); // 찾은 단서 1, 남은 단서 3 ui를 렌더해라
	}

	if (Stage2Obj::cnt == 2) // cnt가 2이면
	{
		if (popUp1->isDestroy)
		{
			popUp2->Render(); //팝업창 2를 렌더해라.
		}
	}

	if (popUp2->isDestroy)//팝업창2가 파괴되었다면
	{
		ui2->Render();  // 찾은 단서 2, 남은 단서 2 ui를 렌더해라
	}

	if (Stage2Obj::cnt == 3) // cnt가 3이면
	{
		if (popUp2->isDestroy)
		{
			popUp3->Render(); //팝업창 3를 렌더해라.
		}
	}

	if (popUp3->isDestroy)//팝업창3이 파괴되었다면
	{
		ui3->Render(); // 찾은 단서 3, 남은 단서 1 ui를 렌더해라
	}



	if (Stage2Obj::cnt == 4)  // cnt가 4면
	{
		if (popUp3->isDestroy)
		{
			popUp4->Render(); // 완료 팝업창을 렌더해라.
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

#include "TestScene.h"
#include "InputSystem.h"
#include "RenderSystem.h"
#include "SceneManager.h"
#include "WInApp.h"
#include "Player.h"
#include "Player2.h"
#include "PathManager.h"

void TestScene::Init()
{
	obj = new Player();
	myObject = new Player2();


}

void TestScene::FixedUpdate()
{
	obj->FixedUpdate();
	myObject->Update();
}

void TestScene::Update()
{
	/*if (InputSystem::GetInstance()->GetKey(UP))
	{
		MessageBox(WinApp::GetInstance()->GetWindow(), TEXT("wŰ�� �������ϴ�."), TEXT("GetAsyncKeyState"), MB_OK);

	}*/
	obj->Update();
	myObject->Update();

	func1();
	func2();
	//PlayerLogic();


	x2 = MouseInputSystem::GetInstance()->curMouse.x;
	y2 = MouseInputSystem::GetInstance()->curMouse.y;
}

void TestScene::Render()
{
	//PlayerRender();
	//RenderSystem::GetInstance()->DrawRect(x,y);

	RenderSystem::GetInstance()->DrawCircle(x2, y2);
	//RenderSystem::GetInstance()->DrawBitmap(PathManager::GetInstance()->hbm, 100, 100);
	//RenderSystem::GetInstance()->DrawDialog(L"�ȳ��ϼ���", 200, 200);

	obj->Render();
	myObject->Render();


}

void TestScene::Destroy()
{
	myObject->Destroy();

}





void TestScene::func1()
{
}

void TestScene::func2()
{
}



#include "GameManager.h"
#include "WInApp.h"
#include "SceneManager.h"

#include "InputSystem.h"
#include "RenderSystem.h"
#include "TimeManager.h"


void GameManager::Init()
{
	FixedTime = 0;
}

void GameManager::FixedUpdate()
{
	//SceneManager::GetInstance()->pScene->FixedUpdate();
	SceneManager::GetInstance()->pScene->FixedUpdate();
}

void GameManager::Update()
{
	//SceneManager::GetInstance()->pScene->Update();
	SceneManager::GetInstance()->pScene->Update();

}

void GameManager::Render()
{
	//SceneManager::GetInstance()->pScene->Render();
	SceneManager::GetInstance()->pScene->Render();


}

void GameManager::Destroy()
{
	SceneManager::GetInstance()->pScene->Destroy();

}

void GameManager::Run()
{
	MSG msg;

	while (true)
	{
		// 메세지 큐에 메세지가 있다면
		TimeManager::GetInstance()->UpdateTime();
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			// 메세지가 종료일떄 프로그램 종료
			if (msg.message == WM_QUIT) break;

			// 처리되지 않은 메세지 -> OS가 알아서 처리
			else
			{
				DispatchMessage(&msg);
			}
		}
		// 큐에 메세지가 없다면 로직 동작
		else
		{
			
		}

		// 마우스 위치받기
		MouseInputSystem::GetInstance()->UpdateMouse();

		// 로직
		if (TimeManager::GetInstance()->Timer(&FixedTime, 17, false))
		{
			FixedUpdate();
		}
		Update();

		// 렌더링
		RenderSystem::GetInstance()->BeginDraw();
		Render();
		RenderSystem::GetInstance()->EndDraw();

		// 키보드리셋
		InputSystem::GetInstance()->SetKeyDownFalse(1);

		SceneManager::GetInstance()->ChageScene();

		// 개발자모드
		Scene::SceneChange();
	}
}
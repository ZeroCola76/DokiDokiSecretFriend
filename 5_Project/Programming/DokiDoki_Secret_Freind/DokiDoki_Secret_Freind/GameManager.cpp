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
		// �޼��� ť�� �޼����� �ִٸ�
		TimeManager::GetInstance()->UpdateTime();
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			// �޼����� �����ϋ� ���α׷� ����
			if (msg.message == WM_QUIT) break;

			// ó������ ���� �޼��� -> OS�� �˾Ƽ� ó��
			else
			{
				DispatchMessage(&msg);
			}
		}
		// ť�� �޼����� ���ٸ� ���� ����
		else
		{
			
		}

		// ���콺 ��ġ�ޱ�
		MouseInputSystem::GetInstance()->UpdateMouse();

		// ����
		if (TimeManager::GetInstance()->Timer(&FixedTime, 17, false))
		{
			FixedUpdate();
		}
		Update();

		// ������
		RenderSystem::GetInstance()->BeginDraw();
		Render();
		RenderSystem::GetInstance()->EndDraw();

		// Ű���帮��
		InputSystem::GetInstance()->SetKeyDownFalse(1);

		SceneManager::GetInstance()->ChageScene();

		// �����ڸ��
		Scene::SceneChange();
	}
}
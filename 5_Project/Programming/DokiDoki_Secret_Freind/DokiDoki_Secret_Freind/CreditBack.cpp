#include "CreditBack.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"
#include "InputSystem.h"
#include "SceneManager.h"

void CreditBack::Init()
{
	escPos = CreateRectRgn(1756, 60, 1821, 125);
}

void CreditBack::FixedUpdate()
{
}

void CreditBack::Update()
{
	EscBtn();
}

void CreditBack::Render()
{
	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->credit.credit, 0, 0);
	EscBtn();
}

void CreditBack::Destroy()
{
}

void CreditBack::EscBtn()
{

	pt.x = MouseInputSystem::GetInstance()->curMouse.x;
	pt.y = MouseInputSystem::GetInstance()->curMouse.y;

	isOutCredit = PtInRegion(escPos, pt.x, pt.y);

	if (InputSystem::GetInstance()->GetKeyDown(SELECT))
	{
		SceneManager::GetInstance()->ChangeSceneState(S_TITLE);
	}

	//if (isOutCredit == true)
	//{
	//	if (MouseInputSystem::GetInstance()->curMouse.left)
	//	{
	//		//isClick = true;
	//		SceneManager::GetInstance()->ChangeSceneState(S_TITLE);
	//	}
	//}
}

//지금 버튼 안됨 왜 안되는지 모르겠음
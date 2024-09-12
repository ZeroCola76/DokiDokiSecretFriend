#include "Stage1Result.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"
#include "InputSystem.h"
#include "PerfectScore.h"
#include "LateScore.h"
#include "SceneManager.h"
#include <iostream>
#include <string>
#include <windows.h>

void Stage1Result::Init()
{
	boxPos = CreateRectRgn(800, 750, 1000, 800);
}

void Stage1Result::FixedUpdate()
{
}

void Stage1Result::Update()
{
	GetEndButton();
}

void Stage1Result::Render()
{
	////폰트 경로
	//const wchar_t* fontPath = L"D:\\Document\\GA5th1Q_Project\\DokiDoki Secret Freind\\5_Project\\Programming\\DokiDoki_Secret_Freind\\DokiDoki_Secret_Freind\\Font\\CookieRun Regular.ttf";
	//int result = AddFontResourceEx(fontPath, FR_PRIVATE, 0);
	//if (result == 0) {
	//	// 폰트 로드 실패
	//	// 에러 처리 등을 수행할 수 있습니다.
	//}

	////폰트 이름과 크기 설정
	//const wchar_t* fontName = L"Cookie Run";
	//int fontSize = 16;

	////폰트 생성
	//HFONT cookieFont = CreateFont(fontSize, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
	//	DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
	//	DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, fontName);

	//if (cookieFont == NULL) {
	//	// 폰트 생성 실패
	//	// 에러 처리 등을 수행할 수 있습니다.
	//}

	std::wstring lStr = std::to_wstring(lateScore);
	const TCHAR* lateString = lStr.c_str();
	std::wstring pStr = std::to_wstring(perfectScore);
	const TCHAR* perfectString = pStr.c_str();


	RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage1.result, 250, 100);
	if (isInsideBox)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage1.afterCheck, 250, 100);
	}
	RenderSystem::GetInstance()->DrawDialog(perfectString, 700, 380,100);
	RenderSystem::GetInstance()->DrawDialog(lateString, 700, 530,100);

	if (perfectScore>=60)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage1.A, 850, 130);
	}
	else if (perfectScore >= 30)
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage1.B, 1200, 300);
	}
	else
	{
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage1.C, 1200, 300);
	}

	if (isClickStage1 == true)
	{
		if (RenderSystem::GetInstance()->PaidIn(10))
		{
			SceneManager::GetInstance()->ChangeSceneState(S_DIALOG1); //여기 씬 체인지
		}
	}


}

void Stage1Result::Destroy()
{
}

void Stage1Result::GetEndButton()
{
	pt.x = MouseInputSystem::GetInstance()->curMouse.x;
	pt.y = MouseInputSystem::GetInstance()->curMouse.y;

	isInsideBox = PtInRegion(boxPos, pt.x, pt.y);

	if (isInsideBox)
	{
		if (!isClickStage1)
		{
			if (MouseInputSystem::GetInstance()->curMouse.left) // 마우스 좌클릭이 되었다면
			{
				isClickStage1 = true;
				DeleteObject(boxPos);

			}
		}
	}
}

#include "RenderSystem.h"
#include <Windows.h>
#include <cmath>
//#pragma comment(lib, "msimg32.lib")

void RenderSystem::Init()
{

	frontMemDC = GetDC(WinApp::GetInstance()->GetWindow()); //front 만듬
	backMemDC = CreateCompatibleDC(frontMemDC);

	backBitmap = CreateCompatibleBitmap(frontMemDC, WinApp::GetInstance()->GetWidth() * 2, WinApp::GetInstance()->GetHeight() * 2); // 도화지 만드는 것-뒤에서 쓸 버퍼
	AddFontResourceA("D:\\1Q_Project\\DokiDoki Secret Freind\\4_Resources\\dumi\\font\\CookieRun Regular.ttf");


	PaidInit();

}

void RenderSystem::ClearScreen()
{
	PatBlt(backMemDC, 0, 0, WinApp::GetInstance()->GetWidth() * 2, WinApp::GetInstance()->GetHeight() * 2, WHITENESS);
}

void RenderSystem::BeginDraw() // 그리기 전 준비 : 도화지 준비
{
	ClearScreen();
	SelectObject(backMemDC, backBitmap);
}

void RenderSystem::EndDraw() //다 그리고 backMemDC에 있던걸 앞으로 밀어준다???? //여기서 프론트로 밀어줌
{
	BitBlt(frontMemDC, 0, 0, WinApp::GetInstance()->GetWidth(), WinApp::GetInstance()->GetHeight(), backMemDC, WinApp::GetInstance()->GetWidth() / 2, WinApp::GetInstance()->GetHeight() / 2, SRCCOPY);
}

void RenderSystem::DrawCircle(int _x, int _y)
{
	int _radius = 100;

	HPEN hPen2 = CreatePen(PS_SOLID, 5, RGB(100, 255, 50));
	HPEN holdPen2 = (HPEN)SelectObject(backMemDC, hPen2);
	HBRUSH hBrush2 = CreateSolidBrush(RGB(225, 200, 240));
	HBRUSH holdBrush2 = (HBRUSH)SelectObject(backMemDC, hBrush2);

	Ellipse(backMemDC, _x - _radius, _y - _radius, _x + _radius, _y + _radius);

	SelectObject(backMemDC, holdPen2);
	SelectObject(backMemDC, holdBrush2);

	DeleteObject(hPen2);
	DeleteObject(hBrush2);
}

void RenderSystem::DrawRect(int _x, int _y, int _width, int _height, COLORREF _color)
{
	HBRUSH hbr = CreateSolidBrush(_color);
	HBRUSH oldHbr = (HBRUSH)SelectObject(backMemDC, hbr);
	Rectangle(backMemDC, _x, _y, _x + _width, _y + _height);
	SelectObject(backMemDC, oldHbr);

	DeleteObject(hbr);

}

void RenderSystem::DrawBitmap(HBITMAP _getBmp, int _imgX, int _imgY)
{
	bBackMemDC = CreateCompatibleDC(backMemDC); //백백MemDC에서 그려줌(hdc를 만들고)
	HBITMAP hBit = (HBITMAP)SelectObject(bBackMemDC, _getBmp); // 사진 가져옴(도구를 가져옴) == LoadBitmap

	BITMAP bm;
	GetObject(_getBmp, sizeof(BITMAP), &bm);

	//BitBlt(backMemDC, 0, 0, WinApp::GetInstance()->GetWidth(), WinApp::GetInstance()->GetHeight(), bBackMemDC, 0, 0, SRCCOPY); //백백에 있던걸 백으로 가져옴
	GdiTransparentBlt(backMemDC, _imgX + (WinApp::GetInstance()->GetWidth() / 2), _imgY + (WinApp::GetInstance()->GetHeight() / 2), bm.bmWidth, bm.bmHeight, bBackMemDC, 0, 0, bm.bmWidth, bm.bmHeight, RGB(255, 255, 254));

	DeleteDC(bBackMemDC);
}

void RenderSystem::DrawDialog(const WCHAR* text, int _x, int _y, int _fontSize)
{
	//TextOutA(backMemDC, _x, _y, text, strlen(text));

	HFONT hf, oldHf;
	LOGFONTW lf;
	lf.lfHeight = _fontSize;
	lf.lfWidth = 0;
	lf.lfEscapement = 0;
	lf.lfOrientation = 0;
	lf.lfWeight = FW_NORMAL;
	lf.lfItalic = FALSE;
	lf.lfUnderline = FALSE;
	lf.lfStrikeOut = 0;
	lf.lfCharSet = HANGEUL_CHARSET;
	lf.lfOutPrecision = OUT_DEFAULT_PRECIS;
	lf.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	lf.lfQuality = DEFAULT_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
	lstrcpyW(lf.lfFaceName, TEXT("CookieRun Regular"));

	hf = CreateFontIndirectW(&lf);
	oldHf = (HFONT)SelectObject(backMemDC, hf);

	SetBkMode(backMemDC, TRANSPARENT);

	TextOutW(backMemDC, _x + (WinApp::GetInstance()->GetWidth() / 2), _y + (WinApp::GetInstance()->GetHeight() / 2), text, 2);//wcslen(text));

	DeleteObject(hf);
	//ReleaseDC(NULL,backMemDC);
}

void RenderSystem::PrintDialog(const char* text, int _x, int _y)
{
	TextOutA(backMemDC, _x + (WinApp::GetInstance()->GetWidth() / 2), _y + (WinApp::GetInstance()->GetHeight() / 2), text, strlen(text));
}

void RenderSystem::RotateBitmap(int _x, int _y, int _angle, HBITMAP _bmp)
{

	BITMAP bm;
	GetObject(_bmp, sizeof(BITMAP), &bm);

	POINT points[3] = { 0, 0 };

	points[0] = { 0, 0 };
	points[1] = { 0 + bm.bmWidth, 0 };
	points[2] = { 0, 0 + bm.bmHeight };

	// 오브젝트 로컬 좌표로 원점이동
	POINT center = { 0 + bm.bmWidth / 2, 0 + bm.bmHeight / 2 };
	{
		for (int i = 0; i < 3; ++i)
		{
			points[i].x -= center.x;
			points[i].y -= center.y;
		}
	}
	// 회전
	{
		float cosScalr = cos(_angle * 3.141592 / 180);
		float sinScalr = sin(_angle * 3.141592 / 180);
		POINT temp;

		for (int i = 0; i < 3; ++i)
		{
			temp.x = points[i].x * cosScalr - points[i].y * sinScalr;
			temp.y = points[i].x * sinScalr + points[i].y * cosScalr;
			points[i] = temp;
		}
	}

	// 월드 좌표로 원점이동
	{
		for (int i = 0; i < 3; ++i)
		{
			points[i].x += center.x;
			points[i].y += center.y;
		}
	}



	HDC rotDC = CreateCompatibleDC(backMemDC);
	HBITMAP hbm1 = CreateCompatibleBitmap(backMemDC, WinApp::GetInstance()->GetWidth(), WinApp::GetInstance()->GetHeight());

	SelectObject(rotDC, hbm1);

	HDC srcDC = CreateCompatibleDC(rotDC);
	SelectObject(srcDC, _bmp);

	RECT rc = { 0,0,WinApp::GetInstance()->GetWidth(), WinApp::GetInstance()->GetHeight() };
	HBRUSH br = CreateSolidBrush(RGB(255, 255, 254));
	FillRect(rotDC, &rc, br);
	DeleteObject(br);

	PlgBlt(rotDC, points, srcDC, 0, 0, bm.bmWidth, bm.bmHeight, 0, 0, 0);



	GdiTransparentBlt(backMemDC, _x + (WinApp::GetInstance()->GetWidth() / 2), _y + (WinApp::GetInstance()->GetHeight() / 2), bm.bmWidth, bm.bmHeight, rotDC, 0, 0, bm.bmWidth, bm.bmHeight, RGB(255, 255, 254));

	DeleteDC(srcDC);
	DeleteObject(hbm1);
	DeleteDC(rotDC);

}

void RenderSystem::PaidInit()
{
	paidCount = 0;
	paidDC = CreateCompatibleDC(backMemDC);
	paidBMP = CreateCompatibleBitmap(backMemDC, WinApp::GetInstance()->GetWidth() * 2, WinApp::GetInstance()->GetHeight() * 2); // 도화지 만드는 것-뒤에서 쓸 버퍼
	SelectObject(paidDC, paidBMP);
	PatBlt(paidDC, 0, 0, WinApp::GetInstance()->GetWidth(), WinApp::GetInstance()->GetHeight(), BLACKNESS);

	bfn.AlphaFormat = 0;
	bfn.BlendFlags = 0;
	bfn.BlendOp = 0;
	bfn.SourceConstantAlpha = paidCount;

}

bool RenderSystem::PaidIn(int _count)
{
	bool result = false;
	if (paidCount < 255)
	{
		paidCount += _count;
		if (paidCount > 255)
		{
			paidCount = 255;
		}
		bfn.SourceConstantAlpha = paidCount;


		result = false;
	}
	else
	{
		result = true;
	}

	GdiAlphaBlend(backMemDC, 0, 0, WinApp::GetInstance()->GetWidth() * 2, WinApp::GetInstance()->GetHeight() * 2
		, paidDC, 0, 0, WinApp::GetInstance()->GetWidth() * 2, WinApp::GetInstance()->GetHeight() * 2, bfn);

	return result;


}

bool RenderSystem::paidOut(int _count)
{
	bool result = false;
	if (paidCount > 0)
	{
		paidCount -= _count;
		if (paidCount < 0)
		{
			paidCount = 0;
		}
		bfn.SourceConstantAlpha = paidCount;

		result = false;




	}
	else
	{
		result = true;
	}

	GdiAlphaBlend(backMemDC, 0, 0, WinApp::GetInstance()->GetWidth() * 2, WinApp::GetInstance()->GetHeight() * 2
		, paidDC, 0, 0, WinApp::GetInstance()->GetWidth() * 2, WinApp::GetInstance()->GetHeight() * 2, bfn);

	return result;
}
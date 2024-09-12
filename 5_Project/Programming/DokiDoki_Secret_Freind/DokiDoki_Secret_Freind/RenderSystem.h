#pragma once
#include "TSinglton.h"
#include "Winapp.h"

class RenderSystem : public TSingleton<RenderSystem>
{
public:
	HDC frontMemDC;
	HDC backMemDC;
	HBITMAP backBitmap = nullptr;
	HDC bBackMemDC;

private:
	// 페이드인 페이드아웃 전용 변수
	int paidCount;
	HDC paidDC;
	HBITMAP paidBMP;
	BLENDFUNCTION bfn;


public:
	void Init();

	//더블버퍼링
	void ClearScreen(); //화면초기화
	void BeginDraw(); //그리기 전 어디다 그릴지 설정(backMemDC에다 그릴거고 backBitmap에다 저장)
	void EndDraw(); //다 그리고 backMemDC에 있던걸 앞으로 밀어준다

	void DrawCircle(int _x, int _y);
	void DrawRect(int _x, int _y,int _width, int _height, COLORREF _color);
	void DrawBitmap(HBITMAP _getBmp, int _imgX, int _imgY);
	void DrawDialog(const WCHAR* text, int _x, int _y, int _fontSize);
	void PrintDialog(const char* text, int _x, int _y);


	void RotateBitmap(int _x,int _y, int _angle, HBITMAP _bmp);



	// 페이드인,아웃 함수 (컨벤션 어김 ㅠㅠ)
public:
	bool PaidIn(int _count);
	bool paidOut(int _count);

private:
	void PaidInit();
};


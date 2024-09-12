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
	// ���̵��� ���̵�ƿ� ���� ����
	int paidCount;
	HDC paidDC;
	HBITMAP paidBMP;
	BLENDFUNCTION bfn;


public:
	void Init();

	//������۸�
	void ClearScreen(); //ȭ���ʱ�ȭ
	void BeginDraw(); //�׸��� �� ���� �׸��� ����(backMemDC���� �׸��Ű� backBitmap���� ����)
	void EndDraw(); //�� �׸��� backMemDC�� �ִ��� ������ �о��ش�

	void DrawCircle(int _x, int _y);
	void DrawRect(int _x, int _y,int _width, int _height, COLORREF _color);
	void DrawBitmap(HBITMAP _getBmp, int _imgX, int _imgY);
	void DrawDialog(const WCHAR* text, int _x, int _y, int _fontSize);
	void PrintDialog(const char* text, int _x, int _y);


	void RotateBitmap(int _x,int _y, int _angle, HBITMAP _bmp);



	// ���̵���,�ƿ� �Լ� (������ ��� �Ф�)
public:
	bool PaidIn(int _count);
	bool paidOut(int _count);

private:
	void PaidInit();
};


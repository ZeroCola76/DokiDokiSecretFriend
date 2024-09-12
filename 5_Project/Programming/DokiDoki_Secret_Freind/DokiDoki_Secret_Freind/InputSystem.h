#pragma once
#include "TSinglton.h"

typedef enum E_KEYCODE
{
	SELECT = 1,
	UP,
	DOWN,
	LEFT,
	RIGHT
}KEYCODE;

class InputSystem : public TSingleton<InputSystem>
{
	//����
public:
	int key; //KeyCodeReturn ��ȯ ����

	int select, up, down, left, right;

	bool keyDown[256];				// keydown�� ���� ���� -> ������ ����
	bool keyUp[256];				// keyup�� ���� ���� -> ������ ��ư�� ���� ����

	//������ �Ҹ���
public:
	InputSystem() {};
	~InputSystem() {};

	//�Լ�
public:
	void Init();

	bool GetKey(KEYCODE _k);			//����Ƽ�� ����
	bool GetKeyDown(KEYCODE _k);
	bool GetKeyUp(KEYCODE _k);

	bool SetKeyDownFalse(int _k);	// keyState�� ��� false�� ����

	int KeyCodeReturn(KEYCODE _k);	// KEYCODE�� ���� �ڵ尪 ��ȯ �Լ�

};

class MouseState
{
public:
	int x, y, wheel = 0;
	bool left, right, middle = false;

public:
	MouseState() {};
	~MouseState() {};
};


class MouseInputSystem : public TSingleton<MouseInputSystem>
{
public:
	MouseState curMouse;
	MouseState prevMouse;

public:
	MouseInputSystem() {};
	~MouseInputSystem() {};

public:
	void Init();

	//void InitMouse(); //���콺 �ʱ�ȭ
	void UpdateMouse(); //���콺 ������Ʈ
	bool IsSame(const MouseState& a, const MouseState& b);

	const MouseState& GetMouseState();
	const MouseState& GetPrevMouseState();

};

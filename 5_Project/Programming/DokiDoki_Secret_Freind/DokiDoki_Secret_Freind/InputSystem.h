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
	//변수
public:
	int key; //KeyCodeReturn 반환 변수

	int select, up, down, left, right;

	bool keyDown[256];				// keydown을 위한 변수 -> 누르는 순간
	bool keyUp[256];				// keyup을 위한 변수 -> 눌렀던 버튼을 떼는 순간

	//생성자 소멸자
public:
	InputSystem() {};
	~InputSystem() {};

	//함수
public:
	void Init();

	bool GetKey(KEYCODE _k);			//유니티와 동일
	bool GetKeyDown(KEYCODE _k);
	bool GetKeyUp(KEYCODE _k);

	bool SetKeyDownFalse(int _k);	// keyState를 모두 false로 변경

	int KeyCodeReturn(KEYCODE _k);	// KEYCODE의 실제 코드값 반환 함수

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

	//void InitMouse(); //마우스 초기화
	void UpdateMouse(); //마우스 업데이트
	bool IsSame(const MouseState& a, const MouseState& b);

	const MouseState& GetMouseState();
	const MouseState& GetPrevMouseState();

};

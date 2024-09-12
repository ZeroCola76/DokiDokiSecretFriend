#include "InputSystem.h"
#include "WInApp.h"


void InputSystem::Init()
{
	select = ' ';
	up = VK_UP;
	down = VK_DOWN;
	left = VK_LEFT;
	right = VK_RIGHT;

	//false 상태로 시작하기 위해
	memset(keyDown, false, 256); //keyState 초기화 하기 위해(쓰레기값 없애기 위해)
	memset(keyUp, false, 256); //keyUp 초기화 하기 위해(쓰레기값 없애기 위해)
}

bool InputSystem::GetKey(KEYCODE _k) //누르는 동안 계속 true 반환
{
	key = KeyCodeReturn(_k);

	if (GetAsyncKeyState(key) & 0x8000)
	{
		keyDown[key] = true;
		return true;
	}

	return false;
}

bool InputSystem::GetKeyDown(KEYCODE _k) //눌렀을 때 한번만 true 반환
{
	key = KeyCodeReturn(_k);
	if ((GetAsyncKeyState(key) & 0x8000) && keyDown[key] == false) // 키 입력을 받고 
	{
		return keyDown[key] = true;
	}
	return false;
}

bool InputSystem::GetKeyUp(KEYCODE _k) //누른걸 떼었을때 한번만 true 반환
{
	key = KeyCodeReturn(_k);
	return keyUp[key] = true;

	return false;
}

bool InputSystem::SetKeyDownFalse(int _k)
{


	for (int i = 0; i < 256; i++)
	{
		keyUp[i] = false;
		if (GetAsyncKeyState(i) == 0)
		{
			if (keyDown[i] == true)
			{
				keyDown[i] = false;
				keyUp[i] = true;
			}
		}
	}

	return true;
}


int InputSystem::KeyCodeReturn(KEYCODE _k)
{
	switch (_k)
	{
	case SELECT:
		return select;

	case UP:
		return up;

	case DOWN:
		return down;

	case LEFT:
		return left;

	case RIGHT:
		return right;

	default:
		break;
	}
	return -1;
}

void MouseInputSystem::Init()
{
	curMouse.x = WinApp::GetInstance()->GetWidth() / 2;
	curMouse.y = WinApp::GetInstance()->GetHeight() / 2;
	curMouse.wheel = 0;

	curMouse.left = false;
	curMouse.right = false;
	curMouse.middle = false;

	prevMouse = curMouse;

	SetCursorPos(curMouse.x, curMouse.y);
}

//void MouseInputSystem::InitMouse() //마우스 초기화
//{
//	curMouse.x = WinApp::GetInstance()->GetWidth() / 2;
//	curMouse.y = WinApp::GetInstance()->GetHeight() / 2;
//	curMouse.wheel = 0;
//
//	curMouse.left = false;
//	curMouse.right = false;
//	curMouse.middle = false;
//
//	prevMouse = curMouse;
//
//	SetCursorPos(curMouse.x, curMouse.y);
//
//}

void MouseInputSystem::UpdateMouse()
{
	prevMouse = curMouse;

	POINT pt; // POINT : x,y 멤버를 가지고 있는 구조체
	GetCursorPos(&pt); //pt 주소에 가지고 있는 x,y 값을 가져옴
	ScreenToClient(WinApp::GetInstance()->GetWindow(), &pt); //전체 화면 기준인 커서의 좌표를 해당 클라이언트(윈도우) 기준으로 좌표를 변환해주는 함수

	curMouse.x = pt.x;
	curMouse.y = pt.y;
	curMouse.wheel = 0;

	curMouse.left = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != false;
	curMouse.right = (GetAsyncKeyState(VK_RBUTTON) & 0x8000) != false;
	curMouse.middle = (GetAsyncKeyState(VK_MBUTTON) & 0x8000) != false;
}

const MouseState& MouseInputSystem::GetMouseState()
{
	// TODO: 여기에 return 문을 삽입합니다.
	return curMouse;
}

const MouseState& MouseInputSystem::GetPrevMouseState()
{
	// TODO: 여기에 return 문을 삽입합니다.
	return prevMouse;
}

bool MouseInputSystem::IsSame(const MouseState& a, const MouseState& b)
{
	return a.x == b.x && a.y == b.y && a.wheel == b.wheel && a.left == b.left && a.right == b.right && a.middle == b.middle;
}
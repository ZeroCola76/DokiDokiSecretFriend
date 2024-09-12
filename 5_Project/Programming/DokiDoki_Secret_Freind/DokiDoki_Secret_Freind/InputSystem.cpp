#include "InputSystem.h"
#include "WInApp.h"


void InputSystem::Init()
{
	select = ' ';
	up = VK_UP;
	down = VK_DOWN;
	left = VK_LEFT;
	right = VK_RIGHT;

	//false ���·� �����ϱ� ����
	memset(keyDown, false, 256); //keyState �ʱ�ȭ �ϱ� ����(�����Ⱚ ���ֱ� ����)
	memset(keyUp, false, 256); //keyUp �ʱ�ȭ �ϱ� ����(�����Ⱚ ���ֱ� ����)
}

bool InputSystem::GetKey(KEYCODE _k) //������ ���� ��� true ��ȯ
{
	key = KeyCodeReturn(_k);

	if (GetAsyncKeyState(key) & 0x8000)
	{
		keyDown[key] = true;
		return true;
	}

	return false;
}

bool InputSystem::GetKeyDown(KEYCODE _k) //������ �� �ѹ��� true ��ȯ
{
	key = KeyCodeReturn(_k);
	if ((GetAsyncKeyState(key) & 0x8000) && keyDown[key] == false) // Ű �Է��� �ް� 
	{
		return keyDown[key] = true;
	}
	return false;
}

bool InputSystem::GetKeyUp(KEYCODE _k) //������ �������� �ѹ��� true ��ȯ
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

//void MouseInputSystem::InitMouse() //���콺 �ʱ�ȭ
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

	POINT pt; // POINT : x,y ����� ������ �ִ� ����ü
	GetCursorPos(&pt); //pt �ּҿ� ������ �ִ� x,y ���� ������
	ScreenToClient(WinApp::GetInstance()->GetWindow(), &pt); //��ü ȭ�� ������ Ŀ���� ��ǥ�� �ش� Ŭ���̾�Ʈ(������) �������� ��ǥ�� ��ȯ���ִ� �Լ�

	curMouse.x = pt.x;
	curMouse.y = pt.y;
	curMouse.wheel = 0;

	curMouse.left = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != false;
	curMouse.right = (GetAsyncKeyState(VK_RBUTTON) & 0x8000) != false;
	curMouse.middle = (GetAsyncKeyState(VK_MBUTTON) & 0x8000) != false;
}

const MouseState& MouseInputSystem::GetMouseState()
{
	// TODO: ���⿡ return ���� �����մϴ�.
	return curMouse;
}

const MouseState& MouseInputSystem::GetPrevMouseState()
{
	// TODO: ���⿡ return ���� �����մϴ�.
	return prevMouse;
}

bool MouseInputSystem::IsSame(const MouseState& a, const MouseState& b)
{
	return a.x == b.x && a.y == b.y && a.wheel == b.wheel && a.left == b.left && a.right == b.right && a.middle == b.middle;
}
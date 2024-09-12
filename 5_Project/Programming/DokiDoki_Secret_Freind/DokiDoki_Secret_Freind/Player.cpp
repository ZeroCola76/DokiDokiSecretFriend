#include "Player.h"
#include "RenderSystem.h"
#include "InputSystem.h"

void Player::Init()
{
}

void Player::FixedUpdate()
{
	PlayerFixedLogic();
}

void Player::Update()
{
	PlayerLogic();
}

void Player::Render()
{
	PlayerRender(x, y);
}

void Player::Destroy()
{
}

void Player::PlayerLogic()
{
	if (InputSystem::GetInstance()->GetKey(DOWN))
	{
		y++;
	}

	if (InputSystem::GetInstance()->GetKey(RIGHT))
	{
		x++;
	}


	if (InputSystem::GetInstance()->GetKeyDown(LEFT))
	{
		x -= 10;
	}
}

void Player::PlayerFixedLogic()
{
	if (InputSystem::GetInstance()->GetKey(UP))
	{
		y--;
	}
}

void Player::PlayerRender(int _x,int _y)
{
	//HPEN hPen = CreatePen(PS_SOLID, 10, RGB(0, 0, 255));
	//HPEN hOldPen = (HPEN)SelectObject(RenderSystem::GetInstance()->backMemDC, hPen);
	//HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));
	//HBRUSH hOldBrush = (HBRUSH)SelectObject(RenderSystem::GetInstance()->backMemDC, hBrush);

	//Rectangle(RenderSystem::GetInstance()->backMemDC, _x, _y, _x + 50, _y + 50);

	//SelectObject(RenderSystem::GetInstance()->backMemDC, hOldPen);
	//SelectObject(RenderSystem::GetInstance()->backMemDC, hOldBrush);

	//DeleteObject(hPen);
	//DeleteObject(hBrush);
}

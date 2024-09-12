#include "Player2.h"
#include "RenderSystem.h"

void Player2::Init()
{
}

void Player2::FixedUpdate()
{
	myFunc1();
}

void Player2::Update()
{
	myFunc2();
}

void Player2::Render()
{
	RenderSystem::GetInstance()->DrawRect(100, 100, 20, 20, RGB(255, 0, 0));
}

void Player2::Destroy()
{
}

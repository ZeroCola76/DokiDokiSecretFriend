#include "Arrow.h"
#include "RenderSystem.h"
#include "ResourcesManager.h"
#include "TimeManager.h"
#include "InputSystem.h"
#include "PerfectScore.h"
#include "LateScore.h"
#include <cstdlib>
#include <time.h>

void Arrow::Init()
{
	RandomSet();
}

void Arrow::FixedUpdate()
{
	MoveArrow();
}

void Arrow::Update()
{
	JudgeNote();
}

void Arrow::Render()
{
	DrawArrow(arrowX);
}

void Arrow::Destroy()
{

}

void Arrow::MoveArrow()
{
	arrowX -= 16.5f;
}



void Arrow::DrawArrow(int _x)
{
	switch (arrowShape)
	{
	case 1:
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage1.downArrow, _x + 1800, 325);
		break;
	case 2:
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage1.UpArrow, _x + 1800, 325);
		break;
	case 3:
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage1.leftArrow, _x + 1800, 325);
		break;
	case 4:
		RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage1.rightArrow, _x + 1800, 325);
		break;
	default:
		break;
	}
}

void Arrow::RandomSet()
{
	if (!isSet)
	{
		arrowShape = rand() % 4 + 1;
		isSet = true;
	}
}

void Arrow::JudgeNote()
{
	//판정 가보자고
	JudegeTimer(2500);

	if (rhythmTimeArrow >= 1800 && rhythmTimeArrow <= 1950)
	{
		if (InputSystem::GetInstance()->GetKeyDown(DOWN) && arrowShape == 1)
		{
			JudgeLogic();
		}

		if (InputSystem::GetInstance()->GetKeyDown(UP) && arrowShape == 2)
		{
			JudgeLogic();
		}

		if (InputSystem::GetInstance()->GetKeyDown(LEFT) && arrowShape == 4)
		{
			JudgeLogic();
		}

		if (InputSystem::GetInstance()->GetKeyDown(RIGHT) && arrowShape == 3)
		{
			JudgeLogic();
		}
	}
}

void Arrow::JudegeTimer(ULONGLONG maxTime)
{
	if (rhythmTimeArrow < maxTime)
	{
		rhythmTimeArrow += TimeManager::GetInstance()->GetDeltaTime();
	}
	else
	{
		rhythmTimeArrow = 0;
		LateScore::countLScore();
		isDone = true;


	}
}

void Arrow::JudgeLogic()
{
	PerfectScore::countPScore();
	isDone = true;
}

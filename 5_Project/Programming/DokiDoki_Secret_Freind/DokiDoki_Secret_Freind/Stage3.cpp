#include "Stage3.h"
#include "InputSystem.h"

#include "RabbitPuzzle.h"
#include "AirplanePuzzle.h"
#include "TreePuzzle.h"
#include "St3Bk.h"


#include "ResourcesManager.h"
#include "SceneManager.h"
#include "RenderSystem.h"
#include "SoundManager.h"

#include <float.h>
#include <cmath>
#include <string>

void Stage3::Init()
{
	BackGround = new St3Bk(ResourcesManager::GetInstance()->stage3.backGround,0,0);

	isAngle = false;

	quizs[0] = new St3Bk(ResourcesManager::GetInstance()->stage3.quiz1,500,0);
	quizs[1] = new St3Bk(ResourcesManager::GetInstance()->stage3.quiz2,500,0);
	quizs[2] = new St3Bk(ResourcesManager::GetInstance()->stage3.quiz3,500,0);

	answer[0] = ResourcesManager::GetInstance()->stage3.quizRabbit;
	answer[1] = ResourcesManager::GetInstance()->stage3.quizAirplane;
	answer[2] = ResourcesManager::GetInstance()->stage3.quizTree;



	InitQuiz1();

	startUI = ResourcesManager::GetInstance()->stage3.startUI;
	nextUI = ResourcesManager::GetInstance()->stage3.nextUI;
	puzzleDone = false;
	isStart = false;

	quizStage = 1;
	isPaid = false;
	isPaidIn = false;

	SoundManager::GetInstance()->SoundInit();
	SoundManager::GetInstance()->MusicPlay(SoundManager::GetInstance()->SEVENPUZZLE);
}

void Stage3::FixedUpdate()
{
	if (isStart == true)
	{
		for (int i = 0; i < 7; i++)
		{
			puzzle[i]->FixedUpdate();
		}
	}
}

void Stage3::Update()
{
	if (isStart == true)
	{
		if (GetAsyncKeyState('P') & 0x8000)
		{
			puzzleDone = true;
		}
		if (QuizIsDone() == true && puzzleDone == false)
		{
			puzzleDone = true;
		}


		if (puzzleDone == false)
		{
			for (int i = 0; i < 7; i++)
			{
				puzzle[i]->Update();
			}
			Stage3Logic();
		}
		else
		{
			if(InputSystem::GetInstance()->GetKeyDown(SELECT))
			{
				quizStage++;
				puzzleDone = false;
				selectedPuzzle = nullptr;
				switch (quizStage)
				{
				case 1:
					InitQuiz1();
					break;
				case 2:
					EndQuiz1();
					InitQuiz2();
					break;
				case 3:
					EndQuiz2();
					InitQuiz3();
					break;
				default:
					isPaidIn = true;
					break;
				}
			}
		}
	}
	else
	{
		if (MouseInputSystem::GetInstance()->curMouse.x > 930 && MouseInputSystem::GetInstance()->curMouse.x < 1070 && MouseInputSystem::GetInstance()->curMouse.y > 640 && MouseInputSystem::GetInstance()->curMouse.y < 730 && isPaid == true)
		{
			if (MouseInputSystem::GetInstance()->curMouse.left)
			{
				isStart = true;
			}
		}
	}
	
}

void Stage3::Render()
{
	BackGround->Render();

	if (isStart == true)
	{
		if (puzzleDone == false)
		{
			if (quiz != nullptr)
			{
				quiz->Render();
			}

			for (int i = 0; i < 7; i++)
			{
				if (puzzle[i]->isDone == true)
				{
					puzzle[i]->Render();

				}
			}
			for (int i = 0; i < 7; i++)
			{
				if (puzzle[i]->isDone == false)
				{
					puzzle[i]->Render();

				}
			}

			if (selectedPuzzle != nullptr)
			{
				selectedPuzzle->Render();
			}
		}
		else
		{
			RenderSystem::GetInstance()->DrawBitmap(nextUI, 100, 900);
			RenderSystem::GetInstance()->DrawBitmap(answer[quizStage - 1], 500, 0);
			if (isPaidIn == true)
			{
				if (RenderSystem::GetInstance()->PaidIn(30))
				{
					SceneManager::GetInstance()->ChangeSceneState(S_END);
				}
			}
		}
		
	}

	else
	{
		if (MouseInputSystem::GetInstance()->curMouse.x > 930 && MouseInputSystem::GetInstance()->curMouse.x < 1070 && MouseInputSystem::GetInstance()->curMouse.y > 640 && MouseInputSystem::GetInstance()->curMouse.y < 730 && isPaid == true)
		{
			RenderSystem::GetInstance()->DrawBitmap(ResourcesManager::GetInstance()->stage3.startUI_a, 700, 350);

		}
		else
		{
			RenderSystem::GetInstance()->DrawBitmap(startUI, 700, 350);
		}

		if (RenderSystem::GetInstance()->paidOut(30))
		{
			isPaid = true;
		}

	}

}

void Stage3::Destroy()
{
	EndQuiz3();
	SoundManager::GetInstance()->ReleaseSound();
}

void Stage3::Stage3Logic()
{
	if (selectedPuzzle != nullptr)
	{

		if (MouseInputSystem::GetInstance()->curMouse.right == true) // 우클릭중일때
		{

			if (isAngle == false)
			{
				isAngle = true;

			}
			if (mousePos.x > MouseInputSystem::GetInstance()->curMouse.x) // 마우스 우로이동
			{
				selectedPuzzle->angle = mousePos.x - MouseInputSystem::GetInstance()->curMouse.x;

			}
			else // 마우스 좌로이동
			{
				selectedPuzzle->angle = mousePos.x - MouseInputSystem::GetInstance()->curMouse.x;
			}



		}
		else // 우클릭중이 아닐때
		{
			if (isAngle == true)
			{
				isAngle = false;

			}

			selectedPuzzle->SetPos(MouseInputSystem::GetInstance()->curMouse.x, MouseInputSystem::GetInstance()->curMouse.y);
		}


		if (MouseInputSystem::GetInstance()->curMouse.middle)
		{
			selectedPuzzle = nullptr;
		}
	}
	else
	{
		if (MouseInputSystem::GetInstance()->curMouse.left)
		{
			SelectPuzzle();
		}

	}
}

bool Stage3::SelectPuzzle()
{
	mousePos.x = MouseInputSystem::GetInstance()->curMouse.x;
	mousePos.y = MouseInputSystem::GetInstance()->curMouse.y;

	RECT rc;
	POINT center;
	double Distance = DBL_MAX;
	double curDistance;
	double preDistance;

	//ScreenToClient(WinApp::GetInstance()->GetWindow(),&mousePos);

	for (int i = 0; i < 7; i++)
	{
		if (puzzle[i]->isDone == true)
		{
			continue;
		}

		rc = puzzle[i]->GetCollider();
		center = puzzle[i]->GetObjectCenter();

		if (rc.left < mousePos.x && rc.right > mousePos.x && rc.top < mousePos.y && rc.bottom > mousePos.y) // 마우스가 칠교조각 충돌박스 안에 있을때
		{
			if (Distance > GetDistance(mousePos, center))
			{
				selectedPuzzle = puzzle[i];
				Distance = GetDistance(mousePos, center);
			}
		}

	}
	return selectedPuzzle != nullptr;
}

double Stage3::GetDistance(POINT a, POINT b)
{
	double x, y;
	double c;
	x = abs(a.x - b.x);
	y = abs(a.y - b.y);
	c = pow(x, 2) + pow(y, 2);
	return sqrt(c);
}

bool Stage3::QuizIsDone()
{
	if (selectedPuzzle != nullptr)
	{
		return false;
	}

	for (int i = 0; i < 7; i++)
	{
		if (puzzle[i]->isDone == false)
		{
			return false;
		}
	}
	return true;
}

void Stage3::InitQuiz1()
{


	quiz1Puzzle[0] = new RabbitPuzzle(rand() % 100, rand()%100, rand() % 360, ResourcesManager::GetInstance()->stage3.rabbit1, 0);
	quiz1Puzzle[1] = new RabbitPuzzle(rand() % 100, rand()%100,rand() % 360, ResourcesManager::GetInstance()->stage3.rabbit2, 1);
	quiz1Puzzle[2] = new RabbitPuzzle(rand() % 100, rand()%100,rand() % 360, ResourcesManager::GetInstance()->stage3.rabbit3, 2);
	quiz1Puzzle[3] = new RabbitPuzzle(rand() % 100, rand()%100,rand() % 360, ResourcesManager::GetInstance()->stage3.rabbit4, 3);
	quiz1Puzzle[4] = new RabbitPuzzle(rand() % 100, rand()%100,rand() % 360, ResourcesManager::GetInstance()->stage3.rabbit5, 4);
	quiz1Puzzle[5] = new RabbitPuzzle(rand() % 100, rand()%100,rand() % 360, ResourcesManager::GetInstance()->stage3.rabbit6, 5);
	quiz1Puzzle[6] = new RabbitPuzzle(rand() % 100, rand()%100,rand() % 360, ResourcesManager::GetInstance()->stage3.rabbit7, 6);

	puzzle = &quiz1Puzzle[0];
	quiz = quizs[0];

}

void Stage3::InitQuiz2()
{
	quiz2Puzzle[0] = new AirplanePuzzle(rand() % 100, rand() % 100, rand() % 360, ResourcesManager::GetInstance()->stage3.airplane1, 0);
	quiz2Puzzle[1] = new AirplanePuzzle(rand() % 100, rand() % 100, rand() % 360, ResourcesManager::GetInstance()->stage3.airplane2, 1);
	quiz2Puzzle[2] = new AirplanePuzzle(rand() % 100, rand() % 100, rand() % 360, ResourcesManager::GetInstance()->stage3.airplane3, 2);
	quiz2Puzzle[3] = new AirplanePuzzle(rand() % 100, rand() % 100, rand() % 360, ResourcesManager::GetInstance()->stage3.airplane4, 3);
	quiz2Puzzle[4] = new AirplanePuzzle(rand() % 100, rand() % 100, rand() % 360, ResourcesManager::GetInstance()->stage3.airplane5, 4);
	quiz2Puzzle[5] = new AirplanePuzzle(rand() % 100, rand() % 100, rand() % 360, ResourcesManager::GetInstance()->stage3.airplane6, 5);
	quiz2Puzzle[6] = new AirplanePuzzle(rand() % 100, rand() % 100,rand() % 360, ResourcesManager::GetInstance()->stage3.airplane7, 6);

	puzzle = &quiz2Puzzle[0];
	quiz = quizs[1];
}

void Stage3::InitQuiz3()
{
	quiz3Puzzle[0] = new TreePuzzle(rand() % 100, rand()%100,rand() % 360, ResourcesManager::GetInstance()->stage3.tree1, 0);
	quiz3Puzzle[1] = new TreePuzzle(rand() % 100, rand()%100,rand() % 360, ResourcesManager::GetInstance()->stage3.tree2, 1);
	quiz3Puzzle[2] = new TreePuzzle(rand() % 100, rand()%100,rand() % 360, ResourcesManager::GetInstance()->stage3.tree3, 2);
	quiz3Puzzle[3] = new TreePuzzle(rand() % 100, rand()%100,rand() % 360, ResourcesManager::GetInstance()->stage3.tree4, 3);
	quiz3Puzzle[4] = new TreePuzzle(rand() % 100, rand()%100,rand() % 360, ResourcesManager::GetInstance()->stage3.tree5, 4);
	quiz3Puzzle[5] = new TreePuzzle(rand() % 100, rand()%100,rand() % 360, ResourcesManager::GetInstance()->stage3.tree6, 5);
	quiz3Puzzle[6] = new TreePuzzle(rand() % 100, rand()%100,rand() % 360, ResourcesManager::GetInstance()->stage3.tree7, 6);

	puzzle = &quiz3Puzzle[0];
	quiz = quizs[2];
}

void Stage3::EndQuiz1()
{
	for (int i = 0; i < 7; i++)
	{
		SAFE_DELETE(quiz1Puzzle[i]);
	}
}

void Stage3::EndQuiz2()
{
	for (int i = 0; i < 7; i++)
	{
		SAFE_DELETE(quiz2Puzzle[i]);
	}
}

void Stage3::EndQuiz3()
{
	for (int i = 0; i < 7; i++)
	{
		SAFE_DELETE(quiz3Puzzle[i]);
	}
}



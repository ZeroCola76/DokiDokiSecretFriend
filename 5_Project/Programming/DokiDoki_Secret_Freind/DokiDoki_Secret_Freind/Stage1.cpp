#define _CRT_SECURE_NO_WARNINGS

#include "Stage1.h"
#include "Arrow.h"
#include "Background.h"
#include "RBG.h"
#include "JudgeRhythm.h"
#include "RenderSystem.h"
#include "SoundManager.h"
#include "TimeManager.h"
#include "ParcingObj.h"
#include "StartBG.h"
#include "Stage1Result.h"
#include "InputSystem.h"
#include "PathManager.h"
#include <stdio.h>
#include <math.h>

void Stage1::Init()
{
	bg = new Background();
	judge = new JudgeRhythm();
	startBg = new StartBG();
	parcingObj = new ParcingObj();
	result = new Stage1Result();
	parcingObj->Init();
	startBg->Init();
	result->Init();
	SoundManager::GetInstance()->SoundInit();

	GetNoteMap();
	for (int i = 0; i < 95; i++)
	{
		arrow[i] = nullptr;
		//arrow[i]->Init();
	}

}

void Stage1::FixedUpdate()
{
	if (startBg->inGame)
	{
		for (int i = 0; i < 95; i++)
		{
			if (arrow[i] != nullptr)
			{
				arrow[i]->FixedUpdate(); //2.������ ���� �̵�
				if (arrow[i]->isDone == true)
				{
					SAFE_DELETE(arrow[i]);
				}
			}
		}
	}


}	

void Stage1::Update()
{


	if (startBg->inGame)
	{
		RhythmTimer(80000);
		//�뷡 ��ũ ����
		if (rhythmTime >= 2000 && !isMusic)
		{
			isMusic = true;
			SoundManager::GetInstance()->MusicPlay(SoundManager::GetInstance()->BGM);
		}



		///?????
		if (rhythmTime >= hObject[rNumberCount].rTime)
		{
			arrow[rNumberCount] = new Arrow(); //1,����

			if (rNumberCount < 95)
			{
			rNumberCount++;
			}
		}



		for (int i = 0; i < 100; i++)
		{
			if (arrow[i] != nullptr)
			{
				arrow[i]->Update(); //2.������ ���� �̵�

			}
		}

		if (rhythmTime >= 60000)
		{
			startBg->inGame = false;
			startBg->isEnd = true;
		}
	}
	else
	{
		if (startBg->isEnd)
		{
			result->Update();
			//SoundManager::GetInstance()->MusicStop();
		}
		else
		{
			startBg->Update();
		}

	}
}

void Stage1::Render()
{
	bg->Render(); //�޹���� �׷�����? ����ü ���� ������

	//���ӽ��۵Ǹ�
	if (startBg->inGame)
	{

		//rbg->Render();
		judge->Render(); //������

		for (int i = 0; i < 95; i++)
		{
			if (arrow[i] != nullptr)
			{
				arrow[i]->Render(); //ȭ��ǥ
			}

		}
	}
	else
	{
		if (startBg->isEnd)
		{
			result->Render(); //�����â
		}
		else
		{
			startBg->Render(); //����
		}
	}

}

void Stage1::Destroy()
{
	SoundManager::GetInstance()->ReleaseSound();
	isMusic = false;
	result->lateScore = 0;
	result->perfectScore = 0;
	SAFE_DELETE(bg);
	SAFE_DELETE(judge);
	SAFE_DELETE(startBg);
	SAFE_DELETE(parcingObj);
	SAFE_DELETE(result);
}

void Stage1::GetNoteMap()
{
	PathManager pm;
	pm.Init();

	FILE* file = nullptr;
	const char* fileName = "PowerTrain.osu";
	char note[100];

	int num_hitobjects = 0;
	file = fopen("PowerTrain.osu", "r"); //������ �о�ɴϴ�

	if (file == NULL)
	{
		//����ó��

	}

	//���鼭 ���� ���� ���Ϳ�
	while (fgets(note, sizeof(note), file) != NULL)
	{
		if (sscanf(note, "%d,%d,%d,%d,%d,%*d:%*d:%*d:%*d:\n",
			&hObject[num_hitobjects].x,
			&hObject[num_hitobjects].y,
			&hObject[num_hitobjects].rTime,
			&hObject[num_hitobjects].type,
			&hObject[num_hitobjects].hit_sound) != 5)
		{
			break;
		}
		num_hitobjects++;
	}

	//�ݾ��ݴϴ�
	fclose(file);
}

void Stage1::RhythmTimer(ULONGLONG maxTime)
{
	int time = 0;
	if (time < maxTime)
	{
		//��ŸŸ���� 1�� �ƴ϶� 10~���� 16�̰ų� �� Ŭ������
		///���� ������ ���� �������� ���� ������ ��ǻ�͸� �˼��ִ�
		rhythmTime += TimeManager::GetInstance()->GetDeltaTime();
	}
}
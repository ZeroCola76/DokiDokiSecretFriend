#pragma once
#include "Scene.h"
#include "Stage3Obj.h"

class Stage3 : public Scene
{
public:
	Stage3Obj* BackGround;

	Stage3Obj* quiz1Puzzle[7];
	Stage3Obj* quiz2Puzzle[7];
	Stage3Obj* quiz3Puzzle[7];

	Stage3Obj** puzzle;
	Stage3Obj* quiz;
	Stage3Obj* quizs[3];

	Stage3Obj* selectedPuzzle;

	int quizStage;

public:

	HBITMAP startUI;
	HBITMAP nextUI;
	HBITMAP answer[3];
	
	bool puzzleDone = false;
	bool isStart = false;

public:
	bool isAngle;
	POINT mousePos;

public:
	bool isPaid;
	bool isPaidIn;

public:
	Stage3() {};
	~Stage3() {};


public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();

private:
	void Stage3Logic();

	bool SelectPuzzle();
	double GetDistance(POINT a, POINT b);
	bool QuizIsDone();


	void InitQuiz1();
	void InitQuiz2();
	void InitQuiz3();

	void EndQuiz1();
	void EndQuiz2();
	void EndQuiz3();

};
#pragma once
#include "TSinglton.h"
#include <Windows.h>

class GameManager : public TSingleton<GameManager>
{
	// 변수
public:
	ULONGLONG FixedTime;
	//SceneManager sceneMgr;

public:
	// 생성자 소멸자
	GameManager() {};
	~GameManager() {};

	// 함수
public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();


	void Run();


};


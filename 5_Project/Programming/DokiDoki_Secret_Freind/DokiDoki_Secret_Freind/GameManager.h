#pragma once
#include "TSinglton.h"
#include <Windows.h>

class GameManager : public TSingleton<GameManager>
{
	// ����
public:
	ULONGLONG FixedTime;
	//SceneManager sceneMgr;

public:
	// ������ �Ҹ���
	GameManager() {};
	~GameManager() {};

	// �Լ�
public:
	void Init();
	void FixedUpdate();
	void Update();
	void Render();
	void Destroy();


	void Run();


};


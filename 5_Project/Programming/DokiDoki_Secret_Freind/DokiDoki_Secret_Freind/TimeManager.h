#pragma once
#include "TSinglton.h"
#include <Windows.h>

class TimeManager : public TSingleton<TimeManager>
{
public:
	//ULONGLONG - 64��Ʈ ��ȣ ���� ���� (unsigned long long integer) �ſ� ū ���� �� ���� ����
	ULONGLONG previousTime; // ���� ������ �ð�
	ULONGLONG currentTime; // ����
	ULONGLONG deltaTime; //�����Ӱ� �������� �ð�����

	TimeManager();
	~TimeManager() {};

	void Init() {};
	void TimeInit();
	void UpdateTime();
	ULONGLONG GetDeltaTime();
	//SorMS�� true �϶� second ��, false�϶� MillieSecond�� ��ȯ��Ų��.
	bool Timer(ULONGLONG* _time, ULONGLONG _timeLength, bool _sorMS); 

};


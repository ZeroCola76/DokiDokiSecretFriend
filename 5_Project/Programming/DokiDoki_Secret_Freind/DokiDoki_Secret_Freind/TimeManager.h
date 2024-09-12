#pragma once
#include "TSinglton.h"
#include <Windows.h>

class TimeManager : public TSingleton<TimeManager>
{
public:
	//ULONGLONG - 64비트 부호 없는 정수 (unsigned long long integer) 매우 큰 정수 값 저장 가능
	ULONGLONG previousTime; // 이전 프레임 시간
	ULONGLONG currentTime; // 현재
	ULONGLONG deltaTime; //프레임과 프레임의 시간간격

	TimeManager();
	~TimeManager() {};

	void Init() {};
	void TimeInit();
	void UpdateTime();
	ULONGLONG GetDeltaTime();
	//SorMS은 true 일때 second 를, false일때 MillieSecond를 반환시킨다.
	bool Timer(ULONGLONG* _time, ULONGLONG _timeLength, bool _sorMS); 

};


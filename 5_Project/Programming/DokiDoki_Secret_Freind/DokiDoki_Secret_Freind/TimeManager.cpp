#include "TimeManager.h"

TimeManager::TimeManager()
{
	TimeInit();
}

void TimeManager::TimeInit()
{
	//GetTickCount64() - 시스템 시작 이후 경과한 밀리초 단위 시간 반환
	previousTime = currentTime = GetTickCount64();
}

void TimeManager::UpdateTime()
{
	previousTime = currentTime;
	currentTime = GetTickCount64();

	deltaTime = currentTime - previousTime;
}

ULONGLONG TimeManager::GetDeltaTime()
{
	return deltaTime;
}

// 
bool TimeManager::Timer(ULONGLONG* _time, ULONGLONG _timeLength, bool _sorMS)
{
	*_time += deltaTime;
	if (_sorMS)
	{
		if ((*_time / 1000) >= _timeLength)
		{
			*_time -= (1000 * _timeLength);
			return true;
		}
	}
	else
	{
		if (*_time >= _timeLength)
		{
			*_time -= _timeLength;
			if (*_time > _timeLength * 2)
			{
				*_time = 0;
			}
			return true;
		}
	}
	return false;
}



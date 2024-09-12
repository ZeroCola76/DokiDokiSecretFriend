#pragma once
#include "Macro.h"

template <typename T>
class TSingleton
{
private:
	static T* _Instance;

protected:
	TSingleton() {};
	~TSingleton() {};

	virtual void Init() = 0;

public:
	static T* GetInstance()
	{
		if (_Instance == nullptr)
		{
			_Instance = new T();
			_Instance->Init();
		}
		return _Instance;
	}

	static void DestroyInstance()
	{
		// GameManager 객체가 있을떄
		if (_Instance != nullptr)
		{
			// GameManager 객체 메모리 반환
			SAFE_DELETE(_Instance);
		}
	}
};

template<typename T> T* TSingleton<T>::_Instance = nullptr;
#pragma once

#include <SDKDDKVer.h>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "TSinglton.h"

	class WinApp
	{
	public:

		WinApp() = default;
		~WinApp() = default;

		void Initialize(HINSTANCE hInstance);

		void Run();

		void Finalize();

		HINSTANCE GetHINSTANCE() const { return m_hInstance; }

		HWND GetWindow() const { return m_hWnd; }

		const int GetWidth() const { return width; }
		const int GetHeight() const { return height; }

		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		static WinApp* GetInstance()
		{
			if (_instance == nullptr)
				_instance = new WinApp();

			return _instance;
		}

	private:

		static WinApp* _instance;

		HINSTANCE m_hInstance = { 0 };  // HINSTANCE is a handle to an instance of a module.
		HWND m_hWnd = { 0 };			// HWND is a handle to a window.

		int width = 1920;
		int height = 1080;
	};


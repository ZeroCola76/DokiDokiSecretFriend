#pragma once
#include <Windows.h>


typedef enum E_PATH
{
	P_TITLE = 0,
	P_CREDIT,
	P_INTRO,
	P_STAGE1,
	P_DIALOG1,
	P_DIALOG2,
	P_STAGE2,
	P_DIALOG3,
	P_STAGE3,
	P_END,

	P_DIALOG,
	P_TEXT,
};

class PathManager
{
public:
	// 현재 디렉토리
	WCHAR originPath[MAX_PATH];
	PWCHAR pPath;

	// 각 미션 스테이지별 리소스 이미지 디렉토리
	WCHAR titlePath[MAX_PATH];
	WCHAR creditPath[MAX_PATH];

	WCHAR introPath[MAX_PATH];
	WCHAR stage1Path[MAX_PATH];
	WCHAR dialog1Path[MAX_PATH];

	WCHAR dialog2Path[MAX_PATH];
	WCHAR stage2Path[MAX_PATH];

	WCHAR dialog3Path[MAX_PATH];
	WCHAR stage3Path[MAX_PATH];

	WCHAR endPath[MAX_PATH];
	WCHAR dialogPath[MAX_PATH];

	WCHAR soundPath[MAX_PATH];

	WCHAR textPath[MAX_PATH];

public:
	PathManager() {};
	~PathManager() {};

public:
	void Init();

	char* GetResourcePath(int _scene);
	const char* GetSoundPath(const char* _path);


};
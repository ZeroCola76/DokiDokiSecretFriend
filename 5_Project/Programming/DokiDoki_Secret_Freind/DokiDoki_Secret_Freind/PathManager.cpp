#include "PathManager.h"
#include <string>

void PathManager::Init()
{
	GetCurrentDirectoryW(MAX_PATH, originPath);
	pPath = wcsstr(originPath, L"\\DokiDoki Secret Freind");
	while (*pPath != L'\0')
	{
		*pPath = '\0';
		pPath++;
	}

	for (int i = 0; originPath[i] != '\0'; i++)
	{
		soundPath[i] = textPath[i] = titlePath[i] = creditPath[i] = introPath[i] = stage1Path[i] = dialog1Path[i]
			= dialog2Path[i] = stage2Path[i] = dialog3Path[i] = stage3Path[i]
			= endPath[i] = dialogPath[i] = originPath[i];
	}

	wcscat_s(titlePath, MAX_PATH, L"\\DokiDoki Secret Freind\\4_Resources\\title\\");

	wcscat_s(creditPath, MAX_PATH, L"\\DokiDoki Secret Freind\\4_Resources\\credit\\");

	wcscat_s(introPath, MAX_PATH, L"\\DokiDoki Secret Freind\\4_Resources\\Intro\\");

	wcscat_s(stage1Path, MAX_PATH, L"\\DokiDoki Secret Freind\\4_Resources\\stage1\\");

	wcscat_s(dialog1Path, MAX_PATH, L"\\DokiDoki Secret Freind\\4_Resources\\Dialog1\\");
	
	wcscat_s(dialog2Path, MAX_PATH, L"\\DokiDoki Secret Freind\\4_Resources\\Dialog2\\");

	wcscat_s(stage2Path, MAX_PATH, L"\\DokiDoki Secret Freind\\4_Resources\\stage2\\");

	wcscat_s(dialog3Path, MAX_PATH, L"\\DokiDoki Secret Freind\\4_Resources\\Dialog3\\");

	wcscat_s(stage3Path, MAX_PATH, L"\\DokiDoki Secret Freind\\4_Resources\\stage3\\");

	wcscat_s(endPath, MAX_PATH, L"\\DokiDoki Secret Freind\\4_Resources\\End\\");

	wcscat_s(dialogPath, MAX_PATH, L"\\DokiDoki Secret Freind\\4_Resources\\conversation\\");

	wcscat_s(textPath, MAX_PATH, L"\\DokiDoki Secret Freind\\4_Resources\\Dialog\\");

	wcscat_s(soundPath, MAX_PATH, L"\\DokiDoki Secret Freind\\3_Media\\music\\");

}

char* PathManager::GetResourcePath(int _scene)
{
	char dest[MAX_PATH] = { 0 };
	size_t sz;


	switch (_scene)
	{
	case P_TITLE:
		wcstombs_s(&sz, dest, MAX_PATH, titlePath, MAX_PATH);
		break;

	case P_CREDIT:
		wcstombs_s(&sz, dest, MAX_PATH, creditPath, MAX_PATH);
		break;

	case P_INTRO:
		wcstombs_s(&sz, dest, MAX_PATH, introPath, MAX_PATH);
		break;

	case P_STAGE1:
		wcstombs_s(&sz, dest, MAX_PATH, stage1Path, MAX_PATH);
		break;

	case P_DIALOG1:
		wcstombs_s(&sz, dest, MAX_PATH, dialog1Path, MAX_PATH);
		break;

	case P_DIALOG2:
		wcstombs_s(&sz, dest, MAX_PATH, dialog2Path, MAX_PATH);
		break;

	case P_STAGE2:
		wcstombs_s(&sz, dest, MAX_PATH, stage2Path, MAX_PATH);
		break;

	case P_DIALOG3:
		wcstombs_s(&sz, dest, MAX_PATH, dialog3Path, MAX_PATH);
		break;

	case P_STAGE3:
		wcstombs_s(&sz, dest, MAX_PATH, stage3Path, MAX_PATH);
		break;

	case P_END:
		wcstombs_s(&sz, dest, MAX_PATH, endPath, MAX_PATH);
		break;

	case P_DIALOG:
		wcstombs_s(&sz, dest, MAX_PATH, dialogPath, MAX_PATH);
		break;

	case P_TEXT:
		wcstombs_s(&sz, dest, MAX_PATH, textPath, MAX_PATH);

	default:
		break;
	}

	return dest;
}

const char* PathManager::GetSoundPath(const char* _path)
{
	char dest[MAX_PATH] = { 0 };
	memset(dest,'\0',MAX_PATH);
	size_t sz;

	wcstombs_s(&sz, dest, MAX_PATH, soundPath, MAX_PATH);
	strcat_s(dest,MAX_PATH,_path);

	return dest;
}

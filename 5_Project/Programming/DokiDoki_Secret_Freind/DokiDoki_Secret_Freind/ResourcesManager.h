#pragma once
#include "TSinglton.h"
#include "PathManager.h"
#include "Resources.h"





class ResourcesManager : public TSingleton<ResourcesManager>
{
public:
	TitleSrc title;
	CreditSrc credit;

	IntroSrc intro;

	DialogSrc dialog;
	Dialog1Src dialog1;
	Dialog2Src dialog2;
	Dialog3Src dialog3;

	EndSrc end;

	Stage1Src stage1;
	Stage2Src stage2;
	Stage3Src stage3;

	DialogText text;
	PathManager pathMgr;

public:
	ResourcesManager() {};
	~ResourcesManager() {};
public:
	void Init();

	//깔끔함을 위해 코딩컨벤션을 좀 어길게요 ㅠㅠ.
private:
	HBITMAP LoadHBITMAP(int _scene, const char* _path);
	void LoadAllResources();
	void LoadTitleResources();
	void LoadCreditResources();

	void LoadStage1Resources();
	void LoadStage2Resources();
	void LoadStage3Resources();

	void LoadDialogResources();
	void LoadDialog1Resources();
	void LoadDialog2Resources();
	void LoadDialog3Resources();

	void LoadIntroResources();
	void LoadEndResources();

	WCHAR* LoadTextResources(const char* _path);

};

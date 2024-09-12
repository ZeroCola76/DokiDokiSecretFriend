#include "SceneManager.h"
#include "TestScene.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "IntroScene.h"
#include "Title.h"
#include "CreditScene.h"
#include "IntroScene.h"
#include "Dialog1.h"
#include "Dialog2.h"
#include "Dialog3.h"
#include "End.h"
#include "EndingIMG.h"


SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Init()
{
	pScene = new Title();
	pScene->Init();
}

void SceneManager::ChageScene()
{
	if (SceneState != nextSceneState)
	{
		pScene->Destroy();
		SAFE_DELETE(pScene);

		switch (nextSceneState)
		{
		case S_TITLE:
			pScene = new Title();
			break;
		case S_CREDIT:
			pScene = new CreditScene();
			break;
		case S_INTRO:
			pScene = new IntroScene();
			break;
		case S_STAGE1:
			pScene = new Stage1();
			break;
		case S_DIALOG1:
			pScene = new Dialog1();
			break;
		case S_DIALOG2:
			pScene = new Dialog2();
			break;
		case S_STAGE2:
			pScene = new Stage2();
			break;
		case S_DIALOG3:
			pScene = new Dialog3();
			break;
		case S_STAGE3:
			pScene = new Stage3();
			break;
		case S_END:
			pScene = new End();
			break;
		case S_ENDIGIMG:
			pScene = new EndingIMG();
			break;
		default:
			break;
		}

		pScene->Init();
		SceneState = nextSceneState;
	}
}

void SceneManager::ChangeSceneState(E_SCENE _sceneNumber)
{
	nextSceneState = _sceneNumber;
}

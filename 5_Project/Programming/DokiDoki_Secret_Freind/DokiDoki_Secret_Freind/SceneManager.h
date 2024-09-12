#pragma once
#include "Scene.h"
#include "TSinglton.h"

typedef enum E_SCENE
{
	S_EMPTY,
	S_TITLE,
	S_CREDIT,
	S_INTRO,
	S_STAGE1,
	S_DIALOG1,
	S_STAGE2,
	S_DIALOG2,
	S_STAGE3,
	S_DIALOG3,
	S_END,
	S_ENDIGIMG
};

class SceneManager : public TSingleton<SceneManager>
{
public:
	Scene* pScene = nullptr;
	E_SCENE SceneState = S_EMPTY;
	E_SCENE nextSceneState = S_TITLE;
public:
	SceneManager();
	~SceneManager();

	void Init();
	void ChageScene();
	void ChangeSceneState(E_SCENE _sceneNumber);

};


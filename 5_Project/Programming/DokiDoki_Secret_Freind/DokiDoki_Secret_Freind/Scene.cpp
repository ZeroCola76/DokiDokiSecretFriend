#include "Scene.h"
#include "SceneManager.h"

#include <Windows.h>


void Scene::SceneChange()
{
	if (GetAsyncKeyState('1') & 0x8000) SceneManager::GetInstance()->ChangeSceneState(E_SCENE::S_TITLE);
	if (GetAsyncKeyState('2') & 0x8000) SceneManager::GetInstance()->ChangeSceneState(S_INTRO);
	if (GetAsyncKeyState('3') & 0x8000) SceneManager::GetInstance()->ChangeSceneState(S_STAGE1);
	if (GetAsyncKeyState('4') & 0x8000) SceneManager::GetInstance()->ChangeSceneState(S_DIALOG1);
	if (GetAsyncKeyState('5') & 0x8000) SceneManager::GetInstance()->ChangeSceneState(S_DIALOG2);
	if (GetAsyncKeyState('6') & 0x8000) SceneManager::GetInstance()->ChangeSceneState(S_STAGE2);
	if (GetAsyncKeyState('7') & 0x8000) SceneManager::GetInstance()->ChangeSceneState(S_DIALOG3);
	if (GetAsyncKeyState('8') & 0x8000) SceneManager::GetInstance()->ChangeSceneState(S_STAGE3);
	if (GetAsyncKeyState('9') & 0x8000) SceneManager::GetInstance()->ChangeSceneState(S_END);
	if (GetAsyncKeyState('0') & 0x8000) SceneManager::GetInstance()->ChangeSceneState(S_ENDIGIMG);
}

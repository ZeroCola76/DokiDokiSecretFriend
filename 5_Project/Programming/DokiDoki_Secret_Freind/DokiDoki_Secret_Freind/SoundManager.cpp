#include "SoundManager.h"
#include <windows.h>
#include "PathManager.h"

// ���� �ʱ�ȭ
void SoundManager::SoundInit() {
	PathManager pm;
	pm.Init();

	// FMOD �ý��� ��ü �ʱ�ȭ
	result = FMOD_System_Create(&fsystem, FMOD_VERSION);
	result = FMOD_System_Init(fsystem, 32, FMOD_INIT_NORMAL, NULL);

	// ���� ����

	result = FMOD_System_CreateSound(fsystem, pm.GetSoundPath("TItle.wav"), FMOD_DEFAULT, 0, &sound[TITLE]); //Ÿ��Ʋ
	result = FMOD_System_CreateSound(fsystem, pm.GetSoundPath("Daydream.wav"), FMOD_DEFAULT, 0, &sound[CREDIT]); //ũ����
	result = FMOD_System_CreateSound(fsystem, pm.GetSoundPath("Diary.wav"), FMOD_DEFAULT, 0, &sound[Intro]); //ũ����
	result = FMOD_System_CreateSound(fsystem, pm.GetSoundPath("PowerTrain.wav"), FMOD_DEFAULT, 0, &sound[BGM]);
	result = FMOD_System_CreateSound(fsystem, pm.GetSoundPath("Pastel.wav"), FMOD_DEFAULT, 0, &sound[DIALOG2]); //2��° ��ȭ
	result = FMOD_System_CreateSound(fsystem, pm.GetSoundPath("Runonsnow.wav"), FMOD_DEFAULT, 0, &sound[SEVENPUZZLE]); //ĥ��
	result = FMOD_System_CreateSound(fsystem, pm.GetSoundPath("Letter.wav"), FMOD_DEFAULT, 0, &sound[END]); //end��
	result = FMOD_System_CreateSound(fsystem, pm.GetSoundPath("Colorful.wav"), FMOD_DEFAULT, 0, &sound[ENDING]); //end��

	//����Ʈ ����
	result = FMOD_System_CreateSound(fsystem, pm.GetSoundPath("TinyButtonPush.wav"), FMOD_DEFAULT, 0, &sound[BUTTON]);

}

// ����Ʈ (�ܹ߼�)
void SoundManager::EffectPlay(Music index) {
	FMOD_System_PlaySound(fsystem, sound[index], NULL, 0, &channelEffect);
	FMOD_Channel_SetMode(channelEffect, FMOD_LOOP_OFF);
}

// BGM (�ݺ�)
void SoundManager::MusicPlay(Music index) {
	FMOD_System_PlaySound(fsystem, sound[index], NULL, 0, &channelMusic);
	FMOD_Channel_SetMode(channelMusic, FMOD_LOOP_NORMAL);
}

// ����
void SoundManager::ReleaseSound() {
	for (int i = 0; i < 32; i++) {
		FMOD_Sound_Release(sound[i]);
	}
	FMOD_System_Close(fsystem);
	FMOD_System_Release(fsystem);
}

// ����Ʈ ����
void SoundManager::EffectStop() {
	FMOD_Channel_Stop(channelEffect);
}

// BGM ����
void SoundManager::MusicStop() {
	FMOD_Channel_Stop(channelMusic);
}

// �� ����ð��� ���غ��ô�
unsigned SoundManager::GetAudioPlayBackTime()
{
	_position = 0;
	result = FMOD_Channel_GetPosition(channelMusic, &_position, FMOD_TIMEUNIT_MS);
	return 0;
}

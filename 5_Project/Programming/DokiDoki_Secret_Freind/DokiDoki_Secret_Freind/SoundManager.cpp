#include "SoundManager.h"
#include <windows.h>
#include "PathManager.h"

// »ç¿îµå ÃÊ±âÈ­
void SoundManager::SoundInit() {
	PathManager pm;
	pm.Init();

	// FMOD ½Ã½ºÅÛ °´Ã¼ ÃÊ±âÈ­
	result = FMOD_System_Create(&fsystem, FMOD_VERSION);
	result = FMOD_System_Init(fsystem, 32, FMOD_INIT_NORMAL, NULL);

	// »ç¿îµå ¸ÅÇÎ

	result = FMOD_System_CreateSound(fsystem, pm.GetSoundPath("TItle.wav"), FMOD_DEFAULT, 0, &sound[TITLE]); //Å¸ÀÌÆ²
	result = FMOD_System_CreateSound(fsystem, pm.GetSoundPath("Daydream.wav"), FMOD_DEFAULT, 0, &sound[CREDIT]); //Å©·¹µ÷
	result = FMOD_System_CreateSound(fsystem, pm.GetSoundPath("Diary.wav"), FMOD_DEFAULT, 0, &sound[Intro]); //Å©·¹µ÷
	result = FMOD_System_CreateSound(fsystem, pm.GetSoundPath("PowerTrain.wav"), FMOD_DEFAULT, 0, &sound[BGM]);
	result = FMOD_System_CreateSound(fsystem, pm.GetSoundPath("Pastel.wav"), FMOD_DEFAULT, 0, &sound[DIALOG2]); //2¹øÂ° ´ëÈ­
	result = FMOD_System_CreateSound(fsystem, pm.GetSoundPath("Runonsnow.wav"), FMOD_DEFAULT, 0, &sound[SEVENPUZZLE]); //Ä¥±³
	result = FMOD_System_CreateSound(fsystem, pm.GetSoundPath("Letter.wav"), FMOD_DEFAULT, 0, &sound[END]); //end¾À
	result = FMOD_System_CreateSound(fsystem, pm.GetSoundPath("Colorful.wav"), FMOD_DEFAULT, 0, &sound[ENDING]); //end¾À

	//ÀÌÆåÆ® ¸ÅÇÎ
	result = FMOD_System_CreateSound(fsystem, pm.GetSoundPath("TinyButtonPush.wav"), FMOD_DEFAULT, 0, &sound[BUTTON]);

}

// ÀÌÆåÆ® (´Ü¹ß¼º)
void SoundManager::EffectPlay(Music index) {
	FMOD_System_PlaySound(fsystem, sound[index], NULL, 0, &channelEffect);
	FMOD_Channel_SetMode(channelEffect, FMOD_LOOP_OFF);
}

// BGM (¹Ýº¹)
void SoundManager::MusicPlay(Music index) {
	FMOD_System_PlaySound(fsystem, sound[index], NULL, 0, &channelMusic);
	FMOD_Channel_SetMode(channelMusic, FMOD_LOOP_NORMAL);
}

// ÇØÁ¦
void SoundManager::ReleaseSound() {
	for (int i = 0; i < 32; i++) {
		FMOD_Sound_Release(sound[i]);
	}
	FMOD_System_Close(fsystem);
	FMOD_System_Release(fsystem);
}

// ÀÌÆåÆ® ¸ØÃã
void SoundManager::EffectStop() {
	FMOD_Channel_Stop(channelEffect);
}

// BGM ¸ØÃã
void SoundManager::MusicStop() {
	FMOD_Channel_Stop(channelMusic);
}

// °î Àç»ý½Ã°£À» ±¸ÇØº¾½Ã´Ù
unsigned SoundManager::GetAudioPlayBackTime()
{
	_position = 0;
	result = FMOD_Channel_GetPosition(channelMusic, &_position, FMOD_TIMEUNIT_MS);
	return 0;
}

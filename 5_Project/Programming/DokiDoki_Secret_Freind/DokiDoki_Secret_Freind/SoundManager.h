#pragma once
#include "TSinglton.h"
#include "WInApp.h"
#include <fmod.h>

class SoundManager : public TSingleton<SoundManager>
{
public:
	// 사운드 시스템
	FMOD_SYSTEM* fsystem;
	FMOD_SOUND* sound[32];
	FMOD_RESULT result;
	FMOD_CHANNEL* channelMusic;
	FMOD_CHANNEL* channelEffect;

	enum Music {
		BGM = 0,
		TITLE,
		CREDIT,
		Intro,
		DIALOG2,
		SEVENPUZZLE,
		END,
		ENDING,
		BUTTON,//여기서부턴 이;펙트
	};

	unsigned int _position;

	SoundManager() {};
	~SoundManager() {};

	void Init() {};
	void SoundInit();
	void EffectPlay(Music index);
	void MusicPlay(Music index);
	void ReleaseSound();
	void EffectStop();
	void MusicStop();
	unsigned GetAudioPlayBackTime();
};

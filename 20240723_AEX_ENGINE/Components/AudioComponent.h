#pragma once
#include "BaseComponent.h"
#include <string>
#include "AEAudio.h"

class AudioComp : public BaseComponent
{
	AEAudioGroup mGroup;
	AEAudio mAudio;
	float volume = 0.5f;
	float pitch = 1;
	int isplay = 1;

public:
	AudioComp();
	AudioComp(GameObject* own);
	~AudioComp();
	void Update() override;


	static std::string GetType()//리소스 매니저한테 써야하기 때문에
	{
		return "AudioComp";
	}


	void SetAudio(std::string s);
	void Play(); // 재생 메서드 추가

	// bool IsPlaying() const; // 재생 상태 확인 메서드 추가
};

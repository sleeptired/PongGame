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


	static std::string GetType()//���ҽ� �Ŵ������� ����ϱ� ������
	{
		return "AudioComp";
	}


	void SetAudio(std::string s);
	void Play(); // ��� �޼��� �߰�

	// bool IsPlaying() const; // ��� ���� Ȯ�� �޼��� �߰�
};

#pragma once
#include "BaseLevel.h"
#include "../Components/GameObject.h"
#include "AETypes.h"

//����� �����
#include "AEAudio.h"
namespace Levels
{
	class MainMenu_Level :public GSM::BaseLevel
	{
		void Init() override;
		void Update() override;
		void	Exit() override;
		s8 pFont;

		//����� ����(�ڵ�)
		/*
		AEAudioGroup mGroup;
		AEAudio mAudio;
		float volume = 0.5f;
		float pitch = 1;
		int play = 0;
		*/

	public:
		
		//GameObject* StartButton;

	};


}
#pragma once
#include "BaseLevel.h"
#include "../Components/GameObject.h"
namespace Levels
{
	class MainLevel :public GSM::BaseLevel
	{
		void Init() override;
		void Update() override;
		void Exit() override;
	public: 
		//���⿡ ������Ʈ �߰�
		int counter;
		GameObject* player;
		GameObject* planet;
	};
}
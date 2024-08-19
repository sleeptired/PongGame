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
		//여기에 오브젝트 추가
		int counter;
		GameObject* player;
		GameObject* planet;
	};
}
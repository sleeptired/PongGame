#pragma once

#include "BaseLevel.h"
#include "../Components/GameObject.h"
#include "AETypes.h"

namespace Levels
{
	class GoalLevel :public GSM::BaseLevel
	{
		void Init() override;
		void Update() override;
		void Exit() override;
		s8 pFont;
	public:

	};
}
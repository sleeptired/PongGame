#pragma once
#include "BaseLevel.h"
#include "../Components/GameObject.h"
#include "AETypes.h"

namespace Levels
{
	class MainLevel :public GSM::BaseLevel
	{
		void Init() override;
		void Update() override;
		void	Exit() override;
		s8 P_Font;
		static int P1score;
		static int P2score;
		std::string P1str_score = "";
		std::string P2str_score = "";
	public: 
		//여기에 오브젝트 추가
		int counter;
		//GameObject* player;
		//GameObject* planet;

		static int P1Win;
		static int P2Win;

		//퐁 게임 오브젝트
		GameObject* P_player1;
		GameObject* P_player2;
		GameObject* CenterLine;
		GameObject* P_ball;

		GameObject* UpWall;
		GameObject* DownWall;

	};

	
}
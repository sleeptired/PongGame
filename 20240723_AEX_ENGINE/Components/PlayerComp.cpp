	#include "PlayerComp.h"
	#include "AEEngine.h"
	#include "AEInput.h"
	#include "TransformComp.h"
	#include "RigidbodyComp.h"
	#include "../Components/GameObject.h"
    #include <cstdlib> 
    #include <ctime>  

	//Player Move 키보드 입력 부분

	float PlayerComp::ballSpeedX = 280.0f;
	float PlayerComp::ballSpeedY = 100.0f;

	PlayerComp::PlayerComp(GameObject* owner) {
		moveSpeed = 280;
		spin = 1;
		// 랜덤 시드 초기화
		srand(static_cast<unsigned int>(time(0)));

		// ballSpeedX는 -280 또는 280으로 랜덤 설정
		ballSpeedX = (rand() % 2 == 0) ? -280.0f : 280.0f;

		// ballSpeedY는 100에서 150 사이의 랜덤값 설정
		float randomValue = 100.0f + static_cast<float>(rand() % 51); // 0에서 50 사이의 랜덤값 추가

		// ballSpeedY의 부호를 랜덤으로 설정
		ballSpeedY = (rand() % 2 == 0) ? randomValue : -randomValue;
	}

	PlayerComp::~PlayerComp()
	{

	}

	void PlayerComp::Update()
	{

		//if (BaseComponent::Update() == false)
		//	return;
		//Check for input

		TransformComp* t = own->GetComponent<TransformComp>();
		if (!t)
			return;
		RigidbodyComp* r = own->GetComponent<RigidbodyComp>();
		if (!t)
			return;

	
		float moveY = 0;//player 속도용

		if (t)
		{
			////키보드 입력부분(Pong Game)
			if (PlayerID == "P_player1" && AEInputCheckCurr(AEVK_W))
			{
				//t->SetPos({ t->GetPos().x, t->GetPos().y + moveSpeed });
				//Move my transform
				//r->AddVelocity(0, moveSpeed);
				moveY = moveSpeed;
			}

			if (PlayerID == "P_player1" && AEInputCheckCurr(AEVK_S))
			{
				//t->SetPos({ t->GetPos().x, t->GetPos().y - moveSpeed });
				//Move my transform

				//r->AddVelocity(0, -moveSpeed);
				moveY = -moveSpeed;
			}

			//player2 키보드
			if (PlayerID == "P_player2" && AEInputCheckCurr(VK_UP))
			{
				moveY = moveSpeed;
			}
			if (PlayerID == "P_player2" && AEInputCheckCurr(VK_DOWN))
			{
				moveY = -moveSpeed;
			}

			//마우스
			if (PlayerID=="P_player2")
			{
			
				AEInputGetCursorPosition(&mouse_x, &mouse_y); //왼쪽 위가 0,0
				AEVec2 newPos = t->GetPos(); // 현재 위치 가져오기
				newPos.y = -1 * mouse_y + 440; // Y 값 변경
				std::cout << newPos.y << std::endl;
				if (newPos.y > 354)
				{
					newPos.y = 354;
				}
				else if (newPos.y < -354) 
				{
					newPos.y = -354;
				}
				t->SetPos(newPos); // 새로운 위치 설정
				//std::cout << P_player2_position.x << std::endl;//중앙이 0,0
				//P_player2_position.y = y;
				//std::cout << mouse_y << std::endl;
			}

			/*
			if (AEInputCheckCurr(AEVK_A))
			{
				//t->SetPos({ t->GetPos().x - moveSpeed, t->GetPos().y });
				//Move my transform

				//r->AddVelocity(-moveSpeed, 0);
			}
		
			if (AEInputCheckCurr(AEVK_D))
			{
				//t->SetPos({ t->GetPos().x + moveSpeed, t->GetPos().y });
				//Move my transform

				//r->AddVelocity(moveSpeed, 0);
			}
			if (AEInputCheckCurr(AEVK_SPACE))
			{
				//t->SetPos({ t->GetPos().x + 1, t->GetPos().y });
				//Move my transform

				//r->AddVelocity(moveSpeed, 0);
			}
			if (AEInputCheckCurr(AEVK_Q))
			{
				//t->SetPos({ t->GetPos().x- moveSpeed, t->GetPos().y + moveSpeed });
					//Move my transform
			}
			if (AEInputCheckCurr(AEVK_E))
			{
				//t->SetPos({ t->GetPos().x + moveSpeed, t->GetPos().y + moveSpeed });
				//Move my transform
			}
			*/

			AEVec2 WallLine_position = t->GetPos();
			// 위치 범위 체크
			if (WallLine_position.y > 355)
			{
				moveY = 0;
				if (PlayerID == "P_player1" && AEInputCheckCurr(AEVK_S))
				{
					moveY = -moveSpeed;
				}
				if (PlayerID == "P_player2" && AEInputCheckCurr(VK_DOWN))
				{
					moveY = -moveSpeed;
				}
			}
			else if (WallLine_position.y < -355)
			{
				moveY = 0;
				if (PlayerID == "P_player1" && AEInputCheckCurr(AEVK_W))
				{
					moveY = moveSpeed;
				}
				if (PlayerID == "P_player2" && AEInputCheckCurr(VK_UP))
				{
					moveY = moveSpeed;
				}
			}

			r->AddVelocity(0, moveY);

			//	
			if (PlayerID == "Ball") 
			{
				r->AddVelocity(ballSpeedX, ballSpeedY);
			}
		}

	}

	void PlayerComp::SetID(std::string insert_PlayerID)
	{
		PlayerID = insert_PlayerID;
	}

	bool PlayerComp::CheckCollisionWithPaddle()
	{
		return false;
	}

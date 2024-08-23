	#include "PlayerComp.h"
	#include "AEEngine.h"
	#include "AEInput.h"
	#include "TransformComp.h"
	#include "RigidbodyComp.h"
	#include "../Components/GameObject.h"
    #include <cstdlib> 
    #include <ctime>  

	//Player Move Ű���� �Է� �κ�

	float PlayerComp::ballSpeedX = 280.0f;
	float PlayerComp::ballSpeedY = 100.0f;

	PlayerComp::PlayerComp(GameObject* owner) {
		moveSpeed = 280;
		spin = 1;
		// ���� �õ� �ʱ�ȭ
		srand(static_cast<unsigned int>(time(0)));

		// ballSpeedX�� -280 �Ǵ� 280���� ���� ����
		ballSpeedX = (rand() % 2 == 0) ? -280.0f : 280.0f;

		// ballSpeedY�� 100���� 150 ������ ������ ����
		float randomValue = 100.0f + static_cast<float>(rand() % 51); // 0���� 50 ������ ������ �߰�

		// ballSpeedY�� ��ȣ�� �������� ����
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

	
		float moveY = 0;//player �ӵ���

		if (t)
		{
			////Ű���� �Էºκ�(Pong Game)
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

			//player2 Ű����
			if (PlayerID == "P_player2" && AEInputCheckCurr(VK_UP))
			{
				moveY = moveSpeed;
			}
			if (PlayerID == "P_player2" && AEInputCheckCurr(VK_DOWN))
			{
				moveY = -moveSpeed;
			}

			//���콺
			if (PlayerID=="P_player2")
			{
			
				AEInputGetCursorPosition(&mouse_x, &mouse_y); //���� ���� 0,0
				AEVec2 newPos = t->GetPos(); // ���� ��ġ ��������
				newPos.y = -1 * mouse_y + 440; // Y �� ����
				std::cout << newPos.y << std::endl;
				if (newPos.y > 354)
				{
					newPos.y = 354;
				}
				else if (newPos.y < -354) 
				{
					newPos.y = -354;
				}
				t->SetPos(newPos); // ���ο� ��ġ ����
				//std::cout << P_player2_position.x << std::endl;//�߾��� 0,0
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
			// ��ġ ���� üũ
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

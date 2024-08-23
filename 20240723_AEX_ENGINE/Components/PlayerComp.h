#pragma once
#include "../Components/LogicComponent.h"
#include "AETypes.h"
class PlayerComp : public LogicComponent
{
	float moveSpeed;
	float spin;
	std::string PlayerID;
	s32 mouse_x = 0, mouse_y = 0;
public:
	static float ballSpeedX;
	static float ballSpeedY;
	PlayerComp() :PlayerID(NULL) {}
	PlayerComp(GameObject* owner);
	~PlayerComp();
	void Update() override;
	void SetID(std::string insert_PlayerID);
	bool CheckCollisionWithPaddle();

	static std::string GetType()
	{
		return "PlayerComp";
	}
};
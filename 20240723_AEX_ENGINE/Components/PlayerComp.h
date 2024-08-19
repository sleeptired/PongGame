#pragma once
#include "../Components/LogicComponent.h"

class PlayerComp : public LogicComponent
{
	float moveSpeed;
	float spin;
public:
	PlayerComp(GameObject* owner);
	~PlayerComp();
	void Update() override;
	static std::string GetType()
	{
		return "PlayerComp";
	}
};
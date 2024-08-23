#pragma once
#include "../Components/EngineComponent.h"
#include "AEVec2.h"
class RigidbodyComp : public EngineComponent
{
	// EPSILON이라는 상수 값이 기본값으로 설정되어 있으며, 이 값은 일반적으로 아주 작은 양수로, 
	// 부동 소수점 비교에서 허용 오차를 나타냅니다.
	float drag = 0.5f;
	AEVec2 Velocity;
	AEVec2 MaxVelocity;
	bool CheckEpsilon(float v, float Ep = EPSILON);
	//이 함수는 부동 소수점 수치의 정확성을 평가하는 데 유용합니다. 
    // 수치 계산에서 발생할 수 있는 오차를 고려하여, 특정 값이 '0' 또는 다른 기준값에 가까운지를 판단하는 데 사용됩니다.

public:
	RigidbodyComp();
	RigidbodyComp(GameObject* owner);
	
	//void Addvelocity(const AEVec2& otherVec);
	void AddVelocity(float x , float y);

	void ClearVelocity();
	
	
	void Update() override;
	static std::string GetType()
	{
		return "RigidbodyComp";
	}

};
#pragma once
#include "../Components/EngineComponent.h"
#include "AEVec2.h"
class RigidbodyComp : public EngineComponent
{
	// EPSILON�̶�� ��� ���� �⺻������ �����Ǿ� ������, �� ���� �Ϲ������� ���� ���� �����, 
	// �ε� �Ҽ��� �񱳿��� ��� ������ ��Ÿ���ϴ�.
	float drag = 0.5f;
	AEVec2 Velocity;
	AEVec2 MaxVelocity;
	bool CheckEpsilon(float v, float Ep = EPSILON);
	//�� �Լ��� �ε� �Ҽ��� ��ġ�� ��Ȯ���� ���ϴ� �� �����մϴ�. 
    // ��ġ ��꿡�� �߻��� �� �ִ� ������ ����Ͽ�, Ư�� ���� '0' �Ǵ� �ٸ� ���ذ��� ��������� �Ǵ��ϴ� �� ���˴ϴ�.

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
#include "RigidbodyComp.h"
#include "../Components/GameObject.h"
#include "TransformComp.h"
#include "AEEngine.h"
#include "AEFrameRateController.h"
bool RigidbodyComp::CheckEpsilon(float v, float Ep)
{
	if (v< -Ep || v > Ep)
		return true;
	return false;

}
RigidbodyComp::RigidbodyComp()
{
	Velocity.x = 0;
	Velocity.y = 0;
	MaxVelocity.x = 100;
	MaxVelocity.y = 100;
}

RigidbodyComp::RigidbodyComp(GameObject* owner): Velocity()
{
	Velocity.x = 0;
	Velocity.y = 0;
	MaxVelocity.x = 100;
	MaxVelocity.y = 100;
}

void RigidbodyComp::AddVelocity(float x, float y)
{
	//Velocity.x += x; �⺻�ڵ�
	//Velocity.y += y;
	Velocity.x = x;
	Velocity.y = y;

	//�ӵ����� �ɱ�
	//if (Velocity.x >= 560) 
	//{
	//	Velocity.x = 560;
	//}

	AEClamp(Velocity.x, -MaxVelocity.x, MaxVelocity.x);

	//f32 AEClamp(f32 x, f32 x0, f32 x1)
	//x�� x0�� x1 ���̷� �����մϴ�.
	//x�� �ּҰ�(x0)���� ������ x0�� ��ȯ�ϰ�, x�� �ִ밪(x1)���� ������ x1�� ��ȯ�Ѵ�. �׷��� ������ x�� ��ȯ�Ѵ�.
	//[in]	x	The input value.
	//[in]	x0	The minimum value.
	//[in]	x1	The maximum value.

	AEClamp(Velocity.y, -MaxVelocity.y, MaxVelocity.y);


}

void RigidbodyComp::ClearVelocity()
{
	Velocity.x = 0;
	Velocity.y = 0;
}
//���⵵ Ʈ���� ������Ʈ���� ��ġ���� �޾ƿ´�.
void RigidbodyComp::Update()
{
	//�̰͵� �м�
	
	TransformComp* t = own->GetComponent<TransformComp>();
	if (!t)
		return;
	float x = t->GetPos().x + static_cast<float>(Velocity.x * AEFrameRateControllerGetFrameTime());
	//AEFrameRateControllerGetFrameTime() -> ���� �������� �ð��� �� ������ ���մϴ�.
	float y = t->GetPos().y + static_cast<float>(Velocity.y * AEFrameRateControllerGetFrameTime());

	//Velocity.x /= drag;

	//Velocity.y /= drag;

	if (CheckEpsilon(Velocity.x) == false)
		Velocity.x = 0;

	if (CheckEpsilon(Velocity.y) == false)
		Velocity.y = 0;

	t->SetPos({ x,y });
	// if y > 200
	//   y = 200;
}

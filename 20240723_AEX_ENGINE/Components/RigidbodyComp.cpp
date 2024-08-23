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
	//Velocity.x += x; 기본코드
	//Velocity.y += y;
	Velocity.x = x;
	Velocity.y = y;

	//속도제한 걸기
	//if (Velocity.x >= 560) 
	//{
	//	Velocity.x = 560;
	//}

	AEClamp(Velocity.x, -MaxVelocity.x, MaxVelocity.x);

	//f32 AEClamp(f32 x, f32 x0, f32 x1)
	//x를 x0와 x1 사이로 고정합니다.
	//x가 최소값(x0)보다 낮으면 x0을 반환하고, x가 최대값(x1)보다 높으면 x1을 반환한다. 그렇지 않으면 x를 반환한다.
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
//여기도 트랜스 컴포넌트에서 위치값을 받아온다.
void RigidbodyComp::Update()
{
	//이것도 분석
	
	TransformComp* t = own->GetComponent<TransformComp>();
	if (!t)
		return;
	float x = t->GetPos().x + static_cast<float>(Velocity.x * AEFrameRateControllerGetFrameTime());
	//AEFrameRateControllerGetFrameTime() -> 이전 프레임의 시간을 초 단위로 구합니다.
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

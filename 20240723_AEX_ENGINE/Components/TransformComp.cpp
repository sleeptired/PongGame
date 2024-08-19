#include "TransformComp.h"
#include <iostream>

void TransformComp::CalculateMatrix() {
	//Create a transform matrix
	AEMtx33 translateMtx;
	// AEMtx33
	//"행렬은 열 우선 형식(column major format)으로 저장되며, 즉 변환 항(translation term)은 가장 오른쪽 열에 위치합니다.

	AEMtx33Trans(&translateMtx, pos.x, pos.y);//void AEMtx33Trans(AEMtx33 * pResult,f32 	x,f32 	y)
	//pResult를 x와 y의 변환 행렬로 설정합니다.
	//[out] Pointer to AEMtx33 을 설정합니다.
	//[in] x 축을 따라 변환합니다.
	//[in] y 축을 따라 변환합니다.
	
	AEMtx33 rotaitionMtx;
	AEMtx33Rot(&rotaitionMtx, rot);//void AEMtx33RotDeg	(AEMtx33 * pResult, f32 angle)
	//반시계 방향으로 회전하는 각도의 회전 행렬에 pResult를 설정합니다.
	//[out] pResult - AEMtx33을 가리키고 설정합니다.
	//[in] angle - 시계 반대 방향으로 회전하는 각도입니다.

	AEMtx33 scaleMtx;
	AEMtx33Scale(&scaleMtx, scale.x, scale.y);//void AEMtx33Scale(AEMtx33 * pResult,f32 x,f32 y)
	//pResult를 x와 y의 스케일링 행렬로 설정합니다.
	//  [out] pResult- Pointer to AEMtx33 을 설정합니다.
	//	[in] x- x축을 따라 스케일링합니다.
	//	[in] y- y축을 따라 스케일링합니다.


	//Concatenate thme
	AEMtx33Concat(&trancsformMatrix, &rotaitionMtx, &scaleMtx);//void AEMtx33Concat	(AEMtx33 * pResult, AEMtx33* pMtx0, AEMtx33* pMtx1)
	//pMtx0과 pMtx1의 곱으로 결과 설정
	//[out] pResult- Pointer to AEMtx33 을 설정합니다.
	//[in]  pMtx0- 입력을 위해 포인터를 AEMtx33으로 이동합니다.
	//[in]  pMtx1- 입력을 위해 AEMtx33으로 포인터를 이동합니다.




	AEMtx33Concat(&trancsformMatrix, &translateMtx, &trancsformMatrix);
}
TransformComp::TransformComp()
{
	pos.x = 0;
	pos.y = 0;
	scale.x = 1;
	scale.y = 1;

	rot = 0; // 기본 회전 값 추가
	CalculateMatrix();
}
TransformComp::TransformComp(GameObject* owner)
{
	pos.x = 0;
	pos.y = 0;

	scale.x = 1;
	scale.y = 1;

	CalculateMatrix();
}


TransformComp::~TransformComp()
{
}

void TransformComp::Update() {

	CalculateMatrix();
}
const AEMtx33& TransformComp::GetMatrix() const
{
	return trancsformMatrix;
}
void TransformComp::SetPos(const AEVec2& otherPos)
{
	this->pos = otherPos;
	CalculateMatrix();
}
void TransformComp::SetScale(const AEVec2& otherScale)
{
	this->scale = otherScale;
	CalculateMatrix();
}
void TransformComp::SetRot(const float& otherRot)
{
	this->rot = otherRot;
	CalculateMatrix();
}

void TransformComp::PrintMatrix()
{
	std::cout << "Printing Transform Comp. With this values: " << std::endl;
	std::cout << "Translate : " << pos.x << " " << pos.y;
	std::cout << "Rotation  : " << rot;
	std::cout << "Scale     : " << scale.x << " " << scale.y;
	for(int i=0; i<3; i++)
	{
		std::cout << " | ";
		for (int x = 0; x < 3; x++)
		{
			std::cout << " " << trancsformMatrix.m[i][x];
		}
		std::cout << " |";
		std::cout << std::endl;
	}
}
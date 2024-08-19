#include "TransformComp.h"
#include <iostream>

void TransformComp::CalculateMatrix() {
	//Create a transform matrix
	AEMtx33 translateMtx;
	// AEMtx33
	//"����� �� �켱 ����(column major format)���� ����Ǹ�, �� ��ȯ ��(translation term)�� ���� ������ ���� ��ġ�մϴ�.

	AEMtx33Trans(&translateMtx, pos.x, pos.y);//void AEMtx33Trans(AEMtx33 * pResult,f32 	x,f32 	y)
	//pResult�� x�� y�� ��ȯ ��ķ� �����մϴ�.
	//[out] Pointer to AEMtx33 �� �����մϴ�.
	//[in] x ���� ���� ��ȯ�մϴ�.
	//[in] y ���� ���� ��ȯ�մϴ�.
	
	AEMtx33 rotaitionMtx;
	AEMtx33Rot(&rotaitionMtx, rot);//void AEMtx33RotDeg	(AEMtx33 * pResult, f32 angle)
	//�ݽð� �������� ȸ���ϴ� ������ ȸ�� ��Ŀ� pResult�� �����մϴ�.
	//[out] pResult - AEMtx33�� ����Ű�� �����մϴ�.
	//[in] angle - �ð� �ݴ� �������� ȸ���ϴ� �����Դϴ�.

	AEMtx33 scaleMtx;
	AEMtx33Scale(&scaleMtx, scale.x, scale.y);//void AEMtx33Scale(AEMtx33 * pResult,f32 x,f32 y)
	//pResult�� x�� y�� �����ϸ� ��ķ� �����մϴ�.
	//  [out] pResult- Pointer to AEMtx33 �� �����մϴ�.
	//	[in] x- x���� ���� �����ϸ��մϴ�.
	//	[in] y- y���� ���� �����ϸ��մϴ�.


	//Concatenate thme
	AEMtx33Concat(&trancsformMatrix, &rotaitionMtx, &scaleMtx);//void AEMtx33Concat	(AEMtx33 * pResult, AEMtx33* pMtx0, AEMtx33* pMtx1)
	//pMtx0�� pMtx1�� ������ ��� ����
	//[out] pResult- Pointer to AEMtx33 �� �����մϴ�.
	//[in]  pMtx0- �Է��� ���� �����͸� AEMtx33���� �̵��մϴ�.
	//[in]  pMtx1- �Է��� ���� AEMtx33���� �����͸� �̵��մϴ�.




	AEMtx33Concat(&trancsformMatrix, &translateMtx, &trancsformMatrix);
}
TransformComp::TransformComp()
{
	pos.x = 0;
	pos.y = 0;
	scale.x = 1;
	scale.y = 1;

	rot = 0; // �⺻ ȸ�� �� �߰�
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
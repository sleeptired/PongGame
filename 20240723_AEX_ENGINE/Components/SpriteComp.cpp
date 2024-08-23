#include "SpriteComp.h"
#include "AEEngine.h"
#include "TransformComp.h"
#include "GameObject.h"

SpriteComp::SpriteComp(GameObject* owner)
	: GraphicsComponent(owner), mTex(nullptr)
{

	mColor = { 0, 0, 0 };
}
SpriteComp::~SpriteComp()
{
	if (mTex)
	{
		AEGfxTextureUnload(mTex);
	}
}
void SpriteComp::Update()
{
	AEGfxMeshStart();//AEGraphics���� �� �޽��� ����� �����ϵ��� �����մϴ�.

	//�� �κ��� ����� ���ϴ� �κ� ��ġ�� ������ pong game�� �÷��̾� ���븦 ������

	//uv whkvy

	                       //alpha,r,g,b
	AEGfxTriAdd(-0.5f, -0.5f, 0xffffffff, 0, 1,
                0.5f, -0.5f, 0xffffffff, 1, 1,
                -0.5f, 0.5f, 0xffffffff, 0, 0);
	//�޽��� ���ο� �ﰢ���� �߰��մϴ�.

	//�ﰢ���� 3���� ����� ���ǵȴ�: pt0, pt1 �� pt2. ������ �ð� �ݴ� ������ ������ �����ȴ�. ������ Z-���� �⺻�� 0���� �����ȴ�.
    AEGfxTriAdd(0.5f, -0.5f, 0xffffffff, 1, 1,
                0.5f, 0.5f, 0xffffffff, 1, 0,
                -0.5f, 0.5f, 0xffffffff, 0, 0);


	AEGfxVertexList* mesh = AEGfxMeshEnd();//AEGraphics �޸𸮿��� �޽��� �����մϴ�. �޽��� �ı��Ǿ� �� �̻� ����� �� �����ϴ�.
	

	//set renderer mod
	//AEGfxSetRenderMod(AE_GFX_RM_COLOR);
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);

	// AEEngine render option
	// AE_GFX_RM_NONE->No render.
	//	AE_GFX_RM_COLOR -> Color rendering.
	//	AE_GFX_RM_TEXTURE->Texture rendering
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);//�̰� ���� ������带 �����Ѵ�.

	//set color to multiply
	//AEGfxSetColorToMultiply(mColor.r / 255.f, mColor.g / 255.f, mColor.b / 255.f, 1);
	//AEGfxSetColorToAdd(0, 0, 0, 0);
	////	AEGfxSetColorToMultiply(mColor.r/255.f, mColor.g / 255.f, mColor.b / 255.f,1);
	AEGfxSetColorToMultiply(1, 1, 1, 1); //�÷� ���ð� 1,1,1,1�̾� ���� ������ ������ �����ϸ� ���� �ٲ�
	//���� ���ϱ�

	////Set color to add
	//**������ �ٲ� �� �ִ� 2���� �Լ�
	AEGfxSetColorToAdd(r, g, b, alpha);//�ܼ� ���ϱ� ����
	//AEGfxSetColorToAdd(mColor.r /*/ 255.f*/, mColor.g /*/ 255.f*/, mColor.b /*/ 255.f*/, 0.f);//���� ��ῡ �߰��ϴ� �� ����� ����(RGBA)�� �����մϴ�.
	


	//void AEGfxSetColorToAdd(float Red, float Green, float Blue,float Alpha)
	//���� �Լ��� ������ ������ �κ� �� ������ ���� �� �ִ�.
	
	//Set blend Mod
	//AE_GFX_BM_NONE - No blending.
	//
	//	AE_GFX_BM_BLEND - Color blending.
	//
	//	AE_GFX_BM_ADD - Additive blending.
	// 
	//	AE_GFX_BM_NUM

	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	//Set Transparency
	AEGfxSetTransparency(1);//�۷ι� ���� ���� �����մϴ�.
	//���ο� ���� ���� �� �Լ��� ȣ��� �Ŀ� �׷��� ��� ��ü�� ����˴ϴ�.
	//[in]	Alpha	Percentage of alpha (transparency). Range from 0.0f (clear) to 1.0f (opaque).

	//Set texture
	if (mTex)
	{
		AEGfxTextureSet(mTex, 0, 0);//�������� ����� �ؽ�ó�� �����մϴ�.
		//�ؽ�ó�� ����[in] offset_x - X ������.������ 0.0f���� 1.0f�Դϴ�.
		//�ؽ�ó�� ����[in]offset_y - Y �������Դϴ�.������ 0.0f���� 1.0f�Դϴ�.
	}

	//set transform

	//Get the transform from my owner transform comp
	 TransformComp* transform = own->GetComponent<TransformComp>();//TransformComp Ÿ���� ������Ʈ�� �˻��Ͽ� transform �����Ϳ� �Ҵ��մϴ�

	 //�� ���� ������Ʈ�� ��ġ ���� �޾ƿ��� ����� �Ѵ�.
    if (transform)
    {
        AEMtx33 matrix = transform->GetMatrix();
        AEGfxSetTransform(matrix.m);
		//�� ���� ��ȯ ����� �����մϴ�.
		//���ο� ����� �� �Լ��� ȣ��� �Ŀ� �׷��� ��� ��ü�� ����˴ϴ�.

    }
	//call Drawmesh
	AEGfxMeshDraw(mesh, AE_GFX_MDM_TRIANGLES);
	//void AEGfxMeshDraw(AEGfxVertexList * pVertexList, AEGfxMeshDrawMode 	MeshDrawMode)
	//ȭ�鿡 �޽��� �׷��ּ���.
	//MeshDrawMode�� ����Ͽ� ȭ�鿡 Mesh�� �������մϴ�.
	//�Ű�����
	//[in] pVertexList - �������� AEGfxVertexList ������.
	//[in] MeshDrawMode - �޽� �������� ����� AEGfxMeshDrawMode�Դϴ�.
	AEGfxMeshFree(mesh);

	//AEGfxMeshStart();
}

void SpriteComp::SetColor(float newR, float newG, float newB, float newAlpha)
{
	r = newR;
	g = newG;
	b = newB;
	alpha = newAlpha;
}

void SpriteComp::SetTexture(const std::string& filepath)
{
	if (mTex != nullptr)
		AEGfxTextureUnload(mTex);

	mTex = AEGfxTextureLoad(filepath.c_str());
}
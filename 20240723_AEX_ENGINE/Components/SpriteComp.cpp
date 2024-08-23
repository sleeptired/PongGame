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
	AEGfxMeshStart();//AEGraphics에게 새 메쉬를 만들기 시작하도록 지시합니다.

	//이 부분이 모양을 정하는 부분 수치를 조절해 pong game의 플레이어 막대를 만들자

	//uv whkvy

	                       //alpha,r,g,b
	AEGfxTriAdd(-0.5f, -0.5f, 0xffffffff, 0, 1,
                0.5f, -0.5f, 0xffffffff, 1, 1,
                -0.5f, 0.5f, 0xffffffff, 0, 0);
	//메쉬에 새로운 삼각형을 추가합니다.

	//삼각형은 3개의 점들로 정의된다: pt0, pt1 및 pt2. 점들은 시계 반대 방향의 순서로 나열된다. 점들의 Z-값은 기본값 0으로 설정된다.
    AEGfxTriAdd(0.5f, -0.5f, 0xffffffff, 1, 1,
                0.5f, 0.5f, 0xffffffff, 1, 0,
                -0.5f, 0.5f, 0xffffffff, 0, 0);


	AEGfxVertexList* mesh = AEGfxMeshEnd();//AEGraphics 메모리에서 메쉬를 해제합니다. 메쉬가 파괴되어 더 이상 사용할 수 없습니다.
	

	//set renderer mod
	//AEGfxSetRenderMod(AE_GFX_RM_COLOR);
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);

	// AEEngine render option
	// AE_GFX_RM_NONE->No render.
	//	AE_GFX_RM_COLOR -> Color rendering.
	//	AE_GFX_RM_TEXTURE->Texture rendering
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);//이걸 통해 렌더모드를 설정한다.

	//set color to multiply
	//AEGfxSetColorToMultiply(mColor.r / 255.f, mColor.g / 255.f, mColor.b / 255.f, 1);
	//AEGfxSetColorToAdd(0, 0, 0, 0);
	////	AEGfxSetColorToMultiply(mColor.r/255.f, mColor.g / 255.f, mColor.b / 255.f,1);
	AEGfxSetColorToMultiply(1, 1, 1, 1); //컬러 세팅값 1,1,1,1이야 원래 색으로 나오고 변경하면 색상도 바뀜
	//색상 곱하기

	////Set color to add
	//**색깔을 바꿀 수 있는 2개의 함수
	AEGfxSetColorToAdd(r, g, b, alpha);//단순 더하기 색깔
	//AEGfxSetColorToAdd(mColor.r /*/ 255.f*/, mColor.g /*/ 255.f*/, mColor.b /*/ 255.f*/, 0.f);//원래 재료에 추가하는 데 사용할 색상(RGBA)을 설정합니다.
	


	//void AEGfxSetColorToAdd(float Red, float Green, float Blue,float Alpha)
	//여기 함수가 색깔을 입히는 부분 즉 색상을 정할 수 있다.
	
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
	AEGfxSetTransparency(1);//글로벌 투명도 값을 설정합니다.
	//새로운 투명도 값은 이 함수가 호출된 후에 그려진 모든 개체에 적용됩니다.
	//[in]	Alpha	Percentage of alpha (transparency). Range from 0.0f (clear) to 1.0f (opaque).

	//Set texture
	if (mTex)
	{
		AEGfxTextureSet(mTex, 0, 0);//렌더링에 사용할 텍스처를 설정합니다.
		//텍스처에 대한[in] offset_x - X 오프셋.범위는 0.0f에서 1.0f입니다.
		//텍스처에 대한[in]offset_y - Y 오프셋입니다.범위는 0.0f에서 1.0f입니다.
	}

	//set transform

	//Get the transform from my owner transform comp
	 TransformComp* transform = own->GetComponent<TransformComp>();//TransformComp 타입의 컴포넌트를 검색하여 transform 포인터에 할당합니다

	 //그 게임 오브젝트의 위치 값을 받아오는 기능을 한다.
    if (transform)
    {
        AEMtx33 matrix = transform->GetMatrix();
        AEGfxSetTransform(matrix.m);
		//새 전역 변환 행렬을 설정합니다.
		//새로운 행렬은 이 함수가 호출된 후에 그려진 모든 객체에 적용됩니다.

    }
	//call Drawmesh
	AEGfxMeshDraw(mesh, AE_GFX_MDM_TRIANGLES);
	//void AEGfxMeshDraw(AEGfxVertexList * pVertexList, AEGfxMeshDrawMode 	MeshDrawMode)
	//화면에 메쉬를 그려주세요.
	//MeshDrawMode를 사용하여 화면에 Mesh를 렌더링합니다.
	//매개변수
	//[in] pVertexList - 렌더링할 AEGfxVertexList 포인터.
	//[in] MeshDrawMode - 메쉬 렌더링에 사용할 AEGfxMeshDrawMode입니다.
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
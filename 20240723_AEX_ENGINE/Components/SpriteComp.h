#pragma once
#include "../ComponentManager/GraphicsManager.h"
#include "GraphicsComponent.h"
#include "AEEngine.h"
#include "AEGraphics.h"
#include "AEMath.h"
class SpriteComp : public GraphicsComponent
{
	
	//mesh of points (quad)
	//All mye bjects have the same quad;
	// so i will not make it a member variable
	//text coords uv // Maybe later
	//color
public:
	struct Color
	{
		unsigned char r = 255;
		unsigned char g = 255;
		unsigned char b = 255;
	};
	float r, g, b, alpha;


private:
	Color mColor;
	//texture
	AEGfxTexture* mTex;
	//Render mode?
	//Blend mode?
	//Transparency

public:
	SpriteComp() :r(0), g(0), b(0), alpha(0) {}
	SpriteComp(GameObject* owner);
	~SpriteComp();
	void Update() override;
	//draw

	//Gettors/Settors

	void SetColor(float newR, float newG, float newB, float newAlpha);
	
	Color& Getcolor() { return mColor; };
	void SetTexture(const std::string& filepath);
	static std::string GetType()
	{
		return "SpriteComp";
	}
};
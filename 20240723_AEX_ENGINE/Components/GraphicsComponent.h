#pragma once
#include "BaseComponent.h"
#include <string>
class GameObject;

class GraphicsComponent : public BaseComponent
{
public:
	GraphicsComponent();
	GraphicsComponent(GameObject* owner);
	~GraphicsComponent();


	static std::string GetType()
	{
		return "GraphicsComponent";
	}
};
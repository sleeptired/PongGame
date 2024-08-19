#pragma once
#include "BaseComponent.h"
#include <string>
class GameObject;

class EngineComponent : public BaseComponent
{
public:
	EngineComponent();
	~EngineComponent();

	
	static std::string GetType()
	{
		return "EngineComponent";
	}
};

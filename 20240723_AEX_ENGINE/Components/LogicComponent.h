#pragma once
#include "BaseComponent.h"
#include <string>
class GameObject;

class LogicComponent : public BaseComponent
{
public:
	LogicComponent();
	~LogicComponent();

	static std::string GetType()
	{
		return "LogicComponent";
	}
};

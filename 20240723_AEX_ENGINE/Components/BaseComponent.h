#pragma once
#include <string>

//���漱��
class GameObject;

class BaseComponent
{
	
	BaseComponent(const BaseComponent&) = delete;
public:
	BaseComponent() :own(nullptr) {}
	BaseComponent(GameObject* owner) : own(owner) {}
	static std::string GetType() { return "BaseComponent"; };
	virtual ~BaseComponent() = default;
	virtual void Update() = 0;

	GameObject* own;
};

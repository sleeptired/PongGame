#include "GameObject.h"
#include "BaseComponent.h"

//GameObject에 있는 Component는 map형식이다.

GameObject::GameObject(BaseComponent* component)
{
	AddComponent(component);
}

GameObject::GameObject(const GameObject& other)// GameObject 객체를 복사할 때, 원본 객체의 컴포넌트들을 새로 생성된 객체에 복사하는 기능을 수행합니다.
{
	CopyComponents(other);//other 객체의 컴포넌트를 현재 객체로 복사하는 역할을 합니다.
}

GameObject& GameObject::operator=(const GameObject& other)
{
	if (this != &other) 
	{
		Clear();
		CopyComponents(other);
	}
	return *this;
}

GameObject::~GameObject()
{
	Clear();
}

void GameObject::Clear()
{
	
	for (auto& comp : Component) 
	{
		delete comp.second;
	}
	Component.clear();
}

void GameObject::CopyComponents(const GameObject& other)
//other 객체의 Component 맵을 순회하여 각 컴포넌트를 현재 객체의 Component 맵에 복사합니다.
{
	for (auto& comp : other.Component) 
	{
		Component.insert({ comp.first, comp.second });
	}
}


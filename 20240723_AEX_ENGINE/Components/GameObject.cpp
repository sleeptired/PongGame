#include "GameObject.h"
#include "BaseComponent.h"

//GameObject�� �ִ� Component�� map�����̴�.

GameObject::GameObject(BaseComponent* component)
{
	AddComponent(component);
}

GameObject::GameObject(const GameObject& other)// GameObject ��ü�� ������ ��, ���� ��ü�� ������Ʈ���� ���� ������ ��ü�� �����ϴ� ����� �����մϴ�.
{
	CopyComponents(other);//other ��ü�� ������Ʈ�� ���� ��ü�� �����ϴ� ������ �մϴ�.
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
//other ��ü�� Component ���� ��ȸ�Ͽ� �� ������Ʈ�� ���� ��ü�� Component �ʿ� �����մϴ�.
{
	for (auto& comp : other.Component) 
	{
		Component.insert({ comp.first, comp.second });
	}
}


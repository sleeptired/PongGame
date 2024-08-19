
#include "../ComponentManager/LogicManager.h"
#include "../ComponentManager/GraphicsManager.h"
#include "../ComponentManager/EngineManager.h"
#include <iostream>
template < typename T>
inline void GameObject::AddComponent(T* component)
{
	//BaseComponent�� ���� static std::string GetType() { return "BaseComponent"; }; �κ�
	//�� return���� �Ű����� component�� �ٲ۴ٴ� ����
	Component[component->GetType()] = component;//. Component[component->GetType()] = component;
												// ���ο����� component->GetType() �޼��尡 ��ȯ�ϴ� ���ڿ� ���� Component ���� Ű�� ���˴ϴ�.
												// value���� ���� component�ȿ� �ִ� �� ��ɰ� ������ ���� �����


	//component�� BaseComponent �Ǵ� �� �Ļ� Ŭ������ �������Դϴ�.
	component->own = this;	//	Ư�� ������Ʈ(component)�� own �Ӽ��� �ڽ��� �Ҵ��ϴ� �ڵ��Դϴ�

	// ������ �Ϲ������� �ش� ������Ʈ�� ���� GameObject�� ����Ű�� ���� ���˴ϴ�.
	// ��, own�� �� ������Ʈ�� ��� GameObject�� ���ϴ����� ��Ÿ���ϴ�.
	// component�� ���� GameObject�� �����ϴ� ���Դϴ�.
}
template<typename T>
inline T* GameObject::GetComponent() const
{
	auto it = Component.find(T::GetType());
	if (it != Component.end())
	{
		return dynamic_cast<T*>(it->second);//���� ����ȯ
	}
	return nullptr;
}
template <typename T>
inline bool GameObject::HasComponent() const
{
	T temp;
	auto it = Component.find(temp.GetType());
	return it != Component.end();
}
template <typename T>
inline void GameObject::RemoveComponent() 
{
	T temp;
	auto it = Component.find(temp.GetType());
	if (it != Component.end()) {
		delete it->second;
		Component.erase(it);
	}


}


#include "../ComponentManager/LogicManager.h"
#include "../ComponentManager/GraphicsManager.h"
#include "../ComponentManager/EngineManager.h"
#include <iostream>
template < typename T>
inline void GameObject::AddComponent(T* component)
{


	//component는 BaseComponent 또는 그 파생 클래스의 포인터입니다.
	component->own = this;	//	특정 컴포넌트(component)의 own 속성에 자신을 할당하는 코드입니다

	// 변수는 일반적으로 해당 컴포넌트가 속한 GameObject를 가리키기 위해 사용됩니다.
	// 즉, own은 그 컴포넌트가 어느 GameObject에 속하는지를 나타냅니다.
	// component가 속한 GameObject를 설정하는 것입니다.
}
template<typename T>
inline T* GameObject::GetComponent() const
{
	auto it = Component.find(T::GetType());
	if (it != Component.end())
	{
		return dynamic_cast<T*>(it->second);//하향 형변환
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

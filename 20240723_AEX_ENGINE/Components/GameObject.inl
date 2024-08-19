
#include "../ComponentManager/LogicManager.h"
#include "../ComponentManager/GraphicsManager.h"
#include "../ComponentManager/EngineManager.h"
#include <iostream>
template < typename T>
inline void GameObject::AddComponent(T* component)
{
	//BaseComponent에 있음 static std::string GetType() { return "BaseComponent"; }; 부분
	//즉 return값을 매개변수 component로 바꾼다는 거임
	Component[component->GetType()] = component;//. Component[component->GetType()] = component;
												// 라인에서는 component->GetType() 메서드가 반환하는 문자열 값이 Component 맵의 키로 사용됩니다.
												// value값은 들어온 component안에 있는 그 기능과 값들이 전부 저장됨


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

#include "GraphicsManager.h"

GraphicsManager* GraphicsManager::Instance_ = nullptr; 

GraphicsManager::~GraphicsManager()
{
    clear();
}


void GraphicsManager::clear()
{
    delete Instance_;
    Instance_ = nullptr;
}

GraphicsComponent* GraphicsManager::GetComponent(const std::string& str) const
{
    for (auto a : Component)
        if (a->GetType() == str)
            return a;
    return nullptr;
}

void GraphicsManager::AddComponent(GraphicsComponent* component)
{
    Component.push_back(component);
}

void GraphicsManager::RemoveComp(GraphicsComponent* component)
{
    Component.erase(std::remove(Component.begin(), Component.end(), component), Component.end());
}

void GraphicsManager::Update()
{
    // for 루프를 사용하여 Component라는 컨테이너(예: 벡터, 리스트 등)의 각 요소를 순회하며, 
    // 각 요소에 대해 Update() 메서드를 호출하는 내용을 나타냅니다.
    
    //따라서 이 코드는 Component라는 컨테이너에 있는 모든 요소를 순회하며 
    // 각 요소의 Update() 메서드를 호출하여 상태를 갱신하는 역할을 합니다.
    for (auto it : Component)
    {
        it->Update();
    }


}

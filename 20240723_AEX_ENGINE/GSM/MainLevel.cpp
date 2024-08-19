#include "MainLevel.h"
#include "GameStateManager.h"
#include "GoalLevel.h"
#include <iostream>
#include "../Components/PlayerComp.h"
#include "../Components/RigidbodyComp.h"
#include "../Components/AudioComponent.h"
#include "../Components/GameObject.h"
#include "../Components/transformcomp.h"
#include "../Components/SpriteComp.h"
#include "../Components/PlayerComp.h"

void Levels::MainLevel::Init()
{
    // 플레이어 객체 초기화
   
   
    // 마리오 객체 초기화
    planet = new GameObject();//행성이라는 객체 생성

    TransformComp* planetTransform = new TransformComp(planet);//행성(게임 오브젝트) 위치 컴포넌트 추가
    SpriteComp* planetSprite = new SpriteComp(planet);//행성(게임 오브젝트) 스프라이트(이미지) 컴포넌트 추가

    planetSprite->SetTexture("../../Assets/hos.png");

    planet->AddComponent(planetTransform);
    planet->AddComponent(planetSprite);

    player = new GameObject();
    TransformComp* playerTransform = new TransformComp(player);
    SpriteComp* playerSprite = new SpriteComp(player);
    RigidbodyComp* playerRigidBody = new RigidbodyComp(player);
    AudioComp* playerAudio = new AudioComp(player);
    PlayerComp* playerMove = new PlayerComp(player);
    playerSprite->SetTexture("../../Assets/ame.png");
    playerAudio->SetAudio("../../Assets/bouken.mp3");

    player->AddComponent(playerTransform);
    player->AddComponent(playerSprite);
    player->AddComponent(playerRigidBody);
    player->AddComponent(playerAudio);
    player->AddComponent(playerMove);
    playerTransform->SetPos({ 100, 100 });
    playerTransform->SetScale({ 200, 200 });
    counter = 0;
    std::cout << "Main level Init" << std::endl;
}

void Levels::MainLevel::Update()
{
	//std::cout << "Main level Update" << std::endl;
    TransformComp* trs = planet->GetComponent<TransformComp>();
    SpriteComp* spr = planet->GetComponent<SpriteComp>();
    AudioComp* audio = player->GetComponent<AudioComp>();
    
    if (trs)
    {
        trs->SetPos({ trs->GetPos().x +1, trs->GetPos().y });
        std::cout << trs->GetPos().x << "\n";
        if (trs->GetPos().x > 800)
            trs->SetPos({ -800, 0 });
        if (counter % 10 == 0)
        {
            trs->SetRot(trs->GetRot() + 0.5f);
        }
        trs->SetScale({ trs->Getscale().x * 1.01f, trs->Getscale().y * 1.01f });
          
    }
    AEGfxMeshStart();
   /* if (spr)
    {
        SpriteComp::Color& c = spr->Getcolor();
        if (counter < 255)
        {
            c.r--;
            c.g++;
            c.b++;
        }
        else
        {
            c.r++;
            c.g--;
            c.b--;
        }
    }*/

    if (!audio->IsPlaying())
    {
 
        audio->Play();
        
    }
	//If goal was reached changed level

	//counter++;
	//if (counter >= 100)
	//{
	//	//Changer to goal
	//	GSM::GameStateManager::GetGSMPtr()->ChangeLevel(new GoalLevel);
	//}
}

void Levels::MainLevel::Exit()
{
	std::cout << "Main level Exit" << std::endl;
	delete player;
	delete planet;
}

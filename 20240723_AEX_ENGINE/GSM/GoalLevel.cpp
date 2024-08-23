#include "GoalLevel.h"
#include "GameStateManager.h"
#include "MainMenu_Level.h"
#include "MainLevel.h"
#include <iostream>
#include "../Components/PlayerComp.h"
#include "../Components/RigidbodyComp.h"
#include "../Components/AudioComponent.h"
#include "../Components/GameObject.h"
#include "../Components/transformcomp.h"
#include "../Components/SpriteComp.h"
void Levels::GoalLevel::Init()
{
	pFont = AEGfxCreateFont("Assets/liberation-mono.ttf", 50);
	//std::cout << "Goal level Init" << std::endl;
}

void Levels::GoalLevel::Update()
{
	//std::cout << "Goal level Update" << std::endl;
	//std::cout << "Yow Win" << std::endl;
	////after something . change level to exit
	//GSM::GameStateManager::GetGSMPtr()->ChangeLevel(nullptr);

    
    if (Levels::MainLevel::P1Win == 1) {
        AEGfxPrint(pFont, "Player 1 Win", -0.9f, 0.5f, 1.f, 1.f, 0.f, 0.f, 1.f);
        AEGfxPrint(pFont, "Player 2 Lose", 0.4f, 0.5f, 1.f, 0.f, 0.f, 1.f, 1.f);
        AEGfxPrint(pFont, "Press R-> GameRestart", -0.5f, 0.f, 1.f, 0.f, 1.f, 0.f, 1.f);
        AEGfxPrint(pFont, "Press Spce-> MainMenu", -0.5f, -0.5f, 1.f, 0.f, 1.f, 0.f, 1.f);
        //font, c-string to print, x position, y position,scale, red, green, blue, alpha
    }

    if (Levels::MainLevel::P2Win == 1) {
        AEGfxPrint(pFont, "Player 2 Win", -0.9f, 0.5f, 1.f, 1.f, 0.f, 0.f, 1.f);
        AEGfxPrint(pFont, "Player 1 Lose", 0.4f, 0.5f, 1.f, 0.f, 0.f, 1.f, 1.f);
        AEGfxPrint(pFont, "Press R-> GameRestart", -0.5f, 0.f, 1.f, 0.f, 1.f, 0.f, 1.f);
        AEGfxPrint(pFont, "Press Spce-> MainMenu", -0.5f, -0.5f, 1.f, 0.f, 1.f, 0.f, 1.f);
    }

    //메인메뉴 가는 기능
    if (AEInputCheckTriggered(AEVK_SPACE))
    {
        GSM::GameStateManager* gsm = GSM::GameStateManager::GetGSMPtr();
        gsm->ChangeLevel(new Levels::MainMenu_Level);
        Levels::MainLevel::P1Win = 0;
        Levels::MainLevel::P2Win = 0;
    }
    //다시 시작 기능
    if (AEInputCheckTriggered(AEVK_R))
    {
        GSM::GameStateManager* gsm = GSM::GameStateManager::GetGSMPtr();
        gsm->ChangeLevel(new Levels::MainLevel);
        Levels::MainLevel::P1Win = 0;
        Levels::MainLevel::P2Win = 0;
    }

}
void Levels::GoalLevel::Exit()
{
    AEGfxDestroyFont(pFont);
	//std::cout << "Goal level Exit" << std::endl;
}
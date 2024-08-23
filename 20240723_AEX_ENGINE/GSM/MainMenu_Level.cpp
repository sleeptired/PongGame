#include "MainMenu_Level.h"
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

//오디오 실험용
#include "AEAudio.h"
#include "AEEngine.h"

void Levels::MainMenu_Level::Init()
{
    pFont = AEGfxCreateFont("Assets/liberation-mono.ttf", 50);

    
    //오디오 세팅(코드)
    /*
    mGroup = AEAudioCreateGroup();
    mAudio = AEAudioLoadSound("Assets/bouken.mp3");
    */


}

void Levels::MainMenu_Level::Update()
{

    AEGfxPrint(pFont,           // font handle given by AEGfxCreateFont()
        "Space Bar -> Game Start",   // null-terminated c-string to print
        -0.5f,             // x position on normalized coordinates, ranging from -1.f to 1.f
        0.f,             // y position in normalized coordinates, ranging from -1.f to 1.f
        1.f,             // how much to scale the text by
        1.f,             // percentage of red, ranging from 0.f to 1.f
        0.f,             // percentage of green, ranging from 0.f to 1.f
        0.f,             // percentage of blue, ranging from 0.f to 1.f
        1.f);            // percentage of alpha, ranging from 0.f to 1.f
    if (AEInputCheckTriggered(AEVK_SPACE))
    {
        GSM::GameStateManager* gsm = GSM::GameStateManager::GetGSMPtr();
        gsm->ChangeLevel(new Levels::MainLevel);
    }

    //오디오 실행시키는 부분(코드)
    /*
    if (play == 0) 
    {
        AEAudioPlay(mAudio, mGroup, volume, pitch, 1);
        play = 1;
    }
    */



    //const char* pText = "Hello World";
    //f32 width, f32 height;
    //AEGfxGetPrintSize(pFont, pText, 1.f, &width, &height);
    //AEGfxPrint(pFont, text, -width / 2, -height / 2, 1, 1, 1, 1, 1);
}

void Levels::MainMenu_Level::Exit()
{
    //오디오 메모리 해제
    /*
    AEAudioUnloadAudio(mAudio);
    AEAudioUnloadAudioGroup(mGroup);
    */

    AEGfxDestroyFont(pFont);
}

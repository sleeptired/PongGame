#include "MainLevel.h"
#include "GameStateManager.h"
#include "MainMenu_Level.h"
#include "GoalLevel.h"
#include <iostream>
#include "../Components/PlayerComp.h"
#include "../Components/RigidbodyComp.h"
#include "../Components/AudioComponent.h"
#include "../Components/GameObject.h"
#include "../Components/transformcomp.h"
#include "../Components/SpriteComp.h"

int Levels::MainLevel::P1score = 0;
int Levels::MainLevel::P2score = 0;
int Levels::MainLevel::P1Win = 0;
int Levels::MainLevel::P2Win = 0;


void Levels::MainLevel::Init()
{
    // 플레이어 객체 초기화
   
   
    // 마리오 객체 초기화
    //planet = new GameObject();//행성이라는 객체 생성

    //TransformComp* planetTransform = new TransformComp(planet);//행성(게임 오브젝트) 위치 컴포넌트 추가
    //SpriteComp* planetSprite = new SpriteComp(planet);//행성(게임 오브젝트) 스프라이트(이미지) 컴포넌트 추가

    //planetSprite->SetTexture("../../Assets/hos.png");

    //planet->AddComponent(planetTransform);
    //planet->AddComponent(planetSprite);

    //Player_1 MoverMent
    /*
    player = new GameObject();
    TransformComp* playerTransform = new TransformComp(player);
    SpriteComp* playerSprite = new SpriteComp(player);
    RigidbodyComp* playerRigidBody = new RigidbodyComp(player);
    AudioComp* playerAudio = new AudioComp(player);
    PlayerComp* playerMove = new PlayerComp(player);
    //playerSprite->SetTexture("../../Assets/ame.png");
    playerAudio->SetAudio("../../Assets/bouken.mp3");

    player->AddComponent(playerTransform);
    player->AddComponent(playerSprite);
    player->AddComponent(playerRigidBody);
    player->AddComponent(playerAudio);
    player->AddComponent(playerMove);
    playerTransform->SetPos({ 50   , 50 });
    playerTransform->SetScale({ 200, 200 });
    */
    counter = 0;
    std::cout << "Main level Init" << std::endl;

    //Pong Game
    P_player1 = new GameObject();
    TransformComp*P_player1Transform = new TransformComp(P_player1);
    SpriteComp* P_player1Sprite = new SpriteComp(P_player1);
    RigidbodyComp* P_player1RigidBody = new RigidbodyComp(P_player1);
    PlayerComp* P_player1Move = new PlayerComp(P_player1);
    //-audio-
    AudioComp* audio = new AudioComp(P_player1);
    P_player1->AddComponent(audio);
    audio->SetAudio("../../Assets/bouken.mp3");
    //-audio-
    P_player1->AddComponent(P_player1Transform);
    P_player1->AddComponent(P_player1Sprite);
    P_player1->AddComponent(P_player1RigidBody);
    P_player1->AddComponent(P_player1Move);
    P_player1Transform->SetPos({ -780,0 });
    P_player1Transform->SetScale({ 16,150 });
    P_player1Move->SetID("P_player1");


    P_player2 = new GameObject();
    TransformComp* P_player2Transform = new TransformComp(P_player2);
    SpriteComp* P_player2Sprite = new SpriteComp(P_player2);
    RigidbodyComp* P_player2RigidBody = new RigidbodyComp(P_player2);
    PlayerComp* P_player2Move = new PlayerComp(P_player2);
    P_player2->AddComponent(P_player2Transform);
    P_player2->AddComponent(P_player2Sprite);
    P_player2->AddComponent(P_player2RigidBody);
    P_player2->AddComponent(P_player2Move);
    P_player2Transform->SetPos({ 780,0 });
    P_player2Transform->SetScale({ 16,150 });
    P_player2Move->SetID("P_player2");

    CenterLine = new GameObject();
    TransformComp* CenterLineTransform = new TransformComp(CenterLine);
    SpriteComp* CenterLineSprite = new SpriteComp(CenterLine);
    CenterLine->AddComponent(CenterLineTransform);
    CenterLine->AddComponent(CenterLineSprite);
    CenterLineTransform->SetPos({ 0,0 });
    CenterLineTransform->SetScale({ 5,900 });
    CenterLineSprite->SetColor(0, 0, -1, 0);

    P_ball = new GameObject();
    TransformComp* P_ballTransform = new TransformComp(P_ball);
    SpriteComp* P_ballSprite = new SpriteComp(P_ball);
    RigidbodyComp* P_ballRigidBody = new RigidbodyComp(P_ball);
    PlayerComp* P_ballMove = new PlayerComp(P_ball);
    P_ball->AddComponent(P_ballTransform);
    P_ball->AddComponent(P_ballSprite);
    P_ball->AddComponent(P_ballRigidBody);
    P_ball->AddComponent(P_ballMove);
    P_ballTransform->SetPos({ 0,0 });
    P_ballTransform->SetScale({ 16,16 });
    P_ballSprite->SetColor(0, -1, -1, 0);
    P_ballMove->SetID("Ball");


    UpWall = new GameObject();
    TransformComp* UpWallTransform = new TransformComp(UpWall);
    SpriteComp* UpWallSprite = new SpriteComp(UpWall);
    RigidbodyComp* UpWallRigidBody = new RigidbodyComp(UpWall);
    UpWall->AddComponent(UpWallTransform);
    UpWall->AddComponent(UpWallSprite);
    UpWall->AddComponent(UpWallRigidBody);
    UpWallTransform->SetPos({ 0,440 });
    UpWallTransform->SetScale({ 1600,20 });
    UpWallSprite->SetColor(-1, 0, -1, 0);

    DownWall = new GameObject();
    TransformComp* DownWallTransform = new TransformComp(DownWall);
    SpriteComp* DownWallSprite = new SpriteComp(DownWall);
    RigidbodyComp* DownWallRigidBody = new RigidbodyComp(DownWall);
    DownWall->AddComponent(DownWallTransform);
    DownWall->AddComponent(DownWallSprite);
    DownWall->AddComponent(DownWallRigidBody);
    DownWallTransform->SetPos({ 0,-440 });
    DownWallTransform->SetScale({ 1600,20 });
    DownWallSprite->SetColor(-1, 0, -1, 0);


    P_Font = AEGfxCreateFont("../../Assets/liberation-mono.ttf", 50);
    P1str_score = std::to_string(P1score);
    P2str_score = std::to_string(P2score);

}

void Levels::MainLevel::Update()
{
    //여기에 충돌처리 한번 구현해보기
    //튕겨나가는거 구현
      AEGfxPrint(P_Font, P1str_score.c_str(), -0.7f, 0.7f, 1.f, 1.f, 0.f, 0.f, 1.f);
      AEGfxPrint(P_Font, P2str_score.c_str(), 0.7f, 0.7f, 1.f, 1.f, 0.f, 0.f, 1.f);
      //오브젝트 위치 값
      TransformComp* p1Transform = P_player1->GetComponent<TransformComp>();
      TransformComp* p2Transform = P_player2->GetComponent<TransformComp>();
      TransformComp* ballTransform = P_ball->GetComponent<TransformComp>();
      TransformComp* UpWallTransform = UpWall->GetComponent<TransformComp>();
      TransformComp* DownWallTransform = DownWall->GetComponent<TransformComp>();
      //공의 움직임을 관리할 함수
      PlayerComp* P_balldir = P_ball->GetComponent<PlayerComp>();


      //-audio-
      AudioComp* p1audio = P_player1->GetComponent<AudioComp>();
      p1audio->Play();
      //-audio-

      AEVec2 Player1_Pos = p1Transform->GetPos();
      AEVec2 Player2_Pos = p2Transform->GetPos();
      AEVec2 ball_Pos = ballTransform->GetPos();
      AEVec2 UpWall_Pos = UpWallTransform->GetPos();
      AEVec2 DownWall_Pos = DownWallTransform->GetPos();

      int Player_halfwidth = (p1Transform->Getscale().x) / 2;
      int Player_halflength = (p1Transform->Getscale().y) / 2;
      int ball_halfside = (ballTransform->Getscale().x) / 2;

      //Player1이 -위치
      if (Player1_Pos.x - Player_halfwidth < ball_Pos.x + ball_halfside && Player1_Pos.x + Player_halfwidth > ball_Pos.x - ball_halfside &&
          Player1_Pos.y - Player_halflength < ball_Pos.y + ball_halfside && Player1_Pos.y + Player_halflength > ball_Pos.y - ball_halfside)
      {
          ballTransform->SetPos({ ballTransform->GetPos().x + 10, ballTransform->GetPos().y });
          //SetPos를 사용하여 공의 위치를 약간 이동시켜서 겹침을 방지함.
          //P_balldir->ballSpeedX = -1 * (P_balldir->ballSpeedX);
          P_balldir->ballSpeedX = -1 * (P_balldir->ballSpeedX);

      }

      //Player2가 +위치
      if (Player2_Pos.x - Player_halfwidth < ball_Pos.x + ball_halfside && Player2_Pos.x + Player_halfwidth > ball_Pos.x - ball_halfside &&
          Player2_Pos.y - Player_halflength < ball_Pos.y + ball_halfside && Player2_Pos.y + Player_halflength > ball_Pos.y - ball_halfside)
      {
          ballTransform->SetPos({ ballTransform->GetPos().x - 10, ballTransform->GetPos().y });
          //여기서 속도를 추가해서 게임의 재미를 더 줄 수 있다.
          //P_balldir->ballSpeedX = -1 * (P_balldir->ballSpeedX);
          P_balldir->ballSpeedX = -1 * (P_balldir->ballSpeedX);


      }

      if (UpWall_Pos.x - 800 < ball_Pos.x + 8 && UpWall_Pos.x + 800 > ball_Pos.x - 8 &&
          UpWall_Pos.y - 10 < ball_Pos.y + 8 && UpWall_Pos.y + 10 > ball_Pos.y - 8)
      {
          ballTransform->SetPos({ ballTransform->GetPos().x , ballTransform->GetPos().y - 10 });
          P_balldir->ballSpeedY = -1 * (P_balldir->ballSpeedY);
      }

      if (DownWall_Pos.x - 800 < ball_Pos.x + 8 && DownWall_Pos.x + 800 > ball_Pos.x - 8 &&
          DownWall_Pos.y - 10 < ball_Pos.y + 8 && DownWall_Pos.y + 10 > ball_Pos.y - 8)
      {
          ballTransform->SetPos({ ballTransform->GetPos().x , ballTransform->GetPos().y + 10 });
          P_balldir->ballSpeedY = -1 * (P_balldir->ballSpeedY);
      }

      //레벨 바꾸는 컨디션

      //if (AEInputCheckTriggered(AEVK_SPACE)) 
        //{
        //    GSM::GameStateManager* gsm = GSM::GameStateManager::GetGSMPtr();
        //    gsm->ChangeLevel(new Levels::MainLevel);
        //}

      //공이 플레이어를 넘어 갈 때 게임을 다시 시작하는 부분
      if (Player2_Pos.x + 20 < ball_Pos.x - 8)
      {
          P2score++;
          GSM::GameStateManager* gsm = GSM::GameStateManager::GetGSMPtr();
          gsm->ChangeLevel(new Levels::MainLevel);
      }

      if (Player1_Pos.x - 20 > ball_Pos.x + 8)
      {
          P1score++;
          GSM::GameStateManager* gsm = GSM::GameStateManager::GetGSMPtr();
          gsm->ChangeLevel(new Levels::MainLevel);
      }

      //실험용
      //if (AEInputCheckTriggered(AEVK_SPACE))
      //{
      //    GSM::GameStateManager* gsm = GSM::GameStateManager::GetGSMPtr();
      //    gsm->ChangeLevel(new Levels::GoalLevel);
      //}

      if (P1score > 11) 
      {
          P1Win = 1;
          P1score = 0;
          P2score = 0;
          GSM::GameStateManager* gsm = GSM::GameStateManager::GetGSMPtr();
          gsm->ChangeLevel(new Levels::GoalLevel);
      }
      
      if (P2score > 11)
      {
          P2Win = 1;
          P1score = 0;
          P2score = 0;
          GSM::GameStateManager* gsm = GSM::GameStateManager::GetGSMPtr();
          gsm->ChangeLevel(new Levels::GoalLevel);
      }


    //일정 점수이상으로 가면 스테이지 넘어가게 로직 작성

	//std::cout << "Main level Update" << std::endl;
    //TransformComp* trs = planet->GetComponent<TransformComp>();
    //SpriteComp* spr = planet->GetComponent<SpriteComp>();
    //AudioComp* audio = P_player1->GetComponent<AudioComp>();
    
    // 
    //이거 분석하기
    //if (trs)
    //{
    //    trs->SetPos({ trs->GetPos().x +1, trs->GetPos().y });
    //    std::cout << trs->GetPos().x << "\n";
    //    if (trs->GetPos().x > 800)
    //        trs->SetPos({ -800, 0 });
    //    if (counter % 10 == 0)
    //    {
    //        trs->SetRot(trs->GetRot() + 0.5f);
    //    }
    //    trs->SetScale({ trs->Getscale().x * 1.01f, trs->Getscale().y * 1.01f });
    //      
    //}
     


   // if(ball_trs->GetPos().x+8>player1_trs)
    //AEGfxMeshStart();


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
	//elete player;
	//delete planet;
    
    //
    delete CenterLine;
    delete P_player1;
    delete P_player2;
    delete P_ball;
    delete UpWall;
    delete DownWall;

}




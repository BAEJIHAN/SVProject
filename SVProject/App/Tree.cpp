#include "Tree.h"
#include <MyRendererBasic.h>
#include <MyCollision.h>
#include "MyPlayer.h"
#include "MyLogicValue.h"
#include "FarmScene.h"
#include <MySound.h>
Tree::Tree() :HP(6), bHit(false), bShakeOn(false), btreebreaksound(false)
{
}

Tree::~Tree()
{
}


void Tree::Start() 
{
    TreeEventer.CreateTimeEvent(0.5f, this, &Tree::HitEnd, &Tree::HitStart);
    TreeEventer.LoopOn();
   
   
	renderer1 = CreateRenderer<MyRendererBasic>(RENDERINDEX::PLAYER);
	renderer1->TransSetting(L"tree1.bmp", { 66, 82 });



	renderer2 = CreateRenderer<MyRendererBasic>(RENDERINDEX::PLAYER);
   
	renderer2->TransSetting(L"tree2.bmp", { 192, 315 });
  
	renderer2->SetPivotPos({ 0.0f, -315.0f * 0.5f });

    
}
void Tree::Update()
{
    MyPlayer* Player=MyLogicValue::FarmSceneAddress->GetPlayer();
    float4 PlayerPos = Player->GetPosition();
    float4 TreePos = GetPosition();
    if ((TreePos.x - 32 <= PlayerPos.x && PlayerPos.x <= TreePos.x + 32)
        && (TreePos.y - 300 <= PlayerPos.y && PlayerPos.y <= TreePos.y))
    {
        renderer2->SetAlpha(100);
    }
    else
    {
        renderer2->TransSetting(L"tree2.bmp", { 192, 315 });
    }

   



    
    if (true == bHit)
    {
        TreeEventer.Update();
    }
    if (true == bShakeOn)
    {
        Shake();
    }
    
}

void Tree::HitStart()
{
    bShakeOn = true;
    
}

void Tree::HitEnd()
{
    if (HP == 2)
    {

        renderer2->Off();

        MySound::Play(L"treebreak.mp3");

    }
    renderer2->TransSetting(L"tree2.bmp", { 192, 315 });
    TreeEventer.Reset();
    bHit = false;
    bShakeOn = false;
    renderer2->SetPivotPos(float4(0.f, -315.0f * 0.5f));
}

void Tree::Shake()
{
    float i= -1;
    static float ShakeScale = 2;
    ShakeScale *= i;
    renderer2->SetPivotPos(float4(ShakeScale, -315.0f * 0.5f));
}


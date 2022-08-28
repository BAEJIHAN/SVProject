#pragma once
#include <MyActor.h>
#include <MyTimeEventer.h>

// 분류 : 
// 용도 : 
// 설명 : 플레이씬에서 플레이어의 기능을 담당해줄 녀석.
class MyRendererBasic;
class FadeInActor : public MyActor
{
private: // MemberVar
    MyRendererBasic* mRender;
    float Alpha;
    bool bFadeOn;
public: // constructer destructer
    FadeInActor();
    ~FadeInActor();

    MyTimeEventer<FadeInActor> FadeInTimer;
 
public: // delete constructer 
    FadeInActor(const FadeInActor& _Other) = delete;
    FadeInActor(const FadeInActor&& _Other) = delete;

public: // delete operator
    FadeInActor& operator=(const FadeInActor& _Other) = delete;
    FadeInActor& operator=(const FadeInActor&& _Other) = delete;

public: // MemberFunc
    void Start() override; // 돈다.
    void Update() override; // 돈다.


    void FadeInStart();
    void FadeInStay();
    void FadeInEnd();

    void SetFadeAlpha(unsigned char _Alpha);

    MyRendererBasic* GetRender() { return mRender; }
    void SetFadeOn(bool _on) 
    { 
        FadeInTimer.Reset();
        bFadeOn = _on; 
    }
    bool IsFadeOn() { return bFadeOn; }

};


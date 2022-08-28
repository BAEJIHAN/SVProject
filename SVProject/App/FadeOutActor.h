#pragma once
#include <MyActor.h>
#include <MyTimeEventer.h>

// 분류 : 
// 용도 : 
// 설명 : 플레이씬에서 플레이어의 기능을 담당해줄 녀석.
class MyRendererBasic;
class FadeOutActor : public MyActor
{
private: // MemberVar
    MyRendererBasic* mRender;
    float Alpha;
    bool bFadeOn;
public: // constructer destructer
    FadeOutActor();
    ~FadeOutActor();
   
    MyTimeEventer<FadeOutActor> FadeOutTimer;

public: // delete constructer 
    FadeOutActor(const FadeOutActor& _Other) = delete;
    FadeOutActor(const FadeOutActor&& _Other) = delete;

public: // delete operator
    FadeOutActor& operator=(const FadeOutActor& _Other) = delete;
    FadeOutActor& operator=(const FadeOutActor&& _Other) = delete;

public: // MemberFunc
    void Start() override; // 돈다.
    void Update() override; // 돈다.

    void FadeOutStart();
    void FadeOutStay();
    void FadeOutEnd();

  

    void SetFadeAlpha(unsigned char _Alpha);

    MyRendererBasic* GetRender() { return mRender; }
    void SetFadeOn(bool _on)
    {
        FadeOutTimer.Reset();
        bFadeOn = _on;
    }
    
    bool IsFadeOn() { return bFadeOn; }

};


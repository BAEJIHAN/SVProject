#pragma once
#include <MyActor.h>
#include <MyTimeEventer.h>

// �з� : 
// �뵵 : 
// ���� : �÷��̾����� �÷��̾��� ����� ������� �༮.
class MyRendererBasic;
class MyFadeActor : public MyActor
{
private: // MemberVar
    MyRendererBasic* mRender;
    float Alpha;
    bool bFadeOn;
public: // constructer destructer
    MyFadeActor();
    ~MyFadeActor();

    MyTimeEventer<MyFadeActor> FadeInTimer;
    MyTimeEventer<MyFadeActor> FadeOutTimer;

public: // delete constructer 
    MyFadeActor(const MyFadeActor& _Other) = delete;
    MyFadeActor(const MyFadeActor&& _Other) = delete;

public: // delete operator
    MyFadeActor& operator=(const MyFadeActor& _Other) = delete;
    MyFadeActor& operator=(const MyFadeActor&& _Other) = delete;

public: // MemberFunc
    void Start() override; // ����.
    void Update() override; // ����.

    void FadeOutStart();
    void FadeOutStay();
    void FadeOutEnd();
    
    void FadeInStart();
    void FadeInStay();
    void FadeInEnd();

    void SetFadeAlpha(unsigned char _Alpha);

    MyRendererBasic* GetRender() { return mRender; }
    void SetFadeOn(bool _on) { bFadeOn = _on; }
    bool IsFadeOn() { return bFadeOn; }
  
};


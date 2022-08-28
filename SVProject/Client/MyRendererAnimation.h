#pragma once
#include "MyRenderer.h"
#include <MyWinImage.h>
#include <Mystring.h>
#include <map>
// 분류 : 
// 용도 : 
// 설명 : 
class MyActor;
class MyWinImage;
class MyRendererAnimation : public MyRenderer
{
private:
    class Animation
    {
    public:
        float4 mScale;
        MyWinImage* mImage;
        float mFrameTime; // 이미지 한장한장이 바뀌는 시간.
        float mCurTime; // 현재 애니메이션 시간
        int mStartFrame; // 시작프레임
        int mEndFrame; // 시작프레임
        int mCurFrame; // 현재 프레임
        bool mIsLoop;
        int TransColor;

    public:
        void Update();
        void Reset();

    public:
        Animation();
        ~Animation();
    };

private: // Static Var
public: // Static Func
private: // member Var
    std::map<Mystring, Animation> mAnimation;
    Animation* mCurAnimation;


public: // constructer destructer
    MyRendererAnimation();
    ~MyRendererAnimation();

public: // delete constructer 
    MyRendererAnimation(const MyRendererAnimation& _Other) = delete;
    MyRendererAnimation(const MyRendererAnimation&& _Other) = delete;

public: // delete operator
    MyRendererAnimation& operator=(const MyRendererAnimation& _Other) = delete;
    MyRendererAnimation& operator=(const MyRendererAnimation&& _Other) = delete;

private:
    Animation* FindAnimation(const Mystring& _Name);

public: // member Func
    //                     Walk                                LeftMino.bmp                     0           8               0.1초마다
    void CreateAnimation(const Mystring& _AniName, const Mystring& _ImageName,float4 Scale, int _Start, int _End, float _FrameTime = 0.1f, bool _Loop = true);
    void ChangeAnimation(const Mystring& _AniName);

public:
    void Render() override;
};


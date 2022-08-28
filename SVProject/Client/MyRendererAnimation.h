#pragma once
#include "MyRenderer.h"
#include <MyWinImage.h>
#include <Mystring.h>
#include <map>
// �з� : 
// �뵵 : 
// ���� : 
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
        float mFrameTime; // �̹��� ���������� �ٲ�� �ð�.
        float mCurTime; // ���� �ִϸ��̼� �ð�
        int mStartFrame; // ����������
        int mEndFrame; // ����������
        int mCurFrame; // ���� ������
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
    //                     Walk                                LeftMino.bmp                     0           8               0.1�ʸ���
    void CreateAnimation(const Mystring& _AniName, const Mystring& _ImageName,float4 Scale, int _Start, int _End, float _FrameTime = 0.1f, bool _Loop = true);
    void ChangeAnimation(const Mystring& _AniName);

public:
    void Render() override;
};


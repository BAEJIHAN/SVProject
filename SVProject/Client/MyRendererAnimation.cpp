#include "MyRendererAnimation.h"
#include "MyResMgr.h"
#include "MyWinImage.h"
#include <MyDebug.h>
#include <MyWindow.h>
#include"MyCamera.h"
MyRendererAnimation::Animation::Animation()
    : mImage(nullptr),
    mFrameTime(0.1f),
    mCurTime(0.0f),
    mStartFrame(-1),
    mEndFrame(-1),
    mCurFrame(-1),
    mIsLoop(true)
{
}

MyRendererAnimation::Animation::~Animation()
{
}


void MyRendererAnimation::Animation::Update()
{
    // 0.1
    mCurTime -= MyTimer::FDeltaTime();

    if (0 >= mCurTime)
    {
        // 0.1f
        mCurTime = mFrameTime;
        ++mCurFrame;

        if (mCurFrame > mEndFrame)
        {
            if (true == mIsLoop)
            {
                mCurFrame = mStartFrame;

            }
            else
            {
                --mCurFrame;
            }
        }

    }

}
void MyRendererAnimation::Animation::Reset()
{
    // �Ųٷ� �����°� �˾Ƽ��غ��ô�.
    mCurTime = mFrameTime;
    mCurFrame = mStartFrame;
}


// Static Var
// Static Func

// member Var
MyRendererAnimation::MyRendererAnimation()
{
    mRenderingType = RENDERINGMODE::TRANS;
}

MyRendererAnimation::~MyRendererAnimation()
{

}
// member Func

MyRendererAnimation::Animation* MyRendererAnimation::FindAnimation(const Mystring& _Name)
{
    if (mAnimation.end() == mAnimation.find(_Name))
    {
        return nullptr;
    }

    return &mAnimation[_Name];
}

void MyRendererAnimation::CreateAnimation(const Mystring& _AniName, const Mystring& _ImageName,float4 _Scale, int _Start, int _End, float _FrameTime /*= 0.1f*/, bool _Loop /*= true*/)
{
    
    
    MyWinImage* FindImage = MyResMgr::Inst().FindImage(_ImageName);

    if (nullptr == FindImage)
    {
        MyDebug::AssertMsg("if (nullptr == FindImage)");
    }

    // FindImage->GetCutData();

    if (0 >= FindImage->GetCutSize())
    {
        MyDebug::AssertMsg("if (0 >= FindImage->GetCutSize())");
    }

    // ���� �̷��� ���ھ�?
    // ����ڵ带 ����� �ȵȴ�.

    if (0 > _Start ||
        0 > _End ||
        _Start >= FindImage->GetCutSize() ||
        _End >= FindImage->GetCutSize() ||
        _End < _Start)
    {
        MyDebug::AssertMsg("_Start And _End Error");
    }

    if (nullptr != FindAnimation(_AniName))
    {
        MyDebug::AssertMsg("_Start And _End Error");
    }

    // �ִϸ��̼��� ����� ������
    // Insert�� find�� �Ѳ����� �Ѵ�.
    // �������� ����ϸ� ������
    // m_Animation[_AniName]
    Animation& NewAni = mAnimation[_AniName];

    NewAni.mImage = FindImage;
    NewAni.mEndFrame = _End;
    NewAni.mStartFrame = _Start;
    NewAni.mFrameTime = _FrameTime;
    NewAni.mIsLoop = _Loop;
    NewAni.mScale= _Scale;
    NewAni.Reset();
}

void MyRendererAnimation::ChangeAnimation(const Mystring& _Name)
{

    mCurAnimation = FindAnimation(_Name);
    mCurAnimation->Reset();

    SetRenderScale(mCurAnimation->mScale);
    if (nullptr == mCurAnimation)
    {
       MyDebug::AssertMsg("if (nullptr == m_CurAnimation)");
    }
}

void MyRendererAnimation::Render()
{
    if (nullptr == mCurAnimation)
    {
        MyDebug::AssertMsg("if (nullptr == m_CurAnimation)");
    }

    // �̳༮�� 
    mCurAnimation->Update();

    const CutData& _Data = mCurAnimation->mImage->GetCutData(mCurAnimation->mCurFrame);
 
    float4 RenderPos = GetActor()->GetPosition() + mPivotPos - MyCamera::GetCamPos();
    MyWindow::GetBackBufferImage().TransparentBltCenter(RenderPos, mRenderScale, *mCurAnimation->mImage, _Data.mPos, _Data.mSize);


    mCutPos = _Data.mPos;
    mCutSize = _Data.mSize;
    RenderImage(mCurAnimation->mImage);


}



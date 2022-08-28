#pragma once
#include <MyObjectBase.h>
#include <MyMath.h>
#include <Mystring.h>

enum class RENDERINGMODE
{
    BIT,
    TRANS,
    ALPHA,
    ROT, // 회전도 가능합니다.
    MAX, // 회전도 가능합니다.
};
// 분류 : 렌더링
// 용도 : 리소스
// 설명 : 렌더링하는 객체들의 공통된 부모. 렌더러들이 가지는 공통된 데이터를 상속시켜준다.
class MyWinImage;
class MyActor;
class MyRenderer : public MyObjectBase
{
private: // Static Var
public: // Static Func
protected: // member Var
    RENDERINGMODE mRenderingType;
    int mOrder;
    // 자신을 가진 액터를 안다.
    MyActor* mActor;
    // 랜더링을 하는 클래스는 모두 사이즈가 있어야 한다.
    float4 mRenderScale;
    float4 mPivotPos;
    float4 mCutPos;
    float4 mCutSize;


    unsigned char mAlpha;

public:
    void SetAlpha(unsigned char _Alpha)
    {
        mAlpha = _Alpha;

        if (255 > _Alpha)
        {
            mRenderingType = RENDERINGMODE::ALPHA;
        }
    }


    float4 GetPivotPos() {
        return mPivotPos;
    }

    void SetPivotPos(float4 _PivotPos) {
        mPivotPos = _PivotPos;
    }

    float4 GetRenderScale() {
        return mRenderScale;
    }

    void SetRenderScale(float4 _RenderScale) {
        mRenderScale = _RenderScale;
    }

 

public:
    void SetOrder(int _Order)
    {
        mOrder = _Order;
    }

    int GetOrder()
    {
        return mOrder;
    }

    void SetActor(MyActor* _Actor)
    {
       
        mActor = _Actor;
    }

    MyActor* GetActor()
    {
        return mActor;
    }
    float4 GetRendererPos();
    
private:
    bool mIsCamEffect;

public:
    // 캠에 영향 받는지 안받는지.
    void CamEffectOff()
    {
        mIsCamEffect = false;
    }

public:
    float4 CamRenderPos();

public: // constructer destructer
    MyRenderer();
    virtual ~MyRenderer();

public: // delete constructer 
    MyRenderer(const MyRenderer& _Other) = delete;
    MyRenderer(const MyRenderer&& _Other) = delete;

public: // delete operator
    MyRenderer& operator=(const MyRenderer& _Other) = delete;
    MyRenderer& operator=(const MyRenderer&& _Other) = delete;

public: // member Func
    void RenderImage(MyWinImage* _Image);
    virtual void Render() = 0;
};


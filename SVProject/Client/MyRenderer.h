#pragma once
#include <MyObjectBase.h>
#include <MyMath.h>
#include <Mystring.h>

enum class RENDERINGMODE
{
    BIT,
    TRANS,
    ALPHA,
    ROT, // ȸ���� �����մϴ�.
    MAX, // ȸ���� �����մϴ�.
};
// �з� : ������
// �뵵 : ���ҽ�
// ���� : �������ϴ� ��ü���� ����� �θ�. ���������� ������ ����� �����͸� ��ӽ����ش�.
class MyWinImage;
class MyActor;
class MyRenderer : public MyObjectBase
{
private: // Static Var
public: // Static Func
protected: // member Var
    RENDERINGMODE mRenderingType;
    int mOrder;
    // �ڽ��� ���� ���͸� �ȴ�.
    MyActor* mActor;
    // �������� �ϴ� Ŭ������ ��� ����� �־�� �Ѵ�.
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
    // ķ�� ���� �޴��� �ȹ޴���.
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


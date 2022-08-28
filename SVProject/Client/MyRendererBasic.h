#pragma once
#include "MyRenderer.h"
#include <MyWinImage.h>
#include <MyDebug.h>

// 분류 : 
// 용도 : 
// 설명 : 

class MyRendererBasic : public MyRenderer
{
private: // Static Var
public: // Static Func
private: // member Var
   
    MyWinImage* mImage;
   

public:

    void SetCutData(int _Index)
    {
        if (nullptr == mImage)
        {
            MyDebug::AssertMsg("if (nullptr == m_Image)");
        }

        const CutData& Data = mImage->GetCutData(_Index);

        mCutPos = Data.mPos;
        mCutSize = Data.mSize;
    }

    void SetCutPosAndSize(const float4& _Pos, const float4& _Size)
    {
        mCutPos = _Pos;
        mCutSize = _Size;
    }

    MyWinImage* GetImage() { return mImage; }

    float4 GetCutPos()
    {
        return mCutPos;
    }
    void SetCutPos(const float4& _Pos)
    {
        mCutPos = _Pos;
    }

    float4 GetCutSize()
    {
        return mCutSize;
    }
    void SetCutSize(const float4& _Size)
    {
        mCutSize = _Size;
    }

    // Trans
public:
    void TransSetting(const Mystring& _Image, float4 _Scale, float4 _PivotPos = float4{ 0,0 });
    void BitSetting(const Mystring& _Image, float4 _Scale, float4 _PivotPos = float4{ 0,0 });
    

public: // constructer destructer
    MyRendererBasic();
    ~MyRendererBasic();

public: // delete constructer 
    MyRendererBasic(const MyRendererBasic& _Other) = delete;
    MyRendererBasic(const MyRendererBasic&& _Other) = delete;

public: // delete operator
    MyRendererBasic& operator=(const MyRendererBasic& _Other) = delete;
    MyRendererBasic& operator=(const MyRendererBasic&& _Other) = delete;

public: // member Func
    // 구현하지 않으면
    // renderer의 자식이 아니다.
    void Render() override;
};


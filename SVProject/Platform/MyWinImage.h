#pragma once
#include <Windows.h>
#include <MyMath.h>
#include <Mystring.h>
//분류 : 렌더링
//용도 : 리소스
//설명 : 이미지에 관련된 여러 데이터를 관리하고 이미지를 렌더링 함.
class CutData
{
public:
    float4 mPos;
    float4 mSize;
};

class MyWinImage
{
private: //static variable
public:	//static func
private: //member var
    HDC mDC;
    BITMAP mBitMapInfo;
    HBITMAP mBitMap;
    HBITMAP mOldBitMap;
    float4 mSize;
    int TransColor;
    BLENDFUNCTION mBlend;

public:  
    void SetTransColor(int _Color)
    {
        TransColor = _Color;
    }

    unsigned long GetPixelColor(int _X, int _Y)
    {
        return  GetPixel(mDC, _X, _Y);
    }

private:
    
    std::vector<CutData> mCutData;

public:
    int GetCutSize() {
        return (int)mCutData.size();
    }
    
    const CutData& GetCutData(int _Index);
    void ImageCut(int _X, int _Y);


public:
    HDC ImageDC()
    {
        return mDC;
    }

public:	//constructor destructor
    MyWinImage();
    ~MyWinImage();


public: // delete constructer 
    MyWinImage(const MyWinImage& _Other) = delete;
    MyWinImage(const MyWinImage&& _Other) = delete;

public: // delete operator
    MyWinImage& operator=(const MyWinImage& _Other) = delete;
    MyWinImage& operator=(const MyWinImage&& _Other) = delete;


private:
    void ImageSizeCheck();

public: // member Func
    void Create(const Scale& _ImageScale);
    
    void Create(HDC _DC);

public:
    
    void Load(const Mystring& _LoadPath);

public:
    // 크기 조절 안됨
    // 투명 안됨.
    void BitBlt(MyWinImage& _OtherImage);
    void BitBlt(float4 _Pos, MyWinImage& _OtherImage);
    void BitBltCenter(float4 _Pos, MyWinImage& _OtherImage);


public:   

    void TransparentBltCenter(const float4& _Pos, const float4& _Size, MyWinImage& _OtherImage, const float4& _CutPos, const float4& _CutSize);
    void TransparentBlt(const float4& _Pos, const float4& _Size, MyWinImage& _OtherImage, const float4& _CutPos, const float4& _CutSize);


public:    // 알파 조절

    void AlphaBltCenter(const float4& _Pos, const float4& _Size, MyWinImage& _OtherImage, const float4& _CutPos, const float4& _CutSize, BYTE _Alpha);
};






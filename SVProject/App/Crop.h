#pragma once
#include<MyActor.h>
#include <Mystring.h>
#include<MyRendererTile.h>

//분류 :
//용도 :
//설명 :




class MyRendererBasic;
class Crop : public MyActor
{
private: //static variable
public:	//static func
private: //member var
    
public:	//constructor destructor
    Crop();
    virtual ~Crop();

public:
    int MinIndex;
    int MaxIndex;
    int Curlevel;
    ITEMINDEX cropitemindex;
   
    // 자라는 시간
    float CurTime;
    float Time;

    MyRendererBasic* Renderer;
    MyRendererTile::Tile* mTile;
    
public: // delete constructer 
    Crop(const Crop& _Other) = delete;
    Crop(const Crop&& _Other) = delete;

public: // delete operator
    Crop& operator=(const Crop& _Other) = delete;
    Crop& operator=(const Crop&& _Other) = delete;
   

public: // member func
    void Update() override;
    void SetTile(MyRendererTile::Tile* _tile) { mTile = _tile; }
    void Grow() { Curlevel++; }
    void CropImage(const Mystring& _Str, float _Time, float4 _Scale, int _Start, int _End, float4 _Pivotpos = 0);

};




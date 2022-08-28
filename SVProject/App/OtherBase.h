#pragma once
#include<MyActor.h>
#include<Mystring.h>
#include<MyRendererTile.h>
//분류 :
//용도 :
//설명 :
class MyRendererBasic;

class OtherBase : public MyActor
{
private: //static variable
public:	//static func
private: //member var
    MyRendererBasic* Renderer;
    MyRendererTile::Tile* mTile;
   
public:	//constructor destructor
    OtherBase();
    virtual ~OtherBase();


public: // delete constructer 
    OtherBase(const OtherBase& _Other) = delete;
    OtherBase(const OtherBase&& _Other) = delete;

public: // delete operator
    OtherBase& operator=(const OtherBase& _Other) = delete;
    OtherBase& operator=(const OtherBase&& _Other) = delete;

public: // member func
    void SetTile(MyRendererTile::Tile* _tile) { mTile = _tile; }
    void Update() override;
    void OtherImage(const Mystring& _Str, float4 _Scale);
};




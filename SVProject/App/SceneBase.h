#pragma once
#include<MyScene.h>
#include<Mystring.h>
//분류 :
//용도 :
//설명 :
enum class TILEVAR
{
    GRASS1,
    GRASS2,
    GRASS3,
    GRASS4,
    STONE1,
    STONE2,
    TREE,
    NONE
};


class SceneBase : public MyScene
{
    
private: //static variable
    
public:	//static func
private: //member var
    float4 MapSize;

    Mystring ColMapName;
public:	//constructor destructor
    SceneBase();
    ~SceneBase();


public: // delete constructer 
    SceneBase(const SceneBase& _Other) = delete;
    SceneBase(const SceneBase&& _Other) = delete;

public: // delete operator
    SceneBase& operator=(const SceneBase& _Other) = delete;
    SceneBase& operator=(const SceneBase&& _Other) = delete;

public: // member func
    const Mystring& GetColMapName() { return ColMapName; }
    void SetColMap(const Mystring& _Name) { ColMapName = _Name; }
    void  SetMapSize(float4 _Size) { MapSize = _Size; }
    float4 GetMapSize() { return MapSize; }
};




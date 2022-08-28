#pragma once
#include <MyActor.h>

// �з� : 
// �뵵 : 
// ���� : 
class MyRendererTile;
class MyTileBackGround : public MyActor
{
private: // Static Var
public: // Static Func
private: // member Var

public:
    MyRendererTile* TileRenderer;

public: // constructer destructer
    MyTileBackGround();
    ~MyTileBackGround();

public: // delete constructer 
    MyTileBackGround(const MyTileBackGround& _Other) = delete;
    MyTileBackGround(const MyTileBackGround&& _Other) = delete;

public: // delete operator
    MyTileBackGround& operator=(const MyTileBackGround& _Other) = delete;
    MyTileBackGround& operator=(const MyTileBackGround&& _Other) = delete;

public: // member Func
    void Start() override; // ����.

};


#pragma once
#include <MyScene.h>

// 분류 : 
// 용도 : 
// 설명 : 
class MyTileBackGround;
class MyPlayer;
class MyPlayTestScene : public MyScene
{
private: // Static Var
public: // Static Func
private: // member Var
    MyTileBackGround* TileBackGround;
    MyPlayer* Player;
public: // constructer destructer
    MyPlayTestScene();
    ~MyPlayTestScene();

public: // delete constructer 
    MyPlayTestScene(const MyPlayTestScene& _Other) = delete;
    MyPlayTestScene(const MyPlayTestScene&& _Other) = delete;

public: // delete operator
    MyPlayTestScene& operator=(const MyPlayTestScene& _Other) = delete;
    MyPlayTestScene& operator=(const MyPlayTestScene&& _Other) = delete;

public: // member Func
    void Start() override;
    void SceneUpdate() override;
};
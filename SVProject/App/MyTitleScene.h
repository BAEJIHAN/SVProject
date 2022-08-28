#pragma once
#include "SceneBase.h"
//분류 :
//용도 :
//설명 :
class TitleBackGround;
class cloud1;
class cloud2;
class MyTitleScene : public SceneBase
{
private: //static variable
public:	//static func
private: //member var
    TitleBackGround* title;
    cloud1* Cloud1;
    cloud2* Cloud2;
public:	//constructor destructor
    MyTitleScene();
    ~MyTitleScene();


public: // delete constructer 
    MyTitleScene(const MyTitleScene& _Other) = delete;
    MyTitleScene(const MyTitleScene&& _Other) = delete;

public: // delete operator
    MyTitleScene& operator=(const MyTitleScene& _Other) = delete;
    MyTitleScene& operator=(const MyTitleScene&& _Other) = delete;

public: // member func
    void SceneUpdate() override;
    void Start() override;
};




#pragma once
#include "SceneBase.h"
#include <MyTimeEventer.h>
//분류 :
//용도 :
//설명 :
class TownBg;
class MyPlayer;
class FadeInActor;
class FadeOutActor;
class TownColmapImage;

class TownScene :public SceneBase
{
private: //static variable
public:	//static func
private: //member var
    TownBg* BackGround;
    MyPlayer* Player;
    TownColmapImage* colmapimage;

    FadeInActor* FadeIn;
    FadeOutActor* FadeOut;

    MyTimeEventer<TownScene> SceneOutEvent;
    MyTimeEventer<TownScene> SceneInEvent;
public:	//constructor destructor
    TownScene();
    ~TownScene();


public: // delete constructer 
    TownScene(const TownScene& _Other) = delete;
    TownScene(const TownScene&& _Other) = delete;

public: // delete operator
    TownScene& operator=(const TownScene& _Other) = delete;
    TownScene& operator=(const TownScene&& _Other) = delete;

public: // member func

    MyPlayer* GetPlayer() { return Player; }
    void Start() override;
    void SceneUpdate() override;
    void SceneChangeStart() override;


    void SceneInStart();
    void SceneInStay();
    void SceneInEnd();

    void SceneOutStart();
    void SceneOutStay();
    void SceneOutEnd();
};




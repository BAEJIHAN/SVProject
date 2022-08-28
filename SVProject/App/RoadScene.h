#pragma once
#include "SceneBase.h"
#include <MyTimeEventer.h>
//분류 :
//용도 :
//설명 :
class RoadBg;
class MyPlayer;
class FadeInActor;
class FadeOutActor;
class RoadColmapImage;

class RoadScene :public SceneBase
{
private: //static variable
public:	//static func
private: //member var
    RoadBg* BackGround;
    MyPlayer* Player;
    RoadColmapImage* colmapimage;

    FadeInActor* FadeIn;
    FadeOutActor* FadeOut;

    MyTimeEventer<RoadScene> SceneOutEvent;
    MyTimeEventer<RoadScene> SceneInEvent;
public:	//constructor destructor
    RoadScene();
    ~RoadScene();


public: // delete constructer 
    RoadScene(const RoadScene& _Other) = delete;
    RoadScene(const RoadScene&& _Other) = delete;

public: // delete operator
    RoadScene& operator=(const RoadScene& _Other) = delete;
    RoadScene& operator=(const RoadScene&& _Other) = delete;

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




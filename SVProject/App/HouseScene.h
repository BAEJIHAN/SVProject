#pragma once
#include "SceneBase.h"
#include <MyTimeEventer.h>

//분류 :
//용도 :
//설명 :
class HouseBg;
class MyPlayer;
class FadeInActor;
class FadeOutActor;
class HouseColmapImage;
class HouseScene :public SceneBase
{
private: //static variable
public:	//static func
private: //member var
	HouseBg* BackGround;
    HouseColmapImage* colmapimage;

    MyPlayer* Player;

    FadeInActor* FadeIn;
    FadeOutActor* FadeOut;

    bool IsFirst;
	MyTimeEventer<HouseScene> SceneOutEvent;
	MyTimeEventer<HouseScene> SceneInEvent;
public:	//constructor destructor
	HouseScene();
	~HouseScene();


public: // delete constructer 
    HouseScene(const HouseScene& _Other) = delete;
    HouseScene(const HouseScene&& _Other) = delete;

public: // delete operator
    HouseScene& operator=(const HouseScene& _Other) = delete;
    HouseScene& operator=(const HouseScene&& _Other) = delete;

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




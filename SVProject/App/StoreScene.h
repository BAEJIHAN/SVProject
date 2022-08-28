#pragma once
#include "SceneBase.h"
#include <MyTimeEventer.h>
//분류 :
//용도 :
//설명 :
class StoreBg;
class MyPlayer;
class FadeInActor;
class FadeOutActor;
class ToolUI;
class Inventory;
class StoreList;
class StoreColmapImage;

class StoreScene :public SceneBase
{
private: //static variable
public:	//static func
private: //member var
    StoreBg* BackGround;
    MyPlayer* Player;
    StoreColmapImage* colmapimage;

    ToolUI* mToolUI;
    Inventory* Inven;
    StoreList* storelist;
    FadeInActor* FadeIn;
    FadeOutActor* FadeOut;

    MyTimeEventer<StoreScene> SceneOutEvent;
    MyTimeEventer<StoreScene> SceneInEvent;
public:	//constructor destructor
    StoreScene();
    ~StoreScene();


public: // delete constructer 
    StoreScene(const StoreScene& _Other) = delete;
    StoreScene(const StoreScene&& _Other) = delete;

public: // delete operator
    StoreScene& operator=(const StoreScene& _Other) = delete;
    StoreScene& operator=(const StoreScene&& _Other) = delete;

public: // member func
    MyPlayer* GetPlayer() { return Player; }
    Inventory* GetInven() { return Inven; }
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

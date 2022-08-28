#pragma once
#include"SceneBase.h"
#include <MyTimeEventer.h>
#include <MySound.h>
//분류 :
//용도 :
//설명 :
class FarmBg;
class MyPlayer;
class FadeInActor;
class FadeOutActor;
class MyTileBackGround;
class OtherBase;
class ToolUI;
class Inventory;
class Selected;
class BagUI;
class EnergyUI;
class FarmColmapImage;
class FarmScene :public SceneBase
{
    friend MyPlayer;
private: //static variable
public:	//static func
private: //member var

    static SoundPlayer bgm;
    FarmColmapImage* colmapimage;
    FarmBg* BackGround;
    
   
   
    MyPlayer* Player;

    EnergyUI* energy;
    ToolUI* mToolUI;
    Inventory* Inven;
    BagUI* bag;

    FadeInActor* FadeIn;
    FadeOutActor* FadeOut;

    MyTimeEventer<FarmScene> SceneOutEvent;
    MyTimeEventer<FarmScene> SceneInEvent;
public:	//constructor destructor
    FarmScene();
    ~FarmScene();


public: // delete constructer 
    FarmScene(const FarmScene& _Other) = delete;
    FarmScene(const FarmScene&& _Other) = delete;

public: // delete operator
    FarmScene& operator=(const FarmScene& _Other) = delete;
    FarmScene& operator=(const FarmScene&& _Other) = delete;

public: // member func

    void PlantCrop();

    MyTileBackGround* TileBackGround;
    Selected* selected;
    BagUI* GetBag() { return bag; }
    MyPlayer* GetPlayer() { return Player; }
    EnergyUI* GetEnergy() { return energy; }
    Inventory* GetInven() { return Inven; }
    void MakeObject(float4 _TilePos, TILEVAR _tilevar, OtherBase* _obj);
    void LoadTile();

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




#pragma once
#include<MyActor.h>
#include<MyFSM.h>
#include<MySound.h>
//분류 :
//용도 :
//설명 :


class MySound;
class MyRendererBasic;
class MyRendererAnimation;
class MyCollision;


enum DIR
{
    LEFT,
    RIGHT,
    UP,
    DOWN,
    MAX,
};

enum class MAP
{
    NONE,
    HOUSE,
    FARM,
    ROAD,
    TOWN,
    STORE
};

enum  ACTION
{
    HOE,
    AXE,
    PICK,
    SICKLE,
    WATERING,
    POTATO,
    RADISH,
    CABBAGE,
    TOMATO,
    EGGPLANT,
    BLUEBERRY,
    NONE
};

class MyPlayer : public MyActor
{
private: //static variable
public:	//static func
private: //member var
    float4 MovePos;
    float Speed;
    MyRendererAnimation* AniRenderer;           
    MyFSM<MyPlayer> PlayerFsm;
    ACTION mAction;
    Mystring CurAniName;
    DIR Dir;
    DIR PrevDir;
  
    MAP CurMap;


    bool bOnMove;
    int CheckColor;
    
    MyCollision* pcol;
    bool bDebugOn;

    float MaxActionTime;
    float CurActionTime;

    float MoveTime;

    int Energy;
    int UsingEnergy;
    static SoundPlayer walksound;

public:	//constructor destructor
    MyPlayer();
    ~MyPlayer();


public: // delete constructer 
    MyPlayer(const MyPlayer& _Other) = delete;
    MyPlayer(const MyPlayer&& _Other) = delete;

public: // delete operator
    MyPlayer& operator=(const MyPlayer& _Other) = delete;
    MyPlayer& operator=(const MyPlayer&& _Other) = delete;

public: // member func
    int GetEnergy() { return Energy; }
    void SetCurMap(MAP _map) { CurMap = _map; }
    void ZeroEnergy()
    {
        Energy =0;
        
    }

    void AddEnergy()
    {
        Energy += 30;
        if (100 <= Energy)
        {
            Energy = 100;
        }
    }
    void Start() override;
    void Update() override; 
    void DebugRender() override;
    void SetDebugOnOff(bool _b) { bDebugOn = _b; }
    bool IsDebugOn() { return bDebugOn; }
    
    void KeyCheck();
    void ChangeAnimation(const Mystring& _Str);
    
    //CROP GetCrop() { return mCrop; }
    ACTION GetAction() { return mAction; }
    void SetDir(DIR _dir) { Dir = _dir; }
    void SetAction(ACTION _action) { mAction = _action; }
public:
 
    void SetMoveOn(bool _on) { bOnMove = _on; }

    void IDLEStart();
    void IDLEStay();
    void MOVEStart();
    void MOVEStay();
    void MOVEEnd();
    void ACTIONStart();
    void ACTIONStay();
   

};




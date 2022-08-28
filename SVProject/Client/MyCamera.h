#pragma once
#include"MyActor.h"
#include"MyScene.h"
//분류 :
//용도 :
//설명 :
class MyActor;
class MyCamera
{
private: //static variable
public:	//static func
private: //member var
    static float4	CamPos;
    static MyActor* Target;
    static float	Speed;
    static MyScene* CurScene;  
    static float4 Pivot;

public:	//constructor destructor
    MyCamera();
    ~MyCamera();


public: // delete constructer 
    MyCamera(const MyCamera& _Other) = delete;
    MyCamera(const MyCamera&& _Other) = delete;

public: // delete operator
    MyCamera& operator=(const MyCamera& _Other) = delete;
    MyCamera& operator=(const MyCamera&& _Other) = delete;

public:
    static void Update();
    static void SetCurScene(MyScene* _Scene) { CurScene = _Scene; }
    static MyScene* GetCurScne() { return CurScene; }

private:
    static void MoveCamera();

public:
    static float4 GetCamPos(){ return CamPos; }
    static void SetPosiotion(float4 _Position) { CamPos = _Position; }
    static void SetTarget(MyActor* _Target) { Target = _Target; }
    static MyActor* GetTarget() { return Target; }
    static void CamMove(float4 _pos);
    static void SetCamPos(float4 _pos);
    static void Start();
    

   
};




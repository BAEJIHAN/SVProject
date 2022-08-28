#pragma once
#include <MyMath.h>
#include <list>
#include "MyScene.h"
#include <MyObjectBase.h>

class MyScene;
class MyRenderer;
class MyCollision;
class MyRendererBasic;
class ItemInfo
{
public:
    ITEMTYPE itemtype;
    ITEMINDEX itemindex;
    int amount;


    MyRendererBasic* Renderer;
};
//분류 : 오브젝트
//용도 : 업데이터
//설명 : 실질적으로 움직이는 객체들의 부모. 단독으로는 쓰지 않고 실직적인 액터들에게 상속해서 쓴다.

class MyActor : public MyObjectBase
{
    friend MyScene;
private: //static variable
   
public:	//static func
public: //member var
    MyScene* mScene;
    float4 mPosition;
public:	//constructor destructor
    MyScene* GetScene() {
        return mScene;
    }

    void SetScene(MyScene* _Scene)
    {
        mScene = _Scene;
    }

public:
    float4 GetCamPosition() {
        return mPosition - mScene->GetCamPos();
    }

    float4 GetPosition() {
        return mPosition;
    }

    void SetPosition(const float4& _Other)
    {
        mPosition = _Other;
    }

    void MovePosition(const float4& _Other)
    {
        mPosition += _Other;
    }
public:
    std::list<MyRenderer*> mRenderer;
    
public:

    template<typename T>
    T* CreateRenderer(int _Order /*= 0*/)
    {
        T* NewT = new T();
        // 오더 세팅 받고
        NewT->SetOrder(_Order);
        NewT->SetParentBase(this);
        // 액터도 세팅받고
        NewT->SetActor(this);
        mRenderer.push_back(NewT);
        mScene->PushRenderer(NewT);
        return NewT;
    }
    template<typename T>
    T* CreateRenderer(RENDERINDEX _Order /*= 0*/)
    {
        T* NewT = new T();
        // 오더 세팅 받고
        NewT->SetOrder((int)_Order);
        NewT->SetParentBase(this);
        // 액터도 세팅받고
        NewT->SetActor(this);
        mRenderer.push_back(NewT);
        mScene->PushRenderer(NewT);
        return NewT;
    }

public:
    std::list<MyCollision*> mCollision;

public:

    template<typename T>
    T* CreateCollision(int _Order /*= 0*/)
    {
        T* NewT = new T();
        NewT->SetOrder(_Order);
        NewT->SetActor(this);
        NewT->SetParentBase(this);
        mCollision.push_back(NewT);
        mScene->PushCollision(NewT);
        return NewT;
    }

    template<typename T>
    T* CreateCollision(COLINDEX _Order /*= 0*/)
    {
        T* NewT = new T();
        NewT->SetOrder((int)_Order);
        NewT->SetActor(this);
        NewT->SetParentBase(this);
        mCollision.push_back(NewT);
        mScene->PushCollision(NewT);
        return NewT;
    }

    MyActor();
    virtual ~MyActor();


public: // delete constructer 
    MyActor(const MyActor& _Other) = delete;
    MyActor(const MyActor&& _Other) = delete;

public: // delete operator
    MyActor& operator=(const MyActor& _Other) = delete;
    MyActor& operator=(const MyActor&& _Other) = delete;

public: // member func
    virtual void Start(); // 시작한다.
    virtual void Update(); // 돈다.
    virtual void DebugRender();
    virtual void Release(); // 돈다.
};




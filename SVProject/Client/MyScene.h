#pragma once
#include <MyBasePublic.h>
#include <MyPlatformPublic.h>
#include<list>
#include<map>
#include "MyCollision.h"
#include <set>

//분류 : 렌더링
//용도 : 업데이터
//설명 : 씬과 그 씬 안에 있는 액터들을 관리한다.

//class SizeScene 
//{
//};

class MyCollision;
class MyRenderer;
class MyActor;



class MyScene
{
private: //static variable
public:	//static func
private: //member var
    std::list<MyActor*> mActors;
    float4 CamPos;
    // 약간 게임에 영향을 받는 느낌이라.


public:
    float4 GetCamPos() {
        return CamPos;
    }

    void SetCamPos(const float4& _CamPos)
    {
        CamPos = _CamPos;
    }

    void SetCamMove(const float4& _CamPos)
    {
        CamPos += _CamPos;
    }
public:	
    template<typename ActorType>
    ActorType* CreateActor()
    {
        ActorType* NewActor = new ActorType();

        NewActor->SetScene(this);
        NewActor->Start();

        mActors.push_back(NewActor);

        return NewActor;
    }
    

public://constructor destructor
    MyScene();
    virtual ~MyScene();


public: // delete constructer 
    MyScene(const MyScene& _Other) = delete;
    MyScene(const MyScene&& _Other) = delete;

public: // delete operator
    MyScene& operator=(const MyScene& _Other) = delete;
    MyScene& operator=(const MyScene&& _Other) = delete;

public: // member func
    virtual void Start() {}
    void Progress();

    /////////////////////////////////////////////////////////////// Rendering
    // 랜더링 해주는 역할은 씬이 할거에요.
    // 액터에게 빌려서
private:
    std::map<int, std::list<MyRenderer*>> mRendererLists;

public:
    void PushRenderer(MyRenderer* _Renderer);

private:
    void Render();

private:
    //  Monster그룹
    //  Player그룹
    std::map<int, std::list<MyCollision*>> mCollisionLists;

    //        0    1
    // 0번그룹과 1번그룹이 충돌한다.
    // 0   2번이 충돌한다.
    // set == value없는 맵
    // set ->second가 없어요
    // 오로지 어떤값을 찾는데만 특수화된 녀석입니다.
    //      0      1, 1, 1, 1, 1, 1, 1, 1
    std::map<int, std::set<int>> mLinkCollsionGroup;

public:
    void CollisionGroupLink(int _Left, int _Right)
    {
        // 맵을 곧바로 이렇게 사용하면
        // INSERT와 FIND까지 다하고 거기에 return second가 까지
        // m_LinkCollsionGroup[_Left]
        // std::set<int> 

        // 그룹이 있다면 만들어버리면서
        if (mLinkCollsionGroup[_Left].end() != mLinkCollsionGroup[_Left].find(_Right))
        {
            return;
        }

        // 없으면 추가
        mLinkCollsionGroup[_Left].insert(_Right);
    }


    void CollisionGroupLink(COLINDEX _Left, COLINDEX _Right)
    {
        int left = (int)_Left;
        int right = (int)_Right;
        if (mLinkCollsionGroup[left].end() != mLinkCollsionGroup[left].find(right))
        {
            return;
        }

      
        mLinkCollsionGroup[left].insert(right);
    }
  
public:
    void PushCollision(MyCollision* _Renderer);

private:
    void CollisionProcess();
    void CollisionGroupOtherCheck(int _Left, int _Right);
    void CollisionGroupThisCheck(int _Value);



public:
    void Release();

    ///////////////////////////////////////////// LogicUpdate
public:
    virtual void SceneChangeStart() {}
    virtual void SceneChangeEnd() {}
    virtual void SceneUpdate() {}
    virtual void SceneDebugRender() {}

    virtual float4 GetMapSize() { return 0; }
    virtual void SetScene() {}
};




//class SizeScene 
//{
//public:
//    float4 Size;
//};
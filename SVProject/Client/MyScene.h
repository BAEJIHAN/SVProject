#pragma once
#include <MyBasePublic.h>
#include <MyPlatformPublic.h>
#include<list>
#include<map>
#include "MyCollision.h"
#include <set>

//�з� : ������
//�뵵 : ��������
//���� : ���� �� �� �ȿ� �ִ� ���͵��� �����Ѵ�.

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
    // �ణ ���ӿ� ������ �޴� �����̶�.


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
    // ������ ���ִ� ������ ���� �Ұſ���.
    // ���Ϳ��� ������
private:
    std::map<int, std::list<MyRenderer*>> mRendererLists;

public:
    void PushRenderer(MyRenderer* _Renderer);

private:
    void Render();

private:
    //  Monster�׷�
    //  Player�׷�
    std::map<int, std::list<MyCollision*>> mCollisionLists;

    //        0    1
    // 0���׷�� 1���׷��� �浹�Ѵ�.
    // 0   2���� �浹�Ѵ�.
    // set == value���� ��
    // set ->second�� �����
    // ������ ����� ã�µ��� Ư��ȭ�� �༮�Դϴ�.
    //      0      1, 1, 1, 1, 1, 1, 1, 1
    std::map<int, std::set<int>> mLinkCollsionGroup;

public:
    void CollisionGroupLink(int _Left, int _Right)
    {
        // ���� ��ٷ� �̷��� ����ϸ�
        // INSERT�� FIND���� ���ϰ� �ű⿡ return second�� ����
        // m_LinkCollsionGroup[_Left]
        // std::set<int> 

        // �׷��� �ִٸ� ���������鼭
        if (mLinkCollsionGroup[_Left].end() != mLinkCollsionGroup[_Left].find(_Right))
        {
            return;
        }

        // ������ �߰�
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
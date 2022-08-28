#pragma once
// #include "GameEngineActor.h"

#include <MyObjectBase.h>
#include <MyMath.h>
#include <set>
#include <vector>


// Collision<Player> == Collision<Monster>

// 분류 : 
// 용도 : 
// 설명 : 
class MyActor;
class MyCollision : public MyObjectBase
{
private: // MemberVar
    COLTYPE mType;
    int mOrder;
    // 자신을 가진 액터를 안다.
    MyActor* mActor;
    float4 mPivotPos;
    Col2DData mData;

    // 동적할당된 자료형은 그 주소값 자체가
    // 유일무이한 키이다.
    std::set<MyCollision*> mColSet;


public: // constructer destructer
    MyCollision();
    ~MyCollision();


public:
    void SetPivotPos(float4 _Pos)
    {
        mPivotPos = _Pos;
    }

    void SetScale(float4 _Scale)
    {
        mData.Size = _Scale;
    }

    void SetOrder(int _Order)
    {
        mOrder = _Order;
    }

    int GetOrder()
    {
        return mOrder;
    }

    void SetActor(MyActor* _Actor)
    {
        // 선생님이 무슨 생각이 있었을거야.
        // 뭔생각 그냥 대놓고 실수한거죠.
        // 선생님이 무슨 생각이 있었을거야.
        // 심각해지면
        // 선생님이 설명해주지 않으면
        // 아무것도 안하려고 하는 습관이 들어버리면
        // 회사가서도 수동으로만 일하게 됩니다.

        // _Actor = m_Actor;
        mActor = _Actor;
    }

    MyActor* GetActor()
    {
        return mActor;
    }

public: // delete constructer 
    MyCollision(const MyCollision& _Other) = delete;
    MyCollision(const MyCollision&& _Other) = delete;

public: // delete operator
    MyCollision& operator=(const MyCollision& _Other) = delete;
    MyCollision& operator=(const MyCollision&& _Other) = delete;

public: // MemberFunc
    void CollisionDataUpdate();
    void CollisionCheck(MyCollision* _Other);

    void ReleaseUpdate();

    void DeathTask() override;
    void OffTask() override;


private:
    class EventBase
    {
    public:
        virtual void CallBack(MyCollision* _This, MyCollision* _Other) {}
    };

    template<typename EventType>
    class EventBaseTemplate : public EventBase
    {
    public:
        EventType* mObj;
        void(EventType::* mStartFunc)(MyCollision* _This, MyCollision* _Other);

    public:
        void CallBack(MyCollision* _This, MyCollision* _Other) override
        {
            (mObj->*mStartFunc)(_This, _Other);
        }

    public:
        EventBaseTemplate(EventType* _Obj, void(EventType::* _StartFunc)(MyCollision* _This, MyCollision* _Other)) : mObj(_Obj), mStartFunc(_StartFunc)
        {

        }
    };

private:
    std::vector<EventBase*> StartEvent;
    std::vector<EventBase*> StayEvent;
    std::vector<EventBase*> EndEvent;

public:
    template<typename Target>
    void AddStartEvent(Target* _Obj, void(Target::* _StartFunc)(MyCollision* _This, MyCollision* _Other))
    {
        StartEvent.push_back(new EventBaseTemplate<Target>(_Obj, _StartFunc));
    }

    void UpdateStartEvent(MyCollision* _This, MyCollision* _Other)
    {
        mColSet.insert(_Other);

        for (size_t i = 0; i < StartEvent.size(); i++)
        {
            StartEvent[i]->CallBack(_This, _Other);
        }
    }

    template<typename Target>
    void AddStayEvent(Target* _Obj, void(Target::* _StartFunc)(MyCollision* _This, MyCollision* _Other))
    {
        StayEvent.push_back(new EventBaseTemplate<Target>(_Obj, _StartFunc));
    }

    void UpdateStayEvent(MyCollision* _This, MyCollision* _Other)
    {
        for (size_t i = 0; i < StayEvent.size(); i++)
        {
            StayEvent[i]->CallBack(_This, _Other);
        }
    }

    template<typename Target>
    void AddEndEvent(Target* _Obj, void(Target::* _StartFunc)(MyCollision* _This, MyCollision* _Other))
    {
        EndEvent.push_back(new EventBaseTemplate<Target>(_Obj, _StartFunc));
    }

    void UpdateEndEvent(MyCollision* _This, MyCollision* _Other)
    {
        for (size_t i = 0; i < EndEvent.size(); i++)
        {
            EndEvent[i]->CallBack(_This, _Other);
        }

        // 내거에서 빼야죠?
        mColSet.erase(_Other);
    }



};


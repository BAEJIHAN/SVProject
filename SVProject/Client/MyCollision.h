#pragma once
// #include "GameEngineActor.h"

#include <MyObjectBase.h>
#include <MyMath.h>
#include <set>
#include <vector>


// Collision<Player> == Collision<Monster>

// �з� : 
// �뵵 : 
// ���� : 
class MyActor;
class MyCollision : public MyObjectBase
{
private: // MemberVar
    COLTYPE mType;
    int mOrder;
    // �ڽ��� ���� ���͸� �ȴ�.
    MyActor* mActor;
    float4 mPivotPos;
    Col2DData mData;

    // �����Ҵ�� �ڷ����� �� �ּҰ� ��ü��
    // ���Ϲ����� Ű�̴�.
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
        // �������� ���� ������ �־����ž�.
        // ������ �׳� ����� �Ǽ��Ѱ���.
        // �������� ���� ������ �־����ž�.
        // �ɰ�������
        // �������� ���������� ������
        // �ƹ��͵� ���Ϸ��� �ϴ� ������ ��������
        // ȸ�簡���� �������θ� ���ϰ� �˴ϴ�.

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

        // ���ſ��� ������?
        mColSet.erase(_Other);
    }



};


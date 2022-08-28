#pragma once

// 분류 : 
// 용도 : 
// 설명 : 생명주기가 있거나 업데이트가 있는 클래스들에 기본적인 기능제공.
class MyObjectBase
{
private: // MemberVar
    // 이걸 어떻게 사용할지는?
    // 이걸 사용하는 사람들이 처리해줘야 겠죠.
    bool mIsOn;
    bool mIsDead;

    // Renderer가 이걸 상속받았다고 칠께요.
    // Actor안에 들어있죠?
    // Actor가 꺼지면 랜더러는 꺼져야 하나요 안꺼져야 하나요?
    MyObjectBase* mParent;

public:
    MyObjectBase* GetParentBase()
    {
        return mParent;
    }

    void SetParentBase(MyObjectBase* _Parent)
    {
        mParent = _Parent;
    }

public:
    bool IsOn()
    {
        if (nullptr == mParent)
        {
            return mIsOn && (false == mIsDead);
        }

        return (mIsOn && (false == mIsDead)) && mParent->IsOn();
        
    }

    void On()
    {

        if (false == mIsOn)
        {
            OnTask();
        }

        mIsOn = true;

    }

    void Off()
    {
        if (true == mIsOn)
        {
            OffTask();
        }

        mIsOn = false;
    }

    bool IsDeath()
    {
        if (nullptr == mParent)
        {
            return mIsDead;
        }

        return mIsDead || mParent->IsDeath();
    }

    void Death()
    {
        mIsDead = true;
    }

public:
    // 꺼졌다가 켜질때 할일
    virtual void OnTask() { }
    virtual void OffTask() { }
    // 완전히 파괴되기 직전에 뭔가 할일이 있다면 해라.
    virtual void DeathTask() { }

public: // constructer destructer
    MyObjectBase();
    virtual ~MyObjectBase();

public: // delete constructer 
    MyObjectBase(const MyObjectBase& _Other) = delete;
    MyObjectBase(const MyObjectBase&& _Other) = delete;

public: // delete operator
    MyObjectBase& operator=(const MyObjectBase& _Other) = delete;
    MyObjectBase& operator=(const MyObjectBase&& _Other) = delete;

public: // MemberFunc
};


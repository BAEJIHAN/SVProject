#pragma once

// �з� : 
// �뵵 : 
// ���� : �����ֱⰡ �ְų� ������Ʈ�� �ִ� Ŭ�����鿡 �⺻���� �������.
class MyObjectBase
{
private: // MemberVar
    // �̰� ��� ���������?
    // �̰� ����ϴ� ������� ó������� ����.
    bool mIsOn;
    bool mIsDead;

    // Renderer�� �̰� ��ӹ޾Ҵٰ� ĥ����.
    // Actor�ȿ� �������?
    // Actor�� ������ �������� ������ �ϳ��� �Ȳ����� �ϳ���?
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
    // �����ٰ� ������ ����
    virtual void OnTask() { }
    virtual void OffTask() { }
    // ������ �ı��Ǳ� ������ ���� ������ �ִٸ� �ض�.
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


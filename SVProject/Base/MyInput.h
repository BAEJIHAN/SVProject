#pragma once
#include <vector>
#include <map>
#include "MyString.h"
#include "MyDebug.h"
#include "MyMath.h"
// �⺻����
// �������� ���� Ŭ������ �з� �뵵 ������ �ڱⰡ �����ض�.
// �������ϰ����� ����

// �з� : �����
// �뵵 : ����
// ���� : Ű����� ���콺�� �Է� ó��
class MyInput
{
    // ��� Ű�� ����
public:
    // ��� ��ư(Ű���峪 ���콺��) 
    // ���Ȱų�
    // ������ �ְų�
    // ���ų�
    // �ȴ����� �ְų��� üũ�Ҽ� �־�� �Ѵ�.
    // ���� ���¸� ǥ���Ϸ��� �޸𸮸� ����ؼ�
    // Ŭ������ ���¸� ����� ���� �Ѵ�.
    // �ڽ��� ������� �ϴ� �༮�� �����ϰ� �׿� �ʿ��� ���¸� �� �����ϴ� ����
    // ���α׷����� �⺻ �Ҿ��̴�.

    class MyKey
    {
    public:
        std::vector<int> mKey;

        bool Down;
        bool Press;
        bool Up;
        bool Free;

    public:
        template<typename ... REST>
        void PushKey(int _Key, REST ... _Arg)
        {
            // �ҹ��ڶ�� ����?
            if ('a' <= _Key && 'z' >= _Key)
            {
                // �ҹ��ڸ� �빮�ڷ�.
                _Key = toupper(_Key);
            }

            mKey.push_back(_Key);
            PushKey(_Arg...);
        }

        void PushKey(int _Key)
        {
            if ('a' <= _Key && 'z' >= _Key)
            {
                // �ҹ��ڸ� �빮�ڷ�.
                _Key = toupper(_Key);
            }
            mKey.push_back(_Key);
        }

    public:
        bool KeyCheck();
        void Update();

    public:
        MyKey();
        ~MyKey();
    };

private: // Static Var
public: // Static Func
private: // member Var
    //               PlayerMoveLeftKey, 
    //               PlayerMoveRightKey, 
    static std::map<Mystring, MyKey> mKeyMap;

    // A�� B�� ���ÿ� ��������
    // 3�� 4���� �ɼ��� ����?
    // ��Ʈ�� + ��Ʈ + P
    // ���ڰ� �������ֳ���?

private:
    static MyKey& FindKey(const Mystring& _Name);

public:

    // ���ø� ��������.
    template<typename ... REST>
    static void CreateKey(const Mystring& _Name, REST ... _ARG)
    {
        if (mKeyMap.end() == mKeyMap.find(_Name))
        {
            // ����� ������.
            // ���� �̷������� ����ϸ� ���������� �ͱ��� �� ����
            // �̰� ��� ȿ������ �ڵ尡 �ƴϴ�.
            // �� �����ڴ� Insert + find
            // m_KeyMap[_Name];
            mKeyMap.insert(std::map<Mystring, MyKey>::value_type(_Name, MyKey()));
        }
        else
        {
            // "PlayerLeft"�� �ִµ� �� "PlayerLeft"�� ������� �� ���
            // Ű�� ������µ�.
            // ���� �̸��� Ű�� �Ǹ������ �ϴ� 
            MyDebug::AssertMsg("if (mKeyMap.end() != mKeyMap.find(_Name))");
        }

        mKeyMap[_Name].mKey.reserve(sizeof...(_ARG));
        mKeyMap[_Name].PushKey(_ARG...);
    }

public:
    static void Update();

    static bool IsFree(const Mystring& _Name);
    static bool IsUp(const Mystring& _Name);
    static bool IsPress(const Mystring& _Name);
    static bool IsDown(const Mystring& _Name);


public:
    static float4 MousePos();

public: // constructer destructer
    MyInput();
    ~MyInput();

public: // delete constructer 
    MyInput(const MyInput& _Other) = delete;
    MyInput(const MyInput&& _Other) = delete;

public: // delete operator
    MyInput& operator=(const MyInput& _Other) = delete;
    MyInput& operator=(const MyInput&& _Other) = delete;

public: // member Func
};


#pragma once
#include <vector>
#include <map>
#include "MyString.h"
#include "MyDebug.h"
#include "MyMath.h"
// 기본숙제
// 선생님이 만든 클래스의 분류 용도 설명을 자기가 기재해라.
// 못기재하겠으면 질문

// 분류 : 입출력
// 용도 : 헬퍼
// 설명 : 키보드와 마우스의 입력 처리
class MyInput
{
    // 모든 키를 관리
public:
    // 어떠한 버튼(키보드나 마우스가) 
    // 눌렸거나
    // 눌리고 있거나
    // 땠거나
    // 안눌리고 있거나를 체크할수 있어야 한다.
    // 저런 상태를 표현하려면 메모리를 사용해서
    // 클래스에 상태를 만들어 놔야 한다.
    // 자신이 만들려고 하는 녀석을 이해하고 그에 필요한 상태를 잘 선택하는 것은
    // 프로그래머의 기본 소양이다.

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
            // 소문자라는 거죠?
            if ('a' <= _Key && 'z' >= _Key)
            {
                // 소문자를 대문자로.
                _Key = toupper(_Key);
            }

            mKey.push_back(_Key);
            PushKey(_Arg...);
        }

        void PushKey(int _Key)
        {
            if ('a' <= _Key && 'z' >= _Key)
            {
                // 소문자를 대문자로.
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

    // A랑 B를 동시에 눌렀을때
    // 3개 4개가 될수도 있죠?
    // 컨트롤 + 알트 + P
    // 인자가 정해져있나요?

private:
    static MyKey& FindKey(const Mystring& _Name);

public:

    // 템플릿 가변인자.
    template<typename ... REST>
    static void CreateKey(const Mystring& _Name, REST ... _ARG)
    {
        if (mKeyMap.end() == mKeyMap.find(_Name))
        {
            // 만들어 버린다.
            // 맵은 이런식으로 사용하면 만들어버리는 것까지 다 하죠
            // 이건 사실 효율적인 코드가 아니다.
            // 이 연산자는 Insert + find
            // m_KeyMap[_Name];
            mKeyMap.insert(std::map<Mystring, MyKey>::value_type(_Name, MyKey()));
        }
        else
        {
            // "PlayerLeft"가 있는데 또 "PlayerLeft"를 만들려고 한 경우
            // 키를 만들었는데.
            // 같은 이름의 키를 또만들려고 하는 
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


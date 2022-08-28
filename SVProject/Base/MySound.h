#pragma once
// 코드를 빌려쓸 준비가 끝났다.
// 우리는 실제로 헤더를 c++ 정식
// hpp로 만들어야 하는데 아무도 이렇게 안만든다.
// 관습이 됬어요 ㅠㅠ
#include "fmod.hpp"
#include "MyDebug.h"
#include <map>

#ifdef _DEBUG
#pragma comment(lib, "fmodL_vc.lib")
#else
#pragma comment(lib, "fmod_vc.lib")
#endif

// fmod는 사운드 라이브러리 중에서 다양한 확장자와 3d사운드까지 지원하는
// 굉장히 좋은 라이브러리로 무료로 풀리는 라이브러리중 거의 종결자라고 할수 있는 라이브러리
// mp3 ogg등등 거의 모든 사운드를 지원한다.

// 분류 :
// 용도 :
// 설명 :

class Mystring;
class MySound
{
public:
    class MySoundPlayer
    {
        friend MySound;
    private:
        FMOD::Channel* Channel;
    public:
        void Stop()
        {
            if (nullptr == Channel)
            {
                MyDebug::AssertMsg("if (nullptr == Channel)");
            }

            Channel->stop();
        }

    public:
        MySoundPlayer() : Channel(nullptr)
        {

        }

    private:

        MySoundPlayer(FMOD::Channel* _Channel) : Channel(_Channel)
        {

        }
    };

private:
    static FMOD::System* mpFmodSystem;
    static std::map<Mystring, MySound*> mSoundMap;

private:
    static void Init();

    class StaticInst
    {
        friend MySound;
    private:
        StaticInst();
        ~StaticInst();
    };
    // 클레스 static 변수가 만들어지면서
    friend StaticInst;
    static StaticInst Inst;

public:
    static void Update();
    static void Release();
    static void Load(const Mystring& _Path);

//효과음 재생
    static MySoundPlayer Play(const Mystring& _Name);

private:	// Static Var
public:		// Static Func
private:	// member Var
    FMOD::Sound* mpSound;


public:		//constructer destructer
    MySound();
    ~MySound();

public:		// delete constructer
    MySound(const MySound& _Other) = delete;
    MySound(const MySound&& _Other) = delete;

public:		//delete operator
    MySound& operator=(const MySound& _Other) = delete;
    MySound& operator=(const MySound&& _Other) = delete;

private:		//member Func
    void Create(const Mystring& _Path);

    // 그냥 재생
    FMOD::Channel* Play();

};

using SoundPlayer = MySound::MySoundPlayer;
#pragma once
// �ڵ带 ������ �غ� ������.
// �츮�� ������ ����� c++ ����
// hpp�� ������ �ϴµ� �ƹ��� �̷��� �ȸ����.
// ������ ���� �Ф�
#include "fmod.hpp"
#include "MyDebug.h"
#include <map>

#ifdef _DEBUG
#pragma comment(lib, "fmodL_vc.lib")
#else
#pragma comment(lib, "fmod_vc.lib")
#endif

// fmod�� ���� ���̺귯�� �߿��� �پ��� Ȯ���ڿ� 3d������� �����ϴ�
// ������ ���� ���̺귯���� ����� Ǯ���� ���̺귯���� ���� �����ڶ�� �Ҽ� �ִ� ���̺귯��
// mp3 ogg��� ���� ��� ���带 �����Ѵ�.

// �з� :
// �뵵 :
// ���� :

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
    // Ŭ���� static ������ ��������鼭
    friend StaticInst;
    static StaticInst Inst;

public:
    static void Update();
    static void Release();
    static void Load(const Mystring& _Path);

//ȿ���� ���
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

    // �׳� ���
    FMOD::Channel* Play();

};

using SoundPlayer = MySound::MySoundPlayer;
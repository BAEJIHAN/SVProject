#include "MySound.h"
#include "MyDebug.h"
#include "Mystring.h"
#include <atlstr.h>
#include "MyPath.h"


// Static Var
// Static Func

FMOD::System* MySound::mpFmodSystem = nullptr;
MySound::StaticInst MySound::Inst;
std::map<Mystring, MySound*> MySound::mSoundMap;

MySound::StaticInst::StaticInst()
{
    MySound::Init();
}

MySound::StaticInst::~StaticInst() {
    //Release();
}

void MySound::Release()
{
    {
        std::map<Mystring, MySound*>::iterator Start = mSoundMap.begin();
        std::map<Mystring, MySound*>::iterator End = mSoundMap.end();
        for (; Start != End; ++Start)
        {
            delete Start->second;
        }
        mSoundMap.clear();
    }

    mpFmodSystem->release();
}

// constructer destructer
MySound::MySound() : mpSound(nullptr)
{

}

MySound::~MySound()
{
    if (nullptr != mpSound)
    {
        mpSound->release();
        mpSound = nullptr;
    }
}

//member Func

void MySound::Init()
{
    // FMOD::System�� �ڵ��� �ְ�
    // �� �ڵ��� ���ؼ� ���带 �ε��ϰ� ����Ҽ� �ִ�.
    // c++������ �ݴϴ�.
    FMOD::System_Create(&mpFmodSystem);

    // ���� ä���� �����̴ϴ�.

    if (nullptr == mpFmodSystem)
    {
        MyDebug::AssertMsg("if (nullptr == m_pFmodSystem)");
    }

    if (FMOD_OK != mpFmodSystem->init(32, FMOD_DEFAULT, nullptr))
    {
       MyDebug::AssertMsg("if (FMOD_OK != m_pFmodSystem->init(32, FMOD_DEFAULT, nullptr))");
    }
}


void MySound::Load(const Mystring& _Path)
{
    MySound* NewSound = new MySound();
    NewSound->Create(_Path);

    Mystring FileName = MyPath::IOName(_Path);

    // ���⼭ find�ؼ�

    // map Ű�� ����� ���ٸ�
    std::pair<std::map<Mystring, MySound*>::iterator, bool> Result =
        mSoundMap.insert(std::map<Mystring, MySound*>::value_type(FileName, NewSound));

    if (false == Result.second)
    {
        MyDebug::AssertMsg("if (false == Result.second)");
        // delete;
    }

    // NewSound->Play();
}

void MySound::Update()
{
    // ���带 �����ϰų�
    // ���尡 ������ �˰ų� �Ϸ���
    // �̳༮�� ���������� m_pFmodSystem�ý����� ���Լ��� ���ؼ� �����Ӹ��� üũ���ݴϴ�.
    if (nullptr != mpFmodSystem)
    {
        mpFmodSystem->update();
    }
}

// ���� �����Ҽ� ���� �ѹ��� ����Ҽ� �ִ� �÷���
MySound::MySoundPlayer MySound::Play(const Mystring& _Name)
{
    if (mSoundMap.end() == mSoundMap.find(_Name))
    {
        MyDebug::AssertMsg("if (mSoundMap.end() == mSoundMap.find(_Name))");
    }

    return mSoundMap[_Name]->Play();
}

//////////////////////////////////// Member

void MySound::Create(const Mystring& _Path)
{
    std::string Path = _Path.GetConvertMultiByte(CP_UTF8);

    if (FMOD_OK != mpFmodSystem->createSound(Path.c_str(), FMOD_DEFAULT, nullptr, &mpSound))
    {
        MyDebug::AssertMsg("if (FMOD_OK != m_pFmodSystem->createSound(Path.c_str(), FMOD_DEFAULT, nullptr, &m_pSound))");
    }
}

FMOD::Channel* MySound::Play()
{
    FMOD::Channel* Ch = nullptr;

    if (FMOD_OK != mpFmodSystem->playSound(mpSound, nullptr, false, &Ch))
    {
        MyDebug::AssertMsg("FMOD_OK != m_pFmodSystem->playSound(m_pSound, nullptr, false, nullptr)");
    }

    return Ch;
}
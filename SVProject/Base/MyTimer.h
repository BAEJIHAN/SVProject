#pragma once

//�з� : Ÿ�̸�
//�뵵 : ����
//���� : ��ŸŸ���� ���ϱ� ���� Ŭ����
#include <Windows.h>



class MyTimer
{
public:
    static MyTimer MainTimer;

public:
    static float FDeltaTime(float _Speed = 1.0f)
    {
        return MainTimer.GetFDeltaTime() * _Speed;
    }

public:
    LARGE_INTEGER mCountTime;
    LARGE_INTEGER mCurTime;
    LARGE_INTEGER mPrevTime;
    double mDDeltaTime;
    float mFDeltaTime;

public:
    double GetDDeltaTime();
    float GetFDeltaTime();
    void Reset();
    void CalTime();

public:
   MyTimer();

};



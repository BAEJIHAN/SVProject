#pragma once

//분류 : 타이머
//용도 : 헬퍼
//설명 : 델타타임을 구하기 위한 클래스
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



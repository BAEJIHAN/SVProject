#include "MyTimer.h"

MyTimer MyTimer::MainTimer = MyTimer();

double MyTimer::GetDDeltaTime()
{
    return mDDeltaTime;
}

float MyTimer::GetFDeltaTime()
{
    return mFDeltaTime;
}

void MyTimer::Reset()
{
    QueryPerformanceCounter(&mCurTime);
    QueryPerformanceCounter(&mPrevTime);
}

void MyTimer::CalTime()
{
    QueryPerformanceCounter(&mCurTime);
    __int64 InterCount = mCurTime.QuadPart - mPrevTime.QuadPart;
    mDDeltaTime = (double)InterCount / (double)mCountTime.QuadPart;
    mFDeltaTime = (float)mDDeltaTime;
    mPrevTime.QuadPart = mCurTime.QuadPart;
}


MyTimer::MyTimer()
    : mCountTime(), mCurTime(), mPrevTime()
{
    // 1초에 컴퓨터가 샐수 있는 숫자
    QueryPerformanceFrequency(&mCountTime);

    // 현재까지 얼마나 샜느냐. m_CurTime 
    // 바로 이전 프레임까지 얼마나 샜느냐. m_PrevTime 
    Reset();
}
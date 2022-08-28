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
    // 1�ʿ� ��ǻ�Ͱ� ���� �ִ� ����
    QueryPerformanceFrequency(&mCountTime);

    // ������� �󸶳� ������. m_CurTime 
    // �ٷ� ���� �����ӱ��� �󸶳� ������. m_PrevTime 
    Reset();
}
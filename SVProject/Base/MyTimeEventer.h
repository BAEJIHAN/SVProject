#pragma once
#include <vector>
#include "MyTimer.h"
#include "MyDebug.h"


template<typename EventTarget>
class MyTimeEventer
{
public:
	class TimeEvent
	{
	public:
		float mTime; 
		float mMaxTime; 
		EventTarget* mObj;
		void(EventTarget::* mStartFunc)(); // 이 이벤트가 시작할때 함수
		void(EventTarget::* mEndFunc)();  // 시간이 모두 종료되면 실행되는 함수
		void(EventTarget::* mStayFunc)(); // 시간이 가는도중 계속 실행되는 함수

	public:

		void Reset() 
		{
			mTime = mMaxTime;
		}

		bool Update()
		{
			if (mTime >= mMaxTime)
			{
				mTime -= MyTimer::FDeltaTime();
				if (nullptr == mStartFunc)
				{
					return false;
				}
				// 함수포인터 실행법.
				(mObj->*mStartFunc)();
				return false;
			}

			mTime -= MyTimer::FDeltaTime();

			if (0.0 <= mTime)
			{
				if (nullptr == mStayFunc)
				{
					return false;
				}
				// 함수포인터 실행법.
				(mObj->*mStayFunc)();

				return false;
			}

			mTime = mMaxTime;

			if (nullptr == mEndFunc)
			{
				return true;
			}
			(mObj->*mEndFunc)();
			return true;
		}

	public:
		TimeEvent() : mTime(0.0f)
		{

		}
		~TimeEvent()
		{

		}
	};

private:
	int CurEvent;
	std::vector<TimeEvent> mEvents;
	bool  mLoop; // 다시 재반복

public:
	void LoopOn()
	{
		mLoop = true;
	}


public:
	void CreateTimeEvent
	(	float _Time, EventTarget* _Obj,
		void(EventTarget::* _EndFunc)(), // 1초가 지난다음 실행하는 함수
		void(EventTarget::* _StartFunc)() = nullptr,// 0.0초에 실행되는 함수입니다.
		void(EventTarget::* _StayFunc)() = nullptr  // 0 ~ 1초 사이에 프레임마다 실행되는 함수
	)
	{
		mEvents.resize(mEvents.size() + 1);
		mEvents[mEvents.size() - 1].mStartFunc = _StartFunc;
		mEvents[mEvents.size() - 1].mStayFunc = _StayFunc;
		mEvents[mEvents.size() - 1].mEndFunc = _EndFunc;
		mEvents[mEvents.size() - 1].mTime = _Time;
		mEvents[mEvents.size() - 1].mMaxTime = _Time;
		mEvents[mEvents.size() - 1].mObj = _Obj;
	}

	void Reset()
	{
		CurEvent = 0;

		for (size_t i = 0; i < mEvents.size(); i++)
		{
			mEvents[i].Reset();
		}
	}

	void Update()
	{
		if (0 == mEvents.size())
		{
			MyDebug::AssertMsg("if (0 == m_Events.size())");
		}

		if (mEvents.size() <= CurEvent)
		{
			if (false == mLoop)
			{
				return;
			}
			// 처음부터 다시 계속 돕니다.
			CurEvent = 0;
		}

		if (true == mEvents[CurEvent].Update())
		{
			++CurEvent;
		}
	}

public:
	MyTimeEventer() : CurEvent(0), mLoop(false)
	{

	}
	~MyTimeEventer()
	{

	}

};


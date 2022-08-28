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
		void(EventTarget::* mStartFunc)(); // �� �̺�Ʈ�� �����Ҷ� �Լ�
		void(EventTarget::* mEndFunc)();  // �ð��� ��� ����Ǹ� ����Ǵ� �Լ�
		void(EventTarget::* mStayFunc)(); // �ð��� ���µ��� ��� ����Ǵ� �Լ�

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
				// �Լ������� �����.
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
				// �Լ������� �����.
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
	bool  mLoop; // �ٽ� ��ݺ�

public:
	void LoopOn()
	{
		mLoop = true;
	}


public:
	void CreateTimeEvent
	(	float _Time, EventTarget* _Obj,
		void(EventTarget::* _EndFunc)(), // 1�ʰ� �������� �����ϴ� �Լ�
		void(EventTarget::* _StartFunc)() = nullptr,// 0.0�ʿ� ����Ǵ� �Լ��Դϴ�.
		void(EventTarget::* _StayFunc)() = nullptr  // 0 ~ 1�� ���̿� �����Ӹ��� ����Ǵ� �Լ�
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
			// ó������ �ٽ� ��� ���ϴ�.
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


#pragma once
#pragma once
#include <map>
#include "MyTimer.h"
#include "Mystring.h"
#include "MyDebug.h"
// 플레이어 만들대 이클래스면 다 만들수 있다.
// 다른 클래스를 쓸필요가 없다.

template<typename EventTarget>
class MyFSM
{
public:
	class State
	{
	public:

		EventTarget* mObj;
		void(EventTarget::* mStartFunc)(); // 이 이벤트가 시작할때 함수
		void(EventTarget::* mEndFunc)();  // 시간이 모두 종료되면 실행되는 함수
		void(EventTarget::* mStayFunc)(); // 시간이 가는도중 계속 실행되는 함수

	public:
		
		void Start()
		{
			if (nullptr == mStartFunc)
			{
				return;
			}

			(mObj->*mStartFunc)();
		}

		void End()
		{
			if (nullptr == mEndFunc)
			{
				return;
			}

			(mObj->*mEndFunc)();
		}


		void Update()
		{
			if (nullptr == mStayFunc)
			{
				MyDebug::AssertMsg("if (nullptr == mStayFunc)");
			}

			(mObj->*mStayFunc)();
		}

	public:
		State() : mObj(nullptr), mStartFunc(nullptr), mEndFunc(nullptr), mStayFunc(nullptr)
		{

		}
		~State()
		{

		}
	};

private:
	std::map<Mystring, State> mState;
	State* mCurState;

public:
	void CreateState(Mystring _StateName, EventTarget* _Obj,
		void(EventTarget::* _StayFunc)(),
		void(EventTarget::* _StartFunc)() = nullptr,// 0.0초에 실행되는 함수입니다.
		void(EventTarget::* _EndFunc)() = nullptr  // 0 ~ 1초 사이에 프레임마다 실행되는 함수
	)
	{
		if (mState.end() != mState.find(_StateName))
		{
			MyDebug::AssertMsg("if (mState.end() != mState.find(_StateName))");
		}

		mState[_StateName].mObj = _Obj;
		mState[_StateName].mStartFunc = _StartFunc;
		mState[_StateName].mStayFunc = _StayFunc;
		mState[_StateName].mEndFunc = _EndFunc;
	}

	void ChangeState(Mystring _StateName)
	{
		if (mState.end() == mState.find(_StateName))
		{
			MyDebug::AssertMsg("if (mState.end() == mState.find(_StateName))");
		}


		if (nullptr != mCurState)
		{
			if(nullptr!=mCurState->mEndFunc)
				mCurState->End();
		}
		mCurState = &mState[_StateName];
		
		if (nullptr != mCurState->mStartFunc)
			mCurState->Start();
	}

	void Update()
	{
		if (nullptr == mCurState)
		{
			MyDebug::AssertMsg("if (0 == mEvents.size())");
		}
		mCurState->Update();
	}

public:
	MyFSM() : mCurState(nullptr)
	{

	}
	~MyFSM()
	{
		mState.clear();
	}
};


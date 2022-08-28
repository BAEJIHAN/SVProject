#pragma once
#pragma once
#include <map>
#include "MyTimer.h"
#include "Mystring.h"
#include "MyDebug.h"
// �÷��̾� ����� ��Ŭ������ �� ����� �ִ�.
// �ٸ� Ŭ������ ���ʿ䰡 ����.

template<typename EventTarget>
class MyFSM
{
public:
	class State
	{
	public:

		EventTarget* mObj;
		void(EventTarget::* mStartFunc)(); // �� �̺�Ʈ�� �����Ҷ� �Լ�
		void(EventTarget::* mEndFunc)();  // �ð��� ��� ����Ǹ� ����Ǵ� �Լ�
		void(EventTarget::* mStayFunc)(); // �ð��� ���µ��� ��� ����Ǵ� �Լ�

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
		void(EventTarget::* _StartFunc)() = nullptr,// 0.0�ʿ� ����Ǵ� �Լ��Դϴ�.
		void(EventTarget::* _EndFunc)() = nullptr  // 0 ~ 1�� ���̿� �����Ӹ��� ����Ǵ� �Լ�
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


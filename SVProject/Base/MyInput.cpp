#include "MyInput.h"
#include <Windows.h>


std::map<Mystring, MyInput::MyKey> MyInput::mKeyMap;

MyInput::MyKey::MyKey()
	: Down(false), Press(false), Up(false), Free(true)
{

}

MyInput::MyKey::~MyKey()
{

}

bool MyInput::MyKey::KeyCheck()
{
	for (size_t i = 0; i < mKey.size(); i++)
	{
		// 하나라도 안눌렸다면 이 키는 안눌린거에요.
		if (0 == GetAsyncKeyState(mKey[i]))
		{
			return false;
		}
	}

	// 다 눌렸다면 이 키는 눌린겁니다.
	return true;
}

// 이녀석의 역할은 자신의 키가 눌렸고 어떠한 상태인지 체크하는 함수입니다.
void MyInput::MyKey::Update()
{
	// 처음에는 free만 true죠?dws
	if (true == KeyCheck())
	{
		// 일단 나는 눌렸다.
		// 여태까지 안눌려있다가
		if (true == Free)
		{
			Down = true;
			Press = true;
			Up = false;
			Free = false;
		}
		else
		{
			// 이전까지 눌려있었다는 거죠?
			Down = false;
			Press = true;
			Up = false;
			Free = false;
		}

	}
	else
	{

		// 일단 나는 안눌렸다.
		// 바로 이전프레임 까지만 해도 나는 누르고 있었다.
		if (true == Press)
		{
			Down = false;
			Press = false;
			Up = true;
			Free = true;
		}
		else
		{
			// 이전까지 눌려있었다는 거죠?
			Down = false;
			Press = false;
			Up = false;
			Free = true;
		}


	}
}


// Static Var
// Static Func
// member Var
MyInput::MyInput()
{

}

MyInput::~MyInput()
{

}
// member Func

MyInput::MyKey& MyInput::FindKey(const Mystring& _Name)
{
	// 없는 키를 사용하려고 하면 터트릴께요.

	// 만들때도 써야 하니까.
	if (mKeyMap.end() == mKeyMap.find(_Name))
	{
		// 무조건 터트릴거라 이렇게 쓴겁니다.
		MyDebug::AssertMsg("if (mKeyMap.end() == mKeyMap.find(_Name))");
		return mKeyMap[_Name];
	}

	return mKeyMap[_Name];
}

void MyInput::Update()
{
	std::map<Mystring, MyKey>::iterator Start = mKeyMap.begin();
	std::map<Mystring, MyKey>::iterator End = mKeyMap.end();

	for (; Start != End; ++Start)
	{
		Start->second.Update();
	}
}

bool MyInput::IsFree(const Mystring& _Name)
{
	return FindKey(_Name).Free;
}
bool MyInput::IsUp(const Mystring& _Name)
{
	return FindKey(_Name).Up;
}
bool MyInput::IsPress(const Mystring& _Name)
{
	return FindKey(_Name).Press;
}
bool MyInput::IsDown(const Mystring& _Name)
{
	return FindKey(_Name).Down;
}
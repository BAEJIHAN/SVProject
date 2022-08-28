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
		// �ϳ��� �ȴ��ȴٸ� �� Ű�� �ȴ����ſ���.
		if (0 == GetAsyncKeyState(mKey[i]))
		{
			return false;
		}
	}

	// �� ���ȴٸ� �� Ű�� �����̴ϴ�.
	return true;
}

// �̳༮�� ������ �ڽ��� Ű�� ���Ȱ� ��� �������� üũ�ϴ� �Լ��Դϴ�.
void MyInput::MyKey::Update()
{
	// ó������ free�� true��?dws
	if (true == KeyCheck())
	{
		// �ϴ� ���� ���ȴ�.
		// ���±��� �ȴ����ִٰ�
		if (true == Free)
		{
			Down = true;
			Press = true;
			Up = false;
			Free = false;
		}
		else
		{
			// �������� �����־��ٴ� ����?
			Down = false;
			Press = true;
			Up = false;
			Free = false;
		}

	}
	else
	{

		// �ϴ� ���� �ȴ��ȴ�.
		// �ٷ� ���������� ������ �ص� ���� ������ �־���.
		if (true == Press)
		{
			Down = false;
			Press = false;
			Up = true;
			Free = true;
		}
		else
		{
			// �������� �����־��ٴ� ����?
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
	// ���� Ű�� ����Ϸ��� �ϸ� ��Ʈ������.

	// ���鶧�� ��� �ϴϱ�.
	if (mKeyMap.end() == mKeyMap.find(_Name))
	{
		// ������ ��Ʈ���Ŷ� �̷��� ���̴ϴ�.
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
#include "MyObjectBase.h"

MyObjectBase::MyObjectBase() :
	mIsOn(true),
	mIsDead(false),
	mParent(nullptr)
{

}

// �޸𸮰� �����Ǳ� ������ �������� �Ҽ��� �ְ���?
MyObjectBase::~MyObjectBase()
{
	DeathTask();
}

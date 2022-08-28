#include "MyObjectBase.h"

MyObjectBase::MyObjectBase() :
	mIsOn(true),
	mIsDead(false),
	mParent(nullptr)
{

}

// 메모리가 삭제되기 직전에 무슨일을 할수가 있겠죠?
MyObjectBase::~MyObjectBase()
{
	DeathTask();
}

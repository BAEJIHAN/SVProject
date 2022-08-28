#include "MyDebug.h"
#include <assert.h>
#include <Windows.h>
#include <crtdbg.h>
void MyDebug::LeakCheck()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}
void MyDebug::AssertMsg(const Mystring& _ErrorMsg)
{

#ifdef _DEBUG
	// OutputDebugStringW(_ErrorMsg.c_str());
	// (_ErrorMsg.c_str(), __FILEW__, __LINE__);
	assert(!_ErrorMsg.c_str());
#endif
	// 
	
}

void MyDebug::AssertMsg(const std::string& _ErrorMsg) {
#ifdef _DEBUG
	// OutputDebugStringW(_ErrorMsg.c_str());
	// (_ErrorMsg.c_str(), __FILEW__, __LINE__);
	assert(!_ErrorMsg.c_str());
#endif
}

void MyDebug::OutPutMsg(const Mystring& _ErrorMsg)
{
	OutputDebugStringW(_ErrorMsg.c_str());

}

MyDebug::MyDebug()
{
}

MyDebug::~MyDebug()
{
}

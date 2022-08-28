#include <MyBasePublic.h>
#include <MyPlatformPublic.h>
#include <MyClientPublic.h>

#include <MyWindow.h>

#include <Windows.h>
#include "Core.h"
#include<MyDebug.h>
#include <MyResMgr.h>
int __stdcall wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
    MyDebug::LeakCheck();
    MyWindow::CreateMyWindow(hInstance, L"GAMEWINDOW", { 0, 0 }, { 800, 600 });
  
    MyWindow::Loop<Core>();
    MyResMgr::Inst().Release();
    return 0;
}
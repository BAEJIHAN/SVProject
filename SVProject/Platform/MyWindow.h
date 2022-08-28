#pragma once
#include <MyBasePublic.h>
#include <Windows.h>
#include <MyString.h>
#include "MyWinImage.h"
#include<MyTimer.h>
#include <MyInput.h>
#include <MySound.h>
//분류 : 플랫폼
//용도 : 업데이터
//설명 : 내가 띄우는 윈도우에 대한 데이터를 관리하고 업데이트 한다.

class MyWindow
{
private: //static variable
    static float4 mSize;
    static float4 mPos;
    static bool bWindowProgress;
    
    static HWND mWindowHWnd;    
    static HDC mWindowDC;
    static MyWinImage WindowMainImage;
    static MyWinImage DoubleBufferImage;

    static __int64 WINDOWEVENT(HWND, unsigned int, unsigned __int64, __int64);
public:	//static func
    static void WindowEnd()
    {
        bWindowProgress = false;
    }
    static HDC GetWindowDC()
    {
        return WindowMainImage.ImageDC();
    }

    static HDC GetBackBufferDC()
    {
        return DoubleBufferImage.ImageDC();
    }

    static MyWinImage& GetWindowImage()
    {
        return WindowMainImage;
    }

    static MyWinImage& GetBackBufferImage()
    {
        return DoubleBufferImage;
    }
    static void BackBufferCopy();


    template<typename Updater>
    static void Loop()
    {
        Updater::Start();

        MSG MsgData;

        while (bWindowProgress)
        {
            MyTimer::MainTimer.CalTime();
            MyInput::Update();
            MySound::Update();
            if (0 != PeekMessage(&MsgData, mWindowHWnd, 0, 0, PM_REMOVE))
            {
                DispatchMessage(&MsgData);
               
                Updater::Update();
                
            }
            else
            {
               
                Updater::Update();
            }
        }

        Updater::End();

        if (true)
        {
            DestroyWindow(mWindowHWnd);
            mWindowHWnd = nullptr;
        }
    }
    static void CreateMyWindow(HINSTANCE _ProcessHandle, const Mystring& _Name, float4 _Pos, float4 _Size);


public:	//constructor destructor
    MyWindow();
    ~MyWindow();


public: // delete constructer 
    MyWindow(const MyWindow& _Other) = delete;
    MyWindow(const MyWindow&& _Other) = delete;

public: // delete operator
    MyWindow& operator=(const MyWindow& _Other) = delete;
    MyWindow& operator=(const MyWindow&& _Other) = delete;

public: // member func
    static void SetSize(float4 _Size);
    static void SetPos(float4 _Pos);
    static void SetSizeAndPos(float4 _Pos, float4 _Size);
    static float4 GetSize();

    static void CursorOff()
    {
        ShowCursor(false);
    }

    static float4 MousePos()
    {
        POINT P;
        // 모니터에서의 마우스 위치
        GetCursorPos(&P);
        // m_HWND 윈도우 기준으로 
        ScreenToClient(mWindowHWnd, &P);

        return { (float)P.x, (float)P.y };

    }
};




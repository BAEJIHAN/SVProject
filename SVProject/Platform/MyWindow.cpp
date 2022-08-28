#include "MyWindow.h"
#include <MyDebug.h>

#include <Windows.h>

// Static Var
float4 MyWindow::mSize;
float4 MyWindow::mPos;
HWND MyWindow::mWindowHWnd = nullptr;
bool MyWindow::bWindowProgress = true;
MyWinImage MyWindow::WindowMainImage;
MyWinImage MyWindow::DoubleBufferImage;

HDC MyWindow::mWindowDC;

__int64 MyWindow::WINDOWEVENT(HWND _hWnd, unsigned int _EventType, unsigned __int64 _LValue, __int64 _SubValue)
{
	switch (_EventType)
	{
	case WM_KILLFOCUS:
	{	
		int a = 0;
		//m_bWindowProgress = false;
		break;
	}
	case WM_DESTROY:
	{
		bWindowProgress = false;
		break;
	}
	default:
		
		return DefWindowProcW(_hWnd, _EventType, _LValue, _SubValue);
	}


	return DefWindowProcW(_hWnd, _EventType, _LValue, _SubValue);
}
void MyWindow::SetSize(float4 _Size)
{
	SetSizeAndPos(mPos, _Size);

}
void MyWindow::SetPos(float4 _Pos)
{
	SetSizeAndPos(_Pos, mSize);

}

void MyWindow::SetSizeAndPos(float4 _Pos, float4 _Size)
{
	mSize = _Size;
	mPos = _Pos;

	RECT Rect = { 0,0, mSize.ix(), mSize.iy() };


	AdjustWindowRect(&Rect, WS_OVERLAPPEDWINDOW, false);

	SetWindowPos(mWindowHWnd, HWND_BOTTOM, _Pos.ix(), _Pos.iy(), Rect.right - Rect.left, Rect.bottom - Rect.top, SWP_NOZORDER);
}

float4 MyWindow::GetSize()
{
	return mSize;
}

void MyWindow::BackBufferCopy()
{
	WindowMainImage.BitBlt(DoubleBufferImage);

}

void MyWindow::CreateMyWindow(HINSTANCE _ProcessHandle, const Mystring& _Name, float4 _Pos, float4 _Size)
{
	

	WNDCLASSEXW WCEX;

	WCEX.cbSize = sizeof(WNDCLASSEXW);

	WCEX.style = CS_HREDRAW | CS_VREDRAW;

	WCEX.lpfnWndProc = &MyWindow::WINDOWEVENT;

	WCEX.cbClsExtra = 0;
	WCEX.cbWndExtra = 0;


	WCEX.hInstance = _ProcessHandle;

	WCEX.hIcon = nullptr;
	WCEX.hIconSm = nullptr;


	WCEX.hCursor = nullptr;

	WCEX.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

	WCEX.lpszMenuName = nullptr;

	WCEX.lpszClassName = L"DEFWINDOW";


	if (0 == RegisterClassExW(&WCEX))
	{
		unsigned int ErrorCode = GetLastError();

		MyDebug::AssertMsg(L"if (0 == RegisterClassExW(&WCEX))");
	}






	mWindowHWnd = CreateWindowW(L"DEFWINDOW", _Name.c_str(), WS_OVERLAPPEDWINDOW, (int)_Pos.x, (int)_Pos.y, (int)_Size.x, (int)_Size.y, nullptr, nullptr, _ProcessHandle, 0);

	if (nullptr == mWindowHWnd)
	{
		MyDebug::AssertMsg(L"if (nullptr == m_WindowHWnd)");
		return;
	}


	ShowWindow(mWindowHWnd, SW_SHOW);
	SetSizeAndPos(_Pos, _Size);

	UpdateWindow(mWindowHWnd);

	mWindowDC = GetDC(mWindowHWnd);

	WindowMainImage.Create(mWindowDC);
	DoubleBufferImage.Create(_Size);


}




MyWindow::MyWindow()
{
}

MyWindow::~MyWindow()
{
}

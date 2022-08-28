#include "MyCamera.h"
#include<MyWindow.h>
#include"MyInput.h"
#include"MyTimer.h"

float4	MyCamera::CamPos;
MyActor* MyCamera::Target;
float	MyCamera::Speed;

float4 MyCamera::Pivot;
MyScene* MyCamera::CurScene;

MyCamera::MyCamera()
{
}

MyCamera::~MyCamera()
{
}

void MyCamera::Update()
{
	MoveCamera();
	
}

void MyCamera::MoveCamera()
{
	float4 WSize= MyWindow::GetSize();
	float4 MapSize = CurScene->GetMapSize();

	
	if (nullptr == Target)
	{
		


		if (true == MyInput::IsPress(L"CL"))
		{
			if (CamPos.x<=0)
				return;
			CamPos.x -= Speed * MyTimer::FDeltaTime();
		}
		 if (true == MyInput::IsPress(L"CR"))
		{
			 if (CamPos.x >= MapSize.x-WSize.x)
				 return;
			 CamPos.x += Speed * MyTimer::FDeltaTime();
		}
		if (true == MyInput::IsPress(L"CU"))
		{
			if(CamPos.y <= 0)
				return;
			CamPos.y -= Speed * MyTimer::FDeltaTime();
		}
		 if (true == MyInput::IsPress(L"CD"))
		{
			 if (CamPos.y >= MapSize.y- WSize.y)
				 return;
			 CamPos.y += Speed * MyTimer::FDeltaTime();
		}		 

		
	}

}

void MyCamera::SetCamPos(float4 _pos) 
{
	if (nullptr != Target)
		CamPos = _pos;

	int Left = CamPos.ix();
	int Right = CamPos.ix() + MyWindow::GetSize().ix();
	int Up = CamPos.iy();
	int Down = CamPos.iy() + MyWindow::GetSize().iy();

	if (0 >= Left)
	{
		CamPos.x = 1;
	}

	if (0 >= Up)
	{
		CamPos.y = 1;
	}

	if (Down >= CurScene->GetMapSize().iy() - 1)
	{
		CamPos.y =(float)(CurScene->GetMapSize().iy() - 1 - MyWindow::GetSize().iy());
	}

	if (Right >= CurScene->GetMapSize().ix() - 1)
	{
		CamPos.x = (float)(CurScene->GetMapSize().ix() - 1 - MyWindow::GetSize().ix());
	}

}


void MyCamera::Start()
{

	CurScene = nullptr;
	Speed = 500;
	Pivot = float4(0.5f, 0.5f);
	CamPos = float4(MyWindow::GetSize().x * Pivot.x, MyWindow::GetSize().y * Pivot.y);
}

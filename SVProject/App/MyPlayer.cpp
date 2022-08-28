#include "MyPlayer.h"
#include <MyRendererBasic.h>
#include <MyInput.h>
#include <MyTimer.h>
#include <MyRendererAnimation.h>
#include <MyWindow.h>
#include <MyResMgr.h>
#include "Core.h"

#include "FarmScene.h"
#include "StoreScene.h"
#include "HouseScene.h"
#include "RoadScene.h"
#include "TownScene.h"


#include "Selected.h"
#include <MyCamera.h>
#include "MyLogicValue.h"
#include <MyCollision.h>

MyPlayer::MyPlayer() :Speed(300.f), Dir(DOWN), bOnMove(true), mAction(AXE), MaxActionTime(0.3f), CurActionTime(0.0f), bDebugOn(false), MoveTime(0), Energy(100), UsingEnergy(3), CurMap(MAP::NONE)
{ 
}

MyPlayer::~MyPlayer()
{
}


void MyPlayer::Start()
{

	pcol = CreateCollision<MyCollision>(COLINDEX::PLAYER);
	pcol->SetScale(float4(64, 64));
	AniRenderer = CreateRenderer<MyRendererAnimation>(RENDERINDEX::PLAYER);
	AniRenderer->SetRenderScale({ 256, 256 });


	AniRenderer->CreateAnimation(L"DMOVE", L"PlayerMove.bmp", float4(256, 256), 1, 4, 0.2f);
	AniRenderer->CreateAnimation(L"UMOVE", L"PlayerMove.bmp", float4(256, 256), 6, 9, 0.2f);
	AniRenderer->CreateAnimation(L"RMOVE", L"PlayerMove.bmp", float4(256, 256), 11, 14, 0.2f);
	AniRenderer->CreateAnimation(L"LMOVE", L"PlayerMove.bmp", float4(256, 256), 16, 19, 0.2f);


	AniRenderer->CreateAnimation(L"DIDLE", L"PlayerMove.bmp", float4(256, 256), 0, 0, 0.2f, false);
	AniRenderer->CreateAnimation(L"UIDLE", L"PlayerMove.bmp", float4(256, 256), 5, 5, 0.2f, false);
	AniRenderer->CreateAnimation(L"RIDLE", L"PlayerMove.bmp", float4(256, 256), 10, 10, 0.2f, false);
	AniRenderer->CreateAnimation(L"LIDLE", L"PlayerMove.bmp", float4(256, 256), 15, 15, 0.2f, false);

	AniRenderer->CreateAnimation(L"DHOE", L"HoeAction.bmp", float4(256, 512), 0, 2, 0.1f, false);
	AniRenderer->CreateAnimation(L"UHOE", L"HoeAction.bmp", float4(256, 512), 3, 5, 0.1f, false);
	AniRenderer->CreateAnimation(L"RHOE", L"HoeAction.bmp", float4(256, 512), 6, 8, 0.1f, false);
	AniRenderer->CreateAnimation(L"LHOE", L"HoeAction.bmp", float4(256, 512), 9, 11, 0.1f, false);

	AniRenderer->CreateAnimation(L"DAXE", L"AxeAction.bmp", float4(256, 512), 0, 2, 0.1f, false);
	AniRenderer->CreateAnimation(L"UAXE", L"AxeAction.bmp", float4(256, 512), 3, 5, 0.1f, false);
	AniRenderer->CreateAnimation(L"RAXE", L"AxeAction.bmp", float4(256, 512), 6, 8, 0.1f, false);
	AniRenderer->CreateAnimation(L"LAXE", L"AxeAction.bmp", float4(256, 512), 9, 11, 0.1f, false);

	AniRenderer->CreateAnimation(L"DPICK", L"PickAction.bmp", float4(256, 512), 0, 2, 0.1f, false);
	AniRenderer->CreateAnimation(L"UPICK", L"PickAction.bmp", float4(256, 512), 3, 5, 0.1f, false);
	AniRenderer->CreateAnimation(L"RPICK", L"PickAction.bmp", float4(256, 512), 6, 8, 0.1f, false);
	AniRenderer->CreateAnimation(L"LPICK", L"PickAction.bmp", float4(256, 512), 9, 11, 0.1f, false);

	AniRenderer->CreateAnimation(L"DSICKLE", L"SickleAction.bmp", float4(256, 512), 0, 2, 0.1f, false);
	AniRenderer->CreateAnimation(L"USICKLE", L"SickleAction.bmp", float4(256, 512), 3, 5, 0.1f, false);
	AniRenderer->CreateAnimation(L"RSICKLE", L"SickleAction.bmp", float4(256, 512), 6, 8, 0.1f, false);
	AniRenderer->CreateAnimation(L"LSICKLE", L"SickleAction.bmp", float4(256, 512), 9, 11, 0.1f, false);

	AniRenderer->CreateAnimation(L"DWATERING", L"WateringAction.bmp", float4(256, 512), 0, 2, 0.1f, false);
	AniRenderer->CreateAnimation(L"UWATERING", L"WateringAction.bmp", float4(256, 512), 3, 5, 0.1f, false);
	AniRenderer->CreateAnimation(L"RWATERING", L"WateringAction.bmp", float4(256, 512), 6, 8, 0.1f, false);
	AniRenderer->CreateAnimation(L"LWATERING", L"WateringAction.bmp", float4(256, 512), 9, 11, 0.1f, false);


	AniRenderer->ChangeAnimation(L"DIDLE");

	PlayerFsm.CreateState(L"ACTION", this, &MyPlayer::ACTIONStay, &MyPlayer::ACTIONStart);
	PlayerFsm.CreateState(L"IDLE", this, &MyPlayer::IDLEStay, &MyPlayer::IDLEStart);
	PlayerFsm.CreateState(L"MOVE", this, &MyPlayer::MOVEStay, &MyPlayer::MOVEStart, &MyPlayer::MOVEEnd);
	PlayerFsm.ChangeState(L"IDLE");
	
}

void MyPlayer::KeyCheck()
{
	
	if (true == MyInput::IsDown(L"ToggleQuick"))
	{
		MyLogicValue::FarmSceneAddress->GetPlayer()->Speed=1000.f;
		 MyLogicValue::StoreSceneAddress->GetPlayer()->Speed = 1000.f;
		MyLogicValue::RoadSceneAddress->GetPlayer()->Speed = 1000.f;
		MyLogicValue::TownSceneAddress->GetPlayer()->Speed = 1000.f;
		 MyLogicValue::HouseSceneAddress->GetPlayer()->Speed = 1000.f;
		
	}
	if (true == MyInput::IsDown(L"ToggleSlow"))
	{
		MyLogicValue::FarmSceneAddress->GetPlayer()->Speed = 300.f;
		MyLogicValue::StoreSceneAddress->GetPlayer()->Speed = 300.f;
		MyLogicValue::RoadSceneAddress->GetPlayer()->Speed = 300.f;
		MyLogicValue::TownSceneAddress->GetPlayer()->Speed = 300.f;
		MyLogicValue::HouseSceneAddress->GetPlayer()->Speed = 300.f;
		
	}

	if (true == MyInput::IsPress(L"L"))
	{
		Dir = DIR::LEFT;
		
	}
	if (true == MyInput::IsPress(L"R"))
	{
		Dir = DIR::RIGHT;
		
	}
	if (true == MyInput::IsPress(L"U"))
	{
		Dir = DIR::UP;
		
	}
	if (true == MyInput::IsPress(L"D"))
	{
		Dir = DIR::DOWN;		
	}

	if (PrevDir != Dir)
	{
		ChangeAnimation(CurAniName);
	}

	PrevDir = Dir;

	if (true == MyInput::IsPress(L"AXE"))
	{
		MyLogicValue::FarmSceneAddress->selected->SetPosition({ 50 ,550 });
		mAction = ACTION::AXE;
	}
	if (true == MyInput::IsPress(L"HOE"))
	{
		MyLogicValue::FarmSceneAddress->selected->SetPosition({ 114 ,550 });
		mAction = ACTION::HOE;

	}
	if (true == MyInput::IsPress(L"WATER"))
	{
		MyLogicValue::FarmSceneAddress->selected->SetPosition({ 178 ,550 });
		mAction = ACTION::WATERING;

	}
	if (true == MyInput::IsPress(L"PICK"))
	{
		MyLogicValue::FarmSceneAddress->selected->SetPosition({ 242 ,550 });
		mAction = ACTION::PICK;
	}
	if (true == MyInput::IsPress(L"SICKLE"))
	{
		MyLogicValue::FarmSceneAddress->selected->SetPosition({ 306 ,550 });
		mAction = ACTION::SICKLE;
	}
	if (true == MyInput::IsPress(L"POTATO"))
	{
		MyLogicValue::FarmSceneAddress->selected->SetPosition({ 370 ,550 });
		mAction = ACTION::POTATO;
	}
	if (true == MyInput::IsPress(L"EGGPLANT"))
	{
		MyLogicValue::FarmSceneAddress->selected->SetPosition({ 434 ,550 });
		mAction = ACTION::EGGPLANT;
	}
	if (true == MyInput::IsPress(L"RADISH"))
	{
		MyLogicValue::FarmSceneAddress->selected->SetPosition({ 498 ,550 });
		mAction = ACTION::RADISH;
	}
	if (true == MyInput::IsPress(L"TOMATO"))
	{
		MyLogicValue::FarmSceneAddress->selected->SetPosition({ 562 ,550 });
		mAction = ACTION::TOMATO;
	}
	if (true == MyInput::IsPress(L"CABBAGE"))
	{
		MyLogicValue::FarmSceneAddress->selected->SetPosition({ 626 ,550 });
		mAction = ACTION::CABBAGE;
	}
	if (true == MyInput::IsPress(L"BLUE"))
	{
		MyLogicValue::FarmSceneAddress->selected->SetPosition({ 690 ,550 });
		mAction = ACTION::BLUEBERRY;
	}

}

void MyPlayer::ChangeAnimation(const Mystring& _Str)
{
	Mystring NewString;

	switch (Dir)
	{
	case LEFT:
		NewString += L"L";
		break;
	case RIGHT:
		NewString += L"R";
		break;
	case UP:
		NewString += L"U";
		break;
	case DOWN:
		NewString += L"D";
		break;
	case MAX:
	default:
		break;
	}

	CurAniName = _Str;

	NewString += _Str;
	AniRenderer->ChangeAnimation(NewString);
}



void MyPlayer::Update()
{
	
	
	if (true == bOnMove)
	{
		KeyCheck();
		PlayerFsm.Update();
	}
	else
	{
		PlayerFsm.ChangeState(L"IDLE");
	}
	

	
}

void MyPlayer::DebugRender()
{
	if (false == bDebugOn)
	{
		return;
	}
	
	float4 RenderPos = GetPosition() - MyCamera::GetCamPos();

	Rectangle(MyWindow::GetBackBufferDC(),
		RenderPos.ix() - 4,
		RenderPos.iy() - 4,
		RenderPos.ix() + 4,
		RenderPos.iy() + 4);

	Mystring PrintText = L"X : ";
	PrintText += Mystring::ToString(GetPosition().ix());
	PrintText += L" Y : ";
	PrintText += Mystring::ToString(GetPosition().iy());

	
	TextOut(MyWindow::GetBackBufferDC(), 0, 0, PrintText.c_str(), lstrlen(PrintText.c_str()));

	Mystring PrintText2 = L"MX : ";
	PrintText2 += Mystring::ToString(MyWindow::MousePos().ix());
	PrintText2 += L" MY : ";
	PrintText2 += Mystring::ToString(MyWindow::MousePos().iy());


	TextOut(MyWindow::GetBackBufferDC(), 0, 15, PrintText2.c_str(), lstrlen(PrintText2.c_str()));

	Mystring PrintText3 = L"CX : ";
	PrintText3 += Mystring::ToString(MyCamera::GetCamPos().ix());
	PrintText3 += L" CY : ";
	PrintText3 += Mystring::ToString(MyCamera::GetCamPos().iy());


	TextOut(MyWindow::GetBackBufferDC(), 0, 30, PrintText3.c_str(), lstrlen(PrintText3.c_str()));

}


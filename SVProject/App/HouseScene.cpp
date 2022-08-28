#include "HouseScene.h"
#include <MyCamera.h>
#include <MyInput.h>
#include "MyPlayer.h"
#include "HouseBg.h"
#include "MyLogicValue.h"
#include "Core.h"
#include <MyWindow.h>
#include "FadeInActor.h"
#include "FadeOutActor.h"
#include <MyTimer.h>
#include "MouseObject.h"
#include "HouseColmapImage.h"
HouseScene::HouseScene() :BackGround(nullptr), Player(nullptr), IsFirst(true)
{
}

HouseScene::~HouseScene()
{
}

void HouseScene::Start()
{
	FadeOut=CreateActor<FadeOutActor>();
	FadeIn = CreateActor<FadeInActor>();
	BackGround = CreateActor<HouseBg>();
	SetMapSize(MyLogicValue::HouseMapSize);
	Player = CreateActor<MyPlayer>();
	Player->SetCurMap(MAP::HOUSE);
	colmapimage = CreateActor<HouseColmapImage>();
	MyLogicValue::HouseSceneAddress = this;

	SetColMap(L"housecolmap.bmp");

	MouseObject* Mouse = CreateActor<MouseObject>();

	SceneOutEvent.CreateTimeEvent(2.0f, this, &HouseScene::SceneOutEnd, &HouseScene::SceneOutStart, &HouseScene::SceneOutStay);
	SceneOutEvent.LoopOn();
	SceneInEvent.CreateTimeEvent(2.0f, this, &HouseScene::SceneInEnd, &HouseScene::SceneInStart, &HouseScene::SceneInStay);
	
}

void HouseScene::SceneUpdate()
{
		
	if (true == MyInput::IsDown(L"ToggleColmap"))
	{
		colmapimage->OnOff();
	}
	

	float4 PlayerPos = Player->GetPosition();
	if (true == MyInput::IsUp(L"TOGGLECAMERA"))
	{
		if (nullptr == MyCamera::GetTarget())
		{
			float4 WSize = MyWindow::GetSize();
			MyCamera::SetTarget(Player);
			MyCamera::SetPosiotion(float4(PlayerPos.x - WSize.hx(), PlayerPos.y - WSize.hy()));
		}
		else
		{
			MyCamera::SetTarget(nullptr);

		}

	}
		
	MyCamera::Update();


	if (false == IsFirst)
	{
		SceneInEvent.Update();
	}
	

	if (true == MyLogicValue::bInDoor(MyLogicValue::DHouseToFarm, PlayerPos))
	{		
		SceneOutEvent.Update();
	}
	
	if (true == MyInput::IsDown(L"DEBUGON"))
	{
		Player->SetDebugOnOff(true);
	}
	if (true == MyInput::IsDown(L"DEBUGOFF"))
	{
		Player->SetDebugOnOff(false);
	}
	
}

void HouseScene::SceneChangeStart()
{
	//bool������ ó������ �ƴ��� üũ. ó���� ���� �ƴ� �� if else ������ �б�.
	float4 PlayerPos = Player->GetPosition();
	float4 WSize = MyWindow::GetSize();



	if (true == IsFirst)
	{
		FadeIn->SetFadeOn(true);
		
		Player->SetPosition(float4(452, 419));
		
		MyCamera::SetTarget(Player);
		MyCamera::SetPosiotion(float4(PlayerPos.x - WSize.hx(), PlayerPos.y - WSize.hy()));
	}
	else
	{
		Player->SetPosition(MyLogicValue::GPlayerPos);
		MyCamera::SetPosiotion(float4(0.f, GetMapSize().y-WSize.y));
	}
	
	
	
}
	



void HouseScene::SceneOutStart()
{
	FadeOut->SetFadeOn(true);
	Player->SetMoveOn(false);
}

void HouseScene::SceneOutStay()
{
}

void HouseScene::SceneOutEnd()
{	
	MyLogicValue::GPlayerPos = MyLogicValue::PPosHouseToFarm;
	IsFirst = false;
	FadeOut->SetFadeAlpha(0);
	FadeOut->SetFadeOn(false);
	
	SceneInEvent.Reset();
	Player->SetDir(UP);
	Core::SceneManager.ChangeScene(L"FarmScene");
	
}

void HouseScene::SceneInStart()
{
	Player->SetMoveOn(false);
	FadeIn->SetFadeOn(true);
	
}

void HouseScene::SceneInStay()
{
}

void HouseScene::SceneInEnd()
{
	Player->SetMoveOn(true);
	FadeIn->SetFadeOn(false);
	
}




//�ٸ� ������ �� ��. fadein ����. �� ���� ĳ���� �� ������. �� �� ĳ���� scenechange.
//�ٸ� ������ �Ѿ�� ��. alpha�� �ʱ�ȭ. fadeout ����. �� ���� ĳ���� �� ������.


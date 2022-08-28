#include "RoadScene.h"
#include <MyCamera.h>
#include <MyInput.h>
#include "MyPlayer.h"
#include "RoadBg.h"
#include "MyLogicValue.h"
#include "Core.h"
#include <MyWindow.h>
#include "FadeInActor.h"
#include "FadeOutActor.h"
#include "MouseObject.h"
#include "RoadColmapImage.h"

RoadScene::RoadScene() :BackGround(nullptr), Player(nullptr)
{
}

RoadScene::~RoadScene()
{
}


void RoadScene::Start()
{
	FadeOut = CreateActor<FadeOutActor>();
	FadeIn = CreateActor<FadeInActor>();
	BackGround = CreateActor<RoadBg>();
	colmapimage = CreateActor<RoadColmapImage>();

	Player = CreateActor<MyPlayer>();
	Player->SetPosition(float4(794, 587));
	Player->SetDir(RIGHT);
	Player->SetCurMap(MAP::ROAD);

	MyLogicValue::RoadSceneAddress = this;

	SetMapSize(MyLogicValue::RoadMapSize);
	SetColMap(L"roadcolmap.bmp");
	MouseObject* Mouse = CreateActor<MouseObject>();

	SceneOutEvent.CreateTimeEvent(2.0f, this, &RoadScene::SceneOutEnd, &RoadScene::SceneOutStart, &RoadScene::SceneOutStay);
	SceneOutEvent.LoopOn();
	SceneInEvent.CreateTimeEvent(2.0f, this, &RoadScene::SceneInEnd, &RoadScene::SceneInStart, &RoadScene::SceneInStay);
}

void RoadScene::SceneUpdate()
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

	SceneInEvent.Update();

	if (true == MyLogicValue::bInDoor(MyLogicValue::DRoadToFarm, PlayerPos))
	{
		MyLogicValue::NextMap = Map::Farm;
		SceneOutEvent.Update();	
	}
	if (true == MyLogicValue::bInDoor(MyLogicValue::DRoadToTown, PlayerPos))
	{
		MyLogicValue::NextMap = Map::Town;
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

void RoadScene::SceneChangeStart()
{
	float4 WSize = MyWindow::GetSize();
	Player->SetPosition(MyLogicValue::GPlayerPos);
	if (Map::Farm == MyLogicValue::PreMap)
	{
		MyCamera::SetPosiotion(float4(0.f, 351.f - WSize.hy()));
	}
	if (Map::Town == MyLogicValue::PreMap)
	{
		MyCamera::SetPosiotion(float4(GetMapSize().x - WSize.x, 351.f - WSize.hy()));
	}

}


void RoadScene::SceneOutStart()
{
	FadeOut->SetFadeOn(true);
	Player->SetMoveOn(false);
}

void RoadScene::SceneOutStay()
{
}

void RoadScene::SceneOutEnd()
{
	FadeOut->SetFadeAlpha(0);
	FadeOut->SetFadeOn(false);
	MyLogicValue::PreMap = Map::Road;
	SceneInEvent.Reset();

	if (Map::Farm == MyLogicValue::NextMap)
	{
		MyLogicValue::GPlayerPos = MyLogicValue::PPosRoadToFarm;
		Player->SetDir(RIGHT);
		Core::SceneManager.ChangeScene(L"FarmScene");
	}
	else if (Map::Town == MyLogicValue::NextMap)
	{
		MyLogicValue::GPlayerPos = MyLogicValue::PPosRoadToTown;
		Player->SetDir(LEFT);
		Core::SceneManager.ChangeScene(L"TownScene");
	}


}

void RoadScene::SceneInStart()
{
	Player->SetMoveOn(false);
	FadeIn->SetFadeOn(true);
}

void RoadScene::SceneInStay()
{
}

void RoadScene::SceneInEnd()
{
	Player->SetMoveOn(true);
	FadeIn->SetFadeOn(false);
}


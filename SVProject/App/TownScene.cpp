#include "TownScene.h"
#include <MyCamera.h>
#include <MyInput.h>
#include "MyPlayer.h"
#include "TownBg.h"
#include "MyLogicValue.h"
#include "Core.h"
#include <MyWindow.h>
#include "FadeInActor.h"
#include "FadeOutActor.h"
#include "MouseObject.h"
#include "TownColmapImage.h"

TownScene::TownScene() :BackGround(nullptr), Player(nullptr)
{
}

TownScene::~TownScene()
{
}

void TownScene::Start()
{	
	FadeOut = CreateActor<FadeOutActor>();
	FadeIn = CreateActor<FadeInActor>();
	BackGround = CreateActor<TownBg>();
	colmapimage = CreateActor<TownColmapImage>();
	Player = CreateActor<MyPlayer>();
	Player->SetDir(RIGHT);
	Player->SetCurMap(MAP::TOWN);

	MyLogicValue::TownSceneAddress = this;

	SetColMap(L"towncolmap.bmp");
	SetMapSize(MyLogicValue::TownMapSize);
	
	MouseObject* Mouse = CreateActor<MouseObject>();

	SceneOutEvent.CreateTimeEvent(2.0f, this, &TownScene::SceneOutEnd, &TownScene::SceneOutStart, &TownScene::SceneOutStay);
	SceneOutEvent.LoopOn();
	SceneInEvent.CreateTimeEvent(2.0f, this, &TownScene::SceneInEnd, &TownScene::SceneInStart, &TownScene::SceneInStay);
}

void TownScene::SceneUpdate()
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



	if (true == MyLogicValue::bInDoor(MyLogicValue::DTownToRoad, PlayerPos))
	{
		MyLogicValue::NextMap = Map::Road;
		SceneOutEvent.Update();

	
	}	

	if (true == MyLogicValue::bInDoor(MyLogicValue::DTownToStore, PlayerPos))
	{
		MyLogicValue::NextMap = Map::Store;
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

void TownScene::SceneChangeStart()
{
	float4 WSize = MyWindow::GetSize();
	Player->SetPosition(MyLogicValue::GPlayerPos);
	if (Map::Road == MyLogicValue::PreMap)
	{
		MyCamera::SetPosiotion(float4(0.f, 378.f - WSize.hy()));
	}
	else
	{
		MyCamera::SetPosiotion(float4(MyLogicValue::GPlayerPos.x - WSize.hx(), MyLogicValue::GPlayerPos.y - WSize.hy()));
	}
	

}

void TownScene::SceneOutStart()
{
	FadeOut->SetFadeOn(true);
	Player->SetMoveOn(false);
}

void TownScene::SceneOutStay()
{
}

void TownScene::SceneOutEnd()
{
	FadeOut->SetFadeAlpha(0);
	FadeOut->SetFadeOn(false);
	MyLogicValue::PreMap = Map::Town;
	SceneInEvent.Reset();

	if (Map::Road == MyLogicValue::NextMap)
	{
		MyLogicValue::GPlayerPos = MyLogicValue::PPosTownToRoad;
		Player->SetDir(RIGHT);
		Core::SceneManager.ChangeScene(L"RoadScene");
	}
	else if (Map::Store == MyLogicValue::NextMap)
	{
		MyLogicValue::GPlayerPos = MyLogicValue::PPosTownToStore;
		Player->SetDir(DOWN);
		Core::SceneManager.ChangeScene(L"StoreScene");

	}


}

void TownScene::SceneInStart()
{
	Player->SetMoveOn(false);
	FadeIn->SetFadeOn(true);
}

void TownScene::SceneInStay()
{
}

void TownScene::SceneInEnd()
{
	Player->SetMoveOn(true);
	FadeIn->SetFadeOn(false);
}



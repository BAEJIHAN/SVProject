#include "StoreScene.h"
#include <MyCamera.h>
#include <MyInput.h>
#include "MyPlayer.h"
#include "StoreBg.h"
#include "MyLogicValue.h"
#include "Core.h"
#include <MyWindow.h>
#include "FadeInActor.h"
#include "FadeOutActor.h"
#include "MouseObject.h"
#include <MyWindow.h>
#include "ToolUI.h"
#include "Inventory.h"
#include "StoreList.h"
#include <MyResMgr.h>
#include "FarmScene.h"
#include "StoreColmapImage.h"

StoreScene::StoreScene() :BackGround(nullptr), Player(nullptr)
{
}

StoreScene::~StoreScene()
{
}

void StoreScene::Start()
{
	CollisionGroupLink(COLINDEX::BUTTON, COLINDEX::MOUSE);
	MyLogicValue::StoreSceneAddress = this;
	FadeOut = CreateActor<FadeOutActor>();
	FadeIn = CreateActor<FadeInActor>();
	BackGround = CreateActor<StoreBg>();
	colmapimage = CreateActor<StoreColmapImage>();
	Player = CreateActor<MyPlayer>();	
	Player->SetDir(UP);
	Player->SetCurMap(MAP::STORE);

	

	SetMapSize(MyLogicValue::StoreMapSize);
	SetColMap(L"storecolmap.bmp");
	mToolUI = CreateActor< ToolUI>();
	mToolUI->SetPosition({ 400 ,550 });
	Inven = CreateActor<Inventory>();
	Inven->SetPosition(float4(47, 550));

	storelist = CreateActor<StoreList>();
	storelist->SetPosition(float4(340, 270));
	storelist->StoreOff();
	MouseObject* Mouse = CreateActor<MouseObject>();

	SceneOutEvent.CreateTimeEvent(2.0f, this, &StoreScene::SceneOutEnd, &StoreScene::SceneOutStart, &StoreScene::SceneOutStay);
	SceneOutEvent.LoopOn();
	SceneInEvent.CreateTimeEvent(2.0f, this, &StoreScene::SceneInEnd, &StoreScene::SceneInStart, &StoreScene::SceneInStay);
}

void StoreScene::SceneUpdate()
{
	if (true == MyInput::IsDown(L"ToggleColmap"))
	{
		colmapimage->OnOff();
	}


	if (true == MyInput::IsUp(L"LCLICK"))
	{
		
		float4 CheckPos = MyWindow::MousePos()+MyCamera::GetCamPos();		
		MyWinImage* FindImage = MyResMgr::Inst().FindImage(GetColMapName());
		int CheckColor = FindImage->GetPixelColor(CheckPos.ix(), CheckPos.iy());
		if (CheckColor == RGB(0, 255, 0))
		{
			storelist->StoreOn();			
		}
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

	/*static int trigger = 0;
	if (0 == trigger)
	{
		MyCamera::SetPosiotion({ 511.0f-400.0f, 414.0f-300.0f });
		trigger++;
	}*/

	if (true == MyInput::IsDown(L"ToFarmScene"))
	{
		Core::SceneManager.ChangeScene(L"FarmScene");
	}
	SceneInEvent.Update();



	if (true == MyLogicValue::bInDoor(MyLogicValue::DStoreToTown, PlayerPos))
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

void StoreScene::SceneChangeStart()
{

	float4 WSize = MyWindow::GetSize();
	//개발 끝나면 이걸로 바꿔야 함.
	{
	
	Player->SetPosition(MyLogicValue::GPlayerPos);
	MyCamera::SetPosiotion(float4(MyLogicValue::GPlayerPos.x - WSize.hx(), GetMapSize().y-WSize.y));
	}

	//이건 임시
	//float4 WSize = MyWindow::GetSize();
	//Player->SetPosition(float4(511.0f, 414.0f));
	//MyCamera::SetTarget(Player);
	//MyCamera::SetPosiotion(float4(511.0f - WSize.hx(), 414.0f - WSize.y));
}


void StoreScene::SceneOutStart()
{
	FadeOut->SetFadeOn(true);
	Player->SetMoveOn(false);
}

void StoreScene::SceneOutStay()
{
}

void StoreScene::SceneOutEnd()
{
	FadeOut->SetFadeAlpha(0);
	FadeOut->SetFadeOn(false);

	SceneInEvent.Reset();
	MyLogicValue::PreMap=Map::Store;
	if (Map::Town == MyLogicValue::NextMap)
	{
		MyLogicValue::GPlayerPos = MyLogicValue::PPosStoreToTown;
		Player->SetDir(UP);
		Core::SceneManager.ChangeScene(L"TownScene");
	}


}

void StoreScene::SceneInStart()
{
	Player->SetMoveOn(false);
	FadeIn->SetFadeOn(true);
}

void StoreScene::SceneInStay()
{
}

void StoreScene::SceneInEnd()
{
	Player->SetMoveOn(true);
	FadeIn->SetFadeOn(false);
	
}




#include "StoreList.h"
#include <MyRendererBasic.h>
#include <MyInput.h>
#include "Inventory.h"
#include "StoreScene.h"
#include "FarmScene.h"
#include "MyLogicValue.h"
#include <MySound.h>
StoreList::StoreList(): Renderer(nullptr),
 //itemRenderer1(nullptr),
 //itemRenderer2(nullptr),
 //itemRenderer3(nullptr),
 //itemRenderer4(nullptr),
 //itemRenderer5(nullptr),
 //itemRenderer6(nullptr),
 //exitbuttonRenderer(nullptr),
itemInfo1(nullptr),
itemInfo2(nullptr),
itemInfo3(nullptr),
itemInfo4(nullptr),
itemInfo5(nullptr),
itemInfo6(nullptr),
itemCollision1(nullptr),
itemCollision2(nullptr),
itemCollision3(nullptr),
itemCollision4(nullptr),
itemCollision5(nullptr),
itemCollision6(nullptr),
exitbuttonCollision(nullptr)
{
}

StoreList::~StoreList()
{
}



void StoreList::Start()
{
	StoreScene* CurScene = (StoreScene*)GetScene();
	

	Renderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::UI);
	Renderer->TransSetting(L"storelist.bmp", float4(608.0f, 348.0f));
	Renderer->CamEffectOff();



		
	exitbuttonCollision= CreateCollision<MyCollision>(COLINDEX::BUTTON);
	exitbuttonCollision->SetPivotPos(float4(282, -148));
	exitbuttonCollision->SetScale(float4(35.0f, 35.0f));
	
	exitbuttonCollision->AddStayEvent(this, &StoreList::ExitColStay);
	

	//itemRenderer1 = CreateRenderer<MyRendererBasic>(RENDERINDEX::UI);
	//itemRenderer1->TransSetting(L"tb.bmp", float4(252.0f, 90.0f));
	//itemRenderer1->SetPivotPos(float4(-155, -105));
	//itemRenderer1->CamEffectOff();
	//
	//itemRenderer2 = CreateRenderer<MyRendererBasic>(RENDERINDEX::UI);
	//itemRenderer2->TransSetting(L"tb.bmp", float4(252.0f, 90.0f));
	//itemRenderer2->SetPivotPos(float4(110, -105));
	//itemRenderer2->CamEffectOff();
	//
	//itemRenderer3 = CreateRenderer<MyRendererBasic>(RENDERINDEX::UI);
	//itemRenderer3->TransSetting(L"tb.bmp", float4(252.0f, 90.0f));
	//itemRenderer3->SetPivotPos(float4(-155, -1));
	//itemRenderer3->CamEffectOff();

	//itemRenderer4 = CreateRenderer<MyRendererBasic>(RENDERINDEX::UI);
	//itemRenderer4->TransSetting(L"tb.bmp", float4(252.0f, 90.0f));
	//itemRenderer4->SetPivotPos(float4(110, -1));
	//itemRenderer4->CamEffectOff();

	//itemRenderer5 = CreateRenderer<MyRendererBasic>(RENDERINDEX::UI);
	//itemRenderer5->TransSetting(L"tb.bmp", float4(252.0f, 90.0f));
	//itemRenderer5->SetPivotPos(float4(-155, 104));
	//itemRenderer5->CamEffectOff();

	//itemRenderer6 = CreateRenderer<MyRendererBasic>(RENDERINDEX::UI);
	//itemRenderer6->TransSetting(L"tb.bmp", float4(252.0f, 90.0f));
	//itemRenderer6->SetPivotPos(float4(110, 104));
	//itemRenderer6->CamEffectOff();


	itemCollision1 = CreateCollision<MyCollision>(COLINDEX::BUTTON);
	itemCollision1->SetPivotPos(float4(-155, -105));
	itemCollision1->SetScale(float4(252.0f, 90.0f));
	itemCollision1->AddStayEvent(this, &StoreList::Item1ColStay);
	itemCollision1->Off();


	itemCollision2 = CreateCollision<MyCollision>(COLINDEX::BUTTON);
	itemCollision2->SetPivotPos(float4(110, -105));
	itemCollision2->SetScale(float4(252.0f, 90.0f));
	itemCollision2->AddStayEvent(this, &StoreList::Item2ColStay);
	itemCollision2->Off();

	itemCollision3 = CreateCollision<MyCollision>(COLINDEX::BUTTON);
	itemCollision3->SetPivotPos(float4(-155, -1));
	itemCollision3->SetScale(float4(252.0f, 90.0f));
	itemCollision3->AddStayEvent(this, &StoreList::Item3ColStay);
	itemCollision3->Off();

	itemCollision4 = CreateCollision<MyCollision>(COLINDEX::BUTTON);
	itemCollision4->SetPivotPos(float4(110, -1));
	itemCollision4->SetScale(float4(252.0f, 90.0f));
	itemCollision4->AddStayEvent(this, &StoreList::Item4ColStay);
	itemCollision4->Off();


	itemCollision5 = CreateCollision<MyCollision>(COLINDEX::BUTTON);
	itemCollision5->SetPivotPos(float4(-155, 104));
	itemCollision5->SetScale(float4(252.0f, 90.0f));
	itemCollision5->AddStayEvent(this, &StoreList::Item5ColStay);
	itemCollision5->Off();

	itemCollision6 = CreateCollision<MyCollision>(COLINDEX::BUTTON);
	itemCollision6->SetPivotPos(float4(110, 104));
	itemCollision6->SetScale(float4(252.0f, 90.0f));
	itemCollision6->AddStayEvent(this, &StoreList::Item6ColStay);
	itemCollision6->Off();


	
}

void StoreList::ExitColStay(MyCollision* _this, MyCollision* _other)
{
	
	if (true == MyInput::IsDown(L"LCLICK"))
	{		
		StoreOff();
	}
}

void StoreList::Item1ColStay(MyCollision* _this, MyCollision* _other)
{
	
	if (true == MyInput::IsDown(L"LCLICK"))
	{
		FarmScene* farmscene = MyLogicValue::FarmSceneAddress;
		StoreScene* storescene = MyLogicValue::StoreSceneAddress;
		Inventory* farmInven = farmscene->GetInven();
		Inventory* storeInven = storescene->GetInven();
		
		farmInven->AddSeed(ITEMINDEX::POTATOSEED);
		storeInven->AddSeed(ITEMINDEX::POTATOSEED);
		
		MySound::Play(L"buttonclick.mp3");
		
	}
}

void StoreList::Item2ColStay(MyCollision* _this, MyCollision* _other)
{

	if (true == MyInput::IsDown(L"LCLICK"))
	{
		FarmScene* farmscene = MyLogicValue::FarmSceneAddress;
		StoreScene* storescene = MyLogicValue::StoreSceneAddress;
		Inventory* farmInven = farmscene->GetInven();
		Inventory* storeInven = storescene->GetInven();
	
		
		farmInven->AddSeed(ITEMINDEX::EGGPLANTSEED);
		storeInven->AddSeed(ITEMINDEX::EGGPLANTSEED);
		
		MySound::Play(L"buttonclick.mp3");
	}
}

void StoreList::Item3ColStay(MyCollision* _this, MyCollision* _other)
{
	
	if (true == MyInput::IsDown(L"LCLICK"))
	{
		FarmScene* farmscene = MyLogicValue::FarmSceneAddress;
		StoreScene* storescene = MyLogicValue::StoreSceneAddress;
		Inventory* farmInven = farmscene->GetInven();
		Inventory* storeInven = storescene->GetInven();

	


		farmInven->AddSeed(ITEMINDEX::RADISHSEED);
		storeInven->AddSeed(ITEMINDEX::RADISHSEED);
		
		MySound::Play(L"buttonclick.mp3");
	}
}

void StoreList::Item4ColStay(MyCollision* _this, MyCollision* _other)
{
	if (true == MyInput::IsDown(L"LCLICK"))
	{
		FarmScene* farmscene = MyLogicValue::FarmSceneAddress;
		StoreScene* storescene = MyLogicValue::StoreSceneAddress;
		Inventory* farmInven = farmscene->GetInven();
		Inventory* storeInven = storescene->GetInven();




		farmInven->AddSeed(ITEMINDEX::TOMATOSEED);
		storeInven->AddSeed(ITEMINDEX::TOMATOSEED);

		MySound::Play(L"buttonclick.mp3");
	}
}

void StoreList::Item5ColStay(MyCollision* _this, MyCollision* _other)
{
	if (true == MyInput::IsDown(L"LCLICK"))
	{
		FarmScene* farmscene = MyLogicValue::FarmSceneAddress;
		StoreScene* storescene = MyLogicValue::StoreSceneAddress;
		Inventory* farmInven = farmscene->GetInven();
		Inventory* storeInven = storescene->GetInven();




		farmInven->AddSeed(ITEMINDEX::CABBAGESEED);
		storeInven->AddSeed(ITEMINDEX::CABBAGESEED);

		MySound::Play(L"buttonclick.mp3");
	}
}

void StoreList::Item6ColStay(MyCollision* _this, MyCollision* _other)
{
	if (true == MyInput::IsDown(L"LCLICK"))
	{
		FarmScene* farmscene = MyLogicValue::FarmSceneAddress;
		StoreScene* storescene = MyLogicValue::StoreSceneAddress;
		Inventory* farmInven = farmscene->GetInven();
		Inventory* storeInven = storescene->GetInven();




		farmInven->AddSeed(ITEMINDEX::BLUEBERRYSEED);
		storeInven->AddSeed(ITEMINDEX::BLUEBERRYSEED);

		MySound::Play(L"buttonclick.mp3");
	}
}



void StoreList::StoreOff()
{
	if (nullptr != Renderer)
	{
		Renderer->Off();
		//exitbuttonRenderer->Off();
		exitbuttonCollision->Off();
		itemCollision1->Off();
		itemCollision2->Off();
		itemCollision3->Off();
		itemCollision4->Off();
		itemCollision5->Off();
		itemCollision6->Off();
	}
		
}

void StoreList::StoreOn()
{
	if (nullptr != Renderer)
	{
		Renderer->On();
		//exitbuttonRenderer->On();
		exitbuttonCollision->On();
		itemCollision1->On();
		itemCollision2->On();
		itemCollision3->On();
		itemCollision4->On();
		itemCollision5->On();
		itemCollision6->On();
	}
		
}
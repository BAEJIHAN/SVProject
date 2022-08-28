#include "TitleBackGround.h"
#include <MyRendererBasic.h>
#include <MyCollision.h>
#include <MyInput.h>
#include "Core.h"
#include <MySound.h>
TitleBackGround::TitleBackGround():
SkyRenderer(nullptr),
StardewRenderer(nullptr),
StartButtonRenderer(nullptr),
EditButtonRenderer(nullptr)
{
}

TitleBackGround::~TitleBackGround()
{
}

void TitleBackGround::Start()
{
	SkyRenderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::BACKGROUND);
	SkyRenderer->TransSetting(L"sky.bmp", float4(800, 600));
	SkyRenderer->CamEffectOff();
	SkyRenderer->SetPivotPos(float4(400, 300));


	StardewRenderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::TILEOBJECT);
	StardewRenderer->TransSetting(L"title.bmp", float4(690, 355));
	StardewRenderer->CamEffectOff();
	StardewRenderer->SetPivotPos(float4(400, 200));


	StartButtonRenderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::TILEOBJECT);
	StartButtonRenderer->TransSetting(L"start.bmp", float4(149, 123));
	StartButtonRenderer->CamEffectOff();
	StartButtonRenderer->SetPivotPos(float4(200,500));


	EditButtonRenderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::TILEOBJECT);
	EditButtonRenderer->TransSetting(L"edit.bmp", float4(149, 123));
	EditButtonRenderer->CamEffectOff();
	EditButtonRenderer->SetPivotPos(float4(600, 500));


	StartButtonCol = CreateCollision<MyCollision>(COLINDEX::BUTTON);
	StartButtonCol->SetScale(float4(149, 123));
	StartButtonCol->SetPivotPos(float4(200, 500));
	StartButtonCol->AddStayEvent(this, &TitleBackGround::StartColStay);
	StartButtonCol->AddStartEvent(this, &TitleBackGround::StartColStart);
	StartButtonCol->AddEndEvent(this, &TitleBackGround::StartColEnd);

	EditButtonCol = CreateCollision<MyCollision>(COLINDEX::BUTTON);
	EditButtonCol->SetScale(float4(149, 123));
	EditButtonCol->SetPivotPos(float4(600, 500));
	EditButtonCol->AddStayEvent(this, &TitleBackGround::EditColStay);
	EditButtonCol->AddStartEvent(this, &TitleBackGround::EditColStart);
	EditButtonCol->AddEndEvent(this, &TitleBackGround::EditColEnd);



}



void TitleBackGround::StartColStart(MyCollision* _this, MyCollision* _other)
{
	MySound::Play(L"buttoncol.mp3");
	StartButtonRenderer->SetRenderScale(float4(186, 153));
	StartButtonCol->SetScale(float4(186, 153));
}





void TitleBackGround::StartColStay(MyCollision* _this, MyCollision* _other)
{
	if (true == MyInput::IsDown(L"LCLICK"))
	{
		MySound::Play(L"buttonclick.mp3");
		Core::SceneManager.ChangeScene(L"HouseScene");
	}
}

void TitleBackGround::StartColEnd(MyCollision* _this, MyCollision* _other)
{
	StartButtonRenderer->SetRenderScale(float4(149, 123));
	StartButtonCol->SetScale(float4(149, 123));
}

void TitleBackGround::EditColStart(MyCollision* _this, MyCollision* _other)
{
	MySound::Play(L"buttoncol.mp3");
	EditButtonRenderer->SetRenderScale(float4(186, 153));
	EditButtonCol->SetScale(float4(186, 153));
}


void TitleBackGround::EditColStay(MyCollision* _this, MyCollision* _other)
{
	if (true == MyInput::IsDown(L"LCLICK"))
	{
		MySound::Play(L"buttonclick.mp3");
		Core::SceneManager.ChangeScene(L"MapEditorScene");
	}
}

void TitleBackGround::EditColEnd(MyCollision* _this, MyCollision* _other)
{
	EditButtonRenderer->SetRenderScale(float4(149, 123));
	EditButtonCol->SetScale(float4(149, 123));
}


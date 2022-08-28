#include "FadeInActor.h"
#include <MyRendererBasic.h>
#include <MyTimer.h>

FadeInActor::FadeInActor() : mRender(nullptr), bFadeOn(false)
{

}

FadeInActor::~FadeInActor()
{

}


void FadeInActor::Start()
{
	{
		mRender = CreateRenderer<MyRendererBasic>(40000);
		mRender->CamEffectOff();
		mRender->SetPivotPos({ 1280 * 0.5f, 720 * 0.5f });
		mRender->TransSetting(L"fade.bmp", { 1280, 720 });
		mRender->SetAlpha(0);
		
	}

	FadeInTimer.CreateTimeEvent(1.0f, this, nullptr, &FadeInActor::FadeInStart, &FadeInActor::FadeInStart);
	FadeInTimer.CreateTimeEvent(2.0f, this, &FadeInActor::FadeInEnd, &FadeInActor::FadeInStart, &FadeInActor::FadeInStay);
}

void FadeInActor::Update()
{
	if (true == bFadeOn)
	{
		FadeInTimer.Update();
	}
}


void FadeInActor::FadeInStart()
{
	Alpha = 255.0f;
	mRender->SetAlpha(static_cast<int>(Alpha));
}

void FadeInActor::FadeInStay()
{
	Alpha -= MyTimer::MainTimer.GetFDeltaTime() * 255.0f;

	if (0 >= Alpha)
	{
		Alpha = 0.0f;
	}

	mRender->SetAlpha(static_cast<int>(Alpha));
}

void FadeInActor::FadeInEnd()
{
	mRender->SetAlpha(0);
}



void FadeInActor::SetFadeAlpha(unsigned char _Alpha)
{
	mRender->SetAlpha(_Alpha);
}

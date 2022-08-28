#include "FadeOutActor.h"
#include <MyRendererBasic.h>
#include <MyTimer.h>

FadeOutActor::FadeOutActor() : mRender(nullptr), bFadeOn(false)
{

}

FadeOutActor::~FadeOutActor()
{

}


void FadeOutActor::Start()
{
	{
		mRender = CreateRenderer<MyRendererBasic>(40000);
		mRender->CamEffectOff();
		mRender->SetPivotPos({ 1280 * 0.5f, 720 * 0.5f });
		mRender->TransSetting(L"fade.bmp", { 1280, 720 });
		mRender->SetAlpha(0);
		// NewRenderer->SetAlpha(100);
		// NewRenderer->SetCutPosAndSize({0,0}, { 768.0f, 762.0f });
		// 이상황에서
	}

	FadeOutTimer.CreateTimeEvent(2.0f, this, &FadeOutActor::FadeOutEnd, &FadeOutActor::FadeOutStart, &FadeOutActor::FadeOutStay);
	
}


void FadeOutActor::Update()
{
	if (true == bFadeOn)
		FadeOutTimer.Update();
}

void FadeOutActor::FadeOutStart()
{
	Alpha = 0.0f;
}

void FadeOutActor::FadeOutStay()
{
	Alpha += MyTimer::MainTimer.GetFDeltaTime() * 1.5f;
	int iAlpha = 0;
	if (2.55f <= Alpha)
	{
		Alpha = 2.55f;
		iAlpha = 255;
	}
	else {
		iAlpha = (int)(Alpha * 100.0f);
	}


	mRender->SetAlpha(iAlpha);
}

void FadeOutActor::FadeOutEnd()
{
	mRender->SetAlpha(255);
}




void FadeOutActor::SetFadeAlpha(unsigned char _Alpha)
{
	mRender->SetAlpha(_Alpha);
}

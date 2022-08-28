#include "EnergyUI.h"
#include <MyRendererBasic.h>
#include "FarmScene.h"
#include "MyLogicValue.h"
EnergyUI::EnergyUI()
{
}

EnergyUI::~EnergyUI()
{
}

void EnergyUI::Start()
{
	mainrender = CreateRenderer<MyRendererBasic>(RENDERINDEX::UI);
	mainrender->TransSetting(L"energyui.bmp", float4(48, 174));
	mainrender->CamEffectOff();

	barrender = CreateRenderer<MyRendererBasic>(RENDERINDEX::UIBUTTON);
	barrender->TransSetting(L"energybar.bmp", float4(24, 128));
	barrender->SetPivotPos(float4(0, 17));
	barrender->CamEffectOff();
}

void EnergyUI::SetBar(int _energy)
{
	float energy = (float)_energy;
	barrender->SetPivotPos(float4(0.f, 17.f+(128-128 * (energy / 100.f))/2));
	barrender->SetRenderScale(float4(24.f, 128*(energy /100.f)));
}



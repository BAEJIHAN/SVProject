#include "Selected.h"
#include <MyRendererBasic.h>
Selected::Selected()
{
}

Selected::~Selected()
{
}

void Selected::Start()
{
	renderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::SELECTEDUI);
	renderer->TransSetting(L"selected.bmp", float4(56, 56));
	renderer->CamEffectOff();
}

void Selected::SetPivot(float4 _pivot)
{
	renderer->SetPivotPos(_pivot);
}

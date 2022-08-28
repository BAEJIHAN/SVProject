#include "FarmBg.h"
#include <MyRendererBasic.h>
#include"MyLogicValue.h"
FarmBg::FarmBg()
{
}

FarmBg::~FarmBg()
{
}

void FarmBg::Start()
{
	MyRendererBasic* NewRenderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::BACKGROUND);

	NewRenderer->BitSetting(L"farmmap.bmp", MyLogicValue::FarmMapSize);
	NewRenderer->SetPivotPos(MyLogicValue::FarmMapSize * 0.5);
}


#include "TownBg.h"
#include <MyRendererBasic.h>
#include"MyLogicValue.h"
TownBg::TownBg()
{
}

TownBg::~TownBg()
{
}


void TownBg::Start()
{
	MyRendererBasic* NewRenderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::BACKGROUND);

	NewRenderer->BitSetting(L"townmap.bmp", MyLogicValue::TownMapSize);
	NewRenderer->SetPivotPos(MyLogicValue::TownMapSize*0.5);
}

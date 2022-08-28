#include "HouseBg.h"
#include <MyRendererBasic.h>
#include"MyLogicValue.h"
HouseBg::HouseBg()
{
}

HouseBg::~HouseBg()
{
}

void HouseBg::Start()
{
	MyRendererBasic* NewRenderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::BACKGROUND);

	NewRenderer->BitSetting(L"housemap.bmp", MyLogicValue::HouseMapSize);
	NewRenderer->SetPivotPos(MyLogicValue::HouseMapSize * 0.5);
}

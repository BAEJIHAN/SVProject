#include "RoadBg.h"
#include <MyRendererBasic.h>
#include"MyLogicValue.h"
RoadBg::RoadBg()
{
}

RoadBg::~RoadBg()
{
}

void RoadBg::Start()
{
	MyRendererBasic* NewRenderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::BACKGROUND);

	NewRenderer->BitSetting(L"roadmap.bmp", MyLogicValue::RoadMapSize);
	NewRenderer->SetPivotPos(MyLogicValue::RoadMapSize * 0.5);
}
#include "StoreBg.h"
#include <MyRendererBasic.h>
#include"MyLogicValue.h"
StoreBg::StoreBg()
{
}

StoreBg::~StoreBg()
{
}

void StoreBg::Start()
{
	MyRendererBasic* NewRenderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::BACKGROUND);

	NewRenderer->BitSetting(L"storemap.bmp", MyLogicValue::StoreMapSize);
	NewRenderer->SetPivotPos(MyLogicValue::StoreMapSize * 0.5);
}
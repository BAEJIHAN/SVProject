#include "StoreColmapImage.h"
#include <MyRendererBasic.h>
#include "MyLogicValue.h"
StoreColmapImage::StoreColmapImage() : bOnOff(false)
{
}

StoreColmapImage::~StoreColmapImage()
{
}

void StoreColmapImage::Start()
{
	renderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::DEBUG);
	renderer->TransSetting(L"storecolmap.bmp", MyLogicValue::StoreMapSize);
	renderer->SetPivotPos(MyLogicValue::StoreMapSize * 0.5);
	renderer->Off();
}

void StoreColmapImage::OnOff()
{
	if (false == bOnOff)
	{
		bOnOff = true;
		renderer->On();
	}
	else
	{
		bOnOff = false;
		renderer->Off();
	}
}
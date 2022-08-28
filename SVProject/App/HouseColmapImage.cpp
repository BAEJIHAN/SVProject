#include "HouseColmapImage.h"
#include <MyRendererBasic.h>
#include "MyLogicValue.h"
HouseColmapImage::HouseColmapImage() : bOnOff(false)
{
}

HouseColmapImage::~HouseColmapImage()
{
}

void HouseColmapImage::Start()
{
	renderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::DEBUG);
	renderer->TransSetting(L"housecolmap.bmp", MyLogicValue::HouseMapSize);
	renderer->SetPivotPos(MyLogicValue::HouseMapSize * 0.5);
	renderer->Off();
}

void HouseColmapImage::OnOff()
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

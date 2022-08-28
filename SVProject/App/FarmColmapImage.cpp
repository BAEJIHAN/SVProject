#include "FarmColmapImage.h"
#include <MyRendererBasic.h>
#include "MyLogicValue.h"
FarmColmapImage::FarmColmapImage() : bOnOff(false)
{
}

FarmColmapImage::~FarmColmapImage()
{
}

void FarmColmapImage::Start()
{
	renderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::DEBUG);
	renderer->TransSetting(L"farmcolmap.bmp", MyLogicValue::FarmMapSize);
	renderer->SetPivotPos(MyLogicValue::FarmMapSize * 0.5);
	renderer->Off();
}

void FarmColmapImage::OnOff()
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
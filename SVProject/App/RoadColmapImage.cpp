#include "RoadColmapImage.h"

#include <MyRendererBasic.h>
#include "MyLogicValue.h"
RoadColmapImage::RoadColmapImage() : bOnOff(false)
{
}

RoadColmapImage::~RoadColmapImage()
{
}

void RoadColmapImage::Start()
{
	renderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::DEBUG);
	renderer->TransSetting(L"roadcolmap.bmp", MyLogicValue::RoadMapSize);
	renderer->SetPivotPos(MyLogicValue::RoadMapSize * 0.5);
	renderer->Off();
}

void RoadColmapImage::OnOff()
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
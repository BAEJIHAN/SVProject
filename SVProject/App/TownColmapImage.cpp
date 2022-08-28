#include "TownColmapImage.h"
#include <MyRendererBasic.h>
#include "MyLogicValue.h"

TownColmapImage::TownColmapImage() : bOnOff(false)
{
}

TownColmapImage::~TownColmapImage()
{
}

void TownColmapImage::Start()
{
	renderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::DEBUG);
	renderer->TransSetting(L"towncolmap.bmp", MyLogicValue::TownMapSize);
	renderer->SetPivotPos(MyLogicValue::TownMapSize * 0.5);
	renderer->Off();
}

void TownColmapImage::OnOff()
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
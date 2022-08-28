#include "GrassItem.h"
#include <MyRendererBasic.h>
#include "FarmScene.h"
#include "BagUI.h"
#include "MyLogicValue.h"
#include <MySound.h>
GrassItem::GrassItem()
{
}

GrassItem::~GrassItem()
{
}

void GrassItem::Start()
{
	fielditemindex = ITEMINDEX::GRASS;
	renderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::TILEOBJECT);
	renderer->TransSetting(L"grassitem.bmp", float4(50, 53));
}

void GrassItem::DeathTask()
{
	BagUI* bag = MyLogicValue::FarmSceneAddress->GetBag();
	bag->AddItem(this);
	MySound::Play(L"getitem.mp3");
}

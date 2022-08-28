#include "StoneItem.h"
#include <MyRendererBasic.h>
#include "FarmScene.h"
#include "BagUI.h"
#include "MyLogicValue.h"
#include <MySound.h>
StoneItem::StoneItem()
{
}

StoneItem::~StoneItem()
{
}

void StoneItem::Start()
{
	fielditemindex = ITEMINDEX::STONE;
	renderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::TILEOBJECT);
	renderer->TransSetting(L"stoneitem.bmp", float4(47, 44));
}

void StoneItem::DeathTask()
{
	BagUI* bag = MyLogicValue::FarmSceneAddress->GetBag();
	bag->AddItem(this);
	MySound::Play(L"getitem.mp3");
}

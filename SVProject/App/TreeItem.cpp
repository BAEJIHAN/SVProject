#include "TreeItem.h"
#include <MyRendererBasic.h>
#include "FarmScene.h"
#include "BagUI.h"
#include "MyLogicValue.h"
#include <MySound.h>
TreeItem::TreeItem()
{
}

TreeItem::~TreeItem()
{
}

void TreeItem::Start()
{
	fielditemindex = ITEMINDEX::TREE;
	renderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::TILEOBJECT);
	renderer->TransSetting(L"treeitem.bmp", float4(51, 46));
}

void TreeItem::DeathTask()
{
	BagUI* bag = MyLogicValue::FarmSceneAddress->GetBag();
	bag->AddItem(this);
	MySound::Play(L"getitem.mp3");
}

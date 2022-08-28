#include "blueberry.h"
#include "FarmScene.h"
#include "StoreScene.h"
#include "MyLogicValue.h"
#include "BagUI.h"
blueberry::blueberry()
{
}

blueberry::~blueberry()
{
}


void blueberry::Start()
{
    cropitemindex = ITEMINDEX::BLUEBERRY;
    CropImage(L"blueberry.bmp", 1.0f, { 100, 100 }, 0, 7, { 0, -30 });
}

void blueberry::DeathTask()
{
    FarmScene* farmscene = MyLogicValue::FarmSceneAddress;
    StoreScene* storescene = MyLogicValue::StoreSceneAddress;

    BagUI* bag = farmscene->GetBag();
    bag->AddCrop(this);

}
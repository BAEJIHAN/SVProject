#include "cabbage.h"
#include "FarmScene.h"
#include "StoreScene.h"
#include "MyLogicValue.h"
#include "BagUI.h"
cabbage::cabbage()
{
}

cabbage::~cabbage()
{
}

void cabbage::Start()
{
    cropitemindex = ITEMINDEX::CABBAGE;
    CropImage(L"cabbage.bmp", 1.0f, { 100, 100 }, 0, 7);
}

void cabbage::DeathTask()
{
    FarmScene* farmscene = MyLogicValue::FarmSceneAddress;
    StoreScene* storescene = MyLogicValue::StoreSceneAddress;
     
    BagUI* bag = farmscene->GetBag();
    bag->AddCrop(this);

}

#include "eggplant.h"
#include "FarmScene.h"
#include "StoreScene.h"
#include "MyLogicValue.h"
#include "BagUI.h"
eggplant::eggplant()
{
}

eggplant::~eggplant()
{
}

void eggplant::Start()
{
    cropitemindex = ITEMINDEX::EGGPLANT;
    CropImage(L"eggplant.bmp", 1.0f, { 100, 100 }, 0, 7);
}

void eggplant::DeathTask()
{
    FarmScene* farmscene = MyLogicValue::FarmSceneAddress;
    StoreScene* storescene = MyLogicValue::StoreSceneAddress;

    BagUI* bag = farmscene->GetBag();
    bag->AddCrop(this);

}
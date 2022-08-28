#include "tomato.h"
#include "FarmScene.h"
#include "StoreScene.h"
#include "MyLogicValue.h"
#include "BagUI.h"
tomato::tomato()
{
}

tomato::~tomato()
{
}

void tomato::Start()
{
    cropitemindex = ITEMINDEX::TOMATO;
    CropImage(L"tomato.bmp", 1.0f, { 100, 100 }, 0, 7, { 0, -30 });
}

void tomato::DeathTask()
{
    FarmScene* farmscene = MyLogicValue::FarmSceneAddress;
    StoreScene* storescene = MyLogicValue::StoreSceneAddress;

    BagUI* bag = farmscene->GetBag();
    bag->AddCrop(this);

}

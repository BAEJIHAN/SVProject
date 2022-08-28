#include "radish.h"
#include "FarmScene.h"
#include "StoreScene.h"
#include "MyLogicValue.h"
#include "BagUI.h"
// Static Var
// Static Func

// constructer destructer
radish::radish()
{
}

radish::~radish()
{
}

//member Func

void radish::Start()
{   
    cropitemindex = ITEMINDEX::RADISH;
    CropImage(L"radish.bmp", 1.0f, { 100, 100 }, 0, 6);
}

void radish::DeathTask()
{
    FarmScene* farmscene = MyLogicValue::FarmSceneAddress;
    StoreScene* storescene = MyLogicValue::StoreSceneAddress;
    
    BagUI* bag = farmscene->GetBag();
    bag->AddCrop(this);

}

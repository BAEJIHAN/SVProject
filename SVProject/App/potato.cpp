#include "potato.h"
#include "FarmScene.h"
#include "StoreScene.h"
#include "MyLogicValue.h"
#include "BagUI.h"
// Static Var
// Static Func

// constructer destructer
potato::potato()
{
}

potato::~potato()
{
}

//member Func

void potato::Start()
{
    
    cropitemindex = ITEMINDEX::POTATO;
    CropImage(L"potato.bmp", 1.0f, { 100, 100 }, 0, 7);
}

void potato::DeathTask()
{
    FarmScene* farmscene = MyLogicValue::FarmSceneAddress;
    StoreScene* storescene = MyLogicValue::StoreSceneAddress;
    
    BagUI* bag = farmscene->GetBag();
    bag->AddCrop(this);
   
 
}
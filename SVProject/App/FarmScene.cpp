#include "FarmScene.h"

#include <MyCamera.h>
#include <MyInput.h>
#include <MyRendererTile.h>
#include <MyWindow.h>
#include <MyFile.h>

#include "StoreScene.h"
#include "MyEditorScene.h"
#include "MyPlayer.h"
#include "FarmBg.h"
#include "MyLogicValue.h"
#include "Core.h"
#include "FadeInActor.h"
#include "FadeOutActor.h"
#include "MyTileBackGround.h"
#include "FarmColmapImage.h"

#include "Selected.h"
#include "ToolUI.h"
#include "Inventory.h"
#include "BagUI.h"
#include "MouseObject.h"
#include "EnergyUI.h"

#include "potato.h"
#include "radish.h"
#include "cabbage.h"
#include "blueberry.h"
#include "eggplant.h"
#include "tomato.h"
#include "Grass1.h"
#include "Grass2.h"
#include "Grass3.h"
#include "Grass4.h"
#include "Stone1.h"
#include "Stone2.h"
#include "Tree.h"
#include "OtherBase.h"


SoundPlayer FarmScene::bgm;

FarmScene::FarmScene() :BackGround(nullptr), Player(nullptr), mToolUI(nullptr),
selected(nullptr), energy(nullptr), bag(nullptr), TileBackGround(nullptr), Inven(nullptr), FadeOut(nullptr), FadeIn(nullptr)
{
}

FarmScene::~FarmScene()
{
}

void FarmScene::Start()
{
    // 충돌해라.
    CollisionGroupLink(COLINDEX::BUTTON, COLINDEX::MOUSE);
   /* CollisionGroupLink(COLINDEX::PLAYER, COLINDEX::OBJECT);*/
    MyLogicValue::FarmSceneAddress = this;
    TileBackGround = CreateActor<MyTileBackGround>();
    FarmScene::LoadTile();
    colmapimage = CreateActor<FarmColmapImage>();
    
    mToolUI = CreateActor< ToolUI>();
    mToolUI->SetPosition({ 400 ,550 });
    selected = CreateActor<Selected>();
    selected->SetPosition({ 50 ,550 });
    bag = CreateActor<BagUI>();
    bag->SetPosition({ 400 , 100 });
    energy = CreateActor< EnergyUI>();
    energy->SetPosition({ 770 ,410 });


    FadeOut = CreateActor<FadeOutActor>();
    FadeIn = CreateActor<FadeInActor>();
    BackGround = CreateActor<FarmBg>();
    Player = CreateActor<MyPlayer>();
    Player->SetCurMap(MAP::FARM);

    MouseObject* Mouse = CreateActor<MouseObject>();
    // inven->SetPosition(float4(47, 550));

    Inven = CreateActor<Inventory>();
    Inven->SetPosition(float4(47, 550));


    SetColMap(L"farmcolmap.bmp");
    SetMapSize(MyLogicValue::FarmMapSize);


    SceneOutEvent.CreateTimeEvent(2.0f, this, &FarmScene::SceneOutEnd, &FarmScene::SceneOutStart, &FarmScene::SceneOutStay);
    SceneOutEvent.LoopOn();
    SceneInEvent.CreateTimeEvent(2.0f, this, &FarmScene::SceneInEnd, &FarmScene::SceneInStart, &FarmScene::SceneInStay);

    MyInput::CreateKey(L"TileCheck", VK_LBUTTON);
    MyInput::CreateKey(L"ObjectCheck", VK_RBUTTON);

    MyCamera::SetPosiotion({ 500, 500 });
}

void FarmScene::SceneUpdate()
{
    if (true == MyInput::IsDown(L"ToggleColmap"))
    {
        colmapimage->OnOff();
    }

    if (true == MyInput::IsDown(L"HP"))
    {
        Player->ZeroEnergy();
        energy->SetBar(0);
    }
    
    //if (true == MyInput::IsDown(L"ObjectCheck"))
    //{
    //    //bgm.Stop();
    //    float4 PlantPos = Player->GetPosition();
    //    MyRendererTile::Tile* Tile = TileBackGround->TileRenderer->GetTile(PlantPos);
    //    if ((STATE::DIGGED == Tile->GetState()
    //        || STATE::WET == Tile->GetState())
    //        && false == Tile->IsOccupied)
    //    {
    //        CROP cropvar = Player->GetCrop();
    //        Crop* Test;
    //        // 타일맵으로 깔아라.
    //        switch (cropvar)
    //        {
    //        case CROP::CABBAGE:
    //        {
    //            Test = CreateActor<cabbage>();
    //            break;
    //        }               
    //        case CROP::POTATO:
    //        {
    //            Test = CreateActor<potato>();
    //            break;
    //        }                
    //        case CROP::RADISH:
    //        {
    //            Test = CreateActor<radish>();
    //            break;
    //        }   
    //        case CROP::TOMATO:
    //        {
    //            Test = CreateActor<tomato>();
    //            break;
    //        }
    //        case CROP::BLUEBERRY:
    //        {
    //            Test = CreateActor<blueberry>();
    //            break;
    //        }
    //        case CROP::EGGPLANT:
    //        {
    //            Test = CreateActor<eggplant>();
    //            break;
    //        }
    //        default:
    //            Test = nullptr;
    //            break;
    //        }
    //        
    //       
    //        PlantPos.x = (float)((int)PlantPos.x - (int)PlantPos.x % 64);
    //        PlantPos.y = (float)((int)PlantPos.y - (int)PlantPos.y % 64);
    //        PlantPos += 32.0f;
    //        Test->SetPosition(PlantPos);
    //        
    //        Tile->MyActor = Test;
    //        Tile->IsOccupied = true;
    //        Tile->kind = KIND::CROP;
    //        Test->SetTile(Tile);
    //    


    //    }
    //}

    if (true == MyInput::IsUp(L"ToggleBag"))
    {
        if (true == bag->bbagon)
        {
            bag->BagOff();
        }
        else if (false == bag->bbagon)
        {
            bag->BagOn();
        }
       
      
    }
    

    float4 PlayerPos = Player->GetPosition();
    if (true == MyInput::IsUp(L"TOGGLECAMERA"))
    {
        if (nullptr == MyCamera::GetTarget())
        {
            float4 WSize = MyWindow::GetSize();
            MyCamera::SetTarget(Player);
            MyCamera::SetPosiotion(float4(PlayerPos.x - WSize.hx(), PlayerPos.y - WSize.hy()));
        }
        else
        {
            MyCamera::SetTarget(nullptr);

        }
    }
    MyCamera::Update();

    //이 부분 개발 끝나면 지우기.
   /* static int trigger = 0;
    if (0 == trigger)
    {   
        MyCamera::SetPosiotion({ 1618-400, 601-300 });
        trigger++;
    }*/
   
    
    SceneInEvent.Update();

    if (true == MyLogicValue::bInDoor(MyLogicValue::DFarmToHouse, PlayerPos))
    {
        MyLogicValue::NextMap = Map::House;
        SceneOutEvent.Update();
    }
    if (true == MyLogicValue::bInDoor(MyLogicValue::DFarmToRoad, PlayerPos))
    {
        MyLogicValue::NextMap = Map::Road;
        SceneOutEvent.Update();
    }

    if (true == MyInput::IsDown(L"DEBUGON"))
    {
        Player->SetDebugOnOff(true);
    }
    if (true == MyInput::IsDown(L"DEBUGOFF"))
    {
        Player->SetDebugOnOff(false);
    }


    if (true == MyInput::IsDown(L"ToStoreScene"))
    {
        Core::SceneManager.ChangeScene(L"StoreScene");
    }
}

void FarmScene::SceneChangeStart()
{
    float4 WSize = MyWindow::GetSize();
  



    //이 부분 임시
  /*  Player->SetPosition(float4(1618, 601));
    float4 PlayerPos = Player->GetPosition();

    MyCamera::SetTarget(Player);*/
   
    
    //개발 끝나고 이걸로 바꿔야 함.
    {     
       
        Player->SetPosition(MyLogicValue::GPlayerPos);
    }



    if (Map::Road == MyLogicValue::PreMap)
    {
        MyCamera::SetPosiotion(float4(GetMapSize().x - WSize.x, 711.f - WSize.hy()));
    }
    else
    {
        MyCamera::SetPosiotion(float4(MyLogicValue::GPlayerPos.x - WSize.hx(), MyLogicValue::GPlayerPos.y - WSize.hy()));
    }

}

void FarmScene::SceneOutStart()
{
    FadeOut->SetFadeOn(true);
    Player->SetMoveOn(false);
}

void FarmScene::SceneOutStay()
{
}

void FarmScene::SceneOutEnd()
{


    FadeOut->SetFadeAlpha(0);
    FadeOut->SetFadeOn(false);
    MyLogicValue::PreMap = Map::Farm;
    SceneInEvent.Reset();

    if (Map::House == MyLogicValue::NextMap)
    {
        MyLogicValue::GPlayerPos = MyLogicValue::PPosFarmToHouse;
        Player->SetDir(DOWN);
        Core::SceneManager.ChangeScene(L"HouseScene");
    }
    else if (Map::Road == MyLogicValue::NextMap)
    {
        MyLogicValue::GPlayerPos = MyLogicValue::PPosFarmToRoad;
        Player->SetDir(LEFT);
        Core::SceneManager.ChangeScene(L"RoadScene");
    }    
   
}

void FarmScene::SceneInStart()
{
    Player->SetMoveOn(false);
    FadeIn->SetFadeOn(true);

}

void FarmScene::SceneInStay()
{
}

void FarmScene::SceneInEnd()
{
    Player->SetMoveOn(true);
    FadeIn->SetFadeOn(false);
    
    
}

void FarmScene::LoadTile()
{
    MyFile File = MyFile(L"..\\Res\\MapSaveData.Data");
    File.Open(L"rb");
    File >> MyEditorScene::m_SaveTile;

   
    for (auto& TileData : MyEditorScene::m_SaveTile)
    {
        float4 TilePos;
        TilePos.Int64ToPos(TileData.first);

        TILEVAR tilevar = TileData.second;

        switch (tilevar)
        {
        case TILEVAR::GRASS1:
        {
            OtherBase* Test = CreateActor<Grass1>();
            MakeObject(TilePos, tilevar, Test);
            break;
        }
        case TILEVAR::GRASS2:
        {
            OtherBase* Test = CreateActor<Grass2>();
            MakeObject(TilePos, tilevar, Test);
            break;
        }
        case TILEVAR::GRASS3:
        {
            OtherBase* Test = CreateActor<Grass3>();
            MakeObject(TilePos, tilevar, Test);
            break;
        }
        case TILEVAR::GRASS4:
        {
            OtherBase* Test = CreateActor<Grass4>();
            MakeObject(TilePos, tilevar, Test);
            break;
        }
        case TILEVAR::STONE1:
        {
            OtherBase* Test = CreateActor<Stone1>();
            MakeObject(TilePos, tilevar, Test);
            break;
        }
        case TILEVAR::STONE2:
        {
            OtherBase* Test = CreateActor<Stone2>();
            MakeObject(TilePos, tilevar, Test);
            break;
        }
        case TILEVAR::TREE:
        {
            OtherBase* Test = CreateActor<Tree>();
            MakeObject(TilePos, tilevar, Test);
            break;
        }
        case TILEVAR::NONE:
            break;

        }

    }
}


void FarmScene::MakeObject(float4 _TilePos, TILEVAR _tilevar, OtherBase* _obj)
{

    _TilePos.x = (float)((int)_TilePos.x - (int)_TilePos.x % 64);
    _TilePos.y = (float)((int)_TilePos.y - (int)_TilePos.y % 64);
    _TilePos += 32.0f;

    MyRendererTile::Tile* Tile = TileBackGround->TileRenderer->GetTile(_TilePos);
    if (nullptr != Tile && false == Tile->IsOccupied)
    {
        _obj->SetPosition(_TilePos);
        Tile->IsOccupied = true;

        Tile->MyActor = _obj;
        _obj->SetTile(Tile);
        if (TILEVAR::GRASS1 == _tilevar || TILEVAR::GRASS2 == _tilevar || TILEVAR::GRASS3 == _tilevar || TILEVAR::GRASS4 == _tilevar)
        {
            Tile->kind = KIND::GRASS;
           
        }
        else if (TILEVAR::STONE1 == _tilevar || TILEVAR::STONE2 == _tilevar)
        {
            Tile->kind = KIND::STONE;
        }
        else if (TILEVAR::TREE == _tilevar)
        {
            Tile->kind = KIND::TREE;
        }
    }
}

void FarmScene::PlantCrop()
{
    float4 PlantPos = Player->GetPosition();
    MyRendererTile::Tile* Tile = TileBackGround->TileRenderer->GetTile(PlantPos);
    if ((STATE::DIGGED == Tile->GetState()
        || STATE::WET == Tile->GetState())
        && false == Tile->IsOccupied)
    {
        ACTION cropvar = Player->GetAction();
        Crop* Test;
        // 타일맵으로 깔아라.
        switch (cropvar)
        {
        case ACTION::CABBAGE:
        {
            Test = CreateActor<cabbage>();
            break;
        }
        case ACTION::POTATO:
        {
            Test = CreateActor<potato>();
            break;
        }
        case ACTION::RADISH:
        {
            Test = CreateActor<radish>();
            break;
        }
        case ACTION::TOMATO:
        {
            Test = CreateActor<tomato>();
            break;
        }
        case ACTION::BLUEBERRY:
        {
            Test = CreateActor<blueberry>();
            break;
        }
        case ACTION::EGGPLANT:
        {
            Test = CreateActor<eggplant>();
            break;
        }
        default:
            Test = nullptr;
            break;
        }


        PlantPos.x = (float)((int)PlantPos.x - (int)PlantPos.x % 64);
        PlantPos.y = (float)((int)PlantPos.y - (int)PlantPos.y % 64);
        PlantPos += 32.0f;
        Test->SetPosition(PlantPos);

        Tile->MyActor = Test;
        Tile->IsOccupied = true;
        Tile->kind = KIND::CROP;
        Test->SetTile(Tile);
    }
}
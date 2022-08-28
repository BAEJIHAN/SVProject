#include "MyLogicValue.h"
#include "Inventory.h"
FarmScene* MyLogicValue::FarmSceneAddress=nullptr;
StoreScene* MyLogicValue::StoreSceneAddress=nullptr;
RoadScene* MyLogicValue::RoadSceneAddress=nullptr;
TownScene* MyLogicValue::TownSceneAddress= nullptr;
HouseScene* MyLogicValue::HouseSceneAddress = nullptr;



float4 MyLogicValue::GPlayerPos;

float4 MyLogicValue::TownMapSize = float4(3436, 904);
float4 MyLogicValue::FarmMapSize = float4(2560, 1920);
float4 MyLogicValue::HouseMapSize = float4(924, 732);
float4 MyLogicValue::RoadMapSize = float4(2148, 742);
float4 MyLogicValue::StoreMapSize = float4(1520, 1140);

float4 MyLogicValue::PPosHouseToFarm=float4(1574, 598);
float4 MyLogicValue::PPosFarmToHouse = float4(300, 662);
float4 MyLogicValue::PPosFarmToRoad = float4(100, 351);
float4 MyLogicValue::PPosRoadToFarm = float4(2497, 712);
float4 MyLogicValue::PPosRoadToTown = float4(117, 378);
float4 MyLogicValue::PPosTownToRoad = float4(2059, 351);
float4 MyLogicValue::PPosTownToStore = float4(414, 877);
float4 MyLogicValue::PPosStoreToTown = float4(2813, 599);

Door MyLogicValue::DHouseToFarm = {226, 702, 325, 732};
Door MyLogicValue::DFarmToHouse = { 1546, 565,1604, 590 };
Door MyLogicValue::DFarmToRoad = { 2520, 550, 2560, 780 };
Door MyLogicValue::DRoadToFarm = { 0, 237, 52, 470 };
Door MyLogicValue::DRoadToTown = { 2114, 237, 2148, 470 };
Door MyLogicValue::DTownToRoad = {0, 282, 44, 432 };
Door MyLogicValue::DTownToStore = {2759, 526, 2882, 554 };
Door MyLogicValue::DStoreToTown = { 383, 997, 448, 1035};

 
Map MyLogicValue::NextMap=Map::Max;
Map MyLogicValue::PreMap = Map::Max;
#pragma once
#include <MyMath.h>
#include"MyPlayer.h"
//#include"Inventory.h"
// 분류 : 
// 용도 : 
// 설명 : 

class FarmScene;
class StoreScene;
class RoadScene;
class TownScene;
class HouseScene;
class MyPlayer;

enum class Map
{
	House,
	Farm,
	Road,
	Town,
	Store,
	Max
};

class Door
{
public:

	float LPos;
	float TPos;
	float RPos;
	float BPos;

public:

	Door(float _LPos, float _TPos, float _RPos, float _BPos)
	{
		LPos = _LPos;
		TPos = _TPos;
		RPos = _RPos;
		BPos = _BPos;
	}
};


class MyLogicValue
{
public:
	static bool bInDoor(Door _Door, float4 _Pos)
	{
		if (_Door.LPos <= _Pos.x && _Pos.x <= _Door.RPos
			&& _Door.TPos <= _Pos.y && _Pos.y <= _Door.BPos)
			return true;
		else
			return false;
		
	}
	enum class RenderGroup
	{
		BackGround = 0,
		Monster = 100,
		Player = 200,
		UI = 100,
	};

	enum class CollisionGroup
	{
		Player,
		Monster,
		UI, // 맵에디터를 만들건 인벤토리를 만들건
		Mouse, // 맵에디터를 만들건 인벤토리를 만들건
	};

	static bool PosCheck(float4 _pos)
	{
		float4 pos = _pos;
		if ((0.f <= pos.x && pos.x <= 900.f) &&
			(213.f <= pos.y && pos.y <= 765.f))
		{
			return true;
		}
		if ((900.f <= pos.x && pos.x <= 1150.f) &&
			(510.f <= pos.y && pos.y <= 765.f))
		{
			return true;
		}
		if ((0.f <= pos.x && pos.x <= 2350.f) &&
			(765.f <= pos.y && pos.y <= 1360.f))
		{
			return true;
		}
		if ((0.f <= pos.x && pos.x <= 1900.f) &&
			(1360.f <= pos.y && pos.y <= 1920.f))
		{
			return true;
		}




		return false;
	}
	
public:

	static float4 GPlayerPos;

	static float4 TownMapSize; 
	static float4 FarmMapSize;
	static float4 HouseMapSize;
	static float4 RoadMapSize;
	static float4 StoreMapSize;
	

	static Door DHouseToFarm;
	static Door DFarmToHouse;
	static Door DFarmToRoad;
	static Door DRoadToFarm;
	static Door DRoadToTown;
	static Door DTownToRoad;
	static Door DTownToStore;
	static Door DStoreToTown;

	static float4 PPosHouseToFarm;
	static float4 PPosFarmToHouse;
	static float4 PPosFarmToRoad;
	static float4 PPosRoadToFarm;
	static float4 PPosRoadToTown;
	static float4 PPosTownToRoad;
	static float4 PPosTownToStore;
	static float4 PPosStoreToTown;

	static Map NextMap;
	static Map PreMap;
	
	static FarmScene* FarmSceneAddress;
	static StoreScene* StoreSceneAddress;
	static RoadScene* RoadSceneAddress;
	static TownScene* TownSceneAddress;
	static HouseScene* HouseSceneAddress;
	
};		  


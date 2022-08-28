#include "MyEditorScene.h"
#include "FarmBg.h"
#include <MyCamera.h>
#include "MyLogicValue.h"
#include "MouseObject.h"
#include <MyWindow.h>
#include <MyInput.h>
#include "Core.h"

#include "MyTileBackGround.h"
#include "EditUI.h"

#include "Grass1.h"
#include "Grass2.h"
#include "Grass3.h"
#include "Grass4.h"
#include "Stone1.h"
#include "Stone2.h"
#include "Tree.h"

std::map<__int64, TILEVAR> MyEditorScene::m_SaveTile;

MyEditorScene::MyEditorScene():bCanPut(true), tilevar(TILEVAR::NONE)
{
}

MyEditorScene::~MyEditorScene()
{
}

void MyEditorScene::Start()
{
    CollisionGroupLink(COLINDEX::BUTTON, COLINDEX::MOUSE);
	SetMapSize(MyLogicValue::FarmMapSize);
	BackGround = CreateActor<FarmBg>();
	MouseObject* Mouse = CreateActor<MouseObject>();
	TileBackGround = CreateActor<MyTileBackGround>();
    editui = CreateActor<EditUI>();
    editui->SetPosition(float4(520, 170));
}

void MyEditorScene::SceneUpdate()
{
    if (true == MyInput::IsDown(L"TileCheck"))
    {
		float4 TilePos = MyWindow::MousePos() + MyCamera::GetCamPos();
		
		float4 SavePos = TilePos;
		SavePos.x = (float)((int)TilePos.x - (int)TilePos.x % 64);
		SavePos.y = (float)((int)TilePos.y - (int)TilePos.y % 64);
		SavePos += 32.0f;


        if(bCanPut&& MyLogicValue::PosCheck(TilePos))
        {
			switch (tilevar)
			{
			case TILEVAR::GRASS1:
			{
				OtherBase* Test = CreateActor<Grass1>();
				MakeObject(TilePos, tilevar, Test);
				m_SaveTile.insert(std::map<__int64, TILEVAR>::value_type(SavePos.ToInt64(), tilevar));
				
				break;
			}				
			case TILEVAR::GRASS2:
			{
				OtherBase* Test = CreateActor<Grass2>();
				MakeObject(TilePos, tilevar, Test);
				m_SaveTile.insert(std::map<__int64, TILEVAR>::value_type(SavePos.ToInt64(), tilevar));
				break;
			}
			case TILEVAR::GRASS3:
			{
				OtherBase* Test = CreateActor<Grass3>();
				MakeObject(TilePos, tilevar, Test);
				m_SaveTile.insert(std::map<__int64, TILEVAR>::value_type(SavePos.ToInt64(), tilevar));
				break;
			}
			case TILEVAR::GRASS4:
			{
				OtherBase* Test = CreateActor<Grass4>();
				MakeObject(TilePos, tilevar, Test);
				m_SaveTile.insert(std::map<__int64, TILEVAR>::value_type(SavePos.ToInt64(), tilevar));
				break;
			}
			case TILEVAR::STONE1:
			{
				OtherBase* Test = CreateActor<Stone1>();
				MakeObject(TilePos, tilevar, Test);
				m_SaveTile.insert(std::map<__int64, TILEVAR>::value_type(SavePos.ToInt64(), tilevar));
				break;
			}
			case TILEVAR::STONE2:
			{
				OtherBase* Test = CreateActor<Stone2>();
				MakeObject(TilePos, tilevar, Test);
				m_SaveTile.insert(std::map<__int64, TILEVAR>::value_type(SavePos.ToInt64(), tilevar));
				break;
			}
			case TILEVAR::TREE:
			{
				OtherBase* Test = CreateActor<Tree>();
				MakeObject(TilePos, tilevar, Test);
				m_SaveTile.insert(std::map<__int64, TILEVAR>::value_type(SavePos.ToInt64(), tilevar));
				break;
			}
			case TILEVAR::NONE:
				break;
			
			}			
        }
    }

	if (true == MyInput::IsDown(L"ObjectCheck"))
	{
		float4 TilePos = MyWindow::MousePos() + MyCamera::GetCamPos();
		float4 SavePos = TilePos;
		SavePos.x = (float)((int)TilePos.x - (int)TilePos.x % 64);
		SavePos.y = (float)((int)TilePos.y - (int)TilePos.y % 64);
		SavePos += 32.0f;
		if (bCanPut && MyLogicValue::PosCheck(TilePos))
		{
			MyRendererTile::Tile* tile = TileBackGround->TileRenderer->GetTile(TilePos);
			if (nullptr != tile && true == tile->IsOccupied)
			{
				tile->MyActor->Death();
				tile->IsOccupied = false;
				tile->kind = KIND::NONE;
				m_SaveTile.erase(SavePos.ToInt64());
				int a = 0;
			}			
			
		}		
	}
	if (true == MyInput::IsDown(L"TOTITLE"))
	{
		Core::SceneManager.ChangeScene(L"TitleScene");
	}

	MyCamera::Update();
}

void MyEditorScene::SceneChangeStart()
{

}

void MyEditorScene::MakeObject(float4 _TilePos, TILEVAR _tilevar, OtherBase* _obj)
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




void MyEditorScene::LoadTile()
{
	for (auto& TileData : m_SaveTile)
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
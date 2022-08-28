#include "MyPlayer.h"
#include <MyRendererAnimation.h>
#include <MyInput.h>
#include <MyCamera.h>
#include "Core.h"
#include <MyWindow.h>
#include <MyWinImage.h>
#include <MyResMgr.h>
#include "SceneBase.h"
#include <MyTimer.h>
#include "FarmScene.h"
#include "MyTileBackGround.h"
#include <MyRendererTile.h>
#include "MyLogicValue.h"
#include "Crop.h"
#include "Tree.h"
#include "StoneItem.h"
#include "TreeItem.h"
#include "GrassItem.h"
#include <MyActor.h>
#include "EnergyUI.h"
SoundPlayer MyPlayer::walksound;

void MyPlayer::IDLEStart()
{
	
	ChangeAnimation(L"IDLE");
	
}

void MyPlayer::IDLEStay()
{
	if (
		true == MyInput::IsPress(L"L") ||
		true == MyInput::IsPress(L"R") ||
		true == MyInput::IsPress(L"U") ||
		true == MyInput::IsPress(L"D")
		)
	{
		PlayerFsm.ChangeState(L"MOVE");
	}
	else if (true == MyInput::IsDown(L"LCLICK"))
	{
		if (MAP::FARM == CurMap)
		{
			PlayerFsm.ChangeState(L"ACTION");
		}
		
	}
}

void MyPlayer::MOVEStart()
{
	walksound = MySound::Play(L"walk.mp3");
	ChangeAnimation(L"MOVE");
}

void MyPlayer::MOVEStay()
{
	MoveTime+= MyTimer::FDeltaTime();
	if (MoveTime >= 2.8f)
	{
		MoveTime = 0.f;
		walksound = MySound::Play(L"walk.mp3");
	}


	float4 MapSize = GetScene()->GetMapSize();
	float4 MovePos = float4::ZERO;
	if (
		true == MyInput::IsFree(L"L") &&
		true == MyInput::IsFree(L"R") &&
		true == MyInput::IsFree(L"U") &&
		true == MyInput::IsFree(L"D")
		)
	{
		PlayerFsm.ChangeState(L"IDLE");
	}
	else
	{
		switch (Dir)
		{
		case LEFT:

			if (GetPosition().x <= 0)
			{
				return;
			}			
			MovePos = float4::LEFT * MyTimer::FDeltaTime(Speed);
			break;
		case RIGHT:

			if (GetPosition().x >= MapSize.x)
			{
				return;
			}
			MovePos = float4::RIGHT * MyTimer::FDeltaTime(Speed);
			break;
		case UP:
			if (GetPosition().y <= 0)
			{
				return;
			}
			MovePos = float4::UP * MyTimer::FDeltaTime(Speed);
			break;
		case DOWN:

			if (GetPosition().y >= MapSize.y)
			{
				return;
			}
			MovePos = float4::DOWN * MyTimer::FDeltaTime(Speed);
			break;
		case MAX:
		default:
			break;
		}

		SceneBase* T = (SceneBase*)GetScene();
		MyWinImage* FindImage = MyResMgr::Inst().FindImage(T->GetColMapName());
		if (nullptr != FindImage)
		{
			
			float4 CheckPos = GetPosition() + MovePos;
			MyRendererTile::Tile* Tile = MyLogicValue::FarmSceneAddress->TileBackGround->TileRenderer->GetTile(CheckPos);
			CheckColor = FindImage->GetPixelColor(CheckPos.ix(), CheckPos.iy());
		
			
			
			if (MAP::FARM == CurMap)
			{
				if (CheckColor != RGB(0, 0, 0) && KIND::STONE != Tile->GetKind() && KIND::TREE != Tile->GetKind())
				{
					if (KIND::ITEM == Tile->GetKind())
					{
						Tile->MyActor->Death();
						Tile->IsOccupied = false;
						Tile->SetTile(STATE::NONE);
					}

					MovePosition(MovePos);
					MyCamera::SetCamPos(GetPosition() - MyWindow::GetSize().hfloat4());
				}
			}
			else
			{
				if (CheckColor != RGB(0, 0, 0))
				{	
					MovePosition(MovePos);
					MyCamera::SetCamPos(GetPosition() - MyWindow::GetSize().hfloat4());
				}
			}
			
			
		}
	}



}

void MyPlayer::MOVEEnd()
{
	walksound.Stop();
	MoveTime = 0.f;
}

void MyPlayer::ACTIONStart()
{
	switch (mAction)
	{
	case HOE:
		ChangeAnimation(L"HOE");
		break;
	case AXE:
		ChangeAnimation(L"AXE");
		break;
	case SICKLE:
		ChangeAnimation(L"SICKLE");
		break;
	case WATERING:
		ChangeAnimation(L"WATERING");
		break;
	case PICK:
		ChangeAnimation(L"PICK");
		break;
	}
	
}
void MyPlayer::ACTIONStay()
{
	
	FarmScene* farmScene = (FarmScene*)GetScene();
	CurActionTime+=MyTimer::FDeltaTime();
	float4 PlantPos = GetPosition();
	//MyRendererTile::Tile* plantTile = farmScene->TileBackGround->TileRenderer->GetTile(PlantPos);
	if (CurActionTime >= MaxActionTime)
	{
		
		float4 hitPos = GetPosition();
		if (DIR::LEFT == Dir)
		{
			hitPos = hitPos-float4(64.0f, 0.0f);
		}
		if (DIR::RIGHT == Dir)
		{
			hitPos = hitPos +float4(64.0f, 0.0f);
		}
		if (DIR::UP == Dir)
		{
			hitPos = hitPos - float4(0.0f, 64.0f);
		}
		if (DIR::DOWN == Dir)
		{
			hitPos = hitPos + float4(0.0f, 64.0f);
		}

		MyRendererTile::Tile* FindTile = farmScene->TileBackGround->TileRenderer->GetTile(hitPos);
		if(MyLogicValue::PosCheck(hitPos))
		{
			switch (mAction)
			{
			case HOE:
				if (nullptr != FindTile && STATE::NONE == FindTile->GetState()&& false==FindTile->IsOccupied && Energy > 0)
				{
					FindTile->SetTile(STATE::DIGGED);
					MySound::Play(L"hoehit.mp3");
					Energy-= UsingEnergy;
					MyLogicValue::FarmSceneAddress->energy->SetBar(Energy);

				}
					
				break;
			case AXE:
				if (nullptr != FindTile && nullptr != FindTile->MyActor && KIND::TREE == FindTile->kind && Energy > 0)
				{
					Tree* tree = (Tree*)FindTile->MyActor;
					tree->bHit = true;
					tree->HP--;
					Energy -= UsingEnergy;
					MyLogicValue::FarmSceneAddress->energy->SetBar(Energy);
					MySound::Play(L"treehit.mp3"); 
					if (0 == tree->HP)
					{
						tree->Death();
						MySound::Play(L"treedestroy.mp3");
						FindTile->MyActor = MyLogicValue::FarmSceneAddress->CreateActor<TreeItem>();
						FindTile->MyActor->SetPosition(hitPos);
						FindTile->kind = KIND::ITEM;
					}
					
					
				}
				break;
			case SICKLE:
				if (nullptr != FindTile)
				{
					if (KIND::CROP == FindTile->kind && Energy > 0)
					{

						Crop* crop = (Crop*)(FindTile->MyActor);
						if (crop->Curlevel == crop->MaxIndex)
						{
							Energy -= UsingEnergy;
							MyLogicValue::FarmSceneAddress->energy->SetBar(Energy);
							MySound::Play(L"grasshit.mp3");
							crop->Death();
							FindTile->IsOccupied = false;
							FindTile->SetTile(STATE::NONE);

						}
					}
					else if (KIND::GRASS == FindTile->kind && Energy > 0)
					{
						Energy -= UsingEnergy;
						MyLogicValue::FarmSceneAddress->energy->SetBar(Energy);
						MySound::Play(L"grasshit.mp3");
						FindTile->MyActor->Death();
						FindTile->MyActor=MyLogicValue::FarmSceneAddress->CreateActor<GrassItem>();
						FindTile->MyActor->SetPosition(hitPos);						
						FindTile->kind = KIND::ITEM;
					}
				}
				break;
			case WATERING:
				MySound::Play(L"wartering.mp3");
				if (nullptr != FindTile && STATE::DIGGED == FindTile->GetState() && Energy > 0)
				{
					FindTile->SetTile(STATE::WET);
					Energy -= UsingEnergy;
					MyLogicValue::FarmSceneAddress->energy->SetBar(Energy);
				}
					
				break;
			case PICK:
				if (nullptr != FindTile && nullptr != FindTile->MyActor && KIND::STONE==FindTile->kind && Energy > 0)
				{
					Energy -= UsingEnergy;
					MyLogicValue::FarmSceneAddress->energy->SetBar(Energy);
					MySound::Play(L"stonehit.mp3");
					FindTile->MyActor->Death();
					FindTile->MyActor = MyLogicValue::FarmSceneAddress->CreateActor<StoneItem>();
					FindTile->MyActor->SetPosition(hitPos);
					FindTile->kind = KIND::ITEM;
				}
				break;
				
			case POTATO:			
			case RADISH:			
			case CABBAGE:			
			case TOMATO:				
			case EGGPLANT:			
			case BLUEBERRY:
				farmScene->PlantCrop();
				break;
			default:
				break;

			}

		}

		
		CurActionTime = 0.0f;
		PlayerFsm.ChangeState(L"IDLE");
	}
	
}

#include "BagUI.h"
#include <MyRendererBasic.h>
#include "Crop.h"
#include "FieldItem.h"
#include <MyCollision.h>
#include <MyInput.h>
#include "MyLogicValue.h"
#include "FarmScene.h"
#include "MyPlayer.h"
#include "EnergyUI.h"
#include <MySound.h>
BagUI::BagUI():bbagon(false)
{
}

BagUI::~BagUI()
{
}

void BagUI::Start()
{
	MainRenderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::UI);
	MainRenderer->TransSetting(L"bag.bmp", float4(798, 165));
	MainRenderer->CamEffectOff();
	MainRenderer->Off();
}

void BagUI::AddItem(FieldItem* _item)
{
	ITEMINDEX itemvar = _item->fielditemindex;
	std::vector<bagItemInfo>::iterator it;
	for (it = iteminfovector.begin(); it != iteminfovector.end(); it++)
	{
		if (it->index == itemvar)
		{
			return;
		}
	}
	MyRendererBasic* newrender = CreateRenderer<MyRendererBasic>(RENDERINDEX::UIBUTTON);
	switch (itemvar)
	{
	case ITEMINDEX::GRASS:
		newrender->TransSetting(L"grassitem.bmp", float4(56, 56));
		newrender->CamEffectOff();

		break;
	case ITEMINDEX::STONE:
		newrender->TransSetting(L"stoneitem.bmp", float4(56, 56));
		newrender->CamEffectOff();
		break;
	case ITEMINDEX::TREE:
		newrender->TransSetting(L"treeitem.bmp", float4(56, 56));
		newrender->CamEffectOff();
		break;
	case ITEMINDEX::NONE:
		break;
	default:
		break;
	}

	bagItemInfo newiteminfo;
	newiteminfo.index = itemvar;
	iteminfovector.push_back(newiteminfo);

	newrender->SetPivotPos(float4(-353 + 64 * (int)(iteminfovector.size() - 1), -37));
	newrender->Off();
	Itemrenderervector.push_back(newrender);

	


	MyCollision* newcol = CreateCollision<MyCollision>(COLINDEX::BUTTON);
	newcol->SetPivotPos(float4(-353 + 64 * (int)(iteminfovector.size() - 1), -37));
	newcol->SetScale(float4(56, 56));
	itemcolvector.push_back(newcol);
	

}


void BagUI::AddCrop(Crop* _crop)
{
	ITEMINDEX cropvar = _crop->cropitemindex;
	std::vector<bagItemInfo>::iterator it;
	for (it = iteminfovector.begin(); it != iteminfovector.end(); it++)
	{
		if (it->index == cropvar)
		{
			return;
		}
	}
	MyRendererBasic* newrender = CreateRenderer<MyRendererBasic>(RENDERINDEX::UIBUTTON);
	switch (cropvar)
	{	
	case ITEMINDEX::RADISH:
		newrender->TransSetting(L"invenradish.bmp", float4(56, 56));
		newrender->CamEffectOff();
		
		break;
	case ITEMINDEX::POTATO:
		newrender->TransSetting(L"invenpotato.bmp", float4(56, 56));
		newrender->CamEffectOff();
		break;
	case ITEMINDEX::CABBAGE:
		newrender->TransSetting(L"invencabbage.bmp", float4(56, 56));
		newrender->CamEffectOff();
		break;	
	case ITEMINDEX::EGGPLANT:
		newrender->TransSetting(L"inveneggplant.bmp", float4(56, 56));
		newrender->CamEffectOff();

		break;
	case ITEMINDEX::TOMATO:
		newrender->TransSetting(L"inventomato.bmp", float4(56, 56));
		newrender->CamEffectOff();
		break;
	case ITEMINDEX::BLUEBERRY:
		newrender->TransSetting(L"invenblueberry.bmp", float4(56, 56));
		newrender->CamEffectOff();
		break;
	case ITEMINDEX::NONE:
		break;
	default:
		break;
	}
	
	bagItemInfo newiteminfo;
	newiteminfo.index = cropvar;
	iteminfovector.push_back(newiteminfo);

	newrender->SetPivotPos(float4(-353+64* (int)(iteminfovector.size()-1), -37));
	newrender->Off();
	Itemrenderervector.push_back(newrender);

	MyCollision* newcol = CreateCollision<MyCollision>(COLINDEX::BUTTON);
	newcol->SetPivotPos(float4(-353 + 64 * (int)(iteminfovector.size() - 1), -37));
	newcol->SetScale(float4(56, 56));
	itemcolvector.push_back(newcol);
	newcol->AddStayEvent(this, &BagUI::ColStay);
}

void BagUI::BagOn()
{
	bbagon = true;
	MainRenderer->On();
	std::vector<MyRendererBasic*>::iterator it;
	for (it = Itemrenderervector.begin(); it != Itemrenderervector.end(); it++)
	{
		(*it)->On();
	}
}

void BagUI::BagOff()
{
	bbagon = false;
	MainRenderer->Off();
	std::vector<MyRendererBasic*>::iterator it;
	for (it = Itemrenderervector.begin(); it != Itemrenderervector.end(); it++)
	{
		(*it)->Off();
	}
}

void BagUI::ColStay(MyCollision* _this, MyCollision* _other)
{
	if (true == MyInput::IsDown(L"RCLICK"))
	{
		MyPlayer* Player=MyLogicValue::FarmSceneAddress->GetPlayer();
		Player->AddEnergy();
		EnergyUI* energy = MyLogicValue::FarmSceneAddress->GetEnergy();
		energy->SetBar(Player->GetEnergy());
		MySound::Play(L"eat.mp3");

	}
}

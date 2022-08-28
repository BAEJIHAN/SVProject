#include "Inventory.h"
#include<MyRendererBasic.h>
#include<MyCollision.h>


Inventory::Inventory() 
{
}

Inventory::~Inventory()
{
}



void Inventory::Start()
{
	for (int i = 0; i <= 4; ++i)
	{
		MyRendererBasic* NewRenderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::UIBUTTON);
		NewRenderer->TransSetting(invenimage[i], float4(56.0f, 56.0f));
		NewRenderer->CamEffectOff();
		NewRenderer->SetPivotPos(float4(64 * i, 0));
		RendererVector.push_back(NewRenderer);
	}

	for (int i = 0; i <= 4; ++i)
	{
		ItemInfo* newItem = new ItemInfo;
		newItem->amount = 1;
		newItem->itemtype = ITEMTYPE::TOOL;
		newItem->itemindex = (ITEMINDEX)(i);		

		newItem->Renderer = RendererVector[i];
		ItemVector.push_back(newItem);

	}






	// 10000번은 ui충돌
	// 이녀석 움직이나요 안움직이나요?
	for (int i = 0; i <= 4; ++i)
	{
		
		MyCollision* NewCollision = CreateCollision<MyCollision>(COLINDEX::BUTTON);
		
		NewCollision->SetPivotPos(float4(64 * i, 0));
		NewCollision->SetScale(float4(56, 56));
		NewCollision->AddStartEvent(this, &Inventory::ColEnter);
		CollisionVector.push_back(NewCollision);
	}
	
}

int Inventory::CheckIndex(MyCollision* _Pointer)
{
	for (int i = 0; i < CollisionVector.size(); i++)
	{
		if (CollisionVector[i] == _Pointer)
		{
			return i;
		}
		
	}

	return -1;
}

void Inventory::ColEnter(MyCollision* _this, MyCollision* _other)
{
	// 몇번째 아이템을 만들었는지 알수가 있다.
	int a = CheckIndex(_this);


}

void Inventory::AddCrop(Crop* _crop)
{
	Crop* crop = _crop;
	if (nullptr == crop)
		return;
	std::vector<ItemInfo*>::iterator Start = ItemVector.begin();
	std::vector<ItemInfo*>::iterator End = ItemVector.end();

	for (; Start != End; Start++)
	{
		if ((*Start)->itemindex == crop->cropitemindex)
		{
			((*Start)->amount)++;
			return;
		}
			
	}
	if (Start == End)
	{		
		ItemInfo* newItem = new ItemInfo;
		newItem->amount = 1;
		newItem->itemtype = ITEMTYPE::CROP;
		newItem->itemindex = crop->cropitemindex;
				
		
		MyRendererBasic* NewRenderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::UIBUTTON);
		NewRenderer->TransSetting(invenimage[(int)(crop->cropitemindex)], float4(56.0f, 56.0f));
		NewRenderer->CamEffectOff();
		NewRenderer->SetPivotPos(float4(64 * (int)(crop->cropitemindex), 0));
		RendererVector.push_back(NewRenderer);

		newItem->Renderer = RendererVector[(int)(crop->cropitemindex)];


		MyCollision* NewCollision = CreateCollision<MyCollision>(100000);
		NewCollision->SetPivotPos(float4(64 * (int)(crop->cropitemindex), 0));
		NewCollision->SetScale(float4(56, 56));
		NewCollision->AddStartEvent(this, &Inventory::ColEnter);
		CollisionVector.push_back(NewCollision);

		ItemVector.push_back(newItem);
	}
}

void Inventory::AddSeed(ITEMINDEX _index)
{
	
	ITEMINDEX tempindex = _index;
	
	std::vector<ItemInfo*>::iterator Start = ItemVector.begin();
	std::vector<ItemInfo*>::iterator End = ItemVector.end();

	for (; Start != End; Start++)
	{
		if ((*Start)->itemindex == tempindex)
		{
			((*Start)->amount)++;
			return;
		}

	}
	if (Start == End)
	{
		ItemInfo* newItem = new ItemInfo;
		newItem->amount = 1;
		newItem->itemtype = ITEMTYPE::SEED;
		newItem->itemindex = tempindex;

	
		MyRendererBasic* NewRenderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::UIBUTTON);
		
	
		NewRenderer->TransSetting(invenimage[(int)tempindex], float4(56.0f, 56.0f));
		
		
		NewRenderer->CamEffectOff();
		RendererVector.push_back(NewRenderer);

		
		
		NewRenderer->SetPivotPos(float4(64 * (int)(RendererVector.size()-1), 0));
		newItem->Renderer = NewRenderer;


		MyCollision* NewCollision = CreateCollision<MyCollision>(COLINDEX::BUTTON);
		NewCollision->SetPivotPos(float4(64 * (int)(RendererVector.size()-1), 0));
		NewCollision->SetScale(float4(56, 56));
		NewCollision->AddStartEvent(this, &Inventory::ColEnter);
		CollisionVector.push_back(NewCollision);

		ItemVector.push_back(newItem);
	}
}


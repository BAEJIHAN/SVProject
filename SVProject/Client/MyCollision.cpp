#include "MyCollision.h"
#include "MyActor.h"

MyCollision::MyCollision() : mType(COLTYPE::RECT), mOrder(0), mActor(nullptr), mPivotPos(float4::ZERO)
{
	mData.Size = { 1, 1 };
}

MyCollision::~MyCollision()
{
	for (size_t i = 0; i < StartEvent.size(); i++)
	{
		delete StartEvent[i];
	}

	for (size_t i = 0; i < StayEvent.size(); i++)
	{
		delete StayEvent[i];
	}

	for (size_t i = 0; i < EndEvent.size(); i++)
	{
		delete EndEvent[i];
	}
}



void MyCollision::CollisionDataUpdate()
{
	
	mData.Pos = GetActor()->GetPosition() + mPivotPos;
	
}

void MyCollision::CollisionCheck(MyCollision* _Other)
{
	
	COLTYPE ThisColType = mType;
	COLTYPE OtherColType = _Other->mType;


	if (true == Coliison2DCheck::ColFunc[(int)ThisColType][(int)OtherColType](mData, _Other->mData))
	{
		if (mColSet.end() == mColSet.find(_Other))
		{
			// 충돌 시작
			UpdateStartEvent(this, _Other);
			_Other->UpdateStartEvent(_Other, this);
		}
		else
		{
			UpdateStayEvent(this, _Other);
			_Other->UpdateStayEvent(_Other, this);
			// 충돌 중
		}
	}
	else
	{
		if (mColSet.end() != mColSet.find(_Other))
		{
			UpdateEndEvent(this, _Other);
			_Other->UpdateEndEvent(_Other, this);
		}

	}




}

void MyCollision::ReleaseUpdate()
{
	std::set<MyCollision*>::iterator Start = mColSet.begin();
	std::set<MyCollision*>::iterator End = mColSet.end();
	for (; Start != End;)
	{
		for (size_t i = 0; i < EndEvent.size(); i++)
		{
			EndEvent[i]->CallBack(this, (*Start));
		}
		(*Start)->UpdateEndEvent(*Start, this);
		Start = mColSet.erase(Start);
	}
}


void MyCollision::DeathTask()
{
	ReleaseUpdate();
}


void MyCollision::OffTask()
{
	ReleaseUpdate();
}
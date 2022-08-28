#include "MyActor.h"
#include "MyRenderer.h"
#include "MyCollision.h"
MyActor::MyActor()
{
}

MyActor::~MyActor()
{
	{
		std::list<MyRenderer*>::iterator Start = mRenderer.begin();
		std::list<MyRenderer*>::iterator End = mRenderer.end();


		for (; Start != End; ++Start)
		{
			delete* Start;
			*Start = nullptr;
		}

		mRenderer.clear();
	}
	{
		std::list<MyCollision*>::iterator Start = mCollision.begin();
		std::list<MyCollision*>::iterator End = mCollision.end();
		for (; Start != End; ++Start)
		{
			delete* Start;
			*Start = nullptr;
		}
		mCollision.clear();
	}

}

void MyActor::Start()
{
	int a = 0;
}

void MyActor::Update()
{
	int a = 0;
}

void MyActor::DebugRender()
{
}

void MyActor::Release()
{
	// 액터는 살려놓은 채로
	// 랜더러랑
	// 콜리전만 death할때 그걸 체크하는 함수입니다.
	{
		std::list<MyRenderer*>::iterator Start = mRenderer.begin();
		std::list<MyRenderer*>::iterator End = mRenderer.end();

		for (; Start != End; )
		{
			if (false == (*Start)->IsDeath())
			{
				++Start;
				continue;
			}
			(*Start)->DeathTask();
			delete (*Start);
			Start = mRenderer.erase(Start);
		}
	}
	{
		std::list<MyCollision*>::iterator Start = mCollision.begin();
		std::list<MyCollision*>::iterator End = mCollision.end();
		for (; Start != End; )
		{
			if (false == (*Start)->IsDeath())
			{
				++Start;
				continue;
			}
			(*Start)->DeathTask();
			delete (*Start);
			Start = mCollision.erase(Start);
		}
	}
}

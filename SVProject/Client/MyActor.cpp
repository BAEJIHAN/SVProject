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
	// ���ʹ� ������� ä��
	// ��������
	// �ݸ����� death�Ҷ� �װ� üũ�ϴ� �Լ��Դϴ�.
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

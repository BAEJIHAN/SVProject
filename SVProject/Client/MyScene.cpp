#include "MyScene.h"
#include "MyActor.h"
#include "MyRenderer.h"
#include <MyWindow.h>
#include "MyCollision.h"

MyScene::MyScene()
{
}

MyScene::~MyScene()
{
	std::list<MyActor*>::iterator Start = mActors.begin();
	std::list<MyActor*>::iterator End = mActors.end();
	for (; Start != End; ++Start)
	{
		if (nullptr != *Start)
		{
			delete* Start;
			*Start = nullptr;
		}
	}
	mActors.clear();
}

void MyScene::Progress()
{
	CollisionProcess();
	SceneUpdate();
	{
		std::list<MyActor*>::iterator Start = mActors.begin();
		std::list<MyActor*>::iterator End = mActors.end();
		for (; Start != End; ++Start)
		{
			if (false == (*Start)->IsOn())
			{
				continue;
			}
			(*Start)->Update();
		}
	}
	Render();

	{
		std::list<MyActor*>::iterator Start = mActors.begin();
		std::list<MyActor*>::iterator End = mActors.end();
		for (; Start != End; ++Start)
		{
			if (false == (*Start)->IsOn())
			{
				continue;
			}
			(*Start)->DebugRender();
		}
		SceneDebugRender();
	}
	MyWindow::BackBufferCopy();

	// �������� ��� �̷��� ������� �ܰ踦 ������
	// ����� �� ������ ������ ���� ���߿� �������� �ʽ��ϴ�.
	// �浹 ���߿� ���ڱ� ���� �׾�. �����ؼ�.
	Release();
}


void MyScene::PushRenderer(MyRenderer* _Renderer)
{
	

	if (mRendererLists.end() == mRendererLists.find(_Renderer->GetOrder()))
	{
		// �̷��Ե� ����� �ִ�.
		// m_RendererLists[_Renderer->GetOrder()];
		mRendererLists.insert(std::map<int, std::list<MyRenderer*>>::value_type(_Renderer->GetOrder(), std::list<MyRenderer*>()));
	}

	
	mRendererLists[_Renderer->GetOrder()].push_back(_Renderer);
}


bool YSort(MyRenderer* _Left, MyRenderer* _Right)
{
	return _Left->GetActor()->GetPosition().y < _Right->GetActor()->GetPosition().y;
}

void MyScene::Render()
{
	//Rectangle(MyWindow::GetBackBufferDC(), -1, -1, MyWindow::GetSize().x, MyWindow::GetSize().y);
	std::map<int, std::list<MyRenderer*>>::iterator LayerStart = mRendererLists.begin();
	std::map<int, std::list<MyRenderer*>>::iterator LayerEnd = mRendererLists.end();

	for (; LayerStart != LayerEnd; ++LayerStart)
	{
		std::list<MyRenderer*>& _RenderLayer = LayerStart->second;
				  
		_RenderLayer.sort(YSort);

		std::list<MyRenderer*>::iterator RendererStart = _RenderLayer.begin();
		std::list<MyRenderer*>::iterator RendererEnd = _RenderLayer.end();

		for (; RendererStart != RendererEnd; ++RendererStart)
		{
			if (false == (*RendererStart)->IsOn())
			{
				continue;
			}

			(*RendererStart)->Render();
		}

	}
}

void MyScene::PushCollision(MyCollision* _Collision)
{
	if (mCollisionLists.end() == mCollisionLists.find(_Collision->GetOrder()))
	{
		// �̷��Ե� ����� �ִ�.
		// m_RendererLists[_Renderer->GetOrder()];
		mCollisionLists.insert(std::map<int, std::list<MyCollision*>>::value_type(_Collision->GetOrder(), std::list<MyCollision*>()));
	}

	mCollisionLists[_Collision->GetOrder()].push_back(_Collision);
}

void MyScene::CollisionProcess()
{
	// ��� �浹ü�� �ڱ� ��ġ�� �����ϰ�
	{
		std::map<int, std::list<MyCollision*>>::iterator Start = mCollisionLists.begin();
		std::map<int, std::list<MyCollision*>>::iterator End = mCollisionLists.end();

		for (; Start != End; ++Start)
		{
			std::list<MyCollision*>::iterator StartCol = Start->second.begin();
			std::list<MyCollision*>::iterator EndCol = Start->second.end();

			for (; StartCol != EndCol; ++StartCol)
			{
				if (false == (*StartCol)->IsOn())
				{
					continue;
				}

				(*StartCol)->CollisionDataUpdate();
			}
		}
	}

	// �浹�� ����.
	// �����ϸ鼭 �ϼ���
	std::map<int, std::set<int>>::iterator LeftGroupStart = mLinkCollsionGroup.begin();
	std::map<int, std::set<int>>::iterator LeftGroupEnd = mLinkCollsionGroup.end();

	for (; LeftGroupStart != LeftGroupEnd; ++LeftGroupStart)
	{
		std::set<int>::iterator RightGroupStart = LeftGroupStart->second.begin();
		std::set<int>::iterator RightGroupEnd = LeftGroupStart->second.end();

		for (; RightGroupStart != RightGroupEnd; ++RightGroupStart)
		{
			int LeftGroupIndex = LeftGroupStart->first;
			int RightGroupIndex = *RightGroupStart;

			// �������� ���Ϳ� �÷��̾��� �浹�� üũ�Ѵ�.

			if (LeftGroupIndex != RightGroupIndex)
			{
				if (LeftGroupIndex == 100000 && RightGroupIndex == 200000)
				{
					int a = 0;
				}

				CollisionGroupOtherCheck(LeftGroupIndex, RightGroupIndex);
			}
			else
			{
				CollisionGroupThisCheck(LeftGroupIndex);
			}

			// ���ʰ� ������ �׷��� �˼��� �ְ���?

		}

	}


}

void MyScene::CollisionGroupOtherCheck(int _Left, int _Right)
{
	std::list<MyCollision*>& LeftGroup = mCollisionLists[_Left];
	std::list<MyCollision*>& RightGroup = mCollisionLists[_Right];

	std::list<MyCollision*>::iterator LeftStartIter = LeftGroup.begin();
	std::list<MyCollision*>::iterator LeftEndIter = LeftGroup.end();

	for (; LeftStartIter != LeftEndIter; ++LeftStartIter)
	{
		if (false == (*LeftStartIter)->IsOn())
		{
			continue;
		}

		std::list<MyCollision*>::iterator RightStartIter = RightGroup.begin();
		std::list<MyCollision*>::iterator RightEndIter = RightGroup.end();

		for (; RightStartIter != RightEndIter; ++RightStartIter)
		{
			if (false == (*RightStartIter)->IsOn())
			{
				continue;
			}

			
			(*LeftStartIter)->CollisionCheck(*RightStartIter);
		}
	}

	
}

void MyScene::CollisionGroupThisCheck(int _Value)
{
	

	//std::list<Collision*>& LeftGroup = m_CollisionLists[_Value];
	//std::list<Collision*>& RightGroup = m_CollisionLists[_Value];

}


void MyScene::Release() {

	// ������ ����
	{
		std::map<int, std::list<MyRenderer*>>::iterator LayerStart = mRendererLists.begin();
		std::map<int, std::list<MyRenderer*>>::iterator LayerEnd = mRendererLists.end();

		for (; LayerStart != LayerEnd; ++LayerStart)
		{
			std::list<MyRenderer*>& _RenderLayer = LayerStart->second;
			std::list<MyRenderer*>::iterator RendererStart = _RenderLayer.begin();
			std::list<MyRenderer*>::iterator RendererEnd = _RenderLayer.end();

			for (; RendererStart != RendererEnd;)
			{
				if (false == (*RendererStart)->IsDeath())
				{
					++RendererStart;
					continue;
				}

				
				RendererStart = _RenderLayer.erase(RendererStart);
			}

		}
	}

	// �浹ü ����
	{
		std::map<int, std::list<MyCollision*>>::iterator Start = mCollisionLists.begin();
		std::map<int, std::list<MyCollision*>>::iterator End = mCollisionLists.end();

		for (; Start != End; ++Start)
		{
			std::list<MyCollision*>::iterator StartCol = Start->second.begin();
			std::list<MyCollision*>::iterator EndCol = Start->second.end();

			for (; StartCol != EndCol; )
			{
				if (false == (*StartCol)->IsDeath())
				{
					++StartCol;
					continue;
				}

				// �ױ����� �ϰ� ������ �ϰ�
				// (*StartCol)->DeathTask();
				// �װ�
				// delete (*StartCol);
				// ����Ʈ������ ����.
				StartCol = Start->second.erase(StartCol);
			}
		}
	}



	
	{
		std::list<MyActor*>::iterator Start = mActors.begin();
		std::list<MyActor*>::iterator End = mActors.end();
		for (; Start != End; )
		{
			if (false == (*Start)->IsDeath())
			{
				(*Start)->Release();
				++Start;
				continue;
			}

			// �ױ����� �ϰ� ������ �ϰ�
			(*Start)->DeathTask();
			// �װ�
			delete (*Start);
			// ����Ʈ������ ����.
			Start = mActors.erase(Start);
		}
	}
}

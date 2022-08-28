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

	// 선생님의 경우 이렇게 삭제라는 단계를 만들지
	// 절대로 이 위에서 로직이 도는 도중에 삭제하지 않습니다.
	// 충돌 도중에 갑자기 누가 죽어. 위험해서.
	Release();
}


void MyScene::PushRenderer(MyRenderer* _Renderer)
{
	

	if (mRendererLists.end() == mRendererLists.find(_Renderer->GetOrder()))
	{
		// 이렇게도 만들수 있다.
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
		// 이렇게도 만들수 있다.
		// m_RendererLists[_Renderer->GetOrder()];
		mCollisionLists.insert(std::map<int, std::list<MyCollision*>>::value_type(_Collision->GetOrder(), std::list<MyCollision*>()));
	}

	mCollisionLists[_Collision->GetOrder()].push_back(_Collision);
}

void MyScene::CollisionProcess()
{
	// 모든 충돌체가 자기 위치를 수정하고
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

	// 충돌에 들어간다.
	// 생각하면서 하세요
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

			// 이제부터 몬스터와 플레이어의 충돌을 체크한다.

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

			// 왼쪽과 오른쪽 그룹을 알수가 있겠죠?

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

	// 랜더러 정리
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

	// 충돌체 정리
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

				// 죽기전에 하고 싶은일 하고
				// (*StartCol)->DeathTask();
				// 죽고
				// delete (*StartCol);
				// 리스트에서도 삭제.
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

			// 죽기전에 하고 싶은일 하고
			(*Start)->DeathTask();
			// 죽고
			delete (*Start);
			// 리스트에서도 삭제.
			Start = mActors.erase(Start);
		}
	}
}

#include "MySceneManager.h"
#include<MyDebug.h>
#include"MyCamera.h"

MySceneManager::MySceneManager() :CurScene(nullptr), NextScene(nullptr)

{
}

MySceneManager::~MySceneManager()
{
	std::map<Mystring, MyScene*>::iterator Start = AllScene.begin();
	std::map<Mystring, MyScene*>::iterator End = AllScene.end();
	for (; Start != End; ++Start)
	{
		if (nullptr != Start->second)
		{
			delete Start->second;
			Start->second = nullptr;
		}
	}
	AllScene.clear();
}

MyScene* MySceneManager::FindScene(const Mystring& _Name)
{
	if (AllScene.end() == AllScene.find(_Name))
	{
		return nullptr;
	}

	return AllScene[_Name];
}

void MySceneManager::ChangeScene(const Mystring& _Name)
{
	NextScene = FindScene(_Name);
	
	
	if (nullptr == NextScene)
	{
		MyDebug::AssertMsg(L"if (nullptr == NextScene)");
	}

	MyCamera::SetCurScene(NextScene);
	NextScene->SceneChangeStart();
}

void MySceneManager::ChangeCheck()
{
	if (nullptr != NextScene)
	{
		
		if (nullptr != CurScene)
		{
			CurScene->SceneChangeEnd();
		}

		CurScene = NextScene;

		CurScene->SceneChangeStart();
		NextScene = nullptr;
	}
}



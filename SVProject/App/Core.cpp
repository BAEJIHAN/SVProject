#include "Core.h"
#include "MyTitleScene.h"
#include "MyEditorScene.h"
#include <MyDirectory.h>
#include <MyFile.h>
#include <MyResMgr.h>
#include<MyWindow.h>

#include<MyInput.h>
#include<MyCamera.h>
#include"MyLogicValue.h"
#include <MySound.h>

#include"TownScene.h"
#include"HouseScene.h"
#include"StoreScene.h"
#include"RoadScene.h"
#include"FarmScene.h"

MySceneManager Core::SceneManager;


Core::Core()
{
}

Core::~Core()
{
}

void Core::Start()
{
	MyWindow::CursorOff();
	MyDirectory Dir;
	
	// 일단 폴더위치를 API35 보내는 함수
	Dir.MoveParent(L"SVProject");
	Dir.MoveChild(L"Res");
	Dir.MoveChild(L"Image");
	Dir.MoveChild(L"animation");
	std::vector<MyFile> AllImageFile = Dir.DirectoryAllFileToVector(L"*.Bmp");
	for (size_t i = 0; i < AllImageFile.size(); i++)
	{
		MyResMgr::Inst().ImageLoad(AllImageFile[i].GetPath());
	}

	Dir.MoveParent(L"Image");
	Dir.MoveChild(L"colmap");
	AllImageFile = Dir.DirectoryAllFileToVector(L"*.Bmp");
	for (size_t i = 0; i < AllImageFile.size(); i++)
	{
		MyResMgr::Inst().ImageLoad(AllImageFile[i].GetPath());
	}

	Dir.MoveParent(L"Image");
	Dir.MoveChild(L"crop");
	AllImageFile = Dir.DirectoryAllFileToVector(L"*.Bmp");
	for (size_t i = 0; i < AllImageFile.size(); i++)
	{
		MyResMgr::Inst().ImageLoad(AllImageFile[i].GetPath());
	}

	Dir.MoveParent(L"Image");
	Dir.MoveChild(L"map");
	AllImageFile = Dir.DirectoryAllFileToVector(L"*.Bmp");
	for (size_t i = 0; i < AllImageFile.size(); i++)
	{
		MyResMgr::Inst().ImageLoad(AllImageFile[i].GetPath());
	}

	Dir.MoveParent(L"Image");
	Dir.MoveChild(L"tile");
	AllImageFile = Dir.DirectoryAllFileToVector(L"*.Bmp");
	for (size_t i = 0; i < AllImageFile.size(); i++)
	{
		MyResMgr::Inst().ImageLoad(AllImageFile[i].GetPath());
	}
	Dir.MoveParent(L"Image");
	Dir.MoveChild(L"ui");
	AllImageFile = Dir.DirectoryAllFileToVector(L"*.Bmp");

	for (size_t i = 0; i < AllImageFile.size(); i++)
	{
		MyResMgr::Inst().ImageLoad(AllImageFile[i].GetPath());
	}

	{
		MyDirectory Dir;
		Dir.MoveParent(L"SVProject");
		Dir.MoveChild(L"Res");
		Dir.MoveChild(L"Sound");
		std::vector<MyFile> AllImageFile = Dir.DirectoryAllFileToVector(L"*.mp3");

		for (size_t i = 0; i < AllImageFile.size(); i++)
		{
			MySound::Load(AllImageFile[i].GetPath());
		}

	}

	MyResMgr::Inst().FindImage(L"PlayerMove.bmp")->SetTransColor(RGB(255, 0, 255));
	MyResMgr::Inst().FindImage(L"PlayerMove.bmp")->ImageCut(4, 5);

	MyResMgr::Inst().FindImage(L"AxeAction.bmp")->SetTransColor(RGB(255, 0, 255));
	MyResMgr::Inst().FindImage(L"AxeAction.bmp")->ImageCut(3, 4);

	MyResMgr::Inst().FindImage(L"HoeAction.bmp")->SetTransColor(RGB(255, 0, 255));
	MyResMgr::Inst().FindImage(L"HoeAction.bmp")->ImageCut(3, 4);

	MyResMgr::Inst().FindImage(L"PickAction.bmp")->SetTransColor(RGB(255, 0, 255));
	MyResMgr::Inst().FindImage(L"PickAction.bmp")->ImageCut(3, 4);

	MyResMgr::Inst().FindImage(L"SickleAction.bmp")->SetTransColor(RGB(255, 0, 255));
	MyResMgr::Inst().FindImage(L"SickleAction.bmp")->ImageCut(3, 4);

	MyResMgr::Inst().FindImage(L"WateringAction.bmp")->SetTransColor(RGB(255, 0, 255));
	MyResMgr::Inst().FindImage(L"WateringAction.bmp")->ImageCut(3, 4);



	MyResMgr::Inst().FindImage(L"soil.bmp")->SetTransColor(RGB(255, 0, 255));
	MyResMgr::Inst().FindImage(L"soil.bmp")->ImageCut(3, 1);

	MyResMgr::Inst().FindImage(L"radish.bmp")->SetTransColor(RGB(255, 0, 255));
	MyResMgr::Inst().FindImage(L"radish.bmp")->ImageCut(8, 1);

	MyResMgr::Inst().FindImage(L"potato.bmp")->SetTransColor(RGB(255, 0, 255));
	MyResMgr::Inst().FindImage(L"potato.bmp")->ImageCut(8, 1);

	MyResMgr::Inst().FindImage(L"cabbage.bmp")->SetTransColor(RGB(255, 0, 255));
	MyResMgr::Inst().FindImage(L"cabbage.bmp")->ImageCut(9, 1);

	MyResMgr::Inst().FindImage(L"blueberry.bmp")->SetTransColor(RGB(255, 0, 255));
	MyResMgr::Inst().FindImage(L"blueberry.bmp")->ImageCut(9, 1);

	MyResMgr::Inst().FindImage(L"eggplant.bmp")->SetTransColor(RGB(255, 0, 255));
	MyResMgr::Inst().FindImage(L"eggplant.bmp")->ImageCut(9, 1);

	MyResMgr::Inst().FindImage(L"tomato.bmp")->SetTransColor(RGB(255, 0, 255));
	MyResMgr::Inst().FindImage(L"tomato.bmp")->ImageCut(9, 1);


	MyInput::CreateKey(L"ToggleQuick", 'Q');
	MyInput::CreateKey(L"ToggleSlow", 'E');
	MyInput::CreateKey(L"ToggleBag", 'I');
	MyInput::CreateKey(L"ToggleColmap", 'Z');

	MyInput::CreateKey(L"ToFarmScene", 'N');
	MyInput::CreateKey(L"ToEditorScene", 'M');
	MyInput::CreateKey(L"ToStoreScene", 'B');
	MyInput::CreateKey(L"HP", 'H');


	MyInput::CreateKey(L"ACTION", VK_SPACE);

	MyInput::CreateKey(L"L", 'A');
	MyInput::CreateKey(L"R", 'D');
	MyInput::CreateKey(L"U", 'W');
	MyInput::CreateKey(L"D", 'S');

	MyInput::CreateKey(L"TOGGLECAMERA", 'P');

	


	MyInput::CreateKey(L"CL", VK_LEFT);
	MyInput::CreateKey(L"CR", VK_RIGHT);
	MyInput::CreateKey(L"CU", VK_UP);
	MyInput::CreateKey(L"CD", VK_DOWN);

	MyInput::CreateKey(L"AXE", '1');
	MyInput::CreateKey(L"HOE", '2');
	MyInput::CreateKey(L"WATER", '3');
	MyInput::CreateKey(L"PICK", '4');
	MyInput::CreateKey(L"SICKLE", '5');
	MyInput::CreateKey(L"POTATO", '6');
	MyInput::CreateKey(L"EGGPLANT", '7');
	MyInput::CreateKey(L"RADISH", '8');
	MyInput::CreateKey(L"TOMATO", '9');
	MyInput::CreateKey(L"CABBAGE", '0');
	MyInput::CreateKey(L"BLUE", 'O');

	MyInput::CreateKey(L"DEBUGON", 'T');
	MyInput::CreateKey(L"DEBUGOFF", 'y');

	MyInput::CreateKey(L"TOTITLE", 'L');

	MyInput::CreateKey(L"LCLICK", VK_LBUTTON);
	MyInput::CreateKey(L"RCLICK", VK_RBUTTON);
	MyCamera::Start();

	//MyLogicValue::MainPlayer::Start();
	
	SceneManager.CreateScene<MyTitleScene>(L"TitleScene");
	SceneManager.CreateScene<MyEditorScene>(L"MapEditorScene");
	
	
	SceneManager.CreateScene<HouseScene>(L"HouseScene");
	SceneManager.CreateScene<TownScene>(L"TownScene");	
	SceneManager.CreateScene<StoreScene>(L"StoreScene");
	SceneManager.CreateScene<RoadScene>(L"RoadScene");
	SceneManager.CreateScene<FarmScene>(L"FarmScene");
	// 현재 씬을 지정.
	//SceneManager.ChangeScene(L"HouseScene");
	//SceneManager.ChangeScene(L"FarmScene");
	//SceneManager.ChangeScene(L"StoreScene");
	//SceneManager.ChangeScene(L"MapEditorScene");
	SceneManager.ChangeScene(L"TitleScene");
}

void Core::Update()
{
	SceneManager.ChangeCheck();

	SceneManager.GetCurScene()->Progress();

}

void Core::End()
{
	MySound::Release();

}

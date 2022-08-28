#include "MyPlayTestScene.h"
#include "MyPlayer.h"
#include <MyWindow.h>
#include "MyPlayBackGround.h"
#include "MyTileBackGround.h"
#include <MyRendererTile.h>
#include <MyWindow.h>
// Static Var
// Static Func

// member Var
MyPlayTestScene::MyPlayTestScene(): TileBackGround(nullptr), Player(nullptr)
{

}

MyPlayTestScene::~MyPlayTestScene()
{

}
// member Func

void MyPlayTestScene::Start()
{
	//MyInput::CreateKey(L"TileCheck", VK_LBUTTON);
	/*{
		MyPlayBackGround* Object = CreateActor<MyPlayBackGround>();
		
	}

	{
		TileBackGround = CreateActor<MyTileBackGround>();
	}
	{
		Player = CreateActor<MyPlayer>();

		SetCamMove(float4(100.0f, 0.0f, 0.0f));
		Player->SetPosition(MyWindow::GetSize().hfloat4() + float4(100.0f, 0.0f, 0.0f));
	}*/

	//Player->Start();
	/*{
		MyPlayer* Object = CreateActor<MyPlayer>();
		Object->SetPosition(MyWindow::GetSize().hfloat4());
	}*/

	
}

void MyPlayTestScene::SceneUpdate()
{
	
	Player->Update();
	/*if (true == MyInput::IsPress(L"TileCheck"))
	{
		float4 TilePos = MyWindow::MousePos() + GetCamPos();

		TileBackGround->TileRenderer->SetTile(TilePos, 0);
	}*/

}
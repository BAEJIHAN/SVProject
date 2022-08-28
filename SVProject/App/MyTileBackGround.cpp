#include "MyTileBackGround.h"
#include <MyRendererTile.h>

// Static Var
// Static Func

// member Var
MyTileBackGround::MyTileBackGround()
{

}

MyTileBackGround::~MyTileBackGround()
{

}
// member Func

void MyTileBackGround::Start()
{
	{
		TileRenderer = CreateRenderer<MyRendererTile>(2);
		
		TileRenderer->TileMapStart(L"soil.bmp", { 64.0f, 64.0f }, { 64.0f, 64.0f }, 40, 30);
	}

}



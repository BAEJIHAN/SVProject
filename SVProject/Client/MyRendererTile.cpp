#include "MyRendererTile.h"
#include "MyResMgr.h"
#include <MyWindow.h>
#include "MyActor.h"
#include"MyCamera.h"
// Static Var
// Static Func

// member Var
MyRendererTile::MyRendererTile() : mImage(nullptr), mCullActor(nullptr)
{

}

MyRendererTile::~MyRendererTile()
{

}

// member Func
void MyRendererTile::TileMapStart(const Mystring& _TileMapImage, float4 _TileSize, float4 _ImageScale, int _SizeX, int _SizeY)
{
	TileSize = _TileSize;
	ImageScale = _ImageScale;
	mImage = MyResMgr::Inst().FindImage(_TileMapImage);

	if (nullptr == mImage)
	{
		MyDebug::AssertMsg(L"if (nullptr == m_Image)");
	}

	mTileMap.resize(_SizeY);
	for (size_t i = 0; i < mTileMap.size(); i++)
	{
		mTileMap[i].resize(_SizeX);
	}

	for (size_t y = 0; y < mTileMap.size(); y++)
	{
		for (size_t x = 0; x < _SizeX; x++)
		{
			// 내가 다 세팅됐죠?
			mTileMap[y][x].mParentTile = this;
			mTileMap[y][x].mImageIndex = -1;
		}
	}
}



void MyRendererTile::Render()
{
	if (nullptr == mCullActor)
	{
		for (int y = 0; y < (int)mTileMap.size(); y++)
		{
			for (int x = 0; x < (int)mTileMap[y].size(); x++)
			{
				if (-1 == mTileMap[y][x].mImageIndex)
				{
					continue;
				}

				// 여기서 이렇게 그리죠?

				float4 TilePos = { x * TileSize.ix(), y * TileSize.iy() };
				const CutData& Data = mImage->GetCutData(mTileMap[y][x].mImageIndex);
				float4 CamPos = MyCamera::GetCamPos();
				float4 RenderPos = GetActor()->GetPosition() + TilePos - CamPos;
				MyWindow::GetBackBufferImage().TransparentBlt(RenderPos, ImageScale, *mImage, Data.mPos, Data.mSize);

			
			}
		}
	}
	else {
		float4 TilePos = mCullActor->GetPosition();
		float4 TileIndex = { TilePos.ix() / TileSize.ix(), TilePos.iy() / TileSize.iy() };

		int YStart = TileIndex.iy() - 10;
		int YEnd = TileIndex.iy() + 10;
		
		int XStart = TileIndex.ix() - 10;
		int XEnd = TileIndex.ix() + 10;


		for (int y = YStart; y < YEnd; y++)
		{
			for (int x = XStart; x < XEnd; x++)
			{
				if (-1 == mTileMap[y][x].mImageIndex)
				{
					continue;
				}

				// 여기서 이렇게 그리죠?

				float4 TilePos = { x * TileSize.ix(), y * TileSize.iy() };
				const CutData& Data = mImage->GetCutData(mTileMap[y][x].mImageIndex);
				float4 CamPos = GetActor()->GetScene()->GetCamPos();
				float4 RenderPos = GetActor()->GetPosition() + TilePos - CamPos;
				MyWindow::GetBackBufferImage().TransparentBlt(RenderPos, ImageScale, *mImage, Data.mPos, Data.mSize);

			}
		}
	}


}



MyRendererTile::Tile* MyRendererTile::GetTile(float4 _CheckPos)
{
	float4 TileIndex = { _CheckPos.ix() / TileSize.ix(), _CheckPos.iy() / TileSize.iy() };

	if (0 > TileIndex.ix())
	{
		return nullptr;
	}

	if (0 > TileIndex.iy())
	{
		return nullptr;
	}

	if (TileIndex.iy() >= mTileMap.size())
	{
		return nullptr;
	}

	if (TileIndex.ix() >= mTileMap[TileIndex.iy()].size())
	{
		return nullptr;
	}

	return &mTileMap[TileIndex.iy()][TileIndex.ix()];
	
}

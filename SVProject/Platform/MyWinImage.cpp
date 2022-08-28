#include "MyWinImage.h"
#include <MyDebug.h>
#include "MyWindow.h"
#pragma comment(lib, "msimg32.lib")
MyWinImage::MyWinImage(): mBitMapInfo(), mBitMap(0), mDC(0), TransColor(RGB(255, 0, 255))
{
	// 그냥 가서 확인해보면 이걸 넣어야 한다고 합니다.
	mBlend.AlphaFormat = AC_SRC_OVER;
	mBlend.BlendFlags = 0;
	mBlend.AlphaFormat = AC_SRC_ALPHA;
	mBlend.SourceConstantAlpha = 255;
}

MyWinImage::~MyWinImage()
{
	if (nullptr != mDC)
	{
		
		DeleteObject(mBitMap);

		DeleteObject(mOldBitMap);

		DeleteDC(mDC);

		
	}
}

void MyWinImage::ImageSizeCheck()
{
	HBITMAP CheckBitMap = (HBITMAP)GetCurrentObject(mDC, OBJ_BITMAP);
	GetObjectW(CheckBitMap, sizeof(mBitMapInfo), &mBitMapInfo);

	mSize.x = static_cast<float>(mBitMapInfo.bmWidth);
	mSize.y = static_cast<float>(mBitMapInfo.bmHeight);
}

void MyWinImage::Create(const Scale& _ImageScale)
{
	
	if (true == _ImageScale.IsZero2D())
	{
		MyDebug::AssertMsg(L"if (true == _ImageScale.IsZero())");
	}

	// 실제 색깔의 배열은 이녀석이 가지고 있고
	// DC는 거기에 간섭할수 있는 권한을 의미한다.
	// 색깔의 배열을 만들고
	// 이미지를 로드하는 행동이 아니니까.
	// 검은색 이미지를 만들어내는 행동을 하고 있는것이다.
	//GameEngineWindow::GetWindowDC()를 기반으로 만들어달라.
	mBitMap = CreateCompatibleBitmap(MyWindow::GetWindowDC(), _ImageScale.ix(), _ImageScale.iy());

	// 짜증나는 점이 dc를 만들기만 해도 내부에 1,1짜리 bitmap이 생긴다. ㅠㅠ
	mDC = CreateCompatibleDC(nullptr);

	if (nullptr == mDC)
	{
		MyDebug::AssertMsg(L"if (nullptr != m_DC)");
	}

	mOldBitMap = (HBITMAP)SelectObject(mDC, mBitMap);


	ImageSizeCheck();
}

void MyWinImage::Create(HDC _DC)
{
	if (nullptr == _DC)
	{
		MyDebug::AssertMsg(L"if (nullptr == _DC)");
	}

	mDC = _DC;

	ImageSizeCheck();
}

void MyWinImage::Load(const Mystring& _LoadPath)
{
	mBitMap = (HBITMAP)LoadImageW(nullptr,
		_LoadPath.c_str(), // 경로
		IMAGE_BITMAP, // 비트맵을 로드하겠다.
		0, // 이미지의 이 위치부터 로드하겠다 X.
		0, // 이미지의 이 위치부터 로드하겠다 Y.
		LR_LOADFROMFILE); // 파일을 기반으로 해서 로드하겠다.

	if (nullptr == mBitMap)
	{
		MyDebug::AssertMsg(L"if (nullptr == m_BitMap)");
	}

	mDC = CreateCompatibleDC(nullptr);

	if (nullptr == mDC)
	{
		MyDebug::AssertMsg(L"if (nullptr != m_DC)");
	}
	// 내부에 1, 1짜리 BITMAP이 들어있으니까.
	mOldBitMap = (HBITMAP)SelectObject(mDC, mBitMap);
	ImageSizeCheck();

}


void MyWinImage::BitBlt(MyWinImage& _OtherImage)
{
	// _OtherImage이미지에 존재하는 그림을 
	// this이미지에 그대로 (빠르게)복사해주는 함수

	BitBlt({ 0, 0 }, _OtherImage);
}


void MyWinImage::BitBlt(float4 _Pos, MyWinImage& _OtherImage)
{
	// :: 전역함수라는것을 명시해준다.
	::BitBlt(mDC,// 나의 이미지에 복사해라
		_Pos.ix(), // 나의 이미지의 X0에서부터
		_Pos.iy(), // 나의 이미지의 Y0에서부터
		_OtherImage.mBitMapInfo.bmWidth,  // 이미지의 너비와
		_OtherImage.mBitMapInfo.bmHeight, // 이미지의 높이만큼
		_OtherImage.mDC,
		0, // 위의 이미지의 X0부터
		0, // 위의 이미지의 Y0부터
		SRCCOPY); // 고속 복사해라
}

void MyWinImage::BitBltCenter(float4 _Pos, MyWinImage& _OtherImage)
{
	::BitBlt(mDC,// 나의 이미지에 복사해라
		_Pos.ix() - _OtherImage.mSize.ihx(), // 나의 이미지의 X0에서부터
		_Pos.iy() - _OtherImage.mSize.ihy(), // 나의 이미지의 Y0에서부터
		_OtherImage.mBitMapInfo.bmWidth,  // 이미지의 너비와
		_OtherImage.mBitMapInfo.bmHeight, // 이미지의 높이만큼
		_OtherImage.mDC,
		0, // 위의 이미지의 X0부터
		0, // 위의 이미지의 Y0부터
		SRCCOPY); // 고속 복사해라
}

void MyWinImage::TransparentBltCenter(const float4& _Pos, const float4& _Size, MyWinImage& _OtherImage, const float4& _CutPos, const float4& _CutSize)
{

	float4 CutSize = _CutSize;
	if (-1 == _CutSize.ix())
	{
		CutSize.x = static_cast<float>(_OtherImage.mSize.ix());
	}

	if (-1 == _CutSize.iy())
	{
		CutSize.y = static_cast<float>(_OtherImage.mSize.iy());
	}

	::TransparentBlt(mDC,
		_Pos.ix() - _Size.ihx(), // 위의 이미지에 그리려고 하는 위치의 x
		_Pos.iy() - _Size.ihy(), // 위의 이미지에 그리려고 하는 위치의 y
		_Size.ix(), // 그리려고 하는 사이즈 x
		_Size.iy(), // 그리려고 하는 사이즈 y
		_OtherImage.mDC,
		_CutPos.ix(),
		_CutPos.iy(),
		CutSize.ix(),
		CutSize.iy(),
		_OtherImage.TransColor); // 마지막은 내일 설명할께요.
}
void MyWinImage::TransparentBlt(const float4& _Pos, const float4& _Size, MyWinImage& _OtherImage, const float4& _CutPos, const float4& _CutSize)
{
	float4 CutSize = _CutSize;

	if (-1 == _CutSize.ix())
	{
		CutSize.x = static_cast<float>(_OtherImage.mSize.ix());
	}

	if (-1 == _CutSize.iy())
	{
		CutSize.y = static_cast<float>(_OtherImage.mSize.iy());
	}

	::TransparentBlt(mDC,
		_Pos.ix(), // 위의 이미지에 그리려고 하는 위치의 x
		_Pos.iy(), // 위의 이미지에 그리려고 하는 위치의 y
		_Size.ix(), // 그리려고 하는 사이즈 x
		_Size.iy(), // 그리려고 하는 사이즈 y
		_OtherImage.mDC,
		_CutPos.ix(),
		_CutPos.iy(),
		CutSize.ix(),
		CutSize.iy(),
		_OtherImage.TransColor); // 마지막은 내일 설명할께요.


}

void MyWinImage::ImageCut(int _X, int _Y)
{
	if (_X == 0 || _Y == 0)
	{
		MyDebug::AssertMsg("if (_X == 0 || _Y == 0)");
	}

	float4 ImageSize = float4{ mSize.ix() / _X,  mSize.iy() / _Y };
	float4 CurPos = float4{ 0,  0 };

	for (int y = 0; y < _Y; y++)
	{
		for (int x = 0; x < _X; x++)
		{
			mCutData.push_back({ CurPos , ImageSize });
			CurPos.x += ImageSize.x;
		}

		CurPos.x = 0;
		CurPos.y += ImageSize.y;
	}


}

const CutData& MyWinImage::GetCutData(int _Index)
{
	if (0 > _Index || mCutData.size() <= _Index)
	{
		MyDebug::AssertMsg("if (0 > _Index || m_CutData.size() <= _Index)");
	}

	return mCutData[_Index];
}

void MyWinImage::AlphaBltCenter(const float4& _Pos, const float4& _Size, MyWinImage& _OtherImage, const float4& _CutPos, const float4& _CutSize, BYTE _Alpha)
{
	mBlend.SourceConstantAlpha = _Alpha;

	float4 CutSize = _CutSize;

	if (-1 == _CutSize.ix())
	{
		CutSize.x = static_cast<float>(_OtherImage.mSize.ix());
	}

	if (-1 == _CutSize.iy())
	{
		CutSize.y = static_cast<float>(_OtherImage.mSize.iy());
	}

	::AlphaBlend(mDC,
		_Pos.ix() - _Size.ihx(), // 위의 이미지에 그리려고 하는 위치의 x
		_Pos.iy() - _Size.ihy(), // 위의 이미지에 그리려고 하는 위치의 y
		_Size.ix(), // 그리려고 하는 사이즈 x
		_Size.iy(), // 그리려고 하는 사이즈 y
		_OtherImage.mDC,
		_CutPos.ix(),
		_CutPos.iy(),
		CutSize.ix(),
		CutSize.iy(),
		mBlend); // 마지막은 내일 설명할께요.

}
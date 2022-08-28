#include "MyWinImage.h"
#include <MyDebug.h>
#include "MyWindow.h"
#pragma comment(lib, "msimg32.lib")
MyWinImage::MyWinImage(): mBitMapInfo(), mBitMap(0), mDC(0), TransColor(RGB(255, 0, 255))
{
	// �׳� ���� Ȯ���غ��� �̰� �־�� �Ѵٰ� �մϴ�.
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

	// ���� ������ �迭�� �̳༮�� ������ �ְ�
	// DC�� �ű⿡ �����Ҽ� �ִ� ������ �ǹ��Ѵ�.
	// ������ �迭�� �����
	// �̹����� �ε��ϴ� �ൿ�� �ƴϴϱ�.
	// ������ �̹����� ������ �ൿ�� �ϰ� �ִ°��̴�.
	//GameEngineWindow::GetWindowDC()�� ������� �����޶�.
	mBitMap = CreateCompatibleBitmap(MyWindow::GetWindowDC(), _ImageScale.ix(), _ImageScale.iy());

	// ¥������ ���� dc�� ����⸸ �ص� ���ο� 1,1¥�� bitmap�� �����. �Ф�
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
		_LoadPath.c_str(), // ���
		IMAGE_BITMAP, // ��Ʈ���� �ε��ϰڴ�.
		0, // �̹����� �� ��ġ���� �ε��ϰڴ� X.
		0, // �̹����� �� ��ġ���� �ε��ϰڴ� Y.
		LR_LOADFROMFILE); // ������ ������� �ؼ� �ε��ϰڴ�.

	if (nullptr == mBitMap)
	{
		MyDebug::AssertMsg(L"if (nullptr == m_BitMap)");
	}

	mDC = CreateCompatibleDC(nullptr);

	if (nullptr == mDC)
	{
		MyDebug::AssertMsg(L"if (nullptr != m_DC)");
	}
	// ���ο� 1, 1¥�� BITMAP�� ��������ϱ�.
	mOldBitMap = (HBITMAP)SelectObject(mDC, mBitMap);
	ImageSizeCheck();

}


void MyWinImage::BitBlt(MyWinImage& _OtherImage)
{
	// _OtherImage�̹����� �����ϴ� �׸��� 
	// this�̹����� �״�� (������)�������ִ� �Լ�

	BitBlt({ 0, 0 }, _OtherImage);
}


void MyWinImage::BitBlt(float4 _Pos, MyWinImage& _OtherImage)
{
	// :: �����Լ���°��� ������ش�.
	::BitBlt(mDC,// ���� �̹����� �����ض�
		_Pos.ix(), // ���� �̹����� X0��������
		_Pos.iy(), // ���� �̹����� Y0��������
		_OtherImage.mBitMapInfo.bmWidth,  // �̹����� �ʺ��
		_OtherImage.mBitMapInfo.bmHeight, // �̹����� ���̸�ŭ
		_OtherImage.mDC,
		0, // ���� �̹����� X0����
		0, // ���� �̹����� Y0����
		SRCCOPY); // ��� �����ض�
}

void MyWinImage::BitBltCenter(float4 _Pos, MyWinImage& _OtherImage)
{
	::BitBlt(mDC,// ���� �̹����� �����ض�
		_Pos.ix() - _OtherImage.mSize.ihx(), // ���� �̹����� X0��������
		_Pos.iy() - _OtherImage.mSize.ihy(), // ���� �̹����� Y0��������
		_OtherImage.mBitMapInfo.bmWidth,  // �̹����� �ʺ��
		_OtherImage.mBitMapInfo.bmHeight, // �̹����� ���̸�ŭ
		_OtherImage.mDC,
		0, // ���� �̹����� X0����
		0, // ���� �̹����� Y0����
		SRCCOPY); // ��� �����ض�
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
		_Pos.ix() - _Size.ihx(), // ���� �̹����� �׸����� �ϴ� ��ġ�� x
		_Pos.iy() - _Size.ihy(), // ���� �̹����� �׸����� �ϴ� ��ġ�� y
		_Size.ix(), // �׸����� �ϴ� ������ x
		_Size.iy(), // �׸����� �ϴ� ������ y
		_OtherImage.mDC,
		_CutPos.ix(),
		_CutPos.iy(),
		CutSize.ix(),
		CutSize.iy(),
		_OtherImage.TransColor); // �������� ���� �����Ҳ���.
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
		_Pos.ix(), // ���� �̹����� �׸����� �ϴ� ��ġ�� x
		_Pos.iy(), // ���� �̹����� �׸����� �ϴ� ��ġ�� y
		_Size.ix(), // �׸����� �ϴ� ������ x
		_Size.iy(), // �׸����� �ϴ� ������ y
		_OtherImage.mDC,
		_CutPos.ix(),
		_CutPos.iy(),
		CutSize.ix(),
		CutSize.iy(),
		_OtherImage.TransColor); // �������� ���� �����Ҳ���.


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
		_Pos.ix() - _Size.ihx(), // ���� �̹����� �׸����� �ϴ� ��ġ�� x
		_Pos.iy() - _Size.ihy(), // ���� �̹����� �׸����� �ϴ� ��ġ�� y
		_Size.ix(), // �׸����� �ϴ� ������ x
		_Size.iy(), // �׸����� �ϴ� ������ y
		_OtherImage.mDC,
		_CutPos.ix(),
		_CutPos.iy(),
		CutSize.ix(),
		CutSize.iy(),
		mBlend); // �������� ���� �����Ҳ���.

}
#include "MyResMgr.h"
#include <MyPath.h>
#include <MyDebug.h>



MyResMgr::MyResMgr()
{
}

MyResMgr::~MyResMgr()
{
	Release();
}

void MyResMgr::Release()
{
	std::map<Mystring, MyWinImage*>::iterator Start = mImage.begin();
	std::map<Mystring, MyWinImage*>::iterator End = mImage.end();
	for (; Start != End; ++Start)
	{
		if (nullptr != Start->second)
		{
			delete Start->second;
			Start->second = nullptr;
		}
	}

	mImage.clear();
}

MyWinImage* MyResMgr::FindImage(const Mystring& _Name)
{
	if (mImage.end() == mImage.find(_Name))
	{
		return nullptr;
	}

	// ���ͷ����� ã�� second���� �� �Ѱ̴ϴ�.
	// ���ο��� �˾Ƽ� �� ���ݴϴ� ����?
	return mImage[_Name];
}

void MyResMgr::ImageLoad(const Mystring& _Path)
{

	Mystring FileName = MyPath::IOName(_Path);

	if (nullptr != FindImage(FileName))
	{
		MyDebug::AssertMsg("if (nullptr != FindImage(FileName))");
		return;
	}

	MyWinImage* NewImage = new MyWinImage();
	NewImage->Load(_Path);
	mImage.insert(std::map<Mystring, MyWinImage*>::value_type(FileName, NewImage));
}

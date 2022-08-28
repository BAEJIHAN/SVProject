#include "MyFile.h"
#include "MyDebug.h"

MyFile::MyFile():mHandle(nullptr), CurMemoryPosition(0), mFileSize(0)
{
}

MyFile::MyFile(const Mystring& _path) : MyPath(_path), mHandle(nullptr), CurMemoryPosition(0), mFileSize(0)
{
}

MyFile::~MyFile()
{
    Close();
}

void MyFile::Close()
{

	if (nullptr != mHandle)
	{
		fclose(mHandle);
		mHandle = nullptr;
	}
}

size_t MyFile::FileSize()
{
	if (nullptr == mHandle)
	{
		return mFileSize;
	}
	return mFileSize;

}



void MyFile::Open(const wchar_t* _mode)
{
	Close();
	
	CurMemoryPosition = 0;

	Mode = _mode;

	_wfopen_s(&mHandle, c_str(), Mode.c_str());

	if (nullptr == mHandle)
	{
	
		MyDebug::AssertMsg(L"if (nullptr == m_Handle)");
	}

	fseek(mHandle, 0, SEEK_END);
	mFileSize = ftell(mHandle);
	fseek(mHandle, 0, SEEK_SET);
}



void MyFile::Write(void* _Ptr, size_t _Size, size_t _Count)
{
	if (nullptr == mHandle)
	{
		MyDebug::AssertMsg(L"if (nullptr == mHandle)");
	}

#ifdef _DEBUG
	if (true == isReadOpen())
	{
		
		MyDebug::AssertMsg(L"if (true == isReadOpen())");		
	}
#endif
	fwrite(_Ptr, _Size, _Count, mHandle);
}

void MyFile::Read(void* _Ptr, size_t _BufferSize, size_t _ReadSize, size_t _Count /*= 1*/)
{
	
	fread_s(_Ptr, _BufferSize, _ReadSize, _Count, mHandle);

}

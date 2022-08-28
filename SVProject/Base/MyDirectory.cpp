#include "MyDirectory.h"
#include "MyDirectory.h"
#include <Windows.h>
#include "MyDebug.h"
#include "MyFile.h"
#include <io.h>

Mystring MyDirectory::GetCurrentDirectoryPath()
{
	wchar_t Arr[512] = { 0 };
	GetCurrentDirectoryW(MAX_PATH, Arr);
	Mystring ReturnPath = Arr;
	ReturnPath += L"\\";
	return ReturnPath;

}

void MyDirectory::GetCurrentDirectoryPath(Mystring& _String)
{
	_String = GetCurrentDirectoryPath();
}

MyDirectory::MyDirectory() :  MyPath(GetCurrentDirectoryPath())
{

}

MyDirectory::~MyDirectory()
{
}

Mystring MyDirectory::DirectoryName()
{
	return IOName();
}

void MyDirectory::MoveChild(const Mystring& _Path)
{
	Mystring::operator+=(_Path + L"\\");
	if (false == isExist())
	{
		MyDebug::AssertMsg(_Path + L"if (false == isExist())");
	}
}

void MyDirectory::MoveParent()
{
	size_t LastIndex = find_last_index(L"\\", size() - 2);
	Mystring::operator=(CutIndex(0, LastIndex + 1));
}

void MyDirectory::MoveParent(const Mystring& _DirName)
{
	while (DirectoryName() != _DirName)
	{
		MoveParent();
	}
}


std::vector<MyFile> MyDirectory::DirectoryAllFileToVector(const Mystring& _CheckPath)
{
	std::vector<MyFile> ReturnVector;



	_wfinddata64i32_t fd;

	Mystring Path = c_str();

	Path += _CheckPath;

	intptr_t FindHandle = _wfindfirst(Path.c_str(), &fd);

	if (-1 == FindHandle)
	{
		MyDebug::AssertMsg(L"if (-1 == FindHandle)");
	}


	do
	{
		if (fd.attrib & _A_SUBDIR)
		{

			_wfindnext(FindHandle, &fd);
			continue;

		}

		Mystring FileName = fd.name;

		MyFile NewFile = operator+(FileName);


		ReturnVector.push_back(NewFile);
	} while (0 == _wfindnext(FindHandle, &fd));


	_findclose(FindHandle);

	return ReturnVector;
}

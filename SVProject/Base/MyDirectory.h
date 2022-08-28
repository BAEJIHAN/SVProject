#pragma once
#include"MyPath.h"


//분류 : 문자열
//용도 : 헬퍼
//설명 : 경로의 정보와 기능을 담당하는 클래스
class MyFile;
class MyDirectory :public MyPath
{
private: //static variable
public:	//static func
    static void GetCurrentDirectoryPath(Mystring& _String);
    static Mystring GetCurrentDirectoryPath();

public:	//constructor destructor
    MyDirectory();
    ~MyDirectory();


public: // delete constructer 
    MyDirectory& operator=(const Mystring& _Other)
    {
    }
    MyDirectory(const MyDirectory& _Other) = delete;
    MyDirectory(const MyDirectory&& _Other) = delete;

public: // delete operator
    MyDirectory& operator=(const MyDirectory& _Other) = delete;
    MyDirectory& operator=(const MyDirectory&& _Other) = delete;

public: // member func
    Mystring DirectoryName();

    void MoveChild(const Mystring& _Path);
    void MoveParent();
    void MoveParent(const Mystring& _DirName);
    std::vector<MyFile> DirectoryAllFileToVector(const Mystring& _CheckPath = L"*.*");
};




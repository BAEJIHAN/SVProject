#pragma once
#include"Mystring.h"
//분류 : 문자열
//용도 : 헬퍼
//설명 : 문자열을 기반으로 파일과 디렉토리를 이루는 공통요소들을 가지고 있다.

class MyPath : public Mystring
{
public:
    static bool isExist(const Mystring& _path);
    static Mystring IOName(const Mystring& _Path)
    {
        Mystring ReturnName = _Path.CutIndex(_Path.find_last_index(L"\\", _Path.size() - 2), _Path.size());
        ReturnName.EraseAll(L"\\");
        return ReturnName;

    }
public:	//constructor destructor
    Mystring IOName()
    {
        Mystring ReturnName = CutIndex(find_last_index(L"\\", size() - 2), size());
        ReturnName.EraseAll(L"\\");
        return IOName(*this);
    }
public:
    Mystring GetPath()
    {
        return *this;
    }

    bool isExist();

public: // delete constructer 
    MyPath();
    MyPath(const Mystring& _path);
    ~MyPath();
};




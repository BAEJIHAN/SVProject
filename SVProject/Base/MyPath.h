#pragma once
#include"Mystring.h"
//�з� : ���ڿ�
//�뵵 : ����
//���� : ���ڿ��� ������� ���ϰ� ���丮�� �̷�� �����ҵ��� ������ �ִ�.

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




#pragma once
#include <MyWinImage.h>
#include <Mystring.h>
#include <map>
//�з� : ���� �����
//�뵵 : �Ŵ�����Ʈ
//���� : ���ҽ����� �ҷ����� ������

class MyResMgr
{
private: //static variable
public:	//static func
    static MyResMgr& Inst()
    {
        // ���� static�̴ϱ� �ܺο��� �˼� ����?
        static MyResMgr SingleInst;
        return SingleInst;
    }

    void Release();
private: //member var
    std::map<Mystring, MyWinImage*> mImage;
public:	//constructor destructor
    MyResMgr();
    ~MyResMgr();


public: // delete constructer 
    MyResMgr(const MyResMgr& _Other) = delete;
    MyResMgr(const MyResMgr&& _Other) = delete;

public: // delete operator
    MyResMgr& operator=(const MyResMgr& _Other) = delete;
    MyResMgr& operator=(const MyResMgr&& _Other) = delete;

public: // member func
    MyWinImage* FindImage(const Mystring& _Name);

    void ImageLoad(const Mystring& _Path);
};




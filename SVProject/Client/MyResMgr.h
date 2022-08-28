#pragma once
#include <MyWinImage.h>
#include <Mystring.h>
#include <map>
//분류 : 파일 입출력
//용도 : 매니지먼트
//설명 : 리소스들을 불러오고 저장하

class MyResMgr
{
private: //static variable
public:	//static func
    static MyResMgr& Inst()
    {
        // 지역 static이니까 외부에서 알수 없죠?
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




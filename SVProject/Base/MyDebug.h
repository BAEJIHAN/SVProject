#pragma once
#include"Mystring.h"
//분류 : 디버깅
//용도 : 헬퍼
//설명 : 프레임워크에서 디버그 기능을 담당하는 클래스

class MyDebug
{
private: //static variable
public:	//static func
    static void LeakCheck();
    static void AssertMsg(const Mystring& _ErrorMsg);
    static void AssertMsg(const std::string& _ErrorMsg);
    static void OutPutMsg(const Mystring& _ErrorMsg);
private: //member var

public:	//constructor destructor
    MyDebug();
    ~MyDebug();


public: // delete constructer 
    MyDebug(const MyDebug& _Other) = delete;
    MyDebug(const MyDebug&& _Other) = delete;

public: // delete operator
    MyDebug& operator=(const MyDebug& _Other) = delete;
    MyDebug& operator=(const MyDebug&& _Other) = delete;

public: // member func
};




#pragma once
#include<memory>
//분류 : 메모리
//용도 : 헬퍼
//설명 : 메모리 기능 관련 클래스

class MyMemory
{
private: //static variable
public:	//static func
    template<typename Left, typename Right>
    static void Memcopy(Left& _Left, Right& _Test)
    {
        memcpy_s(&_Left, sizeof(Left), &_Test, sizeof(Right));
    }

    template<typename Data>
    static void MemZero(Data& _Value)
    {
        memset(&_Value, 0, sizeof(_Value));
    }
private: //member var

public:	//constructor destructor
    MyMemory();
    ~MyMemory();


public: // delete constructer 
    MyMemory(const MyMemory& _Other) = delete;
    MyMemory(const MyMemory&& _Other) = delete;

public: // delete operator
    MyMemory& operator=(const MyMemory& _Other) = delete;
    MyMemory& operator=(const MyMemory&& _Other) = delete;

public: // member func
};




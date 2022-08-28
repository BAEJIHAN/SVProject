#pragma once
#include <MyActor.h>
//분류 :
//용도 :
//설명 :
class MyRendererBasic;
class cloud2 : public MyActor
{
private: //static variable
public:	//static func
private: //member var
    MyRendererBasic* renderer;
public:	//constructor destructor
    cloud2();
    ~cloud2();


public: // delete constructer 
    cloud2(const cloud2& _Other) = delete;
    cloud2(const cloud2&& _Other) = delete;

public: // delete operator
    cloud2& operator=(const cloud2& _Other) = delete;
    cloud2& operator=(const cloud2&& _Other) = delete;

public: // member func
    void Start() override;
};




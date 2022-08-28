#pragma once
#include <MyActor.h>
//분류 :
//용도 :
//설명 :
class MyRendererBasic;
class cloud1 : public MyActor
{
private: //static variable
public:	//static func
private: //member var
    MyRendererBasic* renderer;
public:	//constructor destructor
    cloud1();
    ~cloud1();


public: // delete constructer 
    cloud1(const cloud1& _Other) = delete;
    cloud1(const cloud1&& _Other) = delete;

public: // delete operator
    cloud1& operator=(const cloud1& _Other) = delete;
    cloud1& operator=(const cloud1&& _Other) = delete;

public: // member func
    void Start() override;
};




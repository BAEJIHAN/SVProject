#pragma once
#include<MyActor.h>
//분류 :
//용도 :
//설명 :

class FarmBg : public MyActor
{
private: //static variable
public:	//static func
private: //member var

public:	//constructor destructor
    FarmBg();
    ~FarmBg();


public: // delete constructer 
    FarmBg(const FarmBg& _Other) = delete;
    FarmBg(const FarmBg&& _Other) = delete;

public: // delete operator
    FarmBg& operator=(const FarmBg& _Other) = delete;
    FarmBg& operator=(const FarmBg&& _Other) = delete;

public: // member func
    void Start() override;
};




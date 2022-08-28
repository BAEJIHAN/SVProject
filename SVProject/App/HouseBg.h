#pragma once
#include<MyActor.h>
//분류 :
//용도 :
//설명 :

class HouseBg : public MyActor
{
private: //static variable
public:	//static func
private: //member var

public:	//constructor destructor
    HouseBg();
    ~HouseBg();


public: // delete constructer 
    HouseBg(const HouseBg& _Other) = delete;
    HouseBg(const HouseBg&& _Other) = delete;

public: // delete operator
    HouseBg& operator=(const HouseBg& _Other) = delete;
    HouseBg& operator=(const HouseBg&& _Other) = delete;

public: // member func
    void Start() override;
};




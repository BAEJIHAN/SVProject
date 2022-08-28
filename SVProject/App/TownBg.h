#pragma once
#include<MyActor.h>
//분류 :
//용도 :
//설명 :

class TownBg :public MyActor
{
private: //static variable
public:	//static func
private: //member var

public:	//constructor destructor
    TownBg();
    ~TownBg();


public: // delete constructer 
    TownBg(const TownBg& _Other) = delete;
    TownBg(const TownBg&& _Other) = delete;

public: // delete operator
    TownBg& operator=(const TownBg& _Other) = delete;
    TownBg& operator=(const TownBg&& _Other) = delete;

public: // member func
    void Start() override;
};




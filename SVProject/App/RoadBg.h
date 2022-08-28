#pragma once
#include<MyActor.h>
//분류 :
//용도 :
//설명 :

class RoadBg : public MyActor
{
private: //static variable
public:	//static func
private: //member var

public:	//constructor destructor
    RoadBg();
    ~RoadBg();


public: // delete constructer 
    RoadBg(const RoadBg& _Other) = delete;
    RoadBg(const RoadBg&& _Other) = delete;

public: // delete operator
    RoadBg& operator=(const RoadBg& _Other) = delete;
    RoadBg& operator=(const RoadBg&& _Other) = delete;

public: // member func
    void Start() override;
};




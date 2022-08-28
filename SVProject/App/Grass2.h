#pragma once
#include"OtherBase.h"
//분류 :
//용도 :
//설명 :

class Grass2 : public OtherBase
{
private: //static variable
public:	//static func
private: //member var

public:	//constructor destructor
    Grass2();
    ~Grass2();


public: // delete constructer 
    Grass2(const Grass2& _Other) = delete;
    Grass2(const Grass2&& _Other) = delete;

public: // delete operator
    Grass2& operator=(const Grass2& _Other) = delete;
    Grass2& operator=(const Grass2&& _Other) = delete;

public: // member func
    void Start() override;
};




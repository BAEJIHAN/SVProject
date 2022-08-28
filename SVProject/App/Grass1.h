#pragma once
#include"OtherBase.h"
//분류 :
//용도 :
//설명 :

class Grass1 : public OtherBase
{
private: //static variable
public:	//static func
private: //member var

public:	//constructor destructor
    Grass1();
    ~Grass1();


public: // delete constructer 
    Grass1(const Grass1& _Other) = delete;
    Grass1(const Grass1&& _Other) = delete;

public: // delete operator
    Grass1& operator=(const Grass1& _Other) = delete;
    Grass1& operator=(const Grass1&& _Other) = delete;

public: // member func
    void Start() override;
};




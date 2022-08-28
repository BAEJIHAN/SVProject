#pragma once
#include"OtherBase.h"
//분류 :
//용도 :
//설명 :

class Grass3 : public OtherBase
{
private: //static variable
public:	//static func
private: //member var

public:	//constructor destructor
    Grass3();
    ~Grass3();


public: // delete constructer 
    Grass3(const Grass3& _Other) = delete;
    Grass3(const Grass3&& _Other) = delete;

public: // delete operator
    Grass3& operator=(const Grass3& _Other) = delete;
    Grass3& operator=(const Grass3&& _Other) = delete;

public: // member func
    void Start() override;
};




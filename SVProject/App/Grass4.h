#pragma once
#include"OtherBase.h"
//분류 :
//용도 :
//설명 :

class Grass4 : public OtherBase
{
private: //static variable
public:	//static func
private: //member var

public:	//constructor destructor
    Grass4();
    ~Grass4();


public: // delete constructer 
    Grass4(const Grass4& _Other) = delete;
    Grass4(const Grass4&& _Other) = delete;

public: // delete operator
    Grass4& operator=(const Grass4& _Other) = delete;
    Grass4& operator=(const Grass4&& _Other) = delete;

public: // member func
    void Start() override;
};




#pragma once
#include"OtherBase.h"
//분류 :
//용도 :
//설명 :
class MyCollision;
class Stone1 : public OtherBase
{
private: //static variable
public:	//static func
private: //member var
    MyCollision* col;
public:	//constructor destructor
    Stone1();
    ~Stone1();


public: // delete constructer 
    Stone1(const Stone1& _Other) = delete;
    Stone1(const Stone1&& _Other) = delete;

public: // delete operator
    Stone1& operator=(const Stone1& _Other) = delete;
    Stone1& operator=(const Stone1&& _Other) = delete;

public: // member func
    void Start() override;
};




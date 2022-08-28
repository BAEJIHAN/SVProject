#pragma once
#include"OtherBase.h"
//분류 :
//용도 :
//설명 :
class MyCollision;
class Stone2 : public OtherBase
{
private: //static variable
public:	//static func
private: //member var
    MyCollision* col;
public:	//constructor destructor
    Stone2();
    ~Stone2();


public: // delete constructer 
    Stone2(const Stone2& _Other) = delete;
    Stone2(const Stone2&& _Other) = delete;

public: // delete operator
    Stone2& operator=(const Stone2& _Other) = delete;
    Stone2& operator=(const Stone2&& _Other) = delete;

public: // member func
    void Start() override;
};




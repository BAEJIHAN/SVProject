#pragma once
#include"Crop.h"
//�з� :
//�뵵 :
//���� :

class cabbage : public Crop
{
private: //static variable
public:	//static func
private: //member var

public:	//constructor destructor
    cabbage();
    ~cabbage();


public: // delete constructer 
    cabbage(const cabbage& _Other) = delete;
    cabbage(const cabbage&& _Other) = delete;

public: // delete operator
    cabbage& operator=(const cabbage& _Other) = delete;
    cabbage& operator=(const cabbage&& _Other) = delete;

public: // member func
    void Start() override;
    void DeathTask() override;
};




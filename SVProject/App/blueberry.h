#pragma once
#include "Crop.h"
//�з� :
//�뵵 :
//���� :

class blueberry : public Crop
{
private: //static variable
public:	//static func
private: //member var

public:	//constructor destructor
    blueberry();
    ~blueberry();


public: // delete constructer 
    blueberry(const blueberry& _Other) = delete;
    blueberry(const blueberry&& _Other) = delete;

public: // delete operator
    blueberry& operator=(const blueberry& _Other) = delete;
    blueberry& operator=(const blueberry&& _Other) = delete;

public: // member func
    void Start() override;
    void DeathTask() override;
};




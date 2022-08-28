#pragma once
#include "Crop.h"
//분류 :
//용도 :
//설명 :

class eggplant : public Crop
{
private: //static variable
public:	//static func
private: //member var

public:	//constructor destructor
    eggplant();
    ~eggplant();


public: // delete constructer 
    eggplant(const eggplant& _Other) = delete;
    eggplant(const eggplant&& _Other) = delete;

public: // delete operator
    eggplant& operator=(const eggplant& _Other) = delete;
    eggplant& operator=(const eggplant&& _Other) = delete;

public: // member func
    void Start() override;
    void DeathTask() override;
};




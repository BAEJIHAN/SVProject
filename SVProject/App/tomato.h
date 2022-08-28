#pragma once
#include "Crop.h"
//분류 :
//용도 :
//설명 :

class tomato : public Crop
{
private: //static variable
public:	//static func
private: //member var

public:	//constructor destructor
    tomato();
    ~tomato();


public: // delete constructer 
    tomato(const tomato& _Other) = delete;
    tomato(const tomato&& _Other) = delete;

public: // delete operator
    tomato& operator=(const tomato& _Other) = delete;
    tomato& operator=(const tomato&& _Other) = delete;

public: // member func
    void Start() override;
    void DeathTask() override;
};




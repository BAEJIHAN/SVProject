#pragma once
#include<MyActor.h>
//분류 :
//용도 :
//설명 :
class MyRendererBasic;
class EnergyUI : public MyActor
{
private: //static variable
public:	//static func
private: //member var
    MyRendererBasic* mainrender;
    MyRendererBasic* barrender;
public:	//constructor destructor
    EnergyUI();
    ~EnergyUI();


public: // delete constructer 
    EnergyUI(const EnergyUI& _Other) = delete;
    EnergyUI(const EnergyUI&& _Other) = delete;

public: // delete operator
    EnergyUI& operator=(const EnergyUI& _Other) = delete;
    EnergyUI& operator=(const EnergyUI&& _Other) = delete;

public: // member func
    void Start();
    void SetBar(int enery);
};




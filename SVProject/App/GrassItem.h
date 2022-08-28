#pragma once
#include "FieldItem.h"
//분류 :
//용도 :
//설명 :

class GrassItem : public FieldItem
{
private: //static variable
public:	//static func
private: //member var
   
public:	//constructor destructor
    GrassItem();
    ~GrassItem();


public: // delete constructer 
    GrassItem(const GrassItem& _Other) = delete;
    GrassItem(const GrassItem&& _Other) = delete;

public: // delete operator
    GrassItem& operator=(const GrassItem& _Other) = delete;
    GrassItem& operator=(const GrassItem&& _Other) = delete;

public: // member func
    void Start() override;
    void DeathTask() override;

};




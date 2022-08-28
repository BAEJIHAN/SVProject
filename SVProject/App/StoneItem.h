#pragma once
#include "FieldItem.h"
//분류 :
//용도 :
//설명 :

class StoneItem : public FieldItem
{
private: //static variable
public:	//static func
private: //member var

public:	//constructor destructor
    StoneItem();
    ~StoneItem();


public: // delete constructer 
    StoneItem(const StoneItem& _Other) = delete;
    StoneItem(const StoneItem&& _Other) = delete;

public: // delete operator
    StoneItem& operator=(const StoneItem& _Other) = delete;
    StoneItem& operator=(const StoneItem&& _Other) = delete;

public: // member func
    void Start() override;
    void DeathTask() override;
};




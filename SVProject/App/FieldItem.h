#pragma once
#include <MyActor.h>
//분류 :
//용도 :
//설명 :
class MyRendererBasic;
class FieldItem : public MyActor
{
private: //static variable
public:	//static func
private: //member var

public:
    ITEMINDEX fielditemindex;
    MyRendererBasic* renderer;
public:	//constructor destructor
    FieldItem();
    ~FieldItem();


public: // delete constructer 
    FieldItem(const FieldItem& _Other) = delete;
    FieldItem(const FieldItem&& _Other) = delete;

public: // delete operator
    FieldItem& operator=(const FieldItem& _Other) = delete;
    FieldItem& operator=(const FieldItem&& _Other) = delete;

public: // member func
};




#pragma once
#include <MyActor.h>
//�з� :
//�뵵 :
//���� :
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




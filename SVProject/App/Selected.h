#pragma once
#include<MyActor.h>
//�з� :
//�뵵 :
//���� :
class MyRendererBasic;
class Selected : public MyActor
{
private: //static variable
public:	//static func
private: //member var
    MyRendererBasic* renderer;
public:	//constructor destructor
    Selected();
    ~Selected();


public: // delete constructer 
    Selected(const Selected& _Other) = delete;
    Selected(const Selected&& _Other) = delete;

public: // delete operator
    Selected& operator=(const Selected& _Other) = delete;
    Selected& operator=(const Selected&& _Other) = delete;

public: // member func
    void Start() override;
    void SetPivot(float4 _pivot);
};




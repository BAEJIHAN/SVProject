#pragma once
#include<MyActor.h>
//�з� :
//�뵵 :
//���� :

class StoreBg : public MyActor
{
private: //static variable
public:	//static func
private: //member var

public:	//constructor destructor
    StoreBg();
    ~StoreBg();


public: // delete constructer 
    StoreBg(const StoreBg& _Other) = delete;
    StoreBg(const StoreBg&& _Other) = delete;

public: // delete operator
    StoreBg& operator=(const StoreBg& _Other) = delete;
    StoreBg& operator=(const StoreBg&& _Other) = delete;

public: // member func
    void Start() override;
};




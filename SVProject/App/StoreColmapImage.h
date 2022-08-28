#pragma once
#include <MyActor.h>
//분류 :
//용도 :
//설명 :
class MyRendererBasic;
class StoreColmapImage : public MyActor
{
private: //static variable
public:	//static func
private: //member var
    MyRendererBasic* renderer;
public:	//constructor destructor
    bool bOnOff;

    StoreColmapImage();
    ~StoreColmapImage();


public: // delete constructer 
    StoreColmapImage(const StoreColmapImage& _Other) = delete;
    StoreColmapImage(const StoreColmapImage&& _Other) = delete;

public: // delete operator
    StoreColmapImage& operator=(const StoreColmapImage& _Other) = delete;
    StoreColmapImage& operator=(const StoreColmapImage&& _Other) = delete;

public: // member func
    void Start() override;
    void OnOff();
};




#pragma once
#include <MyActor.h>
//분류 :
//용도 :
//설명 :
class MyRendererBasic;
class FarmColmapImage : public MyActor
{
private: //static variable
public:	//static func
private: //member var
    MyRendererBasic* renderer;
public:	//constructor destructor
    bool bOnOff;

    FarmColmapImage();
    ~FarmColmapImage();


public: // delete constructer 
    FarmColmapImage(const FarmColmapImage& _Other) = delete;
    FarmColmapImage(const FarmColmapImage&& _Other) = delete;

public: // delete operator
    FarmColmapImage& operator=(const FarmColmapImage& _Other) = delete;
    FarmColmapImage& operator=(const FarmColmapImage&& _Other) = delete;

public: // member func
    void Start() override;
    void OnOff();
};




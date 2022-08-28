#pragma once
#include <MyActor.h>
//분류 :
//용도 :
//설명 :
class MyRendererBasic;
class HouseColmapImage : public MyActor
{
private: //static variable
public:	//static func
private: //member var
    MyRendererBasic* renderer;
    
public:	//constructor destructor
    bool bOnOff;

    HouseColmapImage();
    ~HouseColmapImage();


public: // delete constructer 
    HouseColmapImage(const HouseColmapImage& _Other) = delete;
    HouseColmapImage(const HouseColmapImage&& _Other) = delete;

public: // delete operator
    HouseColmapImage& operator=(const HouseColmapImage& _Other) = delete;
    HouseColmapImage& operator=(const HouseColmapImage&& _Other) = delete;

public: // member func
    void Start() override;
    void OnOff();
};




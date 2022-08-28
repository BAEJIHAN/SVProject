#pragma once
#include <MyActor.h>
//분류 :
//용도 :
//설명 :
class MyRendererBasic;
class RoadColmapImage : public MyActor
{
private: //static variable
public:	//static func
private: //member var
    MyRendererBasic* renderer;
public:	//constructor destructor
    bool bOnOff;

    RoadColmapImage();
    ~RoadColmapImage();


public: // delete constructer 
    RoadColmapImage(const RoadColmapImage& _Other) = delete;
    RoadColmapImage(const RoadColmapImage&& _Other) = delete;

public: // delete operator
    RoadColmapImage& operator=(const RoadColmapImage& _Other) = delete;
    RoadColmapImage& operator=(const RoadColmapImage&& _Other) = delete;

public: // member func
    void Start() override;
    void OnOff();
};




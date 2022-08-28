#pragma once
#include <MyActor.h>
//�з� :
//�뵵 :
//���� :
class MyRendererBasic;
class TownColmapImage : public MyActor
{
private: //static variable
public:	//static func
private: //member var
    MyRendererBasic* renderer;
public:	//constructor destructor
    bool bOnOff;

    TownColmapImage();
    ~TownColmapImage();


public: // delete constructer 
    TownColmapImage(const TownColmapImage& _Other) = delete;
    TownColmapImage(const TownColmapImage&& _Other) = delete;

public: // delete operator
    TownColmapImage& operator=(const TownColmapImage& _Other) = delete;
    TownColmapImage& operator=(const TownColmapImage&& _Other) = delete;

public: // member func
    void Start() override;
    void OnOff();
};




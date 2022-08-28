#pragma once
#include<MyActor.h>
#include<vector>
//분류 :
//용도 :
//설명 :

class bagItemInfo
{
public:
    ITEMINDEX index;

    bagItemInfo() :index(ITEMINDEX::NONE)
    {}
    ~bagItemInfo()
    {}
};

class FieldItem;
class Crop;
class MyRendererBasic;
class MyCollision;
class BagUI : public MyActor
{
private: //static variable
public:	//static func
private: //member var
    MyRendererBasic* MainRenderer;
    std::vector<MyRendererBasic*> Itemrenderervector;
    std::vector<bagItemInfo> iteminfovector;
    std::vector< MyCollision*> itemcolvector;
public:
    bool bbagon;

public:	//constructor destructor
    BagUI();
    ~BagUI();


public: // delete constructer 
    BagUI(const BagUI& _Other) = delete;
    BagUI(const BagUI&& _Other) = delete;

public: // delete operator
    BagUI& operator=(const BagUI& _Other) = delete;
    BagUI& operator=(const BagUI&& _Other) = delete;

public: // member func
    void Start() override;
    void AddItem(FieldItem* _item);
    void AddCrop(Crop* _crop);
    void BagOn();
    void BagOff();
    void ColStay(MyCollision* _this, MyCollision* _other);
};




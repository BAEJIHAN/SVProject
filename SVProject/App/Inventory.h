#pragma once
#include<MyActor.h>
#include<vector>
#include<Mystring.h>
#include"Crop.h"
#include<map>


const Mystring invenimage[18] =
{ L"invenaxe.bmp", L"invenhoe.bmp", L"invenwater.bmp", L"invenpick.bmp", L"invensickle.bmp", L"invenpotato.bmp",
L"inveneggplant.bmp", L"invenraddish.bmp", L"inventomato.bmp", L"invencabbage.bmp", L"invenbluberry.bmp",
 L"invenpotatoseed.bmp",L"inveneggplantseed.bmp", L"invenradishseed.bmp", L"inventomatoseed.bmp",
    L"invencabbageseed.bmp", L"invenblueberryseed.bmp",L"invenblank.bmp"};


//분류 :
//용도 :
//설명 :
class MyRendererBasic;
class MyCollision;
class Inventory : public MyActor
{
private: //static variable
public:	//static func
private: //member var
    std::vector<ItemInfo*> ItemVector;
    std::vector<MyRendererBasic*> RendererVector;
    std::vector<MyCollision*> CollisionVector;
   


public:
  
    int CheckIndex(MyCollision* _Pointer);

public:
    void ColEnter(MyCollision* _this, MyCollision* _other);

public:	//constructor destructor
    Inventory();
    ~Inventory();


public: // delete constructer 
    Inventory(const Inventory& _Other) = delete;
    Inventory(const Inventory&& _Other) = delete;

public: // delete operator
    Inventory& operator=(const Inventory& _Other) = delete;
    Inventory& operator=(const Inventory&& _Other) = delete;

public: // member func
    void Start() override;
    void AddCrop(Crop* _crop);
    void AddSeed(ITEMINDEX _index);
   
};




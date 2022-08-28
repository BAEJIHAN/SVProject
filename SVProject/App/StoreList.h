#pragma once
#include<MyActor.h>
//분류 :
//용도 :
//설명 :
class Inventory;
class StoreList : public MyActor
{
private: //static variable
public:	//static func
private: //member var
    MyRendererBasic* Renderer;
    //MyRendererBasic* itemRenderer1;
    //MyRendererBasic* itemRenderer2;
    //MyRendererBasic* itemRenderer3;
    //MyRendererBasic* itemRenderer4;
    //MyRendererBasic* itemRenderer5;
    //MyRendererBasic* itemRenderer6;


    ItemInfo* itemInfo1;
    ItemInfo* itemInfo2;
    ItemInfo* itemInfo3;
    ItemInfo* itemInfo4;
    ItemInfo* itemInfo5;
    ItemInfo* itemInfo6;

    MyCollision* itemCollision1;
    MyCollision* itemCollision2;
    MyCollision* itemCollision3;
    MyCollision* itemCollision4;
    MyCollision* itemCollision5;
    MyCollision* itemCollision6;
    MyCollision* exitbuttonCollision;


  


public:	//constructor destructor
    StoreList();
    ~StoreList();

    void StoreOff();
    void StoreOn();

public: // delete constructer 
    StoreList(const StoreList& _Other) = delete;
    StoreList(const StoreList&& _Other) = delete;

public: // delete operator
    StoreList& operator=(const StoreList& _Other) = delete;
    StoreList& operator=(const StoreList&& _Other) = delete;

public: // member func
    void Start() override;
    void ExitColStay(MyCollision* _this, MyCollision* _other);
    void Item1ColStay(MyCollision* _this, MyCollision* _other);
    void Item2ColStay(MyCollision* _this, MyCollision* _other);
    void Item3ColStay(MyCollision* _this, MyCollision* _other);
    void Item4ColStay(MyCollision* _this, MyCollision* _other);
    void Item5ColStay(MyCollision* _this, MyCollision* _other);
    void Item6ColStay(MyCollision* _this, MyCollision* _other);
    
};




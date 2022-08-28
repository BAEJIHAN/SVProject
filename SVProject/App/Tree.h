#pragma once
#include "OtherBase.h"
#include <MyTimeEventer.h>
//분류 :
//용도 :
//설명 :
class MyCollision;
class MyRendererBasic;

class Tree : public OtherBase
{
private: //static variable
public:	//static func
private: //member var
    MyCollision* col;
    MyRendererBasic* renderer1;
    MyRendererBasic* renderer2;
    MyTimeEventer<Tree> TreeEventer;
    bool btreebreaksound;
   
    
public:	//constructor destructor
    int HP;
    bool bHit;
    bool bShakeOn;
    Tree();
    ~Tree();

public: // delete constructer 
    Tree(const Tree& _Other) = delete;
    Tree(const Tree&& _Other) = delete;

public: // delete operator
    Tree& operator=(const Tree& _Other) = delete;
    Tree& operator=(const Tree&& _Other) = delete;

public: // member func
    void Start() override;
    void Update() override;
    void HitStart();
    void HitEnd();
    void Shake();
 /*   void ColStart(MyCollision* _this, MyCollision* _other);
    void ColStay(MyCollision* _this, MyCollision* _other);
    void ColEnd(MyCollision* _this, MyCollision* _other);*/
};




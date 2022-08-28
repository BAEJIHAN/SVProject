#pragma once
#include <MyActor.h>
//분류 :
//용도 :
//설명 :
class MyRendererBasic;
class MyCollision;
class TitleBackGround : public MyActor
{
private: //static variable
public:	//static func
private: //member var
    MyRendererBasic* SkyRenderer;  
    MyRendererBasic* StardewRenderer;
    MyRendererBasic* StartButtonRenderer;
    MyRendererBasic* EditButtonRenderer;

    MyCollision* StartButtonCol;
    MyCollision* EditButtonCol;
public:	//constructor destructor
    TitleBackGround();
    ~TitleBackGround();


public: // delete constructer 
    TitleBackGround(const TitleBackGround& _Other) = delete;
    TitleBackGround(const TitleBackGround&& _Other) = delete;

public: // delete operator
    TitleBackGround& operator=(const TitleBackGround& _Other) = delete;
    TitleBackGround& operator=(const TitleBackGround&& _Other) = delete;

public: // member func
    void Start();

    void StartColStart(MyCollision* _this, MyCollision* _other);
    void StartColStay(MyCollision* _this, MyCollision* _other); 
    void StartColEnd(MyCollision* _this, MyCollision* _other);
    void EditColStart(MyCollision* _this, MyCollision* _other);
    void EditColStay(MyCollision* _this, MyCollision* _other);
    void EditColEnd(MyCollision* _this, MyCollision* _other);
    
};




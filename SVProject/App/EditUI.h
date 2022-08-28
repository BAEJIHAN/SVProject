#pragma once
#include<MyActor.h>
//분류 :
//용도 :
//설명 :
class MyEditorScene;
class Mystring;
class EditUI :public MyActor
{
private: //static variable
public:	//static func
private: //member var
    MyRendererBasic* MainRenderer;
    MyCollision* MainCol;
    MyEditorScene* CurScene;
    MyRendererBasic* ToggleRenderer;
    MyCollision* ToggleCol;

    MyRendererBasic* uibuttonrenderer1;
    MyRendererBasic* uibuttonrenderer2;
    MyRendererBasic* uibuttonrenderer3;
    MyRendererBasic* uibuttonrenderer4;
    MyRendererBasic* uibuttonrenderer5;
    MyRendererBasic* uibuttonrenderer6;
    MyRendererBasic* uibuttonrenderer7;
    
    MyCollision* uibuttoncol1;
    MyCollision* uibuttoncol2;
    MyCollision* uibuttoncol3;
    MyCollision* uibuttoncol4;
    MyCollision* uibuttoncol5;
    MyCollision* uibuttoncol6;
    MyCollision* uibuttoncol7;
    
    MyRendererBasic* savebuttonrenderer;
    MyRendererBasic* loadbuttonrenderer;

    MyCollision* savebuttonrcol;
    MyCollision* loadbuttonrcol;
   
    
public:	//constructor destructor
    EditUI();
    ~EditUI();


public: // delete constructer 
    EditUI(const EditUI& _Other) = delete;
    EditUI(const EditUI&& _Other) = delete;

public: // delete operator
    EditUI& operator=(const EditUI& _Other) = delete;
    EditUI& operator=(const EditUI&& _Other) = delete;

public: // member func
    void UIOff();
    void UIOn();

    void SetRender(MyRendererBasic* renderer, Mystring image, float4 scale, float4 pivot = 0);
    void SetCol(MyCollision* col, float4 scale, float4 pivot = 0);

    void Start() override;
    void MainColEnter(MyCollision* _this, MyCollision* _other);
    void MainColExit(MyCollision* _this, MyCollision* _other);
    void ToggleColEnter(MyCollision* _this, MyCollision* _other);
    void ToggleColExit(MyCollision* _this, MyCollision* _other);
    void ToggleColStay(MyCollision* _this, MyCollision* _other);
    void Button1ColStay(MyCollision* _this, MyCollision* _other);
    void Button2ColStay(MyCollision* _this, MyCollision* _other);
    void Button3ColStay(MyCollision* _this, MyCollision* _other);
    void Button4ColStay(MyCollision* _this, MyCollision* _other);
    void Button5ColStay(MyCollision* _this, MyCollision* _other);
    void Button6ColStay(MyCollision* _this, MyCollision* _other);
    void Button7ColStay(MyCollision* _this, MyCollision* _other);
    void SaveButtonColStay(MyCollision* _this, MyCollision* _other);
    void LoadButtonColStay(MyCollision* _this, MyCollision* _other);
};




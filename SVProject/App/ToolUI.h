#pragma once
#include<MyActor.h>
#include<Mystring.h>
//분류 :
//용도 :
//설명 :
class MyRendererBasic;
class ToolUI : public MyActor
{
private: //static variable
public:	//static func
private: //member var
    MyRendererBasic* Renderer;
public:	//constructor destructor
    ToolUI();
    ~ToolUI();
	

public: // delete constructer 
    ToolUI(const ToolUI& _Other) = delete;
    ToolUI(const ToolUI&& _Other) = delete;

public: // delete operator
    ToolUI& operator=(const ToolUI& _Other) = delete;
    ToolUI& operator=(const ToolUI&& _Other) = delete;

public: // member func
    void Start() override;
    void ToolUIImage(const Mystring& _Str, float4 _Scale);
};




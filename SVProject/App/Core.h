#pragma once
#include <MyScene.h>
#include <Mystring.h>
#include <map>
#include <MySceneManager.h>
//분류 : 플랫폼
//용도 : 업데이터
//설명 : 프레임워크 전체를 시작하고 업데이트 하는 클래스

class Core
{
private: //static variable
public:	//static func
private: //member var

public:
    static MySceneManager SceneManager;

public:	//constructor destructor
    Core();
    ~Core();


public: // delete constructer 
    Core(const Core& _Other) = delete;
    Core(const Core&& _Other) = delete;

public: // delete operator
    Core& operator=(const Core& _Other) = delete;
    Core& operator=(const Core&& _Other) = delete;

public: // member func
    static void Start();
    static void Update();
    static void End();
};




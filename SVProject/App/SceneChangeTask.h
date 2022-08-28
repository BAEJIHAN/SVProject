#pragma once

//분류 :
//용도 :
//설명 :

class SceneChangeTask
{
private: //static variable
public:	//static func
private: //member var

public:	//constructor destructor
    SceneChangeTask();
    ~SceneChangeTask();


public: // delete constructer 
    SceneChangeTask(const SceneChangeTask& _Other) = delete;
    SceneChangeTask(const SceneChangeTask&& _Other) = delete;

public: // delete operator
    SceneChangeTask& operator=(const SceneChangeTask& _Other) = delete;
    SceneChangeTask& operator=(const SceneChangeTask&& _Other) = delete;

public: // member func
};




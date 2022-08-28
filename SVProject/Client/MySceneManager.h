#pragma once
#include <map>
#include <Mystring.h>
#include "MyScene.h"
//분류 : 렌더링
//용도 : 매니지먼트
//설명 : 씬을 생성하고 바꾸는 기능을 한다.

class MySceneManager
{
private: //static variable
public:	//static func
private: //member var
    std::map<Mystring, MyScene*> AllScene;
    MyScene* CurScene;
    MyScene* NextScene;
public:	//constructor destructor
    MyScene* GetCurScene()
    {
        return CurScene;
    }

    template<typename SceneType>
    MyScene* CreateScene(const Mystring& _Name)
    {
        std::map<Mystring, MyScene*>::iterator FindIter
            = AllScene.find(_Name);

       
        if (AllScene.end() != FindIter)
        {           
            return AllScene[_Name];
        }          

        SceneType* NewScene = new SceneType();

        NewScene->Start();

        
        AllScene.insert(std::map<Mystring, MyScene*>::value_type(_Name, NewScene));
        return NewScene;
    }


   
    MyScene* FindScene(const Mystring& _Name);

    void ChangeScene(const Mystring& _Name); 

    void ChangeCheck(); 
    MySceneManager();
    ~MySceneManager();


public: // delete constructer 
    MySceneManager(const MySceneManager& _Other) = delete;
    MySceneManager(const MySceneManager&& _Other) = delete;

public: // delete operator
    MySceneManager& operator=(const MySceneManager& _Other) = delete;
    MySceneManager& operator=(const MySceneManager&& _Other) = delete;

public: // member func
};




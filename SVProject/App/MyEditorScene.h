#pragma once
#include "SceneBase.h"
//분류 :
//용도 :
//설명 :

class FarmBg;
class MyTileBackGround;
class EditUI;
class OtherBase;
class MyEditorScene : public SceneBase
{
private: //static variable
public:	//static func
    bool bCanPut;
    TILEVAR tilevar;
private: //member var
    EditUI* editui;
    FarmBg* BackGround;
    MyTileBackGround* TileBackGround;

public:
    static std::map<__int64, TILEVAR> m_SaveTile;
    
public:	//constructor destructor
    MyEditorScene();
    ~MyEditorScene();


public: // delete constructer 
    MyEditorScene(const MyEditorScene& _Other) = delete;
    MyEditorScene(const MyEditorScene&& _Other) = delete;

public: // delete operator
    MyEditorScene& operator=(const MyEditorScene& _Other) = delete;
    MyEditorScene& operator=(const MyEditorScene&& _Other) = delete;

public: // member func
    void Start() override;
    void SceneUpdate() override;
    void SceneChangeStart() override;
    void MakeObject(float4 _TilePos, TILEVAR _tilevar, OtherBase* _obj);

    void LoadTile();
};




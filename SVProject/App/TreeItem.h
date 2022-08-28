#pragma once
#include "FieldItem.h"
//분류 :
//용도 :
//설명 :

class TreeItem : public FieldItem
{
private: //static variable
public:	//static func
private: //member var
    
public:	//constructor destructor
    TreeItem();
    ~TreeItem();


public: // delete constructer 
    TreeItem(const TreeItem& _Other) = delete;
    TreeItem(const TreeItem&& _Other) = delete;

public: // delete operator
    TreeItem& operator=(const TreeItem& _Other) = delete;
    TreeItem& operator=(const TreeItem&& _Other) = delete;

public: // member func
    void Start() override;
    void DeathTask() override;
};




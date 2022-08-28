#pragma once
#include <MyScene.h>
#include <Mystring.h>
#include <map>
#include <MySceneManager.h>
//�з� : �÷���
//�뵵 : ��������
//���� : �����ӿ�ũ ��ü�� �����ϰ� ������Ʈ �ϴ� Ŭ����

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




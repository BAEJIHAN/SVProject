#pragma once
#include<MyActor.h>
// �з� :
// �뵵 :
// ���� :
class MouseObject : public MyActor
{
public:
	MyRendererBasic* MouseRenderer;

public:		//constructer destructer
	MouseObject();
	~MouseObject();

public:		// delete constructer
	MouseObject(const MouseObject& _Other) = delete;
	MouseObject(const MouseObject&& _Other) = delete;

public:		//delete operator
	MouseObject& operator=(const MouseObject& _Other) = delete;
	MouseObject& operator=(const MouseObject&& _Other) = delete;

public:
	void Start() override;
	void Update() override;
};


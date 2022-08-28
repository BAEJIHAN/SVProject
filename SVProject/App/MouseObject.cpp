#include "MouseObject.h"
#include <MyWindow.h>
#include <MyRendererBasic.h>
#include <MyCollision.h>


// Static Var
// Static Func

// constructer destructer
MouseObject::MouseObject()
{
}

MouseObject::~MouseObject()
{
}

//member Func

void MouseObject::Start() 
{
	MouseRenderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::MOUSE);
	MouseRenderer->TransSetting(L"cursor.bmp", float4(34.0f, 42.0f));
	MouseRenderer->SetPivotPos(float4(15.0f, 18.0f));
	MouseRenderer->CamEffectOff();


	MyCollision* MyCol = CreateCollision<MyCollision>(COLINDEX::MOUSE);
	
}

void MouseObject::Update() 
{
    SetPosition(MyWindow::MousePos());
}
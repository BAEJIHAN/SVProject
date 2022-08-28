#include "MyTitleScene.h"
#include <MyTimer.h>
#include "MouseObject.h"
#include <MyWindow.h>
#include <MyInput.h>
#include "Core.h"
#include "cloud1.h"
#include "cloud2.h"
#include "TitleBackGround.h"
MyTitleScene::MyTitleScene()
{
}

MyTitleScene::~MyTitleScene()
{
}

void MyTitleScene::Start()
{
	CollisionGroupLink(COLINDEX::BUTTON, COLINDEX::MOUSE);
	MouseObject* Mouse = CreateActor<MouseObject>();
	title = CreateActor<TitleBackGround>();
	Cloud1 = CreateActor<cloud1>();
	Cloud1->SetPosition(float4(0, 300));
	Cloud2 = CreateActor<cloud2>();
	Cloud2->SetPosition(float4(800, 300));

}

void MyTitleScene::SceneUpdate()
{
	
	float movepos1 = MyTimer::FDeltaTime(10.0f);
	float movepos2 = MyTimer::FDeltaTime(10.0f);
	
	Cloud1->MovePosition(float4(-movepos1, 0.f));
	Cloud2->MovePosition(float4(-movepos2, 0.f));
	if (Cloud1->GetPosition().x < -800)
	{
		Cloud1->SetPosition(float4(1200, 300));
		
	}
	if (Cloud2->GetPosition().x < -800)
	{
		Cloud2->SetPosition(float4(1200, 300));
		
	}
}

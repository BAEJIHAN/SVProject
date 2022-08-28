#include "EditUI.h"
#include<MyRendererBasic.h>
#include<MyInput.h>
#include"MyEditorScene.h"
#include <MyFile.h>

EditUI::EditUI() :
MainRenderer(nullptr),
MainCol(nullptr),
uibuttonrenderer1(nullptr),
uibuttonrenderer2(nullptr),
uibuttonrenderer3(nullptr),
uibuttonrenderer4(nullptr),
uibuttonrenderer5(nullptr),
uibuttonrenderer6(nullptr),
uibuttonrenderer7(nullptr),
uibuttoncol1(nullptr),
uibuttoncol2(nullptr),
uibuttoncol3(nullptr),
uibuttoncol4(nullptr),
uibuttoncol5(nullptr),
uibuttoncol6(nullptr),
uibuttoncol7(nullptr)

{
}

EditUI::~EditUI()
{
}

void EditUI::Start()
{

	CurScene = (MyEditorScene*)GetScene();
	//UI틀
	MainRenderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::UI);	
	SetRender(MainRenderer, L"editui.bmp", float4(560.0f, 346.0f));
	
	MainCol = CreateCollision<MyCollision>(COLINDEX::BUTTON);
	MainCol->SetScale(float4(560.0f, 346.0f));
	MainCol->AddStartEvent(this, &EditUI::MainColEnter);
	MainCol->AddEndEvent(this, &EditUI::MainColExit);

	//toggle 키
	ToggleRenderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::UIBUTTON);
	SetRender(ToggleRenderer, L"edittogglebutton.bmp", float4(44, 44), float4(234, -130));
	

	ToggleCol = CreateCollision<MyCollision>(COLINDEX::BUTTON);
	SetCol(ToggleCol, float4(44, 44), float4(234, -130));
	ToggleCol->AddStayEvent(this, &EditUI::ToggleColStay);
	ToggleCol->AddStartEvent(this, &EditUI::ToggleColEnter);
	ToggleCol->AddEndEvent(this, &EditUI::ToggleColExit);

	//object 선택 버튼
	uibuttonrenderer1= CreateRenderer<MyRendererBasic>(RENDERINDEX::UIBUTTON);
	SetRender(uibuttonrenderer1, L"grass1.bmp", float4(64.0f, 64.0f),float4(-200.f, -50.f));
	uibuttonrenderer2= CreateRenderer<MyRendererBasic>(RENDERINDEX::UIBUTTON);
	SetRender(uibuttonrenderer2, L"grass2.bmp", float4(64.0f, 64.0f), float4(-136.f, -50.f));
	uibuttonrenderer3= CreateRenderer<MyRendererBasic>(RENDERINDEX::UIBUTTON);	   
	SetRender(uibuttonrenderer3, L"grass3.bmp", float4(64.0f, 64.0f), float4(-72.f, -50.f));
	uibuttonrenderer4= CreateRenderer<MyRendererBasic>(RENDERINDEX::UIBUTTON);	   
	SetRender(uibuttonrenderer4, L"grass4.bmp", float4(64.0f, 64.0f), float4(-8.f, -50.f));
	uibuttonrenderer5= CreateRenderer<MyRendererBasic>(RENDERINDEX::UIBUTTON);	  
	SetRender(uibuttonrenderer5, L"stone1.bmp", float4(64.0f, 64.0f), float4(56.f, -50.f));
	uibuttonrenderer6= CreateRenderer<MyRendererBasic>(RENDERINDEX::UIBUTTON);	   
	SetRender(uibuttonrenderer6, L"stone2.bmp", float4(64.0f, 64.0f), float4(120.f, -50.f));
	uibuttonrenderer7= CreateRenderer<MyRendererBasic>(RENDERINDEX::UIBUTTON);
	SetRender(uibuttonrenderer7, L"tree.bmp", float4(64.0f, 64.0f), float4(184.f, -50.f));

	uibuttoncol1 = CreateCollision<MyCollision>(COLINDEX::BUTTON);
	SetCol(uibuttoncol1, float4(64.0f, 64.0f), float4(-200.f, -50.f));
	uibuttoncol1->AddStayEvent(this, &EditUI::Button1ColStay);
	
	uibuttoncol2 = CreateCollision<MyCollision>(COLINDEX::BUTTON);
	SetCol(uibuttoncol2, float4(64.0f, 64.0f), float4(-136.f, -50.f));
	uibuttoncol2->AddStayEvent(this, &EditUI::Button2ColStay);

	uibuttoncol3 = CreateCollision<MyCollision>(COLINDEX::BUTTON);
	SetCol(uibuttoncol3, float4(64.0f, 64.0f), float4(-72.f, -50.f));
	uibuttoncol3->AddStayEvent(this, &EditUI::Button3ColStay);

	uibuttoncol4 = CreateCollision<MyCollision>(COLINDEX::BUTTON);
	SetCol(uibuttoncol4, float4(64.0f, 64.0f), float4(-8.f, -50.f));
	uibuttoncol4->AddStayEvent(this, &EditUI::Button4ColStay);

	uibuttoncol5 = CreateCollision<MyCollision>(COLINDEX::BUTTON);
	SetCol(uibuttoncol5, float4(64.0f, 64.0f), float4(56.f, -50.f));
	uibuttoncol5->AddStayEvent(this, &EditUI::Button5ColStay);

	uibuttoncol6 = CreateCollision<MyCollision>(COLINDEX::BUTTON);
	SetCol(uibuttoncol6, float4(64.0f, 64.0f), float4(120.f, -50.f));
	uibuttoncol6->AddStayEvent(this, &EditUI::Button6ColStay);

	uibuttoncol7 = CreateCollision<MyCollision>(COLINDEX::BUTTON);
	SetCol(uibuttoncol7, float4(64.0f, 64.0f), float4(184.f, -50.f));
	uibuttoncol7->AddStayEvent(this, &EditUI::Button7ColStay);


	//세이브 로드 버튼
	savebuttonrenderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::UIBUTTON);
	SetRender(savebuttonrenderer, L"savebutton.bmp", float4(95.f, 44.f), float4(-200.f, 100.f));

	loadbuttonrenderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::UIBUTTON);
	SetRender(loadbuttonrenderer, L"loadbutton.bmp", float4(95.f, 44.f), float4(200.f, 100.f));
	
	savebuttonrcol = CreateCollision<MyCollision>(COLINDEX::BUTTON);
	SetCol(savebuttonrcol, float4(95.f, 44.f), float4(-200.f, 100.f));
	savebuttonrcol->AddStayEvent(this, &EditUI::SaveButtonColStay);

	loadbuttonrcol = CreateCollision<MyCollision>(COLINDEX::BUTTON);
	SetCol(loadbuttonrcol, float4(95.f, 44.f), float4(200.f, 100.f));
	loadbuttonrcol->AddStayEvent(this, &EditUI::LoadButtonColStay);
	

}

void EditUI::SetRender(MyRendererBasic* renderer, Mystring image, float4 scale, float4 pivot)
{
	renderer->TransSetting(image, scale);
	renderer->CamEffectOff();
	renderer->SetPivotPos(pivot);
}

void EditUI::SetCol(MyCollision* col, float4 scale, float4 pivot)
{
	col->SetPivotPos(pivot);
	col->SetScale(scale);
}





void EditUI::MainColEnter(MyCollision* _this, MyCollision* _other)
{	
	CurScene->bCanPut = false;
}

void EditUI::MainColExit(MyCollision* _this, MyCollision* _other)
{
	CurScene->bCanPut = true;
}

void EditUI::ToggleColEnter(MyCollision* _this, MyCollision* _other)
{
	CurScene->bCanPut = false;
}

void EditUI::ToggleColExit(MyCollision* _this, MyCollision* _other)
{
	CurScene->bCanPut = true;
}

void EditUI::ToggleColStay(MyCollision* _this, MyCollision* _other)
{
	if (true == MyInput::IsDown(L"LCLICK"))
	{
		if (true == MainRenderer->IsOn())
			UIOff();
		else
			UIOn();
	}
	CurScene->bCanPut = false;
}

void EditUI::Button1ColStay(MyCollision* _this, MyCollision* _other)
{
	CurScene->bCanPut = false;
	if (true == MyInput::IsDown(L"LCLICK"))
	{
		CurScene->tilevar = TILEVAR::GRASS1;
		CurScene->bCanPut = false;
	}
}

void EditUI::Button2ColStay(MyCollision* _this, MyCollision* _other)
{
	CurScene->bCanPut = false;
	if (true == MyInput::IsDown(L"LCLICK"))
	{
		CurScene->tilevar = TILEVAR::GRASS2;
		CurScene->bCanPut = false;
	}
}

void EditUI::Button3ColStay(MyCollision* _this, MyCollision* _other)
{
	CurScene->bCanPut = false;
	if (true == MyInput::IsDown(L"LCLICK"))
	{
		CurScene->tilevar = TILEVAR::GRASS3;
		CurScene->bCanPut = false;
	}
}

void EditUI::Button4ColStay(MyCollision* _this, MyCollision* _other)
{
	CurScene->bCanPut = false;
	if (true == MyInput::IsDown(L"LCLICK"))
	{
		CurScene->tilevar = TILEVAR::GRASS4;
		CurScene->bCanPut = false;
	}
}

void EditUI::Button5ColStay(MyCollision* _this, MyCollision* _other)
{
	CurScene->bCanPut = false;
	if (true == MyInput::IsDown(L"LCLICK"))
	{
		CurScene->tilevar = TILEVAR::STONE1;
		CurScene->bCanPut = false;
	}
}

void EditUI::Button6ColStay(MyCollision* _this, MyCollision* _other)
{
	CurScene->bCanPut = false;
	if (true == MyInput::IsDown(L"LCLICK"))
	{
		CurScene->tilevar = TILEVAR::STONE2;
		CurScene->bCanPut = false;
	}
}

void EditUI::Button7ColStay(MyCollision* _this, MyCollision* _other)
{
	CurScene->bCanPut = false;
	if (true == MyInput::IsDown(L"LCLICK"))
	{
		CurScene->tilevar = TILEVAR::TREE;
		CurScene->bCanPut = false;
	}
}

void EditUI::SaveButtonColStay(MyCollision* _this, MyCollision* _other)
{
	CurScene->bCanPut = false;
	if (true == MyInput::IsDown(L"LCLICK"))
	{
		// 경로지정
		MyFile File = MyFile(L"..\\Res\\MapSaveData.Data");
		File.Open(L"wb");
		File.operator<< <long long , TILEVAR> (MyEditorScene::m_SaveTile);


		CurScene->bCanPut = false;
	}
}
//L"MapSaveData.Data"
void EditUI::LoadButtonColStay(MyCollision* _this, MyCollision* _other)
{
	CurScene->bCanPut = false;
	if (true == MyInput::IsDown(L"LCLICK"))
	{
		MyFile File = MyFile(L"..\\Res\\MapSaveData.Data");
		File.Open(L"rb");
		File >> MyEditorScene::m_SaveTile;

		MyEditorScene* EditorScene = dynamic_cast<MyEditorScene*>(GetScene());
		EditorScene->LoadTile();
		
		CurScene->bCanPut = false;
	}
}


void EditUI::UIOff()
{
	MainRenderer->Off();
	MainCol->Off();
	uibuttonrenderer1->Off();
	uibuttonrenderer2->Off();
	uibuttonrenderer3->Off();
	uibuttonrenderer4->Off();
	uibuttonrenderer5->Off();
	uibuttonrenderer6->Off();
	uibuttonrenderer7->Off();
	uibuttoncol1->Off();
	uibuttoncol2->Off();
	uibuttoncol3->Off();
	uibuttoncol4->Off();
	uibuttoncol5->Off();
	uibuttoncol6->Off();
	uibuttoncol7->Off();
	savebuttonrenderer->Off();
	loadbuttonrenderer->Off();
	savebuttonrcol->Off();
	loadbuttonrcol->Off();
}

void EditUI::UIOn()
{
	MainRenderer->On();
	MainCol->On();
	uibuttonrenderer1->On();
	uibuttonrenderer2->On();
	uibuttonrenderer3->On();
	uibuttonrenderer4->On();
	uibuttonrenderer5->On();
	uibuttonrenderer6->On();
	uibuttonrenderer7->On();
	uibuttoncol1->On();
	uibuttoncol2->On();
	uibuttoncol3->On();
	uibuttoncol4->On();
	uibuttoncol5->On();
	uibuttoncol6->On();
	uibuttoncol7->On();
	savebuttonrenderer->On();
	loadbuttonrenderer->On();
	savebuttonrcol->On();
	loadbuttonrcol->On();

}



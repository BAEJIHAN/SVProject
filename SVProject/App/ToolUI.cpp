#include "ToolUI.h"
#include<MyRendererBasic.h>
ToolUI::ToolUI()
{
}

ToolUI::~ToolUI()
{
}

void ToolUI::Start()
{
	ToolUIImage(L"tool.bmp", { 798, 96 });
}

void ToolUI::ToolUIImage(const Mystring& _Str, float4 _Scale)
{
		Renderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::UI);
		Renderer->CamEffectOff();
		Renderer->TransSetting(_Str, _Scale);
}

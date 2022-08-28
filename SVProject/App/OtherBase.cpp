#include "OtherBase.h"
#include<MyRendererBasic.h>
OtherBase::OtherBase()
{
}

OtherBase::~OtherBase()
{
}

void OtherBase::Update()
{

}

void OtherBase::OtherImage(const Mystring& _Str, float4 _Scale)
{
	Renderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::TILEOBJECT);	
	Renderer->TransSetting(_Str, _Scale);
	
}
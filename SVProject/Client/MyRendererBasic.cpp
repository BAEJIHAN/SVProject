#include "MyRendererBasic.h"
#include "MyResMgr.h"
#include <MyDebug.h>
#include <MyWindow.h>
#include"MyCamera.h"
// Static Var
// Static Func

// member Var
MyRendererBasic::MyRendererBasic() : mImage(nullptr)
{

}

MyRendererBasic::~MyRendererBasic()
{

}
// member Func
void MyRendererBasic::Render()
{
	RenderImage(mImage);
}



void MyRendererBasic::TransSetting(const Mystring& _Image, float4 _Scale, float4 _PivotPos)
{
	// ΩÃ±€≈Ê¿Ã±∏≥™!!!1
	mImage = MyResMgr::Inst().FindImage(_Image);

	if (nullptr == mImage)
	{
		MyDebug::AssertMsg("if (nullptr == m_Image)");
	}

	mRenderScale = _Scale;
	mRenderingType = RENDERINGMODE::TRANS;
}

void MyRendererBasic::BitSetting(const Mystring& _Image, float4 _Scale, float4 _PivotPos)
{
	mImage = MyResMgr::Inst().FindImage(_Image);

	if (nullptr == mImage)
	{
		MyDebug::AssertMsg("if (nullptr == m_Image)");
	}

	mRenderScale = _Scale;
	mRenderingType = RENDERINGMODE::BIT;
}

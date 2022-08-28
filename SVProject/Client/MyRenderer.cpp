#include "MyRenderer.h"
#include <MyWindow.h>
#include <MyWinImage.h>
#include"MyCamera.h"
#include"MyActor.h"
MyRenderer::MyRenderer() : mIsCamEffect(true), mRenderingType(RENDERINGMODE::MAX), mCutPos(), mCutSize(-1, -1)
{
}

MyRenderer::~MyRenderer()
{
}

float4 MyRenderer::GetRendererPos()
{
	
	return GetActor()->GetPosition() + mPivotPos;
	
}

float4 MyRenderer::CamRenderPos()
{
	if (true == mIsCamEffect)
	{
		return GetActor()->GetPosition() + mPivotPos - MyCamera::GetCamPos();
	}

	return GetActor()->GetPosition() + mPivotPos;
}

void MyRenderer::RenderImage(MyWinImage* _Image)
{
	switch (mRenderingType)
	{
	case RENDERINGMODE::BIT:
		MyWindow::GetBackBufferImage().BitBltCenter(CamRenderPos(), *_Image);
		break;
	case RENDERINGMODE::TRANS:
		MyWindow::GetBackBufferImage().TransparentBltCenter(CamRenderPos(), mRenderScale, *_Image, mCutPos, mCutSize);
		break;
	case RENDERINGMODE::ROT:
		break;
	case RENDERINGMODE::ALPHA:
		MyWindow::GetBackBufferImage().AlphaBltCenter(CamRenderPos(), mRenderScale, *_Image, mCutPos, mCutSize, mAlpha);
		break;
	case RENDERINGMODE::MAX:
	default:
		MyDebug::AssertMsg("case RENDERINGMODE::MAX:");
		break;
	}

}

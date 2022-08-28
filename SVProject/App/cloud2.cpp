#include "cloud2.h"
#include <MyRendererBasic.h>
cloud2::cloud2() :renderer(nullptr)
{
}

cloud2::~cloud2()
{
}

void cloud2::Start()
{
	renderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::OBJECT);
	renderer->TransSetting(L"cloud2.bmp", float4(800, 600));
	renderer->CamEffectOff();
}

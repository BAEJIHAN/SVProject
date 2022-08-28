#include "cloud1.h"
#include <MyRendererBasic.h>
cloud1::cloud1() :renderer(nullptr)
{
}

cloud1::~cloud1()
{
}

void cloud1::Start()
{
	renderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::OBJECT);
	renderer->TransSetting(L"cloud1.bmp", float4(800, 600));
	renderer->CamEffectOff();
}

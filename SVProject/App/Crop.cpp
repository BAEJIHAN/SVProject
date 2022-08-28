#include "Crop.h"
#include <MyRendererBasic.h>
#include <MyTimer.h>

Crop::Crop()  : MinIndex(0), MaxIndex(0), Curlevel(0), Time(0.0f)
{
	
}

Crop::~Crop()
{
}


void Crop::CropImage(const Mystring& _Str, float _Time, float4 _Scale, int _Start, int _End, float4 _Pivotpos)
{
	Renderer = CreateRenderer<MyRendererBasic>(RENDERINDEX::TILEOBJECT);
	// 식물이 다 자랐을때
	MaxIndex = _End;
	MinIndex = _Start;

	Curlevel = MinIndex;
	Renderer->TransSetting(_Str, _Scale);
	Renderer->SetPivotPos(_Pivotpos);
	Renderer->SetCutData(MinIndex);

	Time = _Time;
	CurTime = _Time;
}

void Crop::Update()
{
	if (STATE::WET!=mTile->state)
	{
		return;
	}

	if (Curlevel == MaxIndex)
	{
		return;
	}

	CurTime -= MyTimer::FDeltaTime(1.0f);
	Renderer->SetCutData(Curlevel);

	if (0 >= CurTime)
	{
		++Curlevel;
		CurTime = Time;
	}

}
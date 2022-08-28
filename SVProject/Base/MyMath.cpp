#include "MyMath.h"

const float4 float4::LEFT = { -1, 0 };
const float4 float4::RIGHT = { 1, 0 };
const float4 float4::UP = { 0 , -1 };
const float4 float4::DOWN = { 0 , 1 };
const float4 float4::ZERO = { 0 , 0 };

// 알아서 소숫점 한계치까지 짤립니다.
float MyMath::FPI = 3.141592653589793238462643383279502884197169399375105820974944f;
double MyMath::DPI = 3.141592653589793238462643383279502884197169399375105820974944;

//bool (Coliison2DCheck::* ColFunc[(int)COLTYPE::MAX][(int)COLTYPE::MAX])(const Col2DData&, const Col2DData&);
// 180
// / 180 * 3.14
// 3.14 => 180
// 3.14 => 180

// 라디안은 180 == 3.14
float MyMath::FD2R = FPI / 180;
float MyMath::FR2D = 180 / FPI;

// Static Var
// Static Func

// member Var
MyMath::MyMath()
{

}

MyMath::~MyMath()
{

}
// member Func


Coliison2DCheck::StaticInst Coliison2DCheck::Inst;

bool (/*Coliison2DCheck::*/*Coliison2DCheck::ColFunc[(int)COLTYPE::MAX][(int)COLTYPE::MAX])(const Col2DData&, const Col2DData&);


void Coliison2DCheck::Init()
{
	ColFunc[(int)COLTYPE::RECT][(int)COLTYPE::RECT] = RectToRect;
	ColFunc[(int)COLTYPE::RECT][(int)COLTYPE::CIRCLE] = RectToCirCle;
	ColFunc[(int)COLTYPE::RECT][(int)COLTYPE::POINT] = RectToPoint;

	ColFunc[(int)COLTYPE::CIRCLE][(int)COLTYPE::RECT] = CircleToRect;
	ColFunc[(int)COLTYPE::CIRCLE][(int)COLTYPE::CIRCLE] = CircleToCirCle;
	ColFunc[(int)COLTYPE::CIRCLE][(int)COLTYPE::POINT] = CircleToPoint;

	ColFunc[(int)COLTYPE::POINT][(int)COLTYPE::RECT] = PointToRect;
	ColFunc[(int)COLTYPE::POINT][(int)COLTYPE::CIRCLE] = PointToCirCle;
	ColFunc[(int)COLTYPE::POINT][(int)COLTYPE::POINT] = PointToPoint;

}


bool Coliison2DCheck::RectToRect(const Col2DData& _Left, const Col2DData& _Right)
{
	if (_Left.Right() < _Right.Left())
	{
		return false;
	}

	if (_Left.Left() > _Right.Right())
	{
		return false;
	}

	if (_Left.Up() > _Right.Down())
	{
		return false;
	}

	if (_Left.Down() < _Right.Up())
	{
		return false;
	}

	return true;
}
bool Coliison2DCheck::RectToCirCle(const Col2DData& _Left, const Col2DData& _Right) { return true; }
bool Coliison2DCheck::RectToPoint(const Col2DData& _Left, const Col2DData& _Right) { return true; }

bool Coliison2DCheck::CircleToRect(const Col2DData& _Left, const Col2DData& _Right) { return true; }
bool Coliison2DCheck::CircleToCirCle(const Col2DData& _Left, const Col2DData& _Right) { return true; }
bool Coliison2DCheck::CircleToPoint(const Col2DData& _Left, const Col2DData& _Right) { return true; }

bool Coliison2DCheck::PointToRect(const Col2DData& _Left, const Col2DData& _Right) { return true; }
bool Coliison2DCheck::PointToCirCle(const Col2DData& _Left, const Col2DData& _Right) { return true; }
bool Coliison2DCheck::PointToPoint(const Col2DData& _Left, const Col2DData& _Right) { return true; }

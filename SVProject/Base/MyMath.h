#pragma once
#include<math.h>
//분류 : 기하
//용도 : 헬퍼
//설명 : 프레임워크에 필요한 자료형 재정의

enum class ITEMTYPE
{
    TOOL,
    CROP,
    SEED
};

enum class ITEMINDEX
{
    AXE,
    HOE,
    WATERING,
    PICK,
    SICKLE,
    POTATO,
    EGGPLANT,
    RADISH,
    TOMATO,
    CABBAGE,
    BLUEBERRY,
    POTATOSEED,
    EGGPLANTSEED,
    RADISHSEED,
    TOMATOSEED,
    CABBAGESEED,
    BLUEBERRYSEED,
    TREE,
    GRASS,
    STONE,
    NONE

};



enum class RENDERINDEX
{
    BACKGROUND,
    OBJECT,
    TILEOBJECT,
    PLAYER,
    TREE,
    UI,
    UIBUTTON,
    SELECTEDUI,
    DEBUG,
    MOUSE
};


enum class COLINDEX
{
    PLAYER,
    OBJECT,
    ITEM,
    MOUSE,
    BUTTON
};
class MyMath
{
private: //static variable
public:
    static float FPI;
    static double DPI;

    static float FD2R;
    static float FR2D;
private: //member var

public:	//constructor destructor
    MyMath();
    ~MyMath();


public: // delete constructer 
    MyMath(const MyMath& _Other) = delete;
    MyMath(const MyMath&& _Other) = delete;

public: // delete operator
    MyMath& operator=(const MyMath& _Other) = delete;
    MyMath& operator=(const MyMath&& _Other) = delete;

public: // member func
};

class float4
{
    // 4차원을 나타낼수 있는수를 만들건데
    // 선생님이 이번 API2D에서 이중 뭐와 뭐만 쓸가요?
    // x y
public:
    static const float4 LEFT;
    static const float4 RIGHT;
    static const float4 UP;
    static const float4 DOWN;
    static const float4 ZERO;

    static float4 AngleToDir2DDeg(float _Deg)
    {
        return AngleToDir2DRad(_Deg * MyMath::FD2R);
    }

    static float4 AngleToDir2DRad(float _Rad)
    {
        // 빗변
        // 밑변
        // 높이

        // sinf => 높이 / 빗변
        // cosf => 밑변 / 빗변
        // tan => 높이 / 밑변

        float4 Return;

        // 빗변의 길이가 1짜리인 직각 삼각형의?

        Return.x = cosf(_Rad); // 밑변 x
        Return.y = sinf(_Rad); // 높이 y

        return Return;
    }

    static float Len3D(const float4& _Value)
    {
        return sqrtf((_Value.x * _Value.x) + (_Value.y * _Value.y) + (_Value.z * _Value.z));
    }

    static float Len2D(const float4& _Value)
    {
        return sqrtf((_Value.x * _Value.x) + (_Value.y * _Value.y));
    }

    static float4 Normalize2D(const float4& _Value)
    {
        float4 ReturnValue = _Value;
        float Len = Len2D(_Value);

        ReturnValue.x = _Value.x / Len;
        ReturnValue.y = _Value.y / Len;
        ReturnValue.z = 0.0f;
        return ReturnValue;
    }

    void Int64ToPos(__int64 _Key)
    {
        __int64 TilePos = _Key;
        int* Ptr = reinterpret_cast<int*>(&TilePos);
        x = static_cast<float>(Ptr[0]);
        y = static_cast<float>(Ptr[1]);
        return;
    }


    __int64 ToInt64() 
    {
        __int64 TilePos;
        int* Ptr = reinterpret_cast<int*>(&TilePos);
        Ptr[0] = ix();
        Ptr[1] = iy();

        return TilePos;
    }

public:
    union
    {
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };

        struct
        {
            float r;
            float g;
            float b;
            float a;
        };
    };


public:
    float4() : x(0.0f), y(0.0f), z(0.0f), w(1.0f)
    {
    }

    float4(
        float _value
    ) : x(_value), y(_value), z(_value), w(_value)
    {
    }

    float4(
        float _x,
        float _y
    ) : x(_x), y(_y), z(0.0f), w(1.0f)
    {
    }

    float4(
        float _x,
        float _y,
        float _z
    ) : x(_x), y(_y), z(_z), w(1.0f)
    {
    }

    float4(
        float _x,
        float _y,
        float _z,
        float _w
    ) : x(_x), y(_y), z(_z), w(_w)
    {
    }


    float4(
        int _value
    ) : x(static_cast<float>(_value)), y(static_cast<float>(_value)), z(static_cast<float>(_value)), w(static_cast<float>(_value))
    {
    }

    float4(
        int _x,
        int _y
    ) : x(static_cast<float>(_x)), y(static_cast<float>(_y)), z(0.0f), w(1.0f)
    {
    }

    float4(
        int _x,
        int _y,
        int _z
    ) : x(static_cast<float>(_x)), y(static_cast<float>(_y)), z(static_cast<float>(_z)), w(1.0f)
    {
    }

    float4(
        int _x,
        int _y,
        int _z,
        int _w
    ) : x(static_cast<float>(_x)), y(static_cast<float>(_y)), z(static_cast<float>(_z)), w(static_cast<float>(_w))
    {
    }

public:
   
    void CheckMinfloat()
    {
        // 함수일 겁니다.
        // 0에 가까운 값이라면
        //if (x == )
        //{
        //    x = 0.0f;
        //}
    }

    bool IsZero2D() const
    {
        return x == 0 || y == 0;
    }

    bool IsZero() const
    {
        return x == 0 || y == 0 || z == 0;
    }

    int ix() const
    {
        return static_cast<int>(x);
    }
    int iy()const
    {
        return static_cast<int>(y);
    }
    int iz()const
    {
        return static_cast<int>(z);
    }
    int iw()const
    {
        return static_cast<int>(w);
    }

    int ihx()const
    {
        return static_cast<int>(x * 0.5f);
    }
    int ihy()const
    {
        return static_cast<int>(y * 0.5f);
    }
    int ihz()const
    {
        return static_cast<int>(z * 0.5f);
    }
    int ihw()const
    {
        return static_cast<int>(w * 0.5f);
    }

    float hx()const
    {
        return x * 0.5f;
    }
    float hy()const
    {
        return y * 0.5f;
    }
    float hz()const
    {
        return z * 0.5f;
    }
    float hw()const
    {
        return w * 0.5f;
    }

    float4 hfloat4()const
    {
        return { hx(), hy() };
    }

    float4 operator*(const float& _Value) const
    {
        float4 ReturnVector;
        ReturnVector.x = x * _Value;
        ReturnVector.y = y * _Value;
        ReturnVector.z = z * _Value;
        ReturnVector.w = w * _Value;
        return ReturnVector;
    }

    float4 operator-(const float4& _Other) const
    {
        float4 ReturnVector;
        ReturnVector.x = x - _Other.x;
        ReturnVector.y = y - _Other.y;
        ReturnVector.z = z - _Other.z;
        ReturnVector.w = w - _Other.w;
        return ReturnVector;
    }


    float4 operator+(const float4& _Other) const
    {
        float4 ReturnVector;
        ReturnVector.x = x + _Other.x;
        ReturnVector.y = y + _Other.y;
        ReturnVector.z = z + _Other.z;
        ReturnVector.w = w + _Other.w;
        return ReturnVector;
    }

    float4& operator+=(const float4& _Other)
    {
        x += _Other.x;
        y += _Other.y;
        z += _Other.z;
        w += _Other.w;
        return *this;
    }

    // 사인 코사인 탄젠트란
    // 어떤 각도의 직각삼각형이 있을때
    // 이녀석의 밑변 빗변 높이 가 각자 크기가 얼마가 되건
    // 그 비율은 일정하다는 개념에 가깝다.


    float GetLen()
    {
        return Len2D(*this);
    }


    float4 GetNormalize2D() const
    {
        return Normalize2D(*this);
    }

    // 어떤 방향의 벡터건 결국에는 선일 뿐이다.
    // 그 선의 길이를 알면
    void Normalize()
    {
        *this = Normalize2D(*this);
    }

    /*void 단위백터를 만든다()
    *  길이가 1인 벡터로 만드는지 이해해야 합니다.
    *  벡터를 정규화 한다고 부릅니다.
    {
        x /= Len();
        y /= Len();
        return x;
    }*/
};

typedef float4 Vector;
typedef float4 Position;
typedef float4 Scale;
typedef float4 FRect;
typedef float4 Color;
typedef float4 Color;

/// <summary>
/// ////////////////////////////////////////////////////// 2DCollison
/// </summary>

enum class COLTYPE
{
    RECT,
    CIRCLE, // 타원 충돌 많이 어려버요 ㅠㅠ 타원아닙니다.
    POINT,
    MAX,
};

// 이녀석이면 원
// 렉트 포인트 다 표현할수 있죠?
class Col2DData
{
public: // 
    float4 Pos;
    float4 Size;

public:
    float Left() const
    {
        return Pos.x - Size.hx();
    }
    float Right()const {
        return Pos.x + Size.hx();
    }
    float Up()const {
        return Pos.y - Size.hy();
    }
    float Down()const
    {
        return Pos.y + Size.hy();
    }

    int iLeft() const
    {
        return static_cast<int>(Left());
    }
    int iRight()const {
        return static_cast<int>(Right());
    }
    int iUp()const {
        return static_cast<int>(Up());
    }
    int iDown()const
    {
        return static_cast<int>(Down());
    }

    // 픽셀충돌에도 응용할수 있다.
    float4 LeftPoint() const
    {
        return { Pos.y, Left() };
    }
    float4 RightPoint()const {
        return { Pos.y, Right() };
    }
    float4 UpPoint()const {
        return { Pos.x, Up() };
    }
    float4 DownPoint()const
    {
        return { Pos.x, Down() };
    }

};

class Coliison2DCheck
{
public:
    static bool (*ColFunc[(int)COLTYPE::MAX][(int)COLTYPE::MAX])(const Col2DData&, const Col2DData&);


private:
    class StaticInst
    {
        friend Coliison2DCheck;
    private:
        StaticInst()
        {
            // 안 귀찮아.
            // 이 방식에 단점이 있어요
            // 순서를 내가 정할수 없어.
            // 몬스터 데이터 매니저.
            // 몬스터 만들어주는 매니저
            // 순서와 상관없이 그냥 무조건 실행되면 될때만
            // 이 방법을 사용하세요
            Coliison2DCheck::Init();
        }
        ~StaticInst() {

        }
    };
    // 클레스 static 변수가 만들어지면서
    friend StaticInst;
    static StaticInst Inst;

private:
    static void Init();

public:
    static bool RectToRect(const Col2DData& _Left, const Col2DData& _Right);
    static bool RectToCirCle(const Col2DData& _Left, const Col2DData& _Right);
    static bool RectToPoint(const Col2DData& _Left, const Col2DData& _Right);

    static bool CircleToRect(const Col2DData& _Left, const Col2DData& _Right);
    static bool CircleToCirCle(const Col2DData& _Left, const Col2DData& _Right);
    static bool CircleToPoint(const Col2DData& _Left, const Col2DData& _Right);

    static bool PointToRect(const Col2DData& _Left, const Col2DData& _Right);
    static bool PointToCirCle(const Col2DData& _Left, const Col2DData& _Right);
    static bool PointToPoint(const Col2DData& _Left, const Col2DData& _Right);

private:
    virtual ~Coliison2DCheck();
};

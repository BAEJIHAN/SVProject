#pragma once
#include<math.h>
//�з� : ����
//�뵵 : ����
//���� : �����ӿ�ũ�� �ʿ��� �ڷ��� ������

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
    // 4������ ��Ÿ���� �ִ¼��� ����ǵ�
    // �������� �̹� API2D���� ���� ���� ���� ������?
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
        // ����
        // �غ�
        // ����

        // sinf => ���� / ����
        // cosf => �غ� / ����
        // tan => ���� / �غ�

        float4 Return;

        // ������ ���̰� 1¥���� ���� �ﰢ����?

        Return.x = cosf(_Rad); // �غ� x
        Return.y = sinf(_Rad); // ���� y

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
        // �Լ��� �̴ϴ�.
        // 0�� ����� ���̶��
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

    // ���� �ڻ��� ź��Ʈ��
    // � ������ �����ﰢ���� ������
    // �̳༮�� �غ� ���� ���� �� ���� ũ�Ⱑ �󸶰� �ǰ�
    // �� ������ �����ϴٴ� ���信 ������.


    float GetLen()
    {
        return Len2D(*this);
    }


    float4 GetNormalize2D() const
    {
        return Normalize2D(*this);
    }

    // � ������ ���Ͱ� �ᱹ���� ���� ���̴�.
    // �� ���� ���̸� �˸�
    void Normalize()
    {
        *this = Normalize2D(*this);
    }

    /*void �������͸� �����()
    *  ���̰� 1�� ���ͷ� ������� �����ؾ� �մϴ�.
    *  ���͸� ����ȭ �Ѵٰ� �θ��ϴ�.
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
    CIRCLE, // Ÿ�� �浹 ���� ������� �Ф� Ÿ���ƴմϴ�.
    POINT,
    MAX,
};

// �̳༮�̸� ��
// ��Ʈ ����Ʈ �� ǥ���Ҽ� ����?
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

    // �ȼ��浹���� �����Ҽ� �ִ�.
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
            // �� ������.
            // �� ��Ŀ� ������ �־��
            // ������ ���� ���Ҽ� ����.
            // ���� ������ �Ŵ���.
            // ���� ������ִ� �Ŵ���
            // ������ ������� �׳� ������ ����Ǹ� �ɶ���
            // �� ����� ����ϼ���
            Coliison2DCheck::Init();
        }
        ~StaticInst() {

        }
    };
    // Ŭ���� static ������ ��������鼭
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

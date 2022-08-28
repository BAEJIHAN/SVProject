#pragma once
#include "MyRenderer.h"
#include <MyWinImage.h>
#include <MyDebug.h>
enum class STATE
{    
    DIGGED,
    WET,
    NONE,  
};

enum class KIND
{
    STONE,
    GRASS,
    CROP,
    TREE,
    ITEM,
    NONE
};
// 분류 : 렌더링
// 용도 : 리소스
// 설명 : 타일을 렌더링한다.
class MyActor;
class MyRendererTile : public MyRenderer
{
public:
    class Tile
    {
    public:
        MyRendererTile* mParentTile;
        int mImageIndex;
        STATE state;
        bool IsOccupied;
        MyActor* MyActor;
        KIND kind;
        // 비어있는 타일이라는 표시다.

    public:
        Tile() : mParentTile(nullptr), mImageIndex(-1), state(STATE::NONE), IsOccupied(false), kind(KIND::NONE), MyActor(nullptr)
        {

        }

        void SetState(STATE _state)
        {
            state = _state;
        }

        STATE GetState()
        {
            return state;
        }

        KIND GetKind()
        {
            return kind;
        }

        void SetTile(STATE _state)
        {
            state = _state;
            if (STATE::DIGGED == state)
            {
                mImageIndex = (int)STATE::DIGGED;
            }
            if (STATE::WET == state)
            {
                mImageIndex = (int)STATE::WET;
            }
            if (STATE::NONE == state)
            {
                kind = KIND::NONE;
                mImageIndex = (int)STATE::NONE;
            }
           
        }

    };

private: // Static Var
public: // Static Func
private: // member Var
    MyWinImage* mImage;
    std::vector<std::vector<Tile>> mTileMap;

    float4 TileSize;
    float4 ImageScale;

    float4 PivotPos;

    MyActor* mCullActor;

public:
    void SetCullActor(MyActor* _CullActor)
    {
        mCullActor = _CullActor;
    }

public:
    void TileMapStart(const Mystring& _TileMapImage, float4 _TileSize, float4 _ImageScale, int _SizeX, int _SizeY);

 

    Tile* GetTile(float4 _CheckPos);

public: // constructer destructer
    MyRendererTile();
    ~MyRendererTile();

public: // delete constructer 
    MyRendererTile(const MyRendererTile& _Other) = delete;
    MyRendererTile(const MyRendererTile&& _Other) = delete;

public: // delete operator
    MyRendererTile& operator=(const MyRendererTile& _Other) = delete;
    MyRendererTile& operator=(const MyRendererTile&& _Other) = delete;

public: // member Func
    void Render() override;
};


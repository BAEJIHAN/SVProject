#pragma once
#include "MyPath.h"
#include "MyDebug.h"
#include <map>
#include <list>
#include <vector>

//분류 : 문자열
//용도 : 헬퍼
//설명 : 파일의 정보와 기능을 담당하는 클래스

class MyFile : public MyPath
{
private: //static variable
public:	//static func
private: //member var
    FILE* mHandle;
    int CurMemoryPosition;
    size_t mFileSize;
    Mystring Mode;
public:	//constructor destructor
    bool isReadOpen()
    {
        return Mode.is_find(L"r");
    }
    bool isWriteOpen()
    {
        return Mode.is_find(L"w");
    }

    size_t FileSize();

public:

    MyFile();
    MyFile(const Mystring& _path);
    ~MyFile();


public: // delete constructer 
    MyFile(const MyFile& _Other) : MyPath(_Other), mHandle(nullptr), CurMemoryPosition(0), mFileSize(0)
    {}
    MyFile(const MyFile&& _Other) noexcept : MyPath(_Other), mHandle(nullptr), CurMemoryPosition(0), mFileSize(0)
    {}
public: // delete operator
    MyFile& operator=(const MyFile& _Other) = delete;
    MyFile& operator=(const MyFile&& _Other) = delete;

public: // member func
    void Open(const wchar_t* _mode);
    void Close();

public:
    template<typename T>
    void operator<<(T& _Value)
    {
        Write((void*)&_Value, sizeof(_Value), 1);

    }

    template<>
    void operator<<(Mystring& _Value)
    {
        const Mystring& ConstStr = _Value;
        operator<<(ConstStr);

    }

    template<>
    void operator << (const Mystring& _Value)
    {        
        std::string Convert = _Value.GetConvertMultiByte();

        int Size = (int)Convert.size();

        Write(&Size, sizeof(int), 1);
        
        Write((void*)Convert.c_str(), Size, 1);
    }

    template<typename KEY, typename VALUE>
    void operator<<(std::map<KEY, VALUE>& _Value)
    {
        int Size = (int)_Value.size();
        this->operator<<(Size);

        typename std::map<KEY, VALUE>::iterator Start = _Value.begin();
        typename std::map<KEY, VALUE>::iterator End = _Value.end();

        for (; Start != End; ++Start)
        {
            const KEY& Key = Start->first;
            VALUE& Value = Start->second;

            operator<<(Key);
            operator<<(Value);
        }
    }

    template<typename T>
    void WriteType(T& _Value, size_t _Count = 1)
    {
        Write(&_Value, sizeof(_Value), _Count);

    }
      
    void Write(void* _Ptr, size_t _Size, size_t _Count = 1);

public:
    template<typename T>
    void operator>>(T& _Value)
    {
        Read(&_Value, sizeof(_Value), sizeof(_Value), 1);
    }

    template<>
    void operator>>(Mystring& _Value)
    {
        int Size = 0;
        Read(&Size, sizeof(int), sizeof(int), 1);

        if (0 >= Size)
        {
            MyDebug::AssertMsg(L"Read(&Size, sizeof(int), sizeof(int), 1);");
        }

        std::string ReadBuffer;

        ReadBuffer.resize(Size);

        Read(&ReadBuffer[0], Size, Size, 1);

        _Value.SetConvertWideByte(ReadBuffer);
    }

    template<typename KEY, typename VALUE>
    void operator>>(std::map<KEY, VALUE>& _Value)
    {
        int Size;
        this->operator>>(Size);

        KEY ReadKey = KEY();
        VALUE ReadValue = VALUE();
        for (int i = 0; i < Size; i++)
        {
            operator >> <KEY>(ReadKey);
            operator>><VALUE>(ReadValue);

            _Value.insert(std::map<KEY, VALUE>::value_type(ReadKey, ReadValue));
        }

    }

    template<typename T>
    void ReadType(T& _Value, size_t _Count = 1)
    {
        Read(&_Value, sizeof(_Value), sizeof(_Value), _Count);
    }

    void Read(void* _Ptr, size_t _BufferSize, size_t _ReadSize, size_t _Count = 1);

};




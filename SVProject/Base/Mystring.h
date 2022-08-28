#pragma once
#include <string>
#include <vector>


// �з� : ���ڿ�
// �뵵 : ����
// ���� : �����ӿ�ũ���� ���ڿ��� �ٷ�� Ŭ����
//        
class Mystring
{
private: // Static Var
public: // Static Func
public: // member Var
    std::wstring mStr;

public: // constructer destructer
    Mystring();
    Mystring(const wchar_t* _pString);
    Mystring(const std::wstring& _String);
    ~Mystring();

public:
    template<typename Type>
    static Mystring ToString(Type& _Data)
    {
        Mystring String;
        String += Mystring(std::to_wstring(_Data));
        return String;
    }

    static Mystring ToString(const int& _Data)
    {
        Mystring String;
        String += Mystring(std::to_wstring(_Data));
        return String;
    }

public: // delete constructer 
    Mystring(const Mystring& _Other) : mStr(_Other.mStr)
    {

    }
    Mystring(const Mystring&& _Other) noexcept : mStr(_Other.mStr)
    {

    }
	



public: // delete operator
    Mystring& operator=(const Mystring& _Other)
    {
        mStr = _Other.mStr;
        return *this;
    }
    Mystring& operator=(const Mystring&& _Other) noexcept
    {
        mStr = _Other.mStr;
        return *this;
    }

    Mystring& operator=(int _Value)
    {
        mStr = std::to_wstring(_Value);
        return *this;
    }

    // �ڱ� �ڽ��� �����ȵǴ� �Ŵϱ�
    Mystring operator+(const Mystring& _Other) const
    {
        std::wstring Str = mStr;
        Str += _Other.mStr;
        return Str;
    }


   Mystring& operator+=(const Mystring& _Other)
    {
        mStr += _Other.mStr;
        return *this;
    }


    bool operator==(const Mystring& _Other) const
    {
        return mStr == _Other.mStr;
    }

  

    bool operator!=(const Mystring& _Other) const
    {
        return mStr != _Other.mStr;
    }

    bool operator>(const Mystring& _Other) const
    {
        return mStr > _Other.mStr;
    }

    bool operator<(const Mystring& _Other) const
    {
        return mStr < _Other.mStr;
    }


    wchar_t& operator[](size_t _Index)
    {
        return mStr[_Index];
    }

    size_t size() const {
        return mStr.size();
    }

    void resize(size_t _Size) {
        return mStr.resize(_Size);
    }

    void reserve(size_t _Size) {
        return mStr.reserve(_Size);
    }

    const wchar_t* c_str() const
    {
        return mStr.c_str();
    }

    std::vector<Mystring> StringCutVector(const wchar_t* _Pivot);
    std::vector<Mystring> StringCenterCutVector(const wchar_t* _Start, const wchar_t* _End);

    bool EraseFirst(const Mystring& _Str);
    bool EraseLast(const Mystring& _Str);
    void EraseAll(const Mystring& _Str);

public: // member Func
    // const�� ��ü�� �ڽ��� �ɹ��Լ� �߿��� const �Լ��ۿ� �����
    std::string GetConvertMultiByte(int _encoding = 0) const;
    void SetConvertWideByte(const std::string& _Str);

    bool is_find(const wchar_t* _Text, size_t _StartIndex = 0);

    size_t find_first_index(const wchar_t* _Text, size_t _StartIndex = 0) const;
    size_t find_last_index(const wchar_t* _Text, size_t _StartIndex = -1) const;
    Mystring Cut(size_t _StartIndex, size_t _Count) const;
    Mystring CutIndex(size_t _StartIndex, size_t _EndIndex) const;
};


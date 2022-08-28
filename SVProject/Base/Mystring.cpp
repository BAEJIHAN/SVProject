#include "Mystring.h"
#include <atlstr.h>
Mystring::Mystring()
{
}

Mystring::Mystring(const wchar_t* _pstring) : mStr(_pstring)
{
}

Mystring::Mystring(const std::wstring& _string) : mStr(_string)
{
}


Mystring::~Mystring()
{
}

std::string Mystring::GetConvertMultiByte(int _encoding /*= CP_ACP*/) const
{
	std::string str = CW2A(mStr.c_str(), _encoding).m_psz;
	return str;
}

void Mystring::SetConvertWideByte(const std::string& _str)
{
	mStr = CA2W(_str.c_str()).m_psz;
}

bool Mystring::is_find(const wchar_t* _text, size_t _startindex)
{
	return std::wstring::npos != mStr.find(_text, _startindex);
}



size_t Mystring::find_first_index(const wchar_t* _Text, size_t _StartIndex /*= 0*/) const
{
	return mStr.find(_Text, _StartIndex);
}

size_t Mystring::find_last_index(const wchar_t* _Text, size_t _EndIndex /*= 0*/) const
{
	return mStr.rfind(_Text, _EndIndex);
}



Mystring Mystring::Cut(size_t _StartIndex, size_t _Count) const {
	return mStr.substr(_StartIndex, _Count);
}

Mystring Mystring::CutIndex(size_t _StartIndex, size_t _EndIndex) const
{
	return mStr.substr(_StartIndex, _EndIndex - _StartIndex);
}

std::vector<Mystring> Mystring::StringCutVector(const wchar_t* pivot)
{
	std::vector<Mystring> Return;

	Mystring pivotstr = pivot;

	size_t Start = 0;
	size_t End = find_first_index(pivot, Start);

	if (End == std::string::npos)
	{
		return Return;
	}

	while (true)
	{
		Mystring text = CutIndex(Start, End);
		Return.push_back(text);

		if (End == std::string::npos)
		{
			break;
		}
		Start = End + pivotstr.size();
		End = find_first_index(pivot, Start);
	}
	return Return;

}

std::vector<Mystring> Mystring::StringCenterCutVector(const wchar_t* _Start, const wchar_t* _End)
{
	std::vector<Mystring> Return;
	Mystring StartStr = _Start;
	Mystring EndStr = _End;

	size_t Start = find_first_index(StartStr.c_str(), 0);
	size_t End = find_first_index(EndStr.c_str(), Start + StartStr.size());

	if (Start == std::string::npos)
	{
		// 맨 마지막까지
		return Return;
	}

	// 글자든 문자열 존재한다면 그 위치의 첫번째 위치가 나오죠?
	// 존재하지 않으면 -1 == unsigned 일때 -1은?
	// 못찾았을때 나오는값 -1
	//  std::string::npos

	while (true)
	{
		
		Mystring Text = CutIndex(Start + StartStr.size(), End);

		Return.push_back(Text);

		Start = find_first_index(StartStr.c_str(), End + EndStr.size());
		End = find_first_index(EndStr.c_str(), Start);

		if (Start == std::string::npos)
		{
			// 맨 마지막까지
			break;
		}
	}

	return Return;
}

bool Mystring::EraseFirst(const Mystring& _Str)
{
	size_t Index = find_first_index(_Str.c_str());

	if (Index == std::wstring::npos)
	{
		return false;
	}

	mStr.erase(Index, _Str.size());

	return true;
}

bool Mystring::EraseLast(const Mystring& _Str)
{
	size_t Index = find_last_index(_Str.c_str());

	if (Index == std::wstring::npos)
	{
		return false;
	}

	mStr.erase(Index, _Str.size());

	return true;
}

void Mystring::EraseAll(const Mystring& _Str)
{
	// 그럼 다 지우겠죠.
	while (EraseFirst(_Str));


}
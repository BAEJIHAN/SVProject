#include "MyPath.h"

bool MyPath::isExist(const Mystring& _path)
{
    return 0 == _waccess(_path.c_str(), 00);
}

MyPath::MyPath()
{
}

MyPath::MyPath(const Mystring& _path):Mystring(_path)
{
}

MyPath::~MyPath()
{
}



bool MyPath::isExist()
{
    return isExist(mStr.c_str());
}

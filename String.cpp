//传统写法
#include<iostream>
#include<assert.h>
using namespace std;
class String{
public:
	String(const char* str = "")
	{
		if (str == nullptr)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& str)
		:_str(new char[strlen(str._str) + 1])
	{
		strcpy(_str, str._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pstr = new char[strlen(s) + 1];
			strcpy(pstr, s._str);
			delete[] _str;
			_str = pstr;
		}
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};

//现代版写法
class String
{
public:
	String(const char* str = "")
	{
		if (str == nullptr)
		{
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& str)
		:_str(nullptr)
	{
		String tmp(str);
		swap(_str, tmp._str);
	}
	String& operator=(const String& str)
	{
		if (this != &str)
		{
			String tmp(str);
			swap(_str, tmp._str);
		}
		return*this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
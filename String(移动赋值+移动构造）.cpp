//String类+移动赋值+移动构造
#include<iostream>
#include<assert.h>
using namespace std;
class String{
public:
	//构造函数
	String(const char* str = " ")   
	{
		if (str == nullptr)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	//拷贝构造
	String(const String& str)
		:_str(new char[strlen(str._str)+1])
	{
		cout << "String(const String& str)" << endl;
		strcpy(_str, str._str);
	}
	//移动构造
	/*String(String&& str)
		:_str(nullptr)
	{
		cout << "String(String&& str)" << endl;
		swap(_str, str._str);
	}*/
	//赋值运算符重载
	String& operator=(const String& str)
	{
		if (this != &str)
		{
			char* tmp = new char[strlen(str._str) + 1];
			strcpy(tmp, str._str);
			if (_str)
				delete[] _str;
			_str = tmp;
		}
		return *this;
	}
	//移动赋值
	/*String& operator=(String&& str)
	{
		cout << "String& operator=(String&& str)" << endl;
		swap(_str, str._str);
		return* this;
	}*/
	//s1+=s2
	String& operator+=(const String& str)
	{
		//this->append(str.c_str());
		return* this;
	}
	//s1+s2 需要构造新对象
	String operator+(const String& str)
	{
		String tmp(*this);
		//tmp->append(str.c_str());
		return tmp;
	}

	~String()
	{
		if (_str)
			delete[] _str;
	}
private:
	char* _str;
};
int main()
{
	String s1("hello");
	String s2("hello");
	String ret;
	ret = s1 + s2;

	/*String ret = s1 + s2;*/
}
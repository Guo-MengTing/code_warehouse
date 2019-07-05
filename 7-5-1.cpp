//const修饰指针
#include<iostream>
using namespace std;
int main()
{
	int i = 2;
	int j = 3;
	int* const p1=&i;  //const修饰p
	//p1 = &j;      //p指向的地址不可以改变
	*p1 = 3;         //p指向地址的值可以改变
	cout << i << endl;

	const int* p2 = &j;   //const修饰*p2
	p2 = &i;          //p2指向的地址可以改变
	//*p2 = 4;           //p2指向地址的值不可以改变
	cout << p2 << endl;

	const int* const p3 = &i;   //const既修饰p3又修饰*p3
	//*p3 = 1;             //p3指向地址的值不可以改变
	//p3 = &j;             //p3指向的地址也不可以改变
}

//日期类
#include<iostream>
using namespace std;
class Date{
public:
	Date(){}
	Date(int year, int month, int day)
		:_year(year),
		_month(month),
		_day(day)
	{}
	//拷贝构造(拷贝构造函数的重载）
	 Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//赋值运算符重载
	Date& operator=(const Date& d)
	{
		if (this != &d)  //检测是否自己给自己赋值
		{
			this->_month = d._month;
			this->_year = d._year;
			this->_day = d._day;
		}
		return *this;
	}
	//取地址操作符重载
	Date* operator&()
	{
		return this;
	}
	~Date()
	{}
private:
	int _year = 2019;
	int _month = 7;
	int _day = 5;
};
int main()
{
	Date d1(1998, 8, 22);
	Date d2(1969, 6, 5);
	Date d3(d1);
	d3 = d2;
	return 0;
}
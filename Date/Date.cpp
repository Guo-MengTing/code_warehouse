#include"Date.h"
int Date::GetMonthDay(int year, int month)
{
	static int monthArray[13] = {  0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		return 29;
	}
	return monthArray[month];
}
Date::Date(int year, int month, int day)
{
	if (year >= 0 && month > 0 && month<13 && day>0 && day < GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "Date Invalid" << endl;
	}
}
void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}
Date Date::operator+(int day)
{
	Date ret(*this);
	ret._day += day;
	if (ret._day > GetMonthDay(ret._year, ret._month))
	{
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			ret._day -= GetMonthDay(ret._year, ret._month);
			if (_month == 12)
			{
				++ret._year;
				ret._month = 1;
			}
			else
			{
				++ret._month;
			}
		}
	}
	return ret;
	
}
Date& Date::operator+=(int day)
{
	*this = *this + day;
	return *this;
}
Date Date::operator-(int day)
{
	Date ret(*this);
	ret._day -= day;
    while (ret._day <=0)
	{
		if (ret._month == 1)
		{
				--ret._year;
				ret._month = 12;
		}
		else
		{
				--ret._month;
		}
			ret._day += GetMonthDay(ret._year, ret._month);
	}
	return ret;
}
Date& Date::operator-=(int day)
{
	*this = *this - day;
	return *this;
}
Date Date::operator++()//ÏÈ×ÔÔö
{
	(*this)++;
	return *this;
}
Date Date::operator++(int day)
{
	Date ret(*this);
	*this+=1;
	return ret;
}
int Date::operator-(const Date& d)
{
	int flag = 1;
	Date max = *this;
	Date min = d;
	if (*this<d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int count = 0;
	while (min!=max)
	{
		++min;
		++count;
	}
	return count*flag;
}
bool Date::operator>(const Date& d)
{
	return (_year > d._year || (_year == d._year&&_month > d._month) || (_year == d._year&&_month == d._month&&_day > d._day));
}

bool Date::operator>=(const Date& d)
{
	return (*this > d || *this == d);
}

bool Date::operator<(const Date& d)
{
	return !(*this>d&&*this==d);
}

bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

bool Date::operator==(const Date& d)
{
	return (_year == d._year&&_month == d._month&&_day == d._day);
}
bool Date::operator!=(const Date& d)
{
	return !(*this==d);
}

int main()
{
	Date d1(1990, 9, 26);
	Date d2 = d1 + 15;
	d2.Print();
	Date d3 = d2 - 50;
	d3.Print();
	(d3++).Print();
	Date d4(1990, 5, 22);
	cout << (d4 - d1) << endl;
	/*d1.Print();
	Date d2(1998, 8, 22);
	cout <<(d1==d2)<< endl*/;
	/*cout << +(15) << endl;*/
}
#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);
	void Print();
	int GetMonthDay(int year, int month);

	Date operator+(int day);
	Date& operator+=(int day);

	Date operator-(int day);
	Date& operator-=(int day);

	int operator-(const Date& d);

	// ++d -> d.operator++(&d)
	Date operator++();
	// d++ -> d.operator++(&d, 1)
	Date operator++(int);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};
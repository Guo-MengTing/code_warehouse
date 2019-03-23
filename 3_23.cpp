//https://www.nowcoder.com/questionTerminal/1221ec77125d4370833fd3ad5ba72395
#include<iostream>
using namespace std;
static int getTotalCount(int month)
{
	int a = 1;
	int b = 0;
	int c = 0;
	while (--month)
	{
		c += b;
		b = a;
		a = c;
	}
	int count = a + b + c;
	return count;
}
int main()
{
	int month;
	while (cin >> month)
	{
		if (month < 3)
		{
			cout << "-1" << endl;
		}
		else
		{
			cout << getTotalCount(month) << endl;
		}
	}
	return 0;
}
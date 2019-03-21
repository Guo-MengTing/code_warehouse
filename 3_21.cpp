//1.求两个数最大公约数
#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	int r;
	while (r = a%b)
	{
		a = b;
		b = r;
	}
	return b;
}
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << a*b / gcd(a, b) << endl;
	}
	return 0;
}


//2.井字棋
#include<iostream>
using namespace std;
#include<vector>
class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		int sum = 0;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				sum += board[i][j];
			}
		}
		if (sum>0)
			return true;
		else
			return false;

	}
};

//3.判断整数的二进位连续1的个数
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a;
	while (cin >> a)
	{
		int count = 0;
		int maxcount = 0;
		while (a)
		{
			if (a & 1)
			{
				++count;
				maxcount = max(count, maxcount);
			}
			else
			{
				count = 0;
			}
			a = a >> 1;
		}
		cout << maxcount << endl;
	}
	return 0;
}


//4.日期转换
#include<iostream>
using namespace std;
int iConverDateToDay(int year, int month, int day)
{
	int outday = 0;
	if ((month<0 || month>12) || (day > 31))
		return -1;
	int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 1; i < month; ++i)
	{
		if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		{
			arr[2] = 29;
		}
		outday += arr[i];
	}
	return outday;
}
int main()
{
	int year;
	int month;
	int day;
	cin >> year;
	cin >> month;
	cin >> day;
	cout << iConverDateToDay(year, month, day) << endl;
	return 0;
}
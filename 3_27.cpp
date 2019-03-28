翻转字符串
#include<iostream>
#include<string>
using namespace std;
string getReverse(string& s)
{
	size_t start = 0;
	size_t end = s.size() - 1;
	while (start < end)
	{
		swap(s[start], s[end]);
		++start;
		--end;
	}
	return s;
}
int main()
{
	string s;
	getline(cin, s);
	if (s.empty())
		cout << "error" << endl;
	else
	    cout << getReverse(s) << endl;
	return 0;
}

//求组成偶数的素数差值最小的素数对
#include<iostream>
#include<stdlib.h>
using namespace std;
bool sushu(int n)
{
	for (int i = 2; i < n; ++i)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}
int main()
{
	int n;
	int i;
	while (cin >> n)
	{
		if (n % 2 != 0)
			cout << "error" << endl;
		else
		{
			for (i = n / 2; i > 0; --i)
			{
				if (sushu(i) && sushu(n - i))
					break;
			}
			cout << i << endl;
			cout << n - i << endl;
		}
	}
	
	return 0;
}
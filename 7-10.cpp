//https://www.nowcoder.com/questionTerminal/1046cd038f7a4b04b2b77b415973de1c
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int main()
{
	string s;
	string t;
	while (cin >> s >> t)
	{
		int count = 0;
		int start = 0;
		while (s.length() >= (start + t.length()))
		{
			if (s.substr(start, t.length()) == t)
			{
				++count;
				start += t.length();
			}
			else
				++start;
		}
		cout << count << endl;
	}

}

//https://www.nowcoder.com/questionTerminal/3549ff22ae2c4da4890e9ad0ccb6150d
#include<iostream>
using namespace std;
int main()
{
	long  long f, t;
	while (cin >> f >> t)
	{
		long long f1 = 0;
		long long f2 = 1;
		long long f3;
		long long sum = 1;
		if (f == 1)
		{
			if (t == 1)
			{
				cout << sum << endl;
			}
			else if (t == 2)
			{
				sum = 2;
				cout << sum << endl;
			}
			else
			{
				for (int i = 1; i < t; ++i)
				{
					f3 = f1 + f2;
					f1 = f2;
					f2 = f3;
					sum += f3;
				}
				cout << sum << endl;
			}
		}
		else
		{
			for (int i = 1; i < f; ++i)
			{
				f3 = f1 + f2;
				f1 = f2;
				f2 = f3;
			}
			sum = f3;
			for (int i = f; i < t; ++i)
			{
				f3 = f1 + f2;
				f1 = f2;
				f2 = f3;
				sum += f3;
			}
			cout << sum << endl;
		}
	}
}

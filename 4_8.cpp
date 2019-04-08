// newcoder 最难的问题
#include<iostream>
#include<string>
using namespace std;
string& GetSecret(string& s)
{
	auto e = s.begin();
	while (e != s.end())
	{
		if ((*e >= 'F')&&( *e <= 'Z'))
		{
			*e -= 5;
		}
		else if ((*e <= 'E')&&(*e >= 'A'))
		{
			*e += 21;
		}
		++e;
	}
	return s;
}
int main()
{
	string s;
	while (getline(cin, s))
	{
		if (s.empty())
			cout << "0" << endl;
		else
			cout << GetSecret(s) << endl;
	}
}

//因子个数
#include<iostream>
using namespace std;
int Count(int n)
{
	int count = 0;
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n%i == 0)
		{
			n = n / i;
			++count;
		}
		while (n%i == 0)
		{
			n = n / i;
		}
	}
	if (n > sqrt(n))
		++count;
	return count;
}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << Count(n) << endl;
	}
}

//分解因数
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		cout << n << "=";
		for (int i = 2; i <= sqrt(n); ++i)
		{
			while (n != i)
			{
				if (n%i == 0)
				{
					cout << i << "*";
					n = n / i;
				}
				else
					break;
			}
		}
		cout << n;
	}
}
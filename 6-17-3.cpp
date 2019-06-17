//小易的升级之路
#include<iostream>
#include<vector>
using namespace std;
int GYS(int a, int b)
{
	int ret = a%b;
	while (ret)
	{
		a = b;
		b = ret;
		ret = a%b;
	}
	return b;
}
int main()
{
	int n, a;
	while (cin >> n >> a)
	{
		vector<int> v;
		int b;
		for (int i = 0; i < n; ++i)
		{
			cin >> b;
			v.push_back(b);
		}
		for (int i = 0; i < n; ++i)
		{
			if (a >= v[i])
			{
				a += v[i];
			}
			else
			{
				a += GYS(a, v[i]);
			}
		}
		cout << a << endl;
	}
	return 0;
}

//找出字符串中第一个只出现一次的字符
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	string s;
	while (getline(cin, s))
	{
		map<char, int> mp;
		for (auto a : s)
		{
			mp[a]++;
		}
		int n = 0;
		for (auto j : s)
		{
			if (mp[j] == 1)
			{
				cout << j << endl;
				break;
			}
			++n;
		}
		if (n == s.size())
			cout << "-1" << endl;
	}

}
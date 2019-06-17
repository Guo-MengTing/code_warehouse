//MP3光标位置
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int num;
	string s;
	while (cin >> num >> s)
	{
		int n = 1, first = 1;
		if (num <= 4)
		{
			for (int i = 0; i < s.size(); ++i)
			{
				if (n == 1 && s[i] == 'U')
					n = num;
				else if (n == 4 && s[i] == 'D')
					n = 1;
				else if (s[i] == 'U')
					--n;
				else
					++n;
			}
			for (int i = 1; i <= num ; ++i)
			{
				cout << i << ' ';
			}
			cout << endl;
			cout << n << endl;
		}
		else
		{
			for (int i = 0; i < s.size(); ++i)
			{
				if (n == 1 && first == 1 && s[i] == 'U')
				{
					n = num;
					first = num - 3;
				}
				else if (n == num&&first == num - 3 && s[i] == 'D')
				{
					n = 1;
					first = 1;
				}
				else if (n == first&&first != 1 && s[i] == 'U')
				{
					--n;
					--first;
				}
				else if (n == first + 3 && first != num - 3 && s[i] == 'D')
				{
					++n;
					++first;
				}
				else if (s[i] == 'U')
					--n;
				else
					++n;

			}
			for (int i = first; i <= first + 3; ++i)
			{
				cout << i << ' ';
			}
			cout << endl;
			cout << n << endl;
		}
	}
	return 0;
}

//洗牌
#include<iostream>
#include<vector>
using namespace std;
vector<int> XP(vector<int> v)
{
	vector<int> ret(v.size());
	int k=0;
	for (int j = 0; j < v.size() / 2; ++j)
	{
		ret[k] = v[j];
		k += 2;
	}
	k = v.size() - 1;
	for (int i = v.size() - 1; i >= v.size()/2; --i)
	{
		ret[k] = v[i];
		k -= 2;
	}
	return ret;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> v(2 * n);
		for (int i = 0; i < 2 * n; ++i)
		{
			cin >> v[i];
		}
		while (k--)
		{
			v = XP(v);
		}
		for (int i = 0; i < v.size(); ++i)
		{
			cout << v[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}
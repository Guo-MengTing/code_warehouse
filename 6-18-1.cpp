//微信红包
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		map<int, int> mp;
		for (auto a : gifts)
		{
			mp[a]++;
		}
		int size = n / 2;
		for (auto i : gifts)
		{
			if (mp[i]>size)
			{
				return i;
				break;
			}
		}
		return 0;
	}
};

//计算字符串的距离
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string s1;
	string s2;
	while (getline(cin, s1) && getline(cin, s2))
	{
		int len1 = s1.size();
		int len2 = s2.size();
		vector<vector<int>> v(len1 + 1, vector<int>(len2 + 1, 0));
		for (int x = 1; x < len1 + 1; ++x)
		{
			v[x][0] = x;
		}
		for (int y = 1; y < len2 + 1; ++y)
		{
			v[0][y] = y;
		}

		for (int i = 1; i < len1 + 1; i++)
		{
			for (int j = 1; j < len2 + 1; j++)
			{
				if (s1[i - 1] == s2[j - 1])
				{
					v[i][j] = v[i - 1][j - 1];
				}
				else
				{
					v[i][j] = v[i - 1][j - 1] + 1;
				}
				v[i][j] = min(v[i - 1][j] + 1, v[i][j]);
				v[i][j] = min(v[i][j], v[i][j - 1] + 1);
			}
		}
		cout << v[len1][len2] << endl;
	}
}
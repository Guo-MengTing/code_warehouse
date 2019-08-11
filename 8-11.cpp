//最长递增子序列(可以不连续）
//输入：8
//      5 1 6 8 2 4 5 10
//输出：5
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int num;
		vector<int> res(n);
		vector<int> tmp(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> num;
			res[i] = num;
			tmp[i] = num;
		}
		sort(tmp.begin(), tmp.end());
		vector<vector<int>> dp(n, vector<int>(n, 0));
		if (res[0] == tmp[0])
			dp[0][0] = 1;
		for (int i = 1; i < n; ++i)
		{
			if (res[0] == tmp[i])
				dp[0][i] = 1;
			dp[0][i] = max(dp[0][i], dp[0][i - 1]);
		}
		for (int i = 1; i < n; ++i)
		{
			if (res[i] == tmp[0])
				dp[i][0] = 1;
			dp[i][0] = max(dp[i][0], dp[i - 1][0]);
		}
		for (int i = 1; i < n; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (res[i] == tmp[j])
					dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + 1);
			}
		}
		cout << dp[n - 1][n - 1];
	}
}

//最长递增子序列（连续）
//输入：5
//      1 3 5 4 7
//输出：3
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int num;
		vector<int> v(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> num;
			v[i] = num;
		}
		int count = 0;
		for (int i = 0; i < n-1; ++i)
		{
			int s1 = v[i];
			int tmp = 1;
			for (int j = i + 1; j < n; ++j)
			{
				if (s1 < v[j])
				{
					++tmp;
					s1 = v[j];
				}
				else
					break;
			}
			count = max(count, tmp);
		}
		cout << count << endl;
	}
}

//给定n个数，判断有多少个数可以由剩下的n-1个数中的任意两个数相加组成
//逆向思维：先把所有加起来可能的结果放进unordered_map中（查找效率高），然后在map中找
//          注意数组中元素有0情况
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int num;
		vector<int> v(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> num;
			v[i] = num;
		}
		unordered_map<int, int> mp;
		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				int tmp = v[i] + v[j];
				if (v[i] != 0 && v[j]!=0)
					mp[tmp]=2;       //如果两个数都不为0，直接让value值为2；
				else
				{
					mp[tmp]++; //如果为0，每次+1
				}
			}
		}
		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			if (mp.find(v[i]) != mp.end()&&mp[v[i]]>=2)
				++count;
		}
		cout << count << endl;
	}
}
//给定n个数，判断有多少个数可以由剩下的n-1个数中的任意两个数相加组成
//将要查找的数尾插，之后循环看是否有两个数和为该数字
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
{
	int n;
	while (cin>>n)
	{
		int num;
		vector<int> v(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> num;
			v[i] = num;
		}
		int count = 0;
		bool flag = false;
		vector<int>::iterator it = v.begin();
		for (int i = 0; i < n; ++i)
		{
			int tmp = v[0];
			v.erase(v.begin());
			for (int j = 0; j < (v.size() - 1); ++j)
			{
				flag = false;
				for (int k = j + 1; k < v.size(); ++k)
				{
					if (v[j] + v[k] == tmp)
					{
						++count;
						flag = true;
						break;
					}
				}
				if (flag == true)
					break;
			}
			v.push_back(tmp);
		}
		cout << count << endl;
	}
}
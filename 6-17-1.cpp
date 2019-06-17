//字符串反转
#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	string s;
	while (getline(cin, s))
	{
		stack<char> st;
		string::iterator it = s.begin();
		for (it; it != s.end(); ++it)
		{
			st.push(*it);
		}
		while (!st.empty())
		{
			cout << st.top();
			st.pop();
		}
		cout << endl;
	}
	return 0;
}

//公共字串计算
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	string s1;
	string s2;
	while (cin >> s1 >> s2)
	{
		int len1 = s1.length();
		int len2 = s2.length();
		int max = 0;
		vector<vector<int>> v(len1+1, vector<int>(len2+1, 0));
		for (int i = 1; i <= len1; ++i)
		{
			for (int j = 1; j <= len2; ++j)
			{
				if (s1[i-1] == s2[j-1])
					v[i][j] = v[i - 1][j - 1] + 1;
				if (v[i][j]>max)
					max = v[i][j];
			}
		}
		cout << max << endl;
	}
}
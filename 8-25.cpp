//统计字符串出现个数并降序输出
#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		vector<int> v;
		unordered_map<char, int> mp;
		for (int i = 0; i < str.size(); ++i)
		{
			mp[str[i]]++;
		}
		unordered_map<char, int>::iterator it = mp.begin();
		for (it; it != mp.end(); ++it)
		{
			v.push_back(it->second);
		}
		sort(v.begin(), v.end());
		int tmp=0;
		for (int i = v.size()-1; i >0; --i)
		{
			tmp = v[i];
			it = mp.begin();
			for (it; it != mp.end(); ++it)
			{
				if (it->second == tmp)
				{
					cout << it->first <<":" << it->second << ",";
					it->second = 0;
				}
			}
		}
		it = mp.begin();
		for (it; it != mp.end(); ++it)
		{
			if (it->second!=0)
			{
				cout << it->first << ":" << it->second << endl;
			}
		}	
	}
	return 0;
}

//最小编辑距离
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string str;
	getline(cin, str);
	string word1;
	string word2;
	int i;
	for (i = 0; i<str.size(); ++i)
	{
		if (str[i] != ',')
			word1 += str[i];
		else
			break;
	}
	for (int j = i + 1; j<str.size(); ++j)
	{
		word2 += str[j];
	}
	int len1 = word1.size();
	int len2 = word2.size();
	vector<vector<int>> minD(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 0; i<len2 + 1; ++i)
	{
		minD[0][i] = i;
	}
	for (int i = 0; i<len1 + 1; ++i)
	{
		minD[i][0] = i;
	}
	for (int i = 1; i<len1 + 1; ++i)
	{
		for (int j = 1; j<len2 + 1; ++j)
		{
			minD[i][j] = min(minD[i - 1][j], minD[i][j - 1]) + 1;
			if (word1[i - 1] == word2[j - 1])
				minD[i][j] = min(minD[i - 1][j - 1], minD[i][j]);
			else
				minD[i][j] = min(minD[i - 1][j - 1] + 1, minD[i][j]);
		}
	}
	cout << minD[len1][len2] << endl;
	return 0;
}

//字符回退
#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	char s;
	string S;
	string str;
	cin >> S;
	s = S[0];
	for (int i = 1; i < S.size(); ++i)
	{
		str += S[i];
	}
	stack<char> st;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] != s)
			st.push(str[i]);
		else{
			if (!st.empty())
				st.pop();
			else
				continue;
		}
	}
	string res;
	stack<char> r;
	if (st.size() == 1)
	{
		cout << st.top() << endl;
		return 0;
	}
	else
	{
		while (!st.empty())
		{
			r.push(st.top());
			st.pop();
		}
		while (!r.empty())
		{
			res += r.top();
			r.pop();
		}
		cout << res << endl;
		return 0;
	}
}


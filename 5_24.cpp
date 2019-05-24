//字符串中找出连续最长的数字串
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while (getline(cin, s))
	{
		int num = 0;
		int maxnum = 0;
		int end = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] >= '0'&&s[i] <= '9')
			{
				++num;
				if (maxnum < num)
				{
					maxnum = num;
					end = i;
				}
			}
			else
			{
				num = 0;
			}
		}
		string ret = s.substr(end - maxnum + 1, maxnum);  //获取字符串s从下标end - maxnum + 1的位置开始长度为maxnum的字符串
		cout << ret << endl;
	}
	return 0;
}

//n个数出现次数大于等于n/2的数
#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<int, int> mp;
	int a;
	int size = 0;
	while (cin >> a)
	{
		++size;
		mp[a]++;
	}
	map<int, int>::iterator it = mp.begin();
	for (it; it != mp.end(); ++it)
	{
		if (it->second >= (size/2))
			cout << it->first;
	}
	return 0;
}
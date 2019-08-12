//字符全排列问题
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void Get(string& s, int i, int len, vector<string>& res)
{
	if (s[i] == '\0')
		res.push_back(s);
	else
	{
		for (int st = i; st < len; ++st)
		{
			swap(s[i], s[st]);
			Get(s, i + 1, len, res);
			swap(s[i], s[st]);
		}
	}
}
int main()
{

	int n;
	while(cin>>n)
	{
		vector<string> v;   //没有指定vector大小时，不能直接给v[i]赋值,只能使用push_back		
		string s;
		for (int i = 0; i < n; ++i)
		{
			cin >> s;
			v.push_back(s);
		}
		for (int i = 0; i < n; ++i)
		{
			string tmp = v[i];
			int len = tmp.size();
			vector<string> res;
			Get(tmp, 0, len, res);
			int start = 0;
			for (int j = 0; j < res.size(); ++j)
			{
				if (res[j] == tmp)
				{
					start = j;
					break;
				}
			}
			int end = start + len-1;
			if (end < res.size())
				cout << res[end] << endl;
			else
			{
				end = start + len - (end - res.size());
				cout << res[end] << endl;
			}
		}
		
	}
	return 0;
}

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void Get(int i, int len, string& str, vector<string>& res)
{
	if (str[i] == '\0')
		res.push_back(str);
	else
	{
		for (int st = i; st < len; ++st)
		{
			swap(str[i], str[st]);
			Get(i + 1, len, str, res);
			swap(str[i], str[st]);
		}
	}
}
int main()
{
	string str;
	while (getline(cin, str))
	{
		vector<string> res;
		int len = str.size();
		Get(0, len, str, res);
		sort(res.begin(), res.end());
		auto it = unique(res.begin(), res.end());   //unique会将字符串数组中相同的元素放在数组最后
		res.erase(it, res.end());
		for (int i = 0; i < res.size(); ++i)
		{
			cout << res[i] << endl;
		}
	}
}

//爬塔问题
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	while (cin >> num)
	{
		int h;
		vector<int> v(num);
		for (int i = 0; i < num; ++i)
		{
			cin >> h;
			v[i] = h;
		}
		vector<int> p(num + 2, 0);
		vector<int> t(num + 2, 0);
		for (int i = 2; i <= num+1; ++i)
		{
			p[i] = min(p[i - 1], t[i - 1]) + v[i-2];
			t[i] = min(p[i - 1], p[i - 2]);
		}
		int res = min(p[num+1], t[num+1]);
		cout << res << endl;
	}
}

#include<iostream>
#include<vector>
using namespace std;
void xe_s(int len, vector<int>& v)
{
	int gap = len;
	while (gap != 1)
	{
		gap = gap / 2;
		for (int i = 0; i < len; ++i)
		{
			for (int j = i + gap; j < len; j += gap)
			{
				for (int k = j - gap; k >= 0; k -= gap)
				{
					if (v[k]>v[j])
					{
						int tmp = v[k];
						v[k] = v[j];
						v[j] = tmp;
						j = k;
					}
				}
			}
		}
	}
}

void select_s(int len, vector<int>& v)
{
	for (int i = 0; i < len; ++i)
	{
		int min = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (v[j] < v[min])
				min = j;
		}
		swap(v[i], v[min]);
	}
}

void bubble_s(int len, vector<int>& v)
{
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (v[j]>v[j + 1])
				swap(v[j], v[j + 1]);
		}
	}
}


void adjust(int i, int len, vector<int>& v)
{
	for (int k = 2 * i + 1; k < len; k = 2 * k + 1)
	{
		if (k + 1 < len&&v[k] < v[k + 1])
			k = k + 1;
		if (v[i] < v[k])
		{
			swap(v[i], v[k]);
		}
		else
			break;
	}
}
void hp_s(int len, vector<int>& v)
{
	int i = len / 2 - 1;
	for (; i >= 0; --i)
	{
		adjust(i, len, v);
	}
	for (int j = len - 1; j >= 0; --j)
	{
		swap(v[j], v[0]);
		adjust(0, j, v);   //此时下面的元素已经是大堆，只需要从上向下调整
	}
}

void q_s(int i, int j, vector<int>& v)
{
	int left = i;
	int right = j;
	int base = v[i];
	if (left >= right)
		return;
	while (i != j)
	{
		while (i < j&&v[j] >= base)
			--j;
		if (i < j)
			v[i] = v[j];
		while (i < j&&v[i] <= base)
			++i;
		if (i < j)
			v[j] = v[i];
	}
	v[j] = base;
	q_s(left, j - 1, v);
	q_s(j + 1, right, v);
}

void gb(int left, int right, int mid, vector<int>& v)
{
	vector<int> tmp(right - left + 1);
	for (int i = left; i <= right; ++i)
	{
		tmp[i - left] = v[i];
	}
	int lst = left;
	int rst = mid + 1;
	for (int i = left; i <= right; ++i)
	{
		if (lst > mid)
		{
			v[i] = tmp[right - left];
			++rst;
		}
		else if (rst > right)
		{
			v[i] = tmp[lst - left];
			++lst;
		}
		else if (tmp[lst - left] <= tmp[rst - left])
		{
			v[i] = tmp[lst - left];
			++lst;
		}
		else if (tmp[lst - left] >= tmp[rst - left])
		{
			v[i] = tmp[rst - left];
			++rst;
		}
	}

}
void gb_s(int left, int right, vector<int>& v)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	gb_s(left, mid, v);
	gb_s(mid + 1, right, v);
	gb(left, right, mid, v);
}
int main()
{
	int num;
	while (cin >> num)
	{
		vector<int> v(num);
		int n;
		for (int i = 0; i < num; ++i)
		{
			cin >> n;
			v[i] = n;
		}
		int len = v.size();
		gb_s(0,len-1, v);
		for (int i = 0; i < len; ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}
}
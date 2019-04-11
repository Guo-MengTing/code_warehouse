//剪花布条
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

//客似云来
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

//收件人列表
//方法一
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int n;
	string name;
	while (cin >> n)
	{
		getchar();
		vector<string> v;
		bool flag = true;
		for (int i = 0; i < n; ++i)
		{
			string s;
			getline(cin, name);
			for (auto e : name)
			if (e == ' ' || e == ',')
			{
				flag = false;
				break;
			}
			if (flag == true)
			{
				v.push_back(name);
			}
			else
			{
				s = '\"' + name;
				s += '\"';
				v.push_back(s);
			}
		}
			vector<string>::iterator it = v.begin();
			for (it; it != v.end(); ++it)
			{
				cout << *it;
				if (it != v.end() - 1)
					cout << ','<<' ';
				else
					cout <<  endl;
			}
		}
	return 0;		
}

//方法二
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	while (cin>>n)
	{
		cin.get();
		string name;
		string s;
		if (n == 1)
		{
			getline(cin, name);
			if (name.find(' ') == -1 && name.find(',') == -1)
				s += name;
			else
				s += '\"' + name + '\"';
		}
		else
		{
			for (int i = 0; i < n; ++i)
			{

				getline(cin, name);
				if (i != n - 1)
				{
					if (name.find(' ') == -1 && name.find(',') == -1)
						s += name + ',' + ' ';
					else
						s += '\"' + name + '\"' + ',' + ' ';
				}
				else
				{
					if (name.find(' ') == -1 && name.find(',') == -1)
						s += name;
					else
						s += '\"' + name + '\"';
				}
			}
		}	
		cout << s << endl;
	}
	return 0;
}

//养兔子
#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		long long f1 = 0;
		long long f2 = 1;
		long long f3;
		for (int i = 0; i < n; ++i)
		{
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
		cout << f3 << endl;
	}
	return 0;
}

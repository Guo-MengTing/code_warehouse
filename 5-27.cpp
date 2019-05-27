//不要二
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int w, h;
	while (cin >> w >> h)
	{
		vector<vector<int>> v(w, vector<int>(h, 1));
		for (int i = 0; i < w; ++i)
		{
			for (int j = 0; j < h; ++j)
			{
				if (v[i][j] == 1)
				{
					if (i + 2 < w)
						v[i + 2][j] = 0;
					if (j + 2 < h)
						v[i][j + 2] = 0;
				}
			}
		}
		int num = 0;
		for (int i = 0; i < w; ++i)
		{
			for (int j = 0; j < h; ++j)
			{
				if (v[i][j] == 1)
					++num;
			}
		}
		cout << num << endl;
	}
	return 0;
}

//把字符串转换成整数
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	while (cin >> str)
	{
		long long tmp = 0;
		bool flag = true;
		int size = str.size();
		if (size == 0)
			return 0;
		for (int i = 0; i < size; ++i)
		{
			if (str[i] == '-')
			{
				flag = false;
			}
			else if (str[i] == '+')
			{
				flag = true;
			}
			else if (str[i]<'0' || str[i]>'9')
			{
				cout << "0" << endl;
				return 0;
			}	
			else
				tmp = tmp * 10 + str[i] - '0';
		}
		if (flag == false)
			tmp = tmp*(-1);
		cout << tmp << endl;
	}
}
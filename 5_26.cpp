//统计回文
#include<iostream>
#include<string>
using namespace std;
bool IsHuiWen(string A)
{
	int len = A.length();
	for (int i = 0; i < len; ++i)
	{
		if (A[i] == A[len - 1])
			len = len - 1;
		else
			return false;
	}
	return true;
}
int main()
{
	string A;
	string B;
	while (cin >> A >> B)
	{
		int num = 0;
		string tmp = A;
		int len = A.length() + 1;
		for (int i = 0; i < len; ++i)
		{
			A = tmp;
			A.insert(i, B);
			if (IsHuiWen(A))
				num++;
		}
		cout << num << endl;

	}
}

//连续最大和
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		int sum = v[0];
		int max = v[0];
		for (int i = 0; i < v.size(); ++i)
		{
			if (sum>=0)
			{
				sum += v[i];
			}
			else
			{
				sum = v[i];
			}
			if (max < sum)
				max = sum;	
		}
		cout << max;
	}
}

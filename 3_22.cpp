杨辉三角的变形（输入行数，输出此行第几个元素是偶数）
#include<iostream>
using namespace std;
#include<vector>

int getEven(int n)
{
	vector <vector<int>> v(n);
	for (auto &e : v)
	{
		e.resize(2 * n - 1, 0);
	}
	v[0][n - 1] = 1;
	v[n - 1][0] = 1;
	v[n - 1][2 * n - 2] = 1;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < 2 * n - 2; ++j)
		{
			v[i][j] = v[i - 1][j] + v[i - 1][j - 1] + v[i - 1][j + 1];
		}
	}
	int num = 0;
	for (int i = 0; i < 2 * n - 1; ++i)
	{
		if ((v[n - 1][i] != 0) && (v[n - 1][i] % 2 == 0))
		{
			num = i + 1;
			break;
		}
	}
	return num;
}
int main()
{
	int n;
	while (cin >> n)
	{
		if (n <= 2)
			cout << "-1" << endl;
		else
		{
			cout << getEven(n) << endl;
		}
	}
	return 0;
}

//栈的压入弹出序列
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> s;
		int indx = 0;
		int outdx = 0;
		if (pushV.size() != popV.size())
		{
			return false;
		}
		while (outdx<popV.size())
		{
			while (s.empty() || (s.top() != popV[outdx]))
			{
				if (indx<pushV.size())
				{
					s.push(pushV[indx]);
					++indx;
				}
				else
					return false;
			}
			s.pop();
			++outdx;
		}
		return true;
	}
};
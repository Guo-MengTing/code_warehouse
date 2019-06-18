//迷宫问题
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> mg;
vector<vector<int>> or;
vector<vector<int>> best;
int m, n;
void Find(int i, int j)
{
	mg[i][j] = 1;
	or.push_back({ i, j });
	if (i == m - 1 && j == n - 1)
	{
		if (best.empty() || or.size() < best.size())
			best = or;
	}
	if (i - 1 >= 0 && mg[i - 1][j] == 0)
		Find(i - 1, j);
	if (i + 1 < m&&mg[i + 1][j] == 0)
		Find(i + 1, j);
	if (j - 1 >= 0 && mg[i][j - 1] == 0)
		Find(i, j - 1);
	if (j + 1 < n&&mg[i][j + 1] == 0)
		Find(i, j + 1);
	mg[i][j] = 0;
	or.pop_back();
}
int main()
{
	while (cin >> m >> n)
	{
		mg = vector<vector<int>>(m, vector<int>(n,0));
		or.clear();
		best.clear();
		for (auto &i : mg)
		{
			for (auto j : i)
			{
				cin >> j;
			}
		}
		Find(0, 0);
		for (auto &i : best)
		{
			cout << '(' << i[0] << ',' << i[1]<<')' << endl;
		}
	}
}
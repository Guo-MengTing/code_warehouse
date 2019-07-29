//https://www.nowcoder.com/questionTerminal/16fa68271ee5448cafd504bb4a64b482
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string s;
	while (getline(cin, s))
	{
		vector<int> v;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] >= '0'&&s[i] <= '9')
			{
				v.push_back(s[i] - '0');
			}
		}
		for (int i = 0; i < v.size(); ++i)
		{
			cout << v[i];
		}
		cout << endl;
	}
}

//https://www.nowcoder.com/questionTerminal/6276dbbda7094978b0e9ebb183ba37b9
#include<iostream>
#include<queue>
using namespace std;
char mg[10][10];
bool mark[10][10];
struct point{
	int x;
	int y;
	int step;
};
queue<point> q;
int go[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };
int BFS(int x, int y)
{
	while (!q.empty())
	{
		point node = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = node.x + go[i][0];
			int ny = node.y + go[i][1];
			if (nx < 0 || nx>9 || ny < 0 || ny>9)
				continue;
			if (mg[nx][ny] == '#')
				continue;
			if (mark[nx][ny] == true)
				continue;
			point newnode;
			newnode.x = nx;
			newnode.y = ny;
			newnode.step = node.step + 1;
			mark[nx][ny] = true;
			q.push(newnode);
			if (nx == 9 && ny == 8)
				return newnode.step;
		}
	}
	return 0;
}
int main()
{
	while (cin >> mg[0][0])
	{
		mark[0][0] = false;
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (i == 0 && j == 0)
					continue;
				cin >> mg[i][j];
				mark[i][j] = false;
			}
		}
		point tmp;
		tmp.x = 0;
		tmp.y = 1;
		tmp.step = 0;
		mark[0][1] = true;
		while (!q.empty())
		{
			q.pop();
		}
		q.push(tmp);
		int ret = BFS(10, 10);
		cout << ret << endl;
	}
}
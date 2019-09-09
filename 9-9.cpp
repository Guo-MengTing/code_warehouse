#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	int pid, ppid;
	vector<unsigned> vpid;
	vector<unsigned> vppid;
	while (cin >> pid)
	{
		vpid.push_back(pid);
		if (getchar() == '\n')
			break;
	}
	while (cin >> ppid)
	{
		vppid.push_back(ppid);
		if (getchar() == '\n')
			break;
	}
	int finish;
	cin >> finish;
	bool flag = false;
	for (int i = 0; i < vpid.size(); ++i)
	{
		if (vpid[i] == finish||vppid[i]==finish)
			flag == true;
	}
	if (!flag)
	{
		cout << "0" << endl;
	}
	int count = 1;
	queue<unsigned> q;
	for (int i = 0; i < vppid.size(); ++i)
	{
		if (vppid[i] == finish)
		{
			if (vpid[i] != 0)
			{
				q.push(vpid[i]);
				++count;
			}
		}
	}
	while (!q.empty())
	{
		finish = q.front();
		for (int i = 0; i < vppid.size(); ++i)
		{
			if (vppid[i] == finish)
			{
				if (vpid[i] != 0)
				{
					q.push(vpid[i]);
					++count;
				}
			}
		}
		q.pop();
	}
	cout << count << endl;
	return 0;
}

#include<iostream>
#include<list>
using namespace std;
int main()
{
	int N;
	cin >> N;
	list<int> ls;
	for (int i = 1; i <= N; ++i)
	{
		ls.push_back(i);
	}
	list<int>::iterator cur = ls.begin();
	int count = 0;
	while (ls.size())
	{
		for (int i = 0; i < 4; ++i)
		{
			++cur;
			if (cur == ls.end())
				cur = ls.begin();
		}
		if (*cur !=N)
		{
			++cur;
			++count;
			list<int>::iterator next = cur;
			if (next == ls.end())
				next = ls.begin();
			--cur;
			ls.erase(cur);
			cur = next;
		}
		else
			break;
	}
	cout << (count + 1) << endl;
	return 0;
}
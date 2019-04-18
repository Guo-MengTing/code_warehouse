//dynamic_cast����ת��
#include<iostream>
using namespace std;
class Person
{
public:
	virtual void f() {}
};
class Student :public Person
{
};
void fun(Person* p)
{
	Student* s1 = static_cast<Student*>(p);
	Student* s2 = dynamic_cast<Student*>(p);      //dynamic_cast���ȼ���ܷ�ת���ɹ����ܳɹ���ת�������򷵻�0

	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;
}
int main()
{
	Student s;
	Person *p=&s;
	fun(p);
	fun(&s);
	return 0;
}

//explicit�ؼ���
class A
{
public:
	explicit A(int a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}
private:
	int _a;
};
int main()
{
	A a1(1);
	// ��ʽת��-> A tmp(1); A a2(tmp);
	A a2 = 1;
}

//�����
#include<iostream>
#include<string.h>
using namespace std;
int a[20][20] = { 0 }, res = 0, m, n;
void dfs(int x, int y)
{
	if (a[x][y] == 1 || x<0 || x >= m || y<0 || y >= n)
		return;
	res++;    //�������1
	a[x][y] = 1;//��1�����Ѿ��߹�
	dfs(x - 1, y);//�ֱ��Ӧ��
	dfs(x + 1, y);//��
	dfs(x, y - 1);//��
	dfs(x, y + 1);//�����ڸ���

}
int main()
{
	while (~scanf("%d %d", &m, &n))
	{
		getchar();
		int x, y;
		char c;
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				scanf("%c", &c);
				if (c == '@')
				{
					x = i;
					y = j;
				}
				else{
					if (c == '#')
						a[i][j] = 1;
				}
			}
			getchar();
		}
		dfs(x, y);
		printf("%d\n", res);
		res = 0;
		memset(a, 0, sizeof(a));
	}

	return 0;
}

//���ݿ����ӳ�
#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int maxsize = 0;
		set<string> pool;
		for (int i = 0; i < n; ++i)
		{
			string id, con;
			cin >> id >> con;
			if (con == "connect")
				pool.insert(id);
			else if (con == "disconnect")
				pool.erase(id);
			int size = pool.size();
			if (maxsize < size)
				maxsize = size;
		}
		cout << maxsize << endl;

	}
}

//密码强度等级
#include<iostream>
using namespace std;
#include<string>
int main()
{
	string p;
	while (getline(cin, p))
	{
		int s = 0;
		if (p.size() <= 4)
			s += 5;
		if (5 <= p.size() && p.size() <= 7)
			s += 10;
		if (p.size() >= 8)
			s += 25;
		int num = 0;
		int symbol = 0;
		int small = 0;
		int big = 0;
		for (int i = 0; i < p.size(); ++i)
		{
			if (p[i] >= '0'&&p[i] <= '9')
			{
				++num;
			}
			if (p[i] >= 'a'&&p[i] <= 'z')
			{
				++small;
			}
			if (p[i] >= 'A'&&p[i] <= 'Z')
			{
				++big;
			}
			if (p[i] >= '!'&&p[i] <= '/')
			{
				++symbol;
			}
			if ((p[i] >= ':'&&p[i] <= '@')||(p[i]>='['&&p[i]<='`'))
			{
				++symbol;
			}
			if (p[i] >= '{'&&p[i] <= '~')
			{
				++symbol;
			}
		}
		if (num == 1)
			s += 10;
		if (num > 1)
			s += 20;
		if (symbol == 1)
			s += 10;
		if (symbol > 1)
			s += 25;
		if ((small != 0 && big == 0)||(small==0&&big!=0))	
		{
			s += 10;
			if (num != 0)
			{
				if (symbol != 0)
					s += 3;
				else
					s += 2;
			}
		}
		else if (small == 0&&big == 0)
		{
		}
		else
		{
			s += 20;
			if (num != 0)
			{
				if (symbol != 0)
					s += 5;
			}
		}
		if (s >= 90)
			cout << "VERY_SECURE" << endl;
		if (s >= 80 && s < 90)
			cout << "SECURE" << endl;
		if (s >= 70 && s < 80)
			cout << "VERY_STRONG" << endl;
		if (s >= 60 && s < 70)
			cout << "STRONG" << endl;
		if (s >= 50 && s < 60)
			cout << "AVERAGE" << endl;
		if (s >= 25 && s < 50)
			cout << "WEAK" << endl;
		if (s >= 0 && s < 25)
			cout << "VERY_WEAK" << endl;
	}

}
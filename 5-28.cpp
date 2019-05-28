//Fibonacci数列
#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int f1 = 0;
		int f2 = 1;
		int f3;
		int min;
		int gap;
		while (1)
		{ 
			f3 = f1 + f2;
			if (n > f3)
			{
				f1 = f2;
				f2 = f3;
				min= n - f3;
			}
			else
			{
				gap = f3 - n;
				break;
			}
		  
		}
		if (gap < min)
			min = gap;
		cout << min << endl;
		
	}
}


//合法括号序列判断
#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	string s;
	int n;
	while (cin >> s >> n)
	{
		stack<char> st;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == '(')
				st.push(s[i]);
			else if (s[i] == ')')
			{
				if (!st.empty())
				{
					while (st.top() != '(')
					{
						st.pop();
					}
					if (st.top() == '(')
					{
						st.pop();
					}
					else
						cout << "N" << endl;
				}
				else
				{
					cout << "N" << endl;
					return 0;
				}
			}
			else
				st.push(s[i]);
		}
		if (st.empty())
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}
}
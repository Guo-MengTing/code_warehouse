//https://www.nowcoder.com/questionTerminal/9f6b8f6ec26d44cfb8fc8c664b0edb6b
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s;
//	while (getline(cin, s))
//	{
//		string::iterator it = s.begin();
//		for (it; it != s.end(); ++it)
//		{
//			if (*it == ' ')
//			{
//			}
//			else if (*it >= 'A'&&*it <= 'E')
//			{
//				*it = *it +21;
//			}
//			else
//			{
//				*it = *it-5;
//			}
//		}
//		cout << s << endl;
//	}
//}

//https://www.nowcoder.com/questionTerminal/e8fb8f89f5d147ec92fd8ecfefe89b0d
#include<iostream>
using namespace std;
int main()
{
	int num;
	while (cin >> num)
	{
		int i = 2;
		int count = 0;
		for (i; i <= sqrt(num); ++i)
		{
			if (num%i == 0)
			{
				++count;
				num = num / i;
			}
			while (num%i == 0)
			{
				num = num / i;
			}
		}
			if (num != 1)
				++count;
		cout << count << endl;
	}
}
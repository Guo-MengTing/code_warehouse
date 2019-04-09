//分解因数
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		cout << n << ' ' << "=" << ' ';
		for (int i = 2; i <= sqrt(n); ++i)
		{
			while (n != i)
			{
				if (n%i == 0)
				{
					cout << i << ' ' << "*" << ' ';
					n = n / i;
				}
				else
					break;
			}
		}
		cout << n << endl;
	}
}

//淘宝网店
#include<iostream>
using namespace std;
int Money(int a, int b, int c, int d, int e, int f)
{
	int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int money[13] = { 0, 2, 1, 1, 2, 1, 2, 1, 2, 2, 2, 1, 2};
	int sum = 0;
	if (a == d)
	{
		if ((a % 400 == 0) || ((a % 4 == 0) && (a % 100 != 0)))
			month[2] = 29;
		if (b < e)
		{
			int i;
			for (i = b+1; i < e; ++i)
			{
				sum += month[i] * money[i];
			}
			sum += (month[b] - c + 1)*money[b];
			sum += f*money[e];	
		}
		else if (b==e)
		{
			sum += (f - c + 1)*money[b];
		}
	}
	else if (a<d)
	{
		if ((a % 400 == 0) || ((a % 4 == 0) && (a % 100 != 0)))
			month[2] = 29;
		int j;
		for (j = b + 1; j <= 12; ++j)
		{
			sum += month[j] * money[j];
		}
		sum += (month[b] - c + 1)*money[b];
		if ((d % 400 == 0) || ((d % 4 == 0) && (d % 100 != 0)))
			month[2] = 29;
		else
			month[2] = 28;
		int k;
		if (e==1)
			sum += f*money[e];
		else
		{
			for (k = 1; k < e; ++k)
			{
				sum += month[k] * money[k];
			}
			sum += f*money[e];
		}
	}
	return sum;
}
int main()
{
	int a, b, c, d, e, f;
	while (cin >> a >> b >> c >> d >> e >> f)
	{
		cout << Money(a, b, c, d, e, f) << endl;
	}
}

//斐波那契凤尾
#include<stdio.h>
int main()
{
	int Arr[100001];
	int n = 0;
	Arr[0] = 1;
	Arr[1] = 1;
	for (int i = 2; i <= 100000; ++i)
	{
		Arr[i] = Arr[i - 1] + Arr[i - 2];
		Arr[i] = Arr[i] % 1000000;
	}
	while (scanf("%d", &n) != EOF)
	{
		if (n < 29)
			printf("%d\n", Arr[n]);
		else
			printf("%06d\n", Arr[n]);
	}
	return 0;
}

//红包问题（如果连续两天以上支付金额超过10元，且支付总金额和为target，则输出true)
#include<iostream>
#include<vector>
using namespace std;
int CanGet(vector<int> v, int target)
{
	int sum = 0;
	int count = 0;
	int flag = 0;
	int a = 0;
	auto e = v.begin();
	for (e; e < v.end(); ++e)
	{
		if (*e>10)
			++count;
		else
			--count;
		sum += *e;
		if (sum == target)
		{
			flag = 1;
		}
	}
	if ((count >= 2) && ((flag == 1) || (sum == target)))
		return 1;
	else
		return 2;
}
int main()
{
	int n;
	vector<int> v;
	cin >> n;
	v.push_back(n);
	while (cin.get()!='\n')
	{ 
		cin >> n;
		v.push_back(n);
	}
	int target;
	cin >> target;
	if (CanGet(v, target) == 1)
		cout << "true" << endl;
	else
		cout << "false" << endl;
}
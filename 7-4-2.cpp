//memcpy函数模拟实现
#include<iostream>
#include<assert.h>
using namespace std;
void* my_memcpy(void* dst, const void* src, int n)
{
	void* ret = dst;
	assert(dst != NULL&&src != NULL);
	while (n--)
	{
		*(char*)dst = *(char*)src;
		dst = (char*)dst + 1;
		src = (char*)src + 1;
	}
	return ret;
}
int main()
{
	char a[20] = { 1, 2, 3, 4, 5,6,7,8,9 };
	my_memcpy(a + 4, a+2 , 3);
	cout << a << endl;
}

//大小端判断
//方法一：
#include<iostream>
using namespace std;
int check()
{
	int i = 1;
	return *(char*)(&i);
}
int main()
{
	int ret = check();
	if (ret == 1)
	{
		cout << "小端" << endl;
	}
	else
		cout << "大端" << endl;
}
//方法二：
#include<iostream>
using namespace std;
int main()
{
	union{
		int i;
		char a;
	}un;
	un.i = 1;
	if (un.a == 1)
		cout << "小端" << endl;
	else
		cout << "大端" << endl;
}

//itoa
#include<iostream>
using namespace std;
void InttoString(int n, char* res)
{
	int flag = 1;
	int i = 0, j = 0;
	char buf[100] = "";
	if (n<0)
		res[i++] = '-';
	n = abs(n);
	while (n)
	{
		buf[j++] = n % 10 + '0';
		n = n / 10;
	}
	j--;
	while (j >= 0)
		res[i++] = buf[j--];//倒序赋值给res
	res[i] = '\0';
}
int main()
{
	int num;
	char res[10] = "";
	cin >> num;
	InttoString(num, res);
	cout << res << endl;
	return 0;
}

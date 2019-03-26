1.static修饰局部变量和全局变量
#include<stdio.h>
static int j;
void fun1(void)
{
	static int i = 0;
	i++;
}
void fun2(void)
{
	j = 0;
	j++;
}
int main()
{
	for (int k = 0; k < 10; k++)
	{
		fun1();
		fun2();
	}
	printf("%d", j);
	return 0;
}

2.模拟实现字符串拷贝my_strcpy函数
#include<stdio.h>
#include<assert.h>
char* my_strcpy(char *dest,const char *str)
{
	char *ret = dest;
	assert(str != NULL);
	assert(dest != NULL);
	while (*dest++ = *str++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[10] = { 'x', 'y', 'z', 'j', 'i', 'n', 'u' };
	char arr2[5] = { 'g', 'm', 't', '\0' };
	my_strcpy(arr1, arr2);
	printf("%s", arr1);
	return 0;
}

3.sizeof是关键字不是函数
#include<stdio.h>
int main()
{
	int i;
	printf("%d\n", sizeof(int));
	return 0;

}

4.模拟实现求字符串长度my_strlen函数
#include<stdio.h>
#include<assert.h>
int my_strlen(const char * p)
{
	int count = 0;
	assert(p != NULL);
	while (*p != '\0')
	{
		count++;
		p++;
	}
	return count;
}
int main()
{
	char a[] = "abcdef";
	printf("%d\n", my_strlen(a));
	return 0;
}

5.大小端的实现（巧妙运用联合）
#include<stdio.h>
union 
{
	char c;
	int i;
}un;
int check_sys(int a)
{
	un.i = a;
	if (un.c == 0)
		return 0;
	else
		return 1;
}
int main()
{ 
	int i=1;
	check_sys(i);
	if (check_sys(i) == 0)
		printf("大端\n");
	else
		printf("小端\n");
	return 0;	
}

6.求字符串长度，不创建临时变量（递归）
#include<stdio.h>
#include<assert.h>
int my_strlen(char *str)
{
	assert(str!= NULL);
	if (*str == '\0')
		return 0;
	return 1 + my_strlen(++str);
}
int main()
{
	char a[] = "ancdef";
	int len = my_strlen(a);
	printf("%d\n", len);
	return 0;
}

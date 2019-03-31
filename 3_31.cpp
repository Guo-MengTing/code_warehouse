//字符串逆置
#include<stdio.h>
#include<assert.h>
int my_strlen(const char *str)
{
	assert(str);
	int len = 0;
	while (*str++)
	{
		len++;
	}
	return len;
}
void reverse(char *start, char *end)
{
	assert(start);
	assert(end);
	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}
void str_reverse(char *str)
{
	assert(str);
	int len = my_strlen(str);
	reverse(str, str + len - 1);
	while (*str != '\0')
	{
		char *p = str;
		while ((*str != ' ') && (*str != '\0'))
		{
			str++;
		}
		reverse(p, str - 1);
		if (*str != '\0')
		{
			str++;
		}
	}
}
int main()
{
	char str[] = "student a am i";
	str_reverse(str);
	printf("%s\n", str);
	return 0;
}

//大小端的实现（巧妙运用联合）
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
	int i = 1;
	check_sys(i);
	if (check_sys(i) == 0)
		printf("大端\n");
	else
		printf("小端\n");
	return 0;
}

//求字符串长度，不创建临时变量（递归）
#include<stdio.h>
#include<assert.h>
int my_strlen(char *str)
{
	assert(str != NULL);
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
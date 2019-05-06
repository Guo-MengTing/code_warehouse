#include<iostream>
using namespace std;
//my_strcpy
#include<assert.h>
char* my_strcpy(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;
	while (*dest++ = *src++)
	{
	}
	return ret;
}
int main()
{
	char arr1[] = "helloworld";
	char arr2[] = "winner";
	cout<<my_strcpy(arr1, arr2)<<endl;
	return 0;
}

//my_strcat
#include<assert.h>
char* my_strcat(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;
	while (*dest)
	{
		++dest;
	}
	while (*dest++ = *src++)
	{
	}
	return ret;

}
int main()
{
	char arr1[20] = "winner ";
	char arr2[] = "jinu";
	cout<<my_strcat(arr1, arr2)<<endl;
	
}

//my_strstr(若str2是str1的字串，则返回第一次在str1中出现的地址，否则返回NULL）
#include<assert.h>
char* my_strstr(const char* str1,const char* str2)
{
	assert(str1);
	assert(str2);
	char* s1 = (char*)str1;
	char* substr = (char*)str2;
	char* s = NULL;
	if (*str2 == '\0')
		return NULL;
	while (*s1)
	{
		s = s1;
		substr = (char*)str2;
		while (*s&&*substr && (*s == *substr))
		{
			++s;
			++substr;
		}
		if (*substr == '\0')
			return s1;
		++s1;
	}
}
int main()
{
	char arr1[] = "winner jinu";
	char arr2[] = "jinu";
	cout<<my_strstr(arr1, arr2)<<endl;
	return 0;
}

//my_strcmp
int my_strcmp(const char* dst, const char* src)
{
	int ret = 0;
	while (!(ret = (*(unsigned char*)dst - *(unsigned char*)src))&& *dst&&*src)
	{
		++src;
		++dst;
	}
	if (ret < 0)
		ret = -1;
	else if (ret>0)
		ret = 1;
	return ret;
}
int main()
{
	char arr1[] = "hello";
	char arr2[] = "acs";
	cout << my_strcmp(arr1, arr2) << endl;
	return 0;
}

//memcpy
void* my_memcpy(void* dst, const void* src, size_t count)
{
	void* ret = dst;
	while (count--)
	{
		*(char*)dst = *(char*)src;
		dst = (char*)dst + 1;
		src = (char*)src + 1;
	}
	return ret;
}


//memmove
void* my_memmove(void* dst, const void* src, size_t count)
{
	void* ret = dst;
	if (dst <= src)
	{
		while (count--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		dst = (char*)dst + count - 1;
		src = (char*)src + count - 1;
		while (count--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst - 1;
			src = (char*)src - 1;
		}
	}
	return ret;
}
int main()
{
	char arr1[] = "hello";
	char arr2[] = "acs";
	my_memmove(arr1, arr2, 3);
	cout << arr1 << endl;
	return 0;
}

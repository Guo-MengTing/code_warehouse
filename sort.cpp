÷±Ω”≤Â»Î≈≈–Ú
#include<stdio.h>
void insert_sort(int a[], int len)
{
	int i;
	int j;
	for (i = 1; i < len; ++i)
	{
		for (j = i - 1; j >= 0; --j)
		{
			if (a[i] < a[j])
			{
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
				i = j;
			}
		}
	}
}
int main()
{
	int a[] = { 5, 2, 4, 5, 1, 8 };
	int len = sizeof(a) / sizeof(a[0]);
	insert_sort(a, len);
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

œ£∂˚≈≈–Ú
#include<stdio.h>
void shell_sort(int a[], int len)
{
	int gap=len;
	while (1)
	{
		gap =gap/ 2;
		for (int i = 0; i < len; ++i)
		{
			for (int j = i+gap; j < len; j += gap)
			{
				if (a[j] < a[i])
				{
					int tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
				}
			}
		}
		if (gap == 1)
			break;
	}
}
int main()
{
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	int len = sizeof(a) / sizeof(a[0]);
	shell_sort(a, len);
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}

—°‘Ò≈≈–Ú
#include<stdio.h>
void select_sort(int a[],int len)
{
	for (int i = 0; i < len; ++i)
	{
		int min = i;
		for (int j = i+1; j < len; ++j)
		{
			if (a[j] < a[min])
				min = j;
		}
		int tmp = a[i];
		a[i] = a[min];
		a[min] = tmp;

	}
}
int main()
{
	int a[] = { 7, 4, 5, 9, 8, 2, 1 };
	int len = sizeof(a) / sizeof(a[0]);
	select_sort(a, len);
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}

∂—≈≈–Ú
#include<stdio.h>

void Swap(int a[], int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}
void adjust(int a[], int i, int len)
{
	int tmp = a[i];
	for (int k = 2 * i + 1; k <len;k=2*k+1 )
	{
		if (k+1 < len&&a[k] < a[k + 1])
			k = k + 1;
		if (a[k]>tmp)
		{
			a[i] = a[k];
			i = k;
		}
		else
		{
			break;
		}
	}
	a[i] = tmp;
}
void HeapSort(int a[], int len)
{
	int i = len / 2 - 1;
	for (i; i >= 0; --i)
	{
		adjust(a, i, len);
	}
	for (int j = len - 1; j >= 0; --j)
	{
		Swap(a, 0, j);
		adjust(a, 0, j);
	}
}
int main()
{
	int a[] = { 20, 17, 4, 16, 5, 3 };
	int len = sizeof(a) / sizeof(a[0]);
	HeapSort(a, len);
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", a[i]);
	}
}

√∞≈›≈≈–Ú
#include<stdio.h>
void BubbleSort(int a[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	int a[] = { 20, 17, 4, 16, 5, 3 };
	int len = sizeof(a) / sizeof(a[0]);
	BubbleSort(a, len);
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", a[i]);
	}
}


øÏÀŸ≈≈–Ú
#include<stdio.h>
void QuickSort(int a[], int left,int right)
{
	int i = left;
	int j = right;
	int base = a[left];
	if (left >= right)
		return;
	while (i != j)
	{
		while (i < j&&a[j] >= base)
			j--;
		if (j>i)
			a[i] = a[j];
		while (i<j&&a[i]<=base)
			i++;
		if (i < j)
			a[j] = a[i];
	}
	a[i] = base;
	QuickSort(a, left, i - 1);
	QuickSort(a, i + 1, right);
	
}
int main()
{
	int a[] = { 20, 17, 4, 16, 5, 3 };
	int len = sizeof(a) / sizeof(a[0]);
	QuickSort(a, 0, 5);
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", a[i]);
	}
}


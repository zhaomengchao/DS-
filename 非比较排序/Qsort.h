#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>


void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


//非比较排序
void CountSort(int* a, int n)
{
	int min = a[0];
	int max = a[0];
	for (int i = 0; i < n; i++)//选出最大数和最小数，确定数组大小
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	int range = max - min + 1;//算出新数组开辟空间的个数
	int* count = malloc(sizeof(int)*range);//空间复杂度O(N)
	memset(count, 0, sizeof(int)* range);//数组初始化

	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;//count[a[i] - min]下标是一个绝对位置
	}
	int j = 0;
	for (int i = 0; i < range; i++)//把元素重新写回原数组
	{
		while ((count[i]--) > 0)
		{
			a[j] = i + min;
			j++;
		}
	}
	free(count);

}


void CountSortTest()
{
	int array[] = { 2, 5, 8, 1, 3, 4, 5, 6, 6, 1, 0 };
	int size = sizeof(array) / sizeof(int);
	
	CountSort(array, size);
	Print(array, size);
}
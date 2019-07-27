#include<stdio.h>
#include<stdlib.h>


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


//三数取中法
//每次比较left、right、mid之间的值的大小，每次找到中间的值
int GitMid(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;

	if (a[left] < a[right])
	{
		if (a[mid] > a[right])
		{
			return right;
		}
		else if (a[mid] > a[left])
		{
			return mid;
		}
		else
		{
			return left;
		}
	}
	else//a[left] > a[right]
	{
		if (a[left] < mid)
		{
			return left;
		}
		else if (a[right] < a[mid])
		{
			return mid;
		}
		else
		{
			return right;
		}
	}
}

int PartSort(int* a, int left, int right)//左右指针法
{
	int midIndex = GitMid(a, left, right);//每次进来先进行三数取中法
	Swap(&a[midIndex], &a[right]);//将找到的值与a[right]交换
	int key = a[right];//定义关键值
	int key_index = right;

	while (left < right)
	{
		while (left < right && a[left] <= key)
		{
			left++;
		}
		while (left < right && a[right] >= key)
		{
			right--;
		}

		Swap(&a[left], &a[right]);


	}
	Swap(&a[left], &a[key_index]);
	return left;
}



//利用栈来实现快排的非递归
//为了防止递归栈溢出的问题，我们利用数据结构中在堆上定义的栈来实现
#include"stack.h"

void QuickSortNonR(int* a, int left, int right)//非递归
{
	Stack s;
	StackInit(&s);

	StackPush(&s, left);
	StackPush(&s, right);

	while(!StackEmpty(&s))
	{
		int end = StackTop(&s);
		StackPop(&s);
		int begin = StackTop(&s);
		StackPop(&s);

		int key_i = PartSort(a, begin, end);

		if (begin < key_i)
		{
			StackPush(&s, begin);
			StackPush(&s, key_i -1);
		}
		if (end > key_i)
		{
			StackPush(&s, key_i + 1);
			StackPush(&s, end);
		}
	}
}

void QuickSortNonRTest()
{
	int array[] = { 1, 4, 9, 6, 7, 3, 2, 5, 8, 10, 11, 0 };
	int size = sizeof(array) / sizeof(int);
	QuickSortNonR(array, 0, size-1);//非递归
	Print(array, size);
}






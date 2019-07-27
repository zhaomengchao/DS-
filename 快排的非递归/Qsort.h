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


//����ȡ�з�
//ÿ�αȽ�left��right��mid֮���ֵ�Ĵ�С��ÿ���ҵ��м��ֵ
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

int PartSort(int* a, int left, int right)//����ָ�뷨
{
	int midIndex = GitMid(a, left, right);//ÿ�ν����Ƚ�������ȡ�з�
	Swap(&a[midIndex], &a[right]);//���ҵ���ֵ��a[right]����
	int key = a[right];//����ؼ�ֵ
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



//����ջ��ʵ�ֿ��ŵķǵݹ�
//Ϊ�˷�ֹ�ݹ�ջ��������⣬�����������ݽṹ���ڶ��϶����ջ��ʵ��
#include"stack.h"

void QuickSortNonR(int* a, int left, int right)//�ǵݹ�
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
	QuickSortNonR(array, 0, size-1);//�ǵݹ�
	Print(array, size);
}






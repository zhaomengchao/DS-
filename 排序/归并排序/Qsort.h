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

//归并排序
//归并排序（MERGE-SORT）是建立在归并操作上的一种有效的排序算法,
//该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。
//将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，
//再使子序列段间有序。若将两个有序表合并成一个有序表，称为二路归并

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left == right)
	{
		return;
	}
	int mid = left + (right - left) / 2;
	
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//合并
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i] = a[begin1];
			begin1++;
			i++;
		}
		else
		{
			tmp[i] = a[begin2];
			begin2++;
			i++;
		}
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2];
		begin2++;
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1];
		begin1++;
	}

	//归并到原数组中
	memcpy(a + left, tmp + left, sizeof(int)*(i - left));
	
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)* n);

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}

void MergeSortTest()
{
	int array[] = { 2, 5, 8, 9, 4, 6, 7, 3, 1, 0 };
	int size = sizeof(array) / sizeof(int);
	MergeSort(array, size);
	Print(array, size);

}
//1. 归并的缺点在于需要O(N)的空间复杂度，归并排序的思考更多的是解决在磁盘中的外排序问题。 
//2. 时间复杂度：O(N*logN) 
//3. 空间复杂度：O(N) 
//4. 稳定性：稳定




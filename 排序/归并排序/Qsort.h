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

//�鲢����
//�鲢����MERGE-SORT���ǽ����ڹ鲢�����ϵ�һ����Ч�������㷨,
//���㷨�ǲ��÷��η���Divide and Conquer����һ���ǳ����͵�Ӧ�á�
//��������������кϲ����õ���ȫ��������У�����ʹÿ������������
//��ʹ�����жμ������������������ϲ���һ���������Ϊ��·�鲢

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left == right)
	{
		return;
	}
	int mid = left + (right - left) / 2;
	
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//�ϲ�
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

	//�鲢��ԭ������
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
//1. �鲢��ȱ��������ҪO(N)�Ŀռ临�Ӷȣ��鲢�����˼��������ǽ���ڴ����е����������⡣ 
//2. ʱ�临�Ӷȣ�O(N*logN) 
//3. �ռ临�Ӷȣ�O(N) 
//4. �ȶ��ԣ��ȶ�




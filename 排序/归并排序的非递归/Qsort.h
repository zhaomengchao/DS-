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
	
	_MergeSort(a, left, mid, tmp);//�ݹ飬����˼��
	_MergeSort(a, mid + 1, right, tmp);

	//�ϲ�
	int begin1 = left, end1 = mid;//�鲢���µĿռ�
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
	int* tmp = (int*)malloc(sizeof(int)* n);//�����µĿռ䣬�ռ�������ΪO(N);

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



//�ǵݹ�ʵ�ֹ鲢����

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);//�ռ临�Ӷ�ΪO(N);
	int gap = 1;
	while (gap < n)
	{
		//�������ѭ��
		for (int begin = 0; begin < n; begin += gap * 2)
		{
			int begin1 = begin, end1 = begin + gap - 1;
			//��������Խ������,gap�������Զ���������,���������ʮ��Ԫ�أ�����gap������8ʱ�������
			if (end1 >= n)
			{
				end1 = n - 1;
			}
			int begin2 = begin + gap , end2 = begin + gap * 2 - 1;
			if (end2 >= n)
			{
				end2 = n - 1;
			}

			
			//�鲢
			int index = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[index++] = a[begin1++];
				}
				else
				{
					tmp[index++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[index++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[index++] = a[begin2++];
			}
			
		}
		memcpy(a, tmp, sizeof(int)*n);
		gap = gap * 2;
	}
	free(tmp);
}

void MergeSortNonRTest()
{
	int array[] = { 2, 5, 8, 9, 4, 6, 7, 3, 1, 0 };
	int size = sizeof(array) / sizeof(int);
	MergeSortNonR(array, size);
	Print(array, size);
}

//ʱ�临�Ӷ�O(N*logN)






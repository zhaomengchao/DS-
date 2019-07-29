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


//�ǱȽ�����
void CountSort(int* a, int n)
{
	int min = a[0];
	int max = a[0];
	for (int i = 0; i < n; i++)//ѡ�����������С����ȷ�������С
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
	int range = max - min + 1;//��������鿪�ٿռ�ĸ���
	int* count = malloc(sizeof(int)*range);//�ռ临�Ӷ�O(N)
	memset(count, 0, sizeof(int)* range);//�����ʼ��

	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;//count[a[i] - min]�±���һ������λ��
	}
	int j = 0;
	for (int i = 0; i < range; i++)//��Ԫ������д��ԭ����
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
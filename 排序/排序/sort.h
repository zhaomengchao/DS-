#include<stdio.h>
#include<stdlib.h>


void Print(int* a,int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//��������  ��Ҫ�����ֵ�ٶ������������һ��
//Ԫ�ؼ���Խ�ӽ�����ֱ�Ӳ��������㷨��ʱ��Ч��Խ��
//ʱ�临�Ӷȣ�O(N^2)
//�ռ临�Ӷȣ�O(1),����һ���ȶ��������㷨
void InsertSort(int* a, int n)
{
	
	for (int i = 0; i < n - 1; i++)//���ԱȽϵķ�Χ��n-1֮ǰ
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (a[end + 1]< a[end])//�жϵ�ǰλ��end �����ֵ֮��Ĵ�С��ϵ
			{
				a[end + 1] = a[end];
				end--;         //�ж��Ƿ����ǰһ��Ԫ�أ��ӵ�ǰλ�ü�һ
			}
			else
			{
				break;
			}
			a[end + 1] = temp;
		}
	}
	Print(a, n);
}
void InsertTest()
{
	int array[] = { 3, 4, 2, 6, 5, 7, 1, 9, 8, 0 };
	int num = sizeof(array) / sizeof(int);
	InsertSort(array, num);

}

//��ֱ�Ӳ��������Ż�
//ƽ��ʱ�临�Ӷ�O(N^1.3--N^2)



void  shellsort(int *a, int n) // ϣ������=Ԥ����(�ӽ���˳������)+��������
{
	int gap = n;      //gapԽС������Խ����gapԽ������Խ��
	while (gap>1)
	{
		gap = gap / 3 + 1;   //��һ��֤���һ�εĲ�������
		for (int i = 0; i < n - gap; i++)   // ��ѭ������֮�����ڣ���·ͬʱ��������
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
	Print(a, n);
}

void ShellTest()
{
	int array[] = { 3, 4, 2, 6, 5, 7, 1, 9, 8, 0 };
	int num = sizeof(array) / sizeof(int);
	shellsort(array, num);
	//ShellSort(array, num);

}


void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//1. ֱ��ѡ������˼���ǳ�����⣬����Ч�ʲ��Ǻܺá�ʵ���к���ʹ��
//2. ʱ�临�Ӷȣ�O(N^2)
//3. �ռ临�Ӷȣ�O(1) 
//4. �ȶ��ԣ�����
void SelectSort(int *a, int n)//ֱ��ѡ������
{
	int begin = 0;
	int end = n - 1;

	int min_index, max_index;//�����±�
	while (end >= begin)
	{
		min_index = begin;
		max_index = end;
		for (int i = begin; i <= end; i++)
		{
			if (a[min_index] > a[i])
			{
				min_index = i;
			}
			if (a[max_index] < a[i])
			{
				max_index = i;
			}
		}
		
		Swap(&a[min_index], &a[begin]);
		if (begin == max_index)
		{
			max_index = min_index;
		}
		Swap(&a[max_index], &a[end]);

		begin++;
		end--;
	
	}
	Print(a, n);
}

void SelectTest()
{
	int array[] = { 9, 8, 7, 6, 5, 4, 3, 2 };
	int num = sizeof(array) / sizeof(int);
	SelectSort(array, num);

}

void AdjustDwon(int* a, int n, int parint)//�ѵĵ���
{
	int child = parint * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parint])
		{
			Swap(&a[parint], &a[child]);
			parint = child;
			child = parint * 2 + 1;
		}
		else
		{
			break;
		}	
	}
	
}


//������(Heapsort)��ָ���öѻ������ѣ��������ݽṹ����Ƶ�һ�������㷨������ѡ�������һ�֡�
//���� ͨ����������ѡ�����ݡ���Ҫע�����������Ҫ����ѣ��Ž���С��
void HeapSort(int *a, int n)//������
{
	//����
	int end = n - 1;

	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
	while (end > 0)//�ж�����ʱ��ÿ�����������һ��ͬʱÿ�ε����ĸ���Ҳ�ڱ仯
	{
		Swap(&a[0], &a[end]);
		//end--;
		AdjustDwon(a, end, 0);//ע��end��ʹ��
		end--;
	}
}
//1. ������ʹ�ö���ѡ����Ч�ʾ͸��˺ܶࡣ
//2. ʱ�临�Ӷȣ�O(N*logN) 
//3. �ռ临�Ӷȣ�O(1)
//4. �ȶ��ԣ����ȶ�

void HeapSortTest()
{
	int array[] = { 1,3,5,4,2,6,8,9,7,0 };
	int num = sizeof(array) / sizeof(int)-1;
	HeapSort(array, num);
	Print(array, num);

}


//1. ð��������һ�ַǳ������������� 
//2. ʱ�临�Ӷȣ�O(N^2) 
//3. �ռ临�Ӷȣ�O(1)
//4. �ȶ��ԣ��ȶ�

void  BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
	}
}

void BubbleSortTest()
{
	int a[] = { 7, 5, 3,8,4,9,6,1,2,0};
	int size = sizeof(a) / sizeof(int);
	BubbleSort(a, size);
	Print(a, size);
}



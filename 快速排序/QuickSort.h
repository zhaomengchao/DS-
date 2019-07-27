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
}


//void InsertTest()
//{
//	int array[] = { 3, 4, 2, 6, 5, 7, 1, 9, 8, 0 };
//	int num = sizeof(array) / sizeof(int);
//	InsertSort(array, num);
//	Print(array, num);
//}
//���������ʱ�临�Ӷ�ΪO(nlog(n));
//����ΪO(n^2)
//����һ�������ֻ����������������������
//Ϊ�˱��������ķ��������Բ��õķ���������ȡ�з������ѡkey�������߲����ã�

//1.����ָ�뷨
//2. �ڿӷ� 
//3. ǰ��ָ�뷨

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

int PartSort1(int* a, int left, int right)//����ָ�뷨
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


void QuickSort1(int* a, int left, int right)//����ָ�뷨
{
	if (left >= right)
	{
		return;
	}
	

		int key_i = PartSort1(a, left, right);
		QuickSort1(a, left, key_i - 1);
		QuickSort1(a, key_i + 1, right);
	
}


int PartSort2(int* a, int left, int right)//�ڿӷ�
{
	int key = a[right];

	while (left < right)
	{
		if (left < right && a[left] < key)
		{
			left++;
		}
		a[right] = a[left];

		if (left < right && a[right] > key)
		{
			right--;
		}
		
		a[left] = a[right];
	}
	a[left] = key;
	return left;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int key_i = PartSort2(a, left, right);

	QuickSort(a, left, key_i - 1);
	QuickSort(a, key_i + 1, right);

}

int PartSort3(int* a, int left, int right)//ǰ��ָ�뷨
{
	int key = a[right];
	int prev = left - 1;
	int cur = left;

	while (cur < right)
	{
		if (a[cur] < key && prev++ != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	prev++;
	Swap(&a[prev], &a[right]);
	return prev;
}

void QuickSort3(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int key_i = PartSort3(a, left, right);

	QuickSort3(a, left, key_i - 1);
	QuickSort3(a, key_i + 1, right);

}



void QuickSortTest()
{
	int arr[] = { 1, 5, 9, 7, 6, 8 ,2, 4, 3, 0,11};
	int size = sizeof(arr) / sizeof(int);
	
	if (size > 10)//������Ԫ�صĸ���С��ʮ���ÿ�������Ч�ʺܵͣ��������������ֱ��ѡ�ò�������
	{
		QuickSort1(arr, 0, size - 1);
	}
	else
	{
		InsertSort(arr, size);
	}
	

	Print(arr, size);
}




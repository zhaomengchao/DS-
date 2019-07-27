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

	for (int i = 0; i < n - 1; i++)//所以比较的范围在n-1之前
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (a[end + 1]< a[end])//判断当前位置end 与后面值之间的大小关系
			{
				a[end + 1] = a[end];
				end--;         //判断是否大于前一个元素，从当前位置减一
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
//快速排序的时间复杂度为O(nlog(n));
//最坏情况为O(n^2)
//快排一般情况下只考虑最好情况，不考虑最坏情况
//为了避免最坏情况的发生，可以采用的方法：三数取中法；随机选key法（后者不常用）

//1.左右指针法
//2. 挖坑法 
//3. 前后指针法

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

int PartSort1(int* a, int left, int right)//左右指针法
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


void QuickSort1(int* a, int left, int right)//左右指针法
{
	if (left >= right)
	{
		return;
	}
	

		int key_i = PartSort1(a, left, right);
		QuickSort1(a, left, key_i - 1);
		QuickSort1(a, key_i + 1, right);
	
}


int PartSort2(int* a, int left, int right)//挖坑法
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

int PartSort3(int* a, int left, int right)//前后指针法
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
	
	if (size > 10)//当数组元素的个数小于十，用快速排序，效率很低，所以有如下情况直接选用插入排序
	{
		QuickSort1(arr, 0, size - 1);
	}
	else
	{
		InsertSort(arr, size);
	}
	

	Print(arr, size);
}




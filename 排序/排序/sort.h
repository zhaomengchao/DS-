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

//插入排序  把要插入的值假定放在数组最后一个
//元素集合越接近有序，直接插入排序算法的时间效率越高
//时间复杂度：O(N^2)
//空间复杂度：O(1),它是一种稳定的排序算法
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
	Print(a, n);
}
void InsertTest()
{
	int array[] = { 3, 4, 2, 6, 5, 7, 1, 9, 8, 0 };
	int num = sizeof(array) / sizeof(int);
	InsertSort(array, num);

}

//对直接插入排序优化
//平均时间复杂度O(N^1.3--N^2)



void  shellsort(int *a, int n) // 希尔排序=预排序(接近于顺序有序)+插入排序
{
	int gap = n;      //gap越小，排序越慢；gap越大，排序越快
	while (gap>1)
	{
		gap = gap / 3 + 1;   //加一保证最后一次的插入排序
		for (int i = 0; i < n - gap; i++)   // 该循环巧妙之处在于，多路同时进行排序
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
//1. 直接选择排序思考非常好理解，但是效率不是很好。实际中很少使用
//2. 时间复杂度：O(N^2)
//3. 空间复杂度：O(1) 
//4. 稳定性：不稳
void SelectSort(int *a, int n)//直接选择排序
{
	int begin = 0;
	int end = n - 1;

	int min_index, max_index;//数组下标
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

void AdjustDwon(int* a, int n, int parint)//堆的调整
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


//堆排序(Heapsort)是指利用堆积树（堆）这种数据结构所设计的一种排序算法，它是选择排序的一种。
//它是 通过堆来进行选择数据。需要注意的是排升序要建大堆，排降序建小堆
void HeapSort(int *a, int n)//堆排序
{
	//建堆
	int end = n - 1;

	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
	while (end > 0)//判断条件时，每次数组个数减一，同时每次调整的个数也在变化
	{
		Swap(&a[0], &a[end]);
		//end--;
		AdjustDwon(a, end, 0);//注意end的使用
		end--;
	}
}
//1. 堆排序使用堆来选数，效率就高了很多。
//2. 时间复杂度：O(N*logN) 
//3. 空间复杂度：O(1)
//4. 稳定性：不稳定

void HeapSortTest()
{
	int array[] = { 1,3,5,4,2,6,8,9,7,0 };
	int num = sizeof(array) / sizeof(int)-1;
	HeapSort(array, num);
	Print(array, num);

}


//1. 冒泡排序是一种非常容易理解的排序 
//2. 时间复杂度：O(N^2) 
//3. 空间复杂度：O(1)
//4. 稳定性：稳定

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



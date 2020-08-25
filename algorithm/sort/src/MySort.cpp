#include <malloc.h>
#include <cstring>
#include <queue>
#include "MySort.h"
void  MySort::swap(int arr[], const uint a, const uint b)
{
	if (a == b)return;
	int t = arr[a];
	arr[a] = arr[b];
	arr[b] = t;
}
// 冒泡排序
// 相邻两两排序，每次循环确定一个最大（最小）数位置
bool MySort::bubbleSort(int arr[], const uint len)
{
	for (uint i = 0; i < len; ++i)
	{
		for (uint j = 0; j < len - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])swap(arr, j, j + 1);
		}
	}
	return true;
}
// 选择排序
// 每次从未排序队列选择一个最大（最小）数放在已排序队列开头（末尾）
bool MySort::selectionSort(int arr[], const uint len)
{
	for (uint i = 0; i < len; ++i)
	{
		uint min = i;
		for (uint j = i + 1; j < len; ++j)
		{
			if (arr[min] > arr[j])min = j;
		}
		swap(arr, i, min);
	}
	return true;
}
// 插入排序
// 从未排序队列中选择一个数，并放到已排序队列相应的位置
bool MySort::insertionSort(int arr[], const uint len)
{
	for (uint i = 1; i < len; ++i)
	{
		// j 为相对于i的向前偏移量
		for (uint j = 0; j < i; ++j)
		{
			if (arr[i - j] < arr[i - j - 1])
			{
				swap(arr, i - j, i - j - 1);
				continue;
			}
			break;
		}
	}
	return true;
}
// 希尔排序
// 选择增量序列t(n)，其中t(n-1) > t(n)
// 每次排序根据t(n)的值d进行分组，每组记录的相邻的数的下标相差d
// 对每组数进行直接插入排序
// 增量序列n++，并根据d重新分组并排序
// 直到d=1时，表被分为一组，相当于整个表做直接插入排序
bool MySort::shellSort(int arr[], const uint len)
{
	uint h = 1;
	while (3 * h < len)
		h = 3 * h + 1;
	while (h >= 1)
	{
		for (uint i = h; i < len; ++i)
		{
			// j 为相对于i的向前偏移量
			for (uint j = 0; j < i; j += h)
			{
				if (arr[i - j] < arr[i - j - 1])
				{
					swap(arr, i - j, i - j - 1);
					continue;
				}
				break;
			}
		}
		h /= 3;
	}
	return true;
}
// 归并排序
//申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列；
//设定两个指针，最初位置分别为两个已经排序序列的起始位置；
//比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置；
//重复步骤 3 直到某一指针达到序列尾；
//将另一序列剩下的所有元素直接复制到合并序列尾。
bool MySort::mergeSort(int arr[], const uint len)
{
	if (len < 2)return true;
	int* t = (int*)malloc(sizeof(arr)*len);
	uint la = len >> 1;
	uint lb = len - la;
	int* pa = arr;
	int* pb = arr + la;
	mergeSort(pa, la);
	mergeSort(pb, lb);

	for (uint i = 0; i < len && la>0 && lb > 0; i++)
	{
		if (*pa <= *pb){
			t[i] = *pa;
			--la;
			++pa;
			continue;
		}
		t[i] = *pb;
		--lb;
		++pb;
	}

	memcpy(t + len - la, pa, la*sizeof(int));
	memcpy(t + len - lb, pb, lb*sizeof(int));

	memcpy(arr, t, len*sizeof(int));
	free(t);
	return true;
}

// 快速排序
// 选择基准数，将小于基准数的数放到前面，大于它的放到后面
// 每次排序确定基准数的位置
bool MySort::quickSort(int arr[], const uint len)
{
	if (len < 2)return true;
	// 小于基准数的最后下标
	uint s_end = 0;
	for (uint i = 1; i < len; i++)
	{
		if (arr[i] < arr[0]){
			swap(arr, ++s_end, i);
		}
	}
	// 基准数归位
	swap(arr, 0, s_end);
	// 小于基准数的序列
	quickSort(arr, s_end);
	// 大于基准数的序列
	quickSort(arr + s_end + 1, len - s_end - 1);
	return true;
}
// 基数排序（基数2的实现）
// 
bool MySort::radixSort(int arr[], const uint len)
{
	typedef std::queue<int> t;
	t base[2] = { t(), t() };
	// 权
	for (uint i = 0;; ++i)
	{
		bool flag = false;
		for (uint j = 0; j < len; ++j)
		{
			// 将数放到base[k]中，k为该数第i位（二进制）的值
			base[(arr[j] & (0x1 << i)) >> i].push(arr[j]);
			if (arr[j] >> i)flag = true;
		}
		uint in = 0;
		// 将base[0]和base[1]中的值放回到arr中
		while (!base[0].empty())
		{
			arr[in++] = base[0].front();
			base[0].pop();
		}
		while (!base[1].empty())
		{
			arr[in++] = base[1].front();
			base[1].pop();
		}
		if (!flag)break;
	}
	return true;
}
#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int *arr, int len, int data)
{
	int min = 0;
	int max = len - 1;
	int mid;

	while(min <= max)
	{
		mid = min + (max - min)>>1;
		if (arr[mid] > data)
		{
			max = mid - 1;
		}
		else if (arr[mid] < data)
		{
			min = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int left_bound(int *arr, int len, int data)
{
	int min = 0;
	int max = len - 1;
	int mid;

	while(min <= max)
	{
		mid = min + (max - min) / 2;
		if (arr[mid] > data)
		{
			max = mid - 1;
		}
		else if (arr[mid] < data)
		{
			min = mid + 1;
		}
		else if (arr[mid] == data)
		{
			max = mid - 1;
		}
	}

	if (min >= len || arr[min] != data)
	{
		return -1;
	}
	return min;
}

int right_bound(int *arr, int len, int data)
{
	int min = 0;
	int max = len - 1;
	int mid;

	while(min <= max)
	{
		mid = min + (max - min) / 2;
		if (arr[mid] > data)
		{
			max = mid - 1;
		}
		else if (arr[mid] < data)
		{
			min = mid + 1;
		}
		else
		{
			min = mid + 1;
		}
	}

	if (max < 0 || arr[max] != data)
	{
		return -1;
	}
	return max;
}

int main(int argc, char const *argv[])
{
	int nums[] = {1,2,2,2,3};
	int len = sizeof(nums) / 4;
	printf("%d\n", BinarySearch(nums, len, 2));
	printf("%d\n", left_bound(nums, len, 2));
	printf("%d\n", right_bound(nums, len, 2));	
	return 0;
}
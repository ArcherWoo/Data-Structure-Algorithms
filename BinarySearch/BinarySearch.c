#include <stdio.h>

int BinarySearch(int *arr, int len, int data)
{
	int min = 0;
	int max = len - 1;
	int mid;

	while(min <= max)
	{
		mid = min + ((max - min)>>1);
		// if (arr[mid] < data) 从大到小
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

int main(int argc, char const *argv[])
{
	int arr[] = {1,3,7,9,22,111,344,599};
	int data = 22;
	int len = sizeof(arr) / 4;
	printf("%d\n", BinarySearch(arr, len, data));
	return 0;
}
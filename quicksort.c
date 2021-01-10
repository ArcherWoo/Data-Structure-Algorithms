#include <stdio.h>
#include <stdlib.h>

void printA(int *arr, int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d\n", arr[i]);
	}
}

void swap(int a, int b)
{
	int t = a;
	a = b;
	b = t;
}

void GetMid(int *arr, int l, int r)
{
	int mid = l + ((r - l)>>1);
	if (arr[mid] > arr[r])
	{
		swap(arr[mid], arr[r]);
	}
	if (arr[mid] > arr[l])
	{
		swap(arr[mid], arr[l]);
	}
	if (arr[l] > arr[r])
	{
		swap(arr[l], arr[r]);
	}
}

void quicksort(int *arr, int l, int r)
{
	if (l < r)
	{
		GetMid(arr, l, r);
		int i = l, j = r, x = arr[l];
		while(i < j)
		{
			while(i < j && arr[j] >= x)
			{
				j--;
			}
			if (i < j)
			{
				arr[i++] = arr[j];
			}
			while(i < j && arr[i] < x)
			{
				i++;
			}
			if (i < j)
			{
				arr[j--] = arr[i];
			}
		}
		arr[i] = x;
		quicksort(arr, l, i - 1);
		quicksort(arr, i + 1, r);
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {12, 33, 1, 0, -10};
	int len = sizeof(arr)/4;
	printA(arr, len);
	printf("\n");
	quicksort(arr, 0, len - 1);
	printA(arr, len);

	return 0;
}

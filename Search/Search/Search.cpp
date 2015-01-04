#include <iostream>
#include <conio.h>
#include <stdio.h>

void BinarySearch(int arr[],int n, int key)
{
	if ( n == 0 )
	{
		printf("No Array of elements\n");
		return;
	}

	int low = 0;
	int high = n-1;

	while(low <= high)
	{
		int mid = (high - low)/2;

		if(arr[mid] == key)
		{
			printf("Key %d is found at index %d\n", key, mid);
			return;
		}
		else
		{
			if(key < arr[mid])
			{
				low = 0;
				high = mid - 1;
			}
			else if (key > arr[mid])
			{
				low = mid + 1;
				high = n - 1;
			}

			BinarySearch(arr[
		}
	}
}

int main()
{

	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	
	_getch();
	return 0;
}
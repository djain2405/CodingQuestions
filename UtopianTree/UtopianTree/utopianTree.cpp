#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

int main() {

	int n = 0;
	scanf("%d", &n);

	int *arr = (int*) malloc (n*sizeof(int));

	int i = 0;
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for(i = 0; i < n; i++)
	{
		int sum = 1;
		int isSpring = 1;
		int isSummer = 0;
		int j = 1;
		if(arr[i] == 0)
			arr[i] = 1;
		else
		{
			
			for(j = 1; j <= arr[i]; j++)
			{
				//printf("Value of j ===== %d\n", j);
				if(j%2 == 0)
				{
					sum = sum+1;
				}
				else
				{
					sum = sum*2;
				}
				//printf("Sum ====== %d\n", sum);
			
			}
		}

		arr[i] = sum;


	}
	
	for(i = 0; i < n; i++)
		printf("%d\n", arr[i]);

	_getch();
	
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
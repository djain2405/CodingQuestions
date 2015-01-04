#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

int
FindFibonacci(int n)
{

	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else return (FindFibonacci(n-1) + FindFibonacci(n-2));
}

int main() {

    int no = 0;
    int i = 0;
	printf("Number is :\n");
    scanf("%d", &no);
	printf("elhgflrhgjlrjlg       %d\n", no);
    /*int *arr = (int*)malloc(n*sizeof(int));
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for(i = 0; i < n; i++)
    {
        int count = 0;
        int temp = arr[i];
		
        int number = arr[i];
        
        while(number != 0)
        {
            int temp1 = number % 10;
			
            if(temp % temp1 == 0)
            {
                 count++;
            }
            
            number = number/10;
        }
        
        arr[i] = count;
		
    }
    
    for (i = 0; i < n; i++)
        {
    printf("%d\n", arr[i]);
    }*/
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	printf("Hellooooooooooooooooooooooooo\n");
	int number = FindFibonacci(no);
	printf("Number is %d", number);

	_getch();
    return 0;
}
